#include <iostream>
#include "student.h"
#include "roster.h"
#include <vector>
#include <sstream>
#include <string>
#include <array>
#include <cstring>
using namespace std;



void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, DegreeProgram degreeprogram) {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
			break;
		}
	}
}

void Roster::printAll() {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

void Roster::remove(string studentID) {
	bool idFound = false;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); ++i) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
			idFound = true;
			cout << "Removing student with ID " << studentID << ":" << endl;
			for (int j = i; j < (sizeof(classRosterArray) / sizeof(classRosterArray[i]) - 1); ++j) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			classRosterArray[(sizeof(classRosterArray) / sizeof(classRosterArray[0])) - 1] = nullptr;
		}
	}
	if (idFound == false) {
		cout << "Removing student with ID " << studentID << ":" << endl;
		cout << "Error: Student with ID " << studentID << " was not found." << endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); ++i) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
			int* daysInCourse = classRosterArray[i]->GetDaysInCourse();
			int average = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3;
			string fullName = classRosterArray[i]->GetFullName();
			string id = classRosterArray[i]->GetStudentID();
			cout << id << " " << fullName << ": " << average << " days" << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	bool invalidEmail = false;
	vector<string> invalidEmailAddresses;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); ++i) {
		if (classRosterArray[i] != nullptr) {
			string email;
			email = classRosterArray[i]->GetEmailAddress();
			const int maxEmailAddressLength = 50;
			char emailCharArray[maxEmailAddressLength + 1];
			strcpy_s(emailCharArray, 50, email.c_str());
			if (strchr(emailCharArray, '@') == nullptr || strchr(emailCharArray, '.') == nullptr || strchr(emailCharArray, ' ') != nullptr) {
				invalidEmail = true;
				invalidEmailAddresses.push_back(email);

			}
		}
	}
	cout << "Invalid Email Addresses (A valid email should include an at sign and period and should not include a space): " << endl;
	for (int i = 0; i < invalidEmailAddresses.size(); ++i) {
		cout << invalidEmailAddresses.at(i) << "\t";
	}
	cout << endl << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	string program;
	switch (degreeProgram) {
	case 0: program = "SECURITY";
		break;
	case 1: program = "NETWORK";
		break;
	case 2: program = "SOFTWARE";
		break;
	}
	cout << "Students in the " << program << " program: " << endl;
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); ++i) {
		if (classRosterArray[i] != nullptr) {
			DegreeProgram degree = classRosterArray[i]->GetDegreeProgram();
			if (degree == degreeProgram) {
				classRosterArray[i]->print();
			}
		}
	}
	cout << endl;
}

int Roster::size() {
	return sizeof(classRosterArray) / sizeof(classRosterArray[0]);
}

Roster::~Roster() {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
		}
	}
	return;
}
