#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N;
vector<string> words;

class TrieNode
{
public:
	unordered_map<char, TrieNode*> children;
	int firstIndex = -1;	// 이 노드를 방문하는 첫 번째 단어의 인덱스
};

class Trie
{
private:
	TrieNode* root;

public:
	Trie()
	{
		root = new TrieNode();
	}

	void Insert(string& word, int index)
	{
		TrieNode* curNode = root;

		for (char ch : word)
		{
			if (curNode->children.find(ch) == curNode->children.end())
			{
				curNode->children[ch] = new TrieNode();
			}

			curNode = curNode->children[ch];
			if (curNode->firstIndex == -1)
			{
				curNode->firstIndex = index;
			}
		}
	}

	pair<int, int> GetPrefixLength(string& word, int index)
	{
		TrieNode* curNode = root;
		int length = 0;
		int ret_index = -1;

		for (char ch : word)
		{
			curNode = curNode->children[ch];

			if (curNode->firstIndex != index)
			{
				length++;
				ret_index = curNode->firstIndex;
			}
		}

		return { length, ret_index };
	}
};

void Input()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		words.push_back(s);
	}
}

void Solve()
{
	Trie trie;
	int max_len = 0;
	vector<pair<int, int>> answer;
	answer.push_back({ 0, 1 });

	for (int i = 0; i < N; i++)
	{
		trie.Insert(words[i], i);
	}

	for (int i = 0; i < N; i++)
	{
		int length, index;
		tie(length, index) = trie.GetPrefixLength(words[i], i);

		if (index != -1)
		{
			if (length > max_len)
			{
				max_len = length;
				answer.clear();
				answer.push_back({ index, i });
			}
			else if (length == max_len)
			{
				answer.push_back({ index, i });
			}
		}
	}

	sort(answer.begin(), answer.end());
	cout << words[answer[0].first] << '\n' << words[answer[0].second];
}

int main()
{
	Input();

	Solve();
}
