#include "BlockCourse.h"
#include <iomanip>

BlockCourse::BlockCourse(unsigned int courseKey, std::string title,
		std::string major, float creditPoints, Poco::Data::Date startDate,
		Poco::Data::Date endDate, Poco::Data::Time startTime,
		Poco::Data::Time endTime) : Course(courseKey,title,major,creditPoints),
		startDate(startDate), endDate(endDate), startTime(startTime),
		endTime(endTime){
}

void BlockCourse::write(std::ostream &out) const {
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) <<creditPoints;
	out <<std::string("B;");
	out<<std::to_string(courseKey)+";";
	out<<title+";";
	out<<majorById[major]+";";
	out<<oss.str()+";";
	out<<std::to_string(startDate.day())+"."+std::to_string(startDate.month())+
			"."+std::to_string(startDate.year())+";";
	out<<std::to_string(endDate.day())+"."+std::to_string(endDate.month())+
			"."+std::to_string(endDate.year())+";";
	out<<std::to_string(startTime.hour())+":"+std::to_string(startTime.minute())
			+";"+std::to_string(endTime.hour())+":"+
			std::to_string(endTime.minute());

}

std::unique_ptr<BlockCourse> BlockCourse::read(std::istream &in) {

	std::string line;
	std::vector<std::string> linedata;

	while(getline(in,line,';')) {
		linedata.push_back(line);
	}

	unsigned int courseKey;
	std::string title,major;
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;
	Poco::Data::Date startDate;
	Poco::Data::Date endDate;
	float creditPoints;

	courseKey=std::stoi(linedata.at(0));
	title=linedata.at(1);
	major=linedata.at(2);
	creditPoints=std::stof(linedata.at(3));

	std::string startDate_str =linedata.at(4);
	std::istringstream str(startDate_str);
	std::string sday,smonth,syear;
	if(getline(str,sday,'.')) {
		if(getline(str,smonth,'.')) {
			getline(str,syear);
		}
	}
	startDate= Poco::Data::Date(std::stoi(syear),std::stoi(smonth),
			std::stoi(sday));

	std::string endDate_str =linedata.at(5);
	std::istringstream e_str(endDate_str);
	std::string eday,emonth,eyear;
	if(getline(e_str,eday,'.')) {
		if(getline(e_str,emonth,'.')) {
			getline(e_str,eyear);
		}
	}
	endDate= Poco::Data::Date(std::stoi(eyear),std::stoi(emonth),
			std::stoi(eday));

	std::string startTimeString = linedata.at(6);
	std::istringstream start_str(startTimeString);
	std::string shour,smin;

	int int_start_h,int_start_m;
	if(getline(start_str,shour,':')) {
		getline(start_str,smin);
		int_start_h=std::stoi(shour);
		int_start_m=std::stoi(smin);
	}
	startTime = Poco::Data::Time{int_start_h,int_start_m,0};

	std::string endTimeString =linedata.at(7);
	std::istringstream end_str(endTimeString);
	std::string ehour,emin;

	int int_end_h=0,int_end_m=0;
	if(getline(end_str,ehour,':')) {
		getline(end_str,emin);
		int_end_h=std::stoi(ehour);
		int_end_m=std::stoi(emin);
	}
	endTime = Poco::Data::Time{int_end_h,int_end_m,0};

	return std::make_unique<BlockCourse> (courseKey,title,major,creditPoints,
			startDate,endDate,startTime,endTime);
}

BlockCourse::~BlockCourse()
{
	// TODO Auto-generated destructor stub
}

