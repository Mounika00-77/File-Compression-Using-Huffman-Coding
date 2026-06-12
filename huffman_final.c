#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int freq[256] = {0};
char *codes[256] = {NULL};
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
}
struct MinHeap* buildHeapFromFrequency()
{
    struct MinHeap *heap;

    heap = createMinHeap(256);

    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            insertMinHeap(
                heap,
                createNode((char)i, freq[i])
            );
        }
    }

    return heap;
}
void storeCodes(struct Node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        storeCodes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        storeCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root))
    {
        codes[(unsigned char)root->data] =
            (char*)malloc(top + 1);

        for (int i = 0; i < top; i++)
        {
            codes[(unsigned char)root->data][i] =
                arr[i] + '0';
        }

        codes[(unsigned char)root->data][top] = '\0';
    }
}
void compressFile()
{
    FILE *input;
    FILE *output;
    int ch;

    input = fopen("input.txt", "r");
    output = fopen("compressed.txt", "w");

    if (input == NULL || output == NULL)
    {
        printf("File Error!\n");
        return;
    }

    while ((ch = fgetc(input)) != EOF)
    {
        fprintf(output, "%s", codes[ch]);
    }

    fclose(input);
    fclose(output);

    printf("Compression Complete!\n");
}
void decompressFile(struct Node *root)
{
    FILE *input;
    FILE *output;

    struct Node *current;

    int ch;

    input = fopen("compressed.txt", "r");
    output = fopen("decompressed.txt", "w");

    if (input == NULL || output == NULL)
    {
        printf("File Error!\n");
        return;
    }

    current = root;

    while ((ch = fgetc(input)) != EOF)
    {
        if (ch == '0')
        {
            current = current->left;
        }
        else if (ch == '1')
        {
            current = current->right;
        }

        if (isLeaf(current))
        {
            fputc(current->data, output);
            current = root;
        }
    }

    fclose(input);
    fclose(output);

    printf("Decompression Complete!\n");
}
int main()
{
    struct MinHeap *heap;
    struct Node *root;
    int arr[100];

    countFrequency();

    heap = buildHeapFromFrequency();

    root = buildHuffmanTree(heap);

storeCodes(root, arr, 0);

printf("Stored Codes:\n\n");

for (int i = 0; i < 256; i++)
{
    if (codes[i] != NULL)
    {
        printf("%c : %s\n", i, codes[i]);
    }
}
compressFile();

decompressFile(root);

return 0;
}