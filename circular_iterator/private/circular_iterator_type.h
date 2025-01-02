#pragma once

#include <iterator>

template<class citerator_t, class cthis_t>
class circular_iterator_type
{
public:
    typedef citerator_t                                                     iterator_type;
    typedef typename std::iterator_traits<iterator_type>::value_type        value_type;
    typedef typename std::iterator_traits<iterator_type>::difference_type   difference_type;
    typedef typename std::iterator_traits<iterator_type>::pointer           pointer;
    typedef typename std::iterator_traits<iterator_type>::reference         reference;
    typedef typename std::iterator_traits<iterator_type>::iterator_category iterator_category;

    typedef cthis_t                                                         this_type;

};
