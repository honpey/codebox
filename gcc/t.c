int __attribute__((cdecl)) funcc(int a) {
    int i = a/2;
    return 19 * i;
}
int __attribute__((cdecl)) funcb(int b) {
    funcc(b);
}
int __attribute__((cdecl)) funca(int a) {
    funcb(a);
}
int __attribute__((cdecl)) add(int a,int b)
{
        int i, j;
        i = a+b;
        j = funca(a);
        return i*j;
}
int __attribute__((cdecl)) print(int i, ...)
{
        int j,a,b;
        a = 23; // 0x17 = 23
        b = 39; // 0x27 = 39
        j = add(a,b);
        return j;
}
void __attribute__((cdecl)) main(void)
{
//        print(2,3);
        printf("hello world: %d\n", print(2,3));
        return 0;
}
