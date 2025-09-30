/*PREORDER
 *10-12-3-4-6-7-5-11-2-8
 *INORDER
 *3-12-6-4-7-10-11-5-2-8
 *POSTORDER
 *3-6-7-4-12-11-8-2-5-10
 *ORNEK-3 SINAV SORUSU ORNEGI
 *Bir dugumden birden fazla yol gider
 *Gercek dunya problemlere agac veri yapilari daha(uygun) avantajlı. Ozellikle script(html,css,xml) dili uyg.larda
 *Bellek fazla yer kapliyor(dezavantajli)
 *Her agac bir graftir ama her graf agac degildir
 *Tum agaclarda bir kok vardir
 *Slayttaki tablo ornegi sinavda cikabilir
 *Preorder : 25-15-10-4-12-22-18-24-50-35-31-44-70-66-90
 *Inorder  : 4-10-12-15-18-22-24-25-31-35-44-50-66-70-90
 *Postorder: 4-12-10-18-24-22-15-31-44-35-66-90-70-50-25
 *Ornek-4
 *Preorder : 25-14-7-5-10-7-23-17-24-23-40-34-36-48
 *Inorder  : 5-7-7-10-14-17-23-23-24-25-34-36-40-48
 *Postorder: 5-7-10-7-17-23-24-23-14-36-34-48-40-25
 *Ornek-5
 *Bir binary agacta, bir n derinligindeki maksimum node sayisi 2^n (root 0 oldugunda) ile ilgili soru sinav sorusu
 *k derinligindeki sahip bir binary agacta maksimum node sayisi 2^(k+1) - 1'dir  */
// Balance Tree ile ilgili bir soru gelecek
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *new_node(int data) {
    struct node *p = (struct node*) malloc(sizeof(struct node));
    p -> data = data;
    p -> left = NULL;
    p -> right = NULL;
    return p;
}
struct node *insert(struct node *root, int data) {
    if(root != NULL) {
        if(data < root -> data) {
            root -> left = insert(root -> left, data);
        }
        else {
            root -> right = insert(root -> right, data);
        }
    }else {
        root = new_node(data);
    }
    return root;
}
void print_preOrder(struct node *root) {
    if(root != NULL) {
        printf("%d-",root ->data);
        print_preOrder(root -> left);
        print_preOrder(root -> right);
    }
}
void print_inOrder(struct node *root) {
    if(root != NULL) {
        print_inOrder(root->left);
        printf("%d-", root -> data);
        print_inOrder(root -> right);
    }
}
void print_postOrder(struct node *root) {
    if(root != NULL) {
        print_postOrder(root->left);
        print_postOrder(root->right);
        printf("%d-",root -> data);
    }
}
int main(){
    int veri,secim;
    struct node *my_root = NULL;
 while(1){
      printf("Lutfen agacta yapmak istediginiz islemi seciniz...\n");
      printf("1-Agaca Eleman Ekleme\n");
      printf("2-Elemanlari Listele(Preorder)\n");
      printf("3-Elemanlari Listele(Inorder)\n");
      printf("4-Elemanlari Listele(Postorder)\n");
      printf("5-Cikis\n");
      scanf("%d",&secim);
      switch(secim){
          case 1:
              printf("Lutfen eklemek istediginiz degeri giriniz...\n");
              scanf("%d",&veri);
              my_root = insert(my_root,veri);
              break;
          case 2:
              print_preOrder(my_root);
              break;
          case 3:
              print_inOrder(my_root);
              break;
          case 4:
              print_postOrder(my_root);
              break;
          case 5:
              exit(0);
              break;
            }
        }
    }
