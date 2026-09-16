#include <stdio.h>
#include <string.h>

int main() {
    char important[] = "hello"; 
    char buf[5]; 
    gets(buf); 

    printf("%s\n", buf);
    printf("%s\n", important);

    return 0;
}