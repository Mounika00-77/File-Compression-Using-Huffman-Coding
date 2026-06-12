#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    int freq;

    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char data, int freq)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->freq = freq;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int main()
{
    struct Node *root;

    root = createNode('A', 10);

    printf("Character: %c\n", root->data);
    printf("Frequency: %d\n", root->freq);

    return 0;
}