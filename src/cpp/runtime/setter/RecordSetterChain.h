#ifndef RECORDSETTERCHAIN_H_
#define RECORDSETTERCHAIN_H_

#include "runtime/setter/base/BaseRecordSetterChain.h"

namespace TeraGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class RecordSetterChain : public BaseRecordSetterChain
{
public:

    RecordSetterChain(Myriad::BaseSetterChain::OperationMode& opMode, Myriad::RandomStream& random, Myriad::GeneratorConfig& config) :
        BaseRecordSetterChain(opMode, random, config)
    {
    }

    virtual ~RecordSetterChain()
    {
    }
};

} // namespace TeraGen

#endif /* BASERECORDGENERATOR_H_ */
