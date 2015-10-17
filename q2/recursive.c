/* FIXME: Implement! */
#include <stdio.h>
#include <string.h>
#define SIZE 100
char smallest_character(char str[], char c);
int main()
{
    char test[SIZE]="cfjpv";
    char ans=smallest_character(test, 'z');
    printf("%c\n", ans);
    return 0;
}

char smallest_character(char str[], char c)
{
    if((c<'a') || (c>'z')) 
	return -1;
    int len = strlen(str);
    static int i=0;
    if(len==0) 
	return -1;
    if(i==len)
	return str[0];
    if(str[i]>c) 
	return str[i];
    i++;
    return smallest_character(str, c);
}
