#include "LinkedList.h"
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

	return 0;
}