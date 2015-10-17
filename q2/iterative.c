/* FIXME: Implement! */
#include <stdio.h>
#include <string.h>
#define SIZE 100
char smallest_character(char str[], char c);

int main()
{
    char str[SIZE]="cfjpv";
    char ans=smallest_character(str, 'c');
    printf("%c\n", ans);
    return 0;
}

char smallest_character(char str[], char c)
{
    if((c<'a') || (c>'z'))
        return -1;
    int len=strlen(str);
    int i=0;
    for(i=0; i<len; i++) {
        if(str[i]>c)
            return str[i];
    }
    return str[0];
}
