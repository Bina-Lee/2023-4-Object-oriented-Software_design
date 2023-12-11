#include "problem1.h"

map_list::map_list(string a, string b, string c) {
	temp1 = a;
	temp2 = b + ", " + c;
}

bool map_list::operator==(string& str) {
	return temp1 == str;
}

void map_list::print() {
	cout << temp2 << endl;
}
