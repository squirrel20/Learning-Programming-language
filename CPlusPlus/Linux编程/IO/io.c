#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fileid;
    fileid = open("file.txt", O_RDONLY);

    return 0;
}
