

/******************************************************************************
******* Sa zicem ca vrem sa returnam un pointer catre un array de 10 int ******
************ Sau o referinta. Same thing. Replace '*' with '&' ****************
*******************************************************************************

 declaratia normala
	int (*func(int i))[10];		// func takes an int - i  as an argument
								// and returns a pointer to an array of 10 ints

1) simplificam folosing typedef/using
	typedef int arrT[10];
	using arrT = int[10];

	arrT * func(int i);


************** De aici sunt numai solutii bazate pe c++11 *********************

2) folosim un trailing return
	auto func(int i) -> int(*)[10];


3) folosim decltype daca stim dinainte ce tip de array retuneaza functia
Ex: 
	int odd[] = {1,3,5,7,9};
	int even[] = {0,2,4,6,8};
	// returns a pointer to an array of five int elements
	decltype(odd) * func(int i)
	{
		return (i % 2) ? &odd : &even; // returns a pointer to the array
	}