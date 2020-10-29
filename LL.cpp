#include <iostream>
using std::cout;
using std::endl;

struct Node {
	int data;
	Node* next;
};

// print all integers in the list, in order
void print(Node* head) {
	// IMPLEMENT ME
}

// find integer t from the list, returning a pointer to that node.
// If there are more than one match, return the first one.
// if not found, return nullptr
Node* find(Node* head, int t) {
	Node* tmp = head;
	while(tmp != nullptr) {
		if (tmp->data == t) return tmp;
		tmp = tmp->next;
	}
	return tmp;
}

// insert integer t to the list as the new head
// (yep, you can pass pointers by reference!)
void insert_head(Node*& head, int t) {
	Node* tmp = new Node;
	tmp->data = t;
	tmp->next = head;
	head = tmp;
}

// insert t as a new node after "location"
// location is assumed to point to a valid position in the list
void insert_after(Node* location, int t) {
	// IMPLEMENT ME
}

// remove head from the list
void remove_head(Node*& head) {
	// IMPLEMENT ME
}

// remove the NEXT integer i.e. after the one pointed to by "location"
// location is assumed to point to a valid position in the list
// if there is no next integer after location (i.e. location points to
// the last one) do nothing
void remove_after(Node* location) {
	// IMPLEMENT ME
}

// delete all nodes and release all memory
void cleanup(Node*& head) {
	// IMPLEMENT ME
}

int main() {
	// some example usage of these functions
	Node* mylist = nullptr;
	print(mylist);
	insert_head(mylist, 1);
	insert_head(mylist, 2);
	insert_head(mylist, 3);
	print(mylist);
	Node* result = find(mylist,3);
	if (result != nullptr) insert_after(result, 5);
	print(mylist);
	remove_head(mylist);
	print(mylist);
	remove_after(find(mylist,5));
	print(mylist);
	cleanup(mylist);
	print(mylist);

}
