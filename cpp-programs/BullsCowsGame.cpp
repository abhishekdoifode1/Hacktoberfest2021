#include <Windows.h>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

vector <int> numb();

int main() {
	srand(time(NULL));

	vector <int> guess = numb();
	vector <int> input(4);
	int bulls;
	int cows;
	char chr;
	bool game = true;
	cout << "Enter four different numbers: \n";
	while (game) {
		bulls = 0;
		cows = 0;

		cout << "> ";
		for (size_t i = 0; i < 4; i++)
		{
			cin >> chr;
			input[i] = chr - 48;
		}

		vector<int>::iterator it;
		for (size_t i = 0; i < 4; i++) {
			it = find(guess.begin(), guess.end(), input[i]);
			if (it != guess.end())
				if (guess[i] == input[i])
					bulls++;
				else
					cows++;
		}
		cout << "Bulls: " << bulls << ", cows: " << cows;
		cout << '\n';
		if (bulls == 4) {
			game = false;
			cout << "You win!\nGuessed number: ";
			for (size_t i = 0; i < guess.size(); i++)
			{
				cout << guess[i];
			}
			cout << "\nEnter any key to exit...";
			char temp;
			cin >> temp;
		}
	}

	return 0;
}

vector <int> numb() {
	vector <int> guess_vector;
	while (guess_vector.size() < 4)
	{
		int r = rand() % 10;
		if (find(guess_vector.begin(), guess_vector.end(), r) == guess_vector.end()) {
			guess_vector.push_back(r);
		}
	}
	return guess_vector;

}
