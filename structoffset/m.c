#include <stdio.h>

#pragma pack(1)

struct temp {
    int a;
    char a1;
    char a2;
    char b[5];
    short c;
};

#pragma pack()

int main (void)

{

    int offset;
    offset = (unsigned int)&((struct temp *)0)->c;

    printf("offset = %d\n", offset);
    
    return 0;
}
