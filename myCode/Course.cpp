//
//#include <map>
//#include <memory>
//#include <string>
//
//#include <sstream>
//

//class Course{
//
//protected:

//	unsigned int courseKey;

//	std::string title;

//	unsigned char major;

//	float creditPoints;

//	static std::map<unsigned char, std::string> majorById;
//
//public:
//
//	Course(unsigned int courseKy, std::string title, std::string major,
//			float creditPoints);

//	virtual void write(std::ostream &out) const;
//	virtual std::string getMajor();

//	virtual unsigned int getCourseKey() const;

//	static std::unique_ptr<Course> read(std::istream &in);

//	virtual ~Course();
//};

#include "Course.h"
#include "BlockCourse.h"
#include "WeeklyCourse.h"
#include<memory>

std::map<unsigned char, std::string> Course::majorById{
	{'A',"Automation"},
	{'E',"Embedded"},
	{'P',"Power"},
	{'C',"Communication"},
};

Course::Course(unsigned int courseKey, std::string title, std::string major,
		float creditPoints) : courseKey{courseKey}, title{title},
				creditPoints{creditPoints}
		{
			for ( auto major_temp : majorById)
			{
				if(major_temp.second == major)
				{
					this->major= major_temp.first;
					break;
				}
			}
}

Course::~Course() {
	// TODO Auto-generated destructor stub
}

void Course::write(std::ostream &out) const
{
	out<<std::to_string(courseKey)+";";
	out<<title+";";
	out<<std::to_string(creditPoints)+";";
}

unsigned int Course::getCourseKey() const {
	return courseKey;
}

std::string Course::getMajor() {
	std::string major_string;
	for ( auto major_temp : majorById)
	{
		if(major_temp.first == this->major)
		{
			major_string=major_temp.second;
			break;
		}
	}
	return major_string;
}

std::unique_ptr<Course> Course::read(std::istream &in) {

	std::string line,line2;

	std::vector<std::string> linedata;
	getline(in,line,';');
	linedata.push_back(line);

	char courseType = linedata.at(0)[0];
	getline(in,line2);

	if(courseType=='W'|| courseType=='w') {
		std::istringstream istrg(line2);
		std::unique_ptr<WeeklyCourse> WeeklyCourse_ptr = WeeklyCourse::read(istrg);
		return WeeklyCourse_ptr;

	}else if(courseType=='B' || courseType=='b') {
		std::istringstream istrg(line2);
		std::unique_ptr<BlockCourse> BlockCourse_ptr = BlockCourse::read(istrg);
		return BlockCourse_ptr;
	}

	return nullptr;
}
