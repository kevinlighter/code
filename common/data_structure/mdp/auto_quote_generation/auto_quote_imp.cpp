#include <iostream>
#include <string>
#include "quote_load.h"
#include "mdp_quote.h"

using namespace std;
using namespace kevin::mdp;



int main(int, char**)
{

	vector<string> vec = kevin::mdp::file_load("quote.txt");
	MDPQuote quote;

	for (const auto& t : vec) {
		vector<string> words = separate_string(t);
		quote.update_model(words);
	}
    

    // string text = vec[0];

    // // char_separator<char> sep(" ");
    // // tokenizer<char_separator<char>> tokens(text, sep);
    // // for (const auto& t : tokens) {
    // //     cout << t << "." << endl;
    // // }

    // vector<string> vec1 = separate_string(text);



    // for (const auto& t : vec1) {
    //     cout << t << "." << endl;
    // }

    // MDPQuote quote;
    // quote.update_model(vec1);

    //std::cout << quote.model() << std::endl;

	quote.predict();
	// string f = "apple, orange ; banana ; canana";

 //    vector<string> tt;
 //    char de = ';';
 //    string a = kevin::mdp::quote_load(f, ';');

 //    std::cout << a << std::endl;

	

	//kevin::mdp::quote_load(&vec, ';');

	// for (auto& t : vec) {
	// 	std::cout << t << std::endl;
	// }

	// string text,result;
	// text = "Eat apple a day. Eat orange, and banana.";
	
	// std::remove_copy_if(text.begin(), text.end(),            
 //                        std::back_inserter(result), //Store output           
 //                        std::ptr_fun<int, int>(&std::ispunct)  
 //                       );
	// std::cout << result << std::endl;




	// text.erase (std::remove_if(text.begin (), text.end (), std::ptr_fun<int, int>(&std::ispunct)), text.end ());

	// std::cout << text << std::endl;



	return 0;
}