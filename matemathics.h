#include <iostream>
#include <vector>
#include <string>

typedef struct big_number{
    std::string number;
}BigNumber;

typedef unsigned long long ULL

int gdc(int a, int b);

int lcm(int a, int b);

std::vector<int> prime_factors(BigNumber n);

std::vector<int> prime_factors(ULL n);

bool is_prime(BigNumber);

bool is_prime(ULL n);

std::vector<ULL> first_n_primes(int n);

ULL nth_prime(int n);

BigNumber init_big_number(std::string number);

BigNumber add(BigNumber n1, BigNumber n2);

BigNumber sub(BigNumber n1, BigNumber n2);

BigNumber mult(BigNumber n1, BigNumber n2);

BigNumber div(BigNumber n1, BigNumber n2);

BigNumber mod(BigNumber n1, BigNumber n2);

void print_big_number(BigNUmber n);