#include <stdio.h>
#include <stdlib.h>
/*
 * argc == 3
 * argv[1] : source file
 * argv[2] : destination file
 */
int main(int argc, char **argv)
{
    FILE *fp_src, *fp_des;
    char buf[128];
    int n;
    if(argc != 3)
    {
        printf("You must print source file and destination file!\n");
        exit(EXIT_FAILURE);
    }
    if((fp_src = fopen(argv[1], "r")) == NULL)
    {
        printf("open source file error!\n");
        exit(EXIT_FAILURE);
    }
    if((fp_des = fopen(argv[2], "w")) == NULL)
    {
        printf("open destination file error");
        exit(EXIT_FAILURE);
    }
    
    while(1)
    {
        n = fread(buf, 1, 128, fp_src);
        fwrite(buf, 1, n, fp_des);
        if(feof(fp_src) == 1)
            break;
    }
    fcloseall();
    return(0);
}
