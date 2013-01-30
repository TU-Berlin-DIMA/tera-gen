// auto-generatad C++ setter chain for `rec`

#ifndef BASERECSETTERCHAIN_H_
#define BASERECSETTERCHAIN_H_

#include "runtime/setter/SetterChain.h"
#include "record/Rec.h"
#include "record/RecUtil.h"
#include "runtime/provider/value/ElementWiseValueProvider.h"
#include "runtime/provider/value/RandomValueProvider.h"
#include "runtime/setter/FieldSetter.h"

using namespace Myriad;

namespace TeraGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// SetterChain specialization (base class)
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

/**
 * SetterChain specialization for User.
 */
class BaseRecSetterChain : public SetterChain<Rec>
{
public:

    // runtime component typedefs
    // runtime components for setter `set_key`
    typedef RandomValueProvider< Char, Rec, UniformPrFunction<Char>, 0 > ValueProvider01Type;
    typedef ElementWiseValueProvider< Char, Rec, 10 > ValueProvider02Type;
    typedef FieldSetter< Rec, RecordTraits<Rec>::KEY, ValueProvider02Type > SetKeyType;
    // runtime components for setter `set_value`
    typedef RandomValueProvider< Char, Rec, UniformPrFunction<Char>, 0 > ValueProvider03Type;
    typedef ElementWiseValueProvider< Char, Rec, 8 > ValueProvider04Type;
    typedef FieldSetter< Rec, RecordTraits<Rec>::VALUE, ValueProvider04Type > SetValueType;

    BaseRecSetterChain(OperationMode& opMode, RandomStream& random, GeneratorConfig& config) :
        SetterChain<Rec>(opMode, random),
        _sequenceCardinality(config.cardinality("rec")),
        _valueProvider01(config.function< UniformPrFunction<Char> >("Pr[rec.key.char]")),
        _valueProvider02(_valueProvider01),
        _setKey(_valueProvider02),
        _valueProvider03(config.function< UniformPrFunction<Char> >("Pr[rec.value.char]")),
        _valueProvider04(_valueProvider03),
        _setValue(_valueProvider04),
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
    virtual Interval<I64u> filter(const EqualityPredicate<Rec>& predicate)
    {
        Interval<I64u> result(0, _sequenceCardinality);

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
    SetKeyType _setKey;

    // runtime components for setter `set_value`
    ValueProvider03Type _valueProvider03;
    ValueProvider04Type _valueProvider04;
    SetValueType _setValue;

    // Logger instance.
    Logger& _logger;
};

} // namespace TeraGen

#endif /* BASERECSETTERCHAIN_H_ */
