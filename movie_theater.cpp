#include <iostream>

int main(){
    std::string name_of_Movie; //creating new variables
    int number_of_adult_tickets, number_of_child_tickets;
    float gross_profit,net_profit,amount_paid;
    std::cout << "Let's check your gross profit for the movie!" << std::endl; //printing statements
    std::cout << "What is the name of your movie? ";
    std::getline(std::cin, name_of_Movie);
    std::cout << "How many adult tickets did you sell? ";
    std::cin >> number_of_adult_tickets;
    
    if (std::cin.fail()) { //if the user entered in a value other than an integer
        std::cout << "Number of adults must be a number." << std::endl;
        exit(0);
    }
    
    std::cout << "How many child tickets did you sell? ";
    std::cin >> number_of_child_tickets;
    
    if (std::cin.fail()) { //if the user entered in a value other than an integer
        std::cout << "Number of children must be a number." << std::endl;
        exit(0);
    }
    gross_profit = 6*(number_of_adult_tickets)+ 3*(number_of_child_tickets); //calculating values
    net_profit = 0.2*(gross_profit);
    amount_paid=gross_profit-net_profit;
    std::cout << std::fixed;
    std::cout.precision(2); //setting the precision to two decimal values (found idea on internet)
    std::cout << "Movie Name:                 \"" << name_of_Movie << "\"" << std::endl;
    std::cout << "Adult Tickets Sold:         " << number_of_adult_tickets << std::endl;
    std::cout << "Child Tickets Sold:         " << number_of_child_tickets << std::endl;
    std::cout << "Gross Box Office Profit:    $ " << gross_profit << std::endl;
    std::cout << "Net Box Office Profit:      $ " << net_profit << std::endl;
    std::cout << "Amount Paid to Distrubtors: $ " << amount_paid <<std::endl;
   
    
    return 0;
    
}