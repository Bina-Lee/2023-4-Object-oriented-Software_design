#if 0
#include<iostream>
using namespace std;
int main(){
    string name;
    cin>>name;
    cout<<name<<endl;
    return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
int main(){
    bool b=false;
    cout<<std::boolalpha;
        //type이 bool이면 char로 print
    count<<b<<endl;
    return 0;
}
#endif

#if 0
#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    //공백도 가능
}
#endif

#if 0
//보편적 초기화
int scores[]{10,20,30};
int a{100};
string s{"helloworld"};
vector<string>list{"al","be","gam"}
    //list는 string vector의 name
    //dll로 구현되어있음
#endif

#if 0
for(변수,범위)
int list[]={1,2,3,4,5,6,7};
for(int i,list){
    //asdfasdf
}
#endif

#if 01
for(auto&i:list)
//참조자 버전 // reference
//포인터인데 주소연산은 불가능함...;;;
//뭐임 이 ㅈ같은거는
//ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
//for loop에서는 복사가 생겨서 속도가 느려짐
//reference를 사용하면 복사를 안함

//for loop을 사용해서 값을 가져올때
//값을 다시 대입할거면 reference를 사용해야함
//포인터처럼 쓸수있지만 주소연산만 안된다고 보면 됨
//메모리에 직접 엑세스
#endif

#if 01
//함수를 작성할때는 parameter
//함수를 호출할때는 argument

//함수의 declaration
//main 이전에 이름만 선언
//함수의 definition
//main 이후에 내용 선언
#endif

#if 0
//call by reference
void modify(int& x, int& y){
    x=10;
    y=20;
    return;
    //대신 local인지 reference variable인지 주의해야됨
}
#endif

#if 01
//중복함수
//매개변수의 개수, 타입, 순서가 다르면 overloading 가능
//반환형이 다른건 해당되지 않음
#endif

#if 01
//default argument
void display(char c='*',int n=10){}
//default parameter를 사용하려면
//입력순서에 맞게 해줘야됨
#endif

#if 01
inline int function_name(void){
    //asdf
}
//코드 내에 함수 내용을 그대로 넣어버림
//속도 증가 목적
#endif

#if 01
//문자열
//string class

#endif

