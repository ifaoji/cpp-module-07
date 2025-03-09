#pragma once

#ifndef ITER_HPP_
#    define ITER_HPP_

#    include <cstddef>

template <typename T, typename F>
void iter(T *array, size_t array_length, F fn) {
    for (size_t i = 0; i < array_length; i += 1) {
        fn(array[i]);
    }
}

#endif
