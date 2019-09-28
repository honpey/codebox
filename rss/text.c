void start() {
//	char buffer[3096];
//	int i = 0;
	/*
	for (i = 0; i < 2; i++) {
		buffer[i*4096] = 'a';
	}
	*/
	while(1);
    asm("movl $42 %ebx \n\t"
        "movl $1  %eax \n\t"
        "int $0x80\n\t");
}
