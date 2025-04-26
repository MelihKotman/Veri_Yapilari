#include<stdio.h>
#include<stdlib.h>
//Dizilerle Heap Islemi
# define HEAP_SIZE 4
struct Heap {
    int size;
    int data[HEAP_SIZE];
};
void heapify_MaxHeap(struct Heap *heap,int index) {
    if(heap -> size == 0) {
        printf("Dizi Bos\n");
        return;
    }
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(left < heap -> size && heap -> data[left] > heap -> data[largest]) {
        largest = left;
    }
    if(right < heap -> size && heap -> data[right] > heap -> data[largest]) {
        largest = right;
    }
    if(largest != index) {
        int temp = heap->data[index];
        heap->data[index] = heap->data[largest];
        heap->data[largest] = temp;
        heapify_MaxHeap(heap,largest);
    }
}
void heapify_MinHeap(struct Heap *heap,int index) {
    if(heap -> size == 0) {
        printf("Dizi Bos\n");
        return;
    }
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(left < heap -> size && heap -> data[left] < heap -> data[smallest]) {
        smallest = left;
    }
    if(right < heap -> size && heap -> data[right] < heap -> data[smallest]) {
        smallest = right;
    }
    if(smallest != index) {
        int temp = heap->data[index];
        heap->data[index] = heap->data[smallest];
        heap->data[smallest] = temp;
        heapify_MinHeap(heap,smallest);
    }
}
void insertMaxHeap(struct Heap *heap,int value) {
    if(heap -> size == HEAP_SIZE) {
        printf("Diziniz Dolu\n");
        return;
    }
    heap -> data[heap -> size] = value;
    heap -> size++;
    for(int i = heap -> size / 2 - 1; i >= 0; i--) { //Heap degerlerini yeniden duzenleme
        heapify_MaxHeap(heap,i);
    }
}
void insertMinHeap(struct Heap *heap, int value) {
    if(heap ->size == HEAP_SIZE) {
        printf("Diziniz Dolu\n");
        return;
    }
    heap -> data[heap -> size] = value;
    heap -> size++;
    for(int i = heap -> size / 2 - 1; i >= 0; i--) {
        heapify_MinHeap(heap,i);
    }
}
int deleteMaxHeap(struct Heap *heap) {
    if(heap -> size == 0) {
        printf("Diziniz Bos\n");
        return -1;
    }
    int root = heap -> data[0];
    heap -> data[0] = heap -> data[heap -> size - 1];
    heap -> size--;
    for(int i = heap -> size / 2 - 1; i >= 0; i--) {
        heapify_MaxHeap(heap,i);
    }
    return root;
}
int deleteMinHeap(struct Heap *heap) {
    if(heap -> size == 0) {
        printf("Diziniz Bos\n");
        return -1;
    }
    int root = heap -> data[0];
    heap -> data[0] = heap -> data[heap -> size - 1];
    heap -> size--;
    for(int i = heap -> size / 2 - 1; i >= 0; i--) {
        heapify_MinHeap(heap,i);
    }
    return root;
}
void printHeap(struct Heap *heap) {
    for(int i = 0; i < heap->size; i++) {
        printf("%d ",heap -> data[i]);
    }
    printf("\n");
}

int main() {
    struct Heap heap;
    heap.size = 0;
    int secim,deger,altSecim;
    while(1) {
        printf("Heap Yapisi\n");
        printf("1-Maximum Heap Islemi\n");
        printf("2-Minimum Heap Islemi\n");
        printf("3-Cikis\n");
        scanf("%d",&secim);
        switch(secim) {
            case 1:
                printf("1-Ekle(Insert)\n");
                printf("2-Sil(Delete)\n");
                printf("3-Yazdir\n");
                printf("4-Cikis\n");
                scanf("%d",&altSecim);
                if(altSecim == 4) {
                    exit(0);
                }
                switch(altSecim) {
                    case 1:
                        printf("Lutfen eklenecek deger giriniz\n");
                        scanf("%d",&deger);
                        insertMaxHeap( & heap,deger);
                        break;
                    case 2:
                        deger = deleteMaxHeap(&heap);
                        printf("Silinen Deger: %d\n",deger);
                        break;
                    case 3:
                        printHeap(&heap);
                        break;
                    default:
                        printf("Gecersiz Secim\n");
                }
                break;
            case 2:
                printf("1-Ekle(Insert)\n");
                printf("2-Sil(Delete)\n");
                printf("3-Yazdir\n");
                printf("4-Cikis\n");
                scanf("%d",&altSecim);
                if(altSecim == 4) {
                exit(0);
                 }
            switch(altSecim) {
                case 1:
                    printf("Lutfen eklenecek deger giriniz\n");
                    scanf("%d",&deger);
                    insertMinHeap( & heap,deger);
                    break;
                case 2:
                    deger =deleteMinHeap(&heap);
                    printf("Silinen Deger: %d\n",deger);
                    break;
                case 3:
                    printHeap(&heap);
                    break;
                default:
                    printf("Gecersiz Secim\n");
            }
            case 3:
                exit(0);
                break;
            default:
                printf("Gecersiz Secim\n");
        }
    }
}