#pragma once

#ifndef ARRAY_HPP_
#    define ARRAY_HPP_

#    include <cstddef>
#    include <stdexcept>

template <typename T>
class Array {
   public:
    Array();
    Array(unsigned int length);
    Array(const Array &other);

    Array   &operator=(const Array &rhs);
    T       &operator[](size_t index) throw(std::out_of_range);
    const T &operator[](size_t index) const throw(std::out_of_range);

    ~Array();

    size_t size() const;

   private:
    T     *array_;
    size_t size_;
};

#    include "Array.tpp"

#endif
