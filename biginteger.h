#include <iostream>

class BigInteger {

private:

    std::string number;

public:
    
    BigInteger(std::string num);
    BigInteger(ULL num);

    BigInteger operator + (BigInteger const &, BigInteger const &);
    BigInteger operator - (BigInteger const &, BigInteger const &);
    BigInteger operator * (BigInteger const &, BigInteger const &);
    BigInteger operator / (BigInteger const &, BigInteger const &);
    BigInteger operator % (BigInteger const &, BigInteger const &);

friend std::ostream& operator<<(std::ostream& out, const BigInteger &);
friend std::istream& operator>>(std::istream& inp, BigInteger &);

    
}