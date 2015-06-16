#include <stdio.h>

int main ()
{
	int alpha , beta;
	
	alpha=5;
	//beta = alpha ++;    //beta=alpha . alpha e +1dar separat, in alt context...
	beta = alpha--;       //alpha a fost intai scazuta si mai apoi voloarea ++ a fost stocata in alpha
	
	printf("alpha = %d\n" , alpha);
	printf("alpha 2 = %d\n" , alpha);  //nu mai adauga  +1...alpha++ are efect doar o data. Intr-un loop adaugarea( ex c= c +1) se face de mai multe ori pe rand
	printf("beta = %d\n" , beta);
	
	return(0);
	
	}