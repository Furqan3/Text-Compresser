#include <string>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;
//Node 
struct Node {
	char data;
	unsigned Frequency;
	string code;
	Node* left, * right;

	Node() {
		left = right = NULL;
	}
};
//clas Huffman
class huffman {
private:
	vector <Node*> arr;
	fstream Input_File, Out_File;
	string in_File_Name, Out_File_Name;
	Node* root;
	class Compare_Frequency {
	public:
		bool operator() (Node* l, Node* r)
		{
			return l->Frequency > r->Frequency;
		}
	};
	priority_queue <Node*, vector<Node*>, Compare_Frequency> Queue;
	void createArr();
	void traverse(Node*, string);
	int binToDec(string);
	string decToBin(int);
	void buildTree(char, string&);
	void createQueue();
	void createTree();
	void createCodes();
	void saveEncodedFile();
	void saveDecodedFile();
	void getTree();
public:
	//Constructor
	huffman(string in_File_Name, string Out_File_Name)
	{
		this->in_File_Name = in_File_Name;
		this->Out_File_Name = Out_File_Name;
		createArr();
	}
	void compress();

	void decompress();
};
//creats array 
void huffman::createArr() {
	for (int i = 0; i < 128; i++) {
		arr.push_back(new Node());
		arr[i]->data = i;
		arr[i]->Frequency = 0;
	}
}
//triverse tree
void huffman::traverse(Node* r, string str) {
	if (r->left == NULL && r->right == NULL) {
		r->code = str;
		return;
	}

	traverse(r->left, str + '0');
	traverse(r->right, str + '1');
}
//binary to Decimal
int huffman::binToDec(string inStr) {
	int res = 0;
	for (auto c : inStr) {
		res = res * 2 + c - '0';
	}
	return res;
}
//Decimal to binary
string huffman::decToBin(int inNum) {
	string temp = "", res = "";
	while (inNum > 0) {
		temp += (inNum % 2 + '0');
		inNum /= 2;
	}
	res.append(8 - temp.length(), '0');
	for (int i = temp.length() - 1; i >= 0; i--) {
		res += temp[i];
	}
	return res;
}
//building tree
void huffman::buildTree(char a_code, string& path) {
	Node* curr = root;
	for (int i = 0; i < path.length(); i++) {
		if (path[i] == '0') {
			if (curr->left == NULL) {
				curr->left = new Node();
			}
			curr = curr->left;
		}
		else if (path[i] == '1') {
			if (curr->right == NULL) {
				curr->right = new Node();
			}
			curr = curr->right;
		}
	}
	curr->data = a_code;
}
//creat Queue
void huffman::createQueue() {
	char id;
	Input_File.open(in_File_Name, ios::in);
	Input_File.get(id);

	while (!Input_File.eof()) {
		arr[id]->Frequency++;
		Input_File.get(id);
	}
	Input_File.close();
	//Pushing the Nodes which appear in the file into the priority queue (Min Heap)
	for (int i = 0; i < 128; i++) {
		if (arr[i]->Frequency > 0) {
			Queue.push(arr[i]);
		}
	}
}
//chreat tree
void huffman::createTree() {
	//Creating Huffman Tree with the Min Heap created earlier
	Node* left, * right;
	priority_queue <Node*, vector<Node*>, Compare_Frequency> tempPQ(Queue);
	while (tempPQ.size() != 1)
	{
		left = tempPQ.top();
		tempPQ.pop();

		right = tempPQ.top();
		tempPQ.pop();

		root = new Node();
		root->Frequency = left->Frequency + right->Frequency;

		root->left = left;
		root->right = right;
		tempPQ.push(root);
	}
}
//creat unique for each charector
void huffman::createCodes() {
	//Traversing the Huffman Tree and assigning specific codes to each character
	traverse(root, "");
}
//Save the Encoded File Data
void huffman::saveEncodedFile() {

	Input_File.open(in_File_Name, ios::in);
	Out_File.open(Out_File_Name, ios::out | ios::binary);
	string in = "";
	string s = "";
	char id;

	in += (char)Queue.size();
	priority_queue <Node*, vector<Node*>, Compare_Frequency> tempPQ(Queue);
	while (!tempPQ.empty()) {
		Node* curr = tempPQ.top();
		in += curr->data;
		//Saving 16 decimal values representing code of curr->data
		s.assign(127 - curr->code.length(), '0');
		s += '1';
		s += curr->code;
		//Saving decimal values of every 8-bit binary code 
		in += (char)binToDec(s.substr(0, 8));
		for (int i = 0; i < 15; i++) {
			s = s.substr(8);
			in += (char)binToDec(s.substr(0, 8));
		}
		tempPQ.pop();
	}
	s.clear();

	//Saving codes of every character appearing in the input file
	Input_File.get(id);
	while (!Input_File.eof()) {
		s += arr[id]->code;
		//Saving decimal values of every 8-bit binary code
		while (s.length() > 8) {
			in += (char)binToDec(s.substr(0, 8));
			s = s.substr(8);
		}
		Input_File.get(id);
	}

	//Finally if bits remaining are less than 8, append 0's
	int count = 8 - s.length();
	if (s.length() < 8) {
		s.append(count, '0');
	}
	in += (char)binToDec(s);
	//append count of appended 0's
	in += (char)count;

	//write the in string to the output file
	Out_File.write(in.c_str(), in.size());
	Input_File.close();
	Out_File.close();
}
//Save Decopmressed file
void huffman::saveDecodedFile() {
	Input_File.open(in_File_Name, ios::in | ios::binary);
	Out_File.open(Out_File_Name, ios::out);
	unsigned char size;
	Input_File.read(reinterpret_cast<char*>(&size), 1);
	//Reading count at the end of the file which is number of bits appended to make final value 8-bit
	Input_File.seekg(-1, ios::end);
	char count0;
	Input_File.read(&count0, 1);
	//Ignoring the meta data (huffman tree) (1 + 17 * size) and reading remaining file
	Input_File.seekg(1 + 17 * size, ios::beg);

	vector<unsigned char> text;
	unsigned char textseg;
	Input_File.read(reinterpret_cast<char*>(&textseg), 1);
	while (!Input_File.eof()) {
		text.push_back(textseg);
		Input_File.read(reinterpret_cast<char*>(&textseg), 1);
	}

	Node* curr = root;
	string path;
	for (int i = 0; i < text.size() - 1; i++) {
		//Converting decimal number to its equivalent 8-bit binary code
		path = decToBin(text[i]);
		if (i == text.size() - 2) {
			path = path.substr(0, 8 - count0);
		}
		//Traversing huffman tree and appending resultant data to the file
		for (int j = 0; j < path.size(); j++) {
			if (path[j] == '0') {
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}

			if (curr->left == NULL && curr->right == NULL) {
				Out_File.put(curr->data);
				curr = root;
			}
		}
	}
	Input_File.close();
	Out_File.close();
}
//creat tree from compressed file
void huffman::getTree() {
	Input_File.open(in_File_Name, ios::in | ios::binary);
	//Reading size of Queue
	unsigned char size;
	//reinterpret_cast is used to convert a pointer of some data type into a pointer.
	Input_File.read(reinterpret_cast<char*>(&size), 1);
	root = new Node();
	//next size * (1 + 16) characters contain (char)data and (string)code[in decimal]
	for (int i = 0; i < size; i++) {
		char aCode;
		unsigned char hCodeC[16];
		Input_File.read(&aCode, 1);
		Input_File.read(reinterpret_cast<char*>(hCodeC), 16);
		//converting decimal characters into their binary equivalent to obtain code
		string hCodeStr = "";
		for (int i = 0; i < 16; i++) {
			hCodeStr += decToBin(hCodeC[i]);
		}
		//Removing padding by ignoring first (127 - curr->code.length()) '0's and next '1' character
		int j = 0;
		while (hCodeStr[j] == '0') {
			j++;
		}
		hCodeStr = hCodeStr.substr(j + 1);
		//Adding node with aCode data and hCodeStr string to the huffman tree
		buildTree(aCode, hCodeStr);
	}
	Input_File.close();
}

void huffman::compress() {
	createQueue();
	createTree();
	createCodes();
	saveEncodedFile();
}

void huffman::decompress() {
	getTree();
	saveDecodedFile();
}



std::ifstream::pos_type filesize( string filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}


string Filename(string path) 
{
	string name;

	while (path.back()!=92)
	{
		name.insert(name.begin(), path.back());
		path.pop_back();	
	}
	
	return name;
}



