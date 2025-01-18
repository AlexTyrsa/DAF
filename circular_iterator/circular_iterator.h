#pragma once

#include "private/circular_iterator_impl.h"
#include "private/circular_iterator_type.h"

template<class citerator_t>
class circular_iterator : public circular_iterator_type<citerator_t, circular_iterator<citerator_t>>,
                          public circular_iterator_impl<circular_iterator_type<citerator_t, circular_iterator<citerator_t>>, typename std::iterator_traits<citerator_t>::iterator_category>
{
public:
    using value_type        = typename circular_iterator_type<citerator_t, circular_iterator<citerator_t>>::value_type;
    using difference_type   = typename circular_iterator_type<citerator_t, circular_iterator<citerator_t>>::difference_type;
    using iterator_type     = typename circular_iterator_type<citerator_t, circular_iterator<citerator_t>>::iterator_type;
    using reference         = typename circular_iterator_type<citerator_t, circular_iterator<citerator_t>>::reference;
    using pointer           = typename circular_iterator_type<citerator_t, circular_iterator<citerator_t>>::pointer;
    using iterator_category = typename circular_iterator_impl<circular_iterator_type<citerator_t, circular_iterator<citerator_t>>, typename std::iterator_traits<citerator_t>::iterator_category>::iterator_category;

public:
    circular_iterator<citerator_t>(const iterator_type& inBegin, const iterator_type& inEnd) : circular_iterator_impl<circular_iterator_type<citerator_t, circular_iterator<citerator_t>>, std::random_access_iterator_tag>(inBegin, inEnd, inBegin)
    {

    }

    circular_iterator<citerator_t>(const iterator_type& inEnd) : circular_iterator<citerator_t>(inEnd, inEnd)
    {

    }

    circular_iterator<citerator_t>(const circular_iterator<citerator_t>& inCI) : circular_iterator_impl<circular_iterator_type<citerator_t, circular_iterator<citerator_t>>, std::random_access_iterator_tag>(inCI.mB, inCI.mE, inCI.mI)
    {

    }

    circular_iterator<citerator_t>() : circular_iterator<citerator_t>(iterator_type())
    {

    }

    circular_iterator<citerator_t>& operator=(const circular_iterator<citerator_t>& inCI)
    {
        this->mB = inCI.mB;
        this->mE = inCI.mE;
        this->mI = inCI.mI;

        return *this;
    }

    bool operator==(const circular_iterator<citerator_t>& inCI)
    {
        return (this->isEnd() == inCI.isEnd()) || (this->mI == inCI.mI);
    }

    bool operator!=(const circular_iterator<citerator_t>& inCI)
    {
        return !(*this == inCI);
    }

    reference operator*() const
    {
        return *this->mI;
    }

    pointer operator->() const
    {
        return this->mI.operator->();
    }

    difference_type circle() const
    {
        return this->mIsEnd;
    }

};
