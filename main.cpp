#include <iostream>
#include <vector>
#include <array>

using namespace std;

class QueenProblem {
    public:
    void solve(int queens, int boardSize) {
        int board[][] = createBoard(boardSize);
    };
    
    private:
    int createBoard(int size) {
        int tempBoard[size][size];
        for(int row = 0;row < size;row++) {
            for(int column = 0;column < size;column++) {
                tempBoard[row][column] = 0;
            }
        }
        return tempBoard;
    };
};

int main()
{
    cout<<"Hello World";

    return 0;
}
