#include <iostream>
#include "vector.hpp"
#include <iterator>
int main(void)
{
    ft::vector<const int> my_vector(10, 3);
    ft::vector<int> my_vector2(my_vector.begin(), my_vector.end());
    ft::vector<const int>::iterator it = my_vector.begin();
    ft::vector<const int>::iterator it2 = my_vector.end();
    int i = 0;
    my_vector.front();
    std::cout << my_vector.size() << std::endl;
    while (i < my_vector.size())
    {
        // std::cout << "hello" << std::endl;
        std::cout << my_vector[i] << "    ";
        std::cout << my_vector.at(i) << std::endl;
        i++;
    }
    return (0);
}