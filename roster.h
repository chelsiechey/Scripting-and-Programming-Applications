#pragma once
#include "student.h"
#include <string>
#include <cstring>
using namespace std;

const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Chelsie,Conrad,cgrav51@wgu.edu,22,40,32,12,SOFTWARE"
};

class Roster {
public:
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, DegreeProgram degreeprogram);
	void printAll();
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	int size();
	~Roster();
};



