#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, wchar_t* argv[])
{
	cout << "Content-type:text/html\r\n\r\n";
	cout << "<html>\n<head>\n<title>Therapy</title>\n</head>\n";
	cout << "<body>\n";

	cout << "<a href='therapy.cgi'>Therapy</a><br><a href='games.cgi'>Games</a><br><a href='support.cgi'>Support</a><br>\n";
	cout << "<h2>Therapy</h2>\n";

	//Code here to connect to server
	//"Therapy"

	cout << "</body>\n";
	cout << "</html>\n";
	return 0;
}