#include <iostream>
#include <string>
#include "binary_tree.h"

using namespace std;
using namespace common::binary_tree;

string serialize(Node* root) {
    if (root==NULL)
        return "NULL";
    
    string add_s = std::to_string(root->val);
    return add_s + "," + serialize(root->left) + "," + serialize(root->right);
}

Node* deserialize(string data) {

	if (data.empty()) {
		return NULL;
	}

	Node* newnode = new Node();
	string delimiter = ",";
	size_t pos = data.find(delimiter);

	if (pos != std::string::npos) {
		
		string token = data.substr(0, pos);

		/// create new node 
		
		if (token != "NULL") {
			
			newnode->val = std::stoi(token);
			std::cout << "da: " << data << std::endl;
			std::cout << "ok: " << token << std::endl;
			data.erase(0, pos + delimiter.length());
			newnode->left = deserialize(data);
			newnode->right = deserialize(data);
			
		} else {
			std::cout << "da: " << data << std::endl;
			std::cout << "ok: " << token << std::endl;
			data.erase(0, pos + delimiter.length());
		}
		

		
		

		
	}

	return newnode;
	// string delimiter = ",";
	// string token;




	// while ((pos = data.find(delimiter)) != std::string::npos) {
	//     token = data.substr(0, pos);

	//     std::cout << token << std::endl;
	//     data.erase(0, pos + delimiter.length());
	// }
}

int main() {

	Node* node = buildOneTwoThree();

	std::cout << serialize(node) << std::endl;


	print(deserialize(serialize(node)));


}