#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <deque>
#include <cmath>
#define int long long
#define double long double
#define endl '\n'
#pragma GCC optimize("O3,unroll-loops,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
using namespace std;

#define fastio cin.tie(nullptr);ios_base::sync_with_stdio(false);

// colors for text and background
#define reset   "\033[0m"

#define purple "\033[38;5;55m"
#define bgPurple "\033[48;5;55m"

#define blue    "\033[38;5;20m"
#define bgBlue    "\033[48;5;20m"

#define red     "\033[38;5;160m"
#define bgRed     "\033[48;5;160"

#define yellow  "\033[38;5;226m"
#define bgYellow  "\033[48;5;226m"

#define green   "\033[38;5;46m"
#define bgGreen   "\033[48;5;46m"

#define orange  "\033[38;5;208m"
#define bgOrange  "\033[48;5;208m"

#define cyan    "\033[38;5;51m"
#define bgCyan    "\033[48;5;51m"

#define black   "\033[38;5;0m"
#define bgBlack   "\033[48;5;0m"

#define white   "\033[38;5;15m"
#define bgWhite   "\033[48;5;15m"

vector<int> piecesCounter(7, 0); // purple, blue, red, yellow, green, orange, cyan
vector<string> pieceName = {"#T#", "[J]", "@Z@", "{O}", "$S$", "(L)", "!I!"};
// deque<int> nextPieces = {rand()%7, rand()%4, rand()%7, rand()%4}; // piece, then orientation
vector<vector<vector<vector<int> > > > pieces = {
                                                    {{{-1,0,-1},{0,0,0},{-1,-1,-1}},
                                                     {{-1,0,-1},{-1,0,0},{-1,0,-1}},
                                                     {{-1,-1,-1},{0,0,0},{-1,0,-1}},
                                                     {{-1,0,-1},{0,0,-1},{-1,0,-1}}},

                                                    {{{1,-1,-1},{1,1,1},{-1,-1,-1}},
                                                     {{-1,1,1},{-1,1,-1},{-1,1,-1}},
                                                     {{-1,-1,-1},{1,1,1},{-1,-1,1}},
                                                     {{-1,1,-1},{-1,1,-1},{1,1,-1}}},

                                                    {{{2,2,-1},{-1,2,2},{-1,-1,-1}},
                                                     {{-1,-1,2},{-1,2,2},{-1,2,-1}},
                                                     {{-1,-1,-1},{2,2,-1},{-1,2,2}},
                                                     {{-1,2,-1},{2,2,-1},{2,-1,-1}}},

                                                    {{{3,3,-1},{3,3,-1},{-1,-1,-1}},
                                                     {{-1,3,3},{-1,3,3},{-1,-1,-1}},
                                                     {{-1,-1,-1},{-1,3,3},{-1,3,3}},
                                                     {{-1,-1,-1},{3,3,-1},{3,3,-1}}},

                                                    {{{-1,4,4},{4,4,-1},{-1,-1,-1}},
                                                     {{-1,4,-1},{-1,4,4},{-1,-1,4}},
                                                     {{-1,-1,-1},{-1,4,4},{4,4,-1}},
                                                     {{4,-1,-1},{4,4,-1},{-1,4,-1}}},

                                                    {{{-1,-1,5},{5,5,5},{-1,-1,-1}},
                                                     {{-1,5,-1},{-1,5,-1},{-1,5,5}},
                                                     {{-1,-1,-1},{5,5,5},{5,-1,-1}},
                                                     {{5,5,-1},{-1,5,-1},{-1,5,-1}}},

                                                    {{{-1,-1,-1,-1},{6,6,6,6},{-1,-1,-1,-1},{-1,-1,-1,-1}},
                                                     {{-1,-1,6,-1},{-1,-1,6,-1},{-1,-1,6,-1},{-1,-1,6,-1}},
                                                     {{-1,-1,-1,-1},{-1,-1,-1,-1},{6,6,6,6},{-1,-1,-1,-1}},
                                                     {{-1,6,-1,-1},{-1,6,-1,-1},{-1,6,-1,-1},{-1,6,-1,-1}}}
                                                };
// first means which random piece, second means random orientation, last two for iterating through the orientation

int score = 0;
int lines = 0;
int p, o;

vector<vector<int> > matrix(18, vector<int>(10)); // -1 is empty, and the rest of the numbers correspond to their positions in the other vectors

void clearScreen();
void display();
void initMatrix();
void nextPiece();

signed main() {
    fastio
    srand(time(0));

    initMatrix();
    matrix[0][0] = 6;
    matrix[0][1] = 6;
    matrix[0][2] = 6;
    matrix[0][3] = 6;
    display();
}

void clearScreen() {
    system("clear");
}

void display() {
    for (int i = 0; i < 18; ++i) {
        cout << "||";
        for (int j = 0; j < 10; ++j) {
            switch(matrix[i][j]) {
                case -1: if (j%2 == 1) { cout << ". "; }
                         else { cout << "  "; }
                         break;
                case 0: cout << bgPurple << "##" << reset;
                        break;
                case 1: cout << bgBlue << "[]" << reset;
                        break;
                case 2: cout << bgRed << "@@" << reset;
                        break;
                case 3: cout << bgYellow << "{}" << reset;
                        break;
                case 4: cout << bgGreen << "$$" << reset;
                        break;
                case 5: cout << bgOrange << "()" << reset;
                        break;
                case 6: cout << bgCyan << "!!" << reset;
                        break;
            }
        }
        cout << "||" << endl;
    }
}

void initMatrix() {
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = -1;
        }
    }
}

void nextPiece() {
    // p = nextPieces[0];
    // o = nextPieces[1];
    // nextPieces.pop_front();
    // nextPieces.pop_front();
    // nextPieces.push_back(rand()%7);
    // nextPieces.push_back(rand()%4);
    p = rand()%7;
    o = rand()%4;
}