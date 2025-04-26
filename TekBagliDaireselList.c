#include <stdio.h>
#include <stdlib.h>
// TEK BAGLI DAIRESEL LISTE
struct node {
    int data;
    struct node *next;
};
struct node *addHeadList(struct node *head,int veri){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        temp -> data = veri;
        temp -> next = temp;

    }
    else{
        struct node *last = head;
        while(last->next != head){
            last = last ->next;
        }
        temp -> data = veri;
        temp -> next = head;
        last -> next = temp;

    }
    head = temp;
    return head;
}
void addTailList(struct node *head,int veri){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
     if(head == NULL){
        printf("Lutfen listenin basina eleman giriniz...");
        return;
    }
    else{
       struct node *last = head;
        while(last->next != head){
            last = last ->next;
        }
        temp -> data = veri;
        temp -> next = head;
        last -> next = temp;
    }
}
void addMiddleList(struct node* head, int data, int index){
if(head==NULL){
    printf("Listeniz bos lutfen basa eleman ekleyiniz....\n");
    return;
}
struct node *temp=(struct node *)malloc(sizeof(struct node));
struct node *ortanca = head;
while(ortanca -> data != index){
    ortanca = ortanca -> next;
}
temp -> data = data;
temp -> next = ortanca -> next;
ortanca -> next= temp;
}
void printList(struct node *head){
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
    }while(temp != head);
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
        printf("%d.Elemanin bagli olacak listenin adresi = %p\n",sayac,temp->next);
        sayac++;
        temp = temp->next;
    }while(temp != head);
}
void changeListPart(struct node *head,int veri,int index){
    struct node *temp = head;
    if(head == NULL){
        printf("Bos Listeye ilk eleman gir...\n");
        return;
    }
    else if(index == head -> data){
        head -> data = veri;
    }
    else{
        while(temp -> data != index){
            if(temp -> next -> next == head){
                printf("Aradiginiz pozisyon bulunamadi...\n");
                return;
            }
            temp = temp -> next;
        }
    temp -> data = veri;
    }
}
void searchList(struct node *head,int veri){
    if(head == NULL){
        printf("Liste olusturmadigin yerde ne aramasi yapacaksin git liste olustur...\n");
        return;
    }
    else{
    struct node *temp = head;
        while(temp -> data != veri){
            temp = temp -> next;
            if(temp-> next == head){
                printf("Aradiginiz pozisyon bulunamadi...\n");
                return;
            }
        }
    printf("\nIstediginiz eleman = %d\n",temp ->data);
    printf("Istediginiz elemanin adresi = %p\n",temp);
    printf("Baglý oldugu eleman = %p\n",temp ->next);
    }
}
struct node *deleteListPart(struct node *head,int veri){
    if(head == NULL){
        printf("Ilk once sen bi liste yap...\n");
        return head;
    }
    struct node *temp = head;
    if(head -> data == veri){
        struct node *last = head;
        if(head -> next == head){
            printf("Listenin tum elemanlari silinmistir...");
            head = NULL;
            return head;
        }
        while(last -> next != head){
            last = last -> next;
        }
            head = head -> next;
            last -> next = head;
            free(temp);
        }

    else{
            while(temp -> next -> data != veri){
                if(temp-> next -> next == head){
                printf("Aradiginiz pozisyon bulunamadi...\n");
                return head;
            }
                temp = temp -> next;
            }
    struct node *temp2 = temp -> next;
    temp -> next = temp2 -> next;
    free(temp2);
    }
    return head;
}
struct node *deleteList(struct node *head){
    if(head == NULL){
        printf("Ilk once sen bi liste yap...\n");
        return head;
    }
        do{
            head = deleteListPart(head,head ->data);
        }while(head != NULL);
    return head;
}
int InfoCountList(struct node *head){
    int sayac = 0;
    if(head == NULL){
        printf("Ilk once sen bi liste yap...\n");
        return sayac;
    }
    struct node *temp = head;
    do{
        temp = temp -> next;
        sayac++;
    }while(temp != head);
    return sayac;
}
void reverseListPrint(struct node *head){
    struct node *temp = head;
    struct node *head2 = NULL;

    if(head == NULL){
        printf("Listen bos neyi ters yazdiracaksin...\n");
        return;
    }

    do{
        head2 = addHeadList(head2, temp->data);
        temp = temp -> next;
    }while(temp != head);
    printList(head2);
}
void copyList(struct node *head){
    struct node *temp = head;
    struct node *head1 = NULL;
    if(head == NULL){
        printf("Liste olustur artiiiik....\n");
        return;
    }

    else {
    head1 = addHeadList(head1 , temp -> data);
    temp = temp -> next;
        while(temp != head){
            addTailList(head1, temp -> data);
            temp = temp -> next;
        }
    }
    printf("Listenizin Kopyasi = \n");
    printList(head1);
}
struct node *mergeList(struct node *head,struct node *headekle){
    if (headekle == NULL) {
        printf("Ikinci listemiz bostur...\n");
        return 0;
    }
    struct node *temp = headekle;
    if(head == NULL){
        head = addHeadList(head,temp -> data);
        temp = temp -> next;
            while(temp != headekle){
                addTailList(head,temp -> data);
                temp = temp -> next;
            }
    }
    else{
    struct node *last = head;
        while(last -> next != head){
        last = last -> next;
        }
        do{
            addTailList(last, temp -> data);
            temp = temp -> next;
        }while(temp != headekle);


}
printList(head);
return head;
}
int main(){
    struct node *head = NULL;
    int veri,index,secim;
    struct node *headBirlesim = NULL;
    headBirlesim = addHeadList(headBirlesim,1);
    addTailList(headBirlesim,2);
    addTailList(headBirlesim,3);
    addTailList(headBirlesim,4);
   while(1){
    printf("Lutfen Dogrusal Listelerde yapmak istediginiz islemi seciniz...\n");
    printf("1-Eleman Ekleme(Listenin En Basina)\n");
    printf("2-Eleman Ekleme(Listenin En Sonuna\n");
    printf("3-Eleman Ekleme(Listenin Arasina)\n");
    printf("4-Eleman Bilgisi Degistirme\n");
    printf("5-Eleman Silme\n");
    printf("6-Listeyi Yazdirma\n");
    printf("7-Listedeki Elemanlarin Bilgisini Yazdir\n");
    printf("8-Eleman Sayisi\n");
    printf("9-Listeyi Silin\n");
    printf("10-Listede Arama Yap\n");
    printf("11-Listeyi Ters Yazdir\n");
    printf("12-Listeyi Kopyala\n");
    printf("13-Liste Birlestir ([1,2,3,4])\n");
    printf("14-Kapa\n");
    scanf("%d",&secim);
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
        head = mergeList(head,headBirlesim);
        break;
    case 14:
        exit(0);
        break;
    }
   }
}