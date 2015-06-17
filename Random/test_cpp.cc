#include <iostream>

// using std::cout;
using namespace std;

#define LINUX

int main()
{
	const char *ptr2c = "Yo sunt Mugurel yo!";
	double dvar = 3.14;
	int ivar = 99;
	char cvar = 99;
	float ifsd = 324567.4365;

	cout << "Floatul are " << sizeof(float) << "\nDouble - " \
		  << sizeof(double) << "\nLong double - " << sizeof(long double) \

		  << "\nint - " << sizeof(int) << "\n Long - " << sizeof(long) \
		  << "\nLong long - " << sizeof(long long) << endl;

	cout << "\nStringul e " << ptr2c << ".\nDoubleul e " << dvar \
		 << ".\nIntul e " << ivar << ".\nCharul e " << cvar << endl;  


#ifdef LINUX
cout << "This is Linux!" << endl;
#elif Android
cout << "This is Android!" << endl;
#endif



	return 0;
}

