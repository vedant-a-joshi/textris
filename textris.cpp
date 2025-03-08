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
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

vector<int> piecesCounter(7, 0); // purple, blue, red, yellow, green, orange, light blue
vector<string> piecesNotation = {"##", "[]", "@@", "{}", "$$", "()", "!!"};
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
                case 0: cout << MAGENTA << BG_MAGENTA << "##";
                        break;
                case 1: cout << "[]";
                        break;
                case 2: cout << "@@";
                        break;
                case 3: cout << "{}";
                        break;
                case 4: cout << "$$";
                        break;
                case 5: cout << "()";
                        break;
                case 6: cout << "!!";
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