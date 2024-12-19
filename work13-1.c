#include <stdio.h>
#include <stdlib.h>

// ノードの構造体定義
struct node {
    int key;                  // ノードのキー値
    struct node *parent;      // 親ノードへのポインタ
    struct node *left;        // 左の子ノードへのポインタ
    struct node *right;       // 右の子ノードへのポインタ
};

// 新しいノードを作成する関数
struct node *new_node(int key) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        // メモリ割り当てエラー処理
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    p->key = key;
    p->parent = NULL;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// 2分探索木に要素を挿入する関数
int insert(int key, struct node *root) {
    struct node *current = root;
    struct node *parent = NULL;

    // 挿入位置を探すために木を探索
    while (current != NULL) {
        parent = current;
        if (key == current->key) {
            // 同じ値の要素が既に存在する場合
            return 0;
        } else if (key < current->key) {
            // 左の子ノードへ進む
            current = current->left;
        } else {
            // 右の子ノードへ進む
            current = current->right;
        }
    }

    // 新しいノードを作成し、適切な位置に挿入
    struct node *newNode = new_node(key);
    newNode->parent = parent;

    if (key < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return 1;  // 挿入成功
}

// 木の構造を表示する関数
void print_tree(struct node *node, int depth) {
    if (node == NULL) {
        // ノードがNULLの場合は0を表示
        for (int i = 0; i < depth; i++) {
            printf("    ");
        }
        printf("   0\n");
    } else {
        // 右の子ノードを表示
        print_tree(node->right, depth + 1);
        // 現在のノードを表示
        for (int i = 0; i < depth; i++) {
            printf("    ");
        }
        printf("%4d\n", node->key);
        // 左の子ノードを表示
        print_tree(node->left, depth + 1);
    }
}

int main() {
    struct node *root = NULL;
    int key;

    printf("正の整数を入力してください (終了するには正でない整数を入力):\n");

    while (1) {
        printf("キーを入力: ");
        scanf("%d", &key);

        if (key <= 0) {
            // 正でない整数が入力されたら終了
            break;
        }

        if (root == NULL) {
            // 最初のノードを作成
            root = new_node(key);
        } else {
            // 既存の木に新しいキーを挿入
            if (insert(key, root)) {
                printf("キー %d を挿入しました。\n", key);
            } else {
                printf("キー %d は既に存在します。\n", key);
            }
        }

        // 木の構造を表示
        print_tree(root, 0);
    }

    // メモリ解放（適切なメモリ管理を行うためのコードを追加することをお勧めします）

    return 0;
}