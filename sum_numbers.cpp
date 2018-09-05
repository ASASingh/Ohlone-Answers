/*
Program header
*/
#include <iostream> //Libraries
#include <stdio.h>
using namespace std;
int main(){
    int number = 0; //intialize variables
    int sum_numbers = 0;
    cout << "This program will add all the numbers between 1 and your input:" << endl;
    cout << "Please enter a positive number: "; //Output statements
    cin >> number; //Input in number to be addition-factorized
    while (number <= 0){ //while loop for validation
        cout << "ERROR: Please enter in a positive number." << endl;
        cout << "Please enter a positive number: ";
        cin >> number;
    }
    for(int i = 1; i <= number;i++){ //for loop for printing
        if (i == number) {
            cout << i << " ";
            sum_numbers += i; //adding numbers to sum
        }
        else {
        cout << i << " + ";
        sum_numbers += i; //adding numbers to sum
        }
    }
    cout << "= " << sum_numbers << endl; //printing sum
    cout << "------------" << endl;
    cout << "  Done !!!  " << endl;
    cout << "------------" << endl;
    return 0;
}