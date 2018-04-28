/* 
References
http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
https://www.slideshare.net/amritayan/test-driven-development-in-c
https://stackoverflow.com/questions/9655202/how-to-convert-integer-to-string-in-c
https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
*/

#include "slots.h"

void init(void){
	runTestSuite();

    time_t t;
	srand((unsigned) time(&t));
}

int getWheelValue(){
    return rand() % 4;
}

int main(){
	init();

    printf("%d %d %d\n", getWheelValue(), getWheelValue(), getWheelValue());

    return(0);
}

// ---------------------------------------------------------------------------------------------------------------------

void test_spinWheel(void){
    assert(getWheelValue() == 2);
    assert(getWheelValue() == 3);
    assert(getWheelValue() == 3);
}

void runTestSuite(void){
    printf("running unit test suite...");
    srand(1234);
    test_spinWheel();
    printf(" done\n");
}
