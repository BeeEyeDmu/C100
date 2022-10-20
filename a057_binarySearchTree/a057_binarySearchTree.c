#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* left, * right;
};

struct node* makeNode(int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->key = data;
    ptr->left = ptr->right = NULL;
    return ptr;
}

struct node* insert(struct node* node, int data)
{
    if (node == NULL)
        return makeNode(data);
    if (data < node->key)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

// 가장 작은 노드를 가져옴
struct node* minNode(struct node* node)
{
    struct node* cur = node;
    if (cur == NULL)
        return NULL;
    while (cur->left != NULL)
        cur = cur->left;
    return cur;
}

struct node* deleteNode(struct node* node, int data)
{
    if (node == NULL)
        return node;
    if (data < node->key)
        node->left = deleteNode(node->left, data);
    else if (data > node->key)
        node->right = deleteNode(node->right, data);
    else { // 이 노드가 삭제할 노드
        // case (1), (2)
        if (node->left == NULL) {
            struct node* tmp = node->right;
            free(node);
            return tmp;
        }
        else if (node->right == NULL) {
            struct node* tmp = node->left;
            free(node);
            return tmp;
        }
        // case (3)
        struct node* tmp = minNode(node->right);
        node->key = tmp->key;
        node->right = deleteNode(node->right, tmp->key);
    }
    return node;
}

void inorder(struct node* node)
{
    if (node != NULL) {
        inorder(node->left);
        printf("%d -> ", node->key);
        inorder(node->right);
    }
}

int main()
{
    struct node* root = NULL;
    int data[] = { 10,8,6,9,7,15,12,14 }; // 입력 데이터
    int del; // 삭제할 노드

    for (int i = 0; i < 8; i++)
        root = insert(root, data[i]);

    inorder(root);

    while (1) {
        printf("\nEnter node to delete(-1 to quit): ");
        scanf("%d", &del);
        if (del == -1)
            break;
        root = deleteNode(root, del);
        inorder(root);
    }
}