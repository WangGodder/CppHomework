//
// Created by godder on 2018/12/16.
//

#include "args_run.h"
#include "reprot1/works.h"
#include "report2/works.h"
#include <iostream>
#include <string>
using namespace std;

static const string helpDoc = "if you want to run test, please use order: [report number] [question number]\n"
                              "such as \"run_homework 1 1\" to run homework report 1 and question 1";
static const string missArg = "miss arguments";
static const string wrongArg = "error arguments";

void args_run(int argc, char ** argv) {
    if (argc <= 1) {
        cout<<"miss parameter. you can use order: \"run_homework -h\" to get help"<<endl;
        return;
    }
    if (argv[1][0] == '-') {
        switch (argv[1][1]) {
            case 'h':        cout<<helpDoc<<endl; break;
            default: cout<<wrongArg<<endl;
        }
        return;
    } else {
        switch (argv[1][0]) {
            case '1':
                if (argc < 3) {
                    cout<<missArg<<endl;
                    return;
                }
                using namespace report1;
                switch (argv[2][0]) {
                    case '1': report1::work1();
                        break;
                    case '2': report1::work2();
                        break;
                    case '3': report1::work3();
                        break;
                    default:cout<<"report 1 only has 3 questions."<<endl;
                }
                return;
            case '2':
                if (argc < 3) {
                    cout<<missArg<<endl;
                    return;
                }
                using namespace report2;
                switch (argv[2][0]) {
                    case '1': report2::work1();
                        break;
                    case '2': report2::work2();
                        break;
//                    case '3': report2::work3();
//                        break;
                    default:cout<<"report 1 only has 3 questions."<<endl;
                }
                return;
            default:cout<<wrongArg<<endl;
        }
    }
}


