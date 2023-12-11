#include <iostream>
#include "func.hpp"

using namespace std;
MainList::MainList(string filepath){
    path=filepath;
    size=0;
}
virtual bool MainList::ReadFile(){
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
unsigned int MainList::length(){
    return size;
}
virtual bool MainList::findkey(string findword,string type){
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
string MainList::returnNames(unsigned int idx){
    return names[idx];
}
string MainList::returnNumbers(unsigned int idx){
    return numbers[idx];
}
string MainList::returnLocations(unsigned int idx){
    return locations[idx];
}










FindFromAddress::FindFromAddress(string filepath) :MainList(filepath) {
    ;
}
bool FindFromAddress::ReadFile(){
    return MainList::ReadFile();
}
unsigned int FindFromAddress::length(){
    return MainList::length();
}
bool FindFromAddress::findkey(string findkeyword){
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








FindFromName::FindFromName(string filepath) :MainList(filepath) {
    ;
}
bool FindFromName::ReadFile(){
    return MainList::ReadFile();
}
unsigned int FindFromName::length(){
    return MainList::length();
}
bool FindFromName::findkey(string findkeyword){
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









FindFromKeyword::FindFromKeyword(string filepath) : MainList(filepath) {
    ;
}
bool FindFromKeyword::ReadFile(){
    return MainList::ReadFile();
}
unsigned int FindFromKeyword::length(){
    return MainList::length();
}
bool FindFromKeyword::findkey(string findkeyword){
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







FindFromDong::FindFromDong(string filepath) : MainList(filepath) {
    ;
}
bool FindFromDong::ReadFile(){
    return MainList::ReadFile();
}
unsigned int FindFromDong::length(){
    return MainList::length();
}
bool FindFromDong::findkey(string findkeyword){
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







FindFromCallNum::FindFromCallNum(string filepath) : MainList(filepath) {
    ;
}
bool FindFromCallNum::ReadFile(){
    return MainList::ReadFile();
}
unsigned int FindFromCallNum::length(){
    return MainList::length();
}
bool FindFromCallNum::findkey(string findkeyword){
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









StatisticalAnalysis::StatisticalAnalysis(string filepath) : MainList(filepath){
    ;
}
bool StatisticalAnalysis::ReadFile(){
    return MainList::ReadFile();
}
unsigned int StatisticalAnalysis::length(){
    return MainList::length();
}

void StatisticalAnalysis::analyzeAndPrintConsonants() {
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