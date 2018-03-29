#include "stack.h"
#include <stdio.h>


int main(void) {
	char testCase1[] = "";
	char testCase2[] = "abc";
	char testCase3[] = "a11[c]d";
	char testCase4[] = "3[a]2[bc]";
	char testCase5[] = "3[a2[c]]";
	char testCase6[] = "2[abb3[cd]]ef";
	printf("%s\n", Uncompress(NULL));
	printf("%s\n", Uncompress(testCase1));
	printf("%s\n", Uncompress(testCase2));
	printf("%s\n", Uncompress(testCase3));
	printf("%s\n", Uncompress(testCase4));
	printf("%s\n", Uncompress(testCase5));
	printf("%s\n", Uncompress(testCase6));
	return 0;
}