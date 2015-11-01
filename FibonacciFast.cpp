#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

long int fibonacciF(int n) {
    long int prev, penult, curr;

    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 1;

    prev = penult = 1;

    for (int i=3; i<=n; i++) {
        curr = prev + penult;
        penult = prev;
        prev = curr;
    }
    
    return curr;
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
        
        long int res = fibonacciF(n);
    
        clock_t end = clock();
        double elapsedT = double(end-begin) / CLOCKS_PER_SEC;
        
        cout << "n=" << n << ": " << res << " - ";
        if(res==fib[n]) cout << "Correct - ";
        else cout << "INCORRECT - ";
        
        cout << elapsedT << "sec" << endl;
        
    }
    
    return 0;
}
