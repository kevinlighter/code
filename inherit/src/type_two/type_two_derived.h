#ifndef SECOND_TYPE_DERIVED_
#define SECOND_TYPE_DERIVED_

#include "src/type_two_base.h"
#include "proto/type_two_config.pb.h"

class TypeTwoDerived : public TypeTwoBase {
public:

    TypeTwoDerived(const common::TypeTwoConfig& config): TypeTwoBase(config) {}

    common::GenericMessage calculate();
};


#endif