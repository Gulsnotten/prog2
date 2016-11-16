#include "LinkedList.h"
#include "BinarySearchTree.h"
#include "UnitTest.h"
#include <string>

#include <iostream>

int main() {
	LinkedList<std::string> list;

	std::cout << "Testing linked list...\n";

	// add some stuff
	list.push_back("mickey");
	list.push_back("donald");
	list.push_back("goofy");
	list.push_front("pluto");
	list.insert("daisy", 2);

	// add then pop both (they will not show up)
	list.push_back("black pete");
	list.pop_back();
	list.push_front("scrooge");
	list.pop_front();
	list.insert("176-761", 2);
	list.remove("176-761");

	// should print: pluto, mickey, daisy, donald, goofy
	list.print();

	UnitTest::TestEqual<std::string>(list.at(0), "pluto", "pluto");
	UnitTest::TestEqual<std::string>(list.at(1), "mickey", "mickey");
	UnitTest::TestEqual<std::string>(list.at(2), "daisy", "daisy");
	UnitTest::TestEqual<std::string>(list.at(3), "donald", "donald");
	UnitTest::TestEqual<std::string>(list.at(4), "goofy", "goofy");

	std::cout << "at(2) = " << list.at(2) << "\n";
	std::cout << "find(donald) = " << list.find("donald") << "\n";
	std::cout << "find(black pete) = " << list.find("black pete") << "\n";
	std::cout << "list size = " << list.size() << "\n";

	list.clear();
	list.print();




	std::cout << "\nTesting binary search tree...\n";

	BinarySearchTree<int> bst;

	bst.insert(5);
	bst.insert(2);
	bst.insert(6);
	bst.insert(3);
	bst.insert(9);
	bst.insert(4);
	bst.insert(10);
	bst.insert(1);
	bst.insert(7);
	bst.insert(8);

	bst.remove(4);
	bst.remove(7);
	bst.remove(2);

	UnitTest::TestEqual<bool>(bst.find(4), false, "remove node with 0 children");
	UnitTest::TestEqual<bool>(bst.find(7), false, "remove node with 1 child");
	UnitTest::TestEqual<bool>(bst.find(2), false, "remove node with 2 children");

	bst.traversal_in_order();
	bst.traversal_pre_order();
	bst.traversal_post_order();

	std::cout << "find(6) = " << bst.find(6) << "\n";
	std::cout << "find(11) = " << bst.find(11) << "\n";
	std::cout << "size = " << bst.size() << "\n";

	return 0;
}