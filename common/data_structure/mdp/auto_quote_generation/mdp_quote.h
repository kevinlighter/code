#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#ifndef _MDP_QUOTE_H_
#define _MDP_QUOTE_H_

using namespace std;
namespace kevin {
namespace mdp {

class MDPQuote
{
public:

	MDPQuote();
	~MDPQuote() = default;;

	/// @brief input a sentence and update the model
	void update_model(const vector<string>& vec);

	/// @brief make a prediction
	void predict();

	/// @brief return the model
	inline auto model() const {
		return model_;
	}



private:
	unordered_map<string, vector<string> > model_;
};

template <class T>
ostream& operator<<(ostream& s, const vector<T>& vec){
	for (auto& t : vec) {
		s << t << " ";
	}
	return s; 
}

template <class T, class R>
ostream& operator<<(ostream& s, const unordered_map<T, R>& map){
	s << "model is: " << std::endl;
	for (auto& t : map) {
		s << t.first << " : " << t.second << " " << std::endl;
	}
	return s; 
}



}
}

#endif