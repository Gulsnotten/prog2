#pragma once
#include <memory>
#include <iostream>
//LinkedListTemplate.h

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


template<typename T>
LinkedList<T>::LinkedList() : m_root(nullptr)
{
}

template<typename T>
LinkedList<T>::~LinkedList()
{
}

template<typename T>
void LinkedList<T>::push_front(const T &p_data)
{
	if (m_root == nullptr) {
		m_root = std::make_shared<Node>(p_data);
	}
	else {
		m_current = std::make_shared<Node>(*m_root);
		m_root = std::make_shared<Node>(p_data);
		m_root->m_next = m_current;
	}
}
template<typename T>
void LinkedList<T>::push_back(const T & p_data)
{
	if (m_root == nullptr) {
		m_root = std::make_shared<Node>(p_data);
	}
	else {
		m_current = m_root;
		while (m_current->m_next != nullptr) {
			m_current = m_current->m_next;
		}
		m_current->m_next = std::make_shared<Node>(p_data);
	}
}
template<typename T>
void LinkedList<T>::pop_front()
{
	if (m_root != nullptr) {
		m_root = m_root->m_next;
	}
}
template<typename T>
void LinkedList<T>::pop_back()
{
	if (m_root == nullptr) {
		return;
	}
	else {
		m_current = m_root;
		while (m_current->m_next != nullptr) {
			if (m_current->m_next->m_next == nullptr) {
				m_current->m_next = nullptr;
			}
			else {
				m_current = m_current->m_next;
			}
		}
	}
}
template<typename T>
void LinkedList<T>::clear()
{
	m_root = nullptr;
}
template<typename T>
bool LinkedList<T>::find(const T & p_data)
{
	m_current = m_root;
	while (m_current != nullptr) {
		if (m_current->m_data == p_data) {
			return true;
		}
		m_current = m_current->m_next;
	}

	return false;
}
template<typename T>
void LinkedList<T>::print()
{
	m_current = m_root;
	while (m_current != nullptr) {
		std::cout << m_current->m_data << "\n";
		m_current = m_current->m_next;
	}
}
template<typename T>
const unsigned int LinkedList<T>::size()
{
	int s = 0;
	m_current = m_root;
	while (m_current != nullptr) {
		s++;
		m_current = m_current->m_next;
	}
	return s;
}


// Pass with distinction requirement
template<typename T>
T LinkedList<T>::at(const unsigned int & p_index)
{
	m_current = m_root;
	for (unsigned int i = 0; i < p_index; i++) {
		m_current = m_current->m_next;
	}

	return m_current->m_data;
}
template<typename T>
void LinkedList<T>::insert(const T & p_data, const unsigned int & p_index)
{
	if (p_index == 0) {
		push_front(p_data);
		return;
	}

	m_current = m_root;
	for (unsigned int i = 0; i < p_index - 1; i++) {
		m_current = m_current->m_next;
	}
	std::shared_ptr<Node> tmp = m_current->m_next;
	m_current->m_next = std::make_shared<Node>(p_data);
	m_current->m_next->m_next = tmp;
}
template<typename T>
void LinkedList<T>::remove(const T & p_data)
{
	if (p_data == m_root->m_data) {
		pop_front();
		return;
	}

	m_current = m_root;
	while (m_current->m_next != nullptr) {
		if (m_current->m_next->m_data == p_data) {
			m_current->m_next = m_current->m_next->m_next;
		}
		m_current = m_current->m_next;
	}
}