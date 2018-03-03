/*
	Read in and compute the greatest common divisor (GCD) of two natural numbers using recursion.
	GCD(x, y) is the greatest natural number which divides both x and y
	- GCD(6, 7) = 1
	- GCD(6, 9) = 1
	- GCD(6, 0) = 1
	Note that your program should contain
	- a main function, which does IO
	- and a recursive function, int GCD(int x, int y), which computes the GCD of x and y.
*/
#include <stdio.h>

int GCD(int x, int y);

int main(){
	int user_input_x = 0, user_input_y = 0;
	printf("Please input the first positive integer: ");
	scanf("%d", &user_input_x);
	printf("Please input the second positive integer: ");
	scanf("%d", &user_input_y);
	printf("%d\n", GCD(user_input_x, user_input_y));
	return 0;
}

int GCD(int x, int y){
	if (y == 0){
		return x;
	}
	return GCD(y, x % y);
}