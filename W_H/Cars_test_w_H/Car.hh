#ifndef CAR_HH
	#define CAR_HH

	#include <string>
	#include <iostream>

	class Car {
	public:
		typedef unsigned nr;
		Car();

		// converting constructor. Will be called with either direct
		// initialization ( () / {} ) or copy initialization ( = ).
		Car(std::string n, nr r, nr u, nr L, nr l, nr g);
		// explicit constructor. Will be considered only with direct
		// initialization ( () / {} ). See main.
		explicit Car(std::string s): nume(s) {}

		bool start();
		bool stop();
		void show_properties(std::ostream&);
		void showproperties(Car&);
		static void ask();
	private:
		static nr count;
		std::string nume;
		nr roti;
		nr usi;
		nr lungime;
		nr latime;
		nr greutate;
	};

#endif