#pragma once

#ifndef ARRAY_TPP_
#    define ARRAY_TPP_

#    include "Array.hpp"

template <typename T>
Array<T>::Array() : array_(NULL), size_(0) {
}

template <typename T>
Array<T>::Array(unsigned int length)
    : array_(length == 0 ? NULL : new T[length]), size_(length) {
}

template <typename T>
Array<T>::Array(const Array& other) {
    if (other.size_ == 0) {
        size_  = 0;
        array_ = NULL;

        return;
    }

    array_ = new T[other.size_];
    size_  = other.size_;
    try {
        for (size_t i = 0; i < other.size_; i += 1) {
            array_[i] = other[i];
        }
    } catch (...) {
        delete[] array_;

        // Error needs to bubble up. It should not be handled here.
        throw;
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
    if (this == &rhs) return *this;

    T* tmp_array = new T[rhs.size_];

    try {
        for (size_t i = 0; i < rhs.size_; i += 1) {
            tmp_array[i] = rhs[i];
        }
    } catch (...) {
        delete[] tmp_array;

        // Error needs to bubble up. It should not be handled here.
        throw;
    }

    delete[] array_;
    array_ = tmp_array;
    size_  = rhs.size_;

    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index) throw(std::out_of_range) {
    if (index >= size_) {
        throw std::out_of_range("Index out of bounds");
    }

    return array_[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const throw(std::out_of_range) {
    if (index >= size_) {
        throw std::out_of_range("Index out of bounds");
    }

    return array_[index];
}

template <typename T>
Array<T>::~Array() {
    delete[] array_;
}

template <typename T>
size_t Array<T>::size() const {
    return size_;
}

#endif
