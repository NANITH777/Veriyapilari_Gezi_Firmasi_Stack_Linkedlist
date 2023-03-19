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

void pushlist(int sira, char * ad, char * soyad)
{
    struct Stack_Yolcu * temp;
    temp=(struct Stack_Yolcu *)malloc(sizeof(struct Stack_Yolcu));
    temp->sira=sira;
    strcpy(temp->ad, ad);
    strcpy(temp->soyad, soyad);

    struct Stack_Yolcu * otobus2;
    otobus2=(struct Stack_Yolcu *)malloc(sizeof(struct Stack_Yolcu)*boyut*2);
    otobus2->sira=sira;
    strcpy(otobus2->ad, ad);
    strcpy(otobus2->soyad, soyad);

    if(size>=boyut-1)
    {
        printf("Otobus dolu, iki katli bir otobuse gecmeliyiz\n");

        free(temp);
        temp=otobus2;
        boyut*=2;
    }
    if(top==NULL)
    {
        temp->next=NULL;
    }
    else
    {
        temp->next=top;
    }
    top=temp;
    size++;
}

void poplist()
{
    if(top==NULL)
    {
        printf("\n Otobus bos\n");
    }
    else
    {
        struct Stack_Yolcu* temp1=top;
        printf("\n silinmis yolcu: %d, %s, %s\n", temp1->sira, temp1->ad, temp1->soyad);
        top=temp1->next;

        free(temp1);
        size--;
        printf(" yolcu basariyla silindi!!!\n");
        return;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
