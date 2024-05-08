#ifndef WEEKLYCOURSE_H_
#define WEEKLYCOURSE_H_

#include "Course.h"
#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>

/**
 * @class WeeklyCourse
 * @brief Represents a weekly course, inheriting from the Course class.
 * this class extend Course class and include dayofweek, start time and endtime
 * information
 *
 */
class WeeklyCourse : public Course
{
	/**
	 * @brief Private!!. The day of the week for the weekly course.
		 */
	Poco::DateTime::DaysOfWeek dayOfWeek;

	/**
	 * @brief Private!!. The Start Time of the week for the weekly course.
		 */
	Poco::Data::Time startTime;

	/**
	 * @brief Private!!. The End Time of the week for the weekly course.
		 */
	Poco::Data::Time endTime;

public:
	/**
		 * @fn  WeeklyCourse(unsigned int, std::string, std::string, float,
		 * Poco::DateTime::DaysOfWeek, Poco::Data::Time, Poco::Data::Time)
	 * @brief Parameterised constructor for WeeklyCourse
	 *
	 * @param courseKey
	 * @param title
	 * @param major
	 * @param creditPoints
	 * @param dayOfWeek
	 * @param startTime
	 * @param endTime
	 */
	WeeklyCourse(unsigned int courseKey, std::string title, std::string major,
			float creditPoints, Poco::DateTime::DaysOfWeek dayOfWeek,
			Poco::Data::Time startTime,Poco::Data::Time endTime);

	/**
		 * @fn void write(std::ostream&)const
	 * @brief for writing data to txt or csv file
	 *
	 * @param out
	 */
	void write(std::ostream &out) const;

	/**
		 * @fn std::unique_ptr<WeeklyCourse> read(std::istream&)
	 * @brief for reading data from txt or csv file
	 *
	 * @param in
	 * @return WeeklyCourse
	 */
	static std::unique_ptr<WeeklyCourse> read(std::istream &in);

	/**
		 * @fn  ~WeeklyCourse()
	 * @brief Destructor of the class
	 *
	 */
	virtual ~WeeklyCourse();
};

#endif /* WEEKLYCOURSE_H_ */
