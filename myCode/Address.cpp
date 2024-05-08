//
//#include<string>
//#include <sstream>
//
//class Address {
//
//	std::string street;
//
//	unsigned int postalCode;
//
//	std::string cityName;
//
//	std::string additionalInfo;
//
//public:
//
//	Address(std::string street, unsigned int postalCode, std::string cityName,
//			std::string additionalInfo );
//
//	~Address();
//
//	Address();
//
//	const std::string& getAdditionalInfo() const;
//
//	const std::string& getCityName() const;
//
//	unsigned int getPostalCode() const;
//
//	const std::string& getStreet() const;
//
//	void write(std::ostream &out) const;
//
//	static Address read(std::istream& in);
//
//};

#include "Address.h"
#include<vector>

Address::Address(std::string street, unsigned int postalCode,
		std::string cityName, std::string additionalInfo) : street{street} ,
				postalCode{postalCode}, cityName{cityName},
				additionalInfo{additionalInfo} {
}

const std::string& Address::getAdditionalInfo() const {
	return additionalInfo;
}

const std::string& Address::getCityName() const {
	return cityName;
}

unsigned int Address::getPostalCode() const {
	return postalCode;
}

Address::Address() {
}

const std::string& Address::getStreet() const {
	return street;
}

Address::~Address()
{
	// TODO Auto-generated destructor stub
}

void Address::write(std::ostream &out) const {
	out<<street+";";
	out<<std::to_string(postalCode)+";";
	out<<cityName+";";
	out<<additionalInfo;
}

Address Address::read(std::istream &in) {

	std::string line;
	std::vector<std::string> linedata;

	while(getline(in,line,';')) {
		linedata.push_back(line);
	}

	std::string street;
	unsigned int postalCode;
	std::string cityName;
	std::string additionalInfo="";

	street=linedata.at(0);
	postalCode=std::stoi(linedata.at(1));
	cityName=linedata.at(2);
	if(linedata.size()==4) {

		additionalInfo=linedata.at(3);
	}

	return Address(street,postalCode,cityName,additionalInfo);

}
