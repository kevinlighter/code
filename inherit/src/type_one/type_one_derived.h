#ifndef FIRST_TYPE_DERIVED_
#define FIRST_TYPE_DERIVED_

#include "src/type_one_base.h"
#include "proto/type_one_config.pb.h"

class TypeOneDerived : public TypeOneBase {
public:

    TypeOneDerived(const common::TypeOneConfig& config): TypeOneBase(config) {}

    common::GenericMessage calculate();
};


#endif