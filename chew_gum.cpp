/*
 program header
 */
#include <stdio.h> //Libraries
#include <string>
#include <iostream>

using namespace std; //declaring namespace std

int main(){
    int number_of_times = 0; //intialzing
    int number_of_chars = 0;
    string sentence;
    cout << "Enter a sentence to write on the board:" << endl; //printing lines
    getline(cin, sentence); //Input
                            //code to label and input values for the sentence (use getline(cin, string))
                            //and an integer value to iterate the loop.
    cout << "How many times should it be written? ";
    cin >> number_of_times; //Input fot number of times should be printed
    while(number_of_times <= 0){
        cout << "Please enter in a number that is greater than 0." <<endl;
        cout << "How many times should it be written? ";
        cin >> number_of_times; //Input fot number of times should be printed
    }
    number_of_chars = number_of_times * sentence.length();
    cout << "The concatenated string is now:"<< endl;
    for(int i = 0; i < number_of_times; i++){ //Processing loop
        cout << sentence << endl;          //code for a 'for' loop to concatenate (in a string) the user
                                            // sentence in separate lines, as many times as specified.
    }
    cout << "You have typed " << number_of_chars << " characters." << endl; //Output
    //code to output the concatenated string and it's .length() property.

    return 0;
}
