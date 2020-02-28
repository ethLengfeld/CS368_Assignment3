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
 * Library to read grade file with student
 * information and homework scores. Library will
 * also allow for data manipulation. Library
 * also supports abilty to be outputted to a 
 * desired file.
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
 * Read through all students in map
 * and properly format their names.
 * First letter is uppercase all others
 * are lower case.
 * 
 * @param map<int, Name> &names - student id paired with student
*/
void formatCaseOfNames(map<int,Name> &names);

/**
 * Read through each students homeword scores
 * and compute a score total and a percent
 * that will be added to the respective maps
 *  
 * @param map<int,vector<int>> &studentScores - 
 * @param map<int,int> &total - student's total scores
 * @param map<int,float> &percent - student's percent on scores
*/
void computeTotalAndPercent(map<int,vector<int>> &scores, map<int,int> &total, map<int,float> &percent);


/**
 * Write each student's name, score, and percent
 * (Last, First      Score     Percent)
 * to the passed in output file path
 * 
 * @param string outputFilepath - output file path
 * @param map<int,int> &total - student's total scores
 * @param map<int,float> &percent - student's percent on scores
*/
void writeFormattedGrades(const string outputFilepath, map<int,Name> &names, map<int,int> &total, map<int,float> &percent);

#endif