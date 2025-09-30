#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5
// DIZIYLE YAPILMIS KUYRUK YAPISI
struct queue {
    int data[QUEUE_SIZE];//bu da dizi iste
    int count;//toplam eleman sayisi
    int rear;//son elemanin indexi
    int front;//ilk elemanin indexi
};
void enqueue(struct queue *q,int veri) {
    if(q->count == QUEUE_SIZE) { //rear koyarsak sikinti olabilir dizi yapisina gore eger rear fronttan once geliyorsa o liste bir kere dolmustur.
        printf("Kuyrugunuz doludur...\n");
        return;
    }
    if(q->rear != QUEUE_SIZE - 1) {//bu durumda rear dizinin son elemaninin indexinden kucukse rear++ yapariz
        q->rear++;
    }
    else { //eger rear dizinin son elemaninin indexine esitse rear 0 yapariz
        q->rear = 0;
    }
    q->count++;
    q->data[q->rear] = veri;
}
int dequeue(struct queue *q) {
    if(q-> count == 0) {
        printf("Kuyrugunuz bostur...\n");
        return 0;
    }
    int x = q->data[q->front];
    q->count--;
    if(q->front != QUEUE_SIZE) {
        q->front++;
    }
    else {
        q->front = 0;
    }
    printf("%d elemani cikarilmistir...\n",x);
    q->count--;
    return x;
}
void printQueue(struct queue *q) {
    if(q-> count == 0) {
        printf("Kuyrugunuz bostur...\n");
        return;
    }
    int i = q->front -1;
    do {
        i++;
        i %= QUEUE_SIZE;
        printf("%d\n",q->data[i]);
    }while(i != q->rear);
}
void reset(struct queue *q) {
    q->count = 0;
    q->rear = -1;
    q->front = 0;
}
void initialize(struct queue *q) {
    q -> count = 0;
    q -> front = 0;
    q -> rear = -1;
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
