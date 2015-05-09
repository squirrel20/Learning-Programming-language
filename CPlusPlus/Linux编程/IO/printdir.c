#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>


void printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;

    if((dp = opendir(dir)) == NULL)
    {
        fprintf(stderr, "cannot open direcotry: %s\n", dir);
        return;
    }
    chdir(dir);
    while((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name, &statbuf);
        if(S_ISDIR(statbuf.st_mode))
        {
            // Found a directory, but ignore
            if(strcmp(".", entry->d_name) == 0 ||
                    strcmp("..", entry->d_name) == 0)
                continue;
            printf("%*s%s/\n", depth, "", entry->d_name);
            printdir(entry->d_name, depth+4);
        }
        else
            printf("%*s%s\n", depth, "", entry->d_name);
    }

    chdir("..");
    closedir(dp);
}

int main()
{
    char dir[100];
    printf("Directory scan - \n");
    printf("Input directory path:");
    scanf("%s", dir);
    printdir(dir, 0);
    printf("done.\n");

    exit(0);
}
