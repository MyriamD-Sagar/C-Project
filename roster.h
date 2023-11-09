#pragma once
#include "student.h"

/* Definiton of the "Roster" class
- including data members and member function declaration */
class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents]; // Array of students - not declared dynamically
public:
	/* The "parse" function declaration */
	void parse(string row);

	/* The "add" function declaration */
	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeprogram);
	/* The "remove" function declaration */
	bool remove(string studentID); 
	/* The "printAll" function declaration */
	void printAll(); 
	/* The "printAverageDaysInCourse" function declaration */
	void printAverageDaysInCourse(string studentID);
	/* The "printInvalidEmails function declaration */
	void printInvalidEmails(); 
	/* The "printByDegreeProgram function declaration */
	void printByDegreeProgram(DegreeProgram degreeprogram);

	~Roster(); // Destructor
};