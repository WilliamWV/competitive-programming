#include "biginteger.h"

using namespace std;

void BigInteger::setDigits(vector<BYTE> digits){
    m_digits = digits;
}

void BigInteger::setNonNegative(bool nn){
    m_nonnegative = nn;
}

void BigInteger::setFromString(string num){
    
    vector<BYTE> digits;

    if(!verify_string(num)) throw invalid_argument("String \"" + num + "\" is invalid to create BigInteger");
    
    this->setNonNegative(num[0] != '-');
    
    for (int i = num.size()-1; i>=0; i--){
        if (num[i] != '-')
            digits.push_back((BYTE) num[i] - '0');
    }

    // erase zeros on the left
    bool nonzero = false;
    for(int i = digits.size()-1; i >0 || nonzero; i--){
        if (digits[i] == 0){
            digits.erase(digits.begin() + i);
        }
        else{
            nonzero = true;
        }
    }

    this->setDigits(digits);
}


BigInteger::BigInteger(LL num){
    
    vector<BYTE> digits;
    
    this->setNonNegative(num >= 0);
    
    num = abs(num);
    while (num > 0){
        digits.push_back( (BYTE) num%10);
        num/=10;
    }
    this->setDigits(digits);
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
    this->setFromString(num);
}

bool BigInteger::isNonnegative(){
    return nonnegative;
}

vector<BYTE> BigInteger::getDigits(){
    return digits;
}

BigInteger BigInteger::absolute(){
    
    BigInteger abs_val;
    abs_val.setDigits(this->getDigits());
    abs_val.setNonNegative(true);
    return abs_val;
    
}
    

string BigInteger::toString(){
    string num;
    vector<BYTE> digs = this->getDigits();
    if (!this->isNonnegative()){
        num += "-";
    }
    for (int i = digs.size()-1; i >= 0; i--){
        num += (char) ('0' + digs[i]);
    }
    return num;
}

bool BigInteger::isZero(){
    vector<BYTE> digits = this->getDigits();
    return (digits.size() == 1 && digits[0] == 0);
}
    

void BigInteger::operator = (BigInteger b){
    this->setDigits(b.getDigits);
    this->setNonNegative(b.isNonnegative);
}

BigInteger BigInteger::operator +(BigInteger b){
    BigInteger result;
    bool this_nn = this->isNonnegative();
    bool b_nn = b.isNonnegative();

    vector<BYTE> this_digs = this->getDigits();
    vector<BYTE> b_digs = b.getDigits();

    if (this_nn == b_nn){
        result.setDigits(simpleSum(this_digs, b_digs));
        result.setNonNegative(this_nn);
    }
    else if (this->absolute() > b.absolute()){
        result.setDigits(simpleSub(this_digs, b_digs));
        result.setNonNegative(this_nn);
    }
    else{
        result.setDigits(simpleSub(b_digs, this_digs));
        result.setNonNegative(b_nn);
    }
    return result;
}

BigInteger BigInteger::operator -(BigInteger b){
    b.setNonNegative( ! b.isNonnegative());
    return (*this) + b;
}

BigInteger BigInteger::operator *(BigInteger b){
    BigInteger result;
    
    result.setDigits(simpleMul(this->getDigits(), b.getDigits()));
    result.setNonNegative(this->isNonnegative() == b.isNonnegative());

    if (result.isZero()){
        result.setNonNegative(true);
    }
    return result;
}

BigInteger BigInteger::operator /(BigInteger b){
    BigInteger result;

    result.setDigits(simpleDiv(this->getDigits(), b.getDigits()));
    result.setNonNegative(this->isNonnegative() == b.isNonnegative());

    if (result.isZero()){
        result.setNonNegative(true);
    }
    return result;
}
BigInteger BigInteger::operator %(BigInteger b){
    BigInteger result;

    result.setDigits(simpleMod(this->getDigits(), b.getDigits()));
    result.setNonNegative(this->isNonnegative() == b.isNonnegative());

    if (result.isZero()){
        result.setNonNegative(true);
    }
    return result;
}

BigInteger BigInteger::operator -(){
    BigInteger inv;
    inv.setDigits(this->getDigits());
    if(!this->isZero())
        inv.setNonNegative(!this->isNonnegative());
}

bool BigInteger::operator >(BigInteger b){
    if (this->isNonnegative() != b.isNonnegative()){
        return this->isNonnegative();
    }

    vector<BYTE> this_digs = this->getDigits();
    vector<BYTE> b_digs = b.getDigits();

    if (this_digs.size() != b_digs.size()){
        if (this->isNonnegative())  
            return this_digs.size() > b_digs.size();
        else 
            return this_digs.size() < b_digs.size();
    }

    for (int i = this_digs.size() - 1; i >=0; i--){
        if (this_digs[i] > b_digs[i]) return true;
        else if (this_digs[i] < b_digs[i]) return false;
    }
    return false;

}
bool BigInteger::operator <(BigInteger b){
    return b >= (*this);
}

bool BigInteger::operator >=(BigInteger b){
    if (this->isNonnegative() != b.isNonnegative()){
        return this->isNonnegative();
    }

    vector<BYTE> this_digs = this->getDigits();
    vector<BYTE> b_digs = b.getDigits();

    if (this_digs.size() != b_digs.size()){
        if (this->isNonnegative())  
            return this_digs.size() > b_digs.size();
        else 
            return this_digs.size() < b_digs.size();
    }

    for (int i = this_digs.size() - 1; i >=0; i--){
        if (this_digs[i] > b_digs[i]) return true;
        else if (this_digs[i] < b_digs[i]) return false;
    }
    return true;

}
bool BigInteger::operator <=(BigInteger b){
    return b > (*this);
}

bool BigInteger::operator ==(BigInteger b){
    if(this->isNonnegative() != b.isNonnegative()) return false;

    vector<BYTE> this_digs = this->getDigits();
    vector<BYTE> b_digs = b.getDigits();

    if (this_digs.size() != b_digs.size()) return false;

    for(int i = this_digs.size(); i++){
        if (this_digs[i] != b_digs[i]) return false; 
    }
    return true;
}

bool BigInteger::operator !=(BigInteger b){
    return !((*this) == b);
}


ostream& BigInteger::operator<<(ostream& out, BigInteger &b){
    out<<b.toString();
    return out;
}

istream& BigInteger::operator>>(istream& inp, BigInteger &b){
    string s;
    inp >> s;
    BigInteger fromStr(s);
    b = fromStr;
    return inp;
}
