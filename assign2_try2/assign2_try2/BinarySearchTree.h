#pragma once
#include <iostream>
//BinarySearchTreeTemplate.h

template<typename T>
class BinarySearchTree
{
private:
	struct Node;

public:
	BinarySearchTree();
	void insert(const T &p_data);
	void clear();
	bool find(const T &p_data);
	int size();

	// One traversal for pass, all three for pass with distinction requirement
	void traversal_pre_order();
	void traversal_in_order();
	void traversal_post_order();

	// Pass with distinction requirement
	void remove(const T &p_data);
private:
	bool isGreater(std::shared_ptr<Node> p_node, const T &p_data);
	std::shared_ptr<typename Node> getBranch(std::shared_ptr<Node> p_node, const T &p_data);
	int AmountOfChildren(std::shared_ptr<Node> p_node);

	void insertRecursive(std::shared_ptr<Node> p_node, const T &p_data);
	//void clearRecursive(std::shared_ptr<Node> p_node);
	bool findRecursive(std::shared_ptr<Node> p_node, const T &p_data);
	int sizeRecursive(std::shared_ptr<Node> p_node);

	// One traversal for pass, all three for pass with distinction requirement
	void traversal_pre_orderRecursive(std::shared_ptr<Node> p_node);
	void traversal_in_orderRecursive(std::shared_ptr<Node> p_node);
	void traversal_post_orderRecursive(std::shared_ptr<Node> p_node);

	// Pass with distinction requirement
	void removeRecursive(std::shared_ptr<Node> p_node, const T &p_data);
	std::shared_ptr<Node> m_root;
	bool removeSwitch;
};

template<typename T>
struct BinarySearchTree<T>::Node
{
	Node(const T &p_data) : m_data(p_data), m_lesser(nullptr), m_greater(nullptr) {};
	T m_data;
	std::shared_ptr<Node> m_lesser; // Left
	std::shared_ptr<Node> m_greater; // Right
};

template<typename T>
inline BinarySearchTree<T>::BinarySearchTree() : removeSwitch(false)
{
}

template<typename T>
void BinarySearchTree<T>::insert(const T &p_data)
{
	if (m_root == nullptr) {
		m_root = std::make_shared<Node>(p_data);
	}
	else {
		insertRecursive(m_root, p_data);
	}

	// Pseudo Code
	//
	// Should check if the current root is a nullptr or not.
	//
	// If the root is a nullptr then assign it a new node using make_shared<Node>.
	//
	// If the root is not a nullptr, then call insertRecursive sending the data and the root as parameter
	//
}
template<typename T>
inline void BinarySearchTree<T>::clear()
{
	m_root = nullptr;
}
template<typename T>
inline bool BinarySearchTree<T>::find(const T & p_data)
{
	if (m_root != nullptr && m_root->m_data == p_data) {
		return true;
	}
	else {
		return findRecursive(m_root, p_data);
	}
}
template<typename T>
inline int BinarySearchTree<T>::size()
{
	if (m_root == nullptr) {
		return 0;
	}
	else {
		return sizeRecursive(m_root);
	}
}
template<typename T>
inline void BinarySearchTree<T>::traversal_pre_order()
{
	std::cout << "Traversal pre order:\n";

	traversal_pre_orderRecursive(m_root);
}
template<typename T>
inline void BinarySearchTree<T>::traversal_in_order()
{
	std::cout << "Traversal in order:\n";

	traversal_in_orderRecursive(m_root);
}
template<typename T>
inline void BinarySearchTree<T>::traversal_post_order()
{
	std::cout << "Traversal post order:\n";

	traversal_post_orderRecursive(m_root);
}


template<typename T>
inline void BinarySearchTree<T>::remove(const T & p_data)
{
	removeRecursive(m_root, p_data);
}

template<typename T>
inline bool BinarySearchTree<T>::isGreater(std::shared_ptr<Node> p_node, const T & p_data)
{
	return p_data > p_node->m_data;
}

template<typename T>
inline std::shared_ptr<typename BinarySearchTree<T>::Node> BinarySearchTree<T>::getBranch(std::shared_ptr<Node> p_node, const T & p_data)
{
	std::shared_ptr<Node> branch;
	if (isGreater(p_node, p_data)) {
		branch = p_node->m_greater;
	}
	else {
		branch = p_node->m_lesser;
	}
	return branch;
}

template<typename T>
inline int BinarySearchTree<T>::AmountOfChildren(std::shared_ptr<Node> p_node)
{
	int children = 0;
	if (p_node->m_greater != nullptr) {
		children++;
	}
	if (p_node->m_lesser != nullptr) {
		children++;
	}

	return children;
}

template<typename T>
void BinarySearchTree<T>::insertRecursive(std::shared_ptr<Node> p_node, const T &p_data)
{
	if (isGreater(p_node, p_data)) {
		if (p_node->m_greater == nullptr) {
			p_node->m_greater = std::make_shared<Node>(p_data);
		}
		else {
			insertRecursive(p_node->m_greater, p_data);
		}
	}
	else {
		if (p_node->m_lesser == nullptr) {
			p_node->m_lesser = std::make_shared<Node>(p_data);
		}
		else {
			insertRecursive(p_node->m_lesser, p_data);
		}
	}
}
template<typename T>
inline bool BinarySearchTree<T>::findRecursive(std::shared_ptr<Node> p_node, const T & p_data)
{
	auto branch = getBranch(p_node, p_data);

	if (branch == nullptr) {
		return false;
	}
	else if (branch->m_data == p_data) {
		return true;
	}
	else {
		return findRecursive(branch, p_data);
	}
}
template<typename T>
inline int BinarySearchTree<T>::sizeRecursive(std::shared_ptr<Node> p_node)
{
	int size = 1;
	if (p_node->m_greater != nullptr) {
		size += sizeRecursive(p_node->m_greater);
	}
	if (p_node->m_lesser != nullptr) {
		size += sizeRecursive(p_node->m_lesser);
	}
	return size;
}
template<typename T>
inline void BinarySearchTree<T>::traversal_pre_orderRecursive(std::shared_ptr<Node> p_node)
{
	if (p_node->m_greater != nullptr) {
		traversal_pre_orderRecursive(p_node->m_greater);
	}
	
	std::cout << p_node->m_data << "\n";
	
	if (p_node->m_lesser != nullptr) {
		traversal_pre_orderRecursive(p_node->m_lesser);
	}
}
template<typename T>
inline void BinarySearchTree<T>::traversal_in_orderRecursive(std::shared_ptr<Node> p_node)
{
	if (p_node->m_lesser != nullptr) {
		traversal_in_orderRecursive(p_node->m_lesser);
	}

	std::cout << p_node->m_data << "\n";
	
	if (p_node->m_greater != nullptr) {
		traversal_in_orderRecursive(p_node->m_greater);
	}
}
template<typename T>
inline void BinarySearchTree<T>::traversal_post_orderRecursive(std::shared_ptr<Node> p_node)
{
	if (p_node->m_lesser != nullptr) {
		traversal_post_orderRecursive(p_node->m_lesser);
	}
	if (p_node->m_greater != nullptr) {
		traversal_post_orderRecursive(p_node->m_greater);
	}

	std::cout << p_node->m_data << "\n";
}
template<typename T>
inline void BinarySearchTree<T>::removeRecursive(std::shared_ptr<Node> p_node, const T & p_data)
{
	auto branch = getBranch(p_node, p_data);
	if (branch == nullptr) {
		return;
	}

	if (branch->m_data == p_data) {
		bool branch_is_great = isGreater(p_node, p_data);

		switch (AmountOfChildren(branch)) {
		// removing a node with 0 children
		case 0:
			if (branch_is_great) {
				p_node->m_greater = nullptr;
			}
			else {
				p_node->m_lesser = nullptr;
			}
			break;
		// removing a node with 1 child
		case 1:
		{
			std::shared_ptr<Node> swap;
			if (branch->m_greater != nullptr) {
				swap = branch->m_greater;
			}
			else {
				swap = branch->m_lesser;
			}

			if (branch_is_great) {
				p_node->m_greater = swap;
			}
			else {
				p_node->m_lesser = swap;
			}
		}
			break;
		// removing a node with 2 children
		case 2:
		{
			T swap;
			std::shared_ptr<Node> current;
			removeSwitch = !removeSwitch;
			if (removeSwitch) { // biggest leaf of the smaller branch
				current = branch->m_lesser;
				while (current->m_greater != nullptr) {
					current = current->m_greater;
				}
				swap = current->m_data;
			}
			else {  // smalleset leaf of the biggest branch
				current = branch->m_greater;
				while (current->m_lesser != nullptr) {
					current = current->m_lesser;
				}
				swap = current->m_data;
			}

			if (branch_is_great) {
				p_node->m_greater->m_data = swap;
				removeRecursive(branch, swap);
			}
			else {
				p_node->m_lesser->m_data = swap;
				removeRecursive(branch, swap);
			}
		}
			break;
		}
	}
	else {
		removeRecursive(branch, p_data);
	}
}