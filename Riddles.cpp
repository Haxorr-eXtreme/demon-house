#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Mysteries.h"
#include "Riddles.h"
using namespace std;

Riddles::Riddles()
{
    srand(time(0));
    setMysteryType("Riddle");
    riddle = 1 + rand() % 3;  // Reduced to 3 for bigger riddles
}

void Riddles::solveMystery(bool& chk1)
{
    string answer;

    if (riddle == 1)
    {
        cout << "- - - ->>> A shadow follows wherever I go." << endl;
        cout << "I have hands but never clap, a face but never talk." << endl;
        cout << "I am older than the mountains yet younger than the newborn." << endl;
        cout << "People glance at me for guidance, but I never move." << endl;
        cout << "At times, I vanish, swallowed by the night." << endl;
        cout << "What am I? <<<- - - -" << endl << endl;
        cout << "Answer ---> ";
        cin >> answer;
        cout << endl;

        if (answer == "clock" || answer == "Clock")
        {
            cout << "*** Correct! Time is on your side. Your Power & Visibility have increased! ***" << endl << endl;
            chk1 = true;
        }
        else
        {
            cout << "*** OOPS!!! Incorrect. Time slips away as your Power & Visibility diminish! ***" << endl << endl;
            chk1 = false;
        }
    }

    if (riddle == 2)
    {
        cout << "<> A traveler lost in the desert stumbles upon a cabin with no windows and a single door." << endl;
        cout << "Inside, he finds four candles, each burning at a different height." << endl;
        cout << "A note on the table reads: 'Choose wisely, for light brings life and darkness takes it away.'" << endl;
        cout << "The traveler must pick one candle to extinguish. If he chooses wrong, he may never leave." << endl;
        cout << "Which candle should he put out to escape? <>" << endl << endl;
        cout << "Guess ---> ";
        cin >> answer;
        cout << endl;

        if (answer == "the shortest one" || answer == "shortest candle")
        {
            cout << "*** Correct! The flame was a trick; by choosing the shortest, you found the hidden key! Power & Visibility increased! ***" << endl << endl;
            chk1 = true;
        }
        else
        {
            cout << "*** OOPS!!! Incorrect. The light fades, and the darkness consumes you. Power & Visibility decreased! ***" << endl << endl;
            chk1 = false;
        }
    }

    if (riddle == 3)
    {
        cout << "|--> In a mansion of endless corridors, five doors stand before you." << endl;
        cout << "Behind one lies certain doom; behind another, salvation." << endl;
        cout << "The first door is covered in ice, the second in fire." << endl;
        cout << "The third creaks with an eerie wind, the fourth drips with fresh blood." << endl;
        cout << "The final door looks harmless, but an old note warns: 'The quietest path may be the loudest mistake.'" << endl;
        cout << "Which door should you enter? <--|" << endl << endl;
        cout << "Guess ---> ";
        cin >> answer;
        cout << endl;

        if (answer == "third door" || answer == "the third")
        {
            cout << "*** Correct! The eerie wind was an illusion. You've found the safe passage! Power & Visibility increased! ***" << endl << endl;
            chk1 = true;
        }
        else
        {
            cout << "*** OOPS!!! Incorrect. A terrible fate awaits behind your choice. Power & Visibility decreased! ***" << endl << endl;
            chk1 = false;
        }
    }
}
