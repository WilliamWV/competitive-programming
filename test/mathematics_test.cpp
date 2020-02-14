#include "../include/mathematics.h"
#include "test.h"

using namespace std;

int test_mathematics(){
        
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

    return OK;
}