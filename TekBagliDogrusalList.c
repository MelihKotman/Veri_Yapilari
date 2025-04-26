#include <stdio.h>
#include <stdlib.h>
// TEK BAGLI DOGRUSAL LISTE
struct node {
    int data;
    struct node *next;
};
struct node *addHeadList(struct node *head,int veri) {
    struct node *temp =(struct node*) malloc(sizeof(struct node));
    temp -> data = veri;
    temp -> next = head;
    head = temp;
    return head;
}
void addTailList(struct node *head,int veri) {
    if(head == NULL) {
        printf("Lutfen liste yapiniz...\n");
        return;
    }
    struct node *last = head;
    while(last -> next != NULL) {
        last = last -> next;
    }
    struct node *temp = (struct node * )malloc(sizeof(struct node));
    temp -> data = veri;
    temp -> next = NULL;
    last -> next = temp;
}
void addMiddleList(struct node *head, int veri,int index) {
    if(head == NULL) {
        printf("Lutfen liste yapiniz....\n");
        return;
    }
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *temp2 = head;
    while(temp2 -> data != index) {
        temp2 = temp2 -> next;
    }
    temp -> data = veri;
    temp -> next = temp2 -> next;
    temp2 -> next = temp;
}
void changeListPart(struct node *head,int veri, int index) {
    if(head == NULL) {
        printf("Lutfen liste yapiniz...\n");
        return;
    }
    struct node *temp = head;
    while(temp -> data != index) {
        temp = temp -> next;
    }
    temp -> data = veri;
}
struct node *deleteListPart(struct node *head,int index) {
    if(head == NULL) {
        printf("Bos listeyi silemezsiniz...\n");
        return head;
    }
    struct node *temp = head;
    if(head -> data == index) {
        head = head -> next;
        free(temp);
        return head;
    }
    else {
        while(temp -> next -> data != index) {
            if(temp -> next -> next == NULL) {
                printf("Silmek istediginiz eleman bulunmamistir...\n");
                return head;
            }
            temp = temp -> next;
        }
        struct node *temp2 = temp -> next;
        temp -> next = temp2 -> next;
        free(temp2);
        return head;
    }
}
struct node *deleteList(struct node *head) {
    if(head == NULL) {
        printf("Lutfen liste yapiniz...\n");
        return head;
    }
    struct node *temp = head;
    while(head != NULL) {
        temp = head;
        head = head -> next;
        free(temp);
    }
    /**
     do{
        head = deleteListPart(head,head -> data);
     }(head != NULL);
     **/
    return head;
}
void printList(struct node *head) {
    if(head == NULL) {
        printf("Lutfen liste yapiniz...\n");
        return;
    }
    struct node *temp = head;
    int sayac = 1;
    do {
        printf("%d. Eleman = %d\n",sayac,temp -> data);
        sayac++;
        temp = temp -> next;
    }while(temp != NULL);
}
void printListInfo(struct node *head) {
    if(head == NULL) {
        printf("Lutfen liste yapiniz...\n");
        return;
    }
    struct node *temp = head;
    int sayac = 1;
    do {
        printf("%d. Eleman = %d\n",sayac,temp -> data);
        printf("Elemanin adresi = %p\n",temp);
        printf("Elemanin sonraki adresi = %p\n",temp -> next);
        temp = temp -> next;
        sayac++;
    }while(temp != NULL);
}
int InfoCountList(struct node *head) {
    if(head == NULL) {
        printf("Lutfen liste yapiniz...\n");
        return 0;
    }
    struct node *temp = head;
    int sayac = 1;
    do {
        temp = temp -> next;
        sayac++;
    }while(temp != NULL);
    return sayac;
}
void searchList(struct node *head,int index) {
    if(head == NULL) {
        printf("Lutfen liste yapiniz...\n");
        return;
    }
    struct node *temp = head;
    while(temp -> data != index) {
        temp = temp -> next;
    }
    printf("ELeman = %d\n",temp -> data);
    printf("Elemanin adresi = %p\n",temp);
    printf("Elemanin sonraki adresi = %p\n",temp -> next);
}
void copyList(struct node *head) {
    if(head == NULL) {
        printf("Lutfen liste yapiniz...\n");
        return;
    }
    struct node *head1 = NULL;
    struct node *temp = head;
    head1 = addHeadList(head1,head -> data);
    temp = temp -> next;
    do{
        addTailList(head1,temp -> data);
        temp = temp -> next;
    }while(temp != NULL);
    printList(head1);
}
void reverseListPrint(struct node *head) {
    if(head == NULL) {
    printf("Lutfen liste yapiniz...\n");
        return;
    }
    struct node *head1 = NULL;
    struct node *temp = head;
    do {
        head1 = addHeadList(head1,temp -> data);
        temp = temp -> next;
    }while(temp != NULL);
    printList(head1);
}
struct node *mergeList(struct node *head,struct node *headBirlesim) {
    struct node *tempB = headBirlesim;
    if(head == NULL) {
        while(tempB != NULL){
            head = addHeadList(head,tempB ->data);
            tempB = tempB -> next;
            while(tempB != NULL) {
                addTailList(head,tempB ->data);
                tempB = tempB -> next;
            }
        }
        return head;
    }
    else {
        while(tempB != NULL){
            addTailList(head,tempB ->data);
            tempB = tempB -> next;
        }
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
    printf("10-Listede Arama Yap+\n");//odev
    printf("11-Listeyi Ters Yazdir\n");//odev
    printf("12-Listeyi Kopyala+\n");//odev
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
