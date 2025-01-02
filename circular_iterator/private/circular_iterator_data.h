#pragma once

#include <iterator>

template<class citerator_t>
class circular_iterator_data
{
public:
    circular_iterator_data(const citerator_t& inB, const citerator_t& inE, const citerator_t& inI) : mB(inB), mE(inE), mI(inI), mIsEnd(inI == inE ? 1 : 0)
    {

    }

protected:
    bool isEnd() const
    {
        return mIsEnd != 0;
    }

protected:
    citerator_t mB;
    citerator_t mE;
    citerator_t mI;
    int mIsEnd;

};
