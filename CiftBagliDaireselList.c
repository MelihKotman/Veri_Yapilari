#include <stdio.h>
#include <stdlib.h>
//CIFT BAGLI DAIRESEL LISTE
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *addHeadList(struct node *head,int veri) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(head == NULL) {
        temp -> data = veri;
        temp -> next = temp;
        temp -> prev = temp;
        head = temp;
    }
    else {
        struct node *last = head;
        while(last -> next != head){
            last = last -> next;
        }
        temp -> data = veri;
        temp -> next = head;
        head -> prev = temp;
        last -> next = temp;
        temp -> prev = last;
        head = temp;
    }
}
void addTailList(struct node *head, int veri) {
    if(head == NULL) {
        printf("Lutfen giriniz...\n");
        return;
    }
    struct node *last = head;
    while(last -> next != head) {
        last = last -> next;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = veri;
    temp -> next = head;
    last -> next = temp;
    temp -> prev = last;
    head -> prev = temp;
    last = temp;
}
void addMiddleList(struct node *head, int veri,int index) {
    if(head == NULL) {
        printf("Lutfen liste yapip tekrar deneyiniz...\n");
        return;
    }
    struct node *temp = head;
    while(temp -> data != index) {
        temp = temp -> next;
    }
    struct node *temp2 = (struct node*)malloc(sizeof(struct node));
    temp2 -> data = veri;
    temp2 -> next = temp-> next;
    temp2 -> prev = temp;
    temp -> next -> prev = temp2;
    temp -> next = temp2;
}
void changeListPart(struct node *head, int veri,int index) {
    if(head == NULL) {
        printf("Degistirebilecek veri yoktur...\n");
        return;
    }
    else if(head -> data == index) {
        head -> data = veri;
    }
    else {
        struct node *temp2 = head;
        int sayac = 1;
        struct node *temp = head;
        while(temp -> data != index) {
            temp = temp -> next;
        }
        temp -> data = veri;
    }
}
void printList(struct node *head) {
    if(head == NULL) {
        printf("Yazdiralacak listeniz yoktur...\n");
        return;
    }
    struct node *temp = head;
    int sayac = 1;
    do {
        printf("%d.Eleman = %d\n",sayac,temp -> data);
        sayac++;
        temp = temp -> next;
    }while(temp != head);
}
void printListInfo(struct node *head) {
    if(head == NULL) {
        printf("Listeniz bostur...\n");
        return;
    }
    struct node *temp = head;
    int sayac = 1;
    do {
        printf("%d. Eleman = %d\n",sayac,temp -> data);
        printf("%d. Elemanin Adresi = %p\n",sayac,temp);
        printf("%d. Elemanin Oncesinde Bagli Oldugu Adres = %p\n",sayac,temp -> prev);
        printf("%d. Elemanin Sonrasinda Bagli Oldugu Adres = %p\n",sayac,temp -> next);
        sayac++;
        temp = temp->next;
    }while(temp != head);
}
struct node *deleteListPart(struct node *head,int index) {
    if(head == NULL) {
        printf("Listeniz bostur ve silinecek eleman yoktur...\n");
        return head;
    }
    struct node *temp = head;
    if(head -> data == index) {
        if(head -> next == head) {
            head = NULL;
            printf("Listeniz silinmistir...\n");
            return head;
        }
        else {
            head -> next -> prev = head -> prev;
            head -> prev -> next = head -> next;
            head = head -> next;
            free(temp);
            return head;
        }
    }
    else {
        while(temp -> next -> data != index) {
            if(temp -> next -> next == NULL) {
                printf("Elemaniniz bulunmamistir silinmek istenen...");
                return head;
            }
            temp = temp -> next;
        }
        struct node *temp2 = temp -> next;
        temp -> next = temp2 -> next;
        if(temp -> next == head) {
            head -> prev = temp;
        }
        else {
            temp2 -> next -> prev = temp;
        }
        free(temp2);

    }
    return head;

}
struct node *deleteList(struct node *head) {
    if(head == NULL) {
        printf("Listeniz bos...\n");
        return head;
    }
    if(head -> next == head) {
        head = NULL;
        return head;
    }
    /*do {
        head = deleteListPart(head,head->data);
    }while(head != NULL);
    */
    else {
        struct node *temp = NULL;
        while(head != NULL) {
            temp = head;
            head = head ->next;
            if(temp -> next == head) {
                head = NULL;
                return head;
            }
            free(temp);
        }
    }
    printf("Listeniz silinmistir...\n");
    return head;

}
int InfoCountList(struct node *head) {
    int count = 0;
    if(head == NULL) {
        printf("Listeniz bostur...\n");
        return count;
    }
    struct node *temp = head;
    do {
        count++;
        temp = temp-> next;
    }while(temp != head);
    return count;
}
void searchList(struct node *head, int index) {
    if(head == NULL) {
        printf("Lutfen liste olusturunuz...\n");
        return;
    }
    struct node *temp = head;
    while(temp ->data != index) {
        temp = temp -> next;
    }
    printf("Eleman = %d",temp -> data);
    printf("Elemanin adresi = %p",temp);
    printf("Elemanin onceki bagli oldugu adres = %p",temp -> prev);
    printf("Elemanin sonraki bagli oldugu adres = %p",temp -> next);
}
void reverseListPrint(struct node *head) {
    if(head == NULL) {
        printf("Ters cevirelecek liste yok...\n");
        return;
    }
    struct node *head1 = NULL;
    struct node *temp = head;
    ;
    do{
        head1 = addHeadList(head1,temp-> data);
        temp = temp -> next;
    }while(temp != head);
    printList(head1);
}
void copyList(struct node *head) {
    if(head == NULL) {
        printf("Lutfen kopyalanacak liste olusturunuz...\n");
        return;
    }
    struct node *head1 = NULL;
    struct node *temp = head;
    head1 = addHeadList(head1,temp-> data);
    temp = temp -> next;
    while(temp != head) {
        addTailList(head1,temp-> data);
        temp = temp -> next;
    }
    printf("KOPYA LISTEMIZ =\N");
    printList(head1);
}
struct node* mergeList(struct node *head,struct node *headBirlesim) {
    if(head == NULL) {
        struct node *temp2 = headBirlesim;
        head = addHeadList(head,temp2 -> data);
        temp2 = temp2 -> next;
        while(temp2 != headBirlesim) {
            addTailList(head,temp2 -> data);
            temp2 = temp2 -> next;
        }
     return head;
    }
    else {
        struct node *last = head;
        while(last -> next != head) {
            last = last -> next;
        }
        struct node *last2 = headBirlesim;
        do{
            addTailList(head,last2 -> data);
            last2 = last2 -> next;
        }while(last2 != headBirlesim);
        return head;
    }
}
int main(){
    struct node *head = NULL;
    struct node *headBirlesim = NULL;
    headBirlesim = addHeadList(headBirlesim,1);
    addTailList(headBirlesim,2);
    addTailList(headBirlesim,3);
    addTailList(headBirlesim,4);
    int veri,index,secim;
     while(1){
    printf("Lutfen Dogrusal Listelerde yapmak istediginiz islemi seciniz...\n");
    printf("1-Eleman Ekleme(Listenin En Basina)+\n");
    printf("2-Eleman Ekleme(Listenin En Sonuna)+\n");
    printf("3-Eleman Ekleme(Listenin Arasina)+\n");
    printf("4-Eleman Bilgisi Degistirme+\n");
    printf("5-Eleman Silme+\n");
    printf("6-Listeyi Yazdirma+\n");
    printf("7-Listedeki Elemanlarin Bilgisini Yazdir+\n");
    printf("8-Eleman Sayisi+\n");
    printf("9-Listeyi Silin+\n");
    printf("10-Listede Arama Yap\n");//odev
    printf("11-Listeyi Ters Yazdir\n");//odev
    printf("12-Listeyi Kopyala\n");//odev
    printf("13-Liste Birlestir ([1,2,3,4])\n");//odev
    printf("14-Kapa\n");
    scanf("%d",&secim);
    if(secim <= 0 && secim > 14){
        printf("Yanlis sayi girdiniz tekrar giriniz...\n");
        continue;
    }
    else if(secim <= 14 && secim > 0){
    switch(secim){
    case 1:
        printf("Gireceginiz eleman nedir...\n");
        scanf("%d",&veri);
        head = addHeadList(head,veri);
        break;

    case 2:
        printf("Gireceginiz eleman nedir...\n");
        scanf("%d",&veri);
        addTailList(head,veri);
        break;

    case 3:
        printf("Eklemek istediginiz degeri giriniz...\n");
        scanf("%d",&veri);
        printf("Lutfen Ekleme Yapilacak Pozisyon Bilgisini Giriniz.....\n");
        scanf("%d",&index);
        addMiddleList(head,veri,index);
        break;

    case 4:
        printf("Degistirmek istediginiz degeri giriniz...\n");
        scanf("%d",&veri);
        printf("Degistirmek istediginiz pozisyonu giriniz...\n");
        scanf("%d",&index);
        changeListPart(head,veri,index);
        printList(head);
        break;

    case 5:
        printf("Silmek istediginiz pozisyonu giriniz...\n");
        scanf("%d",&index);
        head = deleteListPart(head,index);
        break;

    case 6:
        printList(head);
        break;

    case 7:
        printListInfo(head);
        break;

    case 8:
        printf("Eleman Sayisi = %d\n",InfoCountList(head));
        break;

    case 9:
        head = deleteList(head);
        break;

    case 10:
        printf("Aramak istediginiz liste elemanini giriniz...\n");
        scanf("%d",&veri);
        searchList(head,veri);
        break;

    case 11:
        reverseListPrint(head);
        break;
    case 12:
        copyList(head);
        break;
    case 13:
        head = mergeList(head,headBirlesim);
        break;
    case 14:
        exit(0);
        break;
            }
        }
    }
}
