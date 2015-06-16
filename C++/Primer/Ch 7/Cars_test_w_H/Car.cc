#include "Car.hh"

	Car::Car() {
		nume = "???";
		roti = 0;
		usi = 0;
		lungime = 0;
		latime = 0;
		greutate = 0;
	}

	Car::nr Car::count = 1;

	// Car::Car() = default;
	Car::Car(std::string n, nr roti, nr usi, nr lungime, nr latime, nr
	greutate) {
		this->nume = n;
		this->roti = roti;
		(*this).usi = usi;
		this->lungime = lungime;
		this->latime = latime;
		this->greutate = greutate;
		count++;
	}

	//Car::Car(std::string n): nume(n) { }

	bool
	Car::start() {
		std::cout << "The car " << count << " has started.\n\n";
		return true;
	}


	bool 
	Car::stop() {
		std::cout << "The car " << count << " has stopped.\n\n";
		return true;
	}


	void 
	Car::show_properties(std::ostream &os) {
		os << "nume \t -\t" << nume << "\n\t"
			<< "roti \t -\t" << roti << "\n\t"
			<< "usi \t -\t" << usi << "\n\t"
			<< "lungime  -\t" << lungime << "\n\t"
			<< "latime   - \t" << latime << "\n\t"
			<< "greutate - \t" << greutate << "\n\n";
	}

	void
	Car::showproperties(Car &machina) {
		std::cout << "nume \t -\t" << machina.nume << "\n\t"
				 << "roti \t -\t" << machina.roti << "\n\t"
				 << "usi \t -\t" << machina.usi << "\n\t"
				 << "lungime  -\t" << machina.lungime << "\n\t"
				 << "latime   - \t" << machina.latime << "\n\t"
				 << "greutate - \t" << machina.greutate << "\n\n";
	}

	void
	Car::ask() {
		std::cout << "How many are there like you?" << std::endl;
		std::cout << count << " cars.\n\n";
	}