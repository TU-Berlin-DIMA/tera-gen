// auto-generatad C++ setter chain for `rec`

#ifndef BASERECSETTERCHAIN_H_
#define BASERECSETTERCHAIN_H_

#include "config/GeneratorConfig.h"
#include "runtime/setter/SetterChain.h"
#include "record/Rec.h"
#include "record/RecUtil.h"
#include "runtime/provider/value/ConstValueProvider.h"
#include "runtime/provider/value/ElementWiseValueProvider.h"
#include "runtime/provider/value/RandomValueProvider.h"
#include "runtime/setter/FieldSetter.h"

namespace TeraGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization (base class)
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

/**
 * SetterChain specialization for User.
 */
class BaseRecSetterChain : public Myriad::SetterChain<Rec>
{
public:

    // runtime component typedefs
    // runtime components for setter `set_key`
    typedef Myriad::RandomValueProvider< Char, Rec, Myriad::UniformPrFunction<Char>, 0 > ValueProvider01Type;
    typedef Myriad::ConstValueProvider< I16u, Rec > ValueProvider02Type;
    typedef Myriad::ElementWiseValueProvider< Char, Rec, 10 > ValueProvider03Type;
    typedef Myriad::FieldSetter< Rec, Myriad::RecordTraits<Rec>::KEY, ValueProvider03Type > SetKeyType;
    // runtime components for setter `set_value`
    typedef Myriad::RandomValueProvider< Char, Rec, Myriad::UniformPrFunction<Char>, 0 > ValueProvider04Type;
    typedef Myriad::ConstValueProvider< I16u, Rec > ValueProvider05Type;
    typedef Myriad::ElementWiseValueProvider< Char, Rec, 8 > ValueProvider06Type;
    typedef Myriad::FieldSetter< Rec, Myriad::RecordTraits<Rec>::VALUE, ValueProvider06Type > SetValueType;

    BaseRecSetterChain(Myriad::BaseSetterChain::OperationMode& opMode, Myriad::RandomStream& random, Myriad::GeneratorConfig& config) :
        Myriad::SetterChain<Rec>(opMode, random),
        _sequenceCardinality(config.cardinality("rec")),
        _valueProvider01(config.function< Myriad::UniformPrFunction<Char> >("Pr[rec.key.char]")),
        _valueProvider02(10),
        _valueProvider03(_valueProvider01, _valueProvider02),
        _setKey(_valueProvider03),
        _valueProvider04(config.function< Myriad::UniformPrFunction<Char> >("Pr[rec.value.char]")),
        _valueProvider05(8),
        _valueProvider06(_valueProvider04, _valueProvider05),
        _setValue(_valueProvider06),
        _logger(Logger::get("rec.setter.chain"))
    {
    }

    virtual ~BaseRecSetterChain()
    {
    }

    /**
     * Applies the setter chain to the given record instance.
     */
    void operator()(AutoPtr<Rec> recordPtr) const
    {
        ensurePosition(recordPtr->genID());

        BaseRecSetterChain* me = const_cast<BaseRecSetterChain*>(this);

        // apply setter chain
        me->_setKey(recordPtr, me->_random);
        me->_setValue(recordPtr, me->_random);
    }

    /**
     * Predicate filter function.
     */
    virtual Myriad::Interval<I64u> filter(const Myriad::EqualityPredicate<Rec>& predicate)
    {
        Myriad::Interval<I64u> result(0, _sequenceCardinality);

        // apply inverse setter chain
        _setKey.filterRange(predicate, result);
        _setValue.filterRange(predicate, result);

        return result;
    }

protected:

    // cardinality
    I64u _sequenceCardinality;

    // runtime components for setter `set_key`
    ValueProvider01Type _valueProvider01;
    ValueProvider02Type _valueProvider02;
    ValueProvider03Type _valueProvider03;
    SetKeyType _setKey;

    // runtime components for setter `set_value`
    ValueProvider04Type _valueProvider04;
    ValueProvider05Type _valueProvider05;
    ValueProvider06Type _valueProvider06;
    SetValueType _setValue;

    // Logger instance.
    Logger& _logger;
};

} // namespace TeraGen

#endif /* BASERECSETTERCHAIN_H_ */
