#pragma once

#include "circular_iterator_data.h"

#include <iterator>
#include <cassert>

template <class ccircular_iterator_t, class citerator_category_t>
class circular_iterator_impl;

template <class ccircular_iterator_t>
class circular_iterator_impl<ccircular_iterator_t, std::forward_iterator_tag> : public circular_iterator_data<typename ccircular_iterator_t::iterator_type>
{
public:
    using this_type     = typename ccircular_iterator_t::this_type;
    using iterator_type = typename ccircular_iterator_t::iterator_type;

    typedef std::forward_iterator_tag iterator_category;

public:
    circular_iterator_impl<ccircular_iterator_t, std::forward_iterator_tag>(const iterator_type& inB, const iterator_type& inE, const iterator_type& inI) : circular_iterator_data<iterator_type>(inB, inE, inI)
    {

    }

    this_type& operator++()
    {
        ++this->mI;

        if(this->mI == this->mE)
        {
            ++this->mIsEnd;
            this->mI = this->mB;
        }

        return static_cast<this_type&>(*this);
    }

    this_type operator++(int)
    {
        this_type ret(static_cast<this_type&>(*this));

        ++(*this);

        return ret;
    }

};

template <class ccircular_iterator_t>
class circular_iterator_impl<ccircular_iterator_t, std::bidirectional_iterator_tag> : public circular_iterator_impl<ccircular_iterator_t, std::forward_iterator_tag>
{
public:
    using this_type     = typename ccircular_iterator_t::this_type;
    using iterator_type = typename ccircular_iterator_t::iterator_type;

    typedef std::bidirectional_iterator_tag iterator_category;

public:
    circular_iterator_impl<ccircular_iterator_t, std::bidirectional_iterator_tag>(const iterator_type& inB, const iterator_type& inE, const iterator_type& inI) : circular_iterator_impl<ccircular_iterator_t, std::forward_iterator_tag>(inB, inE, inI)
    {

    }

    this_type& operator--()
    {
        if(this->mI == this->mB)
        {
            if(this->mIsEnd != 0)
                --this->mIsEnd;

            this->mI = this->mE;
        }

        --this->mI;

        return static_cast<this_type&>(*this);
    }

    this_type operator--(int)
    {
        this_type ret(static_cast<this_type&>(*this));

        --(*this);

        return ret;
    }

};

template <class ccircular_iterator_t>
class circular_iterator_impl<ccircular_iterator_t, std::random_access_iterator_tag> : public circular_iterator_impl<ccircular_iterator_t, std::bidirectional_iterator_tag>
{
public:
    using this_type     = typename ccircular_iterator_t::this_type;
    using iterator_type = typename ccircular_iterator_t::iterator_type;
    using difference_type = typename ccircular_iterator_t::difference_type;

    typedef std::bidirectional_iterator_tag iterator_category;

public:
    circular_iterator_impl<ccircular_iterator_t, std::random_access_iterator_tag>(const iterator_type& inB, const iterator_type& inE, const iterator_type& inI) : circular_iterator_impl<ccircular_iterator_t, std::bidirectional_iterator_tag>(inB, inE, inI)
    {

    }

};
