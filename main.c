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
    int numSymbols = 4;
    char wheelSymbols[] = {
        SYMBOL_MISS,
        SYMBOL_JACKPOT,
        SYMBOL_BELL,
        SYMBOL_CHERRY
    };
    if(valueAsInt > -1 && valueAsInt < numSymbols){
        return wheelSymbols[valueAsInt];
    }
    return SYMBOL_MISS;
}

char* evaluateDisplayedSymbols(char a, char b, char c){
    return "";
}

int main(int argc, char *argv[]){
	init();

	int a = getPseudorandomIntegerForWheel();
	int b = getPseudorandomIntegerForWheel();
	int c = getPseudorandomIntegerForWheel();

    printf("%c %c %c\n", getWheelSymbolByInteger(a), getWheelSymbolByInteger(b), getWheelSymbolByInteger(c));

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
    assert(SYMBOL_MISS == getWheelSymbolByInteger(0));
    assert(SYMBOL_JACKPOT == getWheelSymbolByInteger(1));
    assert(SYMBOL_BELL == getWheelSymbolByInteger(2));
    assert(SYMBOL_CHERRY == getWheelSymbolByInteger(3));
}

void test_getWheelSymbolByInteger_InvalidInput(void){
    assert(SYMBOL_MISS == getWheelSymbolByInteger(-1));
    assert(SYMBOL_MISS == getWheelSymbolByInteger(4));
    assert(SYMBOL_MISS == getWheelSymbolByInteger(5));
    assert(SYMBOL_MISS == getWheelSymbolByInteger(9999));
    assert(SYMBOL_MISS == getWheelSymbolByInteger(INT_MAX));
    assert(SYMBOL_MISS == getWheelSymbolByInteger(INT_MIN));

}

void test_evaluateDisplayedSymbols(void){
    char *actualMessage_Jackpot = evaluateDisplayedSymbols(SYMBOL_JACKPOT, SYMBOL_JACKPOT, SYMBOL_JACKPOT);
    assert(0 == strcmp("", actualMessage_Jackpot));

}

void runTestSuite(void){
    printf("running unit test suite...");
    test_getPseudorandomIntegerForWheel();
    test_getWheelSymbolByInteger();
    test_getWheelSymbolByInteger_InvalidInput();
    test_evaluateDisplayedSymbols();
    printf(" done\n");
}
