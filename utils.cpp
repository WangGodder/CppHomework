//
// Created by godder on 2018/12/16.
//

#include "utils.h"
#include <deque>
#include <sstream>
#include <iostream>

using namespace std;

void trim(string &str) {
    unsigned int i = 0, j = str.length() - 1;
    for (; i < str.length(); i++) {
        if (str[i] != ' ') {
            break;
        }
    }
    for (; j > i; j--) {
        if (str[j] != ' ') {
            break;
        }
    }
    str = str.substr(i, j + 1);
}

vector<string> split(string &str, char c) {
    vector<string> result;
    unsigned int i = 0, j = 0;
    for (; i < str.length(); i++) {
        if (str[i] == c) {
            if (i > j) {
                result.push_back(str.substr(j, i));
            }
            j = i;
        }
    }
    result.push_back(str.substr(j, i));
    return result;
}

string strAdd(string &str1, string &str2, bool &isCarry, bool outSize, bool preCarry) {
    deque<char> opQueue;
    bool carry = false;
    int add = 0;
    int i = str2.length() - 1, j = str1.length() - 1;
    for (; i >= 0 && j >= 0; i--, j--) {
        char c1 = str1[j], c2 = str2[i];
        if (preCarry) {
            c1 = static_cast<char>(str1[j] + 1);
            preCarry = false;
        }
        if (carry) {
            c1 = static_cast<char>(str1[j] + 1);
        }
        carry = false;
        add = c1 + c2 - '0' * 2;
        if (add >= 10) {
            carry = true;
            add %= 10;
        }
        char newChar = static_cast<char>(add + '0');
        opQueue.push_front(newChar);
    }
    for (; j >= 0; j--) {
        char c1 = str1[j];
        if (carry) {
            c1 = static_cast<char>(str1[j] + 1);
        }
        carry = false;
        add = c1 - '0';
        if (add >= 10) {
            carry = true;
            add %= 10;
        }
        char newChar = static_cast<char>(add + '0');
        opQueue.push_front(newChar);
    }
    for (; i >= 0; i--) {
        char c2 = str2[i];
        if (carry) {
            c2 = static_cast<char>(str2[i] + 1);
        }
        carry = false;
        add = c2 - '0';
        if (add >= 10) {
            carry = true;
            add %= 10;
        }
        char newChar = static_cast<char>(add + '0');
        opQueue.push_front(newChar);
    }
    if (outSize && carry) {
        opQueue.push_front('1');
        carry = false;
    }
    isCarry = carry;
    int size = opQueue.size();
    stringstream sstream;
    for (char c : opQueue) {
        sstream << c;
    }
    string newString = sstream.str();
    return newString;
}


long double getFromStr(string &integerPart, string &floatPart) {
    string str = integerPart + "." + floatPart;
    long double result = stold(str);
    return result;
}

bool isUpCap(char &c) {
    int cap = c - 'A';
    return cap >= 0 && cap <= 26;
}

bool isLowCap(char &c) {
    int cap = c - 'a';
    return cap >= 0 && cap <= 26;
}

bool isChartacter(char &c) {
    return isUpCap(c) || isLowCap(c);
}

bool isNumber(char &c) {
    int num = c - '0';
    return num >= 0 && num < 10;
}

void capTranslate(char &c) {
    int cap = c - 'a';
    if (cap >= 0 && cap <= 26) {
        c = static_cast<char>('A' + cap);
    }
    else {
        cap = c - 'A';
        if (cap >= 0 && cap <= 26) {
            c = static_cast<char>('a' + cap);
        }
        else {
            cerr << "can not translate this char" << endl;
            return;
        }
    }
}

void readNumbers(string &str, int argsNum, ...) {
    va_list args;
    _crt_va_start(args, argsNum);
    stringstream sstream;

    for (char c : str) {
        if (isChartacter(c)) {

        }
    }
    sstream.str(str);

}