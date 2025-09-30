#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Dugumler arasindaki en kisa yolu bulan Dijkstra algoritmasi
#define V 5  // Grafin toplam dugum sayisi

// Minimum mesafeye sahip olan dugumu bulma fonksiyonu
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, minIndex = -1;  // minIndex'i -1 olarak baslatiyoruz
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] < min) {  // dist[v] < min yaparak en kucuk mesafeyi kontrol ediyoruz
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Dijkstra algoritmasi
void dijkstra(int graph[V][V], int src) {
    int dist[V];  // Kaynak dugumden diger dugumlere olan en kisa mesafeleri tutar
    int sptSet[V];  // Shortest Path Tree (SPT) kumesi, en kisa yolun bulundugu dugumleri icerir

    // Tum mesafeleri baslangicta sonsuz (INT_MAX) olarak belirle
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // Baslangic dugumune olan mesafeyi 0 yap
    dist[src] = 0;

    // Tum dugumler icin en kisa yolu bul
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);  // En kucuk mesafeye sahip dugumu sec

        // Secilen dugumu SPT kumesine ekle
        sptSet[u] = 1;

        // Komsulari guncelle
        for (int v = 0; v < V; v++) {
            // Guncellenmesi gereken komsu dugumleri kontrol et
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Sonuclari yazdir
    printf("Dugum\tMesafe\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d\tINF\n", i);  // Ulasilamayan dugumleri "INF" olarak yazdir
        } else {
            printf("%d\t%d\n", i, dist[i]);
        }
    }
}

int main() {
    // Agirlikli komsuluk matrisi (graph)
    int graph[V][V] = {
        {0, 5, 2, 0, 0, }, //son elemandan sonra virgül koymak zorunlu değil ama kodun okunabilirliği açısından virgül koymak iyi bir alışkanlıktır.
        {0, 0, 8, 0, 6, },
        {0, 0, 0, 7, 0, },
        {0, 0, 0, 0, 4, },
        {0, 0, 3, 0, 0, },
    };

    // Dijkstra algoritmasını baslat
    dijkstra(graph, 0);  // 0. dugumden basla (A dugumu)

    return 0;
}