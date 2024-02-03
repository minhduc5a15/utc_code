#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

Node *getNode(char ch, int freq, Node *left, Node *right) {
    Node *node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

struct compare {
    bool operator()(Node *l, Node *r) {
        return l->freq > r->freq;
    }
};

void encode(Node *root, const string& str, unordered_map<char, string> &huffmanCode) {
    if (root == nullptr) return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

int solve(const string& s) {
    unordered_map<char, int> freq;
    for (char ch: s) {
        freq[ch]++;
    }

    priority_queue<Node *, vector<Node *>, compare> pq;
    for (const pair<const char, int> pair: freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (pq.size() != 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }
    Node *root = pq.top();
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);
    int result = 0;
    for (char ch: s) {
        result += huffmanCode[ch].size();
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}
