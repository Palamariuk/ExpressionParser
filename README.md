# ExpressionParser

Prints: 

1.	-4.32 ^ 3 + 2.25 * 4 - ( ( -3 - 4 ) + ( 2 - 10 * 0.3 ) ) / 7  = -70.4787
	Reverse polish notation: -4.32 3 ^ 2.25 4 * -3 4 - 2 10 0.3 * - + 7 / - + 
2.	1 + 3  = 4
	Reverse polish notation: 1 3 + 
3.	2 + 2 * 2  = 6
	Reverse polish notation: 2 2 2 * + 
4.	( 2 + 2 ) * 2  = 8
	Reverse polish notation: 2 2 + 2 * 
5.	-56 * 0.25  = -14
	Reverse polish notation: -56 0.25 * 
6.	2 ^ 2 ^ 2 ^ 2  = 256
	Reverse polish notation: 2 2 ^ 2 ^ 2 ^ 
7.	12 + 2 * ( ( 3 * 4 ) + ( 10 / 5 ) )  = 40
	Reverse polish notation: 12 2 3 4 * 10 5 / + * + 
8.	3 + 4 * 2 / ( 1 - 5 ) ^ 2  = 3.5
	Reverse polish notation: 3 4 2 * 1 5 - 2 ^ / + 
9.	1 / 9  = 0.111111
	Reverse polish notation: 1 9 / 
10.	-1 + ( -5 ) * ( 2 - ( 2 / 5 ) )  = -9
	Reverse polish notation: -1 -5 2 2 5 / - * + 
11.	45 * 789 + 78 ^ ( 1 / 6 + 6 / 8 )  = 35559.3
	Reverse polish notation: 45 789 * 78 1 6 / 6 8 / + ^ + 
12.	897 / 78 + 453 ^ ( -0.5 )  = 11.547
	Reverse polish notation: 897 78 / 453 -0.5 ^ + 
13.	( 343 * ( -89 ) + 18 ) - 12 ^ 2.9  = -31856.8
	Reverse polish notation: 343 -89 * 18 + 12 2.9 ^ -
