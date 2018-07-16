#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iostream>

#ifndef _CSVREADER_H_
#define _CSVREADER_H_
/*
 * A class to read data from a csv file.
 */
class CSVReader
{
	std::string fileName;
	std::string delimeter;
 
public:
	CSVReader(std::string filename, std::string delm = ",") :
			fileName(filename), delimeter(delm)
	{ }
 
	// Function to fetch data from a CSV File
	std::vector<std::vector<std::string> > getData();
};

#endif