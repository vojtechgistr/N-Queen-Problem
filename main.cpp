#include <iostream>
#include <vector>

using namespace std;

class QueenProblem {
    public:
    void solve(int queens, int boardSize) {
        vector <vector <string>> board = createBoard(boardSize);
        placeQueens(board, 0);

    };
    
    private:
    vector <vector <string>> createBoard(int size) {
        vector <vector <string>> build(size, vector<string> (size));
        for(int i = 0;i < size;i++) {
            for(int j = 0;j < size;j++) {
                if(i % 2 == 0) build[i][j] = (j % 2 == 0) ? "⬜" : "⬛";
                else build[i][j] = (j % 2 != 0) ? "⬜" : "⬛";
            }
        }
        return build;
    };

    void addSolution(vector <vector <string>> board) {
        cout << "Solution:" << endl;
        for(int e = 0;e < board.size();e++) {
            for(int f = 0;f < board[e].size();f++) {
                cout << " " << board[e][f] << " ";
            }
            cout << endl;
        }
        
        cout << "\n\n";
    };

    bool checkIfIsSafe(vector <vector <string>> board,int row, int column) {
        for(int i = 0;i < column;i++) 
            if(board[row][i] == "🟥") return false;

        for(int i = row, j = column;i >= 0 && j >= 0;i--, j--) 
            if(board[i][j] == "🟥") return false;

        for(int i = row, j = column;j >= 0 && i < board[0].size();i++, j--) 
            if(board[i][j] == "🟥") return false;

        return true;
    };

    bool placeQueens(vector <vector <string>> board, int column) {
        if(column == board.size()) {
            addSolution(board);
            return true;
        }

        for(int i = 0;i < board.size();i++) {
            if(checkIfIsSafe(board, i, column)) {
                board[i][column] = "🟥";
                placeQueens(board, column+1);
                if(i % 2 == 0) board[i][column] = (column % 2 == 0) ? "⬜" : "⬛";
                else board[i][column] = (column % 2 != 0) ? "⬜" : "⬛";
            }
        }
        return false;
    };
};

int main()
{
    QueenProblem puzzle;
    puzzle.solve(8, 8);

    return 0;
}
