#include <google/protobuf/util/json_util.h>
#include "src/create_proto.h"
#include <iostream>
#include "messages/simple_example.pb.h"

bool proto_to_json(const google::protobuf::Message& message, std::string& json) {
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    options.always_print_primitive_fields = true;
    options.preserve_proto_field_names = true;
    return google::protobuf::util::MessageToJsonString(message, &json, options).ok();
}

bool json_to_proto(const std::string& json, google::protobuf::Message& message) {
    return google::protobuf::util::JsonStringToMessage(json, &message).ok();
}

int main() {


    simple_example::Letter letter = createLetter();
    std::string json_str;
    if (!proto_to_json(letter, json_str)) {
        std::cout << "converting to json failed!" << std::endl;
        return 1;
    }

    std::cout << "json string: " << std::endl;
    std::cout << json_str << std::endl;

    simple_example::Letter empty_letter;
    if (!json_to_proto(json_str, empty_letter)) {
        std::cout << "converting json back to proto" << std::endl;
        return 1;
    }

    showLetter(empty_letter);
}