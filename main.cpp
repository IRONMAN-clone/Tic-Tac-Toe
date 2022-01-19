#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;

// Board
char board[3][3];
// (0 - 8) is 9 Chunks
int free_chunk = 8;

// Board Events
void print_board()
{
    cout << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] <<endl;
    cout << "---|-----|---"<<endl;
    cout << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] <<endl;
    cout << "---|-----|---" << endl;
    cout << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] <<endl;
}   

void mark(int row, int col, char player)
{
    board[row][col] = player;
    free_chunk -= 1;
}

// AI Events

void ai_mark(char player)
{
    srand(time(NULL));
    char signnow = (player == 'O') ? 'X' : 'O';
    int row, col;
    row = rand() % 3;
    col = rand() % 3;
    while(board[row][col] == player or board[row][col] == signnow)
    {
       row = rand() % 3;
       col = rand() % 3;
    }

    mark(row, col, signnow);
}

bool check_winner(char player)
{
    if (board[0][1] == board[0][0] && board[0][2] == board[0][0] && board[0][0] == player)
    {
        return true;
    }

    else if (board[1][1] == board[1][0] && board[1][2] == board[1][0] && board[1][0] == player)
    {
        return true;
    }

    else if (board[2][1] == board[2][0] && board[2][2] == board[2][0] && board[2][0] == player)
    {
        return true;
    }

    else if (board[1][0] == board[0][0] && board[2][0] == board[0][0] && board[0][0] == player)
    {
        return true;
    }
    else if (board[1][1] == board[0][1] && board[2][1] == board[0][1] && board[0][1] == player)
    {
        return true;
    }
    else if (board[2][2] == board[0][2] && board[1][2] == board[0][2] && board[0][2] == player)
    {
        return true;
    }
    else if (board[2][2] == board[0][0] && board[1][1] == board[0][0] && board[0][0] == player)
    {
        return true;
    }
    else if (board[1][1] == board[1][2] && board[2][2] == board[1][2] && board[1][2] == player)
    {
        return true;
    }

    else {
        return false;
    }
}

int main(int argc, char** argv)
{
    char sign1 = 'O', sign2 = 'X';
    char player;
    char ai;

    bool pw=false, aw=false;

    cout << "-------------------------------------" << endl;
    cout << "|                                   |" << endl;
    cout << "|           Tic-Tac-Toe             |" << endl;
    cout << "|                                   |" << endl;
    cout << "-------------------------------------" << endl;

    cout << "\n\nPick your side\n";
    cin >> player;
    ai = (player == sign1) ? sign2 : sign1;

    int r, c;
    int t = 0;
    while (true)
    {
        print_board();
        printf("\nYour Turn Pick Row and Column\n");
        cin >> r >> c;
        if (board[r][c] != player && board[r][c] != ai && free_chunk > 0)
        {
            mark(r, c, player);
            pw = check_winner(player);
        }
        if (pw == true)
        {
            print_board();
            cout << "\n\nPlayer Won The Game!!\n";
            break;
        }
        print_board();
        printf("\nAI's Turn Picking Row and Column!\n");
        ai_mark(player);
        aw = check_winner(ai);
        if (aw == true)
        {
            print_board();
            cout << "\n\nAI Won The Game!!\n";
            break;
        }
        if (free_chunk == -1)
        {
            print_board();
            cout << "\nGame Over\n";
            break;
        }
    }

    return 0;
}

