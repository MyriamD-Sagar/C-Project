#include <iostream>
#include <string>
#include "student.h"

using namespace std;

/* Student class 
- including member function definitions */
Student::Student() // Parameterless constructor
{
	/* Default values */
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = 0;
	this->degreeprogram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeprogram) // Full Constructor
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName; 
	this->emailAddress = emailAddress;
	this->age = age; 
	for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeprogram = degreeprogram; 
}
Student::~Student() {} // The student class creates nothing dynamically, so the destructor does nothing 

/* Accessors (getters) */
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysInCourse() { return this->daysInCourse; } // Returns a pointer to int, because an array name is a pointer (constant)
DegreeProgram Student::getDegreeprogram() { return this->degreeprogram; }

/* Mutators (setters) */
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
/* For the days in course, I used a loop to set each days individually. */
void Student::setDaysInCourse(int daysInCourse[])
{
	for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegreeprogram(DegreeProgram degreeprogram) { this->degreeprogram = degreeprogram; }

/* Definition of the function to print headers on top of the data */
void Student::printHeader()
{
	cout << left << setw(15) << "Student ID";
	cout << left << setw(15) << "First Name";
	cout << left << setw(20) << "Last Name";
	cout << left << setw(30) << "Email Address";
	cout << left << setw(5) << "Age";
	cout << left << setw(20) << "Days in Course";
	cout << left << setw(20) << "Degree Program";
	cout << endl;	
}

/* Definition of the function to print specific student data */
void Student::print()
{
	cout << left << setw(15) << this->studentID;
	cout << left << setw(15) << this->firstName;
	cout << left << setw(20) << this->lastName;
	cout << left << setw(30) << this->emailAddress;
	cout << left << setw(5) << this->age;
	cout << left << setw(2) << this->daysInCourse[0] << ",";
	cout << left << setw(2) << this->daysInCourse[1] << ",";
	cout << left << setw(16) << this->daysInCourse[2];
	cout << left << setw(20) << degreeProgramStrings[this->degreeprogram];
	cout << endl;
	  
}