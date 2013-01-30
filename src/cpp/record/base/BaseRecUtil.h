// auto-generatad C++ file for `rec`

#ifndef BASERECUTIL_H_
#define BASERECUTIL_H_

#include "record/Rec.h"

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record field inspection structures
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

// key
template<>
struct RecordFieldTraits<RecordTraits<TeraGen::Rec>::KEY, TeraGen::Rec>
{
    typedef vector<Char> FieldType;
    typedef MethodTraits<TeraGen::Rec, FieldType>::Setter FieldSetterType;
    typedef MethodTraits<TeraGen::Rec, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&TeraGen::Rec::key);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&TeraGen::Rec::key);
    }
};

// value
template<>
struct RecordFieldTraits<RecordTraits<TeraGen::Rec>::VALUE, TeraGen::Rec>
{
    typedef vector<Char> FieldType;
    typedef MethodTraits<TeraGen::Rec, FieldType>::Setter FieldSetterType;
    typedef MethodTraits<TeraGen::Rec, FieldType>::Getter FieldGetterType;

    static inline FieldSetterType setter()
    {
        return static_cast<FieldSetterType>(&TeraGen::Rec::value);
    }

    static inline FieldGetterType getter()
    {
        return static_cast<FieldGetterType>(&TeraGen::Rec::value);
    }
};

} // namespace Myriad

#endif /* BASERECUTIL_H_ */
