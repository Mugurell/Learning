
#include "Car.cc"

int main()
{
	// because the constructor that takes just a string as a parameter
	// is explicit, means that only direct initialization will work.
	// The explicit keyword prevents implicit conversion.
	std::string buba = "Ferrari";
	//Car mazda = buba;		//- this don't work with an explicit constructor
	// Nu se poate face decat o conversie. In cazul asta std::string -> Car.
	// Daca puneam doar "Lambo" trebuie convertit din string literal in
	// std::string, apoi in Car. Hence..:
	Car mazda (static_cast<std::string>("Lambo")); // Car mazda("Lambo");
	Car dacia ("dacia", 3, 5, 5, 2, 1);
	Car Mertzsz ("Mertzsz", 5, 5, 6, 3, 3);


	std::cout << "\n\n";


	dacia.show_properties(std::cout);

	dacia.start();
	dacia.stop();


	mazda.show_properties(std::cout);

	Mertzsz.show_properties(std::cout);
	Mertzsz.start();


	//mazda.showproperties(buba);

	Car::ask();

	std::cout << '\n' << std::endl;
	return 0;
}