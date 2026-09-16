#include <stdio.h>
#include <string.h>

int main(void)
 {
    char str1[10] = "12345";
    printf("strlen: %d\n", strlen(str1));

    char str2[] = "apple!";
    char str3[] = "bird!";
    strncpy(str2, str3, 4);
    printf("strncpy: %s\n", str2);

    char str4[] = "apple!";
    char str5[] = "bird!";
    strncat(str4, str5, 4);
    printf("strncat: %s\n", str4);

    char str6[] = "aaa";
    char str7[] = "AAA";
    printf("strcmp: %d\n", strcmp(str6, str7));
    printf("strcmpi: %d\n", strcmpi(str6, str7));

    char str8[] = "apple bird cat";
    char c[]=" ";
    char *token;
    token = strtok(str8, c);
    printf("strtok: %s\n", token);
    token = strtok(NULL, c);
    printf("strtok: %s\n", token);
    token = strtok(NULL, c);
    printf("strtok: %s\n", token);

    char str9[] = "Hello World!";
    char c2 = 'W';
    printf("strchr: %p\n", strchr(str9, c2));
    printf("strchr index: %d\n", strchr(str9, c2)-str9);

    char str10[] = "abcDef";
    strupr(str10);
    printf("strupr: %s\n", str10);

    char str11[] = "12345";
    char c3 = 'c';
    strset(str11, c3);
    printf("strset: %s\n", str11);

    char str12[] = "Hello World!";
    strrev(str12);
    printf("strrev: %s\n", str12);

    return 0;
 }