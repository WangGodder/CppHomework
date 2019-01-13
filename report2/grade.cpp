//
// Created by godder on 2018/12/16.
//

#include "grade.h"
#include <iostream>

int grade::getFirstQuizz() const {
    return firstQuizz;
}

void grade::setFirstQuizz(int firstQuizz) {
    grade::firstQuizz = firstQuizz;
}

int grade::getSecondQuizz() const {
    return secondQuizz;
}

void grade::setSecondQuizz(int secondQuizz) {
    grade::secondQuizz = secondQuizz;
}

int grade::getMidExam() const {
    return midExam;
}

void grade::setMidExam(int midExam) {
    grade::midExam = midExam;
}

int grade::getFinalExam() const {
    return finalExam;
}

void grade::setFinalExam(int finalExam) {
    grade::finalExam = finalExam;
}

double grade::getMean() {
    if (mean < 0) {
        this->mean = (this->firstQuizz + this->secondQuizz) * 5 * 0.25 + this->midExam * 0.25 + this->finalExam * 0.5;
    }
    return mean;
}

char grade::getRank() {
    if (rank == '\0' && mean >= 0) {
        if (mean > A) {
            this->rank = 'A';
        }
        else if (mean > B) {
            this->rank = 'B';
        }
        else if (mean > 70) {
            this->rank = 'C';
        }
        else if (mean > D) {
            this->rank = 'D';
        }
        else {
            this->rank = 'F';
        }
    }
    return rank;
}

string grade::toString() {
    stringstream sstream;
    sstream << this->firstQuizz << " " << secondQuizz << " " << midExam << " " << finalExam << " " << getMean() << " "<< getRank();
    string str = sstream.str();
    return str;
}

grade::grade(int firstQuizz, int secondQuizz, int midExam, int finalExam) : firstQuizz(firstQuizz),
                                                                            secondQuizz(secondQuizz), midExam(midExam),
                                                                            finalExam(finalExam) {}

grade::grade(string line) {
    stringstream sstream;
    sstream.str(line);
    if (sstream.eof()) {
        cerr << "line should have 4 int split by space"<<endl;
        throw ARGUMENT_ERROR_EXCEPTION;
    }
    if (!(sstream >> firstQuizz)) {
        cerr << "line should have 4 int split by space, but there is not integer"<<endl;
        throw ARGUMENT_ERROR_EXCEPTION;
    }
    if (!(sstream >> secondQuizz)) {
        cerr << "line should have 4 int split by space, but there is not integer"<<endl;
        throw ARGUMENT_ERROR_EXCEPTION;
    }
    if (!(sstream >> midExam)) {
        cerr << "line should have 4 int split by space, but there is not integer"<<endl;
        throw ARGUMENT_ERROR_EXCEPTION;
    }
    if (!(sstream >> finalExam)) {
        cerr << "line should have 4 int split by space, but there is not integer"<<endl;
        throw ARGUMENT_ERROR_EXCEPTION;
    }
}

grade::grade(istream& in) {
    if (!(in >> firstQuizz)) {
        cerr << "line should have 4 int split by space, but there is not integer"<<endl;
        throw ARGUMENT_ERROR_EXCEPTION;
    }
    if (!(in >> secondQuizz)) {
        cerr << "line should have 4 int split by space, but there is not integer"<<endl;
        throw ARGUMENT_ERROR_EXCEPTION;
    }
    if (!(in >> midExam)) {
        cerr << "line should have 4 int split by space, but there is not integer"<<endl;
        throw ARGUMENT_ERROR_EXCEPTION;
    }
    if (!(in >> finalExam)) {
        cerr << "line should have 4 int split by space, but there is not integer"<<endl;
        throw ARGUMENT_ERROR_EXCEPTION;
    }
    in.ignore(INT_MAX, '\n');
//    in.clear();
//    in.sync();
}

vector<grade> readGrades(string lines) {
    stringstream sstream;
    vector<grade> vector1;
    sstream.str(lines);
    while (!sstream.eof()) {
        grade g = grade(sstream);
        vector1.push_back(g);
    }
    return vector1;
}

vector<grade> readGrades(istream& in) {
    vector<grade> vector1;
    while (!in.eof()) {
        grade g = grade(in);
        vector1.push_back(g);
    }
    return vector1;
}



