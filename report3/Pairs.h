//
// Created by godder on 2018/12/27.
//

#ifndef CPPTEST_PAIRS_H
#define CPPTEST_PAIRS_H

#include <iostream>
using namespace std;
/**
 * Pairs class use to store two element with type T
 * @tparam T the type want to store
 */
template <typename T>
class Pairs {
private:
    T first;
    T second;

public:
    T getFirst() const;

    void setFirst(T first);

    T getSecond() const;

    void setSecond(T second);

    Pairs();

    Pairs(T first, T second);

    inline T operator [] (int index) const;

    friend ostream &operator<<(std::ostream &out, Pairs<T> &obj) {
        out << obj.first << " " << obj.second;
        return out;
    }

    friend istream &operator>>(std::istream &in, Pairs<T> &obj) {
        in >> obj.first;
        if (!in) {
            cerr<<"wrong input at index of 0"<<endl;
            throw 0;
        }
        in >> obj.second;
        if (!in) {
            cerr<<"wrong input at index of 1"<<endl;
            throw 1;
        }
        return in;
    }

    bool operator==(const Pairs &rhs) const;

    bool operator!=(const Pairs &rhs) const;

    bool operator<(const Pairs &rhs) const;

    bool operator>(const Pairs &rhs) const;

    bool operator<=(const Pairs &rhs) const;

    bool operator>=(const Pairs &rhs) const;
};

template<typename T>
T Pairs<T>::operator[](int index) const {
    if (index < 0 || index > 1) {
        throw index;
    }
    if (index == 0) {
        return this->getFirst();
    } else {
        return this->getSecond();
    }
}

template<typename T>
Pairs<T>::Pairs() {}

template<typename T>
Pairs<T>::Pairs(T first, T second):first(first), second(second) {}

template<typename T>
T Pairs<T>::getFirst() const {
    return first;
}

template<typename T>
void Pairs<T>::setFirst(T first) {
    Pairs::first = first;
}

template<typename T>
T Pairs<T>::getSecond() const {
    return second;
}

template<typename T>
void Pairs<T>::setSecond(T second) {
    Pairs::second = second;
}

template<typename T>
bool Pairs<T>::operator==(const Pairs &rhs) const {
    return first == rhs.first &&
           second == rhs.second;
}

template<typename T>
bool Pairs<T>::operator!=(const Pairs &rhs) const {
    return !(rhs == *this);
}

template<typename T>
bool Pairs<T>::operator<(const Pairs &rhs) const {
    if (first < rhs.first)
        return true;
    if (rhs.first < first)
        return false;
    return second < rhs.second;
}

template<typename T>
bool Pairs<T>::operator>(const Pairs &rhs) const {
    return rhs < *this;
}

template<typename T>
bool Pairs<T>::operator<=(const Pairs &rhs) const {
    return !(rhs < *this);
}

template<typename T>
bool Pairs<T>::operator>=(const Pairs &rhs) const {
    return !(*this < rhs);
}


#endif //CPPTEST_PAIRS_H
