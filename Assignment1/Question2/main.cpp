#include "bracket.h"
#include <stdio.h>
#include <string.h>

int main(){
	char testcase1[] = "{()}";
	char testcase2[] = "([)]";
	char testcase3[] = "{()}[";
	char testcase4[] = "";
	if (ValidBrackets(testcase1)){
		printf("case1, true\n");
	}else{
		printf("case1, false\n");
	}
	if (ValidBrackets(testcase2)){
		printf("case2, true\n");
	}else{
		printf("case2, false\n");
	}
	if (ValidBrackets(testcase3)){
		printf("case3, true\n");
	}else{
		printf("case3, false\n");
	}
	if (ValidBrackets(testcase4)){
		printf("case4, true\n");
	}else{
		printf("case4, false\n");
	}
	if (ValidBrackets(NULL)){
		printf("case5, true\n");
	}else{
		printf("case5, false\n");
	}
	return 0;
}

bool ValidBrackets(char* str){
	int inputsLength = 0;
	if (str == NULL){ // if the input is NULL, return false
		return false;
	}else{
		inputsLength = strlen(str); // get the length of the string
	}

	if(inputsLength % 2 != 0){ // the string length must be even (The brackets must match & close)
		return false;
	}

	for (int i = 0, j = inputsLength - 1; i < (int)(inputsLength / 2); i++, j--){
		switch(str[i]){
		case '(':
			if(str[j] != ')'){
				return false;
			}
			break;
		case '[':
			if(str[j] != ']'){
				return false;
			}
			break;
		case '{':
			if(str[j] != '}'){
				return false;
			}
			break;
		default:
			return false;
		}
	}
	return true;
}