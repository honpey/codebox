
int add(int a, int b, char **res)
{
    *res = "hello world";
    return a+b;
}

int minus(int a, int b)
{
    return a-b;
}

int merge(const char *a, const char *b, char **res)
{
  int i = 0, j = 0;
  int z = 0;
  while (a[i] != 0) {
    (*res)[z++] = a[i];
  } 
  while (b[i] != 0) {
    (*res)[z++] = b[i];
  } 
  (*res)[z] = 0;
  return 99;
}

int merge2(const char *a, const char *b)
{
  return 103;
}
