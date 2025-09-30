#include <stdio.h>
#include <stdlib.h>

//CIFT BAGLI DOGRUSAL LISTE
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* addHeadList(struct node *head,int veri){
    struct node *temp =(struct node*)malloc(sizeof(struct node));
    temp -> data = veri;
    if(head == NULL){
        temp -> next = NULL;
        temp -> prev = NULL;
        head = temp;
    }
    else{
        temp -> next = head;
        head -> prev = temp;
        temp -> prev = NULL;
        head = temp;
    }
    return head;
}
void addTailList(struct node *head,int veri){
    if(head == NULL){
        printf("Lutfen listeye head ekleyiniz...\n");
        return;
    }
        struct node *last = head;
        while(last -> next != NULL){
            last = last->next;
        }
        struct node *temp = (struct node*)malloc(sizeof(struct node));
            temp -> data = veri;
            temp -> next = NULL;
            temp -> prev = last;
            last -> next = temp;
            last = temp;

}
void addMiddleList(struct node *head,int veri,int index){//iyi bil......... temp -> next -> prev = temp olmadan
    if(head == NULL){
        printf("Lutfen listeye head ekleyiniz...\n");
        return;
    }
    struct node *temp2 = head;
    while(temp2 -> data != index){
        temp2 = temp2 -> next;
    }

    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp -> data = veri;
    temp -> next = temp2-> next;
    temp -> prev = temp2;
    temp2 -> next -> prev = temp;
    temp2 -> next = temp;
}
void printList(struct node *head){// iyi bil...........
    if(head == NULL){
        printf("\nListeniz yok...\n");
        return;
    }
    struct node *temp = head;
    int sayac = 1;
    do{
        printf("%d.Eleman = %d\n",sayac,temp->data);
        sayac++;
        temp = temp->next;
    }while(temp!= NULL);
}
void printListInfo(struct node *head){
    if(head == NULL){
        printf("\nListeniz yok...\n");
        return;
    }
    struct node *temp = head;
    int sayac = 1;
    do{
        printf("\n%d.Elemanin degeri = %d\n",sayac,temp->data);
        printf("%d.Elemanin adresi = %p\n",sayac,temp);
        printf("%d.Elemanin bagli oldugu onceki listenin adresi = %p\n",sayac,temp->prev);
        printf("%d.Elemanin bagli olacak listenin adresi = %p\n",sayac,temp->next);
        sayac++;
        temp = temp->next;
    }while(temp != NULL);
}
void changeListPart(struct node *head,int veri, int index){
    if(head == NULL){
        printf("Listeye head yazdir artik....\n");
        return;
    }
    else if(head -> data == index){
        head -> data = veri;
    }
    else{
        struct node *temp = head;
        while(temp -> data != index){
            temp = temp -> next;
        }
        temp -> data = veri;
    }
}
struct node* deleteListPart(struct node *head, int index){
    if(head == NULL){
    printf("Lutfen head olusturunuz...\n");
        return head;
    }
    struct node *temp = head;
    if(head -> data == index){
        if(head -> next == NULL){
            printf("Tum elemanlar silinmistir...\n");
            head = NULL;
            return head;
        }
        else{
            head = head -> next;
            head -> prev = NULL;
            free(temp);
        }
    }
    else{
        while(temp -> next -> data != index){
            if(temp -> next -> next == NULL){
                printf("Elemaniniz bulunmamistir silinmek istenen...");
                return head;
            }
        temp = temp -> next;
        }
        struct node *temp2 = temp -> next;
        temp -> next = temp2 -> next; // eger bunu yazmayip altina yazsaydik if'in temp-> next -> next)
            if(temp -> next != NULL){
                (temp -> next)-> prev = temp; // Burada eger biz () kullanmazsak temp2'yi gosterir bize ve istedigimiz olmaz...
            }
        free(temp2);
    }
    return head;
}
int InfoCountList(struct node *head){
    if (head == NULL){
        printf("\nListeniz bos...\n");
        return 0;
    }
    int sayac = 0;
    struct node *temp = head;
        while(temp != NULL){
            temp = temp -> next;
            sayac++;
        }
    return sayac;
}
struct node* deleteList(struct node *head){
    if(head == NULL){
        printf("Lutfen head olusturunuz...");
        return head;
    }
    else{
        struct node *temp = NULL;
        while(head != NULL){
            temp = head;
            head = head -> next;
            free(temp);
        }
    return head;
    }
}
void searchList(struct node *head, int veri) {
     if(head == NULL) {
         printf("Bos Listedir...\n");
         return;
         }
     struct node *temp = head;
     while (temp -> data != veri) {
         if(temp -> next == NULL) {
             printf("Aradiginiz eleman listede bulunmamaktadir...\n");
             return;
             }
         temp = temp -> next;
         }
     printf("Istediginiz eleman %d", temp -> data);
     printf("Istediginiz elemanin adresi = %p", temp);
     printf("Istediginiz elemanin bir onceki elemani %p", temp ->
    prev);
     printf("Istediginiz elemanin bir sonraki elemani = %p", temp -> next);
    }
 void reverseListPrint(struct node *head) {
     if (head == NULL) {
        printf("Lutfen liste olusturunuz...\n");
         return;
         }
    struct node *temp = head;
     struct node *head2 = NULL;
     while(temp != NULL) {
         head2 = addHeadList (head2, temp->data);
         temp = temp -> next;
         }
     printList(head2);
    }
 struct node *copyList(struct node *head) {
    struct node *temp = head;
    struct node *head1 = NULL;
    if(head == NULL) {
        printf("Liste olustur artiiiik....\n");
        return head;
    }

    else {
        head1 = addHeadList (head1, temp -> data);
        temp = temp -> next;
        while(temp != NULL) {
            addTailList(head1, temp -> data);
            temp = temp -> next;
        }
    }
    printf("Listemizin Kopyasi = \n");
    printList(head1);
    return head1;
}
struct node* mergeList(struct node *head,struct node *head2) {
    struct node *temp = head2;
    if(head == NULL) {
        head = addHeadList(head, temp -> data);
        temp = temp -> next;
        while(temp != NULL) {
            addTailList(head, temp -> data);
            temp = temp -> next;
        }
        return head;
    }
    else {
        struct node *last = head;
        while(last -> next != NULL) {
            last = last -> next;
        }
        while(temp != NULL) {
            addTailList(head, temp -> data);
            temp = temp -> next;
        }
        return head;
    }
}
    int main(){
        struct node *head = NULL;
        struct node *head2 = NULL;
        head2 = addHeadList(head2, 1);
        addTailList(head2,2);
        addTailList(head2,3);
        addTailList(head2,4);
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
                         head = mergeList(head,head2);
                            break;
                    case 14:
                        exit(0);
                        break;
                }
            }
        }
    }

