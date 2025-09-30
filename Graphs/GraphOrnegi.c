#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Grafların temsil edilmesi için kullanılan yapı
struct node {
    char label[15];
    int komsu_sayisi;

    struct node *komsular[100];
    struct node *next; // yol olmazsa da dugumlere ulasmak icin next pointeri ekledik
};
struct node *start = NULL; // baslangic dugumu
struct node *last = NULL; // son dugum
struct node *temp = NULL; // gecici dugum
struct node *harftenDugum = NULL; // harften dugum olusturduk
void sehirEkle(char sehirHarf[]) {
    struct node *current = (struct node*) malloc(sizeof(struct node));
    strcpy(current->label ,sehirHarf); // sehir ismini kopyalıyoruz
    current -> komsu_sayisi = 0;
    current -> next = NULL;

    if(start == NULL) { // eğer başlangıç düğümü boşsa
        start = current;
        last = current;
    }
    else { // eğer başlangıç düğümü doluysa
        last -> next = current;
        last = current;
    }
}
void sehirYazdir() {
    temp = start;
    while(temp != NULL) {
        printf("%s\n",temp -> label);
        temp = temp -> next;
    }
}
void dugumGetir(char label[]) {
    temp = start;
    while(temp != NULL) {
        if(strcmp(temp -> label,label) == 0) { //strcmp fonksiyonu ile iki stringi karşılaştırıyoruz ve eşitliği kontrol ediyoruz
            harftenDugum = temp; // eger iki string birbirine eşitse o düğümü harftenDugum'a atıyoruz
            return;
        }
        temp = temp -> next;
    }
    harftenDugum = NULL; // eger harftenDugum NULL ise o dugum yok demektir
}
void komsuEkle(char vertex1[15],char vertex2[15]) {
    dugumGetir(vertex1);
    struct node *v1 = harftenDugum;
    dugumGetir(vertex2);
    struct node *v2 = harftenDugum;
    if(v1 != NULL && v2 != NULL) {
        v1 -> komsular[v1 -> komsu_sayisi] = v2;
        v1 -> komsu_sayisi++;
        v2 -> komsular[v2 -> komsu_sayisi] = v1;
        v2 -> komsu_sayisi++;
    }
    else {
        printf("Hata: Sehirlerden biri bulunamadı\n");
    }
}
// bu kod girilen dugumun komsularini yazar bunu sinavda sorar ve bunu yazarsan tam cevap alırsın
void komsuYazdir(char harf[15]) {
    dugumGetir(harf);
    for(int i = 0; i < harftenDugum -> komsu_sayisi; i++) {
        printf("%s\n",harftenDugum -> komsular[i] -> label);
    }
}
int main() {
    int secim;
    char sehirHarf[15];
    char sehirHarf1[15];
    while(1) {
        printf("1-Sehir Ekle \n");
        printf("2-Sehir Yazdir \n");
        printf("3-Yol Ekle \n");
        printf("4-Yol Yazdir \n");
        printf("5-Cikis \n");
        printf("Seciminiz =\n");
        scanf("%d",&secim);
        switch(secim) {
            case 1:
                printf("Sehir ismi giriniz =\n");
                scanf("%s",sehirHarf);
                sehirEkle(sehirHarf);
                break;
            case 2:
                sehirYazdir();
                break;
            case 3:
                printf("Komsu eklemek istediginiz sehrin harfini yaziniz\n");
                scanf("%s",&sehirHarf);
                printf("Komsu eklemek istediginiz sehrin harfini yaziniz\n");
                scanf("%s",&sehirHarf1);
                komsuEkle(sehirHarf,sehirHarf1);
                break;
            case 4:
                printf("Yollari gormek istediginiz sehir harfi giriniz\n");
                scanf("%s",&sehirHarf);
                komsuYazdir(sehirHarf);
                break;
            case 5:
                exit(0);
                break;
        }
    }
}