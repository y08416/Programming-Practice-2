#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// 新しいノードを作成する関数
struct node *new_node(int key) {
    // メモリを動的に割り当てる
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        // メモリ割り当てエラーが発生した場合
        fprintf(stderr, "メモリを確保できませんでした。\n");
        exit(1);
    }
    // ノードのキーとポインタを初期化
    p->key = key;
    p->parent = NULL;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// NULLノードを作成する関数
struct node *null_node() {
    // メモリを動的に割り当てる
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        // メモリ割り当てエラーが発生した場合
        fprintf(stderr, "メモリを確保できませんでした。\n");
        exit(1);
    }
    // ノードのキーを0に設定し、ポインタをNULLに初期化
    p->key = 0;
    p->parent = NULL;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int main() {
    struct node *root, *n[10], *nulls[15];

    // 教科書の図6.1に示される2分探索木のノードを作成
    n[0] = new_node(18);
    n[1] = new_node(9);
    n[2] = new_node(22);
    n[3] = new_node(4);
    n[4] = new_node(12);
    n[5] = new_node(21);
    n[6] = new_node(31);
    n[7] = new_node(7);
    n[8] = new_node(15);
    n[9] = new_node(25);

    // NULLノードを作成
    for (int i = 0; i < 15; i++) {
        nulls[i] = null_node();
    }

    // ノードを手動で繋ぎ合わせる
    n[0]->left = n[1];  // 18 -> 9
    n[0]->right = n[2]; // 18 -> 22
    n[1]->left = n[3];  // 9 -> 4
    n[1]->right = n[4]; // 9 -> 12
    n[2]->left = n[5];  // 22 -> 21
    n[2]->right = n[6]; // 22 -> 31
    n[3]->right = n[7]; // 4 -> 7
    n[4]->right = n[8]; // 12 -> 15
    n[6]->left = n[9];  // 31 -> 25

    // 親ノードのポインタを設定
    n[1]->parent = n[0];
    n[2]->parent = n[0];
    n[3]->parent = n[1];
    n[4]->parent = n[1];
    n[5]->parent = n[2];
    n[6]->parent = n[2];
    n[7]->parent = n[3];
    n[8]->parent = n[4];
    n[9]->parent = n[6];

    // NULLノードを適切な場所に接続
    n[0]->left = n[1];  // 18 -> 9
    n[0]->right = n[2]; // 18 -> 22
    n[1]->left = n[3];  // 9 -> 4
    n[1]->right = n[4]; // 9 -> 12
    n[2]->left = n[5];  // 22 -> 21
    n[2]->right = n[6]; // 22 -> 31
    n[3]->right = n[7]; // 4 -> 7
    n[3]->left = nulls[0];
    n[4]->left = nulls[1];
    n[4]->right = n[8]; // 12 -> 15
    n[5]->left = nulls[2];
    n[5]->right = nulls[3];
    n[6]->left = n[9];  // 31 -> 25
    n[6]->right = nulls[4];
    n[7]->left = nulls[5];
    n[7]->right = nulls[6];
    n[8]->left = nulls[7];
    n[8]->right = nulls[8];
    n[9]->left = nulls[9];
    n[9]->right = nulls[10];

    // ルートノードを設定
    root = n[0];

    // 木の構造を表示
    print_tree(root, 0);

    // メモリ解放
    for (int i = 0; i < 10; i++) {
        free(n[i]);
    }

    for (int i = 0; i < 15; i++) {
        free(nulls[i]);
    }

    return 0;
}