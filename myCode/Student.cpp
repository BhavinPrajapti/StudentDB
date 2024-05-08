/*
 * Student.cpp
 *
 *  Created on: 20 Jan 2024
 *      Author: hp
 */
#include<iostream>
#include "Student.h"
#include"Address.h"
//static pvt varibles
unsigned int Student::nextMatrikelNumber=100000;
unsigned int Student::highestMatrikelNumber=0;
unsigned int Student::readedMatrikelNumber=0;

Student::Student(std::string firstName, std::string lastName,
		Poco::Data::Date datOfBirth, Address address) : firstName{firstName} ,
		lastName{lastName}, datOfBirth{datOfBirth}, address{address}
		{
			//for taking highestst matrikel number
			if(readedMatrikelNumber>0)
			{
				matrikelNumber=readedMatrikelNumber;
				readedMatrikelNumber=0;
				nextMatrikelNumber=0;
			} else if(nextMatrikelNumber>highestMatrikelNumber) {
				matrikelNumber=nextMatrikelNumber;
				nextMatrikelNumber++;
			}else if(nextMatrikelNumber<highestMatrikelNumber) {
				matrikelNumber=highestMatrikelNumber+1;
				nextMatrikelNumber++;
			}
}

std::vector<Enrollment>& Student::getEnrollments() {
	return enrollments;
}

const Address& Student::getAddress() const {
	return address;
}

void Student::setAddress(const Address &address) {
	this->address = address;
}

const Poco::Data::Date& Student::getDatOfBirth() const {
	return datOfBirth;
}

void Student::setDatOfBirth(const Poco::Data::Date &datOfBirth) {
	this->datOfBirth = datOfBirth;
}

const std::string& Student::getFirstName() const {
	return firstName;
}

void Student::setFirstName(const std::string &firstName) {
	this->firstName = firstName;
}

const std::string& Student::getLastName() const {
	return lastName;
}

//Student::Student() {
//}

void Student::setLastName(const std::string &lastName) {
	this->lastName = lastName;
}

unsigned int Student::getMatrikelNumber() const {
	return matrikelNumber;
}

Student Student::read(std::istream &in) {
	std::string line;
	std::string s1,s2,s3,s4;

	std::vector<std::string> linedata;

	getline(in,s1,';');
	linedata.push_back(s1);
	getline(in,s2,';');
	linedata.push_back(s2);
	getline(in,s3,';');
	linedata.push_back(s3);
	getline(in,s4,';');
	linedata.push_back(s4);
	unsigned int matrikelNumber;
	std::string firstName;
	std::string lastName;
	Poco::Data::Date datOfBirth;

	matrikelNumber=std::stoi(linedata.at(0));
	readedMatrikelNumber=matrikelNumber;
	nextMatrikelNumber=0;
	if(matrikelNumber>highestMatrikelNumber)
	{
		highestMatrikelNumber=matrikelNumber;
	}
	firstName=linedata.at(1);
	lastName=linedata.at(2);

	std::string Date_str =linedata.at(3);
	std::istringstream str(Date_str);
	std::string day,month,year;
	if(getline(str,day,'.')) {
		if(getline(str,month,'.')) {
			getline(str,year);
		}
	}
	datOfBirth = Poco::Data::Date(std::stoi(year),std::stoi(month),
			std::stoi(day));
	getline(in,line);
	std::istringstream str2(line);

	return Student(firstName,lastName,datOfBirth,Address::read(str2));

}

void Student::write(std::ostream &out) const{
	out<<std::to_string(matrikelNumber)+";";
	out<<firstName+";";
	out<<lastName+";";
	out<<std::to_string(datOfBirth.day())+"."+std::to_string(datOfBirth.month())
			+"."+std::to_string(datOfBirth.year())+";";
}

Student::~Student()
{
	// TODO Auto-generated destructor stub
}

void Student::addEnrollment(Enrollment enrollment) {
	this->enrollments.push_back(enrollment);
}
