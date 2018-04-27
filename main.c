/* 
References
https://stackoverflow.com/questions/9655202/how-to-convert-integer-to-string-in-c
https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void init(){
    time_t t;
	srand((unsigned) time(&t));
}

int main(){
	init();

    int NUM_WHEELS = 3;
	int WHEELS[NUM_WHEELS];

	for(int i = 0 ; i < NUM_WHEELS ; i++ ) {
	    WHEELS[i] = rand() % 4;
	}
    printf("%d %d %d\n", WHEELS[0], WHEELS[1], WHEELS[2]);

    return(0);
}
