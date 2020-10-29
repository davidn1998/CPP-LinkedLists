#include <iostream>
using std::cout;
using std::endl;

struct Node
{
	int data;
	Node *next;
};

// print all integers in the list, in order
void print(Node *head)
{
	if (head == nullptr)
		return;

	cout << head->data;

	if (head->next != nullptr)
	{
		cout << " ";
		print(head->next);
	}
}

// find integer t from the list, returning a pointer to that node.
// If there are more than one match, return the first one.
// if not found, return nullptr
Node *find(Node *head, int t)
{
	if (head == nullptr)
		return nullptr;

	if (head->data == t)
		return head;
	else if (head->next != nullptr)
		return find(head->next, t);

	return nullptr;
}

// insert integer t to the list as the new head
// (yep, you can pass pointers by reference!)
void insert_head(Node *&head, int t)
{
	Node *tmp = new Node;
	tmp->data = t;
	tmp->next = head;
	head = tmp;
}

// insert t as a new node after "location"
// location is assumed to point to a valid position in the list
void insert_after(Node *location, int t)
{
	if (location == nullptr)
		return;

	Node *newNode = new Node;
	newNode->data = t;

	newNode->next = location->next;
	location->next = newNode;
}

// remove head from the list
void remove_head(Node *&head)
{
	if (head == nullptr)
		return;

	Node *temp = head;
	head = head->next;
	delete temp;
	temp = nullptr;
}

// remove the NEXT integer i.e. after the one pointed to by "location"
// location is assumed to point to a valid position in the list
// if there is no next integer after location (i.e. location points to
// the last one) do nothing
void remove_after(Node *location)
{
	if (location == nullptr)
		return;
	if (location->next == nullptr)
		return;

	if (location->next->next != nullptr)
	{
		Node *temp = location->next;
		location->next = location->next->next;
		delete temp;
		temp = nullptr;
	}
	else
	{
		delete location->next;
		location->next = nullptr;
	}
}

// delete all nodes and release all memory
void cleanup(Node *&head)
{
	if (head == nullptr)
		return;

	if (head->next != nullptr)
		cleanup(head->next);

	delete head;
	head = nullptr;
}

int main()
{
	// some example usage of these functions
	Node *mylist = nullptr;
	print(mylist);
	cout << endl
		 << endl;
	insert_head(mylist, 1);
	insert_head(mylist, 2);
	insert_head(mylist, 3);
	print(mylist);
	cout << endl
		 << endl;
	Node *result = find(mylist, 3);
	if (result != nullptr)
		insert_after(result, 5);
	print(mylist);
	cout << endl
		 << endl;
	remove_head(mylist);
	print(mylist);
	cout << endl
		 << endl;
	remove_after(find(mylist, 5));
	print(mylist);
	cout << endl
		 << endl;
	cleanup(mylist);
	print(mylist);
}