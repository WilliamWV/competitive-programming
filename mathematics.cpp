#include "mathematics.h"

using namespace std;

int gcd_aux (int gr, int sm){
    if (gr % sm == 0) return sm;
    else return gcd_aux(sm, gr%sm);
}

int gcd(int a, int b){
    return gcd_aux(max(a, b), min(a, b));
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

vector<int> prime_factors(BigNumber n);

vector<int> prime_factors(ULL n){

    vector<int> factors;
    while (n % 2 == 0){
        n /= 2;
        factors.push_back(2);
    }

    for(int attempt = 3; n > 1; attempt += 2){
        if (n % attempt == 0){
            factors.push_back(attempt);
            n /= attempt;
        }
    }

    return factors;

}

bool is_prime(BigNumber n);

bool is_prime(ULL n){
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i*i <= n; i+=6){
        if(n%i == 0 || n %(i+2) == 0)
            return false;
    }
    return true;

}

bool is_prime_with_previous(ULL n, vector<ULL> previous){
    for (int i = 0; i < previous.size() && previous[i] <= sqrt(n); i++){
        if (n % previous[i] == 0) return false;
    }
    return true;
}

vector<ULL> first_n_primes(int n){
    vector<ULL> primes;
    if (n < 0) return NULL;
    if (n == 0) return primes;
    primes.push_back(2);
    if (n == 1) return primes;
    primes.push_back(3);
    if (n == 2) return primes;
    
    for (ULL i = 5; true ; i+=6){
        if (is_prime_with_previous(i, primes)){
            primes.push_back(i);
            if (primes.size() == n) return primes;
        }
        if (is_prime_with_previous(i + 2, primes)){
            primes.push_back(i + 2);
            if (primes.size() == n) return primes;
        }
    }

}


ULL nth_prime(int n){
    vector<ULL> primes;
    if (n < 0) return NULL;
    if (n == 0) return -1;
    primes.push_back(2);
    if (n == 1) return 2;
    primes.push_back(3);
    if (n == 2) return 3;
    
    for (ULL i = 5; true ; i+=6){
        if (is_prime(i)){
            primes.push_back(i);
            if (primes.size() == n) return i;
        }
        if (is_prime(i + 2)){
            primes.push_back(i + 2);
            if (primes.size() == n) return i+2;
        }
    }
}

BigNumber init_big_number(std::string number);

BigNumber add(BigNumber n1, BigNumber n2);

BigNumber sub(BigNumber n1, BigNumber n2);

BigNumber mult(BigNumber n1, BigNumber n2);

BigNumber div(BigNumber n1, BigNumber n2);

BigNumber mod(BigNumber n1, BigNumber n2);

void print_big_number(BigNUmber n);