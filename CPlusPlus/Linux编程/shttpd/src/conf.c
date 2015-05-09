#include "func.h"
#include "conf.h"

void get_conf()
{
    FILE *file;
    char buf[MAX_LINE_CONF], key[MAX_LINE_CONF], value[MAX_LINE_CONF];
    fprintf(stdout, "get configure file info\n");

    file = Fopen(CONFIG_PATH, "r");
    while(feof(file) == 0)
    {
        if(fgets(buf, MAX_LINE_CONF, file) == NULL)
        {
            if(feof(file))
                break;
            perror("fgets");
            exit(1);
        }
        if(!is_comment(buf))
        {
            printf("%s",buf);
            sscanf(buf, "%s %s\n", key, value);
            printf("%s %s\n", key, value);
        }
    }
}

/*
 * return 1 when the words is comment, else return 0
 */
int is_comment(char *src)
{
    int len = strlen(src);
    int flag = 1;
    int i;
    for(i = 0; i < len; i++)
    {
        if(src[i] == ' ')
            continue;
        else if(src[i] == COMMENT_FLAG)
            break;
        else
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
