#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define BUFSIZE 4096

int main(void)
{
    int n;   
    char buf[BUFSIZE];
    
    // On error, -1 is returned
    // End of file, 0 is returned
    // The number of bytes read is returned smaller 
    // than the number of bytes requested not an error
    while((n = read(0, buf, BUFSIZE)) > 0)
    {
        
        if(write(1, buf, n) < 0)
        {
            printf("read error: %s\n", strerror(errno));
            return -1;
        }
    }

    if( n < 0)
    {
        printf("read error: %s\n", strerror(errno));
        return -1;
    }

    return 0;
}
