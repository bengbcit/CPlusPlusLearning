#include <stdio.h>
extern int x = 32;
int b = 8;
int main() {
	extern int b;
	printf("The value of extern variables x and b : %d,%d\n", x, b);
	x = 15;
	printf("The value of modified extern variable x : %d\n", x);
	return 0;
}