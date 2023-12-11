#if 01
#include<iostream>

using namespace std;

class Vector{
public:
    Vector(int _x,int _y,int _z){
        x=_x;
        y=_y;
        z=_z;
    }
    Vector(){
        x=0;
        y=0;
        z=0;
    }
    Vector operator+(const Vector &v2){
        Vector v;
        v.x=x+v2.x;
        v.y=y+v2.y;
        v.z=z+v2.z;
        return v;
    }
    bool operator==(Vector &v2){
        return(x==v2.x && y==v2.y && z==v2.z);
    }
    bool operator!=(Vector &v2){
        return !(*this==v2);
    }

    //prefix(++) 이해못함 //전위연산자
    //postfix(++) 입력인수 아무거나 줘야됨
    //이거 다시 보셈



    int x;
    int y;
    int z;
};

int main(){
    Vector p(2,3,4);
    Vector q(5,6,7);
    Vector r=p+q;
    cout<<r.x<<r.y<<r.z<<endl;
}
#endif

#if 01
cout.setf(cout.boolalpha);
//1,0이 아니라 true,false로 출력하게함
#endif

#if 01
//shallow copy / deep copy는 pointer의 복사유무

class Array{
public:
    int a[10];
    int &operator[](int i){
        if(i>=10){
            cout<<"wrong index"<<endl;
            return a[0];
        }
        return a[i];
    }
};

#endif

#if 01
//friend machanisim
class A{
    friend void functionName(){

    };
};
//내부함수가 아님
//외부함수임
//클래스 내에 있는게 아님
#endif

#if 01
class B{
    friend class C; // C는 B에 접근가능
};
#endif

#if 01
//<<중복정의
friend ostream& operator<<(ostream& os,const MyVector& v){}
#endif

#if 01
//중복연산자 만드는거 시험에 나옴
#endif

#if 01
//상속
class Sub : public OriClass, public SecClass{
    //c++은 중복상속이 가능함
    //상속 종류는 3개가 있음 public protected private
    //private default

    //public은 private을 제외하고 나머지 그대로 가져옴
    //private은 접근불가

    //protected는 protected,  public 둘다 protected가 됨
    //private은 그냥 접근불가

    //private은 둘다 private로 상속됨
    //private은 그냥 접근불가

    //생성자 소멸자는 parent가 처음, 마지막에 알아서 실행됨


    //
    //생성자 여러개 상속받는경우 지정하는거 슬라이드 참고
    //

    //override에서 parrentClass::function()
    //사용하면 override되지 않은 함수 호출 가능

    //중복상속 시험에 나옴...;;;;;;;
};
#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

#if 01

#endif

