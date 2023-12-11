#if 01
#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;

class TextFileProcessor{
private:
    string path;
    vector<string>data;
public:
    TextFileProcessor(string filepath){
        path=filepath;
    }//생성자 경로지정
    bool ReadFile(){
        ifstream fs(path);
        if(!fs)return false;//filestream fail ->return
        string temp;
        while(getline(fs,temp))data.push_back(temp);
        //using for loop, push back oneline to oneline
        return true;
    }
    bool IsStringInVector(string target){
        for(string& temp : data)if(temp.find(temp))return true;
        //using for loop, find string oneline to oneline
        return false;
        //if not, return false
    }
    void ConvertToUppercase(){
        for(string& temp : data){
            for(char& c : temp)c=toupper(c);
        }
    }//convert upper one char to one char
    bool WriteToFile(string filename){
        ofstream fs(filename);
        if(!fs)return false;
        for(string& temp : data)fs<<temp<<endl;
        //using for loop, copy oneline to oneline
        return true;
    }
};

int main(){
    std::string filepath;
    std::cout <<"Enter the file path:";
    std::cin >> filepath;
    TextFileProcessor fileProcessor(filepath);
    if(fileProcessor.ReadFile()){
        std::cout <<"File loaded successfully." << std::endl;

        // Check if a string is in the vector
        std::string target;
        std::cout <<"Enter a string to search:";
        std::cin >> target;

        if(fileProcessor.IsStringInVector(target)){
            std::cout <<"String found in the vector." << std::endl;
        } 
        else{
            std::cout <<"String not found in the vector." << std::endl;
        }
        
        // Convert all strings to uppercase
        fileProcessor.ConvertToUppercase();
        
        // Write modified data back to the file
        if(fileProcessor.WriteToFile("uppercased.txt")){
            std::cout <<"File updated with uppercase strings." << std::endl;
        }
    }
    return 0;
}
#endif

#if 01
#include<iostream>
#include<fstream>
#include<list>
using namespace std;

list<int> ReadIntegersFromBinaryFile(string filename){
    ifstream fs(filename, ios_base::binary); //binary file
    list<int>data;
    if(!fs){
        cout<<"open error"<<endl;
        return data;
    }//open error
    int temp;
    while(fs){
        fs.read((char*)&temp,sizeof(int));
        if(fs.eof())break;
        data.push_back(temp);
    }//input and push back
    return data;
}

void SaveIntegersToBinaryFile(string filename, list<int> integers){
    ofstream fs(filename, ios_base::binary); //binary file
    if(!fs){
        cout<<"open error"<<endl;
        return;
    }//open error
    for(int t : integers)fs.write((const char*)&t, sizeof(int));//input list data
    return;
}

int main(){
    std::string filename="integers.bin";
    std::list<int> integers;

    // 바이너리 파일에서 정수 읽기
    integers = ReadIntegersFromBinaryFile(filename);

    // 정수 리스트를 오름차순으로 복사
    std::list<int>ascending_sorted(integers.begin(), integers.end());
    ascending_sorted.sort();
    
    // 정수 리스트를 내림차순으로 복사
    std::list<int> descending_sorted(integers.begin(), integers.end());
    descending_sorted.sort(std::greater<int>());

    // 사용자로부터 정수 입력
    int input;
    std::cout <<"정수를 입력하세요 (0 입력시 종료):";
    while(std::cin >> input && input !=0){
        // 입력된 정수가 리스트에 있는지 확인
        if(std::find(integers.begin(), integers.end(), input) != integers.end()){
            std::cout <<"이 정수는 이미 리스트에 있습니다." << std::endl;
        } 
        else{
            integers.push_back(input);
            ascending_sorted = integers;
            ascending_sorted.sort();
            descending_sorted = integers;
            descending_sorted.sort(std::greater<int>());
            std::cout <<"정수가 리스트에 추가되었습니다." << std::endl;
        }
    }

    // 정수 리스트를 바이너리 파일에 저장
    SaveIntegersToBinaryFile(filename, integers);
    return 0;
}
#endif