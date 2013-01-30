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

        // setup linear scale estimator for rec
        setString("partitioning.rec.base-cardinality", toString<I64u>(parameter<I64u>("rec.sequence.base_cardinality")));
        computeLinearScalePartitioning("rec");
    }

    virtual void configureFunctions()
    {
        // register prototype functions
        function(new UniformPrFunction<Char>("Pr[rec.key.char]", (Char)32, (Char)127));
        function(new UniformPrFunction<Char>("Pr[rec.value.char]", 65, 91));
    }

    virtual void configureSets()
    {
        // bind string sets to config members with the bindStringSet method
    }
};

} // namespace Myriad

#endif /* BASEGENERATORCONFIG_H_ */
