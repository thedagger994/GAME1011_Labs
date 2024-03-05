#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
	ifstream inputFile;
	ofstream outputFile;
	double price;
	string item;

	inputFile.open ("Items.txt");
	outputFile.open ("Prices.txt");

	cout << "Please enter the prices for the following items.\n";

	for (int count = 1; count <= 5; count++)
	{
		inputFile >> item;
		cout << "Price for : " << item << endl;
		cin >> price;
		outputFile << price << endl;
	}

	cout << "All prices have been successfully recorded." << endl;

	inputFile.close();
	outputFile.close();
	return 0;
}