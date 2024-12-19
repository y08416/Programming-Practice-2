#include<stdio.h>
#include<stdlib.h>

// 各要素の構造体を定義
struct node {
    int key;
    struct node *parent, *left, *right;
};

// 新しい要素を追加する関数
struct node *new_node(int key)
{
    struct node *p = (struct node*)malloc(sizeof(struct node));
    if (p != NULL) {
        p->key = key;
        p->parent = p->left = p->right = NULL;
    }
    return p;
}

// 2分探索木に要素を挿入する関数
int insert(int key, struct node **root) {
    struct node *current = *root;
    struct node *parent = NULL;

    // 空の木の場合
    if (*root == NULL) {
        *root = new_node(key);
        return 1;
    }

    // 木を探索して適切な挿入位置を見つける
    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            return 0; // 同じ値の要素がすでにある場合
        }
    }

    // 新しいノードを作成し、親ノードと接続する
    struct node *new = new_node(key);
    new->parent = parent;
    if (key < parent->key) {
        parent->left = new;
    } else {
        parent->right = new;
    }

    return 1;
}

// 木の表示（再帰的に行う）
void ptree(struct node *p, int h) {
    if (p != NULL) {
        ptree(p->right, h + 1);
        for (int i = 0; i < h; i++) {
            printf("      "); // インデントのスペースを表示
        }
        printf("%d\n", p->key); // ノードのキーを表示
        ptree(p->left, h + 1);
    } else {
        for (int i = 0; i < h; i++) {
            printf("      ");
        }
        printf("0\n"); // NULL ノードの場合は "0" を表示
    }
}

// 木の表示を外部から呼び出すための関数
void print_tree(struct node *p) {
    ptree(p, 0); // 開始時の深さは 0 から
}

// メモリの解放（再帰的に行う）
void free_tree(struct node *node){
    if(node != NULL){
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

int main(void) {
    int key;
    struct node *root = NULL; // ルートノードの初期化

    for (;;) {
        printf("挿入するキーを入力して下さい：");
        scanf("%d", &key);

        if (key > 0) {
            if (insert(key, &root) == 1) {
                print_tree(root); // 挿入後の木の表示
            } else {
                printf("その値はすでに存在します。\n");
                print_tree(root); // 既存の値のエラー表示後の木の表示
            }
        } else {
            printf("正でない数値が入力されたので終了します。\n");
            break;
        }
    }

    // メモリの解放
    free_tree(root);

    return 0;
}