#ifndef ADDRESS_H_
#define ADDRESS_H_
//#include<iostream>
#include<string>
#include <sstream>
//#include <memory>
/**
 * @class Address
 * @brief Represent address of the student
 *
 */
class Address {

	/**
	 * @brief street of address
		 */
	std::string street;

	/**
	 * @brief postalcode of address
		 */
	unsigned int postalCode;

	/**
	 * @brief city name of the address
		 */
	std::string cityName;

	/**
	 * @brief additionalinfo of address
		 */
	std::string additionalInfo;

public:

	/**
		 * @fn  Address(std::string, unsigned int, std::string, std::string)
	 * @brief parameterised Constructor for class
	 *
	 * @param street
	 * @param postalCode
	 * @param cityName
	 * @param additionalInfo
	 */
	Address(std::string street, unsigned int postalCode, std::string cityName,
			std::string additionalInfo );

	/**
		 * @fn  ~Address()
	 * @brief destructor of class
	 *
	 */
	~Address();

	/**
		 * @fn  Address()
	 * @brief default constructor of class
	 *
	 */
	Address();

	/**
		 * @fn const std::string getAdditionalInfo&()const
	 * @brief getter for additional info
	 *
	 * @return
	 */
	const std::string& getAdditionalInfo() const;

	/**
		 * @fn const std::string getCityName&()const
	 * @brief getter for city name
	 *
	 * @return
	 */
	const std::string& getCityName() const;

	/**
		 * @fn unsigned int getPostalCode()const
	 * @brief getter for postal code
	 *
	 * @return
	 */
	unsigned int getPostalCode() const;

	/**
		 * @fn const std::string getStreet&()const
	 * @brief getter for street name
	 *
	 * @return
	 */
	const std::string& getStreet() const;

	/**
		 * @fn void write(std::ostream&)const
	 * @brief for writing data to txt or csv file
	 *
	 * @param out
	 */
	void write(std::ostream &out) const;

	/**
		 * @fn Address read(std::istream&)
	 * @brief for reading data from csv or txt file
	 *
	 * @param in
	 * @return
	 */
	static Address read(std::istream& in);

};

#endif /* ADDRESS_H_ */
