#if 0

#include<iostream>
using namespace std;

int main(){

}

#endif


///////////////상속에 뭐에 생성자까지함 ㅅㅂ
#if 0

a = new char[size];//동적메모리할당
~MyString(){
    delete a[]
}

#endif

class A{
public:
    int a;
    A(){
        std::cout<<"생성자\n";
    }
    ~A(){
        std::cout<<"소멸자\n";
    }
}
//소멸자는 함수안에서 return 하면 동적할당 해제함

int main(){

    return 0;
}

//객체가 함수로 넘어갈때는 기본적으로 call by value
//function(객체& 객체이름)
//으로 참조자로 넣으면 call by reference로 넘어감
