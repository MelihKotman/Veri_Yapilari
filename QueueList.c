#include <stdio.h>
#include <stdlib.h>
// LISTEYLE YAPILMIS KUYRUK YAPISI
struct node {
    int data;
    struct node *next;
};
struct queue {
    struct node *front;
    struct node *rear;
    int count;
};
void initialize(struct queue *q) {
    q -> count = 0;
    q -> front = NULL;
    q -> rear = NULL;
}
void enqueue(struct queue *q,int veri) {
    struct node *temp =(struct node*) malloc(sizeof(struct node));
    temp -> next = NULL;
    temp -> data = veri;
    if(q-> count == 0) {
        q -> front = q -> rear = temp;
    }
    else {
        q -> rear -> next = temp;
        q -> rear = temp;
    }
    q-> count++;
}
int dequeue(struct queue *q) {
    if(q-> count == 0) {
        printf("Kuyrugunuz bostur...\n");
        return 0;
    }
    struct node *temp = q -> front;
    int data = temp -> data;
    q -> front = temp -> next;
    free(temp);
    q->count--;
    if(q ->  front == NULL) {
        q -> rear = NULL;
    } // BU EKSIKLIK BU NE HATAYI VERIR
    return data;
}
void printQueue(struct queue *q) {
    if(q-> count == 0) {
        printf("Kuyrugunuz bostur...\n");
        return;
    }
    struct node *temp = q -> front;
    int sayac = 1;
    do {
        printf("%d.Eleman = %d",sayac,temp->data);
        temp = temp -> next;
    }while(temp -> next != NULL); //    WHILE DONGUSU YA DA STACKTE GIBI FOR KULLANABILIRSIN
    /*
    for(int i = q -> count; i > 0; i-- ) {
        printf("%d.Eleman = %d\n",i,temp -> data);
        temp = temp -> next;
    }
     */
}
void reset(struct queue *q) {
    while(q->front != NULL) {
        int x = dequeue(&q);
    }
    //FOR DONGUSUYLE DE YAPABILIRSIN...
}
int main(){
    int veri,secim;
    struct queue q;
    initialize(&q);
    while(1){
        printf("Lutfen kuyruk dizisinde yapmak istediginiz islemi seciniz...\n");
        printf("1-Kuyruga Eleman Ekleme (Enqueue)\n");
        printf("2-Kuyruktan Eleman Cikarma (Dequeue)\n");
        printf("3-Kuyruk Bosaltma (Reset)\n");
        printf("4-Elemanlari Listele\n");
        printf("5-Cikis\n");
        scanf("%d",&secim);
        switch(secim){
            case 1:
                printf("Lutfen eklemek istediginiz degeri giriniz...\n");
                scanf("%d",&veri);
                enqueue(&q, veri);
                break;
            case 2:
                veri = dequeue(&q);
                break;

            case 3:
                reset(&q);
                break;

            case 4:
                printQueue(&q);
                break;

            case 5:
                exit(0);
                break;
        }
    }
}
