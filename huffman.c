#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char data;
    int freq;
    struct Node *left;
    struct Node *right;
};
struct MinHeap
{
    int size;
    int capacity;
    struct Node **array;
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
struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap *minHeap;

    minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));

    minHeap->size = 0;
    minHeap->capacity = capacity;

    minHeap->array = (struct Node**)malloc(
                        capacity * sizeof(struct Node*)
                     );

    return minHeap;
}
void swapNode(struct Node **a, struct Node **b)
{
    struct Node *temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->freq <
        minHeap->array[smallest]->freq)
    {
        smallest = left;
    }

    if (right < minHeap->size &&
        minHeap->array[right]->freq <
        minHeap->array[smallest]->freq)
    {
        smallest = right;
    }

    if (smallest != idx)
    {
        swapNode(&minHeap->array[smallest],
                 &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}
void insertMinHeap(struct MinHeap *minHeap, struct Node *node)
{
    int i;

    minHeap->size++;
    i = minHeap->size - 1;

    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = node;
}
struct Node* extractMin(struct MinHeap *minHeap)
{
    struct Node *temp;

    temp = minHeap->array[0];

    minHeap->array[0] =
        minHeap->array[minHeap->size - 1];

    minHeap->size--;

    minHeapify(minHeap, 0);

    return temp;
}
int isSizeOne(struct MinHeap *minHeap)
{
    return (minHeap->size == 1);
}
struct Node* buildHuffmanTree(struct MinHeap *minHeap)
{
    struct Node *left;
    struct Node *right;
    struct Node *top;

    while (!isSizeOne(minHeap))
    {
    left = extractMin(minHeap);
    right = extractMin(minHeap);

    top = createNode('$',
                     left->freq + right->freq);

    top->left = left;
    top->right = right;

    insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}
int isLeaf(struct Node *root)
{
    return !(root->left) && !(root->right);
}
void printCodes(struct Node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root))
    {
        printf("%c : ", root->data);

        for (int i = 0; i < top; i++)
        {
            printf("%d", arr[i]);
        }

        printf("\n");
    }
}
void countFrequency()
{
    FILE *fp;
    int freq[256] = {0};
    int ch;

    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        freq[ch]++;
    }

    fclose(fp);

    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            printf("%c : %d\n", i, freq[i]);
        }
    }
}
int main()
{
    countFrequency();
    return 0;
}