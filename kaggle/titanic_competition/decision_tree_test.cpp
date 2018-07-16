#include "decision_tree.h"
#include <assert.h>
#include <iostream>
#include "../../common/reader/csv.h"

using namespace std;

decision_tree::DecisionTree constructor_test()
{
	decision_tree::DecisionTree tree;

	// for (int i=0; i<10; i++) {
	// 	string str = "feature " + to_string(i);
	// 	feature_list.push_back(str);
	// }

	CSVReader reader("tennis_data.csv");
	vector<vector<string> > table = reader.getData();
	vector<string> vec;

	vector<string> feature_list = table[0];
	vector<vector<string> > train_data(table.begin()+1, table.end());

	vector<vector<string> > train_data_final;
	vector<string> data_label;
 
	for (int i = 0;i < train_data.size();i++) {

		vector<string> vec(train_data[i].begin(), train_data[i].end()-1);
		std::cout << "here: " << vec << " " << vec.size() << std::endl;
		train_data_final.push_back(vec);
		data_label.push_back(train_data[i].back());
	}

	// for (auto& t : train_data) {
	// 	vector<string> vec(t.rbegin(), t.rend());
	// 	train_data_final.push_back(vec);
	// 	data_label.push_back(t.back());
	// }

	// for (int i=0;i<10;i++) {
	// 	vector<string> vec;
	// 	for (int j=0;j<10;j++) {
	// 		string str = "a " + to_string(i) + to_string(j);
	// 		vec.push_back(str);
	// 	}
	// 	table.push_back(vec);
	// }
	// // add extra
	// table[0][0] = "a 10";

	decision_tree::DecisionTree tree01(feature_list, train_data_final, data_label);

	cout << tree01.table_data() << endl;

	cout << tree01.table_label() << endl;

	cout << "size of table: " << train_data_final.size() << std::endl;

	cout << tree01.feature_map() << endl;

	cout << tree01.feature_map_inverse() << endl;

	return tree01;

}

void cal_gain_test(decision_tree::DecisionTree& tree)
{
	set<int> index;
	for (int i=0;i<30;i++) {
		index.insert(i);
	}
	cout << "info gain test: " << tree.cal_info_gain(index, 0) << endl;
}

void choose_feature_test(decision_tree::DecisionTree& tree)
{
	set<int> index;
	for (int i=0;i<30;i++) {
		index.insert(i);
	}
	cout << "111" << std::endl;
	cout << "choose feature test: " << tree.choose_feature(index) << endl;
}

void choose_data_test(decision_tree::DecisionTree& tree)
{
	set<int> index;
	for (int i=0;i<30;i++) {
		index.insert(i);
	}
	cout << "choose data test: " << tree.choose_data(index, 0) << endl;
}

void grow_tree_test(decision_tree::DecisionTree& tree)
{

	tree.implement_grow_tree();
}

int main()
{
	decision_tree::DecisionTree tree = constructor_test();
	cout << "new table: " << tree.table_data() << endl;
	cal_gain_test(tree);
	choose_feature_test(tree);
	choose_data_test(tree);
	grow_tree_test(tree);
	cout << tree.tree() << std::endl;
}