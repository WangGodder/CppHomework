//
// Created by godder on 2018/12/16.
//

#ifndef GRADE_H
#define GRADE_H

#define A 90
#define B 80
//#define C 75
#define D 60

#define ARGUMENT_ERROR_EXCEPTION -1

#include <string>
#include <vector>
#include <sstream>
#include "../utils.h"
using namespace std;

class grade {
private:
    int firstQuizz, secondQuizz, midExam, finalExam;
    double mean = -1;
    char rank = '\0';
public:
    grade(int firstQuizz, int secondQuizz, int midExam, int finalExam);

    grade(string line);

    grade(istream& in);

    int getFirstQuizz() const;

    void setFirstQuizz(int firstQuizz);

    int getSecondQuizz() const;

    void setSecondQuizz(int secondQuizz);

    int getMidExam() const;

    void setMidExam(int midExam);

    int getFinalExam() const;

    void setFinalExam(int finalExam);

    double getMean();

    char getRank();

    string toString();

};

vector<grade> readGrades(string lines);

vector<grade> readGrades(istream& in);


#endif //GRADE_H
