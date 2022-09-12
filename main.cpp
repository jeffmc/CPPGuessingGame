#include <iostream>
#include <cstdlib>
#include <ctime>

#define GUESS_LIMIT 5
#define GUESS_MIN 0
#define GUESS_MAX 100

#define GUESS_RANGE GUESS_MAX-GUESS_MIN
#define GUESS_MOD GUESS_RANGE+1;

using namespace std;

int main() {
	srand(time(NULL));
	bool playing = true;
	while (playing) {
		cout << std::endl << "A random number between " << GUESS_MIN << " and " << GUESS_MAX << " has been chosen..." << std::endl;
		int target = rand() % GUESS_MOD;
		int guess = -1;
		int guessCt = 0;
		bool guessing = true;
		while (guessing) {
			if (guessCt >= GUESS_LIMIT) {
				guessing = false;
				cout << "Out of guesses!" << std::endl;
				break;
			} else if (guessCt == GUESS_LIMIT-1) {
				cout << "One guess left, make it count!" << std::endl;
			}
			cout << "Guess: ";
			cin >> guess;
			guessCt++;
			if (guess == target) {
				cout << guess << " was correct in " << guessCt << " tries!" << std::endl;
				guessing = false;
			} else if (guess < target) {
				cout << guess << " was too low" << std::endl;
			} else {
				cout << guess << " was too high" << std::endl;
			}
		}
		char again;
		cout << "Play again (y/n)? ";
		cin >> again;
		if (again == 'n' || again == 'N') playing = false;
	}
	cout << std::endl << "Thanks for playing!" << std::endl;

	return 0;
}
