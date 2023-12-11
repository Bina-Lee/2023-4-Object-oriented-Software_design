#if 0
#include<iostream>

int main(){

}

#endif

#if 0
pure virtual function
virtual void functionname()=0;
body가 없음
상속받은 함수에서 overriding해서 사용
다만 parent class의 호출이 불가해짐
오로지 override 한 child만 호출가능
#endif

#if 0
#include <iostream>
#include <string>

using namespace std;

class Klass {
public:
	int size;
	string* strs;
public:
	Klass(int s) : size(s) {
		strs = new string[this->size]{ "hello", "world", "c++" };
	}
	~Klass() {
		delete[] strs;
	}
	/* 
	*   main함수가 정상 동작할 수 있도록 copy constructor를 구현하시오.
		--------------------------------
	*/
    Klass(const Klass& k){
        size=k.size;
        strs=new string[k.size];
        for(int i=0;i<k;i++){
            strs[i]=k.strs[i];
        }
    }

};

//----------------- 이하 수정 금지 -------------------------------

int main() {
	int i;
	cin >> i;

	Klass k(3);
	{
		Klass p = k;
		cout << p.strs[i] << endl;
	}
	cout << k.strs[i] << endl;

	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>

using namespace std;

class Pizza {
private:
	int radius;
public:
	Pizza(int r) : radius(r) {

	}
	/*
	* 피자 radius를 2배로 증가시키는 method void doubleIt() 를 구현하시오.
	*/
    void doubleIt(){
        radius*=2;
    }

	/*
		* 피자 radius를 반환하는 method int getRadius() 를 구현하시오.
	*/
    int getRadius(){
        return radius;
    }

};

void doubleSize(Pizza& p){
    p.doubleIt();
}
/*
	Pizza 객체를 인수로 받아, radius를 2배로 증가시키는 함수 doubleSize를 구현하시오
	인수로 받은 객체의 radius가 2배로 증가되어야 함. (복사본이 아니라...)
*/

//------------------- 이하 수정금지 --------------------------------------
int main() {
	int i;
	cin >> i;

	Pizza k(i);
	cout << k.getRadius() << endl;  // radius = 10이면,
	doubleSize(k);
	cout << k.getRadius() << endl;  // 여기서는 radius=20으로 출력되어야 함.

	return 0;
}

#endif

#if 0
/*
	현재 시각을 나타내는 Time 클래스를 정의한다.
	시간과 분을 나타내는 hours와 minutes 멤버 변수로 가진다.
	시간범위는 0 ~ 23
	분 범위는 0 ~ 59

	클래스 Time에 ++ 연산자를 중복 정의하시오.
	이 연산자는 시간을 1분 증가시킨다.

	- Prefix와 Postfix ++ 연산자를 각각 정의하고,
	- 분(minutes)의 증가에 따른 시(hours)의 증가에 유의하시오.

	이 외의 코드를 수정하여 점수를 취득하는 경우, 부정행위가 됩니다.

*/

#include <iostream>

using namespace std;

//-------------- 아래부터 수정 가능 ------------------------

class Time {
private:
	int hours;
	int minutes;

public:
	Time() : hours(0), minutes(0) {}
	Time(int h, int m) : hours(h), minutes(m) {}

	void displayTime() {
		cout << hours << ":" << minutes << endl;
	}

    Time& operator++(){
        minutes++;
        if(minutes==60){
            minutes=0;
            hours++;
            if(hours==24){
                hours=0;
            }
        }
        return *this;
    }
    Time operator++(int){
        Time temp(hours,minutes);
        minutes++;
        if(minutes==60){
            minutes=0;
            hours++;
            if(hours==24){
                hours=0;
            }
        }
        return temp;
    }
};

//------------- 이하 수정 금지 ------------------------------

int main() {

	int h, m;
	cin >> h >> m;

	Time t2, t3;
	Time t1(h, m);
	t2 = t1++;
	t3 = ++t1;

	t2.displayTime();
	t1.displayTime();
	t3.displayTime();

	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//------------------------------------

// 이 곳에 Class StringAnalyzer를 정의하시오.
/*
class constructor는 인수로 string을 받아들이며,

public method인 int getStrLength( )는 string의 길이를 반환하고,

public method인 char getCharAt(int idx)는 
string의 idx 위치에 있는 문자를 반환한다.
만약, idx가 유효한 범위를 넘어갈 경우에는 대문자 'A'를 반환해야 한다.

public method인 int getCharSum(vector<int> values>는 
vector에 담긴 숫자들을 string에 대한 인덱스로 사용하여, 
해당 위치 문자들의 아스키 코드값의 합을 반환한다. 
만약 숫자가 유효한 인덱스 범위를 벗어나면 대문자 'A'가 있다고 가정하여 처리한다. 

public method인 stirng getLastSubString(int len)은
문자열의 마지막 len개 문자들을 문자열로 반환한다.
예를 들어, 문자열이 "hello"인 경우, getLastSubString(3)은
"llo"를 반환하여야 한다. 단, 1 <= len <= string_length 이므로 
len에 대한 유효성 검사는 할 필요가 없다.
*/

class StringAnalyzer{
public:
    StringAnalyzer(string s){
        str=s;
    }
    int getStrLength(){
        return str.length();
    }
    char getCharAt(int idx){
        if(idx>=str.length())return 'A';
        return str[idx];
    }
    int getCharSum(vector<int>values){
        int temp=0;
        for(int i=0;i<values.size();i++){
            if(i>=str.length())temp+='A';
            else temp+=str[i];
        }
        return temp;
    }
    string getLastSubString(int len){
        return str.substr(str.length()-len,str.length()-1);
    }
private:
    string str;
};


//----------이하 수정 금지 --------------------------

int main()
{
    string str;
    int v;
    int k;
    vector<int> values;

    getline(cin, str);
    cin >> v;
    while (true) {
        cin >> k;
        if (k == -999) {
            break;
        }
        values.push_back(k);
    }
    
    StringAnalyzer sa(str);
    cout << sa.getStrLength() << endl;
    cout << sa.getCharAt(v) << endl;
    cout << sa.getCharSum(values) << endl;
    cout << sa.getLastSubString(v) << endl;

    return 0;
}
#endif

#if 0
/*
	상자를 나타내는 클래스 Box를 다음과 같이 정의한다.
	지금까지 생성된 Box 객체를 세기 위하여, 정적 변수 count를 사용하고자 한다.
	필요한 코드들을 아래 지시사항에 따라 추가하시오.

	필요한 정적 멤버 변수 count를 선언하시오.
	Method getBox : Box 객체를 생성하여, 그 주소를 반환한다.
	Method getNumCreatedBoxes : 지금까지 생성된 Box 객체 개수를 반환한다.

	이 외의 코드를 수정하여 점수를 취득하는 경우, 부정행위가 됩니다.
*/

#include <iostream>

using namespace std;

// ----------------- 아래부터 수정 가능 ------------------------------------

class Box {
private:
	double length;
	double width;
	double height;
public:
	Box(double l=2.0, double w=2.0, double h =2.0) : length(l), width(w), height(h) {}

	static int count;
	static int getNumCreatedBoxes(){
		return count;
	}

	static Box* getBox(){
		Box* box=new Box();
		Box::count++;
		return box;
	}

};

int Box::count=0;

//---------------- 이하 수정 불가 ---------------------------------------------

int main() {

	int n;
	cin >> n;

	Box* pBox = nullptr;

	for (int i = 0; i < n; i++) {
		pBox = Box::getBox();
		if (i == n / 2) {
			pBox = Box::getBox();
		}
	}

	cout << Box::getNumCreatedBoxes() << endl;

	return 0;
}
#endif

#if 0
/*
	Point 클래스를 상속받아서 ThreeDPoint 클래스를 정의해보자.
	ThreeDPoint 클래스는 3차원 공간 상의 점을 나타내고 int z; 멤버 변수를 추가로 가진다.

	1) 아래와 같은 객체 생성이 가능하도록 생성자를 정의하고,
		ThreeDPoint p1(10,10,10);
		ThreeDPoint p2;  (이 때, x,y,z는 모두 20으로 초기화된다.)

	2) operator plus overaloding (x,y,z를 각 요소끼리 더한다.)를 구현하시오.
		
		ThreeDPoint p3 = p1 + p2;
	
	3) 클래스 ThreeDPoint는 메소드 getX, getY, getZ 를 제공해야 한다.
	   각각 x,y,z 값을 반환한다.
	   
	이 외의 코드를 수정하여 점수를 취득하는 경우, 부정행위가 됩니다.
*/

#include <iostream>

using namespace std;

class Point {
private:
	int x, y;
protected:
	void setX(int _x) {
		x = _x;
	}
	void setY(int _y) {
		y = _y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

class ThreeDPoint : public Point {
private:
	int z;
public:

	// --------------- 아래부터 수정 가능 ------------------------------
	
	void setZ(int _z){
		z=_z;
	}
	int getZ(){
		return z;
	}
	int getX(){
		return Point::getX();
	}
	int getY(){
		return Point::getY();
	}
	ThreeDPoint(int _x,int _y, int _z){
		setX(_x);
		setY(_y);
		z=_z;
	}
	ThreeDPoint(){
		setX(20);
		setY(20);
		z=20;
	}
	ThreeDPoint operator+(ThreeDPoint& t){
		ThreeDPoint temp;
		temp.setX(this->getX()+t.getX());
		temp.setY(this->getY()+t.getY());
		temp.setZ(this->z+t.z);
		return temp;
	}


	// ------------- 이하 수정 금지 ----------------------------------------
};



int main() {

	int x, y, z;
	cin >> x >> y >> z;

	ThreeDPoint p1(x,y,z);
	ThreeDPoint p2;

	cout << p1.getX() << p1.getY() << p1.getZ() << endl;
	cout << p2.getX() << p2.getY() << p2.getZ() << endl;

	ThreeDPoint p3 = p1 + p2;
	cout << p3.getX() << p3.getY() << p3.getZ() << endl;

	return 0;
}
#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

