#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_

#include <string>
#include "Course.h"

/**
 * @class Enrollment
 * @brief represent enrollment of course with student
 *
 */
class Enrollment{

	/**
	 * @brief course pointer.
		 */
	 const Course* course;

	/**
	 * @brief semester of enrolled course
		 */
	std::string semester;

	/**
	 * @brief grade of course.
		 */
	float grade;

public:

	/**
		 * @fn  Enrollment(const Course*, std::string, float)
	 * @brief parameterised constructor of class
	 *
	 * @param course
	 * @param semester
	 * @param grade
	 */
	Enrollment( const Course* course, std::string semester, float grade);

	/**
		 * @fn  ~Enrollment()
	 * @brief destructor of class
	 *
	 */
	virtual ~Enrollment();

	/**
		 * @fn const Course getCourse*()const
	 * @brief getter for course
	 *
	 * @return
	 */
	 const Course* getCourse() const;

	/**
		 * @fn float getGrade()const
	 * @brief getter for grade
	 *
	 * @return
	 */
	float getGrade() const;

	/**
		 * @fn void setGrade(float)
	 * @brief setter for grade
	 *
	 * @param grade
	 */
	void setGrade(float grade);

	/**
		 * @fn void write(std::ostream&)const
	 * @brief for writing data to txt or csv file
	 *
	 * @param out
	 */
	void write(std::ostream &out) const;
	
	/**
		 * @fn Enrollment read(std::istream&, const Course*)
	 * @brief  for reading data from csv or txt file
	 *
	 * @param in
	 * @param course
	 * @return
	 */
	static Enrollment read(std::istream &in, const Course* course);

	/**
		 * @fn const std::string getSemester&()const
	 * @brief getter for semester
	 *
	 * @return
	 */
	const std::string& getSemester() const;
};

#endif /* ENROLLMENT_H_ */
