#pragma once
#include "libxl.h"
#include <iostream>


class File {

private:
	
	libxl::Book* book;
	libxl::Sheet* sheet;


public:

	void open_file(const wchar_t* file_name) {

		try {
			book = xlCreateBook();
			book->load(L"file.xls");

			sheet = book->getSheet(0);
		}
		catch (const std::exception& e) {

			std::cout << "Can not open file: " << e.what() << std::endl;
		}
	}


	void print_sheet() {
	
		for (int row = sheet->firstRow(); row < sheet->lastRow(); ++row)
		{
			for (int col = sheet->firstCol(); col < sheet->lastCol(); ++col)
			{
				std::wstring ws(sheet->readStr(row, col));
				std::string str(ws.begin(), ws.end());
				std::cout << "(" << row << ", " << col << ") = " << str << std::endl;
			}
		}
	}

};