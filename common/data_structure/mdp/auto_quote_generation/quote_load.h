#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <boost/tokenizer.hpp>

using namespace std;

namespace kevin {
namespace mdp {


/// @brief input a filename and return vector of string of that file by rows
vector<string> file_load(const string& filename)
{
	ifstream file(filename);
	string str = "";

	vector<string> output;
	output.reserve(1000);

	/// @brief get a line
	while (getline(file, str)) {
		stringstream ss(str);
		string item = "";
		/// @brief get rid of string after ; mark
		getline(ss, item, ';');
		/// @brief get rid of all the punctation marks
		item.erase (std::remove_if(item.begin (), item.end (), 
			std::ptr_fun<int, int>(&std::ispunct)), item.end ());

		/// @brief transfer all the cases to lowercases
		transform(item.begin(), item.end(), item.begin(), ::tolower);
		output.push_back(item);
	}

	return output;
}

/// @brief input a string text and return the vector of string by word
vector<string> separate_string(const string& text)
{
	boost::char_separator<char> sep(" ");
	boost::tokenizer<boost::char_separator<char>> tokens(text, sep);

	vector<string> vec;
	vec.reserve(30);
	
	copy(tokens.begin(), tokens.end(), inserter(vec, vec.end()));

	return vec;
}

}
}