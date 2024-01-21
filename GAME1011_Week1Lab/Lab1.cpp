#include <iostream>
#include <string>
#include <vector>

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
    Game(string gameName, string gamePublisher, string gameDeveloper, const vector<Achievement>& achievements)
        : gameName(gameName), gamePublisher(gamePublisher), gameDeveloper(gameDeveloper), achievements(achievements)
    {

    }

    string getGameName() const
    {
        return gameName;
    }

    void displayGameDetails() const
    {
        cout << "\nGame: " << gameName << "\n  Publisher: " << gamePublisher << "\n  Developer: " << gameDeveloper << "\n";
        cout << "  Achievements:\n";
        for (const auto& achievement : achievements)
        {
            achievement.displayAchievement();
        }
    }

    void addAchievement(const Achievement& achievement)
    {
        achievements.push_back(achievement);
    }

private:
    string gameName;
    string gamePublisher;
    string gameDeveloper;
    vector<Achievement> achievements;
};

class Platform
{
public:
    Platform(string n, string m, const vector<string>& gamesVector) : platformName(n), platformManufacturer(m), gamesVector(gamesVector)
    {

    }

    ~Platform()
    {

    }

    string getPlatformName() const
    {
        return platformName;
    }

    void displayPlatformDetails() const
    {
        cout << "\nPlatform Details:\n";
        cout << "  Name: " << platformName << "\n  Manufacturer: " << platformManufacturer << "\n";
        cout << "  Games Available:\n";
        for (size_t i = 0; i < gamesVector.size(); i++)
        {
            cout << "    " << i + 1 << ". " << gamesVector[i] << "\n";
        }
    }

private:
    string platformName;
    string platformManufacturer;
    vector<string> gamesVector;
};

void createNewPlatform(vector<Platform>& platforms)
{
    string name, manufacturer;
    cout << "Enter platform name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter platform manufacturer: ";
    getline(cin, manufacturer);

    vector<string> gamesVector(5);
    for (int i = 0; i < 5; ++i)
    {
        cout << "Enter game " << i + 1 << " name for the platform: ";
        getline(cin, gamesVector[i]);
    }

    Platform* newPlatform = new Platform(name, manufacturer, gamesVector);

    platforms.push_back(*newPlatform);

    cout << "New platform created successfully!\n";
}

void createNewGame(vector<Game>& gameList, vector<Achievement>& achievementsList, const vector<Platform>& platforms)
{
    string name, publisher, developer;
    int platformIndex;

    cout << "Enter game name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    cout << "Enter game publisher: ";
    getline(cin, publisher);
    cout << "Enter game developer: ";
    getline(cin, developer);

    cout << "Available platforms:\n";
    for (size_t i = 0; i < platforms.size(); i++)
    {
        cout << i + 1 << ". " << platforms[i].getPlatformName() << "\n";
    }

    cout << "Select the platform for the game (enter the number): ";
    if (!(cin >> platformIndex) || platformIndex < 1 || platformIndex > static_cast<int>(platforms.size()))
    {
        cout << "Invalid selection. Game creation canceled.\n";
        return;
    }

    Game newGame(name, publisher, developer, {});

    for (int i = 0; i < 5; ++i)
    {
        int achievementIndex;
        cout << "Select achievement " << i + 1 << " for the game (enter the number): ";
        if (!(cin >> achievementIndex) || achievementIndex < 1 || achievementIndex > static_cast<int>(achievementsList.size()))
        {
            cout << "Invalid selection. Game creation canceled.\n";
            return;
        }
        newGame.addAchievement(achievementsList[achievementIndex - 1]);
    }

    gameList.push_back(newGame);
    cout << "New game created successfully!\n";
}

void createNewAchievement(vector<Achievement>& achievementsList)
{
    string title;
    string description;
    int value;

    cout << "Enter achievement title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter achievement description: ";
    getline(cin, description);
    cout << "Enter achievement value: ";
    cin >> value;

    Achievement newAchievement(title, description, value);
    achievementsList.push_back(newAchievement);
    cout << "New achievement created successfully!\n";
}

void viewPlatformDetails(const vector<Platform>& platforms)
{
    cout << "Available platforms:\n";
    for (size_t i = 0; i < platforms.size(); i++)
    {
        cout << i + 1 << ". " << platforms[i].getPlatformName() << "\n";
    }

    int platformIndex;
    cout << "Select the platform to view details (enter the number): ";
    if (!(cin >> platformIndex) || platformIndex < 1 || platformIndex > static_cast<int>(platforms.size()))
    {
        cout << "Invalid selection. Returning to the main menu.\n";
        return;
    }

    platforms[platformIndex - 1].displayPlatformDetails();
}

void viewGameDetails(const vector<Game>& gameList)
{
    cout << "Available games:\n";
    for (size_t i = 0; i < gameList.size(); i++)
    {
        cout << i + 1 << ". " << gameList[i].getGameName() << "\n";
    }

    int gameIndex;
    cout << "Select the game to view details (enter the number): ";
    if (!(cin >> gameIndex) || gameIndex < 1 || gameIndex > static_cast<int>(gameList.size()))
    {
        cout << "Invalid selection. Returning to the main menu.\n";
        return;
    }

    gameList[gameIndex - 1].displayGameDetails();
}

void viewAllAchievements(const vector<Achievement>& achievements)
{
    cout << "All Achievements:\n";
    for (const auto& achievement : achievements)
    {
        achievement.displayAchievement();
    }
}

int displayMainMenu()
{
    int choice;
    cout << "\n--- Main Menu ---\n";
    cout << "1. Create New Platform\n";
    cout << "2. Create New Game\n";
    cout << "3. Create New Achievement\n";
    cout << "4. View Platform Details\n";
    cout << "5. View Game Details and Achievements\n";
    cout << "6. View All Achievements\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";

    if (!(cin >> choice) || choice < 0 || choice > 6)
    {
        cout << "Invalid choice. Exiting.\n";
        return -1;
    }

    return choice;
}

int main()
{
    string ps5Games[5] = { "Call of Duty", "Horizon Forbidden West", "God of War 2", "Spiderman 2", "Rocket League" };

    Platform ps5("Playstation 5", "Sony", vector<string>(ps5Games, ps5Games + sizeof(ps5Games) / sizeof(ps5Games[0])));
    Achievement codAchievements[] =
    {
        {"First Blood", "Achieve your first kill", 10},
        {"Veteran", "Reach level 50", 50},
        {"Master of War", "Complete all missions", 100},
        {"Sharpshooter", "Score 100 headshots", 30},
        {"Collector", "Unlock all weapons", 75}
    };

    Achievement hzdAchievements[] = 
    {
        {"Explorer", "Visit all regions", 20},
        {"Machine Hunter", "Defeat 50 machines", 40},
        {"Lore Master", "Discover all datapoints", 60},
        {"Master Hunter", "Defeat all legendary machines", 80},
        {"Platinum Trophy", "Unlock all other trophies", 100}
    };

    Achievement dmcAchievements[] = 
    {
        {"Stylish!", "Achieve SSS rank", 20},
        {"Combo Master", "Perform a 100-hit combo", 30},
        {"Demon Slayer", "Defeat 1000 demons", 50},
        {"Dante's Legacy", "Complete the game with Dante", 75},
        {"Legendary Devil Hunter", "Complete the game on Dante Must Die difficulty", 100}
    };

    Achievement spdAchievements[] = 
    {
        {"Web Slinger", "Travel 100 miles using webs", 20},
        {"Arachnid Avenger", "Defeat 500 enemies", 40},
        {"City Protector", "Complete all crimes in the city", 60},
        {"Wall Crawler", "Climb 100 buildings", 30},
        {"Spectacular Spider-Man", "Complete all challenges", 100}
    };

    Achievement rlAchievements[] = 
    {
        {"First Goal", "Score your first goal", 10},
        {"Hat Trick", "Score three goals in a match", 30},
        {"Rocketeer", "Unlock all Rocket Trails", 50},
        {"Grand Champion", "Reach the Grand Champion rank", 80},
        {"Supersonic Legend", "Reach the Supersonic Legend rank", 100}
    };


    vector<Platform> platforms;
    vector<Game> gameList;
    vector<Achievement> achievementsList;
    vector<Achievement> achievements;

    vector<Achievement> codAchievementsVec(codAchievements, codAchievements + sizeof(codAchievements) / sizeof(Achievement));
    vector<Achievement> hzdAchievementsVec(hzdAchievements, hzdAchievements + sizeof(hzdAchievements) / sizeof(Achievement));
    vector<Achievement> dmcAchievementsVec(dmcAchievements, dmcAchievements + sizeof(dmcAchievements) / sizeof(Achievement));
    vector<Achievement> spdAchievementsVec(spdAchievements, spdAchievements + sizeof(spdAchievements) / sizeof(Achievement));
    vector<Achievement> rlAchievementsVec(rlAchievements, rlAchievements + sizeof(rlAchievements) / sizeof(Achievement));


    Game codGame("Call of Duty", "Activision", "Infinity Ward", codAchievementsVec);
    Game hzdGame("Horizon Forbidden West", "Sony", "Guerrilla Games", hzdAchievementsVec);
    Game dmcGame("Devil May Cry 5", "Capcom", "Capcom", dmcAchievementsVec);
    Game spdGame("Spiderman 2", "Sony", "Insomniac Games", spdAchievementsVec);
    Game rlGame("Rocket League", "Psyonix", "Psyonix", rlAchievementsVec);


    // Adding Games to the gameList vector
    gameList.push_back(codGame);
    gameList.push_back(hzdGame);
    gameList.push_back(dmcGame);
    gameList.push_back(spdGame);
    gameList.push_back(rlGame);

    // Adding Achievements to the achievements vector
    achievements.insert(achievements.end(), codAchievementsVec.begin(), codAchievementsVec.end());
    achievements.insert(achievements.end(), hzdAchievementsVec.begin(), hzdAchievementsVec.end());
    achievements.insert(achievements.end(), dmcAchievementsVec.begin(), dmcAchievementsVec.end());
    achievements.insert(achievements.end(), spdAchievementsVec.begin(), spdAchievementsVec.end());
    achievements.insert(achievements.end(), rlAchievementsVec.begin(), rlAchievementsVec.end());

    while (true)
    {
        int choice = displayMainMenu();

        switch (choice)
        {
        case 0:
            cout << "Exiting program. Goodbye!\n";
            return 0;

        case 1:
            createNewPlatform(platforms);
            break;

        case 2:
            createNewGame(gameList, achievementsList, platforms);
            break;

        case 3:
            createNewAchievement(achievementsList);
            break;

        case 4:
            viewPlatformDetails(platforms);
            break;

        case 5:
            viewGameDetails(gameList);
            break;

        case 6:
            viewAllAchievements(achievements);
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}