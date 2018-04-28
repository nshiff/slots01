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

int getPseudorandomIntegerForWheel(){
    return rand() % 4;
}

int main(){
	init();

    printf("%d %d %d\n", getPseudorandomIntegerForWheel(), getPseudorandomIntegerForWheel(), getPseudorandomIntegerForWheel());

    return(0);
}

// ---------------------------------------------------------------------------------------------------------------------

void test_getPseudorandomIntegerForWheel(void){
    assert(2 == getPseudorandomIntegerForWheel());
    assert(3 == getPseudorandomIntegerForWheel());
    assert(3 == getPseudorandomIntegerForWheel());
}

void runTestSuite(void){
    printf("running unit test suite...");
    srand(1234);
    test_getPseudorandomIntegerForWheel();
    printf(" done\n");
}
