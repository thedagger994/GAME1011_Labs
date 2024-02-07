#include <vector>
#include <iostream>
using namespace std;

// Base class (no : at the end)
struct Enemy
{
	//virtual declaration - this function wants to be overriden by derived classes
	virtual float MaxHealth()
	{
		return 100.0f;
	}
};

struct Orc : public Enemy
{
	float MaxHealth() override
	{
		return 200.0f;
	}
};

struct BabyOrc : public Orc
{
	float MaxHealth() override
	{
		return 50.0f;
	}
};

struct CraigTheOrc : public BabyOrc
{
	float MaxHealth() final // not to be overriden
	{
		return 5.0f;
	}
};

float TotalEnemiesHealth(const vector<Enemy*>& enemies)
{
	float health = 0.0f;
	// Range-based for-loops (i : range) automatically deduce the type of the container
	// The following is a manual implementation of a range-based for loop
	//for (int i = 0; i < enemies.size(); i++)
	//{
	//	Enemy* enemy = enemies[i];
	//	health += enemy->MaxHealth();
	//}

	for (Enemy* enemy : enemies)
		health += enemy->MaxHealth();
	return health;
}

enum Type
{
	RECTANGLE,
	TRIANGLE,
	CIRCLE
};

struct Shape
{
	virtual Type GetType() = 0;
};

struct Rectangle : public Shape
{
	Type GetType() override
	{
		return RECTANGLE;
	}
};

struct Triangle : public Shape
{
	Type GetType() override
	{
		return TRIANGLE;
	}
};

struct Circle : public Shape
{
	Type GetType() override
	{
		return CIRCLE;
	}
};

int main()
{
	Enemy* enemy = new Enemy;
	Enemy* orc = new Orc;
	Enemy* baby = new BabyOrc;
	Enemy* craig = new CraigTheOrc;
	std::vector<Enemy*> enemies;
	enemies.push_back(enemy);
	enemies.push_back(orc);
	enemies.push_back(baby);
	enemies.push_back(craig);
	float total = TotalEnemiesHealth(enemies); //100+200+50+5=355
	cout << "Total health of enemies are: " << total << endl;

	vector<Shape*> shapes;
	shapes.push_back(new Rectangle);
	shapes.push_back(new Triangle);
	shapes.push_back(new Circle);
	for (Shape* shape : shapes)
	{
		switch (shape->GetType())
		{
		case Type::RECTANGLE:
			// *Handle rectangle collision*
			cout << "\nRectangle!\n";
			break;

		case Type::TRIANGLE:
			// *Handle triangle collision*
			cout << "\nTriangle!\n";
			break;

		case Type::CIRCLE:
			// *Handle circle collision*
			cout << "\nCircle!\n";
			break;
		}
	}

	return 0;
}