#include <stdio.h>
#include <hfcal.h>

void display_calories(float weight, float distance, float coeff){
	printf("Weight: %3.2f lbs\n", weight); /*in pounds*/
	printf("Distance: %3.f miles\n", distance); /*in miles*/
	printf("Calories burned: %4.2f cal\n", coeff * weight * distance);
}
