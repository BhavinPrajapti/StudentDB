//	class WeeklyCourse : public Course
//	{
//		Poco::DateTime::DaysOfWeek dayOfWeek;
//
//		Poco::Data::Time startTime;
//
//		Poco::Data::Time endTime;

#include "WeeklyCourse.h"
#include <iomanip>

WeeklyCourse::WeeklyCourse(unsigned int courseKey, std::string title,
		std::string major, float creditPoints,
		Poco::DateTime::DaysOfWeek dayOfWeek, Poco::Data::Time startTime,
		Poco::Data::Time endTime) : Course(courseKey,title,major,creditPoints),
		dayOfWeek(dayOfWeek), startTime(startTime),
		endTime(endTime) {
}

//	std::string Temperature::toString() const
//	{
//		ostringstream oss;
//
//		oss << "Temperature: " << this->temperature << "°C";
//
//		return oss.str();
//
//	//	return ("Temperature: " + to_string(this->temperature) + "°C");
//	}

void WeeklyCourse::write(std::ostream &out) const{

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) <<creditPoints;

	out<<std::string("W;");
	out<<std::to_string(courseKey)+";";
	out<<title+";";
	out<<majorById[major]+";";
	out<<oss.str()+";";
	out<<std::to_string(dayOfWeek)+";";
	out<<std::to_string(startTime.hour())+":"+std::to_string(startTime.minute())
			+";"+std::to_string(endTime.hour())+":"+
			std::to_string(endTime.minute());
}

//		//timestamp to hour min
//		std::string Measurement::toTimeOfDay(uint16_t timestamp)
//		{
//			ostringstream oss;
//
//			int hour = (timestamp/60);
//			int minute = timestamp%60;
//			//iomanip for set
//			oss << setw(2) << setfill('0') << hour << ":" << setw(2) <<
//			setfill('0') << minute;
//
//			return oss.str();
//		}

WeeklyCourse::~WeeklyCourse()
{
	// TODO Auto-generated destructor stub
}
//static std::unique_ptr<WeeklyCourse> read(std::istream &in);
std::unique_ptr<WeeklyCourse> WeeklyCourse::read(std::istream &in) {
	std::string line;
	std::vector<std::string> linedata;

	while(getline(in,line,';')) {
		linedata.push_back(line);
	}

	unsigned int courseKey;
	std::string title,major;
	Poco::DateTime::DaysOfWeek dayOfWeek;
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;
	Poco::Data::Date startDate;
	Poco::Data::Date endDate;
	float creditPoints;

	courseKey=std::stoi(linedata.at(0));
	title=linedata.at(1);
	major=linedata.at(2);
	creditPoints=std::stof(linedata.at(3));
	int dayOfWeekInt=std::stoi(linedata.at(4));

	dayOfWeek = static_cast<Poco::DateTime::DaysOfWeek>(dayOfWeekInt);


	std::string startTimeString = linedata.at(5);
	std::istringstream start_str(startTimeString);
	std::string shour,smin;

	int int_start_h,int_start_m;
	if(getline(start_str,shour,':')) {
		getline(start_str,smin);
		int_start_h=std::stoi(shour);
		int_start_m=std::stoi(smin);
	}
	startTime = Poco::Data::Time{int_start_h,int_start_m,0};

	std::string endTimeString =linedata.at(6);
	std::istringstream end_str(endTimeString);
	std::string ehour,emin;

	int int_end_h=0,int_end_m=0;
	if(getline(end_str,ehour,':')) {
		getline(end_str,emin);
		int_end_h=std::stoi(ehour);
		int_end_m=std::stoi(emin);
	}
	endTime = Poco::Data::Time{int_end_h,int_end_m,0};

	std::unique_ptr<WeeklyCourse> wc(new WeeklyCourse(courseKey,title,major,creditPoints,
			dayOfWeek,startTime,endTime) );

	//return std::make_unique<WeeklyCourse> (courseKey,title,major,creditPoints,
		//	dayOfWeek,startTime,endTime);
	return wc;
}

// != string::npos
//
//	uint16_t Measurement::toTimestamp(int hour, int minute)
//	{
//		uint16_t minSinceMidnight = 0;
//
//		if(hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59)
//		{
//			minSinceMidnight = (hour * 60) + minute;
//		}
//		else
//		{
//			cout << "Invalid Argument" << endl;
//		}
//
//		return minSinceMidnight;
//	}


