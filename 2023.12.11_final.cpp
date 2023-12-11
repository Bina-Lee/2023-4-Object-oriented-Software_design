#if 0

#include <iostream>
using namespace std;

/*
	Class template을 이용한 class Box를 구현하시오.
	.set( ) 함수는 argument를 class내 변수에 저장
	.get( ) 함수는 변수 저장된 값을 반환

	Class Box는 아래 main함수에서 사용됨.

*/
template <typename T>
class Box{
public:
    T v;
    void set(T t){
        v=t;
    }
    T get(){
        return v;
    }
};

//------------------ 이하 수정 금지 -------------

int main() {
	Box<int>    box;
	box.set(100);
	cout << box.get() << endl;

	Box<double> box1;
	box1.set(3.141592);
	cout << box1.get() << endl;
	return 0;
}


#endif

#if 0

#include <iostream>
using namespace std;

/*
	Class template을 이용한 class Box2를 구현하시오.
	.set_first, second( ) 함수는 argument를 class내 변수에 저장
	.get_first, second( ) 함수는 변수 저장된 값을 반환

	Class Box2는 아래 main함수에서 사용됨.

*/
template <typename T, typename U>
class Box2{
public:
    T first;
    U second;
    void set_first(T v){
        first=v;
    }
    void set_second(U v){
        second=v;
    }
    T get_first(){
        return first;
    }
    U get_second(){
        return second;
    }
};

int main()
{
	Box2<int, double> b;
	b.set_first(10);
	b.set_second(3.14);
	cout << "(" << b.get_first() << ", " << b.get_second() << ")" << endl;
	return 0;
}

#endif

#if 01

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	Class template을 이용한 class MyStorage를 구현하시오.
	.receive_input( )은 입력값을 내부에 저장
	.show_all()은 저장된 값을 "내림차순"(작아지는 순)으로, 공백 1개로 분리하여 보여준다.
	내부 저장소로는 vector를 이용한다.
	아래 main함수에서 사용가능하여야 한다.
*/
template <typename T>
class MyStorage{
public:
    vector<T> t;
    void receive_input(T v){
        t.push_back(v);
    }
    void show_all(){
        for(T& x1:t){
            for(T& x2:t){
                if(x1>x2){
                    T temp=x1;
                    x1=x2;
                    x2=temp;
                }
            }
        }
        for(int i=0;i<t.size();i++){
            cout<<t[i];
            if(i==t.size()-1){
                break;
            }
            cout<<" ";
        }
        cout<<endl;
    }
};

// ----------- 이하 수정금지 ---------------------
int main()
{
	MyStorage<int> ms;
	while (true) {
		int k;
		cin >> k;
		ms.receive_input(k);
		if (k < 0) {
			break;
		}
	}
	ms.show_all();

	MyStorage<string> ms2;
	while (true) {
		string k;
		cin >> k;
		ms2.receive_input(k);
		if (k == "end") {
			break;
		}
	}
	ms2.show_all();
	return 0;
}

#endif

#if 0
STL에서 제공하는 deque (double ended queue)를 이용하여 프로그래밍 하시오.

양의 정수 1개와 문자열(공백없음) 쌍이 1개의 데이터로
입력될 때,
홀수들은 deque에 push_back(),
짝수들은 push_front() 함수를 사용하여 저장한다.

입력 정수 -1은 입력의 종료를 나타낸다
이후 양의 정수 N이 입력되면,
front에서 먼저 1개,
back에서 한 개 번갈아가며 데이터를 pop하여
양의 정수들의 누적합을 구한다.
그 합이 N보다 크거나 같아지거나, 데이터가 남아있지 않다면 pop을 멈춘다.

이 때, deque에 남아있는 데이터들을
양의 정수의 내림차순으로 숫자와 문자열을 1개 공백으로 구분하여 한 줄에 출력한다.
단, 숫자가 같다면, 문자열의 오름차순으로 출력한다.

다음 줄에는 문자열의 오름차순으로 숫자와 문자열을 1개 공백으로 한 줄에 출력한다.
단, 문자열이 같다면, 숫자의 내림차순으로 출력한다.
각 줄의 마지막에는 1개의 공백문자 뒤에 줄바꿈 표시가 있어야 한다.

데이터가 남아있지 않다면, NoData(끝에 줄바꿈문자)만 1줄 출력한다.
입력
7 charsy
2 sunny
1 charsy
4 sunny
5 farng
3 charsy
7 macy
4 salon
9 tue
10 sunny
-1 end
0
출력
9 tue 7 charsy 7 macy 5 farng 4 salon 4 sunny 3 charsy 2 sunny 1 charsy 
7 charsy 3 charsy 1 charsy 5 farng 7 macy 4 salon 4 sunny 2 sunny 9 tue 
#endif

#if 01


#endif

#if 0
문자열 2개를 입력받아, 두 문자열의 공통 단어를
오름차순으로 출력하는 프로그램을 작성하시오.

문자열은 공백을 포함할 수 있으며, 문장기호 (, . ? !) 등이 없고 알파벳만으로 구성된다.
getline(std::cin, string) 함수를 이용하면
공백이 포함된 문자열을 입력받을 수 있다.

set_intersection 함수를 이용하면, 두 리스트간의
공통요소를 쉽게 찾아낼 수 있다.

공통단어를 출력할 때 각 단어들은 한 줄에 1단어씩
출력하며 (각 단어 뒤에 줄바꿈 문자), 오름차순이어야 한다.

중복해서 나타나는 공통단어들은 별개 단어로 출력한다.
입력
this this is a report

this this is report

출력
is

report

this

this
#endif

#if 01


#endif

