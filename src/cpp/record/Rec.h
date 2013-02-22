#ifndef REC_H_
#define REC_H_

#include "record/base/BaseRec.h"

using namespace Myriad;

namespace TeraGen {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record type
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

class Rec: public BaseRec
{
public:

    Rec(const RecMeta& meta)
        : BaseRec(meta)
    {
    }

};

} // namespace TeraGen

namespace Myriad {

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// record serialize method specialization
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~

template<>
inline void AbstractOutputCollector<TeraGen::Rec>::serialize(std::ostream& out, const TeraGen::Rec& record)
{
    // 10 bytes key
    const vector<Char>& key = record.key();
    for(size_t i = 0; i < key.size(); i++)
    {
        out << key[i];
    }

    // 10 bytes rowid
    out << NumberFormatter::format(record.genID(), 10);

    // 10 bytes filler
    const vector<Char>& value = record.value();
    for(size_t i = 0; i < value.size(); i++)
    {
        for (size_t j = 0; j < ((i < value.size()-1) ? 10 : 9); j++)
        {
            out << value[i];
        }
    }
    out << "\n";
}

} // namespace Myriad

#endif /* REC_H_ */
