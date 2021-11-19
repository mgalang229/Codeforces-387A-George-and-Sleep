#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string x;
	cin >> x;
	string y;
	cin >> y;
	// extract the hours and mins from the two given times
	int x_hrs = stoi(x.substr(0, 2));
	int x_mins = stoi(x.substr(3, 2));
	int y_hrs = stoi(y.substr(0, 2));
	int y_mins = stoi(y.substr(3, 2));
	// calculate the minutes-part
	int s_mins = 0;
	if (y_mins > x_mins) {
		s_mins = 60 - (y_mins - x_mins);
	} else {
		s_mins = x_mins - y_mins;
	}
	// calculate the hours-part
	int s_hrs = 0;
	if (y_hrs > x_hrs) {
		int upper = 24;
		if (y_mins > x_mins) {
			upper--;
		}
		s_hrs = upper - (y_hrs - x_hrs);
	} else if (y_hrs == x_hrs && y_mins > x_mins) {
		s_hrs = 23;
	} else {
		if (y_mins > x_mins) {
			x_hrs--;
		}
		s_hrs = x_hrs - y_hrs;
	}
	// convert the hours answer into a string
	string hours = (s_hrs < 10 ? "0" : "");
	if (s_hrs < 10) {
		hours += string(1, (char) 48 + s_hrs);
	} else {
		hours += to_string(s_hrs);
	}
	// convert the minutes answer into a string
	string minutes = (s_mins < 10 ? "0" : "");
	if (s_mins < 10) {
		minutes += string(1, (char) 48 + s_mins);
	} else {
		minutes += to_string(s_mins);
	}
	// output
	cout << (hours + ":" + minutes) << '\n';
	return 0;
}
