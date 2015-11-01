#include <iostream>
#include <vector>
#include <utility>
#include <ctime>

using namespace std;

int waysToMakeChange(int coins, int total) {
    vector< vector <int> > solution(coins+1, vector<int>(total+1));
    
//    if(coins > total) return waysToMakeChange(total, total);
    
    // Base Cases
    for (int i=0; i<=coins; i++) {
        solution[i][0] = 1; //1 way to make change for amount 0
    }
    for (int j=1; j<=total; j++) {
        solution[0][j] = 0; // no ways to make non-zero amount out of 0 coins
    }
    
    
    for (int i=1; i<=coins; i++) {
        for (int j=1; j<=total; j++) {
            if (i>j) {
                solution[i][j] = solution[i-1][j];
            }
            else {
                solution[i][j] = solution[i-1][j] + solution[i][j-i];
            }
        }
    }
    
    return solution[coins][total];
}

int main() {
/*    cout << "Coins = 0, Amount = 5: " << waysToMakeChange(0,5) << endl;
    cout << "Coins = 3, Amount = 5: " << waysToMakeChange(3,5) << endl;
    cout << "Coins = 3, Amount = 7: " << waysToMakeChange(3,7) << endl;
*/

    clock_t begin = clock();
    
    for (int i=0; i<11; i++) {
        for (int j=0; j<11; j++) {
            cout << waysToMakeChange(i,j) << "\t";
        }
        cout << endl;
    }
    
    clock_t stop = clock();
    double elapsed = (double) (stop-begin) / CLOCKS_PER_SEC;
    
    cout << "Elapsed time: " << elapsed << "sec" << endl;
}