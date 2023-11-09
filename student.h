#pragma once // Keeps us from making multiple includes 
#include <iostream>
#include <iomanip>
#include "degree.h" // Relative reference 

 /* For this file, I need "string" and "cout" from the Standard Name Space */
using std::string; 
using std::cout; 

/* Definition of the Student class 
- Including data members and member function declarations */
class Student
{
/* First, define the constant in the public section */ 
public:
	
	const static int daysInCourseArraySize = 3; // Here is the size of the array of number of days to complete each course (fixed size)

/* Private section */
private: 
	/* Data members */
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[daysInCourseArraySize];
	DegreeProgram degreeprogram; // "DegreeProgram" is an enumerated data type  
public:
	Student(); // Parameterless Constructor 
	
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeprogram); // Here is the full constructor 

	~Student(); // Destructor does nothing here, but it is always good to have it. 

	/* Create accessors (getters) for each instance variable */
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeprogram();

	/* Create mutators (setters) for each instance variable */
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeprogram(DegreeProgram degreeprogram);

	static void printHeader(); // "printHeader" function to diplay headers on top of the data
	void print(); // "print" function to display specific student data 

};