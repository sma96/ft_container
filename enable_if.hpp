
#ifndef ENABLE_IF
#define ENABLE_IF

#include <iostream>
#include <memory>
#include <iterator>
#include <type_traits>
#include <utility>

// template <typename T, T N>
// struct integral_constant{
// //     static constexpr T value = N;
// // };
// // typedef integral_constant<bool, true> true_type;
// // typedef integral_constant<bool, false> false_type;
namespace ft{
    // enable_if , is_integral
    template <bool B, class T = void>
    struct enable_if
    {};

    template <class T>
    struct enable_if<true, T>{
        typedef T type;
    };

    // template <bool B, class T = void>
    // using enable_if_t = typename enable_if<B, T>::type;

    template <typename T>
    struct is_integral{
        static const bool value = false;
    };

    template <>
    struct is_integral<int>{
        static const bool value = true;
    };
// bool, char, char8_t, char16_t, char32_t, wchar_t, short, int, long, long long 모두 true_type;
    template <>
    struct is_integral<bool>{
        static const bool value = true;
    };

    template <>
    struct is_integral<char>{
        static const bool value = true;
    };

    template <>
    struct is_integral<wchar_t>{
        static const bool value = true;
    };

    template <>
    struct is_integral<char16_t>{
        static const bool value = true;
    };

    template <>
    struct is_integral<char32_t>{
        static const bool value = true;
    };

    template <>
    struct is_integral<short>{
        static const bool value = true;
    };

    template <>
    struct is_integral<long>{
        static const bool value = true;
    };

    template <>
    struct is_integral<long long>{
        static const bool value = true;
    };
    // std::pair
}
#endif

// template <typename Integer, ft::enable_if_t<std::is_integral<Integer>::value, int> = true>
// void printz(Integer a)
// {
//     std::cout << "complete!!!!!" << std::endl;
// }
// int main(void)
// {
//     if (ft::is_integral<char>::value)
//     printz(3);
//     std::cout << "hello!" << std::endl;
//     return (0);
// }

// template <class T, class allocator = std::allocator<T>>
// class vector{
//     private:
//         typedef std::random_access_iterator_tag iterator_category;
//         typedef T value_type;
// };
// template <class iterator>
// struct iterator_traits{