// Compiled with: g++ -Wall -std=c++14 -pthread

#include <iostream>
#include <algorithm>

using namespace std;

struct Node;
class LinkedList;

struct Node {
	Node *previous, *next;
	int value;

	Node() :
		previous(nullptr),
		next(nullptr),
		value(0)
	{}

	Node(int val) :
		previous(nullptr),
		next(nullptr),
		value(val),
	{}

};

class LinkedList {
public:
	LinkedList() :
		head(nullptr),
		tail(nullptr),
		length(0)
	{}

	~LinkedList()
	{}

	// Returns the new head
	Node* AddToFront(int value) { // TODO: Fix up tail
		if (head == nullptr)
			head = new Node(value);
		else {
			Node* oldHead = head;
			head->previous = new Node(value);
			head = head->previous;
			head->next = oldHead;
		}

		length++;
		return head;
	}

	Node* AddToBack(int value) {
		if (tail == nullptr)
			tail = new Node(value); // TODO: Fix up the head
		else {
			Node* oldTail = tail;
			tail->next = new Node(value);
			tail = tail->next;
			tail->previous = oldTail;
		}

		length++;
		return tail;
	}

	void InsertAfterIdx(int itemToInsert, int index) {
		// 1. Iterate to the node
		Node* itr = head;

		// @TODO: check for off by one errors
		for (int currIdx = 0; itr != nullptr && currIdx < index; currIdx++)
			itr = itr->next;

		Node* oldNext = itr->next; // save old next
		itr->next = new Node(itemToInsert); // spawn new node after current
		itr->next->next = oldNext; // fix up newly spawned node
		oldNext->previous = itr->next; // fix up old next
		itr->next->previous = itr; // fix up new node PREVIOUS  

		length++;
	}

	void InsertBeforeIdx(int itemToInsert, int index) {
		// 1. Iterate to the node
		Node* itr = head;

		// @TODO: check for off by one errors
		for (int currIdx = 0; itr != nullptr && currIdx < index; currIdx++)
			itr = itr->next;

		Node* oldPrevious = itr->previous; // save old previous
		itr->previous = new Node(itemToInsert); // spawn new node BEFORE current
		itr->previous->previous = oldPrevious; // fix up newly spawned node
		oldPrevious->next = itr->previous; // fix up old previous
		itr->previous->next = itr; // fix up new node NEXT 

		length++;
	}

	void Remove(int itemToRemove) {
		// 1. Advance iterator to desired node
		Node* itr = head;
		for (; itr->next != nullptr && itr->value != itemToRemove; itr = itr->next);

		if (itr->next == nullptr)
			return;
		else {
			itr->previous = itr->next;
			itr->next = itr->previous;
			delete itr;
			length--;
		}
	}

	inline unsigned int length() {
		return length;
	}

	bool Contains(int item) {
		for (Node* itr = head; itr->next != nullptr; itr = itr->next) {
			if (itr->value == itemToRemove)
				return true;
		}

		return false;
	}


	// quicksort
	void Sort(Node* begin, Node* end) {

		if (

			int currLength = length;

			// LOOP BODY

			// 1. Get our pivot
			int pivotIdx = currLength >> 1;
			Node* pivotNode = head;
			for (int currIdx = 0; itr != nullptr && currIdx < pivotIdx; currIdx++) // TODO: check for off by one
				pivotNode = pivotNode->next;

			int pivotValue = pivotNode->value;

		// 2. Converge pointers to beginning and end, and swap anything on wrong side of the pivot
		Node* begin = head;
		Node* end = tail;
		while (begin < end) { // @TODO - check for off by one
			if (begin->value < end->value)
				swap(begin->value, end->value);
		}

		// 3. partition the array where we have converged, and repeat step 2.
	}

	void BubbleSort() {





	}







public:
	Node* head, *tail;
	unsigned int length;
};

/* TODO:
1. check for off by one errors
2. in insert functions, do nullptr checks
3. in add to front / back, fix up tail

*/
// Implement a generic Linked List from scratch with the following interface
//
//////// AddToFront(itemToAdd)
//////// AddToBack(itemToAdd)
//////// InsertAfter(itemToInsert, referenceItem)
//////// InsertBefore(itemToInsert, referenceItem)
//////// Remove(itemToRemove)
/////// uint Length()
/////// bool Contains(item)
// Sort()