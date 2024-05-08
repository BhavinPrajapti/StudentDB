#include "StudentDb.h"
#include "BlockCourse.h"
#include "WeeklyCourse.h"

//		#include"Course.h"
//		#include "Student.h"
//
//		#include <map>
//		#include <memory>	//for smart pointer
//
//		#include <Poco/Data/Date.h>
//		#include <Poco/Data/Time.h>
//		// for boost::asio::ip::tcp::iostream
//		#include <boost/asio.hpp>
//		#include <boost/iostreams/stream.hpp>
//		//for jason read
//		#include <boost/property_tree/ptree.hpp>
//		#include <boost/property_tree/json_parser.hpp>

//	std::map<int,Student> students;
//	std::map<int,std::unique_ptr< const Course>> courses;

StudentDb::StudentDb()
{
	// TODO Auto-generated constructor stub
}

void StudentDb::addCourse(std::unique_ptr<const Course> course) {


	courses[course->getCourseKey()] = std::move(course);
}

void StudentDb::addStudent(Student student) {
//	students[student.getMatrikelNumber()] = student;
	students.insert(std::pair<int,Student>(student.getMatrikelNumber(),student));
}

std::map<int, Student>& StudentDb::getStudents()  {
	return students;
}

StudentDb::~StudentDb()
{
	// TODO Auto-generated destructor stub
}

std::map<int, std::unique_ptr< const Course>>& StudentDb::getCourses() {
	return courses;
}

bool StudentDb::addEnrollment(unsigned int matrikelNumber,
		unsigned int courseKey, std::string sem,float grade) {

	//std::map<int, Student>& students = getStudents();
	auto findstudent=students.find(matrikelNumber);
	bool addEnrollment = false;

	if(findstudent != students.end()){
		Student& student = findstudent->second;
		addEnrollment = true;

		std::vector<Enrollment> enroll=student.getEnrollments();
		for(auto& itr : enroll){
			if(itr.getCourse()->getCourseKey()==courseKey){
				//enrolled already
				addEnrollment = false;
				break;
			}
		}
		if (addEnrollment) {
			auto& courses = getCourses();
			auto coursefind = courses.find(courseKey);
			if (coursefind != courses.end()) {
				const Course* course = coursefind->second.get();
				Enrollment enrollment(course, sem, grade);
				student.addEnrollment(enrollment);
				//Student Enrolled
			}else{
				//Coursekey is not available in the database
				addEnrollment = false;
			}
		}
	}else {
		//Student not found!
		addEnrollment = false;
	}
	return addEnrollment;
}

bool StudentDb::updateFirstName(Student& student,std::string firstName) {
	student.setFirstName(firstName);
	return true;
}

bool StudentDb::updateLastName(Student& student,std::string lastName) {
	student.setLastName(lastName);
	return true;
}
//		list<int> a{10,2,3};   //vector
//		//front operation only list
//		list<int> b;    //vector
//
//		//1- push opration
//		a.push_back(500);   //a.insert(itr,125)
//		a.emplace_back(2500);  //10 2 3 500 2500
//		cout<<"size: "<<a.size()<<endl;     //5
//
//		//2
//		cout<<"start: "<<*a.begin()<<endl;  //10   //a.front()
//		cout<<"end: "<<*a.rbegin()<<endl;   //2500   //a.back()
//		auto third=next(a.begin(),2);       //3     +1 working in vector
//		auto secondlast=prev(a.end(),2);    //500
//
//		//  cout<<"end: "<<a[3]<<endl; //vector
//
//		//3 printing
//		for(auto itr=a.begin();itr!=a.end();++itr) {
//			cout<<*itr<<" "<<endl; }
//
//		for(auto itr:a) {
//			cout<<itr<<endl; }
//
//		//4 algorithms
//		int count=count_if(a.begin(),a.end(),[](int x){return x==10;});
//
//		//5 find operations
//		auto y=find(a.begin(),a.end(),2500);  /return itr pointing to 2500
//		if(y!=a.end()) { cout<<"found!!"<<endl;}
//
//		cout<<"count: "<<count<<" "<<*y<<endl;  // 1 2500
//
//		//6
//		transform(next(a.begin()),a.end(),back_inserter(b),[](int x){
//			if(x>10) {return x+1; }else {return x;}});  //2 3 501 2501
//
//		//7
//		a.sort();   //list
//		sort(a.begin(),a.end());    //vector
//
//		//8
//		a.erase(y);    //remove 2500
//		a.splice(itr,b,itr_A,itr_B);  //list //cut b from A TO B and insert
//			in a at itr
//

bool StudentDb::updateDOB(Student &student, Poco::Data::Date datOfBirth) {
	student.setDatOfBirth(datOfBirth);
	return true;
}
//		For set
//		//1
//		a.insert(500);
//		//5
//		auto y=a.find(2500);
//		//6
//		std::inserter(b, b.end())
//		//8
//		a.erase(2500);  //itr also working like vector list

bool StudentDb::updateAddress(Student &student, unsigned int input,
		std::string name) {

	std::string existingStreetName = student.getAddress().getStreet();
	unsigned int existingPostalCode = student.getAddress().getPostalCode();
	std::string existingCityName = student.getAddress().getCityName();
	std::string existingAdditionalInfo = student.getAddress().getAdditionalInfo();

	//creating new address pointer for updated address
	if(input==1) {
		student.setAddress(Address(name,existingPostalCode,existingCityName,
				existingAdditionalInfo));
		return true;
	} else if (input==2) {
		student.setAddress(Address(existingStreetName,std::stoi(name),
				existingCityName, existingAdditionalInfo));
		return true;
	}else if (input==3) {
		student.setAddress(Address(existingStreetName,existingPostalCode,name,
				existingAdditionalInfo));
		return true;
	}else if(input==4) {
		student.setAddress(Address(existingStreetName,existingPostalCode,
				existingCityName, name));
		return true;
	}else{
		return false;
	}
}

bool StudentDb::updateGrade(Student &student, unsigned int courseKey,
		float grade) {

	std::vector<Enrollment>& enroll=student.getEnrollments();
	for (auto& itr : enroll)
	{
		if(itr.getCourse()->getCourseKey()==courseKey) {
			itr.setGrade(grade);
			return true;
		}else {
			return false;
		}
	}
	return false;
}
//		//map
//		//1
//		map1[1]='B';
//		map1[5]='P';
//		map1.insert(make_pair(3,'h'));
//
//		//2
//		cout<<"start: "<<map1.begin()->first <<endl;  //1
//		cout<<"end: "<<map1.rbegin()->second<<endl;     //p
//		auto it=map1.begin();
//		it++;
//		cout<<"second: "<<it->first<<endl;    //3
//
//		//3
//		for(auto itr=map1.begin();itr!=map1.end();++itr) {
//				cout<<itr->first<<" "<<(*itr).second<<endl; }
//
//		for(auto itr:map1) {
//			cout<<itr.first<<" "<<(itr).second<<endl; }
//
//		//5
//		auto yy=map1.find(3);
//		if(yy!=map1.end())
//		{    cout<<"found";}

bool StudentDb::removeEnrollment(Student &student, unsigned int courseKey) {

	std::vector<Enrollment>& enroll=student.getEnrollments();
	for(auto i=enroll.begin();i!=enroll.end();++i) {
	//for(auto i:enroll) {

		if(i->getCourse()->getCourseKey()== courseKey) {
			//auto in=i;
			enroll.erase(i);
			return true;
		}
	}

//	auto it=std::remove_if(enroll.begin(),enroll.end(),
//			[courseKey](const Enrollment& enr) {
//		return enr.getCourse()->getCourseKey() == courseKey;
//	});
//
//	//find()
//	enroll.erase(it);
//    if (it != enroll.end()) {
//        // Enrollment was removed
//        return true;
//    } else {
//        // CourseKey not found, no enrollment removed
//        return false;
//    }
return false;
}

void StudentDb::write(std::ostream &out) const {		// write
	writeCourse(out);
	writeStudent(out);
	writeEnrollment(out);
}

void StudentDb::writeCourse(std::ostream &out) const {		//write
	int size= courses.size();
	if(size !=0) {
		out<<std::to_string(size);
		out<<std::endl;
	}
	for(const auto& itr: courses)
	{
		itr.second->write(out);
		out<<std::endl;
	}
}

void StudentDb::writeStudent(std::ostream &out) const {		//write
	int size= students.size();
	if(size !=0) {
		out<<std::to_string(size);
		out<<std::endl;
	}
	for(const auto& itr : students)
	{
		itr.second.write(out);
		itr.second.getAddress().write(out);
		out<<std::endl;
	}
}

void StudentDb::writeEnrollment(std::ostream &out) const {		//write
	int count=0;
	for(auto itrcount : students)
	{
		std::vector<Enrollment>& enrollment_count=
				itrcount.second.getEnrollments();
		int size=enrollment_count.size();
		count=count+size;
	}
		if(count !=0) {
			out<<std::to_string(count);
			out<<std::endl;
		}

	for(auto itr : students)
	{
		std::vector<Enrollment> enrollment=itr.second.getEnrollments();
		for(auto& itr1 : enrollment) {
			out<<std::to_string(itr.second.getMatrikelNumber())+";";
			itr1.write(out);
			out<<std::endl;
		}
	}
}

void StudentDb::read(std::istream &in) {		//		read
	this->courses.clear();
	this->students.clear();

	readCourses(in);
	readStudents(in);
	readEnrollments(in);
}

void StudentDb::readStudents(std::istream &in) {		//read

	std::string line;
	std::string count;

	getline(in,count);
	if(!count.empty()) {
		int courseCount=std::stoi(count);

		for(int i=0;i<courseCount;i++) {
			getline(in,line);

			std::istringstream str(line);		//#include<sstream>

			Student student=Student::read(str);
			students.insert(std::pair<int,Student>(student.getMatrikelNumber(),
					student));
			//students[student.getMatrikelNumber()]=student;
		}
	}
}

void StudentDb::readCourses(std::istream &in) {			// read
	std::string line;
	std::string linecopy;
	std::string count;
	getline(in,count);
	if(!count.empty()) {
		int courseCount=std::stoi(count);

		for(int i=0;i<courseCount;i++) {
			getline(in,line);
			linecopy=linecopy+line+"\n";	//copy line string
			std::istringstream istrg(line);

			std::unique_ptr<Course> course = Course::read(istrg);
			if(course != 0) {
				addCourse(std::move(course));
			}
		}
	}
	//there there is no course in file
	if(courses.size()==0) {
		std::string linestr = count + "\n" + linecopy;
		//stream copied string and readstudents
		std::istringstream istrg1(linestr);
				readStudents(istrg1);
	}
}

void StudentDb::readEnrollments(std::istream &in)			// read
{
	std::string line,str_matrikelNumber;
	std::string count;

	getline(in,count);

	if(!count.empty()) {
		int courseCount=std::stoi(count);
		int i=0;
		while(i<courseCount) {

			getline(in,str_matrikelNumber,';');

			unsigned int matrikelNumber = stoi(str_matrikelNumber);
			auto itr = this->students.find(matrikelNumber);
			std::getline(in,line);
			if(matrikelNumber==itr->second.getMatrikelNumber()) {

				for(auto& course_itr : courses) {

					const Course& courseref = *(course_itr.second.get());

					std::istringstream iss(line);

					Enrollment enrollment= Enrollment::read(iss,&courseref);

					if(enrollment.getCourse() != 0) {

						itr->second.addEnrollment(Enrollment(
								enrollment.getCourse(),enrollment.getSemester(),
								enrollment.getGrade()));
						i++;
					}
				}
			}
		}
	}
}

//												//	read from server

void StudentDb::readStudentsFromServer(unsigned int noOfStudent) {
	std::string hostname = "www.hhs.users.h-da.cloud";
	std::string port = "4242";
	boost::asio::ip::tcp::iostream stream;
	namespace pt = boost::property_tree;

	stream.connect(hostname,port);
	if(stream) {
		for(unsigned int i=0;i<noOfStudent;i++) {
			std::string line1,line2,line3;

			stream << "generate" << std::endl;
			std::getline(stream,line1);
			std::getline(stream,line2);
			std::getline(stream,line3);
			stream.flush();

			pt::ptree root;
			std::istringstream jsonStream(line2);
			pt::read_json(jsonStream, root);

			std::string firstName = root.get<std::string>("name.firstName", "");
			std::string lastName = root.get<std::string>("name.lastName", "");
			std::string day = root.get<std::string>("dateOfBirth.date", "");
			std::string month = root.get<std::string>("dateOfBirth.month", "");
			std::string year = root.get<std::string>("dateOfBirth.year", "");
			std::string street = root.get<std::string>("location.street", "");
			std::string postalCode = root.get<std::string>("location.postCode",
					"");
			std::string cityName = root.get<std::string>("location.city", "");
			std::string additionalInfo = root.get<std::string>("location.state",
					"");

			if(validString(firstName) && validString(lastName) &&
					validdigits(day) && validdigits(month) &&
					validdigits(year) && validString(street) &&
					validString(cityName) && validString(additionalInfo) &&
					validdigits(postalCode) ) {

				Student student(firstName,lastName, Poco::Data::Date(
						std::stoi(year)+1900,std::stoi(month)+1,std::stoi(day)),
						Address(street,std::stoi(postalCode),cityName,
								additionalInfo));

				addStudent(student);
			}
		}
	}
	stream << "quit" << std::endl;
	stream.flush();
}

bool StudentDb::validString(const std::string &inputstring) {

	if(all_of(inputstring.begin(),inputstring.end(), ::isprint)) {
		return true;
	} else {
		return false;
	}
}

bool StudentDb::validdigits(std::string &str) {
    return std::all_of(str.begin(), str.end(), [](unsigned char c) {
        return std::isdigit(c);
    });
}

