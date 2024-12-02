/*
Name : car_racing.c
*/

#include <stdlib.h> //include standard library function
#include <stdio.h>
#include <time.h> //include time function

void disp_car(int car_number, int distance);//Function Definition

int main(void)
{
	int i;
	int car1_dist = 0, car2_dist = 0; // initialize distance

	srand((unsigned)time(NULL)); //seed Occurrence


	for (i = 0; i < 5; i++) { //5 iterations
		car1_dist += rand() % 100; //Determine car mileage in random numbers
		car2_dist += rand() % 100;
		disp_car(1, car1_dist); //call the Display Progress function
		disp_car(2, car2_dist);

	printf("---------------------\n");
	_getch(); //Function waiting for user keystroke
	}
	return 0;
}

void disp_car(int car_number, int distance)
{
	int i;

	printf("CAR #%d:", car_number);
	for (i = 0; i < distance / 10; i++) { //Repeat Driving Indication
		printf("*"); //Drive Indication
	}
	printf("\n");
}
