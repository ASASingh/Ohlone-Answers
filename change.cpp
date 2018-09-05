// Example program 
#include <iostream>
#include <string>  
using namespace std;   

const int QUARTER = 25; 
const int DIME = 10; 
const int NICKEL = 5; 
const int PENNY = 1;  

//void getChange (double money, int value); 
int change(double money, int value);  

int main() {     
    double money;     
    int value; 
    cout << "Please enter the number of cents you have." << endl;
    cin >> money;  
    //cout << money << endl;
    //getChange (money, value);        
    int numQuarter = change(money, QUARTER); 
    money = money - (numQuarter*QUARTER); 
    int numDime = change(money, DIME);  
    money = money - (numDime*DIME); 
    int numNickel = change(money, NICKEL);
     money = money - (numNickel*NICKEL);
    int numPenny = change(money, PENNY);  
    money = money - (numPenny*PENNY);
    cout << "The number of quarters is: " << numQuarter << endl;     
    cout << "The number of dimes is: " << numDime << endl; 
    cout << "The number of nickels is: " << numNickel << endl; 
    cout << "The number of pennies is: " << numPenny << endl; 
    return 0;
}   

int change(double money, int value) {     
    int numQuarter, numDime, numNickel, numPenny;             
    if(value == QUARTER){
        numQuarter = money / QUARTER;     
        return numQuarter;
    }
     if(value == DIME){
        numDime = money / DIME;  
        return numDime;
     }
      if(value == NICKEL){
        numNickel = money / NICKEL;     
        return numNickel;
      }
       if(value == PENNY){
        numPenny = money / PENNY;
        return numPenny;
       }
}