#include <cstdlib>
#include <iostream>

#include "Array.hpp"

class Foo {
   public:
    Foo() {
        std::cout << "Default constructor" << std::endl;
        ok_ = 1;
    }
    Foo(int ok) {
        std::cout << "PARAM constructor" << std::endl;
        ok_ = ok;
    }

    Foo(const Foo &other) {
        std::cout << "COPY" << std::endl;
        ok_ = other.ok_;
    }

    ~Foo() { std::cout << "Deconstructo" << std::endl; }

    int ok_;
};

std::ostream &operator<<(std::ostream &os, const Foo &foo) {
    os << foo.ok_;

    return os;
}

template <typename T>
T *crea(int size) {
    return new T[size];
}

int main() {
    // Array<Foo> foo(10);
    // Array<Foo> bar(10);

    // for (int i = 0; i < 10; i++) {
    //     foo[i] = Foo(i);
    //     std::cout << foo[i] << std::endl;
    // }

    // bar = foo;

    // for (int i = 0; i < 10; i++) {
    //     std::cout << bar[i] << std::endl;
    // }
    //
    int *foo = new int[0];

    std::cout << *foo << std::endl;
}
