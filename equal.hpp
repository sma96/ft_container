#ifndef EQUAL_HPP
#define EQUAL_HPP

#include <iostream>
#include <string>


namespace ft{
    template <class InputIt1, class InputIt2>
        bool equal(InputIt1 first, InputIt1 last, InputIt2 first2)
        {
            while (first != last)
            {
                if (*first != *first2)
                    return (false);
                first++;
                first2++;
            }
            return (true);
        }
}
#endif