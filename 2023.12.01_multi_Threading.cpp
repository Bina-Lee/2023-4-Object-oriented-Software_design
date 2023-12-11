#if 01

//Multi Threading


//Overwrite
    //Synchronization:Mutex

#include<mutex>
mutex a;

a.lock();
//필요한 변수 연산
a.unlock();

a.try_lock();
//lock상태에 따른 bool 결과 반환

deadlock
a.lock();
b.lock();
.....
a.unlock();
b.unlock();
//-> 탈출 불가상황
//os는 이에 따라 detection, recovery 하는 시스템

//deadlock preventation
//자원을 가져가는 순서를 정해놓은 상황
//os가 정함

//simple solution
//flag 설정 후 loop로 끝날때까지 확인
//cpu 사용량 많음




//thread pool
//thread 생성해놓고 일 생길때마다 줌
//thread 자체를 추가적으로 만들진 않음

//Asynchronous


#endif