#include <stdio.h>  
#include <string.h>  
#include <ctype.h>  
int strcasecmp(const char *s1, const char *s2)  
{  
    int c1, c2;  
    do {  
        c1 = tolower(*s1++);  
        c2 = tolower(*s2++);  
    } while(c1 == c2 && c1 != 0);  
    return c1 - c2;  
}  
int test1(void)  
{  
    int n = 4;  
    char str1[] = "Acef";  
    char str2[] = "ACEFd";  
    printf("strcasecmp(str1, str2) = %d/n", strcasecmp(str1, str2));  
    return 0;  
}  
int mystrncasecmp(const char *s1, const char *s2, int n)  
{  
    int c1, c2;  
    do {  
        c1 = tolower(*s1++);  
        c2 = tolower(*s2++);  
    } while((--n > 0) && c1 == c2 && c1 != 0);  
    return c1 - c2;  
}  
int test2(void)  
{  
    int n = 4;  
    char str3[] = "ABCf";  
    char str4[] = "abcd";  
    printf("mystrncasecmp(str3, str4, n) = %d/n", mystrncasecmp(str3, str4, n));  
    return 0;  
} 
int main(void)  
{  
    test1();
    test2();
    return 0;  
}  
