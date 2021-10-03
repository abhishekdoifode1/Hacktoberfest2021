#include <iostream>
#include <deque>
#include <vector>
#include <conio.h>
#include <time.h>
#include <string.h>
using namespace std;


string Check;


int main()
{   
    while (1) 
    {
    // Randomization for the time 
        
        srand(time(NULL));
    // Simulate the Game
        cGame game(30, 5);
        game.Run();
        cout << END_MESG << endl;
        cout << AGAIN << endl;
        getchar();
        cin > check;
        if (check == "Yes") 
        {
            continue;
        }
        else 
        {
            break;
        }
    }   
    return 0;
}

