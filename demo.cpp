////////////////////////////////////////////////////////////////////////////////
// Main File: SummarizeGrades.cpp, demo.cpp
// This File: demo.cpp
// Other Files: 	 SummarizeGrades.h / SummarizeGrades.cpp / demo.cpp / Makefile / README.md
// Semester:         CS 368 Spring 2020
//
// Author:           Ethan Lengfeld
// Email:            elengfeld@wisc.edu
// CS Login:         lengfeld
//
//
// Online sources:   http://www.cplusplus.com/doc/tutorial/files/
//                   http://www.cplusplus.com/reference/fstream/ifstream/
//                   
//
////////////////////////////////////////////////////////////////////////////////

/**
 * This class will demo the functions defined in the SummarizedGrades Library
*/
#include "SummarizeGrades.h"

int* numberOfStudents = new int;
int* numberOfAssignments = new int;
map<int,Name> studentNames;
map<int,vector<int>> studentScores;
map<int,int> total;
map<int,float> percent;

int main() {
    
    string inPath = "unformatted_grades.txt";
    string outPath = "test_grades.txt";

    SUMGRADES::readGradeFile(inPath,numberOfStudents,numberOfAssignments,studentNames,studentScores);
    
    SUMGRADES::formatCaseOfNames(studentNames);

    SUMGRADES::computeTotalAndPercent(studentScores, total, percent);

    SUMGRADES::writeFormattedGrades(outPath,studentNames, total, percent);

    return 0;
}