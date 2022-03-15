#ifndef LEXICOGRAPHICAL_COMPARE
#define LEXICOGRAPHICAL_COMPARE

#include <iostream>
#include <string>

// Checks if the first range [first1, last1) is lexicographically less than the second range [first2, last2)
namespace ft{
    template <class InputIt1, class InputIt2>
        bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
        {
            while (first1 != last1)
            {
                if (first2 == last2 || *first2 < *first1)
                    return false;
                else if (*first1 < *first2)
                    return true;
                ++first1; 
                ++first2;
            }
            return (first2 != last2);
        }
//comp 함수 첫번쨰 인자가 더 작을 경우 true를 리턴한다.
    template <class InputIt1, class InputIt2, class Compare>
        bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
        {
            while (first1!=last1)
            {
                if (first2==last2 || comp(*first2, *first1))
                    return false;
                else if (comp(*first1, *first2))
                    return true;
                ++first1;
                ++first2;
            }
            return (first2!=last2);
        }
}
#endif