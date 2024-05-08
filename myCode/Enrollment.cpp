
//	const Course* course;
//	std::string semester;
//	float grade;

#include "Enrollment.h"

#include <iomanip>
#include<vector>

Enrollment::Enrollment( const Course *course, std::string semester, float grade)
: course(course), semester(semester) ,grade(grade){
	//grade=-1;
}

 const Course* Enrollment::getCourse() const {
	return course;
}

float Enrollment::getGrade() const {
	return grade;
}

void Enrollment::setGrade(float grade) {
	this->grade = grade;
}

Enrollment::~Enrollment()
{
	// TODO Auto-generated destructor stub
}

void Enrollment::write(std::ostream &out) const {
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) <<grade;
	out<<std::to_string(course->getCourseKey())+";";
	out<<semester+";";
	out<<oss.str();
}

const std::string& Enrollment::getSemester() const {
	return semester;
}

Enrollment Enrollment::read(std::istream &in, const Course* course) {
	std::string line;
	std::vector<std::string> linedata;

	while(getline(in,line,';')) {
		linedata.push_back(line);
	}

	unsigned int courseKey;
	float grade;
	std::string semester;
	courseKey=std::stoi(linedata.at(0));
	semester=linedata.at(1);
	grade=std::stof(linedata.at(2));

	if(course->getCourseKey()== courseKey) {
		return Enrollment(course,semester,grade);
	}
	else {
		return Enrollment(nullptr,semester,grade);
	}
}
