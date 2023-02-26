//functions for factorial and gcd script
//contributors: Anthony
//progress: complete

int factorial(int factorialInput) {
    int factorialSum = 1;  //used to save the sum of the factorial

    while (factorialInput > 0) {
        factorialSum = factorialSum*factorialInput;
        factorialInput = factorialInput-1;}

return factorialSum; }

int gcd(int gcdInput1, int gcdInput2) {
    int tempVarToSwap;  //variable used to temprararly store the value of gcdInput1 to swap with gcdInput2

    while (gcdInput1 != gcdInput2){
        if (gcdInput1 < gcdInput2){
            tempVarToSwap = gcdInput1;
            gcdInput1 = gcdInput2;
            gcdInput2 = tempVarToSwap;}
        if (gcdInput1 > gcdInput2){
            gcdInput1 = gcdInput1-gcdInput2;} }

return gcdInput1; }
