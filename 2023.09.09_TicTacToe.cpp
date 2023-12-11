#if 01

#include <iostream>
#include <vector>

class TicTacToe {
public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void play() {
        do {
            printBoard();
            takeTurn();
            if (checkWin()) {
                printBoard();
                std::cout << "Player " << currentPlayer << " wins!\n";
                return;
            }
            if (checkDraw()) {
                printBoard();
                std::cout << "It's a draw!\n";
                return;
            }
            togglePlayer();
        } while (true);
    }

private:
    std::vector<std::vector<char> > board;
    char currentPlayer;

    void printBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) std::cout << "|";
            }
            std::cout << "\n";
            if (i < 2) std::cout << "-----\n";
        }
    }

    void takeTurn() {
        int x, y;
        do {
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> x >> y;
        } while (x < 0 || x >= 3 || y < 0 || y >= 3 || board[x][y] != ' ');
        board[x][y] = currentPlayer;
    }

    bool checkWin() {
        // Check rows, columns and diagonals
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

    void togglePlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}


#endif

#if 0

#include<iostream>
using namespace std;

class Tic_Tac_Toe{
public:
    void playgame(){
        init_board();
        cout<<"start TicTacToe game"<<endl;
        print_board();
        do{
            int y,x;
            cout<<turn<<"'s turn, please enter coordinate"<<endl;
            cin>>y>>x;
            while(!(board[y][x]==32) || x<0 || y<0 || x>2 || y>2){
                cout<<"that coordinate is unable, please other coordinate"<<endl;
                cin>>y>>x;
            }
            board[y][x]=turn;

            print_board();

            change_turn();
            check_finish();
        }while(!current_state);

        print_result();
    }

private:
    char board[3][3];

    int raw_sum[3];
    int columm_sum[3];
    int cross_sum[2];

    char turn;

    int current_state;

    void init_board(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                board[i][j]=32;
            }
        }
        turn='O';
    }

    void check_finish(){
        calc_finish();
        calc_state();
    }

    void calc_finish(){
        for(int i=0;i<3;i++){
            raw_sum[i]   =board[i][0]+board[i][1]+board[i][2];
            columm_sum[i]=board[0][i]+board[1][i]+board[2][i];
        }
        cross_sum[0]=board[0][0]+board[1][1]+board[2][2];
        cross_sum[1]=board[0][2]+board[1][1]+board[2][0];
    }

    void calc_state(){
        for(int i=0;i<3;i++){
            if(raw_sum[i]==237 || columm_sum[i]==237){
                current_state=1;
                return;
            }
            else if(raw_sum[i]==264 || columm_sum[i]==264){
                current_state=2;
                return;
            }
        }
        for(int i=0;i<2;i++){
            if(cross_sum[i]==237){
                current_state=1;
                return;
            }
            else if(cross_sum[i]==264){
                current_state=2;
                return;
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==32){
                    current_state=0;
                    return;
                }
            }
        }
        current_state=3;
        return;
    }

    void change_turn(){
        if(turn=='O')turn='X';
        else         turn='O';
        return;
    }

    void print_board(){
        for(int i=0;i<3;i++){
            cout<<"+-+-+-+"<<endl;
            for(int j=0;j<3;j++){
                cout<<"|"<<board[i][j];
            }
            cout<<"|"<<endl;
        }
        cout<<"+-+-+-+"<<endl;;
    }

    void print_result(){
        cout<<"winner is ";
        switch(current_state){
        case 1:
            cout<<"O"<<endl;
            break;
        case 2:
            cout<<"X"<<endl;
            break;
        case 3:
            cout<<"nobody. this game is a draw"<<endl;
            break;
        default:
            cout<<"...?\n who is winner...? it error..."<<endl;
            break;
        } 
    }
};

int main(){
    Tic_Tac_Toe t;
    t.playgame();
    return 0;
}

#endif