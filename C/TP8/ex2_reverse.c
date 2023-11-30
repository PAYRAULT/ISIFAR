#include <stdio.h>
#include <string.h>

void reverse(char* str)
{
    int l = strlen(str);
    char temp;
    for (int i = 0; i <= l / 2; i++)
    {
        temp = str[i];
        str[i] = str[l - 1 - i];
        str[l - 1 - i] = temp;
    }
}

int main(void)
{
    char s[] = "bonjour";
    reverse(s);
    printf("%s", s);
    return 0;
}