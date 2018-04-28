/* 
References
http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
https://www.slideshare.net/amritayan/test-driven-development-in-c
https://stackoverflow.com/questions/9655202/how-to-convert-integer-to-string-in-c
https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
*/

#include "slots.h"

void init(void){
    time_t t;
	srand((unsigned) time(&t));

	runTestSuite();
}

int getWheelValue(){
    return -1;
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

// ---------------------------------------------------------------------------------------------------------------------

void test_spinWheel(void){
    int wheelValue = getWheelValue();
    assert(-1 == wheelValue);
}

void runTestSuite(void){
    printf("running unit test suite...");
    test_spinWheel();
    printf(" done\n");
}
