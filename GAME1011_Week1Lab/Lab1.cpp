#include <iostream>
using namespace std;

class Platform
{


public:
	Platform() : platformName(nullptr), platformManufacturer(nullptr)
	{
		cout << "Platform\n";
		platformName = new string;
		platformManufacturer = new string;
	}

	Platform(string n, string m) : platformName(nullptr), platformManufacturer(nullptr)
	{
		cout << "Platform parameterized constructor called\n";
		platformName = new string;
		platformManufacturer = new string;
		*platformName = n;
		*platformManufacturer = m;
	}

	~Platform()
	{
		//destructor needed if we use the "new" keyword to allocate memory
	}

	string getName()
	{
		return *platformName; 
	}
	string getManufacturer()
	{
		return *platformManufacturer; 
	}

private:
	string* platformName;
	string* platformManufacturer;
};

class Game
{
public:
	Game() : gameName(nullptr), gamePublisher(nullptr), gameDeveloper(nullptr)
	{

	}
private:
	string* gameName;
	string* gamePublisher;
	string* gameDeveloper;
}; 

int main()
{
	string name;
	string manufacturer;
	cout << "Enter in your platform.\n";
	cin >> name;
	cout << "\nWho is the Manufacturer?\n";
	cin >> manufacturer;
	
	Platform one(name, manufacturer);
	cout << "The selected platform is " << one.getName() << " made by " << one.getManufacturer() << ".\n";
}