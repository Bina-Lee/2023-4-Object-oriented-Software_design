#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <codecvt>
#include <algorithm>

using namespace std;

class main_list {
private:
	string line;
	string field;
	vector<string> names;
	vector<string> numbers;
	vector<string> locations;
	int size;
public:
	main_list(string);
	int length();
	string name(int);
	string number(int);
	string location(int);
	void loading();
	bool finding(string, string);  // algorithm + iterator
};

class find_txt : public main_list {  // inheritance
private:
	map<string, list<string> > d_map;
	vector<string> keys;
	map<string, int> a_map;
	wstring_convert<codecvt_utf8<char32_t>, char32_t> converter; // utf-8 to utf-32
	string cho; // 초성 임시 저장 변수
	u32string utf32String; // utf-32 임지 저장 변수
	string temp;
public:
	find_txt(string); 
	void print_by_list(string);
	void print(string);  // 키워드 찾기
	void print();  // 자음 찾기 function overloading
	virtual void loading(); //virtual function
};

class map_list {
private:
	string temp1, temp2;
public:
	map_list(string, string, string);
	bool operator==(string&); // operator overloading
	void print();  // functoin overriding
};

class print_by_name : public find_txt {
private:
	list<map_list*> find_map;
public:
	print_by_name(string);
	void print(string);
	void loading();
};

class print_by_num : public find_txt {
private:
	list<map_list*> find_map;
public:
	print_by_num(string);
	void print(string);
	void loading();
};

class print_by_loc : public find_txt {
private:
	list<map_list*> find_map;
public:
	print_by_loc(string);
	void print(string);
	void loading();
};