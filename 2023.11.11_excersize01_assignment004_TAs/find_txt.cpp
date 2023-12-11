#include "problem1.h"

find_txt::find_txt(string txt_name) : main_list(txt_name){
	for (int i = 0; i < length(); i++) {
		//-------------------------------  동으로 찾기 초기화
		string loc = location(i);

		size_t pos = 0;
		size_t found = string::npos;

		while ((pos = loc.find("동,", pos)) != string::npos) {
			found = pos;
			pos += 3; // utf-8 3바이트 크기 고려
		}
		if (found == string::npos) pos = 0;
		while ((pos = loc.find("동)", pos)) != string::npos) {
			found = pos;
			pos += 3; // utf-8 3byte
		}
		if (found != std::string::npos) {
			string matchedText = loc.substr(found - 6, 9);

			if (d_map.find(matchedText) == d_map.end()) {
				list<string> n;
				n.push_back(name(i));
				d_map[matchedText] = n;
			}
			else {
				d_map[matchedText].push_back(name(i));
			}
		}
		//----------------------------------  키워드로 찾기 초기화
		//----------------------------------  초성 분석하기 초기화
		temp = name(i);

		utf32String = converter.from_bytes(temp);

		for (char32_t c : utf32String) {

			if (c >= 0xAC00 && c <= 0xD7A3) { // 한글 범위

				c = (c - 0xAC00) / 588 + 0x1100; // 한글 초성 index후 해당 단어 찾기
				// 한글 종성도 구해야함.
				cho = converter.to_bytes(c);
			}
			else if ((c >= 0x0041 && c <= 0x0005A) || (c >= 0x0061 && c <= 0x007A)) { // 영어 소문자 및 대문자 범위
				// 모음 제외 따로 코딩 필요
				cho = converter.to_bytes(c);
			}

			if (a_map.find(cho) == a_map.end()) {
				a_map[cho] = 1;
			}
			else {
				a_map[cho] += 1;
			}
		}
	}
}

void find_txt::print_by_list(string dong_name) {
	if (d_map.find(dong_name) == d_map.end()) {
		cout << "해당 동은 없습니다.." << endl;
	}
	else {
		cout << dong_name << " : ";
		for (auto& n : d_map[dong_name]) {
			cout << n << " | ";
		}
		cout << endl;
	}
}

void find_txt::print() {  // 자음 분석
	for (auto& it : a_map) {
		cout << it.first << " : " << it.second << endl;
	}
}

void find_txt::print(string key_ward) {
	for (int i = 0; i < length(); i++) {
		temp = name(i);
		size_t pos = 0;
		while ((pos = temp.find(key_ward, pos)) != string::npos) {
			keys.push_back(temp);
			break;
		}
	}

	for (auto& a : keys) {
		cout << a << endl;
	}
}

void find_txt::loading() {
	cout << "정상적으로 find_txt가 로드되었습니다." << endl;
}