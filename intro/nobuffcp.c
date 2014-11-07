#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 4096

int main(void)
{
    int n;   
    char buf[BUFFSIZE];
    
    n = read(0, buf, BUFSIZE);
    write(1, buf, n);

    return 0;
}
