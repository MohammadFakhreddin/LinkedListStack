#include "Stack.h"

Stack::Stack(const Stack& src)
{
	*this = src;
}

Stack& Stack::operator=(const Stack& src)
{
	if (&src != this) {
		if (!Empty()) {
			delete current;
			current = nullptr;
		}
		current = new Node(*src.current);
		size = src.size;
	}
	return *this;
}

Stack::~Stack()
{
	if (current) {
		delete current;
		current = nullptr;
	}
}

void Stack::Push(int val)
{
	size++;
	current = new Node(val, current);
}

int Stack::Pop()
{
	if (size <= 0 || !current) {
		return 0;
	}
	size--;
	Node* severedNode = current;
	current = current->previous;
	severedNode->previous = nullptr;
	const int value = severedNode->value;
	delete severedNode;
	return value;
}

int Stack::Size() const
{
	return size;
}

bool Stack::Empty() const
{
	return size == 0;
}

Stack::Node::Node(int value,Node* previous)
{
	this->value = value;
	this->previous = previous;
}

Stack::Node::~Node()
{
	delete previous;
	previous = nullptr;
}

Stack::Node::Node(const Node& src)
{
	this->value = src.value;
	if (src.previous != nullptr) {
		this->previous = new Node(*src.previous);
	}
	else
	{
		this->previous = nullptr;
	}
}