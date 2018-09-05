#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std; //declaring a namespace (std)

int main(){

    int a;         //declaration of variables
    double area, radius, base, width, height, length;
    const double pi = 3.141519;  //creation of a constant (pi)
    cout << "Calculate the area of a:" << std::endl;   //printing out statements
    cout << "1. circle               " << std::endl;
    cout << "2. rectangle            " << endl;
    cout << "3. triangle             " << endl << endl;
    cout << "Enter an option number: ";
    cin >> a;  //taking in values
    if (a == 1){ //using if, checking to see if value of a equals number then proceed with code in curly brace
        std::cout << "Enter circle radius: ";
        std::cin >> radius;
        area = pi * pow(radius,double(2));
        std::cout << "The circle's area with radius " << radius << " is: " << fixed << setprecision(2) << area <<endl;
    }
    if (a == 2){
        std::cout << "Enter rectangle length: ";
        std::cin >> length;
        std::cout << "Enter rectangle width: ";
        std::cin >> width;
        area = length * width;
        std::cout << "The rectangle's area with length " << length << " and width " << width << " is: " << fixed << setprecision(2) << area <<endl;
    }
    if (a == 3){
        std::cout << "Enter triangle base: ";
        std::cin >> base;
        cout << "Enter triangle height: ";
        cin >> height;
        area = base * height * 0.5;
        cout << "The triangles's area with base " << base << " and height " << height << " is: " << fixed << setprecision(2) << area <<endl;
    }
    else{ //execute if no coniditons are met
        cout << "Please enter in a valid number, Try again later!" <<endl;
    }
    return 0;
}
