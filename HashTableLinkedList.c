#include <stdio.h>
#include <stdlib.h>
//LINKED LIST WITH HASH TABLE
#define SIZE 10
struct node {//Ayni indexde birden fazla eleman olabilecegi icin linked list yapisi kullanilir.
    int key;//anahtar
    char isim[20];//verilerin duracagi alan
    struct node * next;//bir sonraki elemani gosteren pointer
};
struct hashTable{ //hash table yapisi
    struct node *dizi[SIZE];
};
struct hashTable ht;//hash table yapisi icin bir nesne olusturulur.
void tabloOlustur(){
    int i;
    for (i=0;i<SIZE;i++){
        ht.dizi[i] = (struct node *) malloc(sizeof(struct node));//her bir index icin bellekten yer ayrilir.
        ht.dizi[i]->next=NULL; //her bir index icin next pointeri NULL yapilir.
    }
    printf("Tablo olusturuldu....\n");
}
int indexUret(int key){
    return key % SIZE;
}
int anahtarKontrol(int numara){ //ayni anahtar degerinin olup olmadigini kontrol eden fonksiyon
    int sonuc = 1;//ilk basta ayni anahtar degerinin olmadigini varsayalim.
    int index=indexUret(numara);//anahtar degerinin indexini bulur.
    struct node *temp=ht.dizi[index];//o indexdeki elemanlari tarar.
    while(temp->next!=NULL){
        temp=temp->next;
        if(temp->key==numara){//ayni anahtar degeri varsa
            sonuc=0;//0 ise ayni anahtar degerinden var demektir.
            break;
        }
    }
    if(sonuc==0)
        printf("%d numarali kisi daha oncesinde kayitli,lutfen farkli bir anahtar deger girin.\n",numara);
    return sonuc;
}
void ekle(int key){
    struct node * eleman=(struct node * )malloc(sizeof(struct node));//yeni bir eleman icin bellekten yer ayrilir.
    eleman->key = key;//elemanin anahtar degeri atanir.
    printf("Lutfen Eklemek Istediginiz Veriyi Giriniz:  ");
    scanf("%s",eleman->isim);//elemanin ismi atanir.
    eleman->next=NULL;//elemandan sonrasini NULL yapar.
    int index = indexUret(eleman->key);//elemanin indexini bulur.
    if(anahtarKontrol(eleman->key)){//ayni anahtar degerinden yoksa
        struct node *temp=ht.dizi[index];//o indexe gider
        while(temp->next!=NULL) {//son elemana kadar gider
            temp=temp->next;
        }
        temp->next=eleman;//son elemanin nextini eklenen eleman yapar.
        printf("eleman eklendi \n");
    }
}
void sil(int key){
    int sonuc=0;//ilk basta silinmek istenen elemanin olmadigini varsayalim.
    int index=indexUret(key);//silinmek istenen elemanin indexini bulur.
    struct node *temp2;
    struct node *temp=ht.dizi[index];//silinecek elemani tutar.
    while(temp->next!=NULL){
        temp2 = temp;//silinecek elemandan onceki elemani tutar.
        temp = temp->next;//silinecek elemani tutar.
        if(temp->key==key){//silinecek eleman bulunduysa
            temp2->next=temp->next;//silinecek elemanin oncesinin nextini silinecek elemanin nextine baglar.
            sonuc=1;//silme islemi basarili oldugu icin 1 yapar.
            free(temp);//silinecek elemani siler.
            break;
        }
    }
    if(sonuc==1)
        printf("%d numarali kisi silindi \n",key);
    else
        printf("%d numarali kisi bulunamadi \n",key);

}
void yazdir(){
    int i;
    for(i=0;i<SIZE;i++){
        struct node * temp=ht.dizi[i];//her bir index icin elemanlari tutar.
        printf("\nDizi[%d] -> ",i);//index numarasini yazdirir.
        while(temp->next!=NULL){
            temp=temp->next;//son elemana kadar gider.
            printf("%d : %s -> ",temp->key,temp->isim);
        }
    }
}
void ara(int key){
    int sonuc=0;//ilk basta aranan elemanin olmadigini varsayalim.
    int index =indexUret(key);//aranan elemanin indexini bulur.
    struct node *temp=ht.dizi[index];//aranan elemani tutar.
    while(temp->next!=NULL){
        temp=temp->next;//son elemana kadar gider.
        if(temp->key==key){//aranan eleman bulunduysa
            sonuc=1;//aranan elemanin oldugu icin 1 yapar.
            break;
        }
    }
    if (sonuc == 1)
        printf("%d numarali kisi bilgileri \n Numarasi:%d\n Ismi : %s \n",key,temp->key,temp->isim);
    else
        printf("%d numarali kisi bulunamadi \n",key);
}
int main(){
    tabloOlustur();
    int secim,key;
    char arr[20];
    while(1)
    {   printf("\nHash Table With Linked List\n");
        printf("Asagidaki Islemlerden Birini Seciniz: \n");
        printf("1- Eleman Ekleme\n");
        printf("2- Eleman Silme\n");
        printf("3- Listeyi Yazdirma\n");
        printf("4- Eleman Arama\n");
        printf("0- Listeden Cikis\n");
        scanf("%d",&secim);
        switch(secim)
            {
                case 1:
                    printf("Lutfen Eklemek Istediginiz Elemanin Keyini Giriniz: ");
                    scanf("%d",&key);
                    ekle(key);
                    break;
                case 2:
                    printf("\nLutfen Silinecek Verinin Keyini Giriniz: ");
                    scanf("%d",&key);
                    sil(key);
                    break;
                case 3:
                    printf("Listenin Elemanlari \n");
                    yazdir();
                    break;
                case 4:
                    printf("\n Aradiginiz kisi numarasi : ");
                    scanf("%d",&key);
                    ara(key);
                    break;
                case 0:
                    exit(0);
                    break;
                default:
                    printf("Hatali secim!\n");break;
            }
        }
    return 0;
}