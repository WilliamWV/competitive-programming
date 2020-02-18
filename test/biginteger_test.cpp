#include "../include/biginteger.h"
#include <gtest/gtest.h>

using namespace std;


TEST(BigIntegerConstructorTest, StringTest){
    ASSERT_NO_THROW(BigInteger zero("0"));
    ASSERT_NO_THROW(BigInteger one("1"));
    ASSERT_NO_THROW(BigInteger minus1("-1"));
    ASSERT_NO_THROW(BigInteger bigNumber("92839402938328302034820303989482030239473893413"));
    ASSERT_NO_THROW(BigInteger leftZeros("0000022323193"));
    ASSERT_NO_THROW(BigInteger negativeBig("-128938201391923812301231623517231203129196487123071238163"));
    

    ASSERT_THROW(BigInteger invalid("0-1"), invalid_argument);
    ASSERT_THROW(BigInteger invalid("abcdefg"), invalid_argument);
    ASSERT_THROW(BigInteger invalid("1829302a3232"), invalid_argument);
    ASSERT_THROW(BigInteger invalid("-a"), invalid_argument);
    ASSERT_THROW(BigInteger invalid("029384-"), invalid_argument);
    ASSERT_THROW(BigInteger invalid("0293-840"), invalid_argument);
    
}

TEST(BigIntegerConstructorTest, LongIntTest){

    ASSERT_NO_THROW(BigInteger zero((LL) 0));
    ASSERT_NO_THROW(BigInteger one((LL) 1));
    ASSERT_NO_THROW(BigInteger minus1((LL) -1));
    ASSERT_NO_THROW(BigInteger bigNumber((LL) 82938293829));
    ASSERT_NO_THROW(BigInteger leftZeros((LL) 28374212));
    ASSERT_NO_THROW(BigInteger negativeBig((LL) -8237327183));
    ASSERT_NO_THROW(BigInteger conversion = (LL) 12);
    
}

//bool isNonnegative();
//std::string toString();
//std::vector<BYTE> getDigits();
//BigInteger& absolute();
//bool isZero();


//void operator = (BigInteger b);

//BigInteger& operator +(BigInteger b);
//BigInteger& operator -(BigInteger b);
//BigInteger& operator *(BigInteger b);
//BigInteger& operator /(BigInteger b);
//BigInteger& operator %(BigInteger b);

//BigInteger& operator -();

//bool operator >(BigInteger b);
//bool operator <(BigInteger b);
//bool operator >=(BigInteger b);
//bool operator <=(BigInteger b);
//bool operator ==(BigInteger b);
//bool operator !=(BigInteger b);

//friend std::ostream& operator<<(std::ostream& out, BigInteger &b);
//friend std::istream& operator>>(std::istream& inp, BigInteger &b); 
