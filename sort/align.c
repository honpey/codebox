#include <stdio.h>
#include <stdlib.h>

void* aligned_malloc(int size, int alignment)
{
    void *addr_raw, *addr;
    int ovp = sizeof(unsigned long);
    
    addr_raw = malloc(size + alignment + ovp);
    if (!addr || alignment < 0) {
        return NULL;
    }
    addr = (addr_raw + ovp + alignment - ((unsigned long)addr_raw % alignment));
    *(addr - ovp) =  addr_raw;
    return addr;
}

void aligned_free(void *addr)
{
    void *addr_raw;
    
    if (!addr)
        return;
    addr_raw = *(addr - sizeof(unsigned long));
    free(addr_raw);    
}

int main()
{

}
