#include <iostream>
#include <fstream>
int main()
{
	std::ifstream inText("First.txt");
	std::ofstream result("Result.txt");
	while (!inText.eof())
	{
		std::string str;
		inText >> str;
		
		// ASCII Codes between symbols values  
		if (size(str) >= 7 && (int)str[6] >= 33 && (int)str[6] >= 64)
		{
			// ASCII Codes between symbols values  
			if ((int)str[str.length() - 1] >= 33 && str[str.length() - 1] <= 64)
			{
				// Erase Symbol If found it in this Range
				str.erase(str.length() - 1, 1);
			}
			// Print to Result txt File 
			result << str << '\n';
		}
	}
}
