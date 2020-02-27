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
// Online sources:   CS368-STLIntro slide
//                   http://www.cplusplus.com/reference/string/string/
//                   http://www.asciitable.com/
//                   https://userweb.cs.txstate.edu/~br02/cs1428/SupportFiles/Programming/TypeCasting.htm
//
////////////////////////////////////////////////////////////////////////////////

/**
 * This class will implement the functions defined in the 
 * SummarizeGrades.h. 
*/
#include "SummarizeGrades.h"


/*
 * TODO comment private function
 * 
 * 
 */
string formatName(string name) {
    bool first = true;
    string formattedName;

    for(char &currChar : name) {
        if(first) {
            if (currChar >= 97) {
                currChar -= 32; 
            }
            first = false;
        } else {
            if (currChar < 97 ) {
                currChar += 32;
            }
        }
        formattedName += currChar;
    }
    return name;
}

void readGradeFile(const string inputFilepath, int *numberOfStudents, int *numberOfAssignments, map<int,Name> &studentNames, map<int,vector<int>> &studentScores) {
    
    ifstream inputFile(inputFilepath);

    if(inputFile.good()) {

        string currLine;

        // skip word number_of_students
        inputFile >> currLine;
        inputFile >> *numberOfStudents;

        // skip word number_of_assignments
        inputFile >> currLine;
        inputFile >> *numberOfAssignments;

        // skip \n
        getline(inputFile,currLine);
        // skip line 'student_number first_name last_name ...'
        getline(inputFile,currLine);

        int studentId, currScore;
        string firstName, lastName;
        Name newStudent;
        for(auto i = 0; i < *numberOfStudents; ++i) {

            inputFile >> studentId;

            inputFile >> firstName;

            inputFile >> lastName;

            newStudent = {firstName,lastName};

            // add new student to map
            studentNames[studentId] = newStudent;

            // get student scores
            vector<int> scores;
            for(auto j = 0; j < *numberOfAssignments; ++j) {
                inputFile >> currScore;
                scores.push_back(currScore);

                studentScores[studentId] = scores;
                // TODO delete this
                // cout << "Assignment " << (j+1) << " for " << studentNames[studentId].firstName << ": " << studentScores[studentId][j] << endl;
            }
        }

        inputFile.close();
    } else {
        cout << "bad file! bad!" << endl;
    }
}



void formatCaseOfNames(map<int,Name> &names) {
    for(auto &currStudent : names) {
        currStudent.second.firstName = formatName(currStudent.second.firstName);
        currStudent.second.lastName = formatName(currStudent.second.lastName);
    }
}



void computeTotalAndPercent(map<int,vector<int>> &scores, map<int,int> &total, map<int,float> &percent) {
    int studentId;
    for(auto &currStudent : scores) {
        int totalScore = 0;
        float stuPercent = 0;
        studentId = currStudent.first;

        for(auto &i : currStudent.second) {
            totalScore += i;
        }

        stuPercent = ( static_cast<float>(totalScore) / static_cast<float>(currStudent.second.size() * 10) ) * 100;
        cout << "student " << studentId << " had total score  = " << totalScore << " and percent = " << stuPercent << endl;
        total[studentId] = totalScore;
        percent[studentId] = stuPercent;
    }
}



void writeFormattedGrades(const string outputFilepath, map<int,Name> &names, map<int,int> &total, map<int,float> &percent) {

}



