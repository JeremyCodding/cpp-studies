#include <iostream>
#include <string>

const int ROWNUM{3};
const int COLNUM{3};
char board[ROWNUM][COLNUM] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '},
};

void printBoard()
{

    for (int row = 0; row < ROWNUM; ++row)
    {
        for (int col = 0; col < COLNUM; ++col)
        {
            std::cout << board[row][col];
            if (col < COLNUM - 1)
                std::cout << " | ";
        }
        std::cout << std::endl;
        if (row < ROWNUM - 1)
            std::cout << "---------" << std::endl;
    }
}

void resetBoard()
{
    for (int row = 0; row < ROWNUM; ++row)
    {
        for (int col = 0; col < COLNUM; ++col)
        {
            board[row][col] = ' ';
        }
    }
}

// Players interaction
void playerMove(char player)
{
    int row, col;
    std::cout << "Player " << player << ", enter your move (row and column): ";
    std::cin >> row >> col;

    row--;
    col--;

    if (row >= 0 && row < ROWNUM && col >= 0 && col < COLNUM && board[row][col] == ' ')
    {
        board[row][col] = player;
    }
    else
    {
        std::cout << "Invalid move, try again." << std::endl;
        playerMove(player);
    }
}

bool checkWin(char player)
{
    // Check rows, columns, and diagonals
    for (int i = 0; i < ROWNUM; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }
    return false;
}

bool checkDraw()
{
    for (int row = 0; row < ROWNUM; ++row)
    {
        for (int col = 0; col < COLNUM; ++col)
        {
            if (board[row][col] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void startGame()
{
    char currentPlayer = 'X';

    while (true)
    {
        printBoard();
        playerMove(currentPlayer);
        if (checkWin(currentPlayer))
        {
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            break;
        }
        else if (checkDraw())
        {
            std::cout << "The game is a draw." << std::endl;
            break;
        }
        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main()
{

    char continueGame;

    startGame();

    std::cout << "Do you want to go again? (y|n)";
    std::cin >> continueGame;

    while (continueGame == 'y')
    {
        resetBoard();
        startGame();

        std::cout << "Do you want to go again? (y|n): ";
        std::cin >> continueGame;
    }

    return 0;
}
