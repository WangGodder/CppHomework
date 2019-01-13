cmake_minimum_required(VERSION 3.13)
project(CppTest)

set(CMAKE_CXX_STANDARD 11)

add_executable(CppTest main.cpp utils.cpp utils.h reprot1/works.h reprot1/works.cpp report2/works.h report2/works.cpp args_run.cpp args_run.h report2/grade.cpp report2/grade.h report3/Pairs.cpp report3/Pairs.h report3/TestPairs.cpp report3/TestPairs.h report3/Employee.cpp report3/Employee.h report3/SalariedEmployee.cpp report3/SalariedEmployee.h report3/Administrator.cpp report3/Administrator.h report3/TestAdministrator.cpp report3/TestAdministrator.h report3/ArrayFirstIndex.cpp report3/ArrayFirstIndex.h report3/TestArrayFirstIndex.cpp report3/TestArrayFirstIndex.h report3/TestAll.cpp report3/TestAll.h )