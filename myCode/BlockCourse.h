#ifndef BLOCKCOURSE_H_
#define BLOCKCOURSE_H_

#include "Course.h"
#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>

/**
 * @class BlockCourse
 * @brief Represents a Block course, inheriting from the Course class.
 *  this class extend Course class and include start date, end date,
 *   start time and end time.
 *
 */
class BlockCourse: public Course{

private:

	/**
	 * @brief Private!!. The start date for the Block course.
		 */
	Poco::Data::Date startDate;

	/**
	 * @brief Private!!. The end date for the Block course.
		 */
	Poco::Data::Date endDate;

	/**
	 * @brief Private!!. The start time for the Block course.
		 */
	Poco::Data::Time startTime;

	/**
	 * @brief Private!!. The end time for the Block course.
		 */
	Poco::Data::Time endTime;

public:

	/**
		 * @fn  BlockCourse(unsigned int, std::string, std::string, float,
		 * Poco::Data::Date, Poco::Data::Date, Poco::Data::Time, Poco::Data::Time)
	 * @brief Parameterised constructor for BlockCourse
	 *
	 * @param courseKey
	 * @param title
	 * @param major
	 * @param creditPoints
	 * @param startDate
	 * @param endDate
	 * @param startTime
	 * @param endTime
	 */
	BlockCourse(unsigned int courseKey, std::string title, std::string major,
			float creditPoints, Poco::Data::Date startDate,
			Poco::Data::Date endDate, Poco::Data::Time startTime,
			Poco::Data::Time endTime);

	/**
		 * @fn void write(std::ostream&)const
	 * @brief for writing data to txt or csv file
	 *
	 * @param out
	 */
	void write(std::ostream &out) const;

	/**
		 * @fn std::unique_ptr<BlockCourse> read(std::istream&)
	 * @brief for reading data from txt or csv file
	 *
	 * @param in
	 * @return
	 */
	static std::unique_ptr<BlockCourse> read(std::istream &in);

	/**
		 * @fn  ~WeeklyCourse()
	 * @brief Destructor of the class
	 *
	 */
	virtual ~BlockCourse();
};

#endif /* BLOCKCOURSE_H_ */
