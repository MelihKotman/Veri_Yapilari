#include <stdio.h>
#include <stdlib.h>
// Yigin ve Bagli Liste Birlesimi
struct node {
    int data;
    struct node *next;
};
struct stack {
    struct node *top;
    int cnt;
};
void push(struct stack *stk, int veri) {
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = veri;
    temp->next = stk->top;
    stk->top = temp;
    stk->cnt++;
}
int pop(struct stack *stk) {
    if(stk -> top == NULL) { //stk->cnt == 0 diyebiliriz...
        printf("Liste yigininiz bos\n");
        return -1;
    }
    else {
        struct node *temp = stk -> top;
        int x = temp -> data;
        stk -> top = temp -> next; // ama stk -> top -> next de diyebiliriz...
        free(temp);
        stk -> cnt--;
        printf("%d elemani cikarilmistir...\n",x);
        return x;
    }
}
void reset(struct stack *stk) {
    if(stk -> cnt == 0) {
        printf("Liste yigininiz zaten bos\n");
        return;
    }
    struct node *temp = stk -> top;
    while(temp != NULL) {
        struct node *temp2 = temp;
        temp = temp -> next;
        free(temp2);
    }
    /**
     while(stk -> top != NULL){
         int x = pop(&stk);
    }
    **/
    stk -> cnt = 0;
    printf("Liste yigininiz bosaltildi...\n");
}
void printStk(struct stack *stk) {
    if(stk -> cnt == 0) {
        printf("Liste yigininiz bos...\n");
        return;
    }
    struct node *temp = stk -> top;
    for(int i = stk -> cnt; i > 0; i-- ) {
        printf("%d.Eleman = %d\n",i,temp -> data);
        temp = temp -> next;
    }
}
int main(){
    int veri,secim;
    struct stack stk;
    stk.top = NULL;
    stk.cnt = 0;
    while(1){
        printf("Lutfen bagli liste yiginda yapmak istediginiz islemi seciniz...\n");
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
                printStk(&stk);
            break;

            case 5:
                exit(0);
            break;

        }
    }
}

