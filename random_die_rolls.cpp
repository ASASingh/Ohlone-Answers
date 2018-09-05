#include <iostream>
#include <ctime>		// for the time() function
#include <cstdlib>		// for the srand() and rand() functions
#include <iomanip>		// for formatting, setw() etc.
using namespace std;

int main()
{
    // declare variables
    const int array_size = 6000;		// a constant (array_size) declared and assigned to 6000
    int die = 0;				            // a variable (die) to represent one random die number
    int num_array[array_size];	 	    // array (num_array)of length array_size
    int tally_array[7];	 			    // array (tally_array) to hold the totals of each die face
    
    srand((int) time(0));// set the seed first, and only once (before creating all random numbers)
    
    int i = 0;
    while (i++ < 6000){
        die = (rand() % 6) + 1;
        num_array[i] = die;
    }     // Populate array_size random numbers into array num_array
    
    
    
    // Test part of the array for correct data
    // Leave this debug statement in final app
    cout << "debug for num_array[]" << endl;
    for (int i=100; i<200; i++) {
        cout << num_array[i] << " ";
    }
    cout << endl;
    
    int x = 0;
    while(x++ < 6000){
        die = num_array[x];
        switch(die){
            case 1: tally_array[1]++; break;
            case 2: tally_array[2]++; break;
            case 3: tally_array[3]++; break;
            case 4: tally_array[4]++; break;
            case 5: tally_array[5]++; break;
            case 6: tally_array[6]++; break;
        }
    }
    
    
    /*	Tally the result - this is tricky - understand it fully:
     Declare an array, tally_array with 7 elements - only indexes
     1-6 (not 0) will be used to hold the total of each
     die face values - index 1 will hold the sum of all rolls of 1's,
     index 2 wil hold the sum of all rolls of 2's, etc..
     In order to achieve this, create a loop, cycling through each of the
     6,000 random values, where each value (1 through 6) becomes the
     index of tally_array and that index element will get
     incremented by one with the ++ operator.
     
     Makes sense? If not, let's talk about it on the db
     */
    
    
    
    // Test tally_array for correct data
    cout << "debug for tally_array" << endl;
    for (int i=1; i<=6; i++) {
        cout << "i: " << i << " " << tally_array[i] << endl;
    }
    cout << endl;
    
    
    cout << "  Display Result for 6000 Rolls  " << endl;
    cout << "Die Face                Occurance"<< endl;
    cout << "=================================" << endl;
    cout << " 1                      " << tally_array[1] << "   " <<endl;
    cout << " 2                      " << tally_array[2] << "   " <<endl;
    cout << " 3                      " << tally_array[3] << "   " <<endl;
    cout << " 4                      " << tally_array[4] << "   " <<endl;
    cout << " 5                      " << tally_array[5] << "   " <<endl;
    cout << " 6                      " << tally_array[6] << "   " <<endl;
    
    
    
    
    
    
    // display the results
    // duplicate this format:
    
    /*
     Display Result for 6000 Rolls
     Die Face    Occurance
     ===========================
     1                1017
     2                1033
     3                 949
     4                1026
     5                 987
     6                 988
     */
    
    
    
    
    
    return 0;
}