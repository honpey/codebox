fun:fun.c
	gcc -g -o $@ $< cal.so -Xlinker -rpath ./
cal.so:cal.c
	gcc --shared -fPIC -o $@ $<
