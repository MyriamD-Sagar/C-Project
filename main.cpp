#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main()
{
	/* Input of the student data table */
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,30,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Myriam,Drouin-Sagar,midroui3@wgu.edu,25,20,30,23,SOFTWARE"
	};
	/* Personal information to display */
	cout << "Scripting & Programing - Applications C867"; // Course Title
	cout << endl;
	cout << "C++ Programing Language"; // Programing language used
	cout << endl;
	cout << "Myriam Drouin-Sagar (007857813)"; // Name and Student ID 
	cout << endl;
	cout << endl;

	const int numStudents = 5; // The number of students in the Student Data Table
	/* Here I am creating an instance of the class "Roster" called "classRoster" */
	Roster classRoster; 

    /* Calls the "parse()" function*/
	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);   

	cout << "The Student Data Table will follow:" << endl;
	/* Calls the function "printAll()" to display the Student Data Table */
	classRoster.printAll(); 
	cout << endl; 

    /* Call the function "printInvalidEmails()" */
	cout << "Students with invalid emails will follow:" << endl;
	classRoster.printInvalidEmails(); 
	cout << endl;

	/* Calls the function "printsAverageDaysInCourse()" */
	cout << "The Average days in course for each student will follow:" << endl;
	for (int i = 0; i < numStudents; i++) // Loops through the array of students  
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
		cout << endl;
	}

	/* Calls the function "printByDegreeProgram()" */
	{
		
		classRoster.printByDegreeProgram(SOFTWARE); // Here the requirements for the assessment wants only students in the Software degree program
		cout << endl;
	}

	/* Call the function "remove()" */
	cout << "Removing student from the Student Data Table by Student ID:" << endl;
	cout << endl;
	classRoster.remove("A3");

	cout << "Updated Student Data Table:" << endl;
	classRoster.printAll(); // Calls the function "printAll()" to print the updated Students Data Table  

	cout << "Verifying if the student has been correctly removed from the Student Data Table:" << endl;
	classRoster.remove("A3"); // Calls the function "remove()"

	system("pause"); // End 
	return 0;

};
