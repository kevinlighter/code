#include "../../common/reader/csv.h"
#include <iostream>


int main()
{
	// Creating an object of CSVWriter
	CSVReader reader("train.csv");
 
	// Get the data from CSV File
	std::vector<std::vector<std::string> > dataList = reader.getData();
 

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