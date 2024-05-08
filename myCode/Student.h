#ifndef STUDENT_H_
#define STUDENT_H_

#include<string>
#include <Poco/Data/Date.h>
#include<vector>

#include "Enrollment.h"
#include "Address.h"

/**
 * @class Student
 * @brief Represent student with enrollments and address
 *
 */
class Student{

	/**
	 * @brief Private!!. static variable for providing next matrikel number.
		 */
	static unsigned int nextMatrikelNumber;

	/**
	 * @brief Private!!. static variable to store highest matrikel number.
		 */
	static unsigned int highestMatrikelNumber;

	/**
	 * @brief Private!!. static variable for storing current readed matrikel
	 * number.
		 */
	static unsigned int readedMatrikelNumber;

	/**
	 * @brief Private!!. matrikel number of student.
		 */
	unsigned int matrikelNumber;

	/**
	 * @brief Private!!. first name of the student.
		 */
	std::string firstName;

	/**
	 * @brief Private!!. last name of the student.
		 */
	std::string lastName;

	/**
	 * @brief Private!!. date of birth of student.
		 */
	Poco::Data::Date datOfBirth;

	/**
	 * @brief Private!!. vector to store enrollments of student.
		 */
	std::vector<Enrollment> enrollments;

	/**
	 * @brief Private!!. address of the student.
		 */
	Address address;
public:

	/**
		 * @fn  Student(std::string, std::string, Poco::Data::Date, Address)
	 * @brief Parameterised constructor for Student
	 *
	 * @param firstName
	 * @param lastName
	 * @param datOfBirth
	 * @param address
	 */
	Student(std::string firstName, std::string lastName,
			Poco::Data::Date datOfBirth, Address address);

	/**
		 * @fn  Student()
	 * @brief default constructor for Student
	 *
	 */
//	Student();

	/**
		 * @fn  ~WeeklyCourse()
	 * @brief Destructor of the class
	 *
	 */
	~Student();

	/**
		 * @fn std::vector<Enrollment> getEnrollments&()
	 * @brief getter for student enrollments.
	 *
	 * @return Enrollment
	 */
	std::vector<Enrollment>& getEnrollments();

	/**
		 * @fn unsigned int getMatrikelNumber()const
	 * @brief getter for matrikel number
	 *
	 * @return matrikelNumber
	 */
	unsigned int getMatrikelNumber() const;

	/**
		 * @fn const Address getAddress&()const
	 * @brief getter for Address
	 *
	 * @return Address
	 */
	const Address& getAddress() const;

	/**
		 * @fn void setAddress(const Address&)
	 * @brief setter for Address
	 *
	 * @param address
	 */
	void setAddress(const Address &address);

	/**
		 * @fn const Poco::Data::Date getDatOfBirth&()const
	 * @brief getter for DOB
	 *
	 * @return dateOfBirth
	 */
	const Poco::Data::Date& getDatOfBirth() const;

	/**
		 * @fn void setDatOfBirth(const Poco::Data::Date&)
	 * @brief setter for date of birth
	 *
	 * @param datOfBirth
	 */
	void setDatOfBirth(const Poco::Data::Date &datOfBirth);

	/**
		 * @fn const std::string getFirstName&()const
	 * @brief getter for first name
	 *
	 * @return firstName
	 */
	const std::string& getFirstName() const;

	/**
		 * @fn void setFirstName(const std::string&)
	 * @brief setter for first name
	 *
	 * @param firstName
	 */
	void setFirstName(const std::string &firstName);

	/**
		 * @fn const std::string getLastName&()const
	 * @brief getter for last name
	 *
	 * @return lastName
	 */
	const std::string& getLastName() const;

	/**
		 * @fn void setLastName(const std::string&)
	 * @brief setter for last name
	 *
	 * @param lastName
	 */
	void setLastName(const std::string &lastName);

	/**
		 * @fn void addEnrollment(Enrollment)
	 * @brief for adding enrollment to the student
	 *
	 * @param enrollment
	 */
	void addEnrollment(Enrollment enrollment);

	/**
		 * @fn Student read(std::istream&)
	 * @brief for reading data from txt or csv file
	 *
	 * @param in
	 * @return
	 */
	static Student read(std::istream& in);

	/**
		 * @fn void write(std::ostream&)const
	 * @brief for writing data to txt or csv file
	 *
	 * @param out
	 */
	void write(std::ostream &out) const;
};

#endif /* STUDENT_H_ */
