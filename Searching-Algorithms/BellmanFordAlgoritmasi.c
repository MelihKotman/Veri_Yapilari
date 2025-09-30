#include <stdio.h>
#include <limits.h> // INT_MAX icin

#define V 6  // Toplam dugum sayisi

void bellmanFord(int graph[V][V], int src) {
    int dist[V];

    // Tüm mesafeleri sonsuz olarak ayarla
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;/*C dilinde limits.h başlık dosyasında tanımlı bir sabittir.
                           Algoritmalarda ve programlarda sonsuz değerini temsil etmek için kullanılır.*/
    }
    dist[src] = 0;  // Kaynak dugumun mesafesi 0

    // Tum kenarlar icin (V-1) kez guncelleme yap
    for (int k = 0; k < V - 1; k++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    /* dist[u] + graph[u][v] < dist[v] şartı sağlanıyorsa, dist[v] güncellenir:
     dist[u]: U düğümüne olan en kısa mesafe.
     graph[u][v]: U ve V arasındaki kenarın ağırlığı.
     dist[v]: V düğümüne olan en kısa mesafe, gerekiyorsa güncellenir.*/

    // Negatif dongu kontrolu (Amaç halen güncelleme oluyor mu onu kontrol etmek)
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                printf("Grafikte negatif bir dongu var.\n");
                return;
            }
        }
    } //Güncelleme olduğunda negatif döngü uyarısı verir.

    /* Güncelleme aşamasında: Tüm kenarların tekrar tekrar güncellenmesi gerekebilir,
    çünkü bir düğüme olan mesafe değişirse, bu değişiklik komşu düğümleri de etkileyebilir.
    Negatif döngü kontrolünde: Tüm kenarları bir kez kontrol etmek yeterlidir.
    Eğer bir mesafe hâlâ güncellenmek isteniyorsa, bu negatif bir döngü olduğunu kanıtlar.*/

    // Sonucları yazdır
    printf("Dugum\tMesafe\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d\tINF\n", i);
        } else {
            printf("%d\t%d\n", i, dist[i]);
        }
    }
}

int main() {
    // Agırlıklı komsuluk matrisi
    int graph[V][V] = {
 {0, 3, -1, 0, 0, 0},
  {0, 0, 0, 0, 2, 0},
  {0, 5, 0, -3, 0, 0},
  {0, 0, 0, 0, 4, 0},
  {0, 0, 7, 0, 0, 5},
  {0, 0, 0, -10, 0, 0}
}
    /*
    int graph[V][V] = {
        {0, 3, -1, 0, 0, 0},
        {0, 0, 0, 0, 2, 0},
        {0, 5, 0, -3, 0, 0},
        {0, 0, 0, 0, 4, 6},
        {0, 0, 7, 0, 0, 5},
        {0, 0, 0, 0, 0, 0}
    }
    */
  ; /*Negatif döngü kontrolü işe yarıyor mu onu kontrol etmek için F düğümünden D düğümüne olan
   ağırlıklı kenarın yönünü ve değerini değiştiriyorum*/

    // Bellman-Ford algoritmasini calistir
    bellmanFord(graph, 0);

    return 0;
}