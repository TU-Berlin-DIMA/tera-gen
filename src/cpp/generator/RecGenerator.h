#ifndef RECGENERATOR_H_
#define RECGENERATOR_H_

#include "generator/base/BaseRecGenerator.h"

using namespace Myriad;

namespace TeraGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class RecGenerator: public BaseRecGenerator
{
public:

    typedef RecordTraits<Rec>::SetterChainType SetterChainType;

    RecGenerator(const string& name, GeneratorConfig& config, NotificationCenter& notificationCenter) :
        BaseRecGenerator(name, config, notificationCenter)
    {
    }
};

} // namespace TeraGen

#endif /* BASERECGENERATOR_H_ */
