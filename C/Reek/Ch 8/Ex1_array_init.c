/* Write a declaration for an array that initializes certain locations 
of the array to specific values. The array should be called char_values
and contain 3 × 6 × 4 × 5 unsigned characters. 
The following locations should be statically initialized to 
these values: 
_______________________________________________________________ 
  Loc     Value   |     Loc     Value    |     Loc     Value
---------------------------------------------------------------
1,2,2,3    'A'    |   1,1,1,1    ' '     |   1,3,2,2    0xf3
2,4,3,2    '3'    |   1,4,2,3    '\n'    |   2,2,3,1   '\121'
2,4,3,3     3     |   2,5,3,4    125     |   1,2,3,4     'x'
2,1,1,2   0320    |   2,2,2,2   '\''     |   2,2,1,1     '0'
__________________|______________________|_____________________
*/

#include <stdio.h>

int main(void)
{
	static unsigned char char_values[3][6][4][5] = {
		{/* 0 */
			{/* 0,0 */
				{ 0 },
			}
		},
		{/* 1 */
			{/* 1, 0 */
				{ 0 }
			},
			{/* 1, 1 */
				{ 0 },
				{ 0, ' '}
			},
			{/* 1, 2 */
				{ 0 },
				{ 1 },
				{ 0, 0, 0, 'A'},
				{ 0, 0, 0, 0, 'x'}
			},
			{/* 1, 3 */
				{ 0 },
				{ 0 },
				{ 0, 0, 0363 }
			},
			{/* 1, 4 */
				{ 0 },
				{ 0 },
				{ 0, 0, 0, '\n'}
			}
		},
		{/* 2 */
			{/* 2,0 */
				{ 0 }
			},
			{/* 2,1 */
				{ 0 },
				{ 0, 0, 0320}
			},
			{/* 2, 2 */
				{ 0 },
				{ 0, '0'},
				{ 0, 0, '\''},
				{ 0, '\121'}
			},
			{/* 2,3 */
				{ 0 }
			},
			{/* 2, 4 */
				{ 0 },
				{ 0 },
				{ 0 },
				{ 0 , 0, '3', 3}
			},
			{/* 2,5 */
				{ 0 },
				{ 0 },
				{ 0 },
				{ 0, 0, 0, 0, ')'}
			}
		},
	};

	return 0;
}