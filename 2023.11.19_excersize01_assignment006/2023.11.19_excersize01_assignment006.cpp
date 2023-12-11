#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <codecvt>
#include <algorithm>

using namespace std;

class MainList{
private:
    string path;
    vector < string > names;
    vector < string > locations;
    vector < string > numbers;
    unsigned int size;
public:
    MainList(string filepath){
        path=filepath;
        size=0;
    }
    virtual bool ReadFile(){
        ifstream fs(path);
        if(!fs)return false;
        string temp;
        string field;
        getline(fs,temp);
        while(getline(fs,temp)){
            istringstream iss(temp);

            getline(iss,field,',');

            names.push_back(field);
            
            getline(iss,field,',');

            locations.push_back(field);

            getline(iss,field);

            numbers.push_back(field);
            
            size++;
        }

        return true;
    }
    unsigned int length(){
        return size;
    }
    virtual bool findkey(string findword,string type){
        if(type=="address" || type=="dong"){
            for(string temp : locations){
                if(temp.find(findword)!=string::npos)return true;
            }
            return false;
        }
        if(type=="name"){
            for(string temp : names){
                if(temp.find(findword)!=string::npos)return true;
            }
            return false;
        }
        if(type=="num"){
            return (find(numbers.begin(),numbers.end(),findword)==numbers.end());
        }
        if(type=="category"){
            for(string temp : names){
                if(temp.find(findword)!=string::npos)return true;
            }
            return false;
        }
    }
    
    string returnNames(unsigned int idx){
        return names[idx];
    }
    string returnNumbers(unsigned int idx){
        return numbers[idx];
    }
    string returnLocations(unsigned int idx){
        return locations[idx];
    }
};

class FindFromName : public MainList{
public:
    FindFromName(string filepath) :MainList(filepath) {
        ;
    }
    bool ReadFile(){
        return MainList::ReadFile();
    }
    unsigned int length(){
        return MainList::length();
    }
    bool findkey(string findkeyword){
        if(MainList::findkey(findkeyword,"name")){
            for(unsigned int i=0;i<length();i++){
                if(MainList::returnNames(i).find(findkeyword)!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                }
            }
        }else{
            cout<<"can't found"<<endl;
            return false;
        }
        return true;
    }
};

class FindFromCategory : public MainList{
public:
    FindFromCategory(string filepath) :MainList(filepath) {
        ;
    }
    bool ReadFile(){
        return MainList::ReadFile();
    }
    unsigned int length(){
        return MainList::length();
    }
    bool findkey(string findkeyword){
        unsigned count=0;
        if(findkeyword=="소방"){
            for(unsigned int i=0;i<length();i++){
                if(MainList::returnNames(i).find("119")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
                if(MainList::returnNames(i).find("안전센터")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
                if(MainList::returnNames(i).find("소방")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
            }
        }
        if(findkeyword=="의료"){
            for(unsigned int i=0;i<length();i++){
                if(MainList::returnNames(i).find("보건")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
                if(MainList::returnNames(i).find("병원")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
                if(MainList::returnNames(i).find("건강")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
            }
        }
        if(findkeyword=="경찰"){
            for(unsigned int i=0;i<length();i++){
                if(MainList::returnNames(i).find("경찰")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    continue;
                }
                if(MainList::returnNames(i).find("파출")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
                if(MainList::returnNames(i).find("지구대")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
            }
        }
        if(findkeyword=="관공서"){
            for(unsigned int i=0;i<length();i++){
                if(MainList::returnNames(i).find("행정")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
                if(MainList::returnNames(i).find("복지")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
                if(MainList::returnNames(i).find("문화")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
                if(MainList::returnNames(i).find("여성")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
                if(MainList::returnNames(i).find("선거")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
                if(MainList::returnNames(i).find("세무서")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
            }
        }
        if(findkeyword=="도서관"){
            for(unsigned int i=0;i<length();i++){
                if(MainList::returnNames(i).find("도서관")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
            }
        }
        if(findkeyword=="교육"){
            for(unsigned int i=0;i<length();i++){
                if(MainList::returnNames(i).find("학습")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
                if(MainList::returnNames(i).find("교육")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
            }
        }
        if(findkeyword=="박물관"){
            for(unsigned int i=0;i<length();i++){
                if(MainList::returnNames(i).find("박물관")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
            }
        }
        if(findkeyword=="공기업"){
            for(unsigned int i=0;i<length();i++){
                if(MainList::returnNames(i).find("공단")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
                if(MainList::returnNames(i).find("사업소")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
                if(MainList::returnNames(i).find("지사")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
                if(MainList::returnNames(i).find("공사")!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<endl;
                    count++;
                    continue;
                }
            }
        }
        if(!count){
            cout<<"can't found"<<endl;
            return false;
        }
        cout<<"총 "<<count<<"개의 "<<findkeyword<<"이/가 검색되었습니다"<<endl;
        return true;
    }
};

int main(){
    string filepath="인천연수구공공기관.txt";

    FindFromName name(filepath);
    FindFromCategory category(filepath);

    bool checkFlag=false;
    if(name.ReadFile())     cout<<"loading for search from name success"    <<endl;
    else checkFlag=true;
    if(category.ReadFile()) cout<<"loading for search from category success"<<endl;
    else checkFlag=true;
    if(checkFlag){
        cout<<"Something wrong"<<endl;
        return 1;
    }
    cout<<"\n\n\n"<<endl;

    int n=0;
    string findword;
    while(n<3){
        cout<<"\n\n\n"<<endl;

        cout<<"검색 방법을 번호로 입력해주세요"<<endl;;
        cout<<"1. 키워드/이름 검색"<<endl;
        cout<<"2. 종류별 탐색"<<endl;

        cin>>n;
        cin.ignore();

        switch(n){
            case 1:
                getline(cin,findword);
                cout<<"\n\n\n"<<endl;
                name.findkey(findword);
                break;
            case 2:
                cout<<"소방, 의료, 경찰, 관공서, 도서관, 교육, 박물관, 공기업 으로 입력해주세요"<<endl;
                getline(cin,findword);
                cout<<"\n\n\n"<<endl;
                category.findkey(findword);
                break;
            default:
                break;
        }
    }
    return 0;
}