// auto-generatad base generator config C++ file

#ifndef BASEGENERATORCONFIG_H_
#define BASEGENERATORCONFIG_H_

#include "config/AbstractGeneratorConfig.h"

namespace Myriad {

class BaseGeneratorConfig: public AbstractGeneratorConfig
{
public:

    BaseGeneratorConfig(GeneratorPool& generatorPool) : AbstractGeneratorConfig(generatorPool)
    {
    }

protected:

    virtual void configurePartitioning()
    {
        // TODO: this piece of auto-generating code / Config API needs to be rewritten

        // setup linear scale estimator for record
        setString("partitioning.record.base-cardinality", toString<I64u>(parameter<I64u>("record.sequence.base_cardinality")));
        computeLinearScalePartitioning("record");
    }

    virtual void configureFunctions()
    {
        // register prototype functions
        function(new Myriad::UniformPrFunction<Char>("Pr[record.key.char]", static_cast<Char>(32), static_cast<Char>(127)));
        function(new Myriad::UniformPrFunction<Char>("Pr[record.value.char]", static_cast<Char>(65), static_cast<Char>(91)));
    }

    virtual void configureSets()
    {
        // bind string sets to config members with the bindStringSet method
    }
};

} // namespace Myriad

#endif /* BASEGENERATORCONFIG_H_ */
