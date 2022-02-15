#ifndef FIRST_TYPE_BASE_
#define FIRST_TYPE_BASE_

#include <iostream>
#include "src/base.h"
#include "proto/type_one_config.pb.h"

class TypeOneBase : public CalculatorBase {
public:

    TypeOneBase(const common::TypeOneConfig& config): config_(config) {}

    virtual common::GenericMessage calculate();

private:
    common::TypeOneConfig config_;
};


#endif