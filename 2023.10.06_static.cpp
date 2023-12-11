//static variable

#include<iostream>
class Circle{
    static int count;
    Circle(){
        count++;
    }
    static int getCount(){
        return count;
    }
};

//static은 객체 안에 있는게 아니라 class 안에 있음

//공유변수

//사용은
Circle::count; //와 같이 사용함


//////////////////////

//static function

Circle::getCount();

///////////////////

//static은 object 생성없이 사용가능

//static member function은 static member variable만 참조할수있음

//singletone 패턴
//서버처럼 하나의 객체만 필요한 경우 사용함

///////////////////////////////////////////////////////////////////////

//연산자 중복
//Operator overloading

//example : string plus

Circle operator+(const Circle& v2){
    Circle v;
    v.x=this->x+v2.x;
    v.y=this->y+v2.y;
}