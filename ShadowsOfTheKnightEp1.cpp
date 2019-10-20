#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility> 
using namespace std;


/* Author: Fernando Dominguez Estevez
* It performs binary search to find the next position Batman has to go to.
* This is my C++ solution for the Codingame programming exercise 'Shadows of the Knight - Episode 1'
*/

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

pair<int,int> GetNextPosition(string dir, int x, int y, int W, int H);

int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    
    pair<int,int> next;
    next.first = X0;
    next.second = Y0;
    
    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();

        next = GetNextPosition(bombDir, next.first, next.second, W, H);

        // the location of the next window Batman should jump to.
        cout << next.first << " " << next.second << endl;
    }
}


// Performs Binary Search on the map to find best next position for Batman
pair<int,int> GetNextPosition(string dir, int x, int y, int W, int H){
    pair<int,int> result;
    
    static int R = W;
    static int L = 0;
    static int U = 0;
    static int D = H;
    
    if(dir.compare("U") == 0){
        result.first = x;
        result.second = (y + U) / 2;
        
        D = y;
    }
    else if(dir.compare("UR") == 0){
        result.first = (x + R) / 2;
        result.second = (y + U) / 2;
        
        D = y;
        L = x;
        
    }
    else if(dir.compare("R") == 0){
        result.first = (x + R) / 2;
        result.second = y ;
        L = x;
    }
    else if(dir.compare("DR") == 0){
        result.first = (x + R) / 2;
        result.second = (y + D) / 2;
        U = y;
        L = x;
    }
    else if(dir.compare("D") == 0){
        result.first = x;
        result.second = (y + D) / 2;
        U = y;
    }
    else if(dir.compare("DL") == 0){
        result.first = (x + L) / 2;
        result.second = (y + D) / 2;
        R = x;
        U = y;
    }
    else if(dir.compare("L") == 0){
        result.first = (x + L) / 2;
        result.second = y;
        
        R = x;
    }
    else if(dir.compare("UL") == 0){
        result.first = (x + L) / 2;
        result.second = (y + U) / 2;
        
        D = y;
        R = x;
    }
        
    
    return result;
}

