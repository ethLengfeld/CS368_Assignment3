////////////////////////////////////////////////////////////////////////////////
// Main File: SummarizeGrades.cpp, demo.cpp
// This File: SummarizeGrades.h
// Other Files: 	 SummarizeGrades.h / SummarizeGrades.cpp / demo.cpp / Makefile / README.md
// Semester:         CS 368 Spring 2020
//
// Author:           Ethan Lengfeld
// Email:            elengfeld@wisc.edu
// CS Login:         lengfeld
//
//
// Online sources:   http://www.cplusplus.com/reference/string/
//
////////////////////////////////////////////////////////////////////////////////

#ifndef SUMGRADES
#define SUMGRADES

/**
 * TODO
 * 
*/

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

// hold a students first and last name in one struct
typedef struct Name
{
    string firstName;
    string lastName;
} Name;

/**
 * Take input file and fill data structures
 * with relavent data read in from the input
 * string
 * 
 * @param string inputFilepath - file path
 * @param int* numberOfStudents - no. students read from file
 * @param int* numberOfAssignments - no. assignments read from file
 * @param map<int, Name> &studentNames - student id paired with student
 * @param map<int, vector<int>> &studentScores - student id pair scores
*/
void readGradeFile(const string inputFilepath, int *numberOfStudents, int *numberOfAssignments, map<int,Name> &studentNames, map<int,vector<int>> &studentScores);

/**
 * 
 * 
 * @param map<int, Name> &names -  
*/
void formatCaseOfNames(map<int,Name> &names);

/**
 * 
 *  
 * @param map<int,vector<int>> &studentScores - 
 * @param map<int,int> &total -
 * @param @param map<int,float> &percent - 
*/
void computeTotalAndPercent(map<int,vector<int>> &scores, map<int,int> &total, map<int,float> &percent);


/**
 * 
 * 
 * @param string outputFilepath - 
 * @param map<int,int> &total -
 * @param @param map<int,float> &percent -  
*/
void writeFormattedGrades(const string outputFilepath, map<int,Name> &names, map<int,int> &total, map<int,float> &percent);

#endif