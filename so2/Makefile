liba.so:lib.c
	gcc -shared -g -fPIC -o $@ $<
	cp liba.so ./go/
main:main.c
	gcc -O0 -g -o $@ $< -ldl
clean:
	rm liba.so & rm main
