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
#include "func.hpp"

using namespace std;

class MainList{
private:
    string path;
    vector < string > names;
    vector < string > numbers;
    vector < string > locations;
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
            getline(iss,field,',');

            names.push_back(field);

            getline(iss,field,',');

            numbers.push_back(field);
            
            getline(iss,field);

            locations.push_back(field);
            
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
        if(type=="keyword"){
            for(string temp : names){
                if(temp.find(findword)!=string::npos)return true;
            }
            return false;
        }
        if(type=="name"){
            return (find(names.begin(),names.end(),findword)==names.end());
        }
        if(type=="num"){
            return (find(numbers.begin(),numbers.end(),findword)==numbers.end());
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

class FindFromAddress : public MainList{
public:
    FindFromAddress(string filepath) :MainList(filepath) {
        ;
    }
    bool ReadFile(){
        return MainList::ReadFile();
    }
    unsigned int length(){
        return MainList::length();
    }
    bool findkey(string findkeyword){
        if(MainList::findkey(findkeyword,"address")){
            for(unsigned int i=0;i<MainList::length();i++){
                if(MainList::returnLocations(i).find(findkeyword)!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
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
        if(!MainList::findkey(findkeyword,"name")){
            for(unsigned int i=0;i<length();i++){
                if(MainList::returnNames(i)==findkeyword){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    break;
                }
            }
        }else{
            cout<<"can't found"<<endl;
            return false;
        }
        return true;
    }
};

class FindFromKeyword : public MainList{
public:
    FindFromKeyword(string filepath) : MainList(filepath) {
        ;
    }
    bool ReadFile(){
        return MainList::ReadFile();
    }
    unsigned int length(){
        return MainList::length();
    }
    bool findkey(string findkeyword){
        if(MainList::findkey(findkeyword,"keyword")){
            for(unsigned int i=0;i<MainList::length();i++){
                if(MainList::returnNames(i).find(findkeyword)!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
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

class FindFromDong : public MainList{
public:
    FindFromDong(string filepath) : MainList(filepath) {
        ;
    }
    bool ReadFile(){
        return MainList::ReadFile();
    }
    unsigned int length(){
        return MainList::length();
    }
    bool findkey(string findkeyword){
        if(MainList::findkey(findkeyword,"dong")){
            for(unsigned int i=0;i<MainList::length();i++){
                if(MainList::returnLocations(i).find(findkeyword)!=string::npos){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
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

class FindFromCallNum : public MainList{
public:
    FindFromCallNum(string filepath) : MainList(filepath) {
        ;
    }
    bool ReadFile(){
        return MainList::ReadFile();
    }
    unsigned int length(){
        return MainList::length();
    }
    bool findkey(string findkeyword){
        if(!MainList::findkey(findkeyword,"address")){
            for(unsigned int i=0;i<length();i++){
                if(MainList::returnNumbers(i)==findkeyword){
                    cout<<MainList::returnNames(i)<<endl;
                    cout<<MainList::returnNumbers(i)<<endl;
                    cout<<MainList::returnLocations(i)<<endl;
                    break;
                }
            }
        }else{
            cout<<"can't found"<<endl;
            return false;
        }
        return true;
    }
};

class StatisticalAnalysis : public MainList{
public:
    StatisticalAnalysis(string filepath) : MainList(filepath){
        ;
    }
    bool ReadFile(){
        return MainList::ReadFile();
    }
    unsigned int length(){
        return MainList::length();
    }
    
    void analyzeAndPrintConsonants() {
        // 빈도수 계산을 위한 맵
        unordered_map<char, int> consonant_count;
        // 초성 유니코드 포인트 계산을 위한 상수
        const int base = 0xAC00, chosung_base = 588, jungjung_base = 28;

        // 한글 초성 리스트 (19개)
        const char* chosung_list = "ㄱㄲㄴㄷㄸㄹㅁㅂㅃㅅㅆㅇㅈㅉㅊㅋㅌㅍㅎ";

        for (unsigned int i = 0; i < length(); ++i) {
            string current_str = returnNames(i);
            for (auto& ch : current_str) {
                // 한글 범위 판단
                if ((unsigned char)ch >= 0xE0) { 
                    size_t index = current_str.find(ch);
                    if (index != string::npos && index + 2 < current_str.size()) {
                        int ch1 = (unsigned char)current_str[index] & 0x0F;
                        int ch2 = (unsigned char)current_str[index + 1] & 0x3F;
                        int ch3 = (unsigned char)current_str[index + 2] & 0x3F;
                        int unicode = (ch1 << 12) | (ch2 << 6) | ch3;

                        if (unicode >= base && unicode < base + chosung_base * 19) {
                            int chosung_index = (unicode - base) / chosung_base;
                            consonant_count[chosung_list[chosung_index]]++;
                        }
                    }
                } else if (isalpha(ch)) { // 영문자 범위 판단 및 카운트
                    if (string("AEIOUaeiou").find(ch) == string::npos) {
                        consonant_count[toupper(ch)]++;
                    }
                }
            }
        }

        // 맵을 벡터로 변환하여 정렬
        vector<pair<char, int> > sorted_consonants(consonant_count.begin(), consonant_count.end());
        sort(sorted_consonants.begin(), sorted_consonants.end(), 
            [](const pair<char, int>& a, const pair<char, int>& b) {
                return a.second > b.second; // 빈도수에 따른 내림차순 정렬
            });

        // 결과 출력
        for (const auto& consonant : sorted_consonants) {
            cout << consonant.first << ": " << consonant.second << " times" << endl;
        }
    }
};

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