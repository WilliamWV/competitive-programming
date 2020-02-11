#include "biginteger.h"

using namespace std;

BigInteger::BigInteger(LL num){
    this->number.clear();
    this->nonnegative = num >= 0;
    num = abs(num);
    while (num > 0){
        this->number.push_back( (BYTE) num%10);
        num/=10;
    }
}

bool verify_string(string candidate){
    for(int i = 0; i<candidate.length(); i++){
        if(!((candidate[i] >= '0' && candidate[i] <= '9') || (candidate[i] == '-' && i == 0))){
            return false;
        }
    }
    return true;
}

BigInteger::BigInteger(string num){
    this->number.clear();
    if(!verify_string(num)) throw invalid_argument("String \"" + num + "\" is invalid to create BigInteger");
    if(num[0] == '-') this->nonnegative = false;
    for (int i = num.size()-1; i>=0; i--){
        if (num[i] != '-')
            this->number.push_back((BYTE) num[i] - '0');
    }
}

BigInteger::BigInteger(std::vector<BYTE> num, bool nn){
    this->number = num;
    this->nonnegative = nn;
}

BigInteger operator + (BigInteger const &a, BigInteger const &b){
    vector<BYTE> result;
    bool nn_result;
    BigInteger bigger = a;
    BigInteger smaller = b;

    if (nn_a == nn_b){
        nn_result = nn_a;
        
    }

}
BigInteger operator - (BigInteger const &a, BigInteger const &b);
BigInteger operator * (BigInteger const &a, BigInteger const &b);
BigInteger operator / (BigInteger const &a, BigInteger const &b);
BigInteger operator % (BigInteger const &a, BigInteger const &b);

friend std::ostream& operator<<(std::ostream& out, const BigInteger &num);
friend std::istream& operator>>(std::istream& inp, BigInteger &num);