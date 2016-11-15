//LinkedListTemplate.h

#pragma once
#include <memory>
#include <iostream>

template<typename T>
class LinkedList
{
private:
	struct Node;

public:
	LinkedList();
	~LinkedList();

	void push_front(const T &p_data);
	void push_back(const T &p_data);
	void pop_front();
	void pop_back();
	void clear();
	bool find(const T &p_data);
	void print();
	const unsigned int size();
	
	// Pass with distinction requirement
	T at(const unsigned int &p_index);
	void insert(const T &p_data, const unsigned int &p_index);
	void remove(const T &p_data);

private:
	std::shared_ptr<Node> m_root;
	std::shared_ptr<Node> m_current; // Used as a temporary variable
};

template<typename T>
struct LinkedList<T>::Node
{
	Node(const T &p_data) : m_data(p_data), m_next(nullptr) {};
	T m_data;
	std::shared_ptr<Node> m_next;
};