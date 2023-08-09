#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Huffman tree node
struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;
    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparison function for min heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Build Huffman tree and return the root
Node* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (const auto& pair : freqMap) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top();
        minHeap.pop();
        Node* right = minHeap.top();
        minHeap.pop();
        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }

    return minHeap.top();
}

// Print Huffman codes
void printHuffmanCodes(Node* root, string code) {
    if (root == nullptr)
        return;

    if (root->data != '$') {
        cout << root->data << ": " << code << endl;
    }

    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}

int main() {
    string input = "Aadarsh Kalgotuwar";
    unordered_map<char, int> freqMap;

    for (char c : input) {
        freqMap[c]++;
    }

    Node* root = buildHuffmanTree(freqMap);
    printHuffmanCodes(root, "");

    return 0;
}
