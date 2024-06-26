#include <iostream>
using namespace std;

struct Node {
    int countWord;
    Node *child[26];
};

Node *createNode() {
    Node *node = new Node;
    node->countWord = 0;
    for (Node *&i: node->child) {
        i = nullptr;
    }
    return node;
}

void addWord(Node *root, const string &s) {
    Node *temp = root;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int ch = s[i] - 'a';
        if (temp->child[ch] == nullptr) {
            temp->child[ch] = createNode();
        }
        temp = temp->child[ch];
        temp->countWord++;
    }
}

int findWord(Node *root, const string &s) {
    Node *temp = root;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int ch = s[i] - 'a';
        if (temp->child[ch] == nullptr) {
            return 0;
        }
        temp = temp->child[ch];
    }
    return temp->countWord;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Node *root = createNode();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string cmd, word;
        cin >> cmd >> word;
        if (cmd == "add") {
            addWord(root, word);
        }
        else {
            cout << findWord(root, word) << '\n';
        }
    }
    delete root;
    return 0;
}

