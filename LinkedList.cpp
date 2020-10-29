#include <iostream>
#include "LinkedList.h"
using std::cout;
using std::endl;

LinkedList::LinkedList()
{
	head_ = nullptr;
}

LinkedList::~LinkedList()
{
	if (head_ == nullptr)
		return;

	while (head_->next_ != nullptr)
	{
		LNode *temp = head_;
		head_ = head_->next_;
		delete temp;
		temp = nullptr;
	}

	delete head_;
	head_ = nullptr;
}

void LinkedList::print() const
{
	if (head_ == nullptr)
		return;

	cout << head_->data_;

	LNode *curr = head_->next_;
	while (curr != nullptr)
	{
		cout << " ";
		cout << curr->data_;
		curr = curr->next_;
	}
}

LNode *LinkedList::find(int t) const
{
	if (head_ == nullptr)
		return nullptr;

	if (head_->data_ == t)
		return head_;

	LNode *temp = head_->next_;

	while (temp != nullptr)
	{
		if (temp->data_ == t)
			return temp;
		else
			temp = temp->next_;
	}

	return nullptr;
}

void LinkedList::insert_head(int t)
{
	LNode *newHead = new LNode;
	newHead->data_ = t;
	newHead->next_ = head_;
	head_ = newHead;
}

void LinkedList::insert_after(LNode *location, int t)
{
	if (location == nullptr)
		return;

	LNode *newNode = new LNode;
	newNode->data_ = t;
	newNode->next_ = location->next_;
	location->next_ = newNode;
}

void LinkedList::remove(LNode *location)
{
	if (location == nullptr)
		return;

	if (location == head_)
	{
		if (head_->next_ == nullptr)
		{
			delete head_;
			head_ = nullptr;
			return;
		}

		head_ = head_->next_;
		delete location;
		location = nullptr;
		return;
	}

	LNode *curr = head_;
	while (head_->next_ != nullptr)
	{
		if (head_->next_ == location)
		{
			head_->next_ = location->next_;
			delete location;
			location = nullptr;
			return;
		}
	}
}
