# File Compression Tool using Huffman Coding

## Date: 09-06-2026

### Project Goal

Build a File Compression Tool in C using Huffman Coding.

---

## Environment Setup

### Tools Installed

* VS Code
* GCC Compiler (MinGW-w64 GCC 16.1.0)

### Commands Used

Compile Program:

gcc main.c -o compress

Run Program:

.\compress.exe

---

## Module 1: File Reading

### Objective

Read contents from a text file.

### Concepts Used

* fopen()
* fgetc()
* fclose()

### Outcome

Successfully read and displayed contents of input.txt.

---

## Module 2: Character Frequency Counter

### Objective

Count occurrences of each character in the file.

### Concepts Used

* Arrays
* ASCII values
* Character processing

### Data Structure Used

int freq[256];

### Outcome

Generated frequency counts for all characters in the file.

Example:

o : 5
e : 4
l : 4

---

## Module 3: Huffman Node Structure

### Objective

Create the basic node structure required for Huffman Tree construction.

### Concepts Used

* Structures
* Pointers
* Dynamic Memory Allocation
* malloc()

### Structure Created

struct Node
{
char data;
int freq;
struct Node *left;
struct Node *right;
};

### Outcome

Successfully created and tested Huffman nodes.

---

## Progress Status

Completed:

* GCC Installation
* VS Code Setup
* File Reading
* Frequency Counter
* Huffman Node Creation

Pending:

* Min Heap
* Huffman Tree Construction
* Huffman Code Generation
* Compression
* Decompression
* Testing
* Documentation
* GitHub Upload

---

## Next Session

Continue with:

1. Min Heap
2. Huffman Tree Construction
