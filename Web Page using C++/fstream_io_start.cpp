// File: fstream_io.cpp
//fstream_io.cpp</b> will retrieve data from file students_list.txt, sort it, reformat it, and
//re-write the newly formatted data into file students.txt
//
//input file - students_list.txt - example: first and last names (not sorted) separated by id
//	with tab character
// 		joe smith	3423
// 		linda holland	4344
//		etc.
//
//output file - students.txt - example: the term gen is assigned to the sorted
//	students and numbered automatically. The three fields are separated by
//	one bar character.
// 		gen1|linda holland|4344
// 		gen2|joe smith|3423
// 		etc.
//
//fstream_io.cpp</b> is a long program, therefore already contains
//	correct prototypes, code, function calls and headers (not all complete), etc..
//
//pseudo-code:
//
//students_count = output from function count_records to figure out how many
//	records there are in file student_list.txt
//	function count_records (completed):
//		while !.fail, count how many records there are and return that number
// 			to students_count
//call to function create_array to create a dynamic array (students_list_array) of
//	students_count size - start with function from students_movies.cpp.
//call to function create_array to create another dynamic array (gen_accounts_array)
//	for final data format
//call function populate_students_list_array to read file into array students_list_array
//	function populate_students_list_array:
//		while !input_file.fail, place each file line into students_list_array elements
//call function sort_array to sort students_list_array
//	function sort_array (code given):
//		uses the bubble sort algorithm
//call function 'reformat' to rewrite sorted_students_array into gen_accounts_array
//	function 'reformat':
//		for loop with counter 'index' from 0 to students_count
//			string variable old_line = sorted_students_array[index] element
//			separate old_line into two variables(name, id) by tabs (\t)
//			call convert_counter function to convert integer index into
//				converted_index, a string (code given)
//			concatenate "gen" + converted_index + "|" + name + "|" + id + endl into
//				new_line string variable
//			save new_line into gen_accounts_array
//		end for loop
//call function save_new_format to write gen_accounts_array into students.txt
//call function print_data to print content of file students.txt to the screen

//Begin program
#include <fstream>	// for file I/O
#include <iostream>
#include <sstream>	// for convert
#include <string>
using namespace std;

/////// Prototypes:////////////////////////
bool input_file_open(ifstream &, char const *);
bool io_file_open (fstream &, char const *);
int count_records(ifstream &);
string * create_array (int);
void populate_students_list_array (ifstream &, string [], int);
void sort_array(string [], int);
void reformat(string [], string [], int);
string convert_counter (int);
void save_new_format (fstream &, string [], int);
void print_data (fstream &, int);

int main ()
{
    int students_count;
    string data;
    bool status;
    ifstream input_file;
    fstream io_file;
    
    // open file for input
    status = input_file_open(input_file, "students_list.txt");
    if (!status)
    {
        cout << "input_file_open could not be opened for reading\n";
        cout << "Program terminating\n";
        return 0;
    }
    else
    {
        students_count = count_records(input_file);
        cout << "Debug: " << students_count << " students found." << endl;
    }
    
    //	Compiles and run to this point - students_count gets it's value
    
     // Create two dynamic arrays:
     string * students_list_array = create_array(students_count);
     string * gen_accounts_array = create_array(students_count);
     
     populate_students_list_array (input_file, students_list_array, students_count);
     cout << "debug with 5th element: " << students_list_array[4] << endl;
     
     input_file.close();
     
    
    sort_array(students_list_array, students_count);
     cout << "debug with element 5 after sorted: " << students_list_array[4] << endl;
     cout << "debug with element 0 after sorted: " << students_list_array[0] << endl;
    
     reformat(students_list_array, gen_accounts_array, students_count);
     cout << "debug with gen_acounts_array[3]: " << gen_accounts_array[3] << endl;
     
     //Open file for input/output
     status = io_file_open(io_file, "students.txt");
     if (!status)
     {
     cout << "io_file_open could not be opened for reading and writing\n";
     cout << "Program terminating\n";
     return 0;
     }
     else
     {
     //write gen_accounts_array into students.txt
    
     save_new_format (io_file, gen_accounts_array, students_count);
     print_data (io_file, students_count);
     }
     io_file.close();
     
     return 0;
      	//End of commented out main()
    
}


///////////////////////////////////////////////////
////////////// input_file_open ////////////////////
///////////////////////////////////////////////////
bool input_file_open (ifstream& input_file, char const *file_name)
{
    input_file.open(file_name);
    if (input_file.fail())
        return false;
    else
        return true;
}

///////////////////////////////////////////////////
////////////// count_records //////////////////////
///////////////////////////////////////////////////

int count_records(ifstream &f_input_file_open)
{
    cout << "Counting how many records in input_file_open ... " << endl;
    int records_count = 0;	//Extra record gets counted at the end of the file
    while (!f_input_file_open.fail())
    {
        string data;
        getline(f_input_file_open, data);
        records_count++;
        cout << "data is :" << data << endl;
    }
    
    return records_count -1;	//there is an extra line in text file
}



///////////////////////////////////////////////////
////////////// io_file_open ///////////////////////
///////////////////////////////////////////////////
bool io_file_open (fstream& f_io_file, char const *file_name)
{
    f_io_file.open(file_name);
    if (f_io_file.fail())
        return false;
    else
        return true;
    
}


////////////////////////////////////////////////////
///////////////   create_array   ///////////////////
//                                                //
// Creates a dynamic array                        //
////////////////////////////////////////////////////

string * create_array (int f_array_size)
{
    string * address;
    address = new string[f_array_size];
    return (address);
}


 
 ///////////////////////////////////////////////////
 ////////// populate_students_list_array ///////////
 ///////////////////////////////////////////////////
 
void populate_students_list_array(ifstream & f_input_file, string f_students_list_array[], int f_studentcount)
 {
	
     //The following two lines bring the file cursor back to beginning of file - after
	//	having been left at the end after count_records function
	f_input_file.clear();
	f_input_file.seekg(0L, ios::beg);
     
 
	//for loop code here
     for(int count = 0; count < f_studentcount; count++){
         string contentsoffile;
         getline(f_input_file,contentsoffile);
         f_students_list_array[count] = contentsoffile;
     }
     
     
	cout << "debug with 5th element: " << f_students_list_array[4] << endl;
 }


 //////////////////////////////////////////////////////////////////
 ////////// sort_array ////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////
 // This function is given since this class has not yet covered ///
 // sorting algorithms. This topic is covered in later courses. ///
 // Do figure out how it works.                                 ///
 //////////////////////////////////////////////////////////////////
 
 void sort_array(string array[], int count)
 {
	bool swap;
	string temp;
	count -= 1;
	
	do
	{
 swap = false;
 for (int index = 0; index < count; index++)
 {
 //cout << "debug in sort_array with index: " << index << endl;
 if (array[index] > array [index + 1] && index != count)
 {
 temp = array[index];
 array[index] = array[index + 1];
 array[index + 1] = temp;
 swap = true;
 }
 }
	} while (swap);
 }

 ///////////////////////////////////////////////////
 ////////// reformat ///////////////////////////////
 ///////////////////////////////////////////////////
 
 void reformat(string f_students_list_array[], string f_gen_accounts_array[], int count)
 {
	//	function 'reformat':
	//		for loop with counter 'index' from 0 to count
	//			string variable old_line = sorted_students_array[index] element
	//			separate old_line into two variables(name, id) by tabs (\t) - using
	//				similar string processing code as in retrieve_form.cpp
	//			call convert_counter function to convert integer index into
	//				converted_index, a string
	//			concatenate "gen" + string_counter + "|" + name + "|" + id + endl into
	//				new_line string variable
	//			save new_line into gen_accounts_array
	//		end for loop
     
     
	string old_line, new_line, name,  id, converted_index;
	string delimiter="\t";
	cout << "debug in reformat" << endl;
 
	// for loop code here
     for (int counter = 0; counter < count; counter++){
         old_line = f_students_list_array[counter];
         int pos1 = 0;
         pos1 = old_line.find(delimiter,0);
         name = old_line.substr(0, pos1);
         id = old_line.substr(pos1+1);
         converted_index = convert_counter(pos1);
         new_line= "gen" + converted_index + "|" + name + "|" + id;
         f_gen_accounts_array[counter] = new_line;
     }

 }


 ///////////////////////////////////////////////////
 ////////// convert_counter ////////////////////////
 ///////////////////////////////////////////////////
 // This code given - from the web, converts ///////
 //	an integer to a string                  ///////
 ///////////////////////////////////////////////////
 
 string convert_counter (int f_index)
 {
	string converted_f_index;
	stringstream convert;   	// stream used for the conversion
	convert << f_index;	// insert the textual representation of 'f_index' in the characters stream
	converted_f_index = convert.str(); // set 'converted_f_index' to the contents of the stream
	// 'converted_f_index' now represents the string equivalent of the integer index"
	return converted_f_index;
 }

 ///////////////////////////////////////////////////
 ////////// save_new_format ////////////////////////
 ///////////////////////////////////////////////////
 
 void save_new_format (fstream &io_file, string f_gen_accounts_array [], int f_count)
 {
	cout << "debug in save_new_format function" << endl;
 
	// for loop writing to file with io_file fstream object following
	// example from first link in assignment Ia.
     for(int i=0;i<f_count;i++)
     {
         io_file<<f_gen_accounts_array[i]<<endl;
     }
     
 }
 ///////////////////////////////////////////////////
 ////////////// print_data /////////////////////////
 ///////////////////////////////////////////////////
 
 void print_data(fstream &io_file, int f_count)
 {
	// code to reset the file cursor to start of file
	io_file.clear();
    io_file.seekg(0L, ios::beg);
    
	cout << "Content of students.txt: " << endl;
 
	// while loop to print from file to screen
    string data;
    getline(io_file, data);
      while(!io_file.fail())
      {
         cout << data << endl; 
         getline(io_file, data);
      }
      
 }
 
