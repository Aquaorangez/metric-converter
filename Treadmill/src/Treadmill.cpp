//============================================================================
// Name        : Treadmill.cpp
// Author      : Mick Campitelli
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

double convertToMPH(double speed);
double convertToMPH(int minutes, int seconds);

int main(void) {
	int direction, minutes, seconds;
	double result;
	string milePace, token, token2;
	string delimiter = ",";
	size_t pos = 0;

	cout
			<< "If you wish to convert to MPH from a mile pace, enter 1. Otherwise, enter 2 if you are "
					"converting from a speed in KPH" << endl;
	cin >> direction;

	if (cin.fail() || (direction != 1 && direction != 2)) {
		cout << "Invalid output. Try again." << endl;
	} else if (direction == 1) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Enter mile pace (minutes and seconds separated by a comma)"
				<< endl;
		getline(cin, milePace);
		pos = milePace.find(delimiter);
		if (cin.fail() || (pos != 1 && pos != 2)) {
			cout << "Invalid input. Try Again" << endl;

		} else {

			token = milePace.substr(0, pos);
			token2 = token2 = milePace.substr(pos + 1, milePace.length());

			stringstream placeholder(token);
			placeholder >> minutes;

			stringstream placeholder2(token2);
			placeholder2 >> seconds;

			cout << "Your speed is " << convertToMPH(minutes, seconds) << " MPH"
					<< endl;
		}
	}

	else if (direction == 2) {
		cout << "Enter your speed in KPH" << endl;
		cin >> result;
		cout << "Your speed is " << convertToMPH(result) << " MPH" << endl;
	}

}

double convertToMPH(int minutes, int seconds) {
	if (minutes < 0) {
		cout << "Assuming you meant positive minutes.." << endl;
		minutes = minutes * -1;
	}
	if (seconds < 0) {
		cout << "Assuming you meant positive seconds..." << endl;
		seconds = seconds * -1;
	}
	if (minutes == 0 && seconds == 0) {
		cout << "You have to run first!" << endl;
		return 0; }
	double secondsTotal = minutes * 60 + seconds;
	return 3600 / secondsTotal;
}

double convertToMPH(double speed) {
	if (speed < 0) {
		cout << "Assuming you meant a positive speed..." << endl;
		speed = speed * -1;
	}
	return speed * 0.621371;

}

