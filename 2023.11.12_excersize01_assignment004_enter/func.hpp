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
    vector < string > numbers;
    vector < string > locations;
    unsigned int size;
public:
    MainList(string filepath);
    virtual bool ReadFile();
    unsigned int length();
    virtual bool findkey(string findword,string type);
    string returnNames(unsigned int idx);
    string returnNumbers(unsigned int idx);
    string returnLocations(unsigned int idx);
};

class FindFromAddress : public MainList{
public:
    FindFromAddress(string filepath) :MainList(filepath);
    bool ReadFile();
    unsigned int length();
    bool findkey(string findkeyword);
};

class FindFromName : public MainList{
public:
    FindFromName(string filepath) :MainList(filepath);
    bool ReadFile();
    unsigned int length();
    bool findkey(string findkeyword);
};

class FindFromKeyword : public MainList{
public:
    FindFromKeyword(string filepath) : MainList(filepath);
    bool ReadFile();
    unsigned int length();
    bool findkey(string findkeyword);
};

class FindFromDong : public MainList{
public:
    FindFromDong(string filepath) : MainList(filepath);
    bool ReadFile();
    unsigned int length();
    bool findkey(string findkeyword);
};

class FindFromCallNum : public MainList{
public:
    FindFromCallNum(string filepath) : MainList(filepath);
    bool ReadFile();
    unsigned int length();
    bool findkey(string findkeyword);
};

class StatisticalAnalysis : public MainList{
public:
    StatisticalAnalysis(string filepath) : MainList(filepath);
    bool ReadFile();
    unsigned int length();
    void analyzeAndPrintConsonants();
};