#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;

// A Tree node
struct Node
{
    char ch;
    int freq;
    int id; // Used as a tie-breaker for stable sorting in the priority queue
    Node *left, *right;

    Node(char ch, int freq, int id, Node *left = nullptr, Node *right = nullptr)
    {
        this->ch = ch;
        this->freq = freq;
        this->id = id;
        this->left = left;
        this->right = right;
    }
};

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(Node *l, Node *r)
    {
        // Primary sort: Lowest frequency first
        if (l->freq != r->freq)
        {
            return l->freq > r->freq;
        }
        // Secondary sort (Tie-breaker): Lowest ID first to ensure stability
        return l->id > r->id;
    }
};

// Recursive function to traverse the Huffman Tree and store the binary codes
void generateCodes(Node *root, string str, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    // If it's a leaf node, it contains a character
    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = str;
    }

    // Traverse left (append '0') and right (append '1')
    generateCodes(root->left, str + "0", huffmanCode);
    generateCodes(root->right, str + "1", huffmanCode);
}

int main()
{
    string text;

    // Match the requested input format
    cout << "Enter the string: ";
    cin >> text;

    if (text.empty())
    {
        return 0;
    }

    // 1. Calculate frequencies
    // We use std::map to process distinct characters in alphabetical order initially
    map<char, int> freqMap;
    for (char ch : text)
    {
        freqMap[ch]++;
    }

    // 2. Create a priority queue to store live nodes of the Huffman tree
    priority_queue<Node *, vector<Node *>, comp> pq;

    int idCounter = 0; // Global counter to assign unique IDs for stable sorting

    // Create a leaf node for each character and add it to the priority queue.
    for (auto pair : freqMap)
    {
        pq.push(new Node(pair.first, pair.second, idCounter++));
    }

    // Edge case: If the string has only one distinct character
    if (pq.size() == 1)
    {
        cout << "Encoded: ";
        for (size_t i = 0; i < text.length(); i++)
            cout << "0";
        cout << endl;
        return 0;
    }

    // 3. Iterate until there is only one node left in the queue
    while (pq.size() > 1)
    {
        // Remove the two nodes of highest priority (lowest frequency)
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        // Create a new internal node with these two nodes as children.
        // The frequency is the sum of the two nodes' frequencies.
        // '\0' represents an internal node without a specific character.
        int sumFreq = left->freq + right->freq;
        pq.push(new Node('\0', sumFreq, idCounter++, left, right));
    }

    // The remaining node is the root node
    Node *root = pq.top();

    // 4. Traverse the Huffman Tree and generate codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // 5. Print the encoded string matching the sample format
    cout << "Encoded:";
    for (char ch : text)
    {
        cout << huffmanCode[ch];
    }
    cout << endl;

    return 0;
}