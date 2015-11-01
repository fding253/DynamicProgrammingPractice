#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Fibonacci {
    vector<long int> LookupTable;
    
public:
    Fibonacci();
    long int fibonacci (int n);
};

Fibonacci::Fibonacci() {
    
}

long int Fibonacci::fibonacci (int n) {
    if (LookupTable.size()-1 >= n) return LookupTable[n];
    
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
        
        long int res = fibonacciR(n);
    
        clock_t end = clock();
        double elapsedT = double(end-begin) / CLOCKS_PER_SEC;
        
        cout << "n=" << n << ": " << res << " - ";
        if(res==fib[n]) cout << "Correct - ";
        else cout << "INCORRECT - ";
        
        cout << elapsedT << "sec" << endl;
        
    }
    
    return 0;
}