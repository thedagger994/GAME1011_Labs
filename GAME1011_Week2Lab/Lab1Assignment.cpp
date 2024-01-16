#include <iostream>
#include <string.h>
#include <string>
#include "conio.h"

using namespace std;

struct Platforms
{
	Platforms* platforms;
	int platformCount;
	string platformName;
	string platformManufacturer;

	Platforms()
	{

	}

	void PrintPlatformTitle()
	{
		for (int i = 0; i < platformCount; i++)
		{
			cout << platforms[i].platformName << "\n\n";
		}
	}

	void PrintPlatformDetails()
	{
		for (int i = 0; i < platformCount; i++)
		{
			cout << "\n" << platforms[i].platformManufacturer << endl;
		}
	}

	void SetPlatforms(Platforms* platforms, int platformCount, string platformName, string platformManufacturer)
	{
		this->platforms = platforms;
		this->platformCount = platformCount;
		this->platformName = platformName;
		this->platformManufacturer = platformManufacturer;
	}	
};

struct Games
{
	Games* games;
	int gameCount;
	string gameName;
	string gamePublisher;
	string gameDeveloper;

	Games()
	{

	}
	
	void PrintGameTitle()
	{
		for (int i = 0; i < gameCount; i++)
		{
			cout << games[i].gameName << "\n\n";
		}
	}

	void PrintGameDetails()
	{
		for (int i = 0; i < gameCount; i++)
		{
			cout << "\nMade by:\n" << games[i].gamePublisher << " and " << games[i].gameDeveloper << endl;
		}
	}

	void SetGames(Games* games, int gameCount, string gameName, string gamePublisher, string gameDeveloper)
	{
		this->games = games;
		this->gameCount = gameCount;
		this->gameName = gameName;
		this->gamePublisher = gamePublisher;
		this->gameDeveloper = gameDeveloper;
	}
};

struct Achievements
{
	Achievements* achievements;
	int achievementCount;
	string achievementTitle;
	string achievementDescription;
	int achievementValue;

	Achievements()
	{

	}

	void PrintAchievementTitle()
	{
		for (int i = 0; i < achievementCount; i++)
		{
			cout << achievements[i].achievementTitle;
		}
	}

	void PrintAchievementDetails()
	{
		cout << "\nDescription:\n" << achievementDescription << "\nWith value " <<achievementValue << endl;
	}

	void SetAchievements(Achievements* achievements, int achievementCount, string achievementTitle, string achievementDescription, int achievementValue)
	{
		this->achievements = achievements;
		this->achievementCount = achievementCount;
		this->achievementTitle = achievementTitle;
		this->achievementDescription = achievementDescription;
		this->achievementValue = achievementValue;
	}
};

int main()
{
	string platform;
	int platformAmount;
	string manufacturer;
	cout << "Hello Player, what a great day to create achievements." << endl;
	cout << "How many platforms are available?" << endl;
	cin >> platformAmount;
	cin.ignore(100, '\n');
	cout << "Please enter the platform used." << endl;
	getline(cin, platform);
	cout << "Who is the manufacturer?" << endl;
	getline(cin, manufacturer);
	
	string game;
	int gameAmount;
	string publisher;
	string developer;
	cout << "How many games are available?" << endl;
	cin >> gameAmount;
	cin.ignore(100, '\n');
	cout << "Please enter the game played." << endl;
	getline(cin, game);
	cout << "Who published the game?" << endl;
	getline(cin, publisher);
	cout << "Who is the game dev.?" << endl;
	getline(cin, developer);

	string achievement;
	int achievementAmount;
	string description;
	int value;
	cout << "How many achievemnts are there?" << endl;
	cin >> achievementAmount;
	cin.ignore(100, '\n');
	cout << "Enter the achevement you would like to create." << endl;
	getline(cin, achievement);

	cout << "Press a key to continue.";
	_getch();
	system("cls");

	Platforms* platforms = new Platforms[platformAmount];
	Games* games = new Games[gameAmount];
	Achievements* achievements = new Achievements[achievementAmount];
	
	platforms->SetPlatforms(platforms, platformAmount, platform, manufacturer);
	cout << "The chosen platform is:" << endl;
	platforms->PrintPlatformTitle();
	
	games->SetGames(games, gameAmount, game, publisher, developer);
	cout << "In the game:" << endl;
	games->PrintGameTitle();

	cout << "What description would you like to give " << achievement << "." << endl;
	getline(cin, description);
	cout << "What is the value of this achievement?" << endl;
	cin >> value;
	cout << "Press a key to continue.";
	_getch(); 
	system("cls");

	achievements->SetAchievements(achievements, achievementAmount, achievement, description, value);
	cout << "You added the following achievement to " << game << " on " << platform << "." << endl;
	achievements->PrintAchievementTitle();
	achievements->PrintAchievementDetails();

}
