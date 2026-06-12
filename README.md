# File Compression Using Huffman Coding

## Overview

This project implements a File Compression and Decompression system using the Huffman Coding algorithm in C. Huffman Coding is a lossless compression technique that assigns shorter binary codes to frequently occurring characters and longer codes to less frequent characters.

## Features

* Compresses text files using Huffman Coding
* Decompresses compressed files back to the original content
* Generates Huffman Tree based on character frequencies
* Efficient file handling in C
* Lossless data compression

## Technologies Used

* C Programming
* Data Structures
* File Handling
* Huffman Coding Algorithm

## Project Structure

FileCompressionTool/
├── compress.c
├── decompress.c
├── huffman.c
├── huffman.h
├── input.txt
├── compressed.bin
├── decompressed.txt
└── README.md

## How It Works

1. Read input file.
2. Calculate character frequencies.
3. Build Huffman Tree.
4. Generate Huffman Codes.
5. Compress the file using generated codes.
6. Decompress to recover the original file.

## How to Run

Compile:

gcc *.c -o compression

Run:

./compression

## Sample Workflow

Input File:
Hello, this is Mounika!

Compressed File:
Binary encoded data

Decompressed File:
Hello, this is Mounika!

<img width="1432" height="997" alt="input" src="https://github.com/user-attachments/assets/40bfa9e1-500b-419a-ad42-d28a21036814" />

<img width="1440" height="997" alt="compression" src="https://github.com/user-attachments/assets/1f7a8473-0d2b-4ac8-8399-c5fb93ad78ae" />

<img width="1440" height="972" alt="decompression" src="https://github.com/user-attachments/assets/ea1f47f1-7637-4f0d-bf5b-3e0cb023eda4" />



## Learning Outcomes

* Binary Trees
* Priority Queues
* File Handling
* Compression Algorithms
* Memory Management in C

## Author

Mounika LR
B.Tech Artificial Intelligence & Machine Learning
