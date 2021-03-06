#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<string> dayNames{ "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

void write_out(vector<vector<int>> days)
{
	std::cout << "\nThe values for days of the week are:";

	for (int i = 0; i < dayNames.size(); ++i) {
		cout << endl << dayNames[i] << ": ";

		for (int v : days[i])
			cout << v << " ";
	}
}

vector<int> count_sums(vector<vector<int>> days, vector<int> oldSizes) //we are only finding sums of the newly added elements
{
	vector<int> sums(7);
	//cout << "Sum of values for ";

	for (int i = 0; i < dayNames.size(); ++i) {
		//cout << dayNames[i] << ": ";

		int elAdded = days[i].size() - oldSizes[i];  //how many elements were added?

		for (int j = elAdded; j >= 1; --j) {
			sums[i] += days[i][days[i].size() - j]; //counting the sum of newly added for each day (backwards)
		}

	}
	return sums;
}

void get_input(vector<vector<int>> &days, int &numRejected)
{
    string inputDay;
    int inputVal;

	while (cin >> inputDay >> inputVal) {

		if (inputDay == "Mon" || inputDay == "Monday" || inputDay == "monday")
			days[0].push_back(inputVal);
		else if (inputDay == "Tue" || inputDay == "Tuesday" || inputDay == "tuesday")
			days[1].push_back(inputVal);
		else if (inputDay == "Wed" || inputDay == "Wednesday" || inputDay == "wednesday")
			days[2].push_back(inputVal);
		else if (inputDay == "Thu" || inputDay == "Thursday" || inputDay == "thursday")
			days[3].push_back(inputVal);
		else if (inputDay == "Fri" || inputDay == "Friday" || inputDay == "friday")
			days[4].push_back(inputVal);
		else if (inputDay == "Sat" || inputDay == "Saturday" || inputDay == "saturday")
			days[5].push_back(inputVal);
		else if (inputDay == "Sun" || inputDay == "Sunday" || inputDay == "sunday")
			days[6].push_back(inputVal);
		else if (inputDay == "q")
			break;
		else
			numRejected++;
	}
}

int main()
{
	cout << "Enter day of the week and value separated by whitespace. You may enter several day-value pairs. \nDo not use punctuation marks. " <<
		"Input for incorrect day names will be ignored.\nTo stop input type 'q 0'\n";

	vector<vector<int>> days{ {},{},{},{},{},{},{} };
	vector<int> totalSums(7);
	char userChoice = 0;

	do {

        vector<vector<int>> new_data{ {},{},{},{},{},{},{} };
        int rejectedCnt = 0;

        get_input(new_data, rejectedCnt);

        for (int i = 0; i < totalSums.size(); i++){

            days[i].insert(days[i].end(), new_data[i].begin(), new_data[i].end());

            totalSums[i] += std::accumulate(new_data[i].begin(), new_data[i].end(), 0);
            cout << '\n' << dayNames[i] << ": " << totalSums[i];
        }

        write_out(days);

		cout << "\nThe number of rejected values during this input session is: " << rejectedCnt;

		cout << "\n\nType y to add new values: ";
		cin >> userChoice;

	} while (userChoice == 'y');
	return 0;
}

