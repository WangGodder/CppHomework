//
// Created by godder on 2018/12/16.
//
#include "works.h"
#include "../utils.h"
#include "grade.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <math.h>

namespace report2 {
    using namespace std;
    void work1() {
        string url;
        ifstream stream;
        cout << "input file url";
        cin >> url;
        stream.open(url);
        while (!stream.is_open()) {
            cerr << "file open failure, check your url" << endl;
            cout << "input file url";
            cin >> url;
            stream.open(url);
        }
        vector<double> numVector;
        stringstream sstream;
        double num = 0;
        string integerPart = "";
        string floatPart = "";
        while (!stream.eof()) {
            // 情况缓存区
            sstream.str("");
            stream >> num;
            numVector.push_back(num);
            sstream << num;
            // 由于浮点数相加操作有精度丢失，转为字符串进行相加操作
            string doubleStr = sstream.str();
            sstream.clear();
            int floatIndex = doubleStr.find_first_of('.');
            bool preCarry;
            string ipart = doubleStr.substr(0, floatIndex);
            string fpart = doubleStr.substr(floatIndex + 1, doubleStr.length());
            floatPart = strAdd(floatPart, fpart, preCarry, false, false);
            integerPart = strAdd(integerPart, ipart, preCarry, true, preCarry);
        }
        stream.close();
        if (numVector.empty()) {
            cerr << "file has no num" << endl;
            return;
        }
        long double sum = getFromStr(integerPart, floatPart);
        long double aver = sum / numVector.size();
        cout << "average:" << aver << endl;
        long double sd = 0;
        for (int i = 0; i < numVector.size(); i++) {
            sd += pow(numVector[i] - aver, 2);
        }
        sd = sqrt(sd);
        cout << "standard deviation " <<sd << endl;
    }

    void work2() {
        string str;
        cout << "input:";
        getline(cin, str);
        if (str.length() > 100) {
            cerr << "length > 100" << endl;
            return;
        }
        bool caps = true;
        bool space = false;
        int spaceNum = 0;
        trim(str);
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            if (isChartacter(c)) {
                if (caps != isUpCap(c)) {
                    capTranslate(str[i]);
                }
                caps = false;
            }

            if (c == ' ') {
                if (space) {
                    spaceNum++;
                }
                space = true;
                caps = true;
            }
            else {
                if (space && spaceNum > 1) {
                    str.replace(i - spaceNum + 1, spaceNum - 1, "");
                    i -= (spaceNum - 1);
                }
                spaceNum = 0;
            }
        }
        cout << str << endl;
    }

    void work3() {
        string input;
        cout << "input line:";
        getline(cin, input);
        grade g = grade(input);
        cout << g.toString() << endl;
        cout << "input file url:";
        cin >> input;
        ifstream stream;
        stream.open(input);
        while (!stream.is_open()) {
            cerr << "file open failure, check your url" << endl;
            cout << "input file url";
            cin >> input;
            stream.open(input);
        }
        vector<grade> v = readGrades(stream);
        for (grade g : v) {
            cout<<g.toString()<<endl;
        }
    }

    bool getGradeByInput();
    bool getGradeByFile();
}
