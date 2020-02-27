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

// TODO delete iostream if nothing is printed out
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

// TODO add comment for struct
typedef struct Name
{
    string firstName;
    string lastName;
} Name;

/**
 * 
 * 
 * @param string inputFilepath - 
 * @param int* numberOfStudents - 
 * @param int* numberOfAssignments - 
 * @param map<int, Name> &studentNames - 
 * @param map<int, vector<int>> &studentScores - 
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