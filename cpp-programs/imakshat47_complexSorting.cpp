/*
  Sorting: Comparator

    Sample Input

        5
        amy 100
        david 100
        heraldo 50
        aakansha 75
        aleksa 150
        Sample Output
        
        aleksa 150
        amy 100
        david 100
        aakansha 75
        heraldo 50
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Player
{
    int score;
    string name;
};

class Checker
{
public:
    // complete this method
    static int comparator(Player a, Player b)
    {
        if (a.score < b.score)
        {
            return -1;
        }
        else if (a.score == b.score)
        {
            if (a.name.compare(b.name) == 0)
                return 0;
            else if ((a.name.compare(b.name)) > 0)
            {
                return -1;
            }
        }
        return 1;
    }
};

bool compare(Player a, Player b)
{
    if (Checker::comparator(a, b) == -1)
        return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<Player> players;
    string name;
    int score;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> score;
        Player player;
        player.name = name, player.score = score;
        players.push_back(player);
    }
    sort(players.begin(), players.end(), compare);
    for (int i = 0; i < players.size(); i++)
    {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}