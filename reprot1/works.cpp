//
// Created by godder on 2018/12/16.
//
#include "works.h"
#include "../utils.h"
#include <iostream>
#include <sstream>

namespace report1 {
    using namespace std;

    void work1() {
        double height, weight;
        int age;
        cout << "input height, weight, age: ";
        while (!(cin >> height >> weight >> age)) {
            cout << "error input, input height, weight, age: ";
            cin.sync();
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

        // 清空缓缓区
        cin.ignore(INT_MAX, '\n');
        while (height <= 0 || weight <= 0 || age <= 0) {
            cout << "error input, input should be positive. reinput height, weight and age: ";
            while (!(cin >> height >> weight >> age)) {
                cout << "error input, input height, weight, age: ";
                cin.sync();
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            // 清空缓冲区
            cin.ignore(INT_MAX, '\n');
        }

        double hat = (weight / height) * 2.9;
        double jacket = (height * weight) / 288 + (1 / 8.0) * ((age - 30) / 10);
        double waist = (weight / 5.7) + 0.1 * ((age - 28) / 2);

        char operate;
        cout << "input char 'h' or 'H' output hat size, 'j' or 'J' output jacket size, 'w' or 'W' output waist, q to exit: ";
        cin >> operate;
        // 清空缓冲区
        cin.ignore(INT_MAX, '\n');
        while (operate != 'q') {
            switch (operate)
            {
                case 'h': cout << "hat : " << hat << endl; break;
                case 'H': cout << "hat : " << hat << endl; break;
                case 'j': cout << "jacket: " << jacket << endl; break;
                case 'J': cout << "jacket: " << jacket << endl; break;
                case 'w': cout << "waist: " << waist << endl; break;
                case 'W': cout << "waist: " << waist << endl; break;
                default:
                    cout << "error input" << endl;
                    break;
            }
            cout << "input char 'h' or 'H' output hat size, 'j' or 'J' output jacket size, 'w' or 'W' output waist, q to exit: ";
            cin >> operate;
            // 清空缓冲区
            cin.ignore(INT_MAX, '\n');
        }
    }

    /**
     * 从输入的字符串中提取时间
     * @param time 输入包含时间的字符串
     * @return 返回提取出的时间字符串 hh:MM PM or hh:MM AM
     */
    string transform(string &time) {
        int hour = 0, minute = 0;
        string::iterator ptr = time.begin();
        bool isMinute = false;
        while (ptr != time.end()) {
            if (*ptr == ':') {
                isMinute = true;
                ptr++;
                continue;
            }
            if (isMinute) {
                minute *= 10;
                minute += *ptr++ - '0';
            }
            else {
                hour *= 10;
                hour += *ptr++ - '0';
            }
        }
        // 利用cpp自带转换工具
        stringstream sstream;
        bool isPm = hour / 12;
        string newHour, newMinute;
        sstream << (hour % 12);
        newHour = sstream.str();
        // 清空缓存区
        sstream.str("");
        sstream << (minute % 60);
        newMinute = sstream.str();
        string newTime = isPm ? newHour + ":" + newMinute + "PM" : newHour + ":" + newMinute + "AM";
        return newTime;
    }

    void work2() {
        string input;
        cout << "input 24-hour time input q to quit: ";
        cin >> input;
        cin.ignore(INT_MAX, '\n');
        while (input.length() > 1 || input[0] != 'q') {
            int beginIndex = -1, endIndex = -1, hour = 0, minue = 0;
            int i = 0;
            for (; i < input.length(); i++) {
                char c = input[i];
                if (c >= '0' && c <= '9') {
                    beginIndex = i;
                    break;
                }
            }
            if (beginIndex == -1) {
                cout << "error input, reinput: ";
                cin >> input;
                // 清空缓冲区
                cin.ignore(INT_MAX, '\n');
                continue;
            }
            for (; i < input.length(); i++) {
                if (input[i] == ':') {
                    continue;
                }
                if (input[i] > '9' || input[i] < '0')
                    break;
            }
            endIndex = i;
            string time = input.substr(beginIndex, endIndex - beginIndex);

            cout << transform(time) << endl;
            cout << "input 24-hour time input q to quit: ";
            cin >> input;
            cin.ignore(INT_MAX, '\n');
        }
    }

    /**
     * 删除字符串中重复字符，并返回新字符串长度
     * @param chars 输入
     * @param length 输入长度
     * @return 新字符串的长度
     */
    int delete_repeats(char* chars, int length) {
        int low[26], up[26], *repeatIndexs = (int*)malloc(sizeof(int) * 25);
        for (int i = 0; i < 26; i++) {
            low[i] = 0;
            up[i] = 0;
        }
        int repeatNum = 0, i = 0;
        for (int index = -1; i < length; i++) {
            bool isRepeat = false;
            if (chars[i] - 'A' < 26) {
                index = chars[i] - 'A';
                isRepeat = up[index];
                up[index] = 1;
            }
            else {
                index = chars[i] - 'a';
                isRepeat = low[index];
                low[index] = 1;
            }
            if (isRepeat) {
                *(repeatIndexs+repeatNum) = i;
                repeatNum++;
            }

        }
        char* newchar = (char*)malloc(sizeof(char) * (length - repeatNum));
        for (int j = 0, k = 0; j < length - repeatNum; j++, k++) {
            if (k == *repeatIndexs && k < length) {
                repeatIndexs++;
                j--;
            }
            else {
                *(newchar + j) = *(chars + k);
            }
        }
        for (int j = 0; j < length - repeatNum; j++) {
            *(chars + j) = *(newchar + j);
        }

        return length - repeatNum;
    }

    void work3() {
        char input[20];
        cout<<"input a string to test:";
        cin>>input;
        int newLength = delete_repeats(input, 20);
        for (int i = 0; i < newLength; i++)
            cout << input[i];
        cout<<endl;
    }

}

