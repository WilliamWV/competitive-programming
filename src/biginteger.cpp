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

    digits = removeLeftZeros(digits);
    
    this->setDigits(digits);
}

BigInteger::BigInteger(){
    this->setNonNegative(true);
    this->setDigits({0});
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

bool BigInteger::verify_string(string candidate){
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
    return m_nonnegative;
}

vector<BYTE> BigInteger::getDigits(){
    return m_digits;
}

BigInteger& BigInteger::absolute(){
    
    BigInteger* abs_val = new BigInteger();
    abs_val->setDigits(this->getDigits());
    abs_val->setNonNegative(true);
    return (*abs_val);
    
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
    this->setDigits(b.getDigits());
    this->setNonNegative(b.isNonnegative());
}

BigInteger& BigInteger::operator +(BigInteger b){
    BigInteger* result = new BigInteger();
    bool this_nn = this->isNonnegative();
    bool b_nn = b.isNonnegative();

    vector<BYTE> this_digs = this->getDigits();
    vector<BYTE> b_digs = b.getDigits();

    if (this_nn == b_nn){
        result->setDigits(simpleSum(this_digs, b_digs));
        result->setNonNegative(this_nn);
    }
    else if (this->absolute() > b.absolute()){
        result->setDigits(simpleSub(this_digs, b_digs));
        result->setNonNegative(this_nn);
    }
    else{
        result->setDigits(simpleSub(b_digs, this_digs));
        result->setNonNegative(b_nn);
    }
    return (*result);
}

BigInteger& BigInteger::operator -(BigInteger b){
    b.setNonNegative( ! b.isNonnegative());
    return (*this) + b;
}

BigInteger& BigInteger::operator *(BigInteger b){
    BigInteger* result = new BigInteger();
    
    result->setDigits(simpleMul(this->getDigits(), b.getDigits()));
    result->setNonNegative(this->isNonnegative() == b.isNonnegative());

    if (result->isZero()){
        result->setNonNegative(true);
    }
    return (*result);
}

BigInteger& BigInteger::operator /(BigInteger b){
    BigInteger* result = new BigInteger();

    result->setDigits(simpleDiv(this->getDigits(), b.getDigits()));
    result->setNonNegative(this->isNonnegative() == b.isNonnegative());

    if (result->isZero()){
        result->setNonNegative(true);
    }
    return (*result);
}
BigInteger& BigInteger::operator %(BigInteger b){
    BigInteger* result = new BigInteger();

    result->setDigits(simpleMod(this->getDigits(), b.getDigits()));
    result->setNonNegative(this->isNonnegative() == b.isNonnegative());

    if (result->isZero()){
        result->setNonNegative(true);
    }
    return (*result);
}

BigInteger& BigInteger::operator -(){
    BigInteger* inv = new BigInteger();
    inv->setDigits(this->getDigits());
    if(!this->isZero())
        inv->setNonNegative(!this->isNonnegative());
    return (*inv);
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

    for(int i = 0; i<this_digs.size(); i++){
        if (this_digs[i] != b_digs[i]) return false; 
    }
    return true;
}

bool BigInteger::operator !=(BigInteger b){
    return !((*this) == b);
}


ostream& operator<<(ostream& out, BigInteger &b){
    out<<b.toString();
    return out;
}

istream& operator>>(istream& inp, BigInteger &b){
    string s;
    inp >> s;
    BigInteger fromStr(s);
    b = fromStr;
    return inp;
}


vector<BYTE> BigInteger::fillLeftZeros(vector<BYTE> n, int size){
    int n_size = n.size();
    for(int i = 0; i < size - n_size; i++){
        n.push_back(0);
    }
    return n;
}

vector<BYTE> BigInteger::removeLeftZeros(vector<BYTE> n){
    bool zero = true;
    
    while (n.size() > 1 && n[n.size()-1] == 0){
        n.pop_back();
    }

    return n;
}
    

vector<BYTE> BigInteger::simpleSum(vector<BYTE> a, vector<BYTE> b){
    vector<BYTE> result;
    a = fillLeftZeros(a, max(a.size(), b.size()));
    b = fillLeftZeros(b, max(a.size(), b.size()));
    
    int carry = 0;
    for (int i = 0; i < a.size(); i++){
        result.push_back((a[i] + b[i] + carry) % 10);
        carry = (a[i] + b[i] + carry) / 10;
    }
    if (carry > 0){
        result.push_back(carry);
    }
    return removeLeftZeros(result);
}

vector<BYTE> BigInteger::simpleSub(vector<BYTE> gr, vector<BYTE> sm){
    vector<BYTE> result;
    sm = fillLeftZeros(sm, gr.size());
    

    int borrow = 0;
    for (int i = 0; i < gr.size(); i++){
        int val = gr[i] - borrow - sm[i];
        if (val >= 0){
            result.push_back(val);
            borrow = 0;
        }
        else{
            result.push_back(val + 10);
            borrow = 1;
        }
    }
    return removeLeftZeros(result);

}

vector<BYTE> BigInteger::mulOneDigit(vector<BYTE> a, BYTE digit){
    vector<BYTE> result;
    int carry = 0;
    for (int i = 0; i < a.size(); i++){
        result.push_back((a[i] * digit + carry) % 10);
        carry = (a[i] * digit + carry) / 10;
    }
    if(carry > 0){
        result.push_back(carry);
    }
    return result;
}

vector<BYTE> BigInteger::simpleMul(vector<BYTE> a, vector<BYTE> b){
    vector<vector<BYTE>> partial_results;
    vector<BYTE> result;

    vector<BYTE> smaller = a;
    vector<BYTE> bigger = b;

    if (a.size() > b.size()){
        smaller = b;
        bigger = a;
    }

    for (int i = 0; i < smaller.size(); i++){
        vector<BYTE> temp = mulOneDigit(bigger, smaller[i]);
        for (int j = 0; j < i; j++){
            temp.insert(temp.begin(), (BYTE) 0);
        }
        partial_results.push_back(temp);
    }
    
    result = partial_results[0];
    
    for(int i = 1; i < partial_results.size(); i++){
        result = simpleSum(result, partial_results[i]);
    }

    return removeLeftZeros(result);

}

// a < b
bool BigInteger::simpleSm(vector<BYTE> a, vector<BYTE> b){
    a = removeLeftZeros(a);
    b = removeLeftZeros(b);
    if (a.size()<b.size()) return true;
    if (b.size()<a.size()) return false;
    for (int i = a.size()-1; i >= 0; i--){
        if (a[i] < b[i]) return true;
        if (b[i] < a[i]) return false;
    }
    return false;
}

BYTE BigInteger::oneDigitQuocient(vector<BYTE> n, vector<BYTE> d){
    
    if (simpleSm(n, d)) return 0;
    bool found = false;
    int i;
    for (i = 2; i < 10 && !found; i++){
        if (simpleSm(n, mulOneDigit(d, i))){
            found = true;
            return i-1;
        }
        
    }
    return i-1;
}

vector<BYTE> BigInteger::simpleDiv(vector<BYTE> n, vector<BYTE> d){
    n = removeLeftZeros(n);
    d = removeLeftZeros(d);
    vector<BYTE> result;

    int d_size = d.size();
    int n_size = n.size();

    if (simpleSm(n, d)) return {0};

    vector<BYTE> m;
    // make m the most sigificant digit of n
    for (int i = n_size - 1; i >= 0; i--){
        // divide m by d, store the result as most sigificant digit of the result and use the remainder as r
        m.insert(m.begin(), n[i]);
        BYTE q = oneDigitQuocient(m, d);
        result.insert(result.begin(), q);
        m = simpleSub(m,mulOneDigit(d, q));
        
        // expand r with the next most significant digit of n and use the result as m repeating the previous step
    }
    return removeLeftZeros(result);
}

vector<BYTE> BigInteger::simpleMod(vector<BYTE> n, vector<BYTE> d){
    vector<BYTE> q = simpleDiv(n, d);
    return (simpleSub(n, simpleMul(d, q)));
}

int main(){

    cout<<"Initializing BigIntegers with string"<<endl;

    BigInteger s1("12345");
    BigInteger s2("12345727310102938475692039846583438929030283613");
    BigInteger s3("-7382930283675649203");
    BigInteger s4("2837465924");
    BigInteger s5("92834740233");

    cout<<"Initialized: "<<endl<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl<<s5<<endl;;
    cout<<"Initializing BigIntegers with long int"<<endl;
    
    BigInteger l1(203948402);
    BigInteger l2(28394823023);
    BigInteger l3(-293849203);
    BigInteger l4(-983892756749);
    BigInteger l5(19203954);
    
    cout<<"Initialized: "<<endl<<l1<<endl<<l2<<endl<<l3<<endl<<l4<<endl<<l5<<endl;;

    cout<<s1<<" is ";
    if (s1.isNonnegative()){
        cout<<"non-negative"<<endl;
    }
    else{
        cout<<"negative"<<endl;
    }
    cout<<l3<<" is ";
    if (l3.isNonnegative()){
        cout<<"non-negative"<<endl;
    }
    else{
        cout<<"negative"<<endl;
    }
    cout<<l4<<" is ";
    if (l4.isNonnegative()){
        cout<<"non-negative"<<endl;
    }
    else{
        cout<<"negative"<<endl;
    }

    cout<<"Digits of "<<s3<<" are:"<<endl;
    vector<BYTE> s3_digs = s3.getDigits();
    for (int i = 0; i<s3_digs.size(); i++){
        cout<<(int)s3_digs[i]<<' ';
    }
    cout<<endl;

    cout<<"The absolute value of "<<l3<<" is "<<l3.absolute()<<endl;
    cout<<"The absolute value of "<<l1<<" is "<<l1.absolute()<<endl;

    BigInteger zero("0");
    cout<<zero<<" == 0? "<<zero.isZero()<<endl;
    cout<<l2<<" == 0? "<<l2.isZero()<<endl;

    cout<<"L1 previous value = "<<l1<<endl;
    BigInteger e = l1;
    l1 = l3;
    cout<<"e = "<<e<<"; L1 = "<<l1<<endl;

    cout<<l1<<" + "<<s5<<" = "<<l1 + s5<<endl;
    cout<<l5<<" - "<<l2<<" = "<<l5 - l2<<endl;
    cout<<s3<<" * "<<s1<<" = "<<s3 * s1<<endl;
    cout<<s2<<" / "<<s5<<" = "<<s2 / s5<<endl;
    cout<<s1<<" % "<<s4<<" = "<<s1 % s4<<endl;
    cout<<" - "<<l4<<" = "<<-l4<<endl;
    
    cout<<l1<<" > "<<l2<<" = "<<(l1>l2)<<endl;
    cout<<l4<<" >= "<<s2<<" = "<<(l4>=s2)<<endl;
    cout<<l5<<" <= "<<s4<<" = "<<(l5<=s4)<<endl;
    cout<<s4<<" < "<<l3<<" = "<<(s4<l3)<<endl;
    cout<<l2<<" == "<<s3<<" = "<<(l2==s3)<<endl;
    cout<<s1<<" != "<<s5<<" = "<<(s1!=s5)<<endl;
    
    cout<<"Enter a biginteger: ";
    BigInteger inp;
    cin>>inp;
    cout<<inp<<" + "<<l3<<" = "<<inp+l3<<endl;

}