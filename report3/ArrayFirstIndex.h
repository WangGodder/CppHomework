//
// Created by godder on 2018/12/28.
//

#ifndef CPPTEST_ARRAYFILL_H
#define CPPTEST_ARRAYFILL_H


#include <iostream>
using namespace std;

/**
 * use to get the first index of value in array, if value is not include in this array, then return -1
 * @tparam T the type of array and value
 * @param array array to check
 * @param length the length of array
 * @param value the value want to search
 * @return index of value in array
 */
template <typename T>
int arrayFirstIndex(T* array, int length, T &value) {
    if (length <= 0) {
        return -1;
    }
    int index = 0;
    for (; index < length; index++) {
        try {
            if (array[index] == value) {
                return index;
            }
        } catch (int e) {
            std::cerr << "template type don't define operator ==" << std::endl;
            return -2;
        }
    }
    return -1;
}

#endif //CPPTEST_ARRAYFILL_H
