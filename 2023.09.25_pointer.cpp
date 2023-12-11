#if 01

//nullptr == NULL
//cpp에서
//NULL은 쓰지말고 nullptr을 씀

std::nullptr_t
//C++11부터 도입됨

//포인터와 변수만으로 overload가 됨
//NULL -> 변수로 인식
//nullptr -> 포인터로 인식함

//compile -> link -> exe

//memory
// | 정적 데이터 / heap -> /   / <- stack |
//heap은 malloc하면 쌓이고 stack은 함수호출할때

//{변수이름} = new {type};
p = new Type;

delete p;   //객체
delete [] p;    //배열

//new : class 생성 + 생성자 호출

p = new int[5]{0,1,2,3,4};

delete [] p;

////////////////////

//스마트 포인터 unique_ptr

//1
unique_ptr<type> p(new int);
//포인터 여러개가 동일한 주소를 가리킬수 없음
//해당 변수가 사라지면 그냥 delete해버림

//shared_ptr
//다른 포인터도 동일한 주소를 가질 수 있음
//본인을 가리키는 포인터를 모니터링함
//ref cnt: n
shared_ptr<int> s1 = asdf<int>(110);
//RC가 0이되면 delete

///////////////

//const 포인터
{type} *const p1;
const {type} *p1;
const int * const p3;
//이 세계 차이점
//내용을 수정할수없음
//어떤건 되고 어떤건 안되고
//const ~~ : 수정불가

////////////////////////////////

//복사생성자
    // classname a;
    // classname clone_name{a};

//강의슬라이드 찾아봐야함

//대충 참조하는 데이터를 복제를 해놔야되는 상황같은거
//shallow copy, deep copy
//포인터만 할건지 아니면 데이터 따로 할건지 같은거
//존나 중요함
//memory size나 secure 등 각각의 장단점이 있음

classname(const classnamex& clone){
    //생성자
}

#endif