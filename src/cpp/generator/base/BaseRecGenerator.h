// auto-generatad C++ generator for `rec`

#ifndef BASERECGENERATOR_H_
#define BASERECGENERATOR_H_

#include "generator/RandomSequenceGenerator.h"
#include "runtime/setter/RecSetterChain.h"

namespace TeraGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// AbstractSequenceGenerator specialization (base class)
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseRecGenerator: public Myriad::RandomSequenceGenerator<Rec>
{
public:

    BaseRecGenerator(const string& name, Myriad::GeneratorConfig& config, NotificationCenter& notificationCenter) :
        Myriad::RandomSequenceGenerator<Rec>(name, config, notificationCenter)
    {
    }

    void prepare(Stage stage, const Myriad::GeneratorPool& pool)
    {
        // call generator implementation
        Myriad::RandomSequenceGenerator<Rec>::prepare(stage, pool);

        if (stage.name() == name())
        {
            registerTask(new Myriad::PartitionedSequenceIteratorTask< Rec > (*this, _config));
        }
    }

    RecSetterChain setterChain(Myriad::BaseSetterChain::OperationMode opMode, Myriad::RandomStream& random)
    {
        return RecSetterChain(opMode, random, _config);
    }
};

} // namespace TeraGen

#endif /* BASERECGENERATOR_H_ */
