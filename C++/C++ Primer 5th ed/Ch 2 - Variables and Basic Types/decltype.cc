/*
** It's a new type specifier introduced by C++11.
** decltype (x) returns the type of it's operand - x.
** including (if it's the case) the top-level const/references.
** So it return in full, exactly the identical type of its operand.
*/

decltype (f()) sum = x;
	/* f is a function with a particular returning type
	** here, f() is not called but decltype will give sum
	** the type that f() returns and then initialize it. */


const int ci = 0, &ri = ci;
decltype(ci) x = 0;		// x is a const int;
decltype(ri) y = x;		// y is a const int& bound to x;
decltype(ri) z;			// error: z is const int& -> must be initialized;


int i = 42, *p = &i, &r = i;
decltype(r+0) b;		// b is an unitialized int;
decltype(*p) c;			// error: c is a int& and must be initialized;
						//dereferencing *p gives and int. Because we can
						//assign to *p, decltype gives an int*.
decltype(p) d;			// d is a pointer to int;


// decltype of a parantheized variable is always a reference!
decltype((i)) = e;		// error: e is a int& so should be intialized;
decltype(i) = f;		// ok, f is an unitialized int;


/*
** So, decltype returns a reference in 3 cases:
** 1) if it has a ref as argument: 			decltype(r);
** 2) if it has a dereferenced pointer: 	decltype(*p);
** 3) if it's arguments is a plain variable,
** 		but in doubled paranthesys:			decltype((i));
** 4) if it's arguments is an assignement, i will return a referince
** 		to the left-hand operand. So:
** 				int a, b;					decltype(a = b);
**		Will return an int&.
**
** In all of this cases it gives and int&
*/