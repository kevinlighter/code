
#include "src/create_proto.h"

void ParseForLetter(simple_example::Letter& letter) {
    letter.set_name("Kevin");
    simple_example::Record* r1 = letter.add_records();
    r1->set_message("kevin's short message 1");
    r1->set_unique_id(1);
    r1->set_record_type(simple_example::RecordType::SHORT_MESSAGE);

    simple_example::Record* r2 = letter.add_records();
    r2->set_message("kevin's long message 2");
    r2->set_unique_id(2);
    r2->set_record_type(simple_example::RecordType::LONG_MESSAGE);

    simple_example::Record* r3 = letter.add_records();
    r3->set_message("kevin's short message 3");
    r3->set_unique_id(3);
    r3->set_record_type(simple_example::RecordType::SHORT_MESSAGE);
}

void showLetter(simple_example::Letter& letter) {
    // show hint
    std::cout << "Letter is to ";
    simple_example::Letter::MetadataCase metadata = letter.metadata_case();
    switch (metadata){
        case simple_example::Letter::MetadataCase::kName:
            std::cout << "name: " << letter.name() << std::endl;
            break;
        case simple_example::Letter::MetadataCase::kAddress:
            std::cout << "address: " << letter.address() << std::endl;
            break;
        case simple_example::Letter::MetadataCase::kPhoneNumber:
            std::cout << "phone number: " << letter.phone_number() << std::endl;
            break;
        default:
            std::cout << "NOT SET" << std::endl;
    }

    std::cout << "Letter has record messages: ";
    for (int i=0;i < letter.records_size();i++)
    {
        const simple_example::Record& record = letter.records(i);
        switch (record.record_type()) {
            case simple_example::RecordType::LONG_MESSAGE:
                std::cout << " (long message)";
                break;
            case simple_example::RecordType::SHORT_MESSAGE:
                std::cout << " (short message)";
                break;
            default:
                std::cout << " msg type not set!";
                break;
        }
        std::cout << record.message() << std::endl;
    }
}

simple_example::Letter createLetter() {
    simple_example::Letter letter;
    ParseForLetter(letter);
    // showLetter(letter);
    return letter;
}

// int main() {
//     simple_example::Letter letter = createLetter();
// }