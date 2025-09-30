#include<stdio.h>
#include<stdlib.h>
//HASH TABLE WITH LINEAR PROBING
//Dizimizin Bağlanacağı Struct
struct item{
    int key;
    int value;
};
struct hashtable_item{
    int flag;//her hash table iteminin bir durumu vardır bu durumlar flag değişkeninin altında tanımlanmıştır
     /*
      * flag = 0 : data yok
      * flag = 1 : data var
      * flag = 2 : data silinmiş
	  */
    struct item *data;
};
struct hashtable_item *array;//bu yapı bizim dizimizi oluşturur. bu sayede içerisinde bir flag
// değişkeni ve item'e bağlı bir pointer oluşturulur.
int size = 0;//diziye kaç eleman girildiğini tutan global değişken
int max = 10;//dizinin maks kapasitesi
//diziyi başlatan fonksiyon
void init_array(){
    int i;
    for (i = 0; i < max; i++){
	array[i].flag = 0;
	array[i].data = NULL;
    }
}
//keylerimizi indexlere çeviren fonksiyon
int hashcode(int key){
    return (key % max);
}
//eleman eklememize yarayan fonksiyon
void insert(int key, int value){
    int index = hashcode(key);
    int i = index;
    //dizimize bağlacak struct oluşturuluyor
    struct item *new_item = (struct item*) malloc(sizeof(struct item));
    new_item->key = key;
    new_item->value = value;
    //eğer yerleştirmek istediğimiz index dolu ise boş yer bulana kadar ilerliyor
    while (array[i].flag == 1){
	if (array[i].data->key == key){
		//aynı iki anahtar ile veri kaydedilmeye çalışıldığında anahtarın tuttuğu değeri günceller
		printf("\n Bu anahtar zaten var. Değer güncellendi\n");
		array[i].data->value = value;
		return;
	}
    //index i güncelliyoruz(Linear Probing)
	i = (index + 1) % max;
    //eğer i değişkeni ile index aynı değere ulaştıysa bu tablomuzun dolduğu anlamına gelir.
	if (i == index){
		printf("\n Hash Tablosu Dolu!\n");
		return;
		}
    }
	if(array[i].flag == 2 || array[i].flag == 0) {
		array[i].flag = 1;
		array[i].data = new_item;
		size++;
		printf("\n Anahtarı (%d) eklendi! \n", key);
	}
}
//elemanı hash tablosundan silen fonksiyon
void remove_element(int key){
    int index = hashcode(key);
    int  i = index;
    //aranılan elemanı tarayan döngü
    while (array[i].flag != 0){
	if (array[i].flag == 1  &&  array[i].data->key == key ){// data verilen key ile eşleştiği zaman ;
		array[i].flag = 2; // flag 2 yapılır
		array[i].data = NULL; // data NULL yapılır.
		size--;
		printf("\n Anahtari (%d) kaldirildi! \n", key);
		return;
	}
    //index i güncelliyoruz(Linear Probing)
	i = (index + 1) % max;
	if (i == index){
		break;
		}
    }
    printf("\n Bu Anahtar Listede Bulunamadi! \n");
}
//hash tablosunu ekrana yazdıran fonksiyon
void display(struct hashtable_item *array){
    int i;
    for (i = 0; i < max; i++){
	struct item *current = array[i].data;
	if (current == NULL){
	    printf("\n Array[%d] has no elements \n", i);
	}
	else{
	    printf("\n Array[%d] has elements -: \n  %d (key) and %d(value) ", i, current->key, current->value);
		}
    }
}
void search(int key) {
	int index = hashcode(key);
	int i = index;
	while(array[i].flag != 0) {
		if (array[i].flag == 1  &&  array[i].data->key == key ){// data verilen key ile eşleştiği zaman ;
			printf("Index: %d, Anahtar: %d, Deger: %d\n",i,array[i].data->key, array[i].data->value);
			return;
		}
		//index i güncelliyoruz(Linear Probing)
		i = (index + 1) % max;
		if (i == index){
			break;
		}
	}
	printf("Aranan Anahtar Bulunamadi\n");
}
int size_of_hashtable(){
    return size;
}
int main(){
	int secim, key, value, n;
	array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item));
	init_array();
	while(1){
		printf("\nHashtable");
		printf("\n1.Hash Tablosuna Bir Eleman Eklemek");
        printf("\n2.Hash Tablosundan Bir Eleman Cikarmak");
        printf("\n3.Hash Tablosunun Boyutunu Yazdir");
        printf("\n4.Hash Tablosunu Yazdir");
        printf("\n5-Hash Tablosunda Eleman Aramak");
		printf("\n6-Cikis");
		printf("\n\n Lutfen Bir Secim Yapiniz= ");
		scanf("%d", &secim);
		    switch(secim){
    		    case 1:
                      printf("Anahtar Degerini Giriniz=");
		              scanf("%d",&key);
                      printf("Veriyi Giriniz=");
                      scanf("%d",&value);
        	          insert(key, value);
	    	        break;
		        case 2:
	        	      printf("Hash Tablosundan Eleman Silmek için Silinecek Anahtarı Giriniz=");
        		      scanf("%d", &key);
    		          remove_element(key);
		            break;
		        case 3:
		              n = size_of_hashtable();
		              printf("Hash Tablosunun Boyutu:%d\n", n);
		            break;
		        case 4:
		              display(array);
		    	      break;
                case 5:
                	  printf("Aranacak Anahtari Giriniz:");
					  scanf("%d", &key);
					  search(key);
					  break;
		        case 6:
		    		for (int i = 0; i < max; i++) {
		    			if (array[i].flag == 1) {
		    				free(array[i].data);
		    			}
		    		}
		    		free(array);
		    		exit(0);
				default:
		            printf("Yanlış Secim!\n");
		    }
	}
}