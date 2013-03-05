// auto-generatad C++ file for `record`

#ifndef BASERECORDUTIL_H_
#define BASERECORDUTIL_H_

#include "record/Record.h"

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record field inspection structures
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

// key
template<>
struct RecordFieldTraits<RecordTraits<TeraGen::Record>::KEY, TeraGen::Record>
{
    typedef vector<Char> FieldType;
    typedef MethodTraits<TeraGen::Record, FieldType>::RefSetter FieldSetterType;
    typedef MethodTraits<TeraGen::Record, FieldType>::RefGetter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&TeraGen::Record::key);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&TeraGen::Record::key);
    }
};

// value
template<>
struct RecordFieldTraits<RecordTraits<TeraGen::Record>::VALUE, TeraGen::Record>
{
    typedef vector<Char> FieldType;
    typedef MethodTraits<TeraGen::Record, FieldType>::RefSetter FieldSetterType;
    typedef MethodTraits<TeraGen::Record, FieldType>::RefGetter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&TeraGen::Record::value);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&TeraGen::Record::value);
    }
};

} // namespace Myriad

#endif /* BASERECORDUTIL_H_ */
