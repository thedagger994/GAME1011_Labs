/* pseudocode
begin program
input number of consoles
for all consoles:
	input name
	input manufacturer
	int number of games
	for all games:
		input name
		input publisher
		input developer
		input number of achievements
			for all achievements:
				input title
				input description
				input score
output summary of afformentioned information
end program
*/

#include <iostream>
#include <string>
using namespace std;

struct Achievement
{
	string title;
	string description;
	int score;
};

struct Game
{
	string name;
	string publisher;
	string developer;
	Achievement* achievements;
	int achievementCount;
};

struct Platform
{
	string name;
	string manufacturer;
	Game* games;
	int gameCount;
};

int main()
{
	cout << "please have no spaces in your input" << endl;
	int platformCount = 0;
	cout << "How many platforms would you like to create?" << endl;
	cin >> platformCount;
	Platform* platforms = new Platform[platformCount];

	// Step 1. Gather Input
	for (int i = 0; i < platformCount; i++)
	{
		//reference to individual platform in the array
		Platform& platform = platforms[i];
		cout << "What is the name of platform " << i + 1 << "?\n";
		cin >> platform.name;
		cout << "Who makes the " << platform.name << "?\n";
		cin >> platform.manufacturer;
		cout << "How many games are on the " << platform.name << "?\n";
		cin >> platform.gameCount;
		platform.games = new Game[platform.gameCount];

		for (int j = 0; j < platform.gameCount; j++)
		{
			//reference to individual game in the array
			Game& game = platform.games[j];
			cout << "What is the name of game " << j + 1 << "?\n";
			cin >> game.name;
			cout << "Who publishes " << game.name << "?\n";
			cin >> game.publisher;
			cout << "Who develops " << game.name << "?\n";
			cin >> game.developer;
			cout << "How many achievements does " << game.name << " have?\n";
			cin >> game.achievementCount;
			game.achievements = new Achievement[game.achievementCount];
			  
			for (int k = 0; k < game.achievementCount; k++)
			{
				//reference to individual achievement in the array
				Achievement& achievement = game.achievements[k];
				cout << "What is the title of achievement " << k + 1 << "?\n";
				cin >> achievement.title;
				cout << "What is the description of " << achievement.title << "?\n";
				cin >> achievement.description;
				cout << "What is the score of achievement " << achievement.title << "?\n";
				cin >> achievement.score;
			}
		}
	}

	// Step 2. Generate Output
	cout << endl;
	for (int i = 0; i < platformCount; i++)
	{
		Platform& platform = platforms[i];
		cout << "Name: " << platform.name << endl;
		cout << "Manufacturer: " << platform.manufacturer << endl;
		cout << "Number of games: " << platform.gameCount << endl << endl;

		for (int j = 0; j < platform.gameCount; j++)
		{
			Game& game = platform.games[j];
			cout << "Name: " << game.name << endl;
			cout << "Publisher: " << game.publisher << endl;
			cout << "Developer: " << game.developer << endl;
			cout << "Number of achievements: " << game.achievementCount << endl << endl;

			for (int k = 0; k < game.achievementCount; k++)
			{
				Achievement& achievement = game.achievements[k];
				cout << "Title: " << achievement.title << endl;
				cout << "Description: " << achievement.description << endl;
				cout << "Score: " << achievement.score << endl;
			}
			delete[] game.achievements;
		}
		delete[] platform.games;
	}
	delete[] platforms;

	return 0;
}