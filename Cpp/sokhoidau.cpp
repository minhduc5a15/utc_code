#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode *> children;
    bool end_of_word;

    TrieNode() {
        end_of_word = true;
    }
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string &word) const {
        TrieNode *node = root;
        for (char c: word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->end_of_word = true;
    }

    bool search(const string &word) const {
        TrieNode *node = root;
        for (char c: word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->end_of_word;
    }
};

int solve(const vector<string> &arr) {
    Trie trie;
    for (const string &num: arr) {
        trie.insert(num);
    }
    int k = 1;
    while (trie.search(to_string(k))) {
        k++;
    }
    return k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve(arr) << endl;
    return 0;
}

