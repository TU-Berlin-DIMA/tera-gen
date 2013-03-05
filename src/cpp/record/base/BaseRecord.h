// auto-generatad C++ file for `record`

#ifndef BASERECORD_H_
#define BASERECORD_H_

#include "record/AbstractRecord.h"
#include "record/RecordMeta.h"

namespace TeraGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// forward declarations
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Record;
class RecordConfig;
class RecordGenerator;
class RecordSetterChain;

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// base record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class BaseRecord: public Myriad::AbstractRecord
{
public:

    BaseRecord(const RecordMeta& meta) : 
        _key(10),
        _value(8),
        _meta(meta)
    {
    }

    const RecordMeta& meta() const
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
    const RecordMeta& _meta;
};

inline void BaseRecord::key(const vector<Char>& v)
{
    _key = v;
    _key.resize(v.size());
}

inline const vector<Char>& BaseRecord::key() const
{
    return _key;
}

inline void BaseRecord::value(const vector<Char>& v)
{
    _value = v;
    _value.resize(v.size());
}

inline const vector<Char>& BaseRecord::value() const
{
    return _value;
}

} // namespace TeraGen

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record traits specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
struct RecordTraits<TeraGen::Record>
{
    typedef TeraGen::RecordMeta MetaType;
    typedef TeraGen::RecordGenerator GeneratorType;
    typedef TeraGen::RecordSetterChain SetterChainType;
    typedef RecordFactory<TeraGen::Record> FactoryType;

    enum Field { UNKNOWN, GEN_ID, KEY, VALUE };
};

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void AbstractOutputCollector<TeraGen::BaseRecord>::serialize(std::ostream& out, const TeraGen::BaseRecord& record)
{
}

} // namespace Myriad

#endif /* BASERECORD_H_ */
