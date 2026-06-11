#include <vector>

class Gameboard {
    public:
        Gameboard(int size) : mSize(size), mBoard(size, std::vector<char>(size, ' ')) {}

        void print() const;
        void set(int row, char col, char value) {
            // for row: vector starts at 0 but should be callable with 1, therefor row -1
            // for col: vector starts at 0 (not A), therefore has to be typecasted and converted from ASCII
            mBoard[row-1][int(col)-65] = value;
        };
        char get(int row, char col) {
            return mBoard[row-1][int(col)-65];
        }

    private:
        int mSize;
        std::vector<std::vector<char>> mBoard;
};
