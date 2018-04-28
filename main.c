/* 
References
https://www.slideshare.net/amritayan/test-driven-development-in-c
https://stackoverflow.com/questions/9655202/how-to-convert-integer-to-string-in-c
https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void test_nothing(void){
    assert(false && "My first unit test");
}

void init(void){
    time_t t;
	srand((unsigned) time(&t));
	test_nothing();
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
