//
//  main.cpp
//  GeneratePrimes
//
//  Created by Dinesh Ravilla on 4/15/19.
//  Copyright © 2019 Dinesh Ravilla. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    for(int i = 2; i < n; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

vector<int> generatePrimes1(int n) {
    vector<int> primes;
    
    for(int i = 2; i <= n; i++) {
        if(isPrime(i))
            primes.push_back(i);
    }
    
    return primes;
}


vector<int> generatePrimes2(int n) {
    vector<bool> isPrime(n+1, true);
    vector<int> primes;
    isPrime[0] = false;
    isPrime[1] = false;
    for(int p = 2; p <= n; p++) {
        if(isPrime[p])
            primes.push_back(p);
        for(int i = p; i <= n; i += p)
            isPrime[i] = false;
    }
    return primes;
}


int main(int argc, const char * argv[]) {
    
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    vector<int> result;
    result = generatePrimes2(n);
    
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    
    return 0;
}
