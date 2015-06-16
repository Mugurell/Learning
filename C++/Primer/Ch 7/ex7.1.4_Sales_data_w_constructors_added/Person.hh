#ifndef _PERSON_
	#define _PERSON_

	#include <iostream>
	#include <string>

	struct Person {
		std::string name;
		std::string address;

		Person() = default;
		//Person(std::string n, std::string a): name(n), address(a) { }
		// Equivalent to
		Person(std::string n, std::string a) {
			this->name = n;
			address = a;	// apparently 'this->' is not necessary
							// it is implicitly used
		};

		Person(std::istream &is);
		
		std::string& getName() { return name; }
		std::string& getAddress() { return address; }
	};

	// non member functions
	std::ostream&
	print(std::ostream &os, const Person pers) {
		os << pers.name << " which lives in " << pers.address << std::endl;
		return os;
	}

	std::istream&
	read(std::istream &is, Person &pers) {
		is >> pers.name >> pers.address;
		return is;
	}


	// constructors definition
	// (trebuie definit aici pt ca read sa fie definit mai inainte)
	// altfel -> compile error: 'read' was not declared in this scope.
	Person::Person(std::istream &is)
	{
		read(is, *this); // read will read a transaction from is into this object
						 // will initialize *this with user supplied data.
	}
#endif