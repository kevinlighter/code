#include "mdp_quote.h"

namespace kevin {
namespace mdp {


MDPQuote::MDPQuote() {
	srand(time(NULL));
	vector<string> vec;
	vec.reserve(100);
	this->model_.insert(pair<string, vector<string> >("START", vec));
}

void MDPQuote::update_model(const vector<string>& vec)
{
	auto it = vec.begin();
	(this->model_.find("START")->second).push_back(*it);
	it ++;

	for (;it != vec.end();it++) {
		auto modelIt = this->model_.find(*(it-1));
		/// @brief if the word exists in the map already
		if (modelIt != this->model_.end()) {
			modelIt->second.push_back(*it);
		} else { /// @brief if the word not exist in the map
			vector<string> newVec;
			newVec.reserve(100);
			newVec.push_back(*it);
			this->model_.insert(pair<string, vector<string> >(*(it-1), newVec));
		}
	}
	
	auto modelIt = this->model_.find(*(it-1));
	if (modelIt != this->model_.end()){
		modelIt->second.push_back("END");
	} else {
		vector<string> newVec;
		newVec.reserve(100);
		newVec.push_back("END");
		this->model_.insert(pair<string, vector<string> >(*(it-1), newVec));
	}
}

void MDPQuote::predict()
{
	auto it = this->model_.find("START");
	if (it == this->model_.end())
		return;

	int sizeVec = it->second.size();
	string start_word = it->second[rand() % sizeVec];

	string wordNext = " ";

	while (wordNext != "END") {
		auto wordNextIt = this->model_.find(start_word);
		if (wordNextIt == this->model_.end())
			return;
		wordNext = wordNextIt->second[rand() % wordNextIt->second.size()];
		std::cout << wordNext << std::endl;
	}
}

}
}