#if 01

//프로세스
//스레딩

#include<iostream>
#include<thread>

using namespace std;

void hello(int n){
    cout<<"ThreadID : "<<this_thread::get_id()<<endl;
    for(int i=0;i<10;i++){
        cout<<"print thread, task : "<<n<<endl;
    }
}

int main(){
    thread aThread(&hello,1);
    thread bThread(&hello,2);
    for(int i=0;i<10;i++){
        cout<<"Main"<<endl;
    }
    aThread.join();
    bThread.join();
    cout<<"end of main"<<endl;
    return 0;
}

#endif
