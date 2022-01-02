#include <iostream>
#include "file.h"

int main() {

	std::cout << "Hello";

	File file;

	file.open_file(L"file.xls");
	file.print_sheet();
	
}
