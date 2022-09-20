// Jeff McMillan 9-14-22 Guessing Game C++

// 1. No global variables. (Global constants are all right.)
// 2. No strings. Not ever. (You can use cstrings/character arrays, and the cstring and cctype libraries are okay. In fact, I recommend using strcmp and strlen in your projects.)
// 3. You should include <iostream>, not stdio. (This applies more to C programmers.)

// This program will present the user with prompts to make a integer guess
// within a given range. As the user guesses, the program returns whether the guess is too high, too low,
// or just right. When the user has either won or run out of guesses, the program asks if the user 
// would like to play again.

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
	
	// Enter game loop!
	while (playing) {
		
		// Introduce user to guessing process and pick random target!
		cout << std::endl << "A random number between " << GUESS_MIN << " and " << GUESS_MAX << " has been chosen..." << std::endl;
		int target = GUESS_MIN + rand() % GUESS_MOD;
		int guess = -1;
		int guessCt = 0;
		bool guessing = true;

		// Enter guess loop!
		while (guessing) {
			// Check if guess count has surpassed guess limit
			if (guessCt >= GUESS_LIMIT) {
				guessing = false;
				cout << "Out of guesses!" << std::endl;
				break;
			} else if (guessCt == GUESS_LIMIT-1) {
				cout << "One guess left, make it count!" << std::endl;
			}

			// Take guess input from user
			cout << "(" << GUESS_LIMIT-guessCt << ") Guess: ";
			cin >> guess;
			
			// Check guess against range and target.
			if (guess == target) {
				cout << guess << " was correct in " << guessCt << " tries!" << std::endl;
				guessCt++;
				guessing = false;
			} else if (guess < GUESS_MIN) {
				cout << guess << " was below the range " << GUESS_MIN << "-" << GUESS_MAX << "!" << std::endl;
			} else if (guess > GUESS_MAX) {	
				cout << guess << " was above the range " << GUESS_MIN << "-" << GUESS_MAX << "!" << std::endl;
			} else if (guess < target) {
				cout << guess << " was too low" << std::endl;
				guessCt++;
			} else {
				cout << guess << " was too high" << std::endl;
				guessCt++;
			}
		}

		// After user has guessed successfully or run out of guesses, prompt to play again.
		char again;
		cout << "Play again (y/n)? ";
		cin >> again;
		if (again == 'n' || again == 'N') playing = false;
	}
	cout << std::endl << "Thanks for playing!" << std::endl;

	return 0;
}

