#include "../include/mathematics.h"

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

vector<int> prime_factors(ULL n){

    vector<int> factors;
    while (n % 2 == 0){
        n /= 2;
        factors.push_back(2);
    }

    for(int attempt = 3; n > 1; attempt += 2){
        while (n % attempt == 0){
            factors.push_back(attempt);
            n /= attempt;
            
        }
    }

    return factors;

}

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
    if (n <= 0) return primes;
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
    if (n <= 0) return -1;
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

int main(){
    
    cout<<"Gcd between 24 and 68 is: " <<gcd(24, 68)<<endl;
    cout<<"Gcd between 27 and 80 is: " <<gcd(27, 80)<<endl;
    cout<<"Gcd between 80 and 144 is: " <<gcd(80, 144)<<endl;
    cout<<"Gcd between 17 and 51 is: " <<gcd(17, 51)<<endl;
    cout<<"Gcd between 19 and 2 is: " <<gcd(19, 2)<<endl;

    cout<<"lcm between 24 and 68 is: " <<lcm(24, 68)<<endl;
    cout<<"lcm between 27 and 80 is: " <<lcm(27, 80)<<endl;
    cout<<"lcm between 80 and 144 is: " <<lcm(80, 144)<<endl;
    cout<<"lcm between 17 and 51 is: " <<lcm(17, 51)<<endl;
    cout<<"lcm between 19 and 2 is: " <<lcm(19, 2)<<endl;

    vector<int> p_fac = prime_factors(2637291024);
    cout<<"Prime factors of 2637291024: "<<endl;
    for(int i = 0; i < p_fac.size(); i++){
        cout<<p_fac[i]<<" ";
    }
    
    cout<<endl<<"Is 256 prime? "<<is_prime(256)<<endl;
    cout<<"Is 47 prime? "<<is_prime(47)<<endl;
    cout<<"Is 197 prime? "<<is_prime(197)<<endl;
    cout<<"Is 4031 prime? "<<is_prime(4031)<<endl;
    cout<<"Is 51 prime? "<<is_prime(51)<<endl;
    
    vector<ULL> first_100 = first_n_primes(100);
    cout<<"First 100 Primes: "<<endl;
    for(int i = 0; i < first_100.size(); i++){
        cout<<i<<" : "<<first_100[i];
        if (i%10 == 9){
            cout<<endl;
        }
        else{
            cout<<"  ";
        }
    }

    cout<<endl<<"57th prime: "<<nth_prime(57)<<endl;


}