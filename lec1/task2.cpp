/*
Read in and reverse a string using recursion.
Note that your program should contain:
- a main function, which does IO
- and a recursive function as follows, which reverses the string

void reverseR (int length, char *str){
...
}

assume that the string size is less than 50
*/
#include <stdio.h>
#include <string.h>

void reverseR(int length, char *str);

int main() {
	char user_input[51];
	int input_size = 0;
	printf("Please input a string: ");
	scanf("%s", user_input);
	input_size = strlen(user_input);
	reverseR(input_size, user_input);
	printf("Reverse result: %s\n", user_input);
	return 0;
}

void reverseR(int length, char *str) {
	int real_length = strlen(str);
	char temp;
	if (length <= 1) {
		return;
	}
	if (real_length - length + 1 == length - 1) { // when string length is even
		temp = str[real_length - length];
		str[real_length - length] = str[length - 1];
		str[length - 1] = temp;
		return;
	}
	if (real_length - length == length - 1) { // when string length is odd
		return;
	}
	temp = str[real_length - length];
	str[real_length - length] = str[length - 1];
	str[length - 1] = temp;
	reverseR((length - 1), str);
	return;
}