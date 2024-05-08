#ifndef SIMPLEUI_H_
#define SIMPLEUI_H_

#include "StudentDb.h"
#include <iostream>

/**
 * @class SimpleUI
 * @brief simple user interface for the database
 *
 */
class SimpleUI
{
	/**
	 * @brief reference to StudentDb class.
		 */
	StudentDb db;

public:

	/**
		 * @fn  SimpleUI(StudentDb&)
	 * @brief parameterised constructor
	 *
	 * @param db
	 */
	SimpleUI(StudentDb& db);

	/**
		 * @fn void run()
	 * @brief for running studentDB
	 *
	 */
	void run();

	/**
		 * @fn  ~SimpleUI()
	 * @brief Destructor of class
	 *
	 */
	~SimpleUI();

	/**
		 * @fn void addCourseDataFromUser()
	 * @brief asking data from user and add course
	 *
	 */
	void addCourseDataFromUser();

	/**
		 * @fn void addStudentDataFromUser()
	 * @brief asking data from user and add student
	 *
	 */
	void addStudentDataFromUser();

	/**
		 * @fn void addEnrollmentDataFromUser()
	 * @brief adds enrollment based on data provided from user
	 *
	 *
	 */
	void addEnrollmentDataFromUser();

	/**
		 * @fn void updateStudentDetail()
	 * @brief update student database based on user requirements
	 *
	 */
	void updateStudentDetail();

};

#endif /* SIMPLEUI_H_ */
