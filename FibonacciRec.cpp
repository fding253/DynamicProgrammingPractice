#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int fibonacciR(int n) {
    if(n==0) return 0;
    if(n==1) return 1;

    return fibonacciR(n-2) + fibonacciR(n-1);
}

int main() {
    vector<int> fib(50);
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2; i<49;i++) {
        fib[i] = fib[i-2] +fib[i-1];
    }
    
    for(int n=0; n<=49; n++) {
        
        clock_t begin = clock();
        
        int res = fibonacciR(n);
        
        clock_t end = clock();
        double elapsedT = double(end-begin) / CLOCKS_PER_SEC;
        
        cout << "n=" << n << ": " << res << " - ";
        if(res==fib[n]) cout << "Correct - ";
        else cout << "INCORRECT - ";
        
        cout << elapsedT << "sec" << endl;
        
    }
    
    return 0;
}