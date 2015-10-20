/* FIXME: Implement! */
#include <stdio.h>
#include <string.h>
#define SIZE 26
char smallest_character(char str[], char c);

int main()
{
    char str[6]="cfjpv";
    char key[SIZE]= {'a','b','c','d','e','f','g','h','i','j','k','l',
                     'm','n','o','p','q','r','s','t','u','v','w','x',
                     'y','z'
                    };
    char ans;
    int i;
    for(i=0; i<26; i++) {
        ans = smallest_character(str, key[i]);
        printf("%c\n",ans);
    }

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
