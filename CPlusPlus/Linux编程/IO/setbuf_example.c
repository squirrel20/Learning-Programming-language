#include <stdio.h>
#include <error.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i;
    FILE *fp;
    char msg1[] = "hello, world\n";
    char msg2[] = "hello\nworld";
    char buf[128];
    if((fp = fopen("1.txt", "w")) == NULL)
    {
        perror("file open failure!");
        exit(-1);
    }
    setbuf(fp, NULL);
    memset(buf, '\0', 128);
    fwrite(msg1, 7, 1, fp);
     
}
