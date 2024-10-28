#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    
    Node(char ch, int freq) {
        left = right = nullptr;
        this->ch = ch;
        this->freq = freq;
    }

    Node(char ch, int freq, Node* left, Node* right) {
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

//what are we doing in this function?
//we are traversing the tree and storing the huffman code for each character
void encode(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void decode(Node* root, int &index, string str) {
    if (root == nullptr) {
        return;
    }

    if (!root->left && !root->right) {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

void buildHuffmanTree(string text) {
    unordered_map<char, int> freq;
    //find frequency of each character
    for (char ch : text) {
        freq[ch]++;
    }
    //how will the function work here?
    //it will sort the characters based on their frequency and store them in a priority queue
    //will the fisrt element be the minimum frequency element?
    //yes
    priority_queue<Node*, vector<Node*>, compare> pq;
    //create a leaf node for each character and add it to the priority queue
    //why are we using priority_queue?
    //because we want to extract the minimum frequency node each time
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }
    //what are we doing here?
    //we are creating a tree by extracting two minimum frequency nodes each time
    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Huffman Codes are:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
    }

    string str = "";
    for (char ch : text) {
        str += huffmanCode[ch];
    }

    cout << "\nEncoded string is:\n" << str << '\n';

    int index = -1;
    cout << "\nDecoded string is:\n";
    while (index < (int)str.size() - 1) {
        decode(root, index, str);
    }
}

int main() {
    string text = "Huffman coding is a data compression algorithm.";
    buildHuffmanTree(text);

    return 0;
}