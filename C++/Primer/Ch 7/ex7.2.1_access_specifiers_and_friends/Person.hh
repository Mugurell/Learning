#ifndef _PER_SON_
	#define _PER_SON_

	#include <iostream>
	#include <string>
	

	class Person {
	public: // - access specifier
		// lots of constructors
		Person() = default;
		Person(std::string n, std::string a) : name(n), address(a) { }
		Person(std::string n) : name(n) { }
		Person(std::istream&);		// need read() which will be defined later. 

	private: // - access specifier
		std::string& getName() { return name; }
		std::string& getAddress() { return address; }
		std::string name;
		std::string address;

	// declare non-member functions as friends so they could
	// access the variables declared in the class
	friend std::istream& read(std::istream&, Person&);
	friend std::ostream& print(std::ostream&, const Person&);
	};


	// non-member functions
	// friend functions
	std::istream&
	read(std::istream &is, Person &pers) {
		is >> pers.name >> pers.address;
		return is;
	}

	std::ostream&
	print(std::ostream &os, const Person &pers) {
		os << pers.name << " who lives in " << pers.address;
		return os;
	}


	// constructor definition
	Person::Person(std::istream &is) { read(is, *this); }


#endif