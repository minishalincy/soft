#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void displayBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
}

void updateBoard(int move, char player) {
  int row = (move - 1) / 3;
  int col = (move - 1) % 3;
  board[row][col] = player;
}

bool checkForWin(char player) {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    }
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }
  return false;
}

bool checkForDraw() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != 'X' && board[i][j] != 'O') {
        return false;
      }
    }
  }
  return true;
}

int main() {
  char currentPlayer = 'X';
  int move;

  while (true) {
    displayBoard();
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> move;
    updateBoard(move, currentPlayer);

    if (checkForWin(currentPlayer)) {
      displayBoard();
      cout << "Player " << currentPlayer << " wins!" << endl;
      break;
    }

    if (checkForDraw()) {
      displayBoard();
      cout << "It's a draw!" << endl;
      break;
    }

    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  }

  cout << "Play again? (y/n): ";
  char playAgain;
  cin >> playAgain;
  if (playAgain == 'y') {
    main();
  }

  return 0;
}
