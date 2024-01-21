//#include <iostream>
//#include <string.h>
//#include <string>
//#include "conio.h"
//
//using namespace std;
//
//struct Platforms
//{
//	Platforms* platforms;
//	int platformCount;
//	string platformName;
//	string platformManufacturer;
//
//	Platforms()
//	{
//
//	}
//
//	void PrintPlatformTitle()
//	{
//		for (int i = 0; i < platformCount; i++)
//		{
//			cout << platforms[i].platformName << "\n\n";
//		}
//	}
//
//	void PrintPlatformDetails()
//	{
//		for (int i = 0; i < platformCount; i++)
//		{
//			cout << "\n" << platforms[i].platformManufacturer << endl;
//		}
//	}
//
//	void SetPlatforms(Platforms* platforms, int platformCount, string platformName, string platformManufacturer)
//	{
//		this->platforms = platforms;
//		this->platformCount = platformCount;
//		this->platformName = platformName;
//		this->platformManufacturer = platformManufacturer;
//	}	
//};
//
//struct Games
//{
//	Games* games;
//	int gameCount;
//	string gameName;
//	string gamePublisher;
//	string gameDeveloper;
//
//	Games()
//	{
//
//	}
//	
//	void PrintGameTitle()
//	{
//		for (int i = 0; i < gameCount; i++)
//		{
//			cout << games[i].gameName << "\n\n";
//		}
//	}
//
//	void PrintGameDetails()
//	{
//		for (int i = 0; i < gameCount; i++)
//		{
//			cout << "\nMade by:\n" << games[i].gamePublisher << " and " << games[i].gameDeveloper << endl;
//		}
//	}
//
//	void SetGames(Games* games, int gameCount, string gameName, string gamePublisher, string gameDeveloper)
//	{
//		this->games = games;
//		this->gameCount = gameCount;
//		this->gameName = gameName;
//		this->gamePublisher = gamePublisher;
//		this->gameDeveloper = gameDeveloper;
//	}
//};
//
//struct Achievements
//{
//	Achievements* achievements;
//	int achievementCount;
//	string achievementTitle;
//	string achievementDescription;
//	int achievementValue;
//
//	Achievements()
//	{
//
//	}
//
//	void PrintAchievementTitle()
//	{
//		for (int i = 0; i < achievementCount; i++)
//		{
//			cout << achievements[i].achievementTitle;
//		}
//	}
//
//	void PrintAchievementDetails()
//	{
//		cout << "\nDescription:\n" << achievementDescription << "\nWith value " <<achievementValue << endl;
//	}
//
//	void SetAchievements(Achievements* achievements, int achievementCount, string achievementTitle, string achievementDescription, int achievementValue)
//	{
//		this->achievements = achievements;
//		this->achievementCount = achievementCount;
//		this->achievementTitle = achievementTitle;
//		this->achievementDescription = achievementDescription;
//		this->achievementValue = achievementValue;
//	}
//};
//
//int main()
//{
//
//}