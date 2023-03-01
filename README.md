# Huffman Text Compressor Program with GUI in C++
This program implements a text compression algorithm using Huffman encoding in C++. The program provides a Command Line Interface (CLI) based GUI.


## Prerequisites
- A C++ compiler that supports C++11 standard.
- CMake 

## Usage
After running the program, the user will be presented with the following options:

- Compress text
  -  To compress text, select the *Compress text* option and enter the path to the input text file. The compressed output will be written to a file named *output.huff*.
- Decompress text
  - To decompress text, select the *Decompress text* option and enter the path to the compressed text file (i.e.,*output.huff*). The decompressed output will be written to a file named *output.txt*.
- Exit

##  Implementation Details
The program uses the Huffman encoding algorithm to compress text. Huffman encoding is a variable-length prefix coding algorithm that assigns shorter codes to more frequently occurring characters in the input text.

The program first reads the input text and computes the frequency of each character. It then constructs a Huffman tree by repeatedly merging the two least frequent characters until a single tree is formed. The Huffman codes for each character are determined by traversing the tree from the root to the leaf corresponding to that character.

The compressed output consists of the Huffman tree (in a serialized form) followed by the encoded text. The Huffman tree is used to decompress the text.

## Acknowledgements
This program was developed as a project for the Data Structures and Algorithms course at ***NUST College of EME***.
## GUI
### Starup GUI
![image](https://user-images.githubusercontent.com/88136810/222056079-011a4b69-954f-4a57-b1c7-1bcb6c768d29.png)
### File Dailog 
![image](https://user-images.githubusercontent.com/88136810/222056202-e61ada96-0582-433e-ac97-269ea96c7538.png)
### After Opning text file
![image](https://user-images.githubusercontent.com/88136810/222056601-1bea622a-36e2-404f-87b6-0b600141c9cc.png)
### Original file
![image](https://user-images.githubusercontent.com/88136810/222056654-35729da2-a244-4c0a-b034-e3c3aa282ca4.png)
### Size of original File
![image](https://user-images.githubusercontent.com/88136810/222056723-b732ffff-ea2a-4930-8a27-5e6cc5ad1100.png)
#### Size of Compressed file
![image](https://user-images.githubusercontent.com/88136810/222057006-e7b2fcdd-5138-489b-aa44-0e4e8c492932.png)




