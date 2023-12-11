#if 01

#include<iostream>
#include<string>
using namespace std;
class Circle{
        //class 첫글자는 대문자로 만드는게 관례
public: //접근지정자
    int radius;
    string color;

    double calcArea(){
        return 3.14*radius*radius;
    }
    //작성 수정 아무거나 다 할 수 있음

    calcArea2();
    //외부에서 정의함

private:
    char a;
    //class 선언하는 내부에서만 접근이 가능
    //default
protected:
    char b;
    //
};

double Circle::calsArea2(){
    return 3.14*radius*radius;
}
//이렇게 밖에서 정의하는건 권장하지는 않음

int main(){
    Circle a;
    a.radius=100;
    cout<<a.calcArea()<<endl;
    return 0;
}

#endif

//멤버 함수 중복 정의
//member function overloading
class PrintData{
        //Camel Notation 낙타표기법
public:
    void print(int i){cout<<i<<endl;}
    void print(double f){cout<<f<<ebdl;}
    void print(string s="No Data!"){cout<<s<<endl;}
};

namespace MyNamespace{
    int myVariable=42;
    void myFunction(){
        cout<<"Helllo world"<<endl;
    }
}

