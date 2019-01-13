//
// Created by godder on 2018/12/16.
//

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <datetimeapi.h>
using namespace std;

/**
 * trim str as String.trim() in java
 * @param string the str to trim
 */
void trim(string &string);

/**
 * split str by split c
 * @param string  the splited str
 * @param c     the splited character
 * @return vector of str
 */
vector<string> split(string &string, char c);

/**
 * whether c is up case
 * @param c the character to just
 * @return ture if up case,   other character and low case will be false;
 */
bool isUpCap(char &c);

/**
 * whether c is low case
 * @param c the character to just
 * @return  ture if low case.   other character and up case will be false
 */
bool isLowCap(char &c);

/**
 * whether c is a character
 * @param c the character to just
 * @return true if c is character
 */
bool isChartacter(char &c);

/**
 * add two str as integer
 * @param str1 the str to add
 * @param str2 the other str to add
 * @param isCarry if true, the operator will allow carry
 * @param outSize if true, allow the size of result bigger than the longest str
 * @param preCarry if true, the last number will add 1
 * @return the result by add with string type
 */
string strAdd(string &str1, string &str2, bool &isCarry, bool outSize = true, bool preCarry = false);

/**
 * get long double type from str
 * @param integerPart the integer part of a float
 * @param floatPart the float part of a float
 * @return the long double type float
 */
long double getFromStr(string &integerPart, string &floatPart);

/**
 * translate up to low and low to up case
 * @param c the character to translate
 */
void capTranslate(char &c);

#endif //UTILS_H
