#include <stdio.h>
#include <stdlib.h>
// Düğüm yapısının tanımı
struct Node {
    int data;           // Düğümün veri alanı (değer)
    struct Node* left;  // Düğümün sol alt ağacı
    struct Node* right; // Düğümün sağ alt ağacı
    int height;         // Düğümün yüksekliği
};
// Düğümün yüksekliğini hesaplayan fonksiyon
int getHeight(struct Node* node) {
    if (node == NULL) {
        return 0; // Eğer düğüm NULL ise, yüksekliği 0
    }
    return node->height;
}
// İki sayı arasındaki maksimum değeri döndüren fonksiyon
int max(int a, int b) {
    /*
     * if(a > b) {
     * return a;
     * } else {
     * return b;
     * }
     */
    return (a > b) ? a : b;
}
// Düğümün denge faktörünü hesaplayan fonksiyon
int getBalanceFactor(struct Node* node) {
    if (node == NULL) {
        return 0; // Eğer düğüm NULL ise, denge faktörü 0
    }
    return getHeight(node->left) - getHeight(node->right); // Sol ve sağ alt ağaçların yüksekliği farkı
}
// Yeni düğüm oluşturma fonksiyonu
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;       // Düğüm verisini atıyoruz
    node->left = NULL;       // Sol çocuk null
    node->right = NULL;      // Sağ çocuk null
    node->height = 1;        // Başlangıçta yükseklik 1
    return node;
}
// Sağ dönüş (Right Rotation) fonksiyonu
struct Node* rotateRight(struct Node* B) {
    struct Node* A = B -> left; // Sol çocuk düğüm
    struct Node* temp = A -> right; // Sol çocuğun sağ alt ağacını geçici olarak saklıyoruz
    // Dönüş işlemi yapıyoruz
    A->right = B;
    B->left = temp;
    // Yükseklikleri güncelliyoruz
    B->height = max(getHeight(B->left), getHeight(B->right)) + 1;
    A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
    // Yeni kök düğümünü döndürüyoruz
    return A;
}
// Sol dönüş (Left Rotation) fonksiyonu
struct Node* rotateLeft(struct Node* A) {
    struct Node* B = A->right; // Sağ çocuk düğüm
    struct Node* temp = B->left; // Sağ çocuğun sol alt ağacını geçici olarak saklıyoruz
    // Dönüş işlemi yapıyoruz
    B->left = A;
    A->right = temp;
    // Yükseklikleri güncelliyoruz
    A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
    B->height = max(getHeight(B->left), getHeight(B->right)) + 1;
    // Yeni kök düğümünü döndürüyoruz
    return B;
}
//2. Çift Döndürme (Double Rotation)
//Sol-Sağ Durumu (Left-Right Case) - Çift Döndürme: Sola Sonra Sağa Döndürme
//Açıklama:
//Dengesizlik, sol alt düğümün sağ çocuğunda bulunuyorsa:
//1. İlk olarak sol alt düğüme sola döndürme uygulanır.
//2. Ardından kök düğüme sağa döndürme uygulanır.
//Bu işlem sonucunda dengeli bir ağaç oluşur.
struct Node* leftRightRotate(struct Node* node) {
    // 1. Sol alt düğüme sola döndürme
    node->left = rotateLeft(node->left);

    // 2. Ana düğüme sağa döndürme
    return rotateRight(node);
}
/*
//Sağ-Sol Durumu (Right-Left Case) - Çift Döndürme: Sağa Sonra Sola Döndürme
//Açıklama:
//Dengesizlik, sağ alt düğümün sol çocuğunda bulunuyorsa:
//1. İlk olarak sağ alt düğüme sağa döndürme uygulanır.
//2. Ardından kök düğüme sola döndürme uygulanır.
*/

struct Node* rightLeftRotate(struct Node* node) {
    // 1. Sağ alt düğüme sağa döndürme
    node->right = rotateRight(node->right);

    // 2. Ana düğüme sola döndürme
    return rotateLeft(node);
}
// AVL ağacına düğüm ekleyen fonksiyon
struct Node* insert(struct Node* node, int data) {
    // 1. Adım: Düğümü ağaca ekliyoruz
    if (node == NULL) {
        return createNode(data); // Eğer ağaç boşsa yeni bir düğüm oluşturuyoruz
    }

    // Yeni veri ekleme kısmı (sol veya sağ alt ağaç)
    if (data < node->data) {
        node->left = insert(node->left, data); // Veri küçükse, sol alt ağaca ekle
    } else if (data > node->data) {
        node->right = insert(node->right, data); // Veri büyükse, sağ alt ağaca ekle
    } else {
        return node; // Aynı veri tekrar edilmesin diye eklemeyi engelliyoruz
    }
    // 2. Adım: Düğümün yüksekliğini güncelliyoruz
    node->height = 1 + max(getHeight(node->left), getHeight(node->right)); // Sol ve sağ alt ağaçların yüksekliklerini alıp güncelliyoruz
    // 3. Adım: Düğümün denge faktörünü hesaplıyoruz
    int balance = getBalanceFactor(node); // Düğümün denge faktörünü hesaplıyoruz
    // 4. Adım: Dengeyi sağlıyoruz, eğer gerekli ise dönüş yapıyoruz
    // Sol-Sol Durumu (Left-Left Case)
    if (balance > 1 && data < node->left->data) {
        return rotateRight(node); // Sağ dönüş yapıyoruz
        }
    // Sağ-Sağ Durumu (Right-Right Case)
    if (balance < -1 && data > node->right->data) {
        return rotateLeft(node); // Sol dönüş yapıyoruz
        }
    // Sol-Sağ Durumu (Left-Right Case)
    if (balance > 1 && data > node->left->data) {
        return leftRightRotate(node);
        }
    // Sağ-Sol Durumu (Right-Left Case)
    if (balance < -1 && data < node->right->data) {
        return rightLeftRotate(node);
    }
    return node;
    }
/*

/*AVL Ağacında Silme İşlemi (Deletion)
Silme işlemi AVL ağacından bir düğümü kaldırmak için yapılır. Silme işleminden sonra AVL ağacının dengesini korumak için gerekli döndürme işlemleri uygulanır.
Silme İşlemi Açıklaması:
Silme işlemi üç adımdan oluşur:
1. Standart Binary Search Tree (BST) silme işlemi:
Silinecek düğüm bulunur.
Üç durum göz önünde bulundurulur:
1. Yaprak düğüm (çocuk yok) silinir.
2. Tek çocuklu düğüm silinir ve çocuğu üst düğüme bağlanır.
3. İki çocuklu düğüm: Sağ alt ağacın minimum değeri (in-order successor) bulunur ve yerine yerleştirilir.

2. Yükseklik güncellemesi:
Silme işleminden sonra düğümlerin yükseklikleri güncellenir.

3. AVL ağacının dengesi kontrol edilir:
Silme işleminden sonra AVL dengesizliği kontrol edilir ve uygun döndürme işlemleri gerçekleştirilir:
Sol-Sol (LL) → Sağa döndürme
Sağ-Sağ (RR) → Sola döndürme
Sol-Sağ (LR) → Sola sonra sağa döndürme
Sağ-Sol (RL) → Sağa sonra sola döndürme
*/
// En küçük değeri bulan fonksiyon
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
// AVL ağacında düğüm silen fonksiyon
struct Node* deleteNode(struct Node* root, int data) {
    // 1. Standart BST silme işlemi
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data); // Sol alt ağaçta ara
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data); // Sağ alt ağaçta ara
    } else {
        // Silinecek düğüm bulundu
        if ((root->left == NULL) || (root->right == NULL)) {
            // Tek çocuklu veya yaprak düğüm
            struct Node* temp = root->left ? root->left : root->right; // Burada tek çocuklu düğümü alıyoruz eğer yoksa NULL
            /* Eğer düğüm yaprak düğümse veya tek çocuklu ise */
            if (temp == NULL) {
                // Yaprak düğüm
                temp = root;
                root = NULL;
            } else {
                // Tek çocuklu düğüm
                *root = *temp; //burada düğümü kopyalıyoruz ve silme işlemi yapıyoruz
            }
            free(temp);
        } else {
            // İki çocuklu düğüm
            struct Node* temp = minValueNode(root->right); // Sağ alt ağacın minimum değeri
            root->data = temp->data; // Değeri kopyala
            root->right = deleteNode(root->right, temp->data); // Minimum değeri sil
        }
    }
    if (root == NULL) return root;
    // 2. Yükseklik güncellemesi
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    // 3. Denge faktörünü kontrol et ve döndürme uygula
    int balance = getBalanceFactor(root);
    // Sol-Sol durumu
    if (balance > 1 && getBalanceFactor(root->left) >= 0) {
        return rotateRight(root);
    }
    // Sol-Sağ durumu
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
         //return leftRightRotate(root);
    }
    // Sağ-Sağ durumu
    if (balance < -1 && getBalanceFactor(root->right) <= 0) {
        return rotateLeft(root);
    }
    // Sağ-Sol durumu
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
         // return rightLeftRotate(root);
    }
    return root; // Dengeli düğümü döndür
}
// In-order Traversal: Sol -> Kök -> Sağ
void printInOrder(struct Node* root) {
    if (root != NULL) {
        printInOrder(root->left);           // Sol alt ağacı gez
        printf("%d ", root->data);          // Kök düğümünü yazdır
        printInOrder(root->right);          // Sağ alt ağacı gez
    }
}
// Pre-order Traversal: Kök -> Sol -> Sağ
void printPreOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);          // Kök düğümünü yazdır
        printPreOrder(root->left);          // Sol alt ağacı gez
        printPreOrder(root->right);         // Sağ alt ağacı gez
    }
}
// Post-order Traversal: Sol -> Sağ -> Kök
void printPostOrder(struct Node* root) {
    if (root != NULL) {
        printPostOrder(root->left);         // Sol alt ağacı gez
        printPostOrder(root->right);        // Sağ alt ağacı gez
        printf("%d ", root->data);          // Kök düğümünü yazdır
    }
}
int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Ekleme işleminden sonra değerler:\n");
    printf("In-order Traversal (Düğüm sıralı gezinme): ");
    printInOrder(root); // In-order yöntemine göre değerleri yazdırıyoruz
    printf("\n");

    printf("Pre-order Traversal (Düğüm öncelikli gezinme): ");
    printPreOrder(root); // Pre-order yöntemine göre değerleri yazdırıyoruz
    printf("\n");

    printf("Post-order Traversal (Düğüm sonralıklı gezinme): ");
    printPostOrder(root); // Post-order yöntemine göre değerleri yazdırıyoruz
    printf("\n");

    printf("\n20, 30 ve 40 değerleri siliniyor...\n");
    root = deleteNode(root, 20);//Balance degismez
    root = deleteNode(root, 30);//Balance degismez
    root = deleteNode(root, 40);
    root = insert(root,55);
    printf("\nSilme işleminden sonra değerler:\n");
    printf("In-order Traversal (Düğüm sıralı gezinme): ");
    printInOrder(root); // In-order yöntemi
    printf("\n");

    printf("Pre-order Traversal (Düğüm öncelikli gezinme): ");
    printPreOrder(root); // Pre-order yöntemi
    printf("\n");

    printf("Post-order Traversal (Düğüm sonralıklı gezinme): ");
    printPostOrder(root); // Post-order yöntemi
    printf("\n");
}
