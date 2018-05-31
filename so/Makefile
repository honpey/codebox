liba.so:lib.c
	gcc -shared -g -fPIC -o $@ $<
main:main.c
	gcc -O0 -g -o $@ $< -L/home/hon/codebox/so -la
clean:
	rm liba.so & rm main
