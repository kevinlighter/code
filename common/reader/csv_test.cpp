#include "csv.h"
#include <iostream>


int main()
{
	// Creating an object of CSVWriter
	CSVReader reader("/home/kailiang.chen/Documents/git/common/reader/example.csv");
 
	// Get the data from CSV File
	std::vector<std::vector<std::string> > dataList = reader.getData();
 
	std::cout << "123" << std::endl;

	// Print the content of row by row on screen
	for(std::vector<std::string> vec : dataList)
	{
		for(std::string data : vec)
		{
			std::cout<<data << " , ";
		}
		std::cout<<std::endl;
	}
	return 0;
 
}