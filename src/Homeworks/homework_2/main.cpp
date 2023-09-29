#include <iostream>
#include "vector_h.h"

int main() {
    vector_ <int, 3> c;
    std::cin >> c;
    std::cout << c << std::endl;

    int a[5] = {1, 3, 4, 6, 7};
    vector_<int, 5> t(a);

    std::cout << "t : "<< t << std::endl;

    int a1[5] = {5, 2, 3 , 0, 3};
    vector_<int, 5> q (a1);
    std::cout << "q : " << q << std::endl;

    t += q;
    std::cout << "t+=q : " << t << std::endl;

    int a2[5] = {5, 2, 3 , 0, 3};
    vector_<int, 5> s (a2);
    std::cout << "s : "<< s << std::endl;
    q = t + s;
    std::cout << "t + s : " << q << std::endl;

    std::cout << "euclidean norm of t+s: " << q.eun() << std::endl;
}
