#ifndef SECOND_TYPE_BASE_
#define SECOND_TYPE_BASE_

#include "base.h"
#include "proto/type_two_config.pb.h"

class TypeTwoBase : public CalculatorBase {
public:

    TypeTwoBase(const common::TypeTwoConfig& config): config_(config) {}

    virtual common::GenericMessage calculate();


private:
    common::TypeTwoConfig config_;
};


#endif