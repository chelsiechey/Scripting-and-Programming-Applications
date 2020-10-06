#include "student.h"

string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetFullName() const {
	return fullName;
}

string Student::GetEmailAddress() const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}

int* Student::GetDaysInCourse() {
	return daysInCourse;
}

DegreeProgram Student::GetDegreeProgram() const {
	return degreeprogram;
}

void Student::SetStudentID(string id) {
	studentID = id;
}

void Student::SetFirstName(string fname) {
	firstName = fname;
}

void Student::SetLastName(string lname) {
	lastName = lname;
}

void Student::SetFullName(string fname, string lname) {
	fullName = fname + " " + lname;
}

void Student::SetEmailAddress(string email) {
	emailAddress = email;
}

void Student::SetAge(int studentAge) {
	age = studentAge;
}

void Student::SetDaysInCourse(int* days) {
	for (int i = 0; i < NUM_COURSES; ++i) {
		daysInCourse[i] = days[i];
	}
}

void Student::SetDegreeProgram(DegreeProgram program) {
	degreeprogram = program;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[NUM_COURSES], DegreeProgram degreeprogram) {
	SetStudentID(studentID);
	SetFirstName(firstName);
	SetLastName(lastName);
	SetFullName(firstName, lastName);
	SetEmailAddress(emailAddress);
	SetAge(age);
	SetDaysInCourse(days);
	SetDegreeProgram(degreeprogram);
}

void Student::print() {
	cout << GetStudentID() << "\t";
	cout << "First Name: " << GetFirstName() << "\t";
	cout << "Last Name: " << GetLastName() << "\t";
	cout << "Age: " << GetAge() << "\t";
	int* days = GetDaysInCourse();
	cout << "daysInCourse: {" << days[0] << ", " << days[1] << ", " << days[2] << "}" << "\t";
	cout << "Degree Program: ";
	switch (GetDegreeProgram()) {
	case 0: cout << "Security";
		break;
	case 1: cout << "Network";
		break;
	case 2: cout << "Software";
		break;
	}
	cout << endl;
}

