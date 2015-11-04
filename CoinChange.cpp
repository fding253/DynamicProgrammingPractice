#include <iostream>
#include <vector>
#include <utility>
#include <ctime>
#include <algorithm>

using namespace std;

int waysToMakeChange(vector<int>& coins, int total) {
    if (find(coins.begin(), coins.end(), 0) == coins.end()) {
        // coins does not contain 0: add it
        coins.push_back(0);
    }
    
    vector< vector <long int> > solution(coins.size(), vector<long int>(total+1));
    
    sort(coins.begin(), coins.end());
    
    // Base Cases
    for (int i=0; i<coins.size(); i++) {
        solution[i][0] = (long int)1; //1 way to make change for amount 0
    }
    for (int j=1; j<=total; j++) {
        solution[0][j] = (long int)0; // no ways to make non-zero amount out of 0 coins
    }
    
    
    for (int i=1; i<coins.size(); i++) {
        for (int j=1; j<=total; j++) {
            if (coins[i]>j) {
                solution[i][j] = solution[i-1][j];
            }
            else {
                solution[i][j] = solution[i-1][j] + solution[i][j-coins[i]];
            }
        }
    }
    
    return solution[coins.size()-1][total];
}

void printTable(vector<int>& coins, int total) {
    if (find(coins.begin(), coins.end(), 0) == coins.end()) {
        // coins does not contain 0: add it
        coins.push_back(0);
    }
    
    vector<int> subset;
  
    for (int i=0; i<coins.size(); i++) {
        subset.push_back(coins[i]);
        for (int j=0; j<total; j++) {
            cout << waysToMakeChange(subset, j) << "\t";
        }
        cout << endl;
    }
    
}

int main() {

    clock_t begin = clock();
    
    vector<int> coins {0,1,2,3,4,5};

    printTable(coins, 11);
    
    clock_t stop = clock();
    double elapsed = (double) (stop-begin) / CLOCKS_PER_SEC;
    
    cout << "Elapsed time: " << elapsed << "sec" << endl;
}
