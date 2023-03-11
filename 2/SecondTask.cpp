#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream text("Second.txt");
	ofstream Result("Result.txt");

	while (!text.eof())
	{
		string str;
		getline(text,str);
		Result << str << endl;
	}
}