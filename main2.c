#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// 新しいノードを作成する関数
struct node *new_node(int key) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
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

    while (current != NULL) {
        parent = current;
        if (key == current->key) {
            return 0;  // 同じ値の要素が既に存在
        } else if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    struct node *newNode = new_node(key);
    newNode->parent = parent;

    if (key < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return 1;  // 挿入成功
}

// カプセル化された print_tree 関数
void encapsulated_print_tree(struct node *node, int depth) {
    if (node == NULL) {
        for (int i = 0; i < depth; i++) {
            printf("    ");
        }
        printf("   0\n");
    } else {
        encapsulated_print_tree(node->right, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("    ");
        }
        printf("%4d\n", node->key);
        encapsulated_print_tree(node->left, depth + 1);
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
            break;  // 正でない整数が入力されたら終了
        }

        if (root == NULL) {
            root = new_node(key);  // 最初のノードを作成
        } else {
            if (insert(key, root)) {
                printf("キー %d を挿入しました。\n", key);
            } else {
                printf("キー %d は既に存在します。\n", key);
            }
        }

        encapsulated_print_tree(root, 0);  // 修正：カプセル化された print_tree を使用
    }

    // メモリ解放（適切なメモリ管理を行うためのコードを追加することをお勧めします）

    return 0;
}