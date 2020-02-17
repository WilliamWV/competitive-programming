#include "../include/mathematics.h"
#include "../include/util.h"
#include <gtest/gtest.h>

using namespace std;

TEST(GCDTest, NotCoprimes){
    ASSERT_EQ(4, gcd(476, 232));
    ASSERT_EQ(3, gcd(123, 57));
    ASSERT_EQ(23, gcd(69, 115));
    ASSERT_EQ(2, gcd(5002, 14));
    ASSERT_EQ(7, gcd(7, 6783));
    
}

TEST(GCDTest, Coprimes){
    ASSERT_EQ(1, gcd(4, 7));
    ASSERT_EQ(1, gcd(123, 124));
    ASSERT_EQ(1, gcd(34, 503));
    ASSERT_EQ(1, gcd(627, 5));
    ASSERT_EQ(1, gcd(423, 98));
    
}

TEST(LCMTest, LCMTest){
    ASSERT_EQ(45, lcm(9, 15));
    ASSERT_EQ(72, lcm(24, 18));
    ASSERT_EQ(33, lcm(11, 33));
    ASSERT_EQ(80, lcm(40, 16));
    ASSERT_EQ(144, lcm(48, 72));
    ASSERT_EQ(152, lcm(8, 19));
    ASSERT_EQ(20, lcm(4, 5));
}

TEST(PrimeFactorsTest, PrimeFactorTest){
    vector<int> expected_factorsOf12 = {2, 2, 3};
    vector<int> actual_factorsOf12 = prime_factors(12);
    
    vector<int> expected_factorsOf144 = {2, 2, 2, 2, 3, 3};
    vector<int> actual_factorsOf144 = prime_factors(144);
    
    vector<int> expected_factorsOf45 = {3, 3, 5};
    vector<int> actual_factorsOf45 = prime_factors(45);
    
    vector<int> expected_factorsOf27384 = {2, 2, 2, 3, 7, 163}; 
    vector<int> actual_factorsOf27384 = prime_factors(27384);
    

    ASSERT_TRUE(vectorCompare(actual_factorsOf12, expected_factorsOf12));
    ASSERT_TRUE(vectorCompare(actual_factorsOf144, expected_factorsOf144));
    ASSERT_TRUE(vectorCompare(actual_factorsOf45, expected_factorsOf45));
    ASSERT_TRUE(vectorCompare(actual_factorsOf27384, expected_factorsOf27384));


}

TEST(IsPrimeTest, PrimesTest){
    ASSERT_TRUE(is_prime(2));
    ASSERT_TRUE(is_prime(3));
    ASSERT_TRUE(is_prime(5));
    ASSERT_TRUE(is_prime(7));
    ASSERT_TRUE(is_prime(31));
    ASSERT_TRUE(is_prime(59));
    ASSERT_TRUE(is_prime(101));
    ASSERT_TRUE(is_prime(877));
}

TEST(IsPrimeTest, NotPrimes){
    ASSERT_FALSE(is_prime(4));
    ASSERT_FALSE(is_prime(8));
    ASSERT_FALSE(is_prime(9));
    ASSERT_FALSE(is_prime(15));
    ASSERT_FALSE(is_prime(34));
    ASSERT_FALSE(is_prime(51));
    ASSERT_FALSE(is_prime(49));
}

TEST(FirstPrimesTest, FirstPrimesTest){
    std::vector<ULL> expected_first4Primes = {2, 3, 5, 7};
    std::vector<ULL> actual_first4Primes = first_n_primes(4);

    std::vector<ULL> expected_first10Primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    std::vector<ULL> actual_first10Primes = first_n_primes(10);
    
    std::vector<ULL> expected_first15Primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    std::vector<ULL> actual_first15Primes = first_n_primes(15);
    
    std::vector<ULL> expected_first20Primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
    std::vector<ULL> actual_first20Primes = first_n_primes(20);
    
    ASSERT_TRUE(vectorCompare(expected_first4Primes, actual_first4Primes));
    ASSERT_TRUE(vectorCompare(expected_first10Primes, actual_first10Primes));
    ASSERT_TRUE(vectorCompare(expected_first15Primes, actual_first15Primes));
    ASSERT_TRUE(vectorCompare(expected_first20Primes, actual_first20Primes));

}

TEST(NthPrimeTest, NthPrimeTest){

    ASSERT_EQ(2, nth_prime(1));
    ASSERT_EQ(3, nth_prime(2));
    ASSERT_EQ(29, nth_prime(10));
    ASSERT_EQ(263, nth_prime(56));
    ASSERT_EQ(547, nth_prime(101));

}

