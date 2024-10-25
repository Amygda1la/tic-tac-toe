#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
enum Sector {EMPTY = 0, X = 1, O = 2};
void render_board (const Sector board[3][3]) {
  for(int i = 0; i < 3; i++) {
    cout<<"|";
    for(int j = 0; j < 3; j++){
      switch (board[i][j]){
        case EMPTY : cout<< "  |"; break;
        case X : cout<< " X|"; break;
        case O : cout<< " O|"; break;
      }
    }
    cout<< endl;
  }
}
bool winner(const Sector board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
        return true;

    return false;
}
bool is_draw (const Sector board[3][3]) {
  int counter = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != EMPTY) counter++;
        }
      }
      if (counter == 9) return true;
      else return false;
}
void add_input(const int &input, Sector board[3][3], Sector value) {
  if (input < 1 || input > 9 || board[(input -1) / 3][(input - 1) % 3] != EMPTY){
    cout<< "Wrong move\n";
    return;
  }
  board[(input -1) / 3][(input - 1) % 3] = value;
}
int main (){
  Sector board[3][3] = {
        { EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY }
    };
  Sector player = X;
  int input;
  int player_switcher = 0;
  bool game_status = false;
  cout << "Hello, This is TIC-TAC-TOE game.\nTo play, you need to use inputs from 1-9 that illustrate board cells.\nIt goes from left-to-right-to-down.\nType a number to start.\nType anything else if you want to quit the game.\nEnjoy!\n";
  render_board(board);
  cin >> input;
  game_status = true;
  while(game_status) {
    system("cls");
    add_input(input,board,(player_switcher % 2 == 0) ? X : O);
    winner(board);
    is_draw(board);
    if (winner(board)){
      cout<< ((player == X) ? "X " : "O ") << "Has won\n";
      game_status = false;
      render_board(board);
      break;
    }
    else if(is_draw(board)) {
      cout<< "THE DRAW\n";
      render_board(board);
      break;
    }
    player_switcher++;
    player = (player_switcher % 2 == 0) ? X : O;
    render_board(board);
    cin>> input;
  }
}
