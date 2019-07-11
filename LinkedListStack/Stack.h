#pragma once

class Stack
{
	class Node
	{
	public:
		Node() = default;
		Node(int value,Node* previous);
		~Node();
		Node* previous;
		int value;
		Node& operator=(const Node&) = delete;
		Node(const Node& src);
	};
public:
	Stack() = default;
	Stack(const Stack& src);
	Stack& operator=(const Stack& src);
	~Stack();
	void Push(int val);
	int Pop();
	int Size() const;
	bool Empty() const;
private:
	Node* current = nullptr;
	int size = 0;
};