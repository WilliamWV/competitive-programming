#include <iostream>
#include <vector>
#include <string>

typedef long long LL;
typedef unsigned char BYTE;

class BigInteger {

private:
    // The number will be represented as a vector of unsigned 8-bit integers (BYTE)
    // where a number such as 240 would become: number[0] = 0; number[1] = 4; number[2] = 2
    std::vector<BYTE> m_digits;
    bool m_nonnegative;
    
    void setDigits(std::vector<BYTE> digs);
    void setNonNegative(bool nn);
    void setFromString(std::string num);
    // WHEN IMPLEMENTING THIS MUST AVOID ADDITIONAL ZEROS ON THE LEFT 
    BigInteger simpleSum(std::vector<BYTE> a, std::vector<BYTE> b);
    BigInteger simpleSub(std::vector<BYTE> gr, std::vector<BYTE> sm);
    BigInteger simpleMul(std::vector<BYTE> a, std::vector<BYTE> b);
    BigInteger simpleDiv(std::vector<BYTE> n, std::vector<BYTE> d);
    BigInteger simpleMod(std::vector<BYTE> n, std::vector<BYTE> d);

public:
    
    //receives a string without spaces or letters, the only characters allowed are: 
    //-(only if is the first charactere), 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9
    explicit BigInteger(std::string num);
    BigInteger(LL num);
    bool isNonnegative();
    std::string toString();
    std::vector<BYTE> getDigits();
    BigInteger absolute();
    bool isZero();
    

    void operator = (BigInteger b);

    BigInteger operator +(BigInteger b);
    BigInteger operator -(BigInteger b);
    BigInteger operator *(BigInteger b);
    BigInteger operator /(BigInteger b);
    BigInteger operator %(BigInteger b);
    
    BigInteger operator -();

    bool operator >(BigInteger b);
    bool operator <(BigInteger b);
    bool operator >=(BigInteger b);
    bool operator <=(BigInteger b);
    bool operator ==(BigInteger b);
    bool operator !=(BigInteger b);
    

    friend std::ostream& operator<<(std::ostream& out, BigInteger &b);

    friend std::istream& operator>>(std::istream& inp, BigInteger &b);

}