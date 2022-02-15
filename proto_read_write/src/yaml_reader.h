#include "yaml-cpp-yaml-cpp-0.7.0/include/yaml-cpp/yaml.h"
#include <iostream>


using namespace std;

void readYaml() {
    YAML::Node config = YAML::LoadFile("/code/learn/code/proto_read_write/data/config.yaml");

    cout << "name:" << config["name"].as<string>() << endl;
    cout << "sex:" << config["sex"].as<string>() << endl;
    cout << "age:" << config["age"].as<int>() << endl;
}