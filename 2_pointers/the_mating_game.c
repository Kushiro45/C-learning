#include <stdio.h>

int main(){
	int contestants[] = {1, 2, 3};
	int *choice = contestants /* choice points to address of 1st char i.e. 1 */
	contestants[0] = 2;
	/* new array {2, 2, 3}
	     choice---^   */
	contestants[1] = contestants[2];
	/* new array {2, 3, 3}
             choice---^   */
	contestants[2] = *choice;
	/* new array {2, 3, 2}
             choice---^   */
	printf("Im going to pick contestant %i", contestants[2]);
	return 0;
}
