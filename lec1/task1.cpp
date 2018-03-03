/*
	Reading a positive number and compute its factorial using recursion.
	Note that your program should contain:
		- a main function, which does IO
		- and a recursive functionm long int factR(int n), which computes the factorial
*/
#include <stdio.h>

long int factR(int n);

int main() {
	int user_input = 0;
	printf("Please input a positive integer: ");
	scanf("%d", &user_input);
	printf("Factorial of %d = %ld\n", user_input, factR(user_input));
	return 0;
}

long int factR(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 1;
	}
	return (n * factR(n - 1));
}