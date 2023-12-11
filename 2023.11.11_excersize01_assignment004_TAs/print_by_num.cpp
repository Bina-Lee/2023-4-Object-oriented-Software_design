#include "problem1.h"

//------------------------------
print_by_num::print_by_num(string txt_name) : find_txt(txt_name) {
	for (int i = 0; i < length(); i++)
	{
		find_map.push_back(new map_list(number(i), name(i), location(i)));
	}
}

void print_by_num::print(string find) {
	if (finding("num", find)) {
		cout << "해당 약국이 존재하지 않습니다." << endl;
		return;
	}
	for (auto& n : find_map) {
		if (*n == find) {
			n->print();
			return;
		}
	}
}

void print_by_num::loading() {
	cout << "정상적으로 print_by_num이 로드되었습니다." << endl;
}