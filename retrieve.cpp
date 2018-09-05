#include <iostream>
#include <cstdlib>
using namespace std;

int main ()
{
        string s(getenv("QUERY_STRING"));
		//string s = "one+two+three";	//use this for testing in an IDE
						//instead of the QUERY_STRING
        cout << "Content-type:text/html\n\n";
        cout << "<html>" << endl;
        cout << "<head>" << endl;
        cout << "<title>Grabbing Data From the URL</title>" << endl;
        cout << "</head>" << endl;
        cout << "<body>" << endl;
        cout << "<body bgcolor=\"#00FFFF\">" << endl;
        cout << "<font color=\"#FF00FF\">" << endl;
        cout << "s: " << s << "<br>\n";
        cout << "</font></body>" << endl;
        cout << "</html>" << endl;
        return 0;
}

