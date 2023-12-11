#include <iostream>
//#include <Windows.h>
#include "problem1.h"

using namespace std;

int main() {
	// SetConsoleOutputCP(CP_UTF8);
	// SetConsoleCP(CP_UTF8);

	find_txt* m;
	find_txt f("인천연수구약국리스트.txt");
	print_by_name na("인천연수구약국리스트.txt");
	print_by_num nu("인천연수구약국리스트.txt");
	print_by_loc lo("인천연수구약국리스트.txt");
	int c = -1;
	string word;

	m = &f;
	m->loading();
	m = &na;
	m->loading();
	m = &nu;
	m->loading();
	m = &lo;
	m->loading();

	while (c <= 6) {
		cout << "어떤 방식으로 찾으시겠습니까? \n1 : 약국 이름으로\n2 : 약국 전화번호로\n3 : 약국 도로명으로\n4 : 약국 이름 키워드로\n5 : 약국 동별로\n6 : 약국 이름분석\n7 : 종료" << endl;
		
		cin >> c;
		cin.ignore();

		switch (c) {
		case 1:
			cout << "이름을 입력해 주세요 : ";
			getline(cin, word);
			// system("cls");
			na.print(word);
			break;
		case 2:
			cout << "전화번호를 입력해 주세요 : ";
			getline(cin, word);
			// system("cls");
			nu.print(word);
			break;
		case 3:
			cout << "도로명을 입력해 주세요 : ";
			getline(cin, word);
			// system("cls");
			lo.print(word);
			break;
		case 4:
			cout << "키워드를 입력해 주세요 : ";
			getline(cin, word);
			// system("cls");
			f.print(word);
			break;
		case 5:
			cout << "동을 입력해 주세요 : ";
			getline(cin, word);
			// system("cls");
			f.print_by_list(word);
			break;
		case 6:
			// system("cls");
			f.print();
			break;
		default:
			cout << "종료...";
			break;
		}
		cout << endl;
	}

	return 0;
}
