// auto-generatad C++ file for `rec`

#ifndef BASEREC_H_
#define BASEREC_H_

#include "record/Record.h"
#include "record/RecMeta.h"

using namespace Myriad;

namespace TeraGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// forward declarations
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Rec;
class RecConfig;
class RecGenerator;
class RecSetterChain;

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// base record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseRec: public Record
{
public:

    BaseRec(const RecMeta& meta) : 
        _key(10),
        _value(8),
        _meta(meta)
    {
    }

    const RecMeta& meta() const
    {
        return _meta;
    }

    void key(const vector<Char>& v);
    const vector<Char>& key() const;

    void value(const vector<Char>& v);
    const vector<Char>& value() const;

protected:

    // fields
    vector<Char> _key;
    vector<Char> _value;

    // meta
    const RecMeta& _meta;
};

inline void BaseRec::key(const vector<Char>& v)
{
    _key = v;
}

inline const vector<Char>& BaseRec::key() const
{
    return _key;
}

inline void BaseRec::value(const vector<Char>& v)
{
    _value = v;
}

inline const vector<Char>& BaseRec::value() const
{
    return _value;
}

} // namespace TeraGen

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record traits specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
struct RecordTraits<TeraGen::Rec>
{
    typedef TeraGen::RecMeta MetaType;
    typedef TeraGen::RecGenerator GeneratorType;
    typedef TeraGen::RecSetterChain SetterChainType;
    typedef RecordFactory<TeraGen::Rec> FactoryType;

    enum Field { UNKNOWN, GEN_ID, KEY, VALUE };
};

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void AbstractOutputCollector<TeraGen::BaseRec>::serialize(std::stringstream& outputBuffer, const TeraGen::BaseRec& record)
{
    write(outputBuffer, record.key(), false);
    write(outputBuffer, record.value(), false);
    outputBuffer << '\n';
}

} // namespace Myriad

#endif /* BASEREC_H_ */
