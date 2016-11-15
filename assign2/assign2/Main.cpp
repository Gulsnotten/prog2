#include "LinkedList.h"
#include <string>
#include <iostream>

int main() {
	LinkedList<std::string> list;
	list.push_back("mickey");
	list.push_back("donald");
	list.insert("goofy", 1);
	std::cout << list.find("scrooge");

	list.print();

	return 0;
}