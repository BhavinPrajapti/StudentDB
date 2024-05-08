#ifndef COURSE_H_
#define COURSE_H_

#include <map>
#include <memory>
#include <string>

#include <sstream>

/**
 * @class Course
 * @brief represent Course with Coursekey, title, major, creditpoints
 * this class is main class for WeeklyCourse and BlockCourse
 *
 */
class Course{

protected:
	/**
	 * @brief Private!!. Key of the course.
		 */
	unsigned int courseKey;

	/**
	 * @brief Private!!. title of the course.
		 */
	std::string title;

	/**
	 * @brief Private!!. Represents major of the course.
		 */
	unsigned char major;

	/**
	 * @brief Private!!. Represents creditpoint of the course.
		 */
	float creditPoints;

	/**
	 * @brief Private!!. Map of the major. for storage optimization for major
	 * string.
		 */
	static std::map<unsigned char, std::string> majorById;

public:

	/**
		 * @fn  Course(unsigned int, std::string, std::string, float)
	 * @brief Parameterised constructor for course
	 *
	 * @param courseKey
	 * @param title
	 * @param major
	 * @param creditPoints
	 */
	Course(unsigned int courseKy, std::string title, std::string major,
			float creditPoints);

	/**
		 * @fn void write(std::ostream&)const
	 * @brief for writing data to txt or csv file
	 *
	 * @param out
	 */
	virtual void write(std::ostream &out) const;

	/**
		 * @fn std::string getMajor()
	 * @brief getter for major string
	 *
	 * @return
	 */
	virtual std::string getMajor();

	/**
		 * @fn unsigned int getCourseKey()const
	 * @brief getter for coursekey
	 *
	 * @return Course
	 */
	virtual unsigned int getCourseKey() const;

	/**
		 * @fn std::unique_ptr<Course> read(std::istream&)
	 * @brief for reading data from txt or csv file
	 *
	 * @param in
	 * @return
	 */
	static std::unique_ptr<Course> read(std::istream &in);

	/**
		 * @fn  ~WeeklyCourse()
	 * @brief Destructor of the class
	 *
	 */
	virtual ~Course();

};

#endif /* COURSE_H_ */
