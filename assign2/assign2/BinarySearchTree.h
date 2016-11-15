//BinarySearchTreeTemplate.h
#pragma once
#include <memory>

template<typename T>
class BinarySearchTree
{
private:
	struct Node;

public:
	void insert(const T &p_data);
	void clear();
	void find(const T &p_data);
	int size();

	//void traversal_pre_order();			// One traversal for pass, all three for pass with distinction requirement
	//void traversal_in_order();			// One traversal for pass, all three for pass with distinction requirement
	//void traversal_post_order();			// One traversal for pass, all three for pass with distinction requirement

	//void remove(const T &p_data);			// Pass with distinction requirement
private:
	void insertRecursive(std::shared_ptr<Node> p_node, const T &p_data);
	void clearRecursive(std::shared_ptr<Node> p_node);
	void findRecursive(std::shared_ptr<Node> p_node, const T &p_data);
	int sizeRecursive(std::shared_ptr<Node> p_node);

	//void traversal_pre_orderRecursive(std::shared_ptr<Node> p_node);			// One traversal for pass, all three for pass with distinction requirement
	//void traversal_in_orderRecursive(std::shared_ptr<Node> p_node);			// One traversal for pass, all three for pass with distinction requirement
	//void traversal_post_orderRecursive(std::shared_ptr<Node> p_node);			// One traversal for pass, all three for pass with distinction requirement

	//void removeRecursive(std::shared_ptr<Node> p_node, const T &p_data);			// Pass with distinction requirement
	std::shared_ptr<Node> m_root;
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
void BinarySearchTree<T>::insert(const T &p_data)
{
	// Pseudo Code
	//
	// Should check if the current root is a nullptr or not.
	//
	// If the root is a nullptr then assign it a new node using make_shared<Node>.
	//
	// If the root is not a nullptr, then call insertRecursive sending the data and the root as parameter
	//
};

template<typename T>
void BinarySearchTree<T>::insertRecursive(std::shared_ptr<Node> p_node, const T &p_data)
{
	// Pseudo Code
	//
	// Check if the data being inserted is of a lower or higher value compared to the node sent as a parameter in the function.
	//
	// If the value is lower we check, if the node parameters lesser reference is a nullptr, if it is a nullptr we create and put our new node there.
	// If the node parameters lesser reference is not a nullptr the function recursivly calls itself sending the lesser reference and data as parameters.
	//
	// If the value is greater we check, if the node parameters greater reference is a nullptr, if it is a nullptr we create and put our new node there.
	// If the node parameters greater reference is not a nullptr the function recursivly calls itself sending the greater reference and data as parameters.
	//
};