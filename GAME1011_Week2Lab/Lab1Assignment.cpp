#include <iostream>
#include <string>
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

	void PrintPlatformCount()
	{
		for (int i = 0; i < platformCount; i++)
		{
			cout << "\n" << platforms[i].platformName;
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
	
	void PrintGameCount()
	{
		for (int i = 0; i < gameCount; i++)
		{
			cout << "\n" << games[i].gameName;
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

	void PrintAchievementCount()
	{
		for (int i = 0; i < achievementCount; i++)
		{
			cout << "\n" << achievements[i].achievementTitle;
		}
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
	string game;
	int gameAmount;
	string publisher;
	string developer;
	string achievement;
	int achievementAmount;
	string description;
	int value;

	cout << "Hello Player, what a great day to create achievements." << endl;
	cout << "How many platforms are available?" << endl;
	cin >> platformAmount;
	cout << "Please enter the platform used." << endl;
	cin >> platform;
	cout << "Who is the manufacturer?" << endl;
	cin >> manufacturer;
	cout << "How many games are available?" << endl;
	cin >> gameAmount;
	cout << "Please enter the game played." << endl;
	cin >> game;
	cout << "Who published the game?" << endl;
	cin >> publisher;
	cout << "Who is the game dev.?" << endl;
	cin >> developer;
	cout << "How many achievemnts are there?" << endl;
	cin >> achievementAmount;
	cout << "Enter the achevement you would like to create." << endl;
	cin >> achievement;
	cout << "What description would you like to give the achievement?" << endl;
	cin >> description;
	cout << "What is the value of this achievement?" << endl;
	cin >> value;

	Platforms* platforms = new Platforms[platformAmount];
	Games* games = new Games[gameAmount];
	Achievements* achievements = new Achievements[achievementAmount];
	platforms->SetPlatforms(platforms, platformAmount, platform, manufacturer);
	games->SetGames(games, gameAmount, game, publisher, developer);
	achievements->SetAchievements(achievements, achievementAmount, achievement, description, value);
	platforms->PrintPlatformCount();
	games->PrintGameCount();
	achievements->PrintAchievementCount();

}
