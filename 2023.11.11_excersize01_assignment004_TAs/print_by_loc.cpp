#include "problem1.h"

//------------------------------
print_by_loc::print_by_loc(string txt_name) : find_txt(txt_name) {
	for (int i = 0; i < length(); i++)
	{
		find_map.push_back(new map_list(location(i), number(i), name(i)));
	}
}

void print_by_loc::print(string find) {
	if (finding("loc", find)) {
		cout << "해당 약국이 존재하지 않습니다." << endl;
		return;
	}
	for(auto & n : find_map) {
		if (*n == find) {
			n->print();
			return;
		}
	}
}

void print_by_loc::loading() {
	cout << "정상적으로 print_by_loc이 로드되었습니다." << endl;
}