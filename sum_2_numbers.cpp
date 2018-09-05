#include <iostream>

int main() {
    float x;                                    //declaration of variables
    float y;
    std::cout << "Enter in the variable x: "; //printing out statement to ask for input
    std::cin >> x;                              //taking in input
    std::cout << "Enter in the variable y: "; //printing out statement to ask for input
    std::cin >> y;                              //taking in input
    float sum = x+y;
    std::cout << "Sum:#################### " << sum << std::endl; 
//printing the sum
    
    return 0;
}

