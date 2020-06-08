#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Hello World");
    char* s = crypt("C*msc","00");
    printf(s);
    return 0;
}