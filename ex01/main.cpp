#include <iostream>

#include "iter.hpp"

void test_const_ref(const int &elem) {
    std::cout << elem << " ";
}

void test_ref(int &elem) {
    std::cout << elem << " ";
}

void test_const_cpy(const int elem) {
    std::cout << elem << " ";
}

void test_cpy(int elem) {
    std::cout << elem << " ";
}

template <typename T>
void print_element(T e) {
    std::cout << e << " ";
}

template <typename T>
void multiply_element(T &e) {
    e *= e;
}

void PrintHeader(const std::string &header) {
    std::cout << "----" << std::endl
              << header << std::endl
              << "----" << std::endl;
}

int main() {
    {
        PrintHeader("Const Array");
        const int array[]      = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        size_t    array_length = sizeof(array) / sizeof(array[0]);

        std::cout << "Const REF: ";
        iter(array, array_length, test_const_ref);
        std::cout << std::endl << "Const CPY: ";
        iter(array, array_length, test_const_cpy);
        std::cout << std::endl << "Just  CPY: ";
        iter(array, array_length, test_cpy);
        std::cout << std::endl << "Templ Const REF: ";
        iter(array, array_length, print_element<const int &>);
        std::cout << std::endl << "Templ Just  CPY: ";
        iter(array, array_length, print_element<int>);
        std::cout << std::endl;
    }

    {
        PrintHeader("Normal Array");
        int    array[]      = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        size_t array_length = sizeof(array) / sizeof(array[0]);

        std::cout << "Const REF: ";
        iter(array, array_length, test_const_ref);
        std::cout << std::endl << "Just  REF: ";
        iter(array, array_length, test_ref);
        std::cout << std::endl << "Const CPY: ";
        iter(array, array_length, test_const_cpy);
        std::cout << std::endl << "Just  CPY: ";
        iter(array, array_length, test_cpy);
        std::cout << std::endl << "Templ Const REF: ";
        iter(array, array_length, print_element<const int &>);
        std::cout << std::endl << "Templ Just  REF: ";
        iter(array, array_length, print_element<int &>);
        std::cout << std::endl << "Templ Just  CPY: ";
        iter(array, array_length, print_element<int>);
        std::cout << std::endl;
    }

    {
        PrintHeader("Modify Array");
        int    array[]      = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        size_t array_length = sizeof(array) / sizeof(array[0]);

        iter(array, array_length, print_element<const int>);
        std::cout << std::endl;
        iter(array, array_length, multiply_element<int>);
        iter(array, array_length, print_element<const int>);
        std::cout << std::endl;
    }
}
