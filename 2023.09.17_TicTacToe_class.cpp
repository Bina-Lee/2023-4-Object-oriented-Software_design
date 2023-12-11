#if 01

#include<iostream>
#include<string>

using namespace std;

class Board{
public:
    Board(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                board[i][j]=32;
            }
        }
    }

    char board[3][3];

    void print(){
        for(int i=0;i<3;i++){
            cout<<"+-+-+-+"<<endl;
            for(int j=0;j<3;j++){
                cout<<"|"<<board[i][j];
            }
            cout<<"|"<<endl;
        }
        cout<<"+-+-+-+"<<endl;
    }
    bool isNull(int i,int j){
        if(i<0 || i>2 || j<0 || j>2)return false;
        if(board[i][j]==32)return true;
        return false;
    }
    bool isNull(char c){
        switch(c){
        case 'q': return isNull(0,0);
        case 'w': return isNull(0,1);
        case 'e': return isNull(0,2);
        case 'a': return isNull(1,0);
        case 's': return isNull(1,1);
        case 'd': return isNull(1,2);
        case 'z': return isNull(2,0);
        case 'x': return isNull(2,1);
        case 'c': return isNull(2,2);
        default: return false;
        }
    }
    void placeMark(int i,int j,char who){
        board[i][j]=who;
        return;
    }
    void placeMark(char c, char who){
        switch(c){
        case 'q': placeMark(0,0,who);return;
        case 'w': placeMark(0,1,who);return;
        case 'e': placeMark(0,2,who);return;
        case 'a': placeMark(1,0,who);return;
        case 's': placeMark(1,1,who);return;
        case 'd': placeMark(1,2,who);return;
        case 'z': placeMark(2,0,who);return;
        case 'x': placeMark(2,1,who);return;
        case 'c': placeMark(2,2,who);return;
        default:return;
        }
    }

    bool isFull(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==32)return false;
            }
        }
        return true;
    }
private:

};

class Player{
public:
    string name;
    char callsign;
    bool turn;
    bool win;
    Player(){
        win=false;
    }

    void setname(){
        cin>>name;
        return;
    }
    void setCallsign(){
        cin>>callsign;
        return;
    }

    void changeTurn(){
        turn = !turn;
    }
    void isWin(Board b){
        int check1;
        int check2;
        for(int i=0;i<3;i++){
            check1=b.board[i][0]+b.board[i][1]+b.board[i][2];
            check2=b.board[0][i]+b.board[1][i]+b.board[2][i];
            if(check1==callsign*3 || check2==callsign*3){
                win=true;
                return;
            }
        }
        check1=b.board[0][0]+b.board[1][1]+b.board[2][2];
        check2=b.board[0][2]+b.board[1][1]+b.board[2][0];
        if(check1==callsign*3 || check2==callsign*3){
            win=true;
            return;
        }
    }
private:

};

class Game{
public:
    void play(){
        cout<<"TicTacToe 게임을 시작합니다"<<endl;
        setPlayer();
        b.print();
        while((!b.isFull()) && (!anybodyWin())){
            cout<<whosTurn()<<"님, 좌표를 입력해주세요. q~v의 키보드 입력도 가능합니다"<<endl;
            char cc=0;
            bool able;
            int i;
            int j;
            do{
                if(cc)cout<<"다른 좌표를 사용해주세요"<<endl;
                cin>>cc;
                if(!(cc>='0' && cc<='9'))able=b.isNull(cc);
                else{
                    i=(int)(cc-'0');
                    cin>>j;
                    able=b.isNull(i,j);
                }
            }while(!able);
            if(!(cc>='0' && cc<='9'))b.placeMark(cc,whosTurnCS());
            else b.placeMark(i,j,whosTurnCS());

            b.print();

            p1.changeTurn();
            p2.changeTurn();
        }
        anybodyWin();

        if(p1.win){
            cout<<p1.name<<" is win!! Congratulation"<<endl;
        }
        else if(p2.win){
            cout<<p2.name<<"is win!! Congratulation"<<endl;
        }
        else{
            cout<<"this game is draw..."<<endl;
        }
    }
private:
    Player p1;
    Player p2;
    Board b;

    void setPlayer(){
        cout<<"게임을 시작할 플레이어1의 이름을 입력해주세요"<<endl;
        p1.setname();
        cout<<"보드에 표시할 플레이어1의 이름을 입력해주세요, 한글자입니다"<<endl;
        p1.setCallsign();
        p1.turn=true;
        cout<<"플레이어2의 이름을 입력해주세요"<<endl;
        p2.setname();
        while(p1.name==p2.name){
            cout<<"이미 등록된 이름입니다. 다른 이름을 사용해주세요"<<endl;
            p2.setname();
        }
        cout<<"보드에 표시할 플레이어2의 이름을 입력해주세요, 한글자입니다"<<endl;
        p2.setCallsign();
        while(p1.callsign==p2.callsign){
            cout<<"이미 등록된 식별자입니다. 다른 문자를 사용해주세요"<<endl;
            p2.setCallsign();
        }
        p2.turn=false;
        cout<<p1.name<<"님은 "<<p1.callsign<<"으로, "<<p2.name<<"님은 "<<p2.callsign<<"으로 표시됩니다"<<endl;
    }

    bool anybodyWin(){
        p1.isWin(b);
        p2.isWin(b);
        return (p1.win || p2.win);
    }
    string whosTurn(){
        if(p1.turn)return p1.name;
        return p2.name;
    }
    char whosTurnCS(){
        if(p1.turn)return p1.callsign;
        return p2.callsign;
    }
    bool enterCoor(){
        char cc;
        bool able;
        cin>>cc;
        if(cc>96 && cc<123)able=b.isNull(cc);
        else{
            int i=(int)(cc-'0');
            int j;
            cin>>j;
            able=b.isNull(i,j);
        }
        return able;
    }
};

int main(){
    Game t;
    t.play();
    return 0;
}

#endif