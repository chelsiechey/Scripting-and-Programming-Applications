#include "student.h"
#include "roster.h"
#include "degree.h"
#include <iostream>


using namespace std;



int main() {
	cout << "C867 - Scripting and Programming - Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 001130463" << endl;
	cout << "Name: Chelsie Conrad" << endl;
	cout << endl << "Class Roster: " << endl;

	Roster classRoster; // creating an instance of the Roster class

	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[0]); ++i) {
		vector<string> currentStudentData; // initialize vector to store data for one student
		string currentStudentString = studentData[i];
		stringstream s_stream(currentStudentString); // create string stream from currentStudentString
		while (s_stream.good()) {
			string currentDataItem;
			getline(s_stream, currentDataItem, ',');
			currentStudentData.push_back(currentDataItem);
		}
		stringstream age(currentStudentData[4]);
		int convertToInt = 0; // variable created to convert age into an integer
		age >> convertToInt;
		stringstream day1(currentStudentData[5]);
		int convertToInt2 = 0;
		day1 >> convertToInt2;
		stringstream day2(currentStudentData[6]);
		int convertToInt3 = 0;
		day2 >> convertToInt3;
		stringstream day3(currentStudentData[7]);
		int convertToInt4 = 0;
		day3 >> convertToInt4;
		int daysInCourse[NUM_COURSES] = { convertToInt2, convertToInt3, convertToInt4 };

		DegreeProgram degreeprogram;
		if (currentStudentData[8] == "SECURITY") {
			degreeprogram = SECURITY;
		}
		else if (currentStudentData[8] == "NETWORK") {
			degreeprogram = NETWORK;
		}
		else if (currentStudentData[8] == "SOFTWARE") {
			degreeprogram = SOFTWARE;
		}


		classRoster.add(currentStudentData[0], currentStudentData[1], currentStudentData[2], currentStudentData[3], convertToInt, daysInCourse, degreeprogram);
	}

	classRoster.printAll();
	cout << endl;
	classRoster.printInvalidEmails();
	cout << "Average Number of Days to Complete 3 Courses for each student:" << endl;
	for (int i = 0; i < classRoster.size(); ++i) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	}
	cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	cout << endl;

	return 0;
}