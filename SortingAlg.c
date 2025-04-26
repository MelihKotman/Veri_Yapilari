//Siralama algoritmalari yapan menü
#include <stdio.h>
#include <stdlib.h>
void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void printDizi(int dizi[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}
void bubbleSort(int dizi[], int n) {
    int i,j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (dizi[j] > dizi[j+1]) {
                swap(&dizi[j], &dizi[j+1]);
                printDizi(dizi,  n);
            }
        }
    }
}
void selectionSort(int dizi[], int n) {
    int i, j, min_index;
    for (i = 0; i < n - 1; i++) {
        min_index = i; // ilk elemanı minimum kabul ediyoruz
        for (j = i + 1; j < n; j++) {
            if (dizi[j] < dizi[min_index]) { // minimum elemanı bulana kadar devam ediyoruz
                min_index = j;
            }
        }
        swap(&dizi[min_index], &dizi[i]); //bulunan minimum elemanı i indexini ile yer değiştiriyoruz
        printDizi(dizi,  n);
    }
}
void insertionSort(int dizi[],int n) {
    int i,j;
    for(i = 1; i < n; i++) {
        int key = dizi[i]; // anahtar elemanı kaydediyoruz ve bu elemanı solundaki elemanlarla karşılaştıracağız
        j = i - 1;
        while(j >= 0 && dizi[j] > key) {
            dizi[j+1] = dizi[j]; // anahtar elemandan büyük olan elemanları sağa kaydırıyoruz
            j = j - 1;

        }
        dizi[j+1] = key; // anahtar elemanı uygun yere yerleştiriyoruz
        printDizi(dizi,n);
    }
}
void merge(int dizi[],int sol,int orta, int sag) {
    int dizi_sol = orta - sol + 1; // sol dizinin boyutu
    int dizi_sag = sag - orta; // sağ dizinin boyutu

    int L[dizi_sol], R[dizi_sag]; // geçici diziler

    for(int i = 0; i < dizi_sol; i++) {
        L[i] = dizi[sol + i]; // sol diziyi geçici diziye kopyalıyoruz
    }
    for(int j = 0; j < dizi_sag; j++) {
        R[j] = dizi[orta + 1 + j]; // sağ diziyi geçici diziye kopyalıyoruz
    }
    int i = 0, j = 0, k = sol;
    while(i < dizi_sol && j < dizi_sag) { // geçici dizilerdeki elemanları karşılaştırıyoruz
        if(L[i] <= R[j]) { // iki dizinin elemanlarını karşılaştırıp küçük olanı sırasıyla ana diziye yerleştiriyoruz
            dizi[k] = L[i];
            i++;
        }
        else {
            dizi[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < dizi_sol) { // kalan elemanları ana diziye yerleştiriyoruz
        dizi[k] = L[i];
        i++;
        k++;
    }
    while(j < dizi_sag) { // kalan elemanları ana diziye yerleştiriyoruz
        dizi[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int dizi[],int sol,int sag) {
    if(sol < sag) { // dizinin boyutu 1'den büyükse
        int orta = sol + (sag - sol) / 2; // diziyi ikiye bölüyoruz

        mergeSort(dizi, sol, orta); // sol diziyi sıralamak için mergeSort fonksiyonunu recursive olarak çağırıyoruz ve tek eleman kalana kadar devam ediyoruz
        mergeSort(dizi, orta + 1, sag); // aynı işlemi sağ diziyi sıralamak için yapıyoruz

        merge(dizi, sol, orta, sag); // sıralanmış dizileri birleştiriyoruz
    }
}
//Lomuto partition scheme
int Bolumleme(int dizi[],int baslangic,int bitis) {
    int pivot = dizi[bitis]; // pivot elemanı seçiyoruz
    int i = (baslangic - 1); // indeximiz -1'den başlıyor

    for(int j = baslangic; j <= bitis - 1; j++) {
        if(dizi[j] < pivot) { // pivot elemanından küçük olanları sol tarafa atıyoruz
            i++;
            swap(&dizi[i], &dizi[j]);
        }
    }
    swap(&dizi[i + 1], &dizi[bitis]); // pivot elemanını doğru yere yerleştiriyoruz
    return (i + 1);
}
void quickSort(int dizi[],int baslangic,int bitis) {
    if(baslangic < bitis) { // dizinin boyutu 1'den büyükse
        int pivot = Bolumleme(dizi, baslangic, bitis); // diziyi ikiye bölüyoruz ve pivot elemanını buluyoruz

        quickSort(dizi, baslangic, pivot - 1); // sol taraftaki elemanlar için recursive olarak quickSort fonksiyonunu çağırıyoruz
        quickSort(dizi, pivot + 1, bitis); // sağ taraftaki elemanlar için recursive olarak quickSort fonksiyonunu çağırıyoruz
    }
}
//YOK HEAP VE SHELL SORT
void heapify(int dizi[],int boyut,int i) {
    int en_buyuk = i; // en büyük elemanı bulmak için en büyük elemanı en başta kabul ediyoruz
    int sol = 2 * i + 1; // her bir elemanın sol çocuğu
    int sag = 2 * i + 2; // her bir elemanın sağ çocuğu
    if(sol < boyut && dizi[sol] > dizi[en_buyuk]) { // sol çocuk elemanı en büyük elemandan büyükse
        en_buyuk = sol;  // en büyük elemanı sol çocuk elemanı olarak kabul ediyoruz
    }
    if(sag < boyut && dizi[sag] > dizi[en_buyuk]) {  // sağ çocuk elemanı en büyük elemandan büyükse
        en_buyuk = sag; // en büyük elemanı sağ çocuk elemanı olarak kabul ediyoruz
    }
    if(en_buyuk != i) { // en büyük eleman kök eleman değilse burada yer değiştirme işlemi yapılır
        swap(&dizi[i], &dizi[en_buyuk]);
        heapify(dizi, boyut, en_buyuk); // en büyük elemanın çocukları ile tekrar heapify fonksiyonunu çağırıyoruz
    }
}
void heapSort(int dizi[],int boyut) {
    for(int i = boyut / 2 - 1; i >= 0; i--) {
        heapify(dizi, boyut, i); //bu döngüde diziyi heap yapısına çeviriyoruz
    }
    for(int i = boyut - 1; i > 0; i--) { //bu döngüde diziyi sıralıyoruz
        swap(&dizi[0], &dizi[i]); //kök elemanı en sona alıyoruz
        heapify(dizi, i, 0);//kök elemanı en sona aldıktan sonra diziyi tekrar heap yapısına çeviriyoruz
    }
}
void shellSort(int dizi[],int boyut) {
    int i, j, ara_deger; // ara değişken
    for(ara_deger = boyut / 2; ara_deger > 0; ara_deger /= 2) { // ara değişkeni boyutun yarısından başlayarak 1'e kadar azaltıyoruz
        for(i = ara_deger; i < boyut; i += 1) { // ara değişkenden başlayarak dizinin sonuna kadar devam ediyoruz
            int temp = dizi[i]; // geçici değişken
            for(j = i; j >= ara_deger && dizi[j - ara_deger] > temp; j -= ara_deger) { // ara değişkenden başlayarak dizinin başına kadar devam ediyoruz
                dizi[j] = dizi[j - ara_deger]; // ara değişkenden büyük olan elemanları sağa kaydırıyoruz
            }
            dizi[j] = temp; // geçici değişkeni uygun yere yerleştiriyoruz
            printDizi(dizi, boyut);
        }
    }
}
int main() {
    int dizi[10] = { 12, 11, 13, 8, 4, 7, 5, 9, 10, 1 };
    int dizi2[10] = { 12, 11, 13, 8, 4, 7, 5, 9, 10, 1 };
    int i, j, temp;
     int secim;
        while(1){
            printf("Lutfen yapmak istediginiz siralama islemi seciniz...\n");
            printf("1-Bubble Sort ile Yap\n");
            printf("2-Selection Sort ile Yap\n");
            printf("3-Insertion Sort ile Yap\n");
            printf("4-Merge Sort ile Yap\n");
            printf("5-Quick Sort ile Yap\n");
            printf("6-Heap Sort ile Yap\n");
            printf("7-Shell Sort ile Yap\n");
            printf("8-Cikis Yap\n");
            scanf("%d",&secim);
            if(secim <= 0 && secim > 8){
                printf("Yanlis sayi girdiniz tekrar giriniz...\n");
                continue;
            }
            else if(secim <= 8 && secim > 0){
                switch(secim){
                    case 1:
                        bubbleSort(dizi, 10);
                        for(int i = 0; i < 10; i++){
                            dizi[i] = dizi2[i];
                        }
                    break;
                    case 2:
                        selectionSort(dizi, 10);
                        printf("\n");
                        printDizi(dizi, 10);
                        for(int i = 0; i < 10; i++){
                             dizi[i] = dizi2[i];
                        }
                    break;
                    case 3:
                        insertionSort(dizi, 10);
                        printf("\n");
                         for(int i = 0; i < 10; i++){
                             dizi[i] = dizi2[i];
                        }
                    break;
                    case 4:
                        mergeSort(dizi, 0, 9);
                        printDizi(dizi, 10);
                        for(int i = 0; i < 10; i++){
                            dizi[i] = dizi2[i];
                        }
                    break;
                    case 5:
                        quickSort(dizi, 0, 9);
                        printDizi(dizi, 10);
                         for(int i = 0; i < 10; i++){
                                dizi[i] = dizi2[i];
                        }
                        break;
                    case 6:
                        heapSort(dizi, 10);
                        printDizi(dizi,10);
                        for(int i = 0; i < 10; i++){
                            dizi[i] = dizi2[i];
                        }
                        printf("\n");
                        break;
                    case 7:
                        shellSort(dizi, 10);
                        printDizi(dizi,10);
                        for(int i = 0; i < 10; i++){
                            dizi[i] = dizi2[i];
                        }
                        printf("\n");
                        break;
                    case 8:
                        exit(0);
                        break;
                }
            }
        }
}
