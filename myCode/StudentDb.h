#ifndef STUDENTDB_H_
#define STUDENTDB_H_

#include"Course.h"
#include "Student.h"

#include <map>
#include <memory>	//for smart pointer

#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
// for boost::asio::ip::tcp::iostream
#include <boost/asio.hpp>
#include <boost/iostreams/stream.hpp>
//for jason read
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

/**
 * @class StudentDb
 * @brief Database of students and courses
 *
 */
class StudentDb{

	/**
	 * @brief Private!!. map of the all students.
		 */
	std::map<int,Student> students;

	/**
	 * @brief Private!!. map of the all courses.
		 */
	std::map<int,std::unique_ptr< const Course>> courses;

public:

	/**
		 * @fn  StudentDb()
	 * @brief default constructor for StudentDb
	 *
	 */
	StudentDb();

	void addCourse(std::unique_ptr<const Course> course);

	/**
		 * @fn void addStudent(Student)
	 * @brief for adding student in database.
	 *
	 * @param student
	 */
	void addStudent(Student student);

	/**
		 * @fn  ~StudentDb()
	 * @brief Desturctor of class
	 *
	 */
	virtual ~StudentDb();

	/**
		 * @fn std::map<int,std::unique_ptr<const Course>> getCourses&()
	 * @brief getter for course from map
	 *
	 * @return
	 */
	std::map<int, std::unique_ptr<const Course>>& getCourses();

	/**
		 * @fn std::map<int,Student> getStudents&()
	 * @brief getter for student from map
	 *
	 * @return
	 */
	std::map<int, Student>& getStudents();

	/**
		 * @fn bool addEnrollment(unsigned int, unsigned int, std::string, float)
	 * @brief for enrollment of student to courses
	 *
	 * @param matrikelNumber
	 * @param courseKey
	 * @param sem
	 * @param grade
	 * @return
	 */
	bool addEnrollment(unsigned int matrikelNumber,unsigned int courseKey,
			std::string sem,float grade);

	/**
		 * @fn bool updateFirstName(Student&, std::string)
	 * @brief for updating student first name
	 *
	 * @param student
	 * @param firstName
	 * @return
	 */
	bool updateFirstName(Student& student,std::string firstName);

	/**
		 * @fn bool updateLastName(Student&, std::string)
	 * @brief for updating student last name
	 *
	 * @param student
	 * @param lastName
	 * @return
	 */
	bool updateLastName(Student& student,std::string lastName);

	/**
		 * @fn bool updateDOB(Student&, Poco::Data::Date)
	 * @brief for update student date of birth
	 *
	 * @param student
	 * @param datOfBirth
	 * @return
	 */
	bool updateDOB(Student& student,Poco::Data::Date datOfBirth);

	/**
		 * @fn bool updateAddress(Student&, unsigned int, std::string)
	 * @brief for update student address data
	 *
	 * @param student
	 * @param input
	 * @param name
	 * @return
	 */
	bool updateAddress(Student& student,unsigned int input,std::string name);

	/**
		 * @fn bool updateGrade(Student&, unsigned int, float)
	 * @brief for update grade of the student
	 *
	 * @param student
	 * @param courseKey
	 * @param grade
	 * @return
	 */
	bool updateGrade(Student& student,unsigned int courseKey,float grade);

	/**
		 * @fn bool removeEnrollment(Student&, unsigned int)
	 * @brief for removing enrollments of student enrollment
	 *
	 * @param student
	 * @param courseKey
	 * @return
	 */
	bool removeEnrollment(Student& student,unsigned int courseKey);

	/**
		 * @fn void write(std::ostream&)const
	 * @brief for writing Student DB data to txt or csv file
	 *
	 * @param out
	 */
	void write(std::ostream &out) const;

	/**
		 * @fn void writeCourse(std::ostream&)const
	 * @brief for writing courses to txt or csv file
	 *
	 * @param out
	 */
	void writeCourse(std::ostream& out) const;

	/**
		 * @fn void writeStudent(std::ostream&)const
	 * @brief for writing student details to txt or csv file
	 *
	 * @param out
	 */
	void writeStudent(std::ostream& out) const;

	/**
		 * @fn void writeEnrollment(std::ostream&)const
	 * @brief for writing student's enrollments to txt or csv file
	 *
	 * @param out
	 */
	void writeEnrollment(std::ostream& out) const;

	/**
		 * @fn void read(std::istream&)
	 * @brief for reading student DB data from txt or csv file
	 *
	 * @param in
	 */
	void read(std::istream &in);

	/**
		 * @fn void readStudents(std::istream&)
	 * @brief for reading student data from csv or txt file
	 *
	 * @param in
	 */
	void readStudents(std::istream &in);

	/**
		 * @fn void readCourses(std::istream&)
	 * @brief for reading courses data from csv or txt file
	 *
	 * @param in
	 */
	void readCourses(std::istream &in);

	/**
		 * @fn void readEnrollments(std::istream&)
	 * @brief for reading enrollments data from csv or txt file
	 *
	 * @param in
	 */
	void readEnrollments(std::istream &in);

	/**
		 * @fn void readStudentsFromServer(unsigned int)
	 * @brief for reading data from server
	 *
	 * @param noOfStudent
	 */
	void readStudentsFromServer(unsigned int noOfStudent);

	/**
		 * @fn bool validString(const std::string&)
	 * @brief for checking printable valid string
	 *
	 * @param inputstring
	 * @return
	 */
	bool validString(const std::string &inputstring);

	/**
		 * @fn bool validdigits(std::string&)
	 * @brief for checking valid numerical string
	 *
	 * @param inputdigits
	 * @return
	 */
	bool validdigits(std::string &inputdigits);

};

#endif /* STUDENTDB_H_ */
