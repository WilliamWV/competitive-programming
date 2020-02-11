#include <iostream>
#include <vector>
#include <string>

typedef long long LL;
typedef unsigned char BYTE;

class BigInteger {

private:
    // The number will be represented as a vector of unsigned 8-bit integers (BYTE)
    // where a number such as 240 would become: number[0] = 0; number[1] = 4; number[2] = 2
    std::vector<BYTE> number;
    bool nonnegative;
    BigInteger(std::vector<BYTE> num, bool nn);

public:
    
    //receives a string without spaces or letters, the only characters allowed are: 
    //-(only if is the first charactere), 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9
    explicit BigInteger(std::string num);
    BigInteger(LL num);

    BigInteger operator + (BigInteger const &, BigInteger const &);
    BigInteger operator - (BigInteger const &, BigInteger const &);
    BigInteger operator * (BigInteger const &, BigInteger const &);
    BigInteger operator / (BigInteger const &, BigInteger const &);
    BigInteger operator % (BigInteger const &, BigInteger const &);
    
    BigInteger operator > (BigInteger const &, BigInteger const &);

    friend std::ostream& operator<<(std::ostream& out, const BigInteger &);
    friend std::istream& operator>>(std::istream& inp, BigInteger &);

    
}