
#define HUFFMANCODING_HPP
#include <string>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

const int bits = 128;

// 1) Defining the node of huffman Tree 

struct Node {
	char data;
	int freq;
	string code;
	Node* left;
	Node* right;

	// when intialize the new node, both left and right child 
	// of the new node initialized with null
	Node(){
		left = NULL;
		right =  NULL;
	}
};


class huffman {
	private :
		vector<Node*> arr;

		fstream inFile,outFile;

		string inFileName,outFileName;

		Node* root;

		class Compare {
			public :
			bool operator()(Node* l,Node* r){
				return l->freq > r-> freq;
			}
		};


		priority_queue<Node*,vector<Node*>,Compare> minHeap;


		void createArr();

		void traverseArr(Node*,string);

		int binToDec(string);

		string decToBin(int );

		void buildTree(char,string &);

		void createMinHeap();
        
        void createTree();
        
        void createCodes();
        
        void saveEncodedFile();
        
        void saveDecodedFile();
        
        void getTree();

    public :

    	huffman(string inFileName,string outFileName){
    		this->inFileName = inFileName;
    		this->outFileName = outFileName;
    		createArr();
    	}
    	void compress();
    	void decompress();
};
