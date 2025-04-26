#include <stdio.h>

int main() {
    //Asal carpanlara ayirma
    /*int sayi = 612;
    for(int i = 2;sayi > 1;i++){
        if(sayi % i == 0){
            printf("%d ",i);
            sayi /= i;
            i--;
        }
    }*/
    //Dizi islemleri ve pointerlar
    int dizi[] = {15,4,11,7,3};
    int *p;
    p = &dizi[0];
    printf("%d",*p+dizi[2]);
    for(int i = 2; i < 3;i++) {
        p[i] += 11;
    }
    p++;
    printf("%d\n",--*p);
}