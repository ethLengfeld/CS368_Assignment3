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
//                   http://www.cplusplus.com/reference/ios/fixed/
//
////////////////////////////////////////////////////////////////////////////////

/**
 * This class will implement the functions defined in the 
 * SummarizeGrades.h. 
*/
#include "SummarizeGrades.h"


/*
 * This private helper function will
 * take a string and properly case it
 * First letter will be capital and following
 * are lower case
 * 
 * @param string name - name to format
 * @return string - properly formatted string
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
        inputFile >> currLine;
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
            }
        }
        inputFile.close();
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
       
        total[studentId] = totalScore;
        percent[studentId] = stuPercent;
    }
}



void writeFormattedGrades(const string outputFilepath, map<int,Name> &names, map<int,int> &total, map<int,float> &percent) {

    ofstream outputFile(outputFilepath);

    if(outputFile.good()) {

        int studentId;
        long startPos;
        long tillPos;
        for(auto &currStudent : names) {
            startPos = outputFile.tellp();

            studentId = currStudent.first;

            outputFile << currStudent.second.lastName << ", ";
            outputFile << currStudent.second.firstName;

            // write total score
            tillPos = 22-(outputFile.tellp()-startPos);
            outputFile << setw(tillPos);            
            outputFile << total[studentId];

            // write percent
            tillPos =  29-(outputFile.tellp()-startPos);
            outputFile << setw(tillPos);
            outputFile << fixed << setprecision(1) << percent[studentId];

            outputFile << endl;
        }

    }
    outputFile.close();
}
