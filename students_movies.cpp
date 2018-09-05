#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int *dyn_array;
    int students;
    float avrg;
    
    int* create_array(int);
    /*This function allows us to create a dynamic array.
     With this function we can input in any number and
     get a pointer as an output*/
    void enter_data(int*, int);
    /*This method allows us to input in all the data
     into the array. We use this method along with
     pointers to make the entry easy.*/
    float find_average(int*,int);
    /*We use this method to find the average of
     all the data. We use pointers and basic
     arithmetic to help us out.*/
    void show_array(int*,int);
    /*We print the array in this function.*/
    
    do
    {
        cout << "How many students will you enter? ";
        cin >> students;
    }while ( students <= 0 );
    
    dyn_array = create_array(students);
    //this function creates a dynamic array
    //and returns its pointer
    enter_data(dyn_array, students);
    //use 'pointer' notation in this function to
    //access array elements
    //accept only numbers 0-100 for movie seen
    avrg = find_average(dyn_array, students);
    //use 'pointer' notation in this function to
    //access array elements
    
    
    cout << "The array is:" << endl << endl;
    show_array(dyn_array, students);
    
    cout << endl;
    cout << "The average is " << avrg << ".\n";
    
    //delete[] dyn_array;
    return 0;
}

int* create_array(int f_students){
    
    int * address;
    address = new int[f_students];
    return (address);
    
}

void enter_data(int* f_dyn_array, int f_students){
    int value = 0;
    int* initialplace = f_dyn_array;
    for(int i = 0; i < f_students; i++ ){
        cout << "Please enter in the value for Student " << i+1 << ":" ;
        cin >> value;
        
        while(!(value >= 0 && value <= 100)){
            cout << "Please enter in the value for Student " << i+1 << ":" ;
            cin >> value;
        }
        *f_dyn_array = value;
        f_dyn_array++;
    }
    f_dyn_array = initialplace;
}

float find_average(int* f_dyn_array, int f_students){
    float p_avrg=0;
    int* initialplace = f_dyn_array;
    for(int i = 0; i < f_students; i++ ){
        p_avrg += *f_dyn_array;
        f_dyn_array++;
    }
    p_avrg /= f_students;
    f_dyn_array = initialplace;
    return p_avrg;
}

void show_array(int* f_dyn_array, int f_students){
    int p_value = 0;
    for(int i = 0; i < f_students; i++ ){
        p_value = *f_dyn_array;
        cout << "Student " << i+1 << " watched " << p_value << endl ;
        f_dyn_array++;
        
    }
}

