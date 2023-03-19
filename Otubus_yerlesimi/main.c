#include<stdlib.h>
#include<string.h>
#include <string.h>

int boyut=6;

struct Stack_Yolcu
{
    int sira;
    char ad[50];
    char soyad[50];
    struct Stack_Yolcu * next;
};

struct Stack_Yolcu * top=NULL;
int size=-1;

int main()
{
    printf("Hello world!\n");
    return 0;
}
