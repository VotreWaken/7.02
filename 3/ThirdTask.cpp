#include <iostream>
#include <fstream>

// Fraction Class
class Fraction
{
public:
	Fraction()
	{
		numerator_ = 0;
		denominator_ = 0;
	}
	~Fraction()
	{

	}
	void Output()
	{
		std::cout << "Numerator: " << numerator_ << '\n';
		std::cout << "Denominator: " << denominator_ << '\n';
	}
	void SetNum()
	{
		std::cout << "Enter Numerator\n";
		std::cin >> numerator_;
	}
	void SetDenum()
	{
		std::cout << "Enter Denominator\n";
		std::cin >> denominator_;
	}
private:
	int numerator_;
	int denominator_;
};

// Initialize Class Array
void InitArray(Fraction* FractionArray, size_t Size)
{
	for (size_t i = 0; i < Size; i++)
	{
		FractionArray[i].SetNum();
		FractionArray[i].SetDenum();
	}
}

// Write Array to Binary File
void WriteBinary(Fraction* FractionArray, size_t Size)
{
	std::ofstream Text("Third.txt", std::ios::binary);
	if (!Text)
	{
		std::cerr << " The file Ex2.txt could not be opened for writing!\n";
		exit(1);
	}
	for (size_t i = 0; i < Size; i++)
	{
		Text.write((char*)&FractionArray[i], sizeof(FractionArray));
	}
	Text.close();
}

// Read Array From Binary File
void ReadBinary(Fraction* FractionArray, size_t Size)
{
	std::ifstream readFile("Third.txt", std::ios::binary);
	if (!readFile)
	{
		std::cerr << " The file Ex2.txt could not be opened for reading!\n";
		exit(1);
	}
	for (size_t i = 0; i < Size; i++)
	{
		readFile.read((char*)&FractionArray[i], sizeof(FractionArray));
		FractionArray[i].Output();
	}
	readFile.close();
}

int main()
{
	// Create First Array to Write to File 
	const int Size = 4;
	Fraction temp[Size];
	// Initialize First Array
	InitArray(temp, Size);
	// Write To File Array
	WriteBinary(temp, Size);
	// Create Second Array to Read from File 
	Fraction temp2[Size];
	// Read From File
	ReadBinary(temp2, Size);
}