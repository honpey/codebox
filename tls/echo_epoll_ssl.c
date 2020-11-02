#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/epoll.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAXEVENTS 64

typedef struct userdata_s {
    int fd;
    SSL * ssl;
} userdata_t;

void error(char *msg)
{
    perror(msg);
    exit(1);
}

static void make_socket_non_blocking(int sfd)
{
    int flags, s;

    flags = fcntl(sfd, F_GETFL, 0);
    if (flags == -1)
    {
        error("fcntl get");
    }

    flags |= O_NONBLOCK;
    s = fcntl(sfd, F_SETFL, flags);
    if (s == -1)
    {
        error("fcntl set");
    }
}

static int create_and_bind(char *port)
{
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int s, sfd;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;     /* Return IPv4 and IPv6 choices */
    hints.ai_socktype = SOCK_STREAM; /* We want a TCP socket */
    hints.ai_flags = AI_PASSIVE;     /* All interfaces */

    s = getaddrinfo(NULL, port, &hints, &result);
    if (s != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        return -1;
    }

    for (rp = result; rp != NULL; rp = rp->ai_next)
    {
        sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sfd == -1)
            continue;

        s = bind(sfd, rp->ai_addr, rp->ai_addrlen);
        if (s == 0)
        {
            /* We managed to bind successfully! */
            break;
        }

        close(sfd);
    }

    if (rp == NULL)
    {
        fprintf(stderr, "Could not bind\n");
        return -1;
    }

    freeaddrinfo(result);

    return sfd;
}

SSL_CTX* init_ssl_ctx()
{
    SSL_CTX *ctx;

    SSL_load_error_strings();   
    OpenSSL_add_ssl_algorithms();

    /* create ctx */
    const SSL_METHOD *method;

    method = SSLv23_server_method();

    ctx = SSL_CTX_new(method);
    if (!ctx) {
        /* prints the error strings for all errors that OpenSSL has recorded to 
           stderr, thus emptying the error queue*/
        ERR_print_errors_fp(stderr);
        error("Unable to create SSL context");
    }

    SSL_CTX_set_ecdh_auto(ctx, 1);

    /* Set the key and cert */
    if (SSL_CTX_use_certificate_file(ctx, "server.crt", SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
        error("Unable to set certificate");
    }
    
    if (SSL_CTX_use_PrivateKey_file(ctx, "rsa_private_key.pem", SSL_FILETYPE_PEM) <= 0 ) {
        ERR_print_errors_fp(stderr);
        error("Unable to set private key");
    }
    return ctx;
}

int ssl_handshake(SSL *ssl)
{
    int n, sslerr;

    n = SSL_do_handshake(ssl);
    if (n == 1)
    {
        printf("ssl connection established\n");
        printf("成功握手\n");
        return 1;
    }
    else
    {
        sslerr = SSL_get_error(ssl, n);
        switch (sslerr)
        {
            case SSL_ERROR_WANT_READ:
            case SSL_ERROR_WANT_WRITE:
                return EAGAIN;
            default:
                ERR_print_errors_fp(stderr);
                error("ssl handshake");
        }
    }
    printf("成功握手\n");
}

int main(int argc, char *argv[])
{
    int sfd, s;
    int efd;

    /* Since epoll_data is a union, only one field can be used. ptr is always 
       used to pointer a user data structure which then contain file descriptor.
       Do not forget to free user data structure you created. */
    struct epoll_event event;
    struct epoll_event *events;


    sfd = create_and_bind("8000");
    if (sfd == -1)
        abort();

    make_socket_non_blocking(sfd);

    s = listen(sfd, SOMAXCONN);
    if (s == -1)
    {
        error("listen");
    }

    efd = epoll_create1(0);
    if (efd == -1)
    {
        error("epoll_create");
    }

    userdata_t *data = (userdata_t*)malloc(sizeof(userdata_t));
    data->fd = sfd;
    event.data.ptr = data;
    event.events = EPOLLIN | EPOLLET;
    s = epoll_ctl(efd, EPOLL_CTL_ADD, sfd, &event);
    if (s == -1)
    {
        error("epoll_ctl");
    }

    /* Buffer where events are returned */
    events = calloc(MAXEVENTS, sizeof event);

    SSL_CTX *ctx = init_ssl_ctx();

    /* The event loop */
    while (1)
    {
        int n, i, fd;

        n = epoll_wait(efd, events, MAXEVENTS, -1);
        printf("get one event....\n");
        for (i = 0; i < n; i++)
        {
            fd = ((userdata_t *)events[i].data.ptr)->fd;

            printf("get one event.... %d\n", fd);

            if ((events[i].events & EPOLLERR) ||
                (events[i].events & EPOLLHUP) ||
                (!(events[i].events & EPOLLIN)))
            {
                if (events[i].events & EPOLLERR)
                    fprintf(stderr, "epoll error: EPOLLERR\n");
                if (events[i].events & EPOLLHUP)
                    fprintf(stderr, "epoll error: EPOLLHUP\n");
                close(fd);
                free(events[i].data.ptr);
                continue;
            }
            else if (sfd == fd)
            {
                /* We have a notification on the listening socket, which
                   means one or more incoming connections. */
                while (1)
                {
                    struct sockaddr in_addr;
                    socklen_t in_len;
                    int infd;
                    char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];
                    printf("--------Enter sfd == fd\n");

                    in_len = sizeof in_addr;
                    infd = accept(sfd, &in_addr, &in_len);
                    if (infd == -1)
                    {
                        if ((errno == EAGAIN) || (errno == EWOULDBLOCK))
                        {
                            /* We have processed all incoming
                               connections. */
                            printf("--------Exit sfd == fd\n");
                            break;
                        }
                        else
                        {
                            perror("accept");
                            break;
                        }
                    }

                    s = getnameinfo(&in_addr, in_len,
                                    hbuf, sizeof hbuf,
                                    sbuf, sizeof sbuf,
                                    NI_NUMERICHOST | NI_NUMERICSERV);
                    if (s == 0)
                    {
                        printf("Accepted connection on descriptor %d "
                                       "(host=%s, port=%s)\n", infd, hbuf, sbuf);
                    }

                    /* Make the incoming socket non-blocking and add it to the
                       list of fds to monitor. */
                    userdata_t *data = (userdata_t*)malloc(sizeof(userdata_t));
                    make_socket_non_blocking(infd);
                    data->fd = infd;

                    SSL *ssl = SSL_new(ctx);
                    SSL_set_accept_state(ssl);
                    SSL_set_fd(ssl, infd);
                    // 这里就开始做握手了～～
                    data->ssl = ssl;

                    event.data.ptr = data;
                    event.events = EPOLLIN | EPOLLET;
                    s = epoll_ctl(efd, EPOLL_CTL_ADD, infd, &event);
                    if (s == -1)
                    {
                        error("epoll_ctl");
                    }
                }
                continue;
            }
            else
            {
                /* start or continue ssl handshake */
                SSL *ssl = ((userdata_t*)events[i].data.ptr)->ssl;
                printf("ssl_is_init_finished:%d\n", SSL_is_init_finished(ssl));
                if ( !SSL_is_init_finished(ssl) )
                {
                    ssl_handshake(ssl);
                    continue;
                }
                break;

                int done = 0;
                int sslerr;
                ssize_t count;
                char buf[512];

                count = SSL_read(ssl, buf, sizeof buf); // read
                if (count > 0)
                {
                    //count = SSL_write(ssl, buf, count); // write
                }

                char *pBuf = (char*)buf;
                printf("read Buffer :%s\n", pBuf);

                if (count < 0)
                {
                    sslerr = SSL_get_error(ssl, count);
                    if (sslerr != SSL_ERROR_WANT_READ && sslerr != SSL_ERROR_WANT_WRITE) {
                        ERR_print_errors_fp(stderr);
                        done = 1;
                    }
                }
                else if (count == 0)
                {
                    /* The remote has closed the connection. Do I have to call SSL_shutdown? */
                    done = 1;
                }

                if (done)
                {
                    printf("Close connection on descriptor %d\n", fd);
                    SSL_free(ssl);
                    /* Closing the descriptor will make epoll remove it
                       from the set of descriptors which are monitored. */
                    close(fd);
                    free(events[i].data.ptr);
                }
            }
        }
    }

    // clean
    free(events);
    close(sfd);
    SSL_CTX_free(ctx);
    EVP_cleanup();

    return EXIT_SUCCESS;
}
