// File: retrieve_form_start.cpp
// Author: Taj Shaik
// cs102 Online
// Date: 
// Description: This program retrieves three form fields and sends the result
//				back to the browser

#include <iomanip> //importing the classes
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

struct FIELDS  //creating a struct
{
	string name;
	string value;
}; 

const int cnt = 3; //creation of a constant

// Prototypes
void parse(string, FIELDS []); 
string param(string, FIELDS [], int);
void changeSeason(string);

//main begins
int main()
{
	FIELDS name_value_pairs [cnt];

	string qs(getenv("QUERY_STRING")); 
		//string qs("first=fred&last=flint&color=red");
	cout << "Content-type:text/html\n\n";  //html text declaration
	cout << "<html>" << endl; 
	cout << "<head>" << endl; 
    cout << "<title>Results for Assignment 10</title>" << endl; 
    cout << "</head>" << endl;
    cout << "<body bgcolor ='#FF884D'><center>" << endl; 
	

	parse(qs, name_value_pairs); //call parse method
	
	string first = param("first", name_value_pairs, cnt); //calling param 
	string last = param("last", name_value_pairs, cnt);
	string season = param("season", name_value_pairs, cnt);

	cout << "<h1>" << "Hello " << first << " " << last << "!" << "</h1>" << endl;
	cout << "<p>" << season << " is one of the best seasons!" << endl;

	changeSeason(season);

	cout << "</center></body>" << endl; 
	cout << "</html>" << endl; 

/*
	// Three fields are retrieved with the param function
	string first = param("first", name_value_pairs, cnt);
	string last = param("last", name_value_pairs, cnt);
	string color = param("color", name_value_pairs, cnt);
*/
	// code an HTML page, which includes the three fields
	// received.
	
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
void parse (string qs, FIELDS f_name_value_pairs[])
{	
	string name, value;
	int start_pos = 0, pos; 
	for (int counter=0; counter<cnt; counter++) {
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
string param(string lookUp, FIELDS f_name_value_pairs[], int f_cnt)
{	
	string returnstatement;
	for(int i = 0; i < f_cnt; i++){
		if(lookUp.compare(f_name_value_pairs[i].name) == 0){
			returnstatement = f_name_value_pairs[i].value;
		}
	}
	return returnstatement;
}
void changeSeason(string f_Season){ //method to change season
	if(f_Season.compare("Summer") == 0){
		cout << "<p>" << "You must love the sun!" << "</p><br>" << endl;
		cout << "<img src='http://wingsprogram.com/wp-content/uploads/2015/06/Summer-Is-On-Its-Way.jpg' alt='Summer'>" << endl;
	}
	if(f_Season.compare("Winter") == 0){
		cout << "<p>" << "You must love the snow!" << "</p><br>" << endl;
		cout << "<img src='http://static.ddmcdn.com/gif/winter-wonderland-pictures-16.jpg' alt='Winter'>" << endl;
	}
	if(f_Season.compare("Spring") == 0){
		cout << "<p>" << "You must love the rain!" << "</p><br>" << endl;
		cout << "<img src='http://img.lapseshot.com/images/desktopbackgroundshq.com/backgrounds/spring-rain-wallpaper-nature-backgrounds-water-backgrounds-30153.jpg' alt='Spring'>" << endl;
	}
	if(f_Season.compare("Fall") == 0){
		cout << "<p>" << "You must like the leaves!" << "</p><br>"<< endl;
		cout << "<img src='https://static1.squarespace.com/static/5256b08ee4b0b689af60dbb3/5283d5f9e4b00fa592e5c551/55600867e4b06c953d5b5468/1432357605094/?format=1000w' alt='Fall'>" << endl;
	}
}

