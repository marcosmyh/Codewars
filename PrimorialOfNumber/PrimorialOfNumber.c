#include "PrimorialOfNumber.h"

unsigned long long num_primorial(unsigned n){
    return n == 1? 2: nthPrime(n)*num_primorial(n-1);
}

bool isPrime(int n){
    switch(n){
        case 0:case 1:
            return false;
        default:;
            for(int i = 2;i*i <= n;i++)
                if(n % i == 0) return false;
            return true;
    }
}

int nthPrime(int n){
    int count = 0;
    int i;
    for(i = 2;;i++){
        if(isPrime(i))
            if(++count == n)
                break;
    }
    return i;
}