#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

int main(int argv, char *argc[])
{
    DIR *dp;
    struct dirent *dirp;

    if(argv != 2)
    {
        printf("Usage: %s dirname\n", argc[0]);
        return -1;
    }
     
    if((dp = opendir(argc[1])) == NULL)
    {
        printf("opendir error: %s\n", strerror(errno));
        return -1;
    }

    while((dirp = readdir(dp)) != NULL)
    {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);

    return 0;
}
