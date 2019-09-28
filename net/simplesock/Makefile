default: client server armserver armclient
client:client.c
	gcc -o $@ $<
server:server.c
	gcc -o $@ $<
armserver:server.c
	arm-linux-gnueabihf-gcc -static -o $@ $<
armclient:client.c
	arm-linux-gnueabihf-gcc -static -o $@ $<
install:
	cp server /home/hon/f2fs/fsdir/
	cp client /home/hon/f2fs/fsdir/

