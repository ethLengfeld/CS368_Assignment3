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
    
    string filePath = "unformatted_grades.txt";

    SUMGRADES::readGradeFile(filePath,numberOfStudents,numberOfAssignments,studentNames,studentScores);
    
    SUMGRADES::formatCaseOfNames(studentNames);

    SUMGRADES::computeTotalAndPercent(studentScores, total, percent);


    /*
98861 BOB BARKER 8 5 9
23091 bill kerman 6 9 10
48701 bob kerman 10 10 10
55335 jebediah kerman 5 6 5
25825 val kerman 10 7 5
70558 STEVE ROGERS 10 5 9
89390 Luke Skywalker 5 7 10
83937 TONY STARK 8 10 10
18150 Darth Vader 10 6 6
*/
    int studentId = 70558;

    for(auto j = 0; j < *numberOfAssignments; ++j) {
         cout << "Assignment " << (j+1) << " for " << studentNames[studentId].firstName << ": " << studentScores[studentId][j] << endl;
    }
    return 0;
}