/* 
References
http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
https://www.slideshare.net/amritayan/test-driven-development-in-c
https://stackoverflow.com/questions/1102542/how-to-define-an-enumerated-type-enum-in-c
https://stackoverflow.com/questions/9655202/how-to-convert-integer-to-string-in-c
https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
https://www.tutorialspoint.com/cprogramming/c_structures.htm
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

char getWheelSymbolByInteger(int valueAsInt){

    char wheelSymbols[] = {'x', '7', 'a', 'b'};
    return wheelSymbols[valueAsInt];
}

int main(int argc, char *argv[]){
	init();

    printf("%d %d %d\n", getPseudorandomIntegerForWheel(), getPseudorandomIntegerForWheel(), getPseudorandomIntegerForWheel());

    return(0);
}

// ---------------------------------------------------------------------------------------------------------------------

void test_getPseudorandomIntegerForWheel(void){
    srand(1234);

    assert(2 == getPseudorandomIntegerForWheel());
    assert(3 == getPseudorandomIntegerForWheel());
    assert(3 == getPseudorandomIntegerForWheel());
    assert(3 == getPseudorandomIntegerForWheel());

    assert(0 == getPseudorandomIntegerForWheel());
    assert(1 == getPseudorandomIntegerForWheel());
    assert(3 == getPseudorandomIntegerForWheel());
    assert(2 == getPseudorandomIntegerForWheel());
}

void test_getWheelSymbolByInteger(void){
    assert('x' == getWheelSymbolByInteger(0));
    assert('7' == getWheelSymbolByInteger(1));
    assert('a' == getWheelSymbolByInteger(2));
    assert('b' == getWheelSymbolByInteger(3));
}

void runTestSuite(void){
    printf("running unit test suite...");
    test_getPseudorandomIntegerForWheel();
    test_getWheelSymbolByInteger();
    printf(" done\n");
}
