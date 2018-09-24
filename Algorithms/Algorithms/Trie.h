#pragma once

#include <memory>
#include <string>
#include <unordered_map>

using namespace std;

class TrieNode
{
public:
	unordered_map<char, TrieNode*> children;
};

void InsertWord(string word, TrieNode* currentNode)
{
	for (size_t i = 0; i < word.length(); ++i)
	{
		// if character isn't in children, insert it, otherwise add it to the end
		if (currentNode->children.empty() || currentNode->children.find(word[i]) == currentNode->children.end())
		{
			char currentLetter = word[i];
			currentNode->children.insert(make_pair(currentLetter, new TrieNode()));
			currentNode = currentNode->children[currentLetter];
		}
		else
		{
			currentNode = currentNode->children[word[i]];
		}
	}
}

bool ContainsWord(string word, TrieNode* currentNode)
{
	for (size_t i = 0; i < word.length(); ++i)
	{
		char currentCharacter = word[i];

		if (currentNode->children.empty() || currentNode->children.find(currentCharacter) ==
			currentNode->children.end())
		{
			return false;
		}
		else
		{
			currentNode = currentNode->children[currentCharacter];
		}
	}

	return true;
}

class TrieNode {
public:
	class HashMap {
	public:
		TrieNode* members[26] = {}; // initialize all to nullptr

		HashMap() {
			memset(members, 0, _countof(members));
		}

		TrieNode* operator[] (char c) {
			return *(members + charToIdx(c));
		}

	private:
		// helper function - char to idx
		inline int charToIdx(char c) {
			return c - 'a';
		}
	};

	HashMap children;

	// Index is a CHARACTER; Content is a ptr to a NEW NODE!
	TrieNode* children[26];
	bool bIsEndOfWord;

	TrieNode() :
		bIsEndOfWord(false)
	{
		for (TrieNode* node : children.members)
			node = nullptr;
	}

	void InsertRec(string str = "hello", int idx = 0) {
		if (idx > str.length())
			return;

		if (idx == str.length())
			bIsEndOfWord = true;

		if (children[str[idx]] == nullptr)
			children[str[idx]] = new TrieNode();
		
		children[str[idx]]->InsertRec(str, idx + 1);
	}

	void Insert(string str = "hello") {
		TrieNode* itr = this;

		for (int i = 0; i < str.size(); ++i) {
			if (children[str[i]] == nullptr)
				children[str[i]] = new TrieNode();

			itr = children[str[i]];
		}

		itr->bIsEndOfWord == true;
	}

	bool Find(string str) {
		TrieNode* itr = this;

		for (int i = 0; i < str.size(); ++i) {
			if (itr->children[str[i]] != nullptr) // has child node
				itr = children[str[i]];
			else
				return false;
		}

		return true;
	}

	bool FindRec(string str, int idxInStr) {
		if (idxInStr >= str.length())
			return true;

		if (children[str[idxInStr]] != nullptr) // has child node
			FindRec(str, idxInStr + 1);
		else
			return false;
	}
};

