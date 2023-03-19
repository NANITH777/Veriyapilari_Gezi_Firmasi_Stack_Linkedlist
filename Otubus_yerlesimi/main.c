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

void displaylist()
{
    if(top==NULL)
    {
        printf("Otobus nos!!\n");
    }
    else
    {
        struct Stack_Yolcu * temp=top;
        printf("\n----------------otobus-------------\n");
        while(temp!=NULL)
        {
            printf("\n %d.sira -- Yolcu Adi: %s -- Yolcu Soyadi: %s\n", temp->sira, temp->ad, temp->soyad);
            temp=temp->next;
        }
        printf("\n-------------------------------------\n");
    }
}

int main()
{
    top=NULL;
    int choice;
    int sira;
    char ad[50];
    char soyad[50];

    printf("\t\n\n bizim gezi firmasimiza hosgeldiniz\n");
    printf("\t 1 Yolcu bilgileri ekleme\n");
    printf("\t 2 Yolcu bilgileri silme\n");
    printf("\t 3 alinmis koltuk sayisi ve otobusun boyutu\n");
    printf("\t 4 yolcular listesi\n");
    printf("\t 5 sistemden cik\n");

    do
    {
        printf("\t enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\t kacinci sira: ");
                scanf("%d", &sira);
                printf("\t Yolcu adi:");
                scanf("%s", &ad);
                printf("\t Yolcu soyadi:");
                scanf("%s", &soyad);
                pushlist(sira, ad, soyad);
                break;
            case 2:
                poplist();
                break;
            case 3:
                printf("\t alinmis koltuk sayisi: %d ve otobusun boyutu: %d\n", size+1, boyut);
                break;
            case 4:
                displaylist();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\n Dogru tusa basin\n");
        }

    }while(choice!=0);

    return 0;
}
