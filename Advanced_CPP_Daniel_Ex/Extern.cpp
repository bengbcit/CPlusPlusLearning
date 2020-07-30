#include <stdio.h>
/*	The extern keyword tells the compiler that a variable is defined in another source module 
	(outside of the current scope). Variables described by extern statements will not have any space
	allocated for them, as they should be properly defined elsewhere.*/
extern int x = 32;
int y = 111;
int b = 8;
int main() {
	extern int b;
	printf("The value of extern variables x, y and b : %d,%d,%d\n", x, y,b);

	x = 15;
	y = 100;
	b = 9;
	printf("The value of modified extern variable x y and b : %d,%d,%d\n", x,y,b);
	return 0;
}