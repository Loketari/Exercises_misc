#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

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

int main()
{
	cout << "Enter day of the week and value separated by whitespace. You may enter several day-value pairs. \nDo not use punctuation marks. " <<
		"Input for incorrect day names will be ignored.\nTo stop input type 'q 0'\n";

	vector<vector<int>> days{ {},{},{},{},{},{},{} };
	string inputDay;
	int inputVal;
	vector<int> oldSizes(7);
	vector<int> totalSums(7);
	vector<int> newSums(7);
	int numRejected = 0;
	char userChoice = 0;

	do {
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
		write_out(days);

		newSums = count_sums(days, oldSizes);
		cout << "\n\nTotal sum of elements for:";
		for (int ii = 0; ii < totalSums.size(); ++ii) {
			totalSums[ii] += newSums[ii];
			cout << '\n' << dayNames[ii] << ": " << totalSums[ii];
		}

		for (int jj = 0; jj < oldSizes.size(); ++jj)
			oldSizes[jj] = days[jj].size(); //updating oldSizes for use in the next cycle (to find out how many el-ts will have been added)

		cout << "\nThe number of rejected values during this input session is: " << numRejected;

		cout << "\n\nType y to add new values: ";
		cin >> userChoice;

	} while (userChoice == 'y');
	return 0;
}

