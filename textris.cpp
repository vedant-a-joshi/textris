#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <cmath>
#include <deque>
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
deque<int> nextPieces = {rand()%7, rand()%4, rand()%7, rand()%4};
vector<vector<vector<vector<string> > > > pieces = {{{{"  ##  "},{"######"},{"      "}},
                                                     {{"  ##  "},{"  ####"},{"  ##  "}},
                                                     {{"      "},{"######"},{"  ##  "}},
                                                     {{"  ##  "},{"####  "},{"  ##  "}}},
                                                    {{{"[]    "},{"[][][]"},{"      "}},
                                                     {{"  [][]"},{"  []  "},{"  []  "}},
                                                     {{"      "},{"[][][]"},{"    []"}},
                                                     {{"  []  "},{"  []  "},{"[][]  "}}},
                                                    {{}, {}, {}, {}},
                                                    {{}, {}, {}, {}},
                                                    {{}, {}, {}, {}},
                                                    {{}, {}, {}, {}},
                                                    {{}, {}, {}, {}}};
// first means which random piece, second means which random orientation, last two are just for iterating through the orientation

int score = 0;
int lines = 0;

vector<vector<string> > matrix(18, vector<string>(10));

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

signed main() {
    fastio
    srand(time(0));

    initMatrix();
}