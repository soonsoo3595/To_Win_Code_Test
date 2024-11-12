#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int t, n;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode() : isEnd(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    bool Insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->isEnd) {
                // 이미 다른 번호가 현재 번호의 접두사임
                return false;
            }
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }

        current->isEnd = true;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        Trie trie;
        vector<string> phone(n);

        for (int i = 0; i < n; i++) {
            cin >> phone[i];
        }

        // 사전순으로 정렬하여 접두사 문제를 순차적으로 검사할 수 있게 함
        sort(phone.begin(), phone.end());

        bool consistent = true;
        for (const string& number : phone) {
            if (!trie.Insert(number)) {
                consistent = false;
                break;
            }
        }

        if (consistent) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}