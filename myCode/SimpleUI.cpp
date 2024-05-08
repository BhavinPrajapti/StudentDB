//		StudentDb db;
//		SimpleUI(StudentDb& db);
#include "SimpleUI.h"
#include <map>
#include <vector>
//#include <memory>

#include "BlockCourse.h"
#include "WeeklyCourse.h"

SimpleUI::SimpleUI(StudentDb &db) {
}

void SimpleUI::run() {

	while(true)
	{
		std::cout<<"Enter 1 - Add New Course" << std::endl;
		std::cout<<"Enter 2 - List the Courses" << std::endl;
		std::cout<<"Enter 3 - Add new Student" << std::endl;
		std::cout<<"Enter 4 - Add Enrollment" << std::endl;
		std::cout<<"Enter 5 - Print Student Details" << std::endl;
		std::cout<<"Enter 6 - Search Student in Database" << std::endl;
		std::cout<<"Enter 7 - Update Student Details" << std::endl;
		std::cout<<"Enter 8 - Write Student Database to a text file" << std::endl;
		std::cout<<"Enter 9 - Read Student Database from a file" << std::endl;
		std::cout<<"Enter 10 - Read Student Database from a server" << std::endl;

			std::string userInput;
			unsigned int input=0;

			std::cout<<"Choose any option: "<<std::endl;
			std::cin>>userInput;
			//checking for valid value
			if(db.validdigits(userInput)) {
				input=std::stoi(userInput);
			}

		switch(input){

		case 1:
		{
			addCourseDataFromUser();

		break;
		}
		case 2:
		{
			std::cout<<"Available Courses in Database."<<std::endl;
			//reading data from courses map
			for (auto const& courseItr : db.getCourses()) {
				courseItr.second->write(std::cout);
				std::cout<<std::endl;	//printing on console
			}
			break;
		}
		case 3:
		{
			addStudentDataFromUser();
			break;
		}
		case 4:
		{
			addEnrollmentDataFromUser();
			break;
		}

		case 5:
		{
			int matrikelNumber;

			do {
				std::cout<<"Enter matrikel Number: "<<std::endl;
				std::cin>>matrikelNumber;
				//checking for valid value
				if (std::cin.fail() ||matrikelNumber<0 ) {
					std::cerr<<"Invalid input. Please enter a valid"
							"integer for matrikelNumber." <<std::endl;
					std::cin.clear();  // Clear the error flag
					std::cin.ignore(std::numeric_limits<std::streamsize>
					::max(),'\n');  // Discard invalid input
					continue;
				} else {
					break;
				}
			} while (true);

			std::map<int, Student>& students = db.getStudents();

			//finding student
			auto findstudent=students.find(matrikelNumber);

			if(findstudent != students.end()){
				Student& student = findstudent->second;
				//printing on console
				std::cout<<"Basic Details:"<<std::endl;
				student.write(std::cout);
				std::cout<<std::endl;
				std::cout<<std::endl;

				std::cout<<"Address Details:"<<std::endl;
				student.getAddress().write(std::cout);
				std::cout<<std::endl;
				std::cout<<std::endl;

				std::vector<Enrollment> enroll=student.getEnrollments();

				std::cout<<"Enrolled Courses:"<<std::endl;
				for (auto const& e : enroll)
				{
					e.getCourse()->write(std::cout);
					e.write(std::cout);
					std::cout<<std::endl;
				}
			} else
			{
				std::cout<<"Student does not exist in database!!"<<std::endl;
			}
			break;
		}
		case 6:
		{
			std::string searchedtext;
			std::cout<<"Enter firstname/lastname of student: "<<std::endl;
			std::cin>>searchedtext;
			std::map<int, Student>& students = db.getStudents();

			for(auto& itr : students)
			{
				if(itr.second.getFirstName()== searchedtext ||
						itr.second.getLastName() == searchedtext){

					std::cout<<"First Name: "
							<<itr.second.getFirstName()<<std::endl;
					std::cout<<"Last Name: "
							<<itr.second.getLastName()<<std::endl;
					std::cout<<"Matrikel Number: "
							<<itr.second.getMatrikelNumber()<<std::endl;
				} else {
					std::cout<<"Not able to find related student data based on "
							"your searched data"<<std::endl;
				}
			}
			break;
		}
		case 7:
		{
			updateStudentDetail();
			break;
		}
		case 8:									// data writing to file
		{
			std::string filename;
			std::cout<<"Enter file name to write data: (i.e. file.txt)"<<std::endl;
	        std::cin>>filename;

			std::ofstream fb(filename);
			if(fb.is_open()){
				db.write(fb);
				fb.close();
				std::cout<<"Student Database is written sucessfully!"<<std::endl;
			} else {
				std::cout<<"Unable to Open File"<<std::endl;
			}
			break;
		}

//		void StudentDb::writeStudent(std::ostream &out) const {
//			int size= students.size();
//			if(size !=0) {
//				out<<std::to_string(size);
//				out<<std::endl;
//			}
//			for(const auto& itr : students)
//			{
//				itr.second.write(out);
//				itr.second.getAddress().write(out);
//				out<<std::endl;
//			}
//		}
//

		case 9:								//reading data
		{
			std::string filename="readStudentDb.txt";

	        std::ifstream inputFile(filename);		//#include<ifstream>

	        if(inputFile.is_open()) {
	        	db.read(inputFile);
	        	inputFile.close();
				std::cout<<"read sucessfully!"<<std::endl;
	        } else {
	        	std::cout<<"Unable to Open File"<<std::endl;
	        }
			break;
		}
		case 10:
		{
			int noOfUser=1;

				std::cout<<"Enter no of student: "<<std::endl;
				std::cin>>noOfUser;

			db.readStudentsFromServer(noOfUser);

			break;
		}
		default:
		{
			std::cout<<"Invalid option!!"<<std::endl;
		}}}
}
//	regex timePattern(R"(\d{1,2}\:\d{1,2})");
//
//	cout << endl << "\t \t Enter the Course Start Time - HH:MM : ";
//	getline(cin, startTime);
//
//	if(!regex_match(startTime, timePattern))
//	{
//		cerr << "You entered an invalid time format (hint: HH:MM)" << endl;
//		return;
//	}
void SimpleUI::addCourseDataFromUser() {
	std::string courseKeyStr;
	unsigned int courseKey;
	std::string title;
	std::string creditPointsStr;
	float creditPoints=0;
	std::string major;
	int startTimeH = 0;
	int endTimeH = 0;
	int startTimeM = 0;
	int endTimeM = 0;
	unsigned int startDateY = 0;
	unsigned int startDateM = 0;
	unsigned int startDateD = 0;
	unsigned int endDateY = 0;
	unsigned int endDateM = 0;
	unsigned int endDateD = 0;
	std::string courseType;
	unsigned int dayOfWeekInt;
	Poco::DateTime::DaysOfWeek dayOfWeek;
//
//	void print() {
//			if(!this->condition)
//				throw "Not digit";
// 				throw std::logic_error("balance is non zero:
//				"+std::to_string(accounts.at(id).get()->getBalance()));
//			std::cout<<"run sucessfully";
//		}
//
//	try{
//			c.print();
//		}
//	catch(const char* txtException) {
//			std::cerr<<"Exception :"<<txtException;
//		}
//
//	catch(int code) {
//			std::cerr<<"Exception :"<<code;
//		}
//
//	catch(const std::exception& e){
//			std::cerr<<"An error occured "<<e.what()<<std::endl;
//											//poco throwing this
//		}


	if(courseType=="w" || courseType=="W") {
		std::cout<<"choose Day of the week:"<<std::endl;
		std::cout<<"0. SUNDAY       1. MONDAY"<<std::endl;
		std::cout<<"2. TUESDAY      3. WENESDAY "<<std::endl;
		std::cout<<"4. THURSDAY     5. FRIDAY "<<std::endl;
		std::cout<<"6. SATURDAY"<<std::endl;
		std::string dayOfWeekIntStr;

		do {
			do {
				std::cout<<"Enter Day of the week:"<<std::endl;
				std::getline(std::cin,dayOfWeekIntStr);
			} while (!db.validdigits(dayOfWeekIntStr));

		} while(std::stoi(dayOfWeekIntStr)>7 || std::stoi(dayOfWeekIntStr)<0);

		dayOfWeekInt=std::stoi(dayOfWeekIntStr);
		dayOfWeek=static_cast<Poco::DateTime::DaysOfWeek>(dayOfWeekInt);
	}

//	class DuplicateSensorName: public std::invalid_argument {
//	public:
//	    DuplicateSensorName(std::string sensorName);

//	DuplicateSensorName::DuplicateSensorName(std::string sensorName) :
//	std::invalid_argument("Duplicate sensor name: " + sensorName) {
//	}

//	throw DuplicateSensorName(sensor->getName());

	if(courseType=="w" || courseType=="W") {

		std::unique_ptr<WeeklyCourse> course5=
				std::make_unique<WeeklyCourse> (courseKey,
				title, major, creditPoints,dayOfWeek,
				Poco::Data::Time{startTimeH,startTimeM,0},
				Poco::Data::Time{endTimeH,endTimeM,0});
		db.addCourse(std::move(course5));

	} else if(courseType=="b" || courseType=="B"){
								//					unique pointer
		std::unique_ptr<const Course> course
		=std::unique_ptr<BlockCourse> (new BlockCourse(courseKey,
				title, major, creditPoints,
				Poco::Data::Date(startDateY,startDateM,startDateD),
				Poco::Data::Date(endDateY,endDateM,endDateD),
				Poco::Data::Time{startTimeH,startTimeM,0},
				Poco::Data::Time{endTimeH,endTimeM,0}));
		db.addCourse(std::move(course));
	}
}

void SimpleUI::addStudentDataFromUser() {

	std::string firstName;
	std::string lastName;
	unsigned short day,month,year;
	Poco::Data::Date datOfBirth;
	Address address;
	std::string street;
	int postalCode=-1;
	std::string cityName;
	std::string additionalInfo;

	Student a(firstName,lastName,
				Poco::Data::Date(year,month,day),
				Address(street,postalCode,cityName,additionalInfo));

	db.addStudent(a);

	std::cout<<"\n Student added!!. Your matrikel number is: "<<
			a.getMatrikelNumber()
			<<std::endl;

}

void SimpleUI::addEnrollmentDataFromUser() {

	int matrikelNumber, courseKey;
	std::string sem,gradestr;
	float grade=-1;

	bool enrollmentStatus = db.addEnrollment(matrikelNumber,courseKey,
			sem,grade);
}

SimpleUI::~SimpleUI() {
}

void SimpleUI::updateStudentDetail() {

	int matrikelNumber;

	std::map<int, Student>& students = db.getStudents();

	auto findstudent=students.find(matrikelNumber);

	if(findstudent != students.end()){
		Student& student = findstudent->second;
		std::cout<<"Enter 1 for update firstName: "<<std::endl;
		std::cout<<"Enter 2 for update lastName: "<<std::endl;
		std::cout<<"Enter 3 for update DOB: "<<std::endl;
		std::cout<<"Enter 4 for update Address: "<<std::endl;
		std::cout<<"Enter 5 for update Enrollments: "<<std::endl;
		std::cout<<"Enter 0 for exit: "<<std::endl;
		std::string userInput2;
		unsigned int input2=0;

		std::cout<<"Choose any option: "<<std::endl;
		std::cin>>userInput2;

		if(db.validdigits(userInput2)) {
			input2=std::stoi(userInput2);
		}

		switch(input2){
		case 5: {
			int input=-1;
			int courseKey=-1;
			float grade;
			bool gradestatus=false;
			bool removestatus=false;

			std::vector<Enrollment> enroll=student.getEnrollments();

			for (auto itr : enroll) {
				itr.getCourse()->write(std::cout);
				itr.write(std::cout);
				std::cout<<std::endl;
			}

			std::cout<<"Enter 1 for update grade"<<std::endl;
			std::cout<<"Enter 2 for remove enrolment"<<std::endl;

			std::cin>>input;

			do{
				std::cout<<"Enter CourseKey: "<<std::endl;

				std::cin>>courseKey;

				if (std::cin.fail() || courseKey<0) {
					std::cerr<<"Invalid input. Please enter a "
							"valid integer for input." <<std::endl;
					std::cin.clear();  // Clear the error flag
					std::cin.ignore(std::numeric_limits<std::
							streamsize>::max(),'\n');  // Discard invalid input
					continue;
				} else {
					break;
				}
			}while(true);

			if(input==1)
			{std::string gradestr;

				gradestatus= db.updateGrade(student,courseKey,grade);

			}else {
				removestatus=db.removeEnrollment(student,courseKey);

			}

			break;
		}
		default: {
			std::cout<<"invalid Input. exiting to main options."<<
					std::endl;
			break;
		}
	}

	}else {
		std::cout << "Student not found!" << std::endl;
	}
}


