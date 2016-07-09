struct aiocb {
	int aio_fildes; /* file descriptor*/
	off_t aio_offset; /* file offset for I/O */
	volatile void *aio_buf; /* buffer for I/O */
	size_t aio_nbytes; /* number of bytes to transfer */
	int aio_reqprio; /* priority */
	struct sigevent aio_sigevent; /* signal information */
	int aio_lio_opcode; /* operation for list IO*/
}

struct aiocb{
	int aio_fildes;
	off_t aio_offset;
	volatile void *aio_buf;
	size_t aio_nbytes;
	int aio_reqprio;
	struct sigevent aio_segevent;
	int aio_lio_opcode;
}

struct sigevent {
	int sigev_notify; /* notify type */
	int sigev_signo; /* signal number */
	union sigval sigev_value; /* notify argument */
	void (*sigev_notify_function)(union sigval);	/* notify function */
	pthread_attr_t *sigev_notify_attributes;
}

struct sigevent {
	int sigev_notify;
	int sigev_signo;
	union sigval sigev_value;
	void (*sigev_notify_function)(union sigval);
	pthread_attr_t *sigev_notify_attributes;
};

struct sigevent {
	int sigev_notify; /* notify type */
	int sigev_signo; /* signal number */
	union sigev_value; /* notify number */
	void (*sigev_notify_function)(union sigval); /* notify function */
	pthread_attr_t *sigev_notify_attributes;
}

struct sigevent {
	int sigev_notify;
	int sigev_signo;
	union sigev_value;
	void (*sigev_notify_function)(union sigval);
	pthread_attr_t *sigev_notify_attributes;
};

struct sigevent {
	int sigev_notify;
	int sigev_signo;
	union sigev_value;
	void (*sigev_notify_function)(union sigval);
	pthread_attr_t *sigev_notify_attributes;
}

struct sigevent {
	int sigev_notify;
	int sigev_signo;
	union sigev_value;
	void (*sigev_notify_function)(union sigval);
	pthread_attr_t *sigev_notify_attributes;
}

struct sigevent {
	int sigev_notify;
	int sigev_signo;
	union sigev_value;
	void (*sigev_notify_function)(union sigval);
	pthread_attr_t *sigev_notify_attributes;

};

int pthread_attr_destroy(pthread_attr_t *attr);
int pthread_attr_getdetachstate(const pthread_attr_t *attr, int *detachstate);
int pthread_attr_getguardsize(const pthread_attr_t *restrict attr,
							size_t 

int pthread_attr_init(pthread_attr_t *attr);
int pthread_attr_destroy(pthread_attr_t *attr);

int pthread_barrierattr_init(pthread_barrierattr_t *attr);

int pthread_cond_broadcast(pthread_cond_t *cond);
int pthread_cond_destroy(pthread_cond_t *cond);
int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr);
int pthread_cond_signal(pthread_cond_t *cond);

int pthread_cond_broadcast(pthread_cond_t *cond);
int pthread_cond_destroy(pthread_cond_t *cond);
int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *restrict attr);
int pthread_cond_signal(pthread_cond_t *cond);

int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *restrict attr);
int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *restrict mutex);
int pthread_cond_broadcast(pthread_cond_t *cond);
int pthread_cond_signal(pthread_cond_t *cond);
int pthread_cond_destroy(pthread_cond_t *cond);

int pthread_mutex_init(pthread_mutex_t *restrict mutext, const pthread_mutexattr_t *restrict attr);
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
int pthread_mutex_destroy(pthread_mutext_t *mutex);

int pthread_create(pthread_t *restrict tidp,
					const pthread_attr_t *restrict attr,
					void *(*start_rtn)(void *),
					void *restrict arg);
int pthread_join(pthread_t thread, void **rval_ptr);
int pthread_key_create(pthread_key_t *keyp,
			void (*destructor)(void *));
int pthread_exit(void *rval_ptr);

int pthread_create(pthread_t *restrict tidp,
			const pthread_attr_t *restrict attr,
			void *(start_rtn)(void *),
			void *restrict arg);
int pthread_join(pthread_t thread, void **rval_ptr);
int pthread_key_create(pthread_key_t *keyp,
			void (*destructor)(void *));
int pthread_exit(void *rval_ptr);

int pthread_create(pthread_t *restrict tidp,
					const ptread_attr_t *attr,
					void *(start_rtn)(void *),
					void *arg);

int sigemptyset(sigset_t *set);
int sigaction(int signo, const struct sigaction *restrict act,
		struct sigaction *restrict oact);

struct sigaction {
	void (*sa_handler)(int); /* addr of signal handler */
	sigset_t sa_mask;
	int sa_flags; /* signal options, */
	void (sa_sigaction)(int , siginfo_t *, void*);
}

int sigemptyset(sigset_t *set);
int sigfillset(signset_t *set);
int sigaddset(sigset_t *set, int signo);
int sigdelset(sigset_t *set, int signo);

int sigismember(sigset_t *set, int signo);
int sigaddset(sigset_t *set, int signo);
int sigdelset(sigset_t *set, int signo);
int sigismember(const sigset_t *set, int signo);
int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);
int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);

int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);
int sigaddset(sigset_t *set, int signo);
int sigdelset(sigset_t *set, int signo);
int sigismember(sigset_t *set, int signo);
int sigprocmask(int how, const sigset_t *set, const sigset_t *oset);
SIG_BLOCK SIG_UNBLOCK SIG_SETMASK
SIG_BLOCK SIG_UNBLOCK SIG_SETMASK
int sigpending(sigset_t *set);
int sigpending(sigset_t *set);
int sigaction(int signo, const struct sigaction *act, struct sigaction *oact);

struct sigaction {
	void (*sa_handler)(int );
	sigset_t sa_mask;
	int sa_flags;
	void (*sa_sigaction)(int, siginfo_t *,void *);
}

struct sigaction {
	void (*sa_handler)(int);
	sigset_t sa_mask;
	int sa_flags;
	void (*sa_sigaction)(int, siginfo_t *,void *);
};

struct sigaction {
	void (*sa_handler)(void *);
	sigset_t sa_mask;
	int sa_flags;
}

struct sigaction {
	void (*sa_handler)(void *);
	sigset_t sa_mask;
	int sa_flags;

}

struct sigaction {
	void (*sa_handler)(void *);
	sigset_t mask
		int sa_flags;

	void (*sa_action)(int, siginfo_t *, void *);
}

struct sigaction {
	void (*sa_handler)(void *);
	sigset_t mask;
	int sa_falgs;
	void (*sa_action)(int, siginfo_t *, void *);
}

struct sigaction {
	void (*sa_handler)(int);
	sigset_t mask;
	int sa_flags;
	void (sa_sigaction)(int, siginfo_t *, void *);
}

struct sigaction {
	void (*sa_handler)(int);
	sigset_t mask;
	int sa_flasgs;
	void (*sa_sigaction)(int, siginfo_t *, void *);
}

struct sigaction {
	void (*sa_handler)(int);
	sigset_t mask;
	int sa_flags;
	void (*sa_sigaction)(int, siginfo_t *,void *);
}

struct sigaction {
	void (*sa_handler)(int);
	sigset_t mask;
	int sa_flags;
	void (*sa_sigaction)(int, siginfo_t *,void *);
}	

struct sigaction {
	void (*sa_handler)(int);
	sigset_t mask;
	int sa_flags;
	void (*sa_sigaction)(int, siginfo_t *, void *);
};


