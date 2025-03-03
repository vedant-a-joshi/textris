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

vector<int> piecesCounter(7, 0); // purple, blue, red, yellow, green, orange, light blue
vector<string> piecesNotation = {"##", "[]", "@@", "{}", "$$", "()", "!!"};
vector<string> pieceName = {"#T#", "[J]", "@Z@", "{O}", "$S$", "(L)", "!I!"};
// deque<int> nextPieces = {rand()%7, rand()%4, rand()%7, rand()%4}; // piece, then orientation
vector<vector<vector<string> > > pieces = {
                                                    {{{"  ##  "},{"######"},{"      "}},
                                                     {{"  ##  "},{"  ####"},{"  ##  "}},
                                                     {{"      "},{"######"},{"  ##  "}},
                                                     {{"  ##  "},{"####  "},{"  ##  "}}},

                                                    {{{"[]    "},{"[][][]"},{"      "}},
                                                     {{"  [][]"},{"  []  "},{"  []  "}},
                                                     {{"      "},{"[][][]"},{"    []"}},
                                                     {{"  []  "},{"  []  "},{"[][]  "}}},

                                                    {{{"@@@@  "},{"  @@@@"},{"      "}},
                                                     {{"    @@"},{"  @@@@"},{"  @@  "}},
                                                     {{"      "},{"@@@@  "},{"  @@@@"}},
                                                     {{"  @@  "},{"@@@@  "},{"@@    "}}},

                                                    {{{"{}{}  "},{"{}{}  "},{"      "}},
                                                     {{"  {}{}"},{"  {}{}"},{"      "}},
                                                     {{"      "},{"  {}{}"},{"  {}{}"}},
                                                     {{"      "},{"{}{}  "},{"{}{}  "}}},

                                                    {{{"  $$$$"},{"$$$$  "},{"      "}},
                                                     {{"  $$  "},{"  $$$$"},{"    $$"}},
                                                     {{"      "},{"  $$$$"},{"$$$$  "}},
                                                     {{"$$    "},{"$$$$  "},{"  $$  "}}},

                                                    {{{"    ()"},{"()()()"},{"      "}},
                                                     {{"  ()  "},{"  ()  "},{"  ()()"}},
                                                     {{"      "},{"()()()"},{"()    "}},
                                                     {{"()()  "},{"  ()  "},{"  ()  "}}},

                                                    {{{"        "},{"!!!!!!!!"},{"        "},{"        "}},
                                                     {{"    !!  "},{"    !!  "},{"    !!  "},{"    !!  "}},
                                                     {{"        "},{"        "},{"!!!!!!!!"},{"        "}},
                                                     {{"  !!    "},{"  !!    "},{"  !!    "},{"  !!    "}}}
                                                    };
// first means which random piece, second means random orientation, last one for iterating through the orientation

int score = 0;
int lines = 0;
int p, o;

vector<vector<string> > matrix(18, vector<string>(10));

void clearScreen();
void display();
void initMatrix();
void nextPiece();

signed main() {
    fastio
    srand(time(0));

    initMatrix();
    for (int i = 0; i < 10; ++i) {
        nextPiece();
        for (int a = 0; a < pieces[p][o].size(); ++a) {
            cout << pieces[p][o][a] << endl;
        }
        cout << "------------" << endl;
    }
}

void clearScreen() {
    system("clear");
}

void display() {
    for (int i = 0; i < 18; ++i) {
        cout << "||";
        for (int j = 0; j < 10; ++j) {
            cout << matrix[i][j];
        }
        cout << "||" << endl;
    }
}

void initMatrix() {
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j%2 == 1) {
                matrix[i][j] = ". ";
            } else {
                matrix[i][j] = "  ";
            }
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