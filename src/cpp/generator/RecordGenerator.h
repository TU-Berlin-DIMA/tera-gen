#ifndef RECORDGENERATOR_H_
#define RECORDGENERATOR_H_

#include "generator/base/BaseRecordGenerator.h"

namespace TeraGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class RecordGenerator: public BaseRecordGenerator
{
public:

    typedef Myriad::RecordTraits<Record>::SetterChainType SetterChainType;

    RecordGenerator(const string& name, Myriad::GeneratorConfig& config, NotificationCenter& notificationCenter) :
        BaseRecordGenerator(name, config, notificationCenter)
    {
    }
};

} // namespace TeraGen

#endif /* BASERECORDGENERATOR_H_ */
