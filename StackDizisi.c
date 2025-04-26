#include <stdio.h>
#include <stdlib.h>
//Stack(Yigit) İslemi
#define STACK_SIZE  4
struct stack {
    int data[STACK_SIZE];
    int top;
};
void push(struct stack *stk, int veri) {
    if(stk -> top == STACK_SIZE - 1) {
        printf("Stack dolu...\n");
    }
    else {
        stk -> top++;
        stk -> data[stk -> top] = veri;
    }
}
int pop(struct stack *stk) {
    if(stk -> top == -1) {
        printf("Stack bostur\n");
        return -1;
    }
    else {
        printf("%d elemani listenizden cikarilmistir...\n",stk -> data[stk->top]);
        int x = stk -> top--;
        return x;
    }
}
void reset(struct stack *stk) {
    stk -> top = -1;
}
void printList(struct stack *stk) {
    if(stk -> top == -1) {
        printf("Stack bostur\n");
        return;
    }
    int temp = stk -> top;
    int sayac = 1;
    while(temp  != -1) {
        printf("%d. ELeman = %d\n",sayac,stk -> data[temp]);
        temp--;
        sayac++;
    }
}
int main(){
    int veri,secim;
    struct stack stk;
    stk.top = -1;
   while(1){
    printf("Lutfen yiginda yapmak istediginiz islemi seciniz...\n");
    printf("1-Yigina Eleman Ekleme (Push)\n");
    printf("2-Yigindan Eleman Cikarma (Pop)\n");
    printf("3-Yigin Bosaltma (Reset)\n");
    printf("4-Elemanlari Listele\n");
    printf("5-Cikis\n");
    scanf("%d",&secim);
    switch(secim){
    case 1:
        printf("Lutfen eklemek istediginiz degeri giriniz...\n");
        scanf("%d",&veri);
        push(&stk, veri);
        break;

    case 2:
        veri = pop(&stk);
        break;

    case 3:
        reset(&stk);
        break;

    case 4:
        printList(&stk);
        break;

    case 5:
        exit(0);
        break;

   }
}
}
