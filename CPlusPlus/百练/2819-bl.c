#include <stdio.h>
#include <string.h>

char arr[302];

void cyper(char *p, int len, int k, int *in)
{
	int i;
	char temp[102];
	strcpy(temp, p);
	for(i = 0; i < len; i++)
		p[(i + k)%len] = temp[i];
	for(i = 0; i < len; i++)
		arr[in[i]] = p[i];
}
int main()
{
	int i,j,a,b,c,len,k1,k2,k3, in1[102], in2[102], in3[102];
	char a1[102],a2[102],a3[102];
	scanf("%d %d %d", &k1, &k2, &k3);
	while(1){
		if(k1 == 0 && k2 == 0 && k3 == 0)
			break;
		scanf("%s", arr);
		len = strlen(arr);
		a = b = c = 0;
		for(i = 0; i < len; i++){
			if(arr[i] >= 'a' && arr[i] <= 'i'){
				a1[a] = arr[i];
				in1[a] = i;
				a++;
			}else if(arr[i] >= 'j' && arr[i] <= 'r'){
				a2[b] = arr[i];
				in2[b] = i;
				b++;
			}else{
				a3[c] = arr[i];
				in3[c] = i;
				c++;
			}
		}
		a1[a] = a2[b] = a3[c] = '\0';
		cyper(a1, a, k1, in1);
		cyper(a2, b, k2, in2);
		cyper(a3, c, k3, in3);
		puts(arr);
		scanf("%d %d %d", &k1, &k2, &k3);
	}
	return 0;
}
