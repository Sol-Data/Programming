/*
Name : login.c
*/

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1 //declaration of symbol constants
#define FAIL 2
#define LIMIT 3
int check(int id, int password); //Function Definition
int main(void)
{
	int id, password, result;

	while (1) {
		printf("id(4 digits) : ");
		scanf("%d", &id);
		printf("pass(4 digits): ");
		scanf("%d", &password);
		result = check(id, password);
		if (result == SUCCESS) break;
	}
	printf("login successful\n");
	return 0;
}

int check(int id, int password)
{

	static int super_id = 1234;
	static int super_password = 5678;
	static int try_count = 0;

	try_count++;
	if (try_count >= LIMIT) {
		printf("Over Count\n");
		exit(1); //Exit Program
}
	if (id == super_id && password == super_password)
		return SUCCESS;
	else
		return FAIL;
}
