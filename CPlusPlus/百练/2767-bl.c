#include <stdio.h>
#include <string.h>

int main()
{
char word[201], sign[11];
int i,len;
while(1)
{
gets(sign);
if(strncmp(sign, "ENDOFINPUT", 10) == 0) break;
memset(word, '\0', 201);
gets(word);
gets(sign);
len = strlen(word);
for(i = 0; i < len; i++)
if(word[i] >= 'A' && word[i] <= 'Z'){ word[i] = (word[i] - 'A' - 5 + 26)%26 + 'A';}
puts(word);
}
}
