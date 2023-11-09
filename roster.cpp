#include <iostream>
#include <string>
#include "roster.h"

using namespace std; 

/* The "parse" function definition
It goes through a set of strings (in a long string) delimited by commas (',')
It parses out each row of the string 
This is going to allow me to extract the student data */ 
void Roster::parse(string row)
{
	DegreeProgram dp = SECURITY; // Default value 
	/* Here the last character allows to find the degree program */
	if (row.back() == 'K') dp = NETWORK; 
	else if (row.back() == 'E') dp = SOFTWARE;

	int rhs; // Right hand side
	int lhs; // Left hand side 

	rhs = row.find(","); // Find the first comma 
	string sID = row.substr(0, rhs); // Extracts the substring in front of the comma - Student ID

	lhs = rhs + 1; // move to the next substring
	rhs = row.find(",", lhs); // find the comma 
	string fName = row.substr(lhs, rhs - lhs); // Extracts the First name 

	lhs = rhs + 1; 
	rhs = row.find(",", lhs);
	string lName = row.substr(lhs, rhs - lhs); // Extracts the Last name 

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string email = row.substr(lhs, rhs - lhs); // Extracts the Email address

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int age = stoi(row.substr(lhs, rhs - lhs)); // Converts Age to an integer and extracts

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int dIc1 = stoi(row.substr(lhs, rhs - lhs)); // Converts First course to an integer and extracts
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int dIc2 = stoi(row.substr(lhs, rhs - lhs)); // Converts Second course to an integer and extracts
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int dIc3 = stoi(row.substr(lhs, rhs - lhs)); // Converts Third course to an integer and extracts

	/* Call to "add" function to create an object
	It passes the temporary variables */
	add(sID, fName, lName, email, age, dIc1, dIc2, dIc3, dp);
}
/* The "add" function definition
It creates the student object and places it in the repository */
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{

	int daysArray[3] = { daysInCourse1,daysInCourse2,daysInCourse3 }; // Here I want to put the days back into an array for the constructor
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeprogram); // Full constructor
}

/* The "printAll" function definition
It prints the information for each student */
void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
		 
}
/* The "printByDegreeProgram" function definiton
It prints out student information for a degree program specified by an enumerated type */
void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
	cout << "Information of students in the " << degreeProgramStrings[degreeprogram] << " Program:" << endl;
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeprogram() == degreeprogram) classRosterArray[i]->print();
	}
	cout << endl;
}

/* The "printInvalidEmails function declaration
It finds and prints invalid emails and the students ID related
Valid email include an ('@') sign and a period ('.') and do not include a space (' ') */
void Roster::printInvalidEmails()
{
	bool any = false; // If no invalid emails are found
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string emailAddress = (classRosterArray[i]->getEmailAddress());
		if (emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos || emailAddress.find(' ') != string::npos)
		{
			any = true;
			cout << classRosterArray[i]->getStudentID() << ": " << emailAddress << endl;
		}
	}
	if (!any) cout << "No invalid emails" << endl; // Displays if no invalid email is found 
}

/* The "printAverageDaysInCourse" function declaration 
It prints the students average number of days in the three courses by student ID */
void Roster::printAverageDaysInCourse(string studentID) // Student ID is passed as a parameter
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			cout << studentID << ":";
			cout <<(classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << endl;

		}
		
	}
}
/* The "remove" function declaration 
It finds and removes student from the "Roster" by student ID */
bool Roster::remove(string studentID) // Student ID is passed as a parameter
{
	bool found = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			found = true; 
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (found)
	{
		cout << "Student with ID " << studentID << " is removed from the Student Data Table." << endl << endl;
		/* Not actually deleted, but it won't appear anymore in the Student Data Table */
		
	}
	else {
		cout << "Student with ID " << studentID << " was not found in the Student Data Table" << endl << endl;
	}
	return found; // Return Value
}
/* Implementation of a destructor to release the memory that was dynamically allocated in the Roster */
Roster::~Roster()
{
	cout << " The Destructor is called." << endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << " Deleting/destroying student's data" << i + 1 << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
