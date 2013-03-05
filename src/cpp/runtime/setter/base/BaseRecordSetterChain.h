// auto-generatad C++ setter chain for `record`

#ifndef BASERECORDSETTERCHAIN_H_
#define BASERECORDSETTERCHAIN_H_

#include "config/GeneratorConfig.h"
#include "runtime/setter/SetterChain.h"
#include "record/Record.h"
#include "record/RecordUtil.h"
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
class BaseRecordSetterChain : public Myriad::SetterChain<Record>
{
public:

    // runtime component typedefs
    // runtime components for setter `set_key`
    typedef Myriad::RandomValueProvider< Char, Record, Myriad::UniformPrFunction<Char>, 0 > ValueProvider01Type;
    typedef Myriad::ConstValueProvider< I16u, Record > ValueProvider02Type;
    typedef Myriad::ElementWiseValueProvider< Char, Record, 10 > ValueProvider03Type;
    typedef Myriad::FieldSetter< Record, Myriad::RecordTraits<Record>::KEY, ValueProvider03Type > SetKeyType;
    // runtime components for setter `set_value`
    typedef Myriad::RandomValueProvider< Char, Record, Myriad::UniformPrFunction<Char>, 0 > ValueProvider04Type;
    typedef Myriad::ConstValueProvider< I16u, Record > ValueProvider05Type;
    typedef Myriad::ElementWiseValueProvider< Char, Record, 8 > ValueProvider06Type;
    typedef Myriad::FieldSetter< Record, Myriad::RecordTraits<Record>::VALUE, ValueProvider06Type > SetValueType;

    BaseRecordSetterChain(Myriad::BaseSetterChain::OperationMode& opMode, Myriad::RandomStream& random, Myriad::GeneratorConfig& config) :
        Myriad::SetterChain<Record>(opMode, random),
        _sequenceCardinality(config.cardinality("record")),
        _valueProvider01(config.function< Myriad::UniformPrFunction<Char> >("Pr[record.key.char]")),
        _valueProvider02(10),
        _valueProvider03(_valueProvider01, _valueProvider02),
        _setKey(_valueProvider03),
        _valueProvider04(config.function< Myriad::UniformPrFunction<Char> >("Pr[record.value.char]")),
        _valueProvider05(8),
        _valueProvider06(_valueProvider04, _valueProvider05),
        _setValue(_valueProvider06),
        _logger(Logger::get("record.setter.chain"))
    {
    }

    virtual ~BaseRecordSetterChain()
    {
    }

    /**
     * Applies the setter chain to the given record instance.
     */
    void operator()(AutoPtr<Record> recordPtr) const
    {
        ensurePosition(recordPtr->genID());

        BaseRecordSetterChain* me = const_cast<BaseRecordSetterChain*>(this);

        // apply setter chain
        me->_setKey(recordPtr, me->_random);
        me->_setValue(recordPtr, me->_random);
    }

    /**
     * Predicate filter function.
     */
    virtual Myriad::Interval<I64u> filter(const Myriad::EqualityPredicate<Record>& predicate)
    {
        Myriad::Interval<I64u> result(0, _sequenceCardinality);

        // explicitly mimic inverse setter logic for gen_id
        if (predicate.bound(Myriad::RecordTraits<Record>::GEN_ID))
        {
            const AutoPtr<Record>& valueHolder = predicate.valueHolder();
            result.intersect(Myriad::Interval<I64u>(valueHolder->genID(), valueHolder->genID()+1));
        }

        // apply inverse setter chain, setters are applied in the same order
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

#endif /* BASERECORDSETTERCHAIN_H_ */
