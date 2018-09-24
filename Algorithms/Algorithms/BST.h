#include <iostream>
#include <math.h>
using namespace std;

template<typename T>
struct Node {
	T val;
	Node* left;
	Node* right;

	Node(T v) :
		val(v),
		left(nullptr),
		right(nullptr)
	{}
};

template<typename T>
class BST {
	Node<T> root;

	void Insert(T val) {
		// base case
		if (!root) {
			root = new Node(T);
		}
		else {
			if (val < root->val) {
				if (root->left)
					Insert(root->left);
				else
					root->left = new Node<T>(val);
			}
			else {
				if (root->right)
					Insert(root->right);
				else
					root->right = new Node<T>(val);
			}
		}
	}

	void InOrder(Node* r) {
		if (r) {
			InOrder(r->left);
			cout << r->val;
			InOrder(r->right);
		}
	}

	Node* Find(Node<T>* r, T v) {
		if (r) {
			if (r->val == v)
				return r;
			else if (v < r->val)
				return Find(r->left);
			else
				return Find(r->right);
		}
		else
			return nullptr;
	}

	void Destroy(node *r) {
		if (r != NULL) {
			Destroy(r->left);
			Destroy(r->right);
			delete r;
		}
	}

	/*
	https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
	*/

	/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
	struct node * minValueNode(struct node* node)
	{
		struct node* current = node;

		/* loop down to find the leftmost leaf */
		while (current->left != NULL)
			current = current->left;

		return current;
	}

	/* Given a binary search tree and a key, this function deletes the key
   and returns the new r */
	struct node* deleteNode(struct node* r, int key)
	{
		// base case
		if (r == NULL) return r;

		// If the key to be deleted is smaller than the r's key,
		// then it lies in left subtree
		if (key < r->key)
			r->left = deleteNode(r->left, key);

		// If the key to be deleted is greater than the r's key,
		// then it lies in right subtree
		else if (key > r->key)
			r->right = deleteNode(r->right, key);

		// if key is same as r's key, then This is the node
		// to be deleted
		else
		{
			// node with only one child or no child
			if (r->left == NULL)
			{
				struct node *temp = r->right;
				free(r);
				return temp;
			}
			else if (r->right == NULL)
			{
				struct node *temp = r->left;
				free(r);
				return temp;
			}

			// node with two children: Get the inorder successor (smallest
			// in the right subtree)
			struct node* temp = minValueNode(r->right);

			// Copy the inorder successor's content to this node
			r->key = temp->key;

			// Delete the inorder successor
			r->right = deleteNode(r->right, temp->key);
		}
		return r;
	}
};

//template <class T>
//struct Node {
//	T value;
//	Node *left;
//	Node *right;
//
//	Node(T val) {
//		this->value = val;
//	}
//
//	Node(T val, Node<T> left, Node<T> right) {
//		this->value = val;
//		this->left = left;
//		this->right = right;
//	}
//};
//
//template <class T>
//class BST {
//
//private:
//	Node<T> *root;
//
//	void addHelper(Node<T> *root, T val) {
//		if (root->value > val) {
//			if (!root->left) {
//				root->left = new Node<T>(val);
//			}
//			else {
//				addHelper(root->left, val);
//			}
//		}
//		else {
//			if (!root->right) {
//				root->right = new Node<T>(val);
//			}
//			else {
//				addHelper(root->right, val);
//			}
//		}
//	}
//
//	void printHelper(Node<T> *root) {
//		if (!root) return;
//		printHelper(root->left);
//		cout << root->value << ' ';
//		printHelper(root->right);
//	}
//
//	int nodesCountHelper(Node<T> *root) {
//		if (!root) return 0;
//		else return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
//	}
//
//	int heightHelper(Node<T> *root) {
//		if (!root) return 0;
//		else return 1 + max(heightHelper(root->left), heightHelper(root->right));
//	}
//
//	void printMaxPathHelper(Node<T> *root) {
//		if (!root) return;
//		cout << root->value << ' ';
//		if (heightHelper(root->left) > heightHelper(root->right)) {
//			printMaxPathHelper(root->left);
//		}
//		else {
//			printMaxPathHelper(root->right);
//		}
//	}
//
//	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
//		if (!current) return false;
//		if (current->value == value) {
//			if (current->left == NULL || current->right == NULL) {
//				Node<T>* temp = current->left;
//				if (current->right) temp = current->right;
//				if (parent) {
//					if (parent->left == current) {
//						parent->left = temp;
//					}
//					else {
//						parent->right = temp;
//					}
//				}
//				else {
//					this->root = temp;
//				}
//			}
//			else {
//				Node<T>* validSubs = current->right;
//				while (validSubs->left) {
//					validSubs = validSubs->left;
//				}
//				T temp = current->value;
//				current->value = validSubs->value;
//				validSubs->value = temp;
//				return deleteValueHelper(current, current->right, temp);
//			}
//			delete current;
//			return true;
//		}
//		return deleteValueHelper(current, current->left, value) ||
//			deleteValueHelper(current, current->right, value);
//	}
//
//public:
//	void add(T val) {
//		if (root) {
//			this->addHelper(root, val);
//		}
//		else {
//			root = new Node<T>(val);
//		}
//	}
//
//	void print() {
//		printHelper(this->root);
//	}
//
//	int nodesCount() {
//		return nodesCountHelper(root);
//	}
//
//	int height() {
//		return heightHelper(this->root);
//	}
//
//	void printMaxPath() {
//		printMaxPathHelper(this->root);
//	}
//
//	bool deleteValue(T value) {
//		return this->deleteValueHelper(NULL, this->root, value);
//	}
//};