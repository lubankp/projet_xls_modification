#pragma once
#include "file.h"

class Transformation {

private:
	File file1;
	File file2;

public:

	void modification() {
	
		for (int row = file1.get_sheet()->firstRow(); row < file1.get_sheet()->lastRow(); ++row)
		{
			for (int col = file1.get_sheet()->firstCol(); col < file1.get_sheet()->lastCol(); ++col)
			{
				
				file2.get_sheet()->writeStr(col, row, file1.get_sheet()->readStr(row,col));
			}
		}
	
	}

	void transform_file(const wchar_t* file_name1, const wchar_t* file_name2) {
	
		file1.create_file();
		file2.create_file();

		file2.set_format_and_font(8, L"Century Gothic");
		file2.create_sheet(L"New");

		file1.open_file(file_name1);
		modification();
		//file1.print_sheet();
		file2.save_file(file_name2);
	}

};