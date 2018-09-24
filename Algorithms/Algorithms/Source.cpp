#include "List.h"
#include "Inheritance.h"

int main() {
	List<int> list;
	//for (auto val : list) {
	//	//cout << val;
	//}

	Child* ch = &(Child());
	ch->func();

	void* pSource = ch;

	int* myInt = new int(6);
	Base* p1 = (Base*)myInt;
	Unrelated* p2 = dynamic_cast<Unrelated*>(ch);
	Unrelated* p3 = static_cast<Unrelated*>(pSource);
	//Unrelated* p4 = static_cast<Unrelated*>(ch);
	Unrelated* p5 = (Unrelated*)ch;

	Base* base = ch;
	((Child*)base)->childFunc();
	static_cast<Child*>(base)->childFunc();
	reinterpret_cast<Child*>(base)->childFunc();
	dynamic_cast<Child*>(base)->childFunc();

	//TrieNode* head = new TrieNode();

	//InsertWord("hello", head);
	//InsertWord("hella", head);
	//InsertWord("hierarch", head);
	//InsertWord("hi", head);
	//InsertWord("heel", head);

	//cout << (ContainsWord("heel", head) ? "true" : "false");

	int stopper;
	cin >> stopper;

	return 0;
}