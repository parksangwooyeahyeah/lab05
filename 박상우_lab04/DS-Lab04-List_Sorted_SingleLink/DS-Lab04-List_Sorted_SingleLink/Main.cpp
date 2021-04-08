/**

*/

#include "Application.h"
#include <iomanip>
/**
*	program main function for data structures course.
*/
int main()
{
	Application app;	// Program application
	app.Run();			// run program

	return 0;
}


// Display command on screen and get a input from keyboard.
int GetCommand(int NUMOFCOMMAND, string commandList[])
{
	int select;
	int WIDTH = 0;
	// find the max length of commands
	for (int i = 0; i < NUMOFCOMMAND; i++) {
		if (commandList[i].size() > WIDTH) WIDTH = commandList[i].size();
	}

	while (1) {
		cout << "\t=" << setw(WIDTH + 5) << setfill('=') << "=\n";
		cout.fill(' ');
		for (int i = 0; i < NUMOFCOMMAND; i++) {
			cout << "\t|  " << left << setw(WIDTH) << commandList[i] << " |\n";
		}
		cout << "\t=" << right << setw(WIDTH + 5) << setfill('=') << "=\n";
		cout.fill(' ');
		cout << "\t  Select a function --> ";

		if (cin.fail() || !(cin >> select) || select < 0 || select>NUMOFCOMMAND)	// input fail or input value is out of bound
		{
			cout << "\t    ### Invalid Command Number. Select again  ####" << endl;
			cin.clear();	//clear flag
			cin.ignore(INT_MAX, '\n');	//empty input buffer
		}
		else {
			cin.clear();  // clear flag
			cin.ignore(INT_MAX, '\n');  // empty input buffer
			return select;
		}
	}
}

