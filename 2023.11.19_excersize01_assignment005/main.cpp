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
#include <numeric>
#include <charconv>

using namespace std;

class MainList{
private:
    string path;
    vector < string > loc;
    vector < string > locstart;
    vector < string > locend;
    vector < string > peon;
    vector < string > roadlength;
    vector < string > iskm;
    vector < string > daystart;
    vector < string > dayend;
    vector < string > weekendstart;
    vector < string > weekendend;
    vector < string > gongstart;
    vector < string > gongend;
    vector < unsigned int > available;
    vector < string > updatedate;

    unsigned int size;

    // template <typename T>
    // void reorder(vector<T>& data, const vector<size_t>& order) {
    //     vector<T> temp(data.size());
    //     for (size_t i = 0; i < order.size(); ++i) {
    //         temp[i] = data[order[i]];
    //     }
    //     data = move(temp); // 기존 데이터를 재배치된 데이터로 교체
    // }
    // bool compareFunction(size_t a, size_t b) {
    //     return available[a] < available[b];
    // }
public:
    MainList(string filepath){
        path=filepath;
        size=0;
    }

    // void sortByPark() {
    //     // 인덱스 벡터 생성 및 초기화
    //     vector<size_t> indices(size);
    //     iota(indices.begin(), indices.end(), 0); // 0부터 시작해서 1씩 증가하는 순차적인 값을 할당

    //     // 벡터를 기준으로 인덱스 벡터 정렬
    //     sort(indices.begin(), indices.end(),(int a, int b) -> bool{
    //         return available[a] < available[b];
    //     });

    //     // 정렬된 인덱스를 사용해서 모든 벡터 재배치
    //     reorder(loc, indices);
    //     reorder(locstart, indices);
    //     reorder(locend, indices);
    //     reorder(peon, indices);
    //     reorder(roadlength, indices);
    //     reorder(iskm, indices);
    //     reorder(daystart, indices);
    //     reorder(dayend , indices);
    //     reorder(weekendstart, indices);
    //     reorder(weekendend, indices);
    //     reorder(gongstart, indices);
    //     reorder(gongend, indices);
    //     reorder(available, indices);
    //     reorder(updatedate, indices);

    // }

    bool ReadFile(){
        ifstream fs(path);
        if(!fs)return false;
        string temp;
        string field;
        getline(fs,temp);
        while(getline(fs,temp)){
            
            istringstream iss(temp);

            getline(iss,field,',');
            loc.push_back(field);

            getline(iss,field,',');
            locstart.push_back(field);

            getline(iss,field,',');
            locend.push_back(field);

            getline(iss,field,',');
            peon.push_back(field);

            getline(iss,field,',');
            roadlength.push_back(field);

            getline(iss,field,',');
            iskm.push_back(field);

            getline(iss,field,',');
            daystart.push_back(field);

            getline(iss,field,',');
            dayend.push_back(field);

            getline(iss,field,',');
            weekendstart.push_back(field);

            getline(iss,field,',');
            weekendend.push_back(field);

            getline(iss,field,',');
            gongstart.push_back(field);

            getline(iss,field,',');
            gongend.push_back(field);

            getline(iss,field,',');
            available.push_back(stoi(field));

            getline(iss,field);
            updatedate.push_back(field);

            size++;
        }

        // for(string temp : locstart)cout<<temp<<endl;

        // // sortByPark();
        // cout<<"size : "<<size<<endl;

        // for(string temp : locstart)cout<<temp<<endl;

        return true;
    }
    unsigned int length(){
        return size;
    }
    
    bool findkey(string dong){
        bool checkflag=false;
        for(unsigned int i=0;i<size;i++){
            if(loc[i]==dong){
                cout<<loc[i]<<endl;
                cout<<locstart[i]<<" <--> "<<locend[i]<<endl;
                cout<<peon[i]<<endl;
                cout<<"\n"<<endl;
                checkflag=true;
            }
        }
        if(!checkflag){
            cout<<"can't find"<<endl;
            return false;
        }
        return true;
    }
    bool findkey(string day, string time){
        bool checkflag=false;
        for(unsigned int i=0;i<size;i++){
            int timeInMinutes=stoi(time.substr(0,2))*60+stoi(time.substr(3,2));
            if(day=="평일"){
                if (daystart[i].length() != 5 || daystart[i][2] != ':')continue;
                if (dayend[i].length() != 5 || dayend[i][2] != ':')continue;
                int startTimeInMinutes=stoi(daystart[i].substr(0,2))*60+stoi(daystart[i].substr(3,2));
                int endTimeInMinutes=stoi(dayend[i].substr(0,2))*60+stoi(dayend[i].substr(3,2));
                if (startTimeInMinutes <= endTimeInMinutes) {
                    if((timeInMinutes >= startTimeInMinutes) && (timeInMinutes <= endTimeInMinutes)){
                        cout<<loc[i]<<endl;
                        cout<<locstart[i]<<" <--> "<<locend[i]<<endl;
                        cout<<peon[i]<<endl;
                        cout<<"평일 운영시각 : "<<daystart[i]<<" ~ "<<dayend[i]<<endl;
                        cout<<"\n"<<endl;
                        checkflag=true;
                    }
                } else {
                    if((timeInMinutes >= startTimeInMinutes) || (timeInMinutes <= endTimeInMinutes)){
                        cout<<loc[i]<<endl;
                        cout<<locstart[i]<<" <--> "<<locend[i]<<endl;
                        cout<<peon[i]<<endl;
                        cout<<"평일 운영시각 : "<<daystart[i]<<" ~ "<<dayend[i]<<endl;
                        cout<<"\n"<<endl;
                        checkflag=true;
                    }
                }
            }
            if(day=="주말"){
                if (weekendstart[i].length() != 5 || weekendstart[i][2] != ':')continue;
                if (weekendend[i].length() != 5 || weekendend[i][2] != ':')continue;
                int startTimeInMinutes=stoi(weekendstart[i].substr(0,2))*60+stoi(weekendstart[i].substr(3,2));
                int endTimeInMinutes=stoi(weekendend[i].substr(0,2))*60+stoi(weekendend[i].substr(3,2));
                if (startTimeInMinutes <= endTimeInMinutes) {
                    if((timeInMinutes >= startTimeInMinutes) && (timeInMinutes <= endTimeInMinutes)){
                        cout<<loc[i]<<endl;
                        cout<<locstart[i]<<" <--> "<<locend[i]<<endl;
                        cout<<peon[i]<<endl;
                        cout<<"평일 운영시각 : "<<weekendstart[i]<<" ~ "<<weekendend[i]<<endl;
                        cout<<"\n"<<endl;
                        checkflag=true;
                    }
                } else {
                    if((timeInMinutes >= startTimeInMinutes) || (timeInMinutes <= endTimeInMinutes)){
                        cout<<loc[i]<<endl;
                        cout<<locstart[i]<<" <--> "<<locend[i]<<endl;
                        cout<<peon[i]<<endl;
                        cout<<"평일 운영시각 : "<<weekendstart[i]<<" ~ "<<weekendend[i]<<endl;
                        cout<<"\n"<<endl;
                        checkflag=true;
                    }
                }
            }
            if(day=="공휴일"){
                if (gongstart[i].length() != 5 || gongstart[i][2] != ':')continue;
                if (gongend[i].length() != 5 || gongend[i][2] != ':')continue;
                int startTimeInMinutes=stoi(gongstart[i].substr(0,2))*60+stoi(gongstart[i].substr(3,2));
                int endTimeInMinutes=stoi(gongend[i].substr(0,2))*60+stoi(gongend[i].substr(3,2));
                if (startTimeInMinutes <= endTimeInMinutes) {
                    if((timeInMinutes >= startTimeInMinutes) && (timeInMinutes <= endTimeInMinutes)){
                        cout<<loc[i]<<endl;
                        cout<<locstart[i]<<" <--> "<<locend[i]<<endl;
                        cout<<peon[i]<<endl;
                        cout<<"주말 운영시각 : "<<gongstart[i]<<" ~ "<<gongend[i]<<endl;
                        cout<<"\n"<<endl;
                        checkflag=true;
                    }
                } else {
                    if((timeInMinutes >= startTimeInMinutes) || (timeInMinutes <= endTimeInMinutes)){
                        cout<<loc[i]<<endl;
                        cout<<locstart[i]<<" <--> "<<locend[i]<<endl;
                        cout<<peon[i]<<endl;
                        cout<<"공휴일 운영시각 : "<<gongstart[i]<<" ~ "<<gongend[i]<<endl;
                        cout<<"\n"<<endl;
                        checkflag=true;
                    }
                }
            }
        }
        if(!checkflag){
            cout<<"can't find"<<endl;
            return false;
        }
        return true;
    }
};

int main(){
    string filepath="인천시주차시설.txt";

    MainList mainlist(filepath);
    // StatisticalAnalysis SA(filepath);

    bool checkFlag=false;
    if(mainlist.ReadFile())  cout<<"loading for search from address success" <<endl;
    else checkFlag=true;
    // if(SA.ReadFile())       cout<<"loading for statistical analysis success"<<endl;
    // else checkFlag=true;
    if(checkFlag){
        cout<<"Something wrong"<<endl;
        return 1;
    }
    cout<<"\n\n\n"<<endl;

    unsigned char n=0;
    while(n!='e'){
        cout<<"\n\n\n"<<endl;

        cout<<"검색 방법을 입력해주세요"<<endl;
        cout<<"끝내고 싶으시면 e를 입력해주세요"<<endl;
        cout<<"입력가능 명령어"<<endl;
        cout<<"동 : d, 시간 : t"<<endl;

        cin>>n;
        cin.ignore();

        switch(n){
            case 'd':{
                cout<<"동 이름을 적어주세요"<<endl;
                string dong;
                getline(cin,dong);
                cout<<"\n\n\n"<<endl;
                mainlist.findkey(dong);
                break;
            }
            case 't':{
                cout<<"평일, 주말, 공휴일 중에서 입력해주세요"<<endl;
                string day;
                getline(cin,day);
                cout<<"시간을 hh:mm으로 입력해주세요"<<endl;
                string time;
                getline(cin,time);
                cout<<"\n\n\n"<<endl;
                mainlist.findkey(day, time);
                break;
            }
            case 'e':{
                break;
            }
            default:{
                break;
            }
        }
        
        
    }
    return 0;
}