#if 0

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

class Hangman{
public:
    Hangman(){
        word[0]="chocolate";
        word[1]="kangaroo";
        word[2]="mysterious";
        word[3]="symphony";
        word[4]="boulevard";
        word[5]="universe";
        word[6]="juxtapose";
        word[7]="zucchini";
        word[8]="quicksand";
        word[9]="nebulous";
        srand(time(0));
        index=rand()%10;
        question_word=word[index];
        word_length=question_word.length();
        respon_word=string(word_length,'_');
        chance=10;
        charlist=string(26,' ');
        for(int i=0;i<26;i++)charlist[i]='a'+i;
    }

    void playgame(){
        while(question_word!=respon_word && chance){
            char temp;
            temp=input();
            bool check=check_is_valid(temp);
            if(!check)chance--;
        }
        if(chance){
            win();
        }
        else{
            lose();
        }
    }
private:
    string word[10];
    int index;
    string question_word;
    int word_length;
    string respon_word;
    int chance;
    string charlist;

    char input(){
        cout<<"Choose alphabet, you have "<<chance<<" chances"<<endl;
        cout<<"Usable alphabet : "<<charlist<<endl;
        cout<<"current state : "<<respon_word<<endl;
        char temp;
        cin>>temp;
        bool check=check_usable_alphabet(temp);
        while(!check){
            cout<<"Unusable alphabet, take other alphabet"<<endl;
            cin>>temp;
            check=check_usable_alphabet(temp);
        }
        return temp;
    }

    bool check_usable_alphabet(char temp){
        if(charlist[temp-'a']=='_')return false;
        return true;
    }

    bool check_is_valid(char temp){
        bool return_value=false;
        for(int i=0;i<word_length;i++){
            if(question_word[i]==temp){
                respon_word[i]=temp;
                return_value=true;
            }
        }
        charlist[temp-'a']='_';
        return return_value;
    }

    void win(){
        cout<<"Keyword is "<<question_word<<endl;
        cout<<"Congratulation!!"<<endl;
    }
    void lose(){
        cout<<"Chance is over, keyword is "<<question_word<<endl;
    }
};

int main(){
    Hangman t;
    t.playgame();
    return 0;
}

#endif

#if 01
#include <iostream>
#include <vector>
#include <ctime>
#include <string>

class Hangman {
private:
    std::vector<std::string> words;
    std::string chosenWord;
    std::string guessedWord;
    int tries = 7;

public:
    Hangman() {
        words.push_back("apple");
        words.push_back("banana");
        words.push_back("cherry");
        words.push_back("date");
        words.push_back("elderberry");
        words.push_back("fig");
        words.push_back("grape");
        words.push_back("honeydew");
        words.push_back("kiwi");
        words.push_back("lemon");
        
        srand(static_cast<unsigned int>(time(0))); 
        chosenWord = words[rand() % words.size()];
        guessedWord = std::string(chosenWord.size(), '_');
    }

    void play() {
        std::cout << "Welcome to Hangman!" << std::endl;
        while(tries > 0 && guessedWord != chosenWord) {
            std::cout << guessedWord << std::endl;
            std::cout << "Tries left: " << tries << "\nGuess a letter: ";
            char guess;
            std::cin >> guess;

            if(chosenWord.find(guess) != std::string::npos) {
                for(size_t i = 0; i < chosenWord.size(); i++) {
                    if(chosenWord[i] == guess) {
                        guessedWord[i] = guess;
                    }
                }
            } else {
                tries--;
            }
        }

        if(guessedWord == chosenWord) {
            std::cout << "Congratulations! You guessed the word: " << chosenWord << std::endl;
        } else {
            std::cout << "Sorry, you lost! The word was: " << chosenWord << std::endl;
        }
    }
};

int main() {
    Hangman game;
    game.play();
    return 0;
}


#endif