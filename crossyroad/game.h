#include <iostream>
#include <deque>
#include <vector>
#include <conio.h>
#include <time.h>
#include <string>
using namespace std;

const string END_MESG = "Game over!";
const string AGAIN = "Would You Like to Play again?";


// Class for the player
class Player
{
public:
	int x, y;
	Player(int width) { x = width / 2; y = 0; }
};


// Class for Lane
class Lane
{
private:
	deque<bool> cars;
	bool right;
public:
	Lane(int width)
	{
		for (int i = 0; i < width; i++)
			cars.push_front(true);
		right = rand() % 2;
	}
	void Move()
	{
		if (right)
		{
			if (rand() % 10 == 1)
			{
				cars.push_front(true);
			}
			else
			{
				cars.push_front(false);
			}
			cars.pop_back();
		}
		else
		{
			if (rand() % 10 == 1)
			{
				cars.push_back(true);
			}
			else
			{
				cars.push_back(false);
			}
			cars.pop_front();
		}

	}
	bool Positioncheck(int pos) { return cars[pos]; }
	void Directionchange() { right = !right; }
};


// Class for the Game
class GameGeneration
{
private:
	bool quit;
	int numberOfLanes;
	int width;
	int score;
	Player * player;
	vector<Lane*> map;
public:
	// CONSTRUCTOR
	GameGeneration(int w = 20, int h = 10)
	{
		numberOfLanes = h;
		width = w;
		quit = false;
		for (int i = 0; i < numberOfLanes; i++)
		{
			map.push_back(new Lane(width));
		}
		player = new Player(width);
	}
	~GameGeneration()
	{
		delete player;
		for (int i = 0; i < map.size(); i++)
		{
			Lane * current = map.back();
			map.pop_back();
			delete current;
		}
	}
	void Draw()
	{
		system("cls");
		for (int i = 0; i < numberOfLanes; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 0 && (j == 0 || j == width - 1)) {
					cout << "S";
				}
				if (i == numberOfLanes - 1 && (j == 0 || j == width - 1)) {
					cout << "F";
				}
				if (map[i]->Positioncheck(j) && i != 0 && i != numberOfLanes - 1)
				{
					cout << "#";
				}
				else if (player->x == j && player->y == i)
				{
					cout << "V";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		cout << "Score: " << score << endl;
	}
	void Input()
	{
		if (_kbhit())
		{
			char current = _getch();
			if (current == 'a')
			{
				player->x--;
			}
			if (current == 'd')
			{
				player->x++;
			}
			if (current == 'w')
			{
				player->y--;
			}
			if (current == 's')
			{
				player->y++;
			}
			if (current == 'q')
			{
				quit = true;
			}
		}
	}
	void Logic()
	{
		for (int i = 1; i < numberOfLanes - 1; i++)
		{
			if (rand() % 10 == 1)
			{
				map[i]->Move();
			}
			if (map[i]->Positioncheck(player->x) && player->y == i)
			{
				quit = true;
			}
		}
		if (player->y == numberOfLanes - 1)
		{
			score++;
			player->y = 0;
			cout << "\x07";
			map[rand() % numberOfLanes]->Directionchange();
		}
	}
	void Move()
	{
		while (!quit)
		{
			Input();
			Draw();
			Logic();
		}
	}
};
