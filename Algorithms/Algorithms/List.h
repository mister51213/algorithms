#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
class List {
public:
	struct Node;

public:
	class Iterator {
	public:
		Iterator(int idx = 0) {
			pNode = head;
			// allow getting an iterator at a specific index
			for (int i = 0; i < idx && pNode; pNode = pNode->next, i++);
		}

		Iterator(Node* node) {
			pNode = node;
		}

		bool operator ==(Node* node) const {
			return pNode == node;
		}

		T& operator* () {
			return pNode->val;
		}

		Iterator& operator = (Node* node) {
			pNode = node;
			return *this;
		}

		Iterator& operator ++ () {
			if (pNode->next)
				pNode = pNode->next;
			return *pNode;
		}

		Iterator& operator --() {
			if (pNode->prev)
				pNode = pNode->prev;
			return *pNode;
		}

		bool operator < (const Node& right) const {
			return pNode->val < right.val;
		}

		bool operator!= (const Iterator &Dummy) const {
			return pNode ? true : false;
		}

		void Destroy() {
			delete pNode;
			pNode = nullptr;
		}

	private:
		Node* pNode;
	};

	struct Node {
		Node* prev;
		Node* nex;
		T val;

		Node(const int val = 0) :
			prev(nullptr),
			nex(nullptr),
			val(val)
		{}
	};

public:
	List<T>():
		head(nullptr)
	{}

	Iterator begin() const {
		return Iterator(head);
	}

	Iterator end() const {
		return Iterator(tail);
	}

	Node* Insert(const T val) {

	}
	void AddToFront(T val) {
		if (head == nullptr)
			head = new Node(val);
		else {
			Node* oldHead = head;
			head->prev = new Node(val);
			head = head->prev;
			head->next = oldHead;
		}
	}
	void AddToBack(T val) {
		if (tail == nullptr)
			tail = new Node(val);
		else {
			Node* oldTail = tail;
			tail->next = new Node(val);
			tail = tail->next;
			tail->prev = oldTail;
		}
	}
	void RemoveAt(int Idx) {
		Iterator itr = List<T>::Iterator(Idx);
		if (itr != nullptr) { // checks if idx out of range
			itr->previous->next = itr->next;
			itr->next->previous = itr->previous;
			itr.Destroy();
		}
	}
	void Remove(T val) {
		Iterator itr = List<T>::Iterator();
		if (itr != nullptr) {
			while (itr != end()) {
				if (*itr == val) {
					itr->previous->next = itr->next;
					itr->next->previous = itr->previous;
					itr.Destroy();
					return;
				}
			}
		}
	}
	void Sort() {
		// Bubble Sort
		for (Node* i = head; i->next != nullptr; i = i->next) {
			for (Node* j = i; j->next != nullptr; j = j->next)
				if (i < j)
					swap(i, j);
		}
	}

	void Swap(Node& a, Node& b) {
		std::swap(&a, &b);
	}

	int length;
	Node* head, tail;
};

