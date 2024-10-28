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

//traversing the tree and sorting the huffman code for each character
void encode(Node* root, string str, unordered_map<char, string> &huffmanCode) {

    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void buildHuffmanTree(string text) {
    unordered_map<char, int> freq;
    //find frequency of each character
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;
    //add leaf node to priority queue so that we can extract two minimum frequency nodes each time
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }
    //create a tree by extracting two minum nodes from priiotiy queue and if only 1 node is present then it is the root node
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

}

int main() {
    string text = "tavaheed";
    buildHuffmanTree(text);

    return 0;
}