/* An identity matrix is a square matrix whose values are all zero 
except for those on the main diagonal, which are one. For example: 
1  0  0
0  1  0
0  0  1

is a 3 × 3 identity matrix. Write a function called identity_matrix 
that takes a 10 × 10 matrix of integers as its only argument and returns
a boolean value indicating whether the matrix is an identity matrix. 
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int identity_matrix(const char matrix[10][10]);

int main(void)
{
}

int identity_matrix(const char matrix[10][10])
{
    int row;
    int column;

    /*
	** Go through each of the matrix elements
	*/
    for (row = 0; row < 10; row += 1) {
        for (column = 0; column < 10; column += 1) {
            /*
        	** If the row number is equal to the column number,
        	** the value should be 1, else 0
        	*/
            if (matrix[row][column] != (row == column))
                return FALSE;
        }
    }
    return TRUE;
}