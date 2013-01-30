#ifndef RECSETTERCHAIN_H_
#define RECSETTERCHAIN_H_

#include "runtime/setter/base/BaseRecSetterChain.h"

using namespace Myriad;

namespace TeraGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class RecSetterChain : public BaseRecSetterChain
{
public:

    RecSetterChain(OperationMode& opMode, RandomStream& random, GeneratorConfig& config) :
        BaseRecSetterChain(opMode, random, config)
    {
    }

    virtual ~RecSetterChain()
    {
    }
};

} // namespace TeraGen

#endif /* BASERECGENERATOR_H_ */
