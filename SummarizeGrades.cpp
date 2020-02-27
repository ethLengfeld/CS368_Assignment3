////////////////////////////////////////////////////////////////////////////////
// Main File: SummarizeGrades.cpp, demo.cpp
// This File: SummarizeGrades.cpp
// Other Files: 	 SummarizeGrades.h / SummarizeGrades.cpp / demo.cpp / Makefile / README.md
// Semester:         CS 368 Spring 2020
//
// Author:           Ethan Lengfeld
// Email:            elengfeld@wisc.edu
// CS Login:         lengfeld
//
//
// Online sources:   
//
////////////////////////////////////////////////////////////////////////////////

/**
 * This class will implement the functions defined in the 
 * SummarizeGrades.h. 
*/
#include "SummarizeGrades.h"


void readGradeFile(const string inputFilepath, int *numberOfStudents, int *numberOfAssignments, map<int,Name> &studentNames, map<int,vector<int>> &studentScores) {
ifstream inputFile("unformatted_grades.txt");

    if(inputFile.good()) {

        string currLine;

        // get number of students
       // getline(inputFile, currLine, ' ');
       // getline(inputFile, currLine, ' ');
        //*numberOfStudents = stoi(currLine);

        // TODO delete
        //cout << *numberOfStudents << endl;

       // getline(inputFile, currLine, ' ');
        //getline(inputFile, currLine, ' ');
        // *numberOfAssignments = stoi(currLine);

        while (!inputFile.eof()){
            getline(inputFile, currLine); 
            cout << currLine << endl;
        }



        inputFile.close();

    } else {
        cout << "bad file! bad!" << endl;
    }
}



void formatCaseOfNames(map<int,Name> &names) {

}



void computeTotalAndPercent(map<int,vector<int>> &scores, map<int,int> &total, map<int,float> &percent) {

}



void writeFormattedGrades(const string outputFilepath, map<int,Name> &names, map<int,int> &total, map<int,float> &percent) {

}