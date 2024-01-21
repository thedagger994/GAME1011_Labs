#include <iostream>
#include <string>
using namespace std;

class Achievement
{
public:
    Achievement(string title, string description, int value) : title(title), description(description), value(value)
    {
    
    }

    void displayAchievement() const
    {
        cout << "\n    Title: " << title << " (" << value << ")" << "\n      Description: " << description << "\n";
    }

private:
    string title;
    string description;
    int value;
};

class Game
{
public:
    Game(string gameName, string gamePublisher, string gameDeveloper, Achievement* achievementsArray)
        : gameName(gameName), gamePublisher(gamePublisher), gameDeveloper(gameDeveloper)
    {
        this->achievementsArray = achievementsArray;
    }

    ~Game()
    {
        delete[] achievementsArray;
    }

    void displayGameDetails() const
    {
        cout << "\nGame: " << gameName << "\n  Publisher: " << gamePublisher << "\n  Developer: " << gameDeveloper << "\n";
        cout << "  Achievements:\n";
        for (int i = 0; i < 5; i++)
        {
            achievementsArray[i].displayAchievement();
        }
    }

private:
    string gameName;
    string gamePublisher;
    string gameDeveloper;
    Achievement* achievementsArray;
};

class Platform
{
public:
    Platform(string n, string m, string* gamesArray) : platformName(n), platformManufacturer(m)
    {
        this->gamesArray = new string[5];
        for (int i = 0; i < 5; ++i)
        {
            this->gamesArray[i] = gamesArray[i];
        }
        cout << "Platform: " << platformName << "\nBy " << platformManufacturer << "\n";
    }

    ~Platform()
    {
        delete[] gamesArray;
    }

private:
    string platformName;
    string platformManufacturer;
    string* gamesArray;
};

int main()
{
    string ps5Games[5] = { "Call of Duty", "Horizon Forbidden West", "God of War 2", "Spiderman 2", "Rocket League" };

    Platform ps5("Playstation 5", "Sony", ps5Games);

    Achievement codAchievements[] = {
        {"First Blood", "Achieve your first kill", 10},
        {"Veteran", "Reach level 50", 50},
        {"Master of War", "Complete all missions", 100},
        {"Sharpshooter", "Score 100 headshots", 30},
        {"Collector", "Unlock all weapons", 75} };

    Achievement hzdAchievements[] = {
        {"Explorer", "Visit all regions", 20},
        {"Machine Hunter", "Defeat 50 machines", 40},
        {"Lore Master", "Discover all datapoints", 60},
        {"Master Hunter", "Defeat all legendary machines", 80},
        {"Platinum Trophy", "Unlock all other trophies", 100} };

    Achievement dmcAchievements[] = {
        {"Stylish!", "Achieve SSS rank", 20},
        {"Combo Master", "Perform a 100-hit combo", 30},
        {"Demon Slayer", "Defeat 1000 demons", 50},
        {"Dante's Legacy", "Complete the game with Dante", 75},
        {"Legendary Devil Hunter", "Complete the game on Dante Must Die difficulty", 100} };

    Achievement spdAchievements[] = {
        {"Web Slinger", "Travel 100 miles using webs", 20},
        {"Arachnid Avenger", "Defeat 500 enemies", 40},
        {"City Protector", "Complete all crimes in the city", 60},
        {"Wall Crawler", "Climb 100 buildings", 30},
        {"Spectacular Spider-Man", "Complete all challenges", 100} };

    Achievement rlAchievements[] = {
        {"First Goal", "Score your first goal", 10},
        {"Hat Trick", "Score three goals in a match", 30},
        {"Rocketeer", "Unlock all Rocket Trails", 50},
        {"Grand Champion", "Reach the Grand Champion rank", 80},
        {"Supersonic Legend", "Reach the Supersonic Legend rank", 100} };

    Game games[] = {
        Game("Call of Duty", "Activision", "Sledgehammer Games", codAchievements),
        Game("Horizon Forbidden West", "Sony", "Guerrilla Games", hzdAchievements),
        Game("Devil May Cry", "Capcom", "Capcom", dmcAchievements),
        Game("Spiderman 2", "Sony", "Insomniac Games", spdAchievements),
        Game("Rocket League", "Psyonix", "Psyonix", rlAchievements) };

    // Display the list of games
    cout << "Games available:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << ps5Games[i] << "\n";
    }

    // Player picks a game
    int selectedGame;
    cout << "Enter the number of the game you want to view: ";
    if (!(cin >> selectedGame) || selectedGame < 1 || selectedGame > 5)
    {
        cout << "Invalid selection.\n";
        return 1; // Exit with an error code
    }

    // Display the details of the selected game
    games[selectedGame - 1].displayGameDetails();

    return 0;
}