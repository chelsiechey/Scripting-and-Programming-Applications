#pragma once
#include "degree.h"
#include <string>
#include <vector>
#include <sstream>
#include <array>
#include <iostream>

using namespace std;

const int NUM_COURSES = 3;

class Student {
public:
	// Accessors
	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmailAddress() const;
	int GetAge() const;
	int* GetDaysInCourse();
	DegreeProgram GetDegreeProgram() const;
	string GetFullName() const;
	// Mutators
	void SetStudentID(string id);
	void SetFirstName(string fname);
	void SetLastName(string lname);
	void SetFullName(string fname, string lname);
	void SetEmailAddress(string email);
	void SetAge(int studentAge);
	void SetDaysInCourse(int[3]);
	void SetDegreeProgram(DegreeProgram program);

	void print();

	// Constructor
	Student(string, string, string, string, int, int*, DegreeProgram);


private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	string fullName;
	int age;
	int daysInCourse[NUM_COURSES];
	DegreeProgram degreeprogram;
};
