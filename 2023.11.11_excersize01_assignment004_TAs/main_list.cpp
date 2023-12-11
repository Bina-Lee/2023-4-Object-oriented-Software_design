#include "problem1.h"

//-------------------------------------------
// class main_list 정의
//-------------------------------------------

main_list::main_list(string txt_name) {
    size=0;

	ifstream file(txt_name);

	if (!file.is_open()) {
		cerr << "fail to open file" << endl;
		return; //error
	}
	else {
		//cout << "success to open file" << endl;
	}

	getline(file, line);

	while (getline(file, line)) {
		istringstream iss(line);

		getline(iss, field, ','); // num
		getline(iss, field, ','); // name

		names.push_back(field);

		getline(iss, field, ','); // phone number

		numbers.push_back(field);

		getline(iss, field); // location

		locations.push_back(field);

		size++;
	}
}

int main_list::length() {
	return size;
}

string main_list::name(int i) {
	return names[i];
}

string main_list::number(int i) {
	return numbers[i];
}

string main_list::location(int i) {
	return locations[i];
}

void main_list::loading() {
	cout << "정상적으로 main_list가 로드되었습니다." << endl;
}

bool main_list::finding(string type, string finds) {
	if (type == "name") {
		return (find(names.begin(), names.end(), finds) == names.end());
	}
	else if (type == "num") {
		return (find(numbers.begin(), numbers.end(), finds) == numbers.end());
	}
	else if (type == "loc") {
		return (find(locations.begin(), locations.end(), finds) == locations.end());
	}
	else {
		return false;
	}
}