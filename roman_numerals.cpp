#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std; //declaring a namespace (std)

int main(){
    int numberentered; //declaring a variable
    cout << "Enter a number (1-10):";
    cin >> numberentered;
    switch(numberentered){ //checking various values
        case 1: cout << "The roman numeral is I." << endl; break;
        case 2: cout << "The roman numeral is II." << endl; break;
        case 3: cout << "The roman numeral is III." << endl; break;
        case 4: cout << "The roman numeral is IV." << endl; break;
        case 5: cout << "The roman numeral is V." << endl; break;
        case 6: cout << "The roman numeral is VI." << endl; break;
        case 7: cout << "The roman numeral is VII." << endl; break;
        case 8: cout << "The roman numeral is VIII." << endl; break;
        case 9: cout << "The roman numeral is IX." << endl; break;
        case 10: cout << "The roman numeral is X." << endl; break;
        default: cout << "Please enter in a number between 1 and 10." << endl; break; //if no condiitons met
    }
    return 0;
}

