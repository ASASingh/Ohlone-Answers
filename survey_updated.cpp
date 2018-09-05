#include <iomanip> //importing the classes
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>  // for file I/O
#include <iostream>
using namespace std;

struct FIELDS  //creating a struct
{
    string name;
    string value;
}; 


// Prototypes
void parse(string, FIELDS *, int ); 
string param(string, FIELDS * , int);
void changeSeason(string);
int how_many(string);
FIELDS * create_array (int);
void create_form();
void save_data(fstream &, char const *, int, FIELDS *);
FIELDS * read_data(ifstream &, char const *);
int count_records (ifstream &);
void display_result(FIELDS*, ifstream &);
int IP_not_duplicated(ifstream & input_file, char const *);

//main begins
int main()
{
    fstream io_file;
    ifstream input_file;

    string qs(getenv("QUERY_STRING")); 
    
    int result;
    const int cnt = how_many(qs); //creation of a constant
    FIELDS * name_value_pairs = create_array(cnt);
    FIELDS * data_array;
    input_file.open("survey.txt");
    
        
    cout << "Content-type:text/html\n\n";  //html text declaration
    if (qs.length() != 0) { 
                //create_form(); 
                parse(qs, name_value_pairs, cnt);
                string value = param("vote", name_value_pairs, cnt); //calling param 
                save_data(io_file,"survey.txt",cnt,name_value_pairs);
                data_array = read_data(input_file,"survey.txt");
                cout << "<html>" << endl; 
                cout << "<head>" << endl; 
                cout << "<title>Results for Survey</title>" << endl; 
                cout << "</head>" << endl;
                cout << "<body bgcolor ='#FF884D'><center>" << endl;
                cout << "<h2>ONLY TILL STAGE 4, NO STAGE 5 FUNCTIONALITY</h2>"; 
                display_result(data_array , input_file);
                cout << "<a href = \"http://toolkit.cs.ohlone.edu/~gen203/survey.txt\">RAW DATA</a>\n";
                cout << "</center></body>" << endl; 
                cout << "</html>" << endl;
        
        } 
        else { 
                create_form();
                data_array = read_data(input_file,"survey.txt");
                cout << "<html>" << endl; 
                cout << "<head>" << endl; 
                cout << "<title>Results for Survey</title>" << endl; 
                cout << "</head>" << endl;
                cout << "<body bgcolor ='#FF884D'><center>" << endl; 
                display_result(data_array , input_file);
                cout << "<a href = \"http://toolkit.cs.ohlone.edu/~gen203/survey.txt\">RAW DATA</a>\n";
                cout << "</center></body>" << endl; 
                cout << "</html>" << endl;
        }
    return 0;
}

//*******************************************
//******** Functions begin ******************
//*******************************************

//*******************************************
// parse()
// This will separate the name/value pairs found after the ? in 
// the URL and populate the name_value_pairs array of structures
//*******************************************
void parse (string qs, FIELDS * f_name_value_pairs, int f_cnt)
{   
    string name, value;
    int start_pos = 0, pos; 
    for (int counter=0; counter<f_cnt; counter++) {
        pos = qs.find("=", start_pos);
        name = qs.substr(start_pos, pos - start_pos); 
        f_name_value_pairs[counter].name = name;
        start_pos = pos + 1;  
        pos = qs.find("&", start_pos);
        if (pos == string::npos) {
            pos = qs.length();
        }
        value = qs.substr(start_pos, pos - start_pos); 
        f_name_value_pairs[counter].value = value;
        start_pos = pos + 1; 
    } 
}

//*******************************************
// param()
// This will find the field value based on the
// field name
//*******************************************
string param(string lookUp, FIELDS * f_name_value_pairs, int f_cnt)
{   
    string returnstatement;
    for(int i = 0; i < f_cnt; i++){
        if(lookUp.compare(f_name_value_pairs[i].name) == 0){
            returnstatement = f_name_value_pairs[i].value;
        }
    }
    return returnstatement;
}

    int how_many(string f_qs) {      
        int count = 0;  
        int start = 0;  
        int pos = 0;  
        bool found = true; 
                 
        while(found) {  
                pos = f_qs.find("=" , start);  
                if(pos == -1) {  
                     found = false;  
                }  
                else {  
                count++;  
                start = pos + 1;  
                }  
                pos = 0;  
        }  
    return count;  
}   
FIELDS * create_array (int f_cnt)
{
    FIELDS * address;
    address = new FIELDS[f_cnt];
    return (address);
}
void create_form(){
    cout << "<html><head><title>Survey for Final Project</title></head>\n"
         << "<body bgcolor = \"#DDA0DD\"><center>\n"
         <<"<form action=\"survey.cgi\" method=\"GET\">\n"
         <<"<font face = \"Times\">\n"
         <<"<h1><font color = \"navy\">DO YOU USE FREE WATER CUPS TO GET SODA?</font></h1>\n"
         <<"<label for=\"vote\">Yes</label>\n"
         <<"<input name=\"vote\" value=\"Yes\" type=\"radio\"><d><br>\n"
         <<"<label for=\"vote\">No</label>\n"
         << "<input name=\"vote\" value=\"No\" type=\"radio\"><d><p>\n" 
         << "<label for=\"vote\">Embarrased to say</label>\n"
         << "<input name=\"vote\" value=\"embarassed\" type=\"radio\"><d><br>\n"
         << "<p><input type=\"submit\" value=\"Submit\">\n</p>"
         << "<a href = \"http://toolkit.cs.ohlone.edu/~gen203/survey.txt\">RAW DATA</a>\n"
         << "</font>\n"
         << "</form>\n"
         << "</body>\n"
         << "</html>\n" ;
}

void save_data(fstream & f_io_file, char const * file_name, int cnt, FIELDS * f_name_value_pairs){
    f_io_file.open(file_name, ios::out | ios::app);
    string value = param("vote", f_name_value_pairs, cnt); //calling param 
    string line_appended = value + "|"+ getenv("REMOTE_ADDR") + "\n";
    //cout << "debug with lines: " << line_appended << "<p>" << endl; 
    if (f_io_file.is_open())
    {
        f_io_file << line_appended;
        f_io_file.close();
    }
     else cout << "Unable to open file";
}


FIELDS* read_data(ifstream & input_file, char const * file_name) 
{  
        //input_file.open("survey.txt"); 
        int cnt = count_records(input_file); 
        string delimiter = "|";
        FIELDS * data_array = create_array(cnt); 
        input_file.clear();
        input_file.seekg(0, ios::beg);
        for(int i = 0; i < cnt; i++) 
        { 
                string line; 
                string IP; 
                string value; 
                getline(input_file,line); 
                int pos = line.find(delimiter, 0); 
                value = line.substr(0 , pos); 
                IP = line.substr(pos + 1, line.length()); 
                //cout << value << endl;
                //cout << IP << endl;
                data_array[i].name = value; 
                data_array[i].value = IP; 
                pos = 0; 
        } 
        input_file.close(); 
        return data_array;
}  


int count_records(ifstream &f_input_file_open)
{
    //cout << "Counting how many records in input_file_open ... " << endl;
    int records_count = 0;  //Extra record gets counted at the end of the file
    while (!f_input_file_open.fail())
    {
        string data;
        getline(f_input_file_open, data);
        records_count++;
        //cout << "data is :" << data << endl;
    }
    records_count--;
    return records_count;    //there is an extra line in text file
}

void display_result(FIELDS* f_data_array,ifstream & input_file){
    input_file.open("survey.txt"); 
    int count_yes = 0, count_no = 0, count_embarrass = 0;
    int cnt = count_records(input_file); 
    for(int i = 0; i < cnt; i++) 
        {
            string value = f_data_array[i].name;
            if(value.compare("Yes") == 0) {
                count_yes++;
            }
            if(value.compare("No") == 0){
                count_no++;
            }
            if(value.compare("embarassed") == 0){
                count_embarrass++;
            }
        }
    cout << "<h1>The Results!\n</h1>";
    cout << "<p>Yes: ";
    for (int counter = 0; counter < count_yes; counter++){
        cout << "*";
    }
    cout << "   " << count_yes << "\n</p>";
    cout << "<p>No: ";
    for (int counter = 0; counter < count_no; counter++){
        cout << "*";
    }
    cout << "   " << count_no << "\n</p>";
    cout << "<p>I'm so embarassed: ";
    for (int counter = 0; counter < count_embarrass; counter++){
        cout << "*";
    }
    cout << "   " << count_embarrass << "\n</p>";
}

