#include <iostream>
#include <cmath>
using namespace std;

void print2D(int arr[][20], int M, int N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool myfixed[20][20] = {};

void input2D_soduku(int arr[][20], int M, int N)
{
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0) myfixed[i][j] = true;  //so that our entry does not change
        }
    }
}

bool canPlace(int board[][20], int N, int x, int y, int num)
{
    //check along row && col
    for (int i = 0; i < N; ++i)
    {
        if (board[x][i] == num) return false;   //check along row
        if (board[i][y] == num) return false;   //check along col
    }

    //check in the box
    int rootN = sqrt(N);
    int boxRow = x / rootN;
    int boxCol = y / rootN;
    int startRow = boxRow * rootN;
    int startCol = boxCol * rootN;

    for (int r = startRow; r < startRow + rootN; ++r)
    {
        for (int c = startCol; c < startCol + rootN; ++c)
        {
            if (board[r][c] == num) return false;
        }
    }

    return true;
}


bool solveSudoku(int board[][20], int N, int x, int y)
{
    if (x == N && y == 0) return true;   //we have reached row 4 ---->sudoku over

    if (y == N) return solveSudoku(board, N, x + 1, 0);//stop y to go to column4-->goto nxt row

    if (myfixed[x][y]) return solveSudoku(board, N, x , y + 1);

    for (int num = 1; num <= N; ++num)
    {
        if (canPlace(board, N, x, y, num) == true)
        {
            board[x][y] = num;
            bool isSuccessful = solveSudoku(board, N, x , y + 1);  //recursion for nxt columns
            if (isSuccessful) return true;
            else board[x][y] = 0;
        }
    }
    return false;
}

int main()
{
    int board[20][20] = {};

    int N;
    cin >> N;
    input2D_soduku(board, N, N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
              cin>>board[i][j];
        }
    }
    cout << "==============\n";

    print2D(board, N, N);
    
    cout << "==============\n";

    solveSudoku(board, N, 0, 0);

    print2D(board, N, N);
    
}

