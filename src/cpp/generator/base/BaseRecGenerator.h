// auto-generatad C++ generator for `rec`

#ifndef BASERECGENERATOR_H_
#define BASERECGENERATOR_H_

#include "generator/RandomSequenceGenerator.h"
#include "runtime/setter/RecSetterChain.h"

using namespace Myriad;

namespace TeraGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization (base class)
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseRecGenerator: public RandomSequenceGenerator<Rec>
{
public:

    BaseRecGenerator(const string& name, GeneratorConfig& config, NotificationCenter& notificationCenter) :
        RandomSequenceGenerator<Rec>(name, config, notificationCenter)
    {
    }

    void prepare(Stage stage, const GeneratorPool& pool)
    {
        // call generator implementation
        RandomSequenceGenerator<Rec>::prepare(stage, pool);

        if (stage.name() == name())
        {
            registerTask(new PartitionedSequenceIteratorTask< Rec > (*this, _config));
        }
    }

    RecSetterChain setterChain(BaseSetterChain::OperationMode opMode, RandomStream& random)
    {
        return RecSetterChain(opMode, random, _config);
    }
};

} // namespace TeraGen

#endif /* BASERECGENERATOR_H_ */
