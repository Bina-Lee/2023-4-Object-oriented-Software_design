#include <iostream>
#include "func.hpp"

using namespace std;



int main(){
    string filepath="인천연수구약국리스트.txt";

    FindFromAddress address(filepath);
    FindFromName name(filepath);
    FindFromKeyword keyword(filepath);
    FindFromDong dong(filepath);
    FindFromCallNum callnum(filepath);
    StatisticalAnalysis SA(filepath);

    bool checkFlag=false;
    if(address.ReadFile())  cout<<"loading for search from address success" <<endl;
    else checkFlag=true;
    if(name.ReadFile())     cout<<"loading for search from name success"    <<endl;
    else checkFlag=true;
    if(keyword.ReadFile())  cout<<"loading for search from keyword success" <<endl;
    else checkFlag=true;
    if(dong.ReadFile())     cout<<"loading for search from dong success"    <<endl;
    else checkFlag=true;
    if(callnum.ReadFile())  cout<<"loading for search from callnum success" <<endl;
    else checkFlag=true;
    if(SA.ReadFile())       cout<<"loading for statistical analysis success"<<endl;
    else checkFlag=true;
    if(checkFlag){
        cout<<"Something wrong"<<endl;
        return 1;
    }
    cout<<"\n\n\n"<<endl;

    int n=0;
    string findword;
    while(n<7){
        cout<<"\n\n\n"<<endl;

        cout<<"검색 방법을 번호로 입력해주세요"<<endl;;
        cout<<"1. 도로명 주소"<<endl;
        cout<<"2. 약국 이름"<<endl;
        cout<<"3. 약국 이름 키워드 검색"<<endl;
        cout<<"4. 동별 리스트 출력"<<endl;
        cout<<"5. 전화번호"<<endl;
        cout<<"6. 이름 분석"<<endl;

        cin>>n;
        cin.ignore();

        switch(n){
            case 1: //주소 완료
                getline(cin,findword);
                cout<<"\n\n\n"<<endl;
                address.findkey(findword);
                break;
            case 2: //이름 완료
                getline(cin,findword);
                cout<<"\n\n\n"<<endl;
                name.findkey(findword);
                break;
            case 3:
                getline(cin,findword);
                cout<<"\n\n\n"<<endl;
                keyword.findkey(findword);
                break;
            case 4: //동 완료
                getline(cin,findword);
                cout<<"\n\n\n"<<endl;
                dong.findkey(findword);
                break;
            case 5: //전화번호 완료
                getline(cin,findword);
                cout<<"\n\n\n"<<endl;
                callnum.findkey(findword);
                break;
            case 6:
                SA.analyzeAndPrintConsonants();
                break;
            default:
                break;
        }
    }
    return 0;
}