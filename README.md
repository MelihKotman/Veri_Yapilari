<h1 align="center">📚 Veri Yapıları – C ile Uygulamalar</h1>

<p align="center">
  <b>C programlama dili ile yazılmış kapsamlı veri yapıları ve algoritmalar arşivi</b><br>
  <i>Bağlı listelerden AVL ağaçlarına, graf algoritmalarından hashing yapısına kadar...</i>
</p>

---

## 🚀 Proje Hakkında

Bu repo, **Veri Yapıları** dersi boyunca yazdığım C dili örneklerinden oluşur. Her dosya bir veri yapısını veya algoritmayı bağımsız şekilde anlatan örnek kod içerir.  
Kodlar hem derste pratik yapmak hem de algoritmaları derinlemesine anlamak için tasarlanmıştır.

> **🔧 Not:** Tüm `.c` dosyaları bağımsız çalıştırılabilir. Dilersen tek tek derleyip çalıştırabilirsin.

---

## 🧠 Kapsanan Konular

### 🔷 1. Bağlı Listeler
- `TekBagliDogrusalList.c` → Tek yönlü bağlı liste  
- `TekBagliDaireselList.c` → Dairesel bağlı liste (tek yönlü)  
- `CiftBagliDogrusalList.c` → Çift yönlü klasik bağlı liste  
- `CiftBagliDaireselList.c` → Dairesel çift yönlü liste  

---

### 🧱 2. Stack & Queue Yapıları
- `StackDizisi.c` ve `StackList.c` → Yığınlar (dizi ve bağlı liste ile)  
- `QueueDizisi.c` ve `QueueList.c` → Kuyruklar (dizi ve bağlı liste ile)

---

### 🌳 3. Ağaç (Tree) Yapıları
- `BinaryTree.c` → Temel ikili ağaç  
- `AVLTree.c` → AVL denge ağaçları  
- `Heap.c` → Min-Heap & Max-Heap

---

### 🕸️ 4. Grafikler ve Algoritmalar
- `Graphs.c` & `GraphOrnegi.c` → Temel graph tanımı ve örnek  
- `DijkstraAlgoritmasi.c` → Dijkstra ile en kısa yol  
- `BellmanFordAlgoritmasi.c` → Negatif ağırlık destekli yol bulma  

---

### 🔐 5. Hash Tablolar
- `HashTableLinkedList.c` → Chaining ile hashing  
- `LinearHashTable.c` → Linear probing tekniği  
- `QuadraticHashTable.c` → Quadratic probing yöntemi

---

### 🌀 6. Sıralama Algoritmaları
- `SortingAlg.c` → Bubble Sort, Insertion Sort, Selection Sort gibi temel sıralamalar  

---

### 🧪 7. Ekstra Çalışmalar
- `SınavSoru.c` → Uygulamalı sınav örneği veya soru çözümü  
- `CMakeLists.txt` → CMake proje dosyası  
- `.idea/`, `cmake-build-debug/` → CLion gibi IDE'lere ait yapılandırmalar (önemsiz dosyalar)

---

## 🛠️ Derleme ve Çalıştırma

### Terminal Üzerinden:
```bash
gcc AVLTree.c -o avl
./avl
