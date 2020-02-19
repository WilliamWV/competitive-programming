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

TEST(isNegativeTest, isNegativeTest){
    BigInteger n1 = 12;
    BigInteger n2 = 0;
    BigInteger n3 = -938;
    BigInteger n4 = 920391;
    BigInteger n5 = 7382;
    BigInteger n6 = -9382;
    BigInteger n7 = -0;
    BigInteger n8 = -9283;

    BigInteger s1("0");
    BigInteger s2("-0");
    BigInteger s3("3892638263928320938207323");
    BigInteger s4("-989383273920302392836283");
    BigInteger s5("-1");
    
    ASSERT_TRUE(n1.isNonnegative());
    ASSERT_TRUE(n2.isNonnegative());
    ASSERT_FALSE(n3.isNonnegative());
    ASSERT_TRUE(n4.isNonnegative());
    ASSERT_TRUE(n5.isNonnegative());
    ASSERT_FALSE(n6.isNonnegative());
    ASSERT_TRUE(n7.isNonnegative());
    ASSERT_FALSE(n8.isNonnegative());
    ASSERT_TRUE(s1.isNonnegative());
    ASSERT_TRUE(s2.isNonnegative());
    ASSERT_TRUE(s3.isNonnegative());
    ASSERT_FALSE(s4.isNonnegative());
    ASSERT_FALSE(s5.isNonnegative());
    
}

TEST(toStringTest, toStringTest){
    BigInteger two = 2;
    BigInteger minus10 = -10;

    BigInteger bigNumber("2839200293828329379832892937868263823");
    BigInteger zero("0");

    ASSERT_EQ(two.toString(), "2");
    ASSERT_EQ(minus10.toString(), "-10");
    ASSERT_EQ(bigNumber.toString(), "2839200293828329379832892937868263823");
    ASSERT_EQ(zero.toString(), "0");
    
}

TEST(absoluteTest, absoluteTest){
    BigInteger two = 2;
    BigInteger zero = 0;
    BigInteger minus2 = -2;
    BigInteger four = 4;
    BigInteger minus8 = -8;
    BigInteger minus1 = -1;
    BigInteger minus5 = -5;
    
    BigInteger minus0("-0");

    ASSERT_EQ(minus0.absolute(), zero);
    ASSERT_EQ(two.absolute(), (BigInteger) 2);
    ASSERT_EQ(zero.absolute(), (BigInteger) 0);
    ASSERT_EQ(minus2.absolute(), (BigInteger) 2);
    ASSERT_EQ(four.absolute(), (BigInteger) 4);
    ASSERT_EQ(minus8.absolute(), (BigInteger) 8);
    ASSERT_EQ(minus1.absolute(), (BigInteger) 1);
    ASSERT_EQ(minus5.absolute(), (BigInteger) 5);
    
}

TEST(isZeroTest, isZeroTest){
    BigInteger z1 = 0;
    BigInteger z2 = -0;
    BigInteger z3("0");
    BigInteger z4("-0");

    BigInteger n1 = 9382;
    BigInteger n2 = 972;
    BigInteger n3 = 837;
    BigInteger n4 = 2;
    BigInteger n5 = 927;
    BigInteger n6 = 123;
    BigInteger n7 = -9;
    BigInteger n8("12818267312531726351267351867318267531826735");
    BigInteger n9("-12818267312531726351267351867318267531826735");
    
    ASSERT_TRUE(z1.isZero());
    ASSERT_TRUE(z2.isZero());
    ASSERT_TRUE(z3.isZero());
    ASSERT_TRUE(z4.isZero());
    
    ASSERT_FALSE(n1.isZero());
    ASSERT_FALSE(n2.isZero());
    ASSERT_FALSE(n3.isZero());
    ASSERT_FALSE(n4.isZero());
    ASSERT_FALSE(n5.isZero());
    ASSERT_FALSE(n6.isZero());
    ASSERT_FALSE(n7.isZero());
    ASSERT_FALSE(n8.isZero());
    ASSERT_FALSE(n9.isZero());
}

TEST(assignOpTest, assignOpTest){
    BigInteger n1 = 928374;
    BigInteger n2("83829130937283231");

    n1 = n2;

    ASSERT_EQ(n1.toString(), "83829130937283231");
    ASSERT_EQ(n2.toString(), "83829130937283231");
    
}

TEST(cmpOpTest, greaterTest){
    BigInteger n1 = 928392;
    BigInteger n2 = 973163;
    BigInteger n3 = -625372;
    BigInteger n4 = 123723;
    BigInteger n5("123723");
    BigInteger n6("7561173581723517653167531725310938172936172");

    ASSERT_TRUE(n2 > n1);
    ASSERT_TRUE(n1 > n3);
    ASSERT_TRUE(n4 > n3);
    ASSERT_TRUE(n2 > n4);
    ASSERT_TRUE(n6 > n2);
    ASSERT_TRUE(n5 > n3);

    ASSERT_FALSE(n4 > n5);
    ASSERT_FALSE(n5 > n4);
    ASSERT_FALSE(n1 > n6);
    ASSERT_FALSE(n3 > n1);
}

TEST(CmpOpTest, smallerTest){
    BigInteger n1 = 928392;
    BigInteger n2 = 973163;
    BigInteger n3 = -625372;
    BigInteger n4 = 123723;
    BigInteger n5("123723");
    BigInteger n6("7561173581723517653167531725310938172936172");

    ASSERT_FALSE(n2 < n1);
    ASSERT_FALSE(n1 < n3);
    ASSERT_FALSE(n4 < n3);
    ASSERT_FALSE(n2 < n4);
    ASSERT_FALSE(n6 < n2);
    ASSERT_FALSE(n5 < n3);

    ASSERT_FALSE(n4 < n5);
    ASSERT_FALSE(n5 < n4);
    
    ASSERT_TRUE(n1 < n6);
    ASSERT_TRUE(n3 < n1);
}

TEST(CmpOpTest, greaterEqTest){
    BigInteger n1 = 928392;
    BigInteger n2 = 973163;
    BigInteger n3 = -625372;
    BigInteger n4 = 123723;
    BigInteger n5("123723");
    BigInteger n6("7561173581723517653167531725310938172936172");

    ASSERT_TRUE(n2 >= n1);
    ASSERT_TRUE(n1 >= n3);
    ASSERT_TRUE(n4 >= n3);
    ASSERT_TRUE(n2 >= n4);
    ASSERT_TRUE(n6 >= n2);
    ASSERT_TRUE(n5 >= n3);

    ASSERT_TRUE(n4 >= n5);
    ASSERT_TRUE(n5 >= n4);
    
    ASSERT_FALSE(n1 >= n6);
    ASSERT_FALSE(n3 >= n1);
}

TEST(CmpOpTest, smallerEqTest){
    BigInteger n1 = 928392;
    BigInteger n2 = 973163;
    BigInteger n3 = -625372;
    BigInteger n4 = 123723;
    BigInteger n5("123723");
    BigInteger n6("7561173581723517653167531725310938172936172");

    ASSERT_FALSE(n2 <= n1);
    ASSERT_FALSE(n1 <= n3);
    ASSERT_FALSE(n4 <= n3);
    ASSERT_FALSE(n2 <= n4);
    ASSERT_FALSE(n6 <= n2);
    ASSERT_FALSE(n5 <= n3);

    ASSERT_TRUE(n4 <= n5);
    ASSERT_TRUE(n5 <= n4);
    
    ASSERT_TRUE(n1 <= n6);
    ASSERT_TRUE(n3 <= n1);
}

TEST(CmpOpTest, equalTest){
    BigInteger n1 = 928392;
    BigInteger n2 = 973163;
    BigInteger n3 = -625372;
    BigInteger n4 = 123723;
    BigInteger n5("123723");
    BigInteger n6("7561173581723517653167531725310938172936172");

    ASSERT_FALSE(n2 == n1);
    ASSERT_FALSE(n1 == n3);
    ASSERT_FALSE(n4 == n3);
    ASSERT_FALSE(n2 == n4);
    ASSERT_FALSE(n6 == n2);
    ASSERT_FALSE(n5 == n3);

    ASSERT_TRUE(n4 == n5);
    ASSERT_TRUE(n5 == n4);
    
    ASSERT_FALSE(n1 == n6);
    ASSERT_FALSE(n3 == n1);
}

TEST(CmpOpTest, NeqTest){
    BigInteger n1 = 928392;
    BigInteger n2 = 973163;
    BigInteger n3 = -625372;
    BigInteger n4 = 123723;
    BigInteger n5("123723");
    BigInteger n6("7561173581723517653167531725310938172936172");

    ASSERT_TRUE(n2 != n1);
    ASSERT_TRUE(n1 != n3);
    ASSERT_TRUE(n4 != n3);
    ASSERT_TRUE(n2 != n4);
    ASSERT_TRUE(n6 != n2);
    ASSERT_TRUE(n5 != n3);

    ASSERT_FALSE(n4 != n5);
    ASSERT_FALSE(n5 != n4);
    
    ASSERT_TRUE(n1 != n6);
    ASSERT_TRUE(n3 != n1);
}

TEST(ArithmeticTest, SumTest){
    BigInteger n20 = 20;
    BigInteger n2 = 2;
    BigInteger n1 = 1;
    BigInteger n5 = 5;
    BigInteger n_5 = -5;
    BigInteger n_10 = -10;

    ASSERT_EQ(n20 + n2, (BigInteger) 22);
    ASSERT_EQ(n2 + n_10, (BigInteger) -8);
    ASSERT_EQ(n20 + n_5, (BigInteger) 15);
    ASSERT_EQ(n_10 + n2, (BigInteger) -8);
    ASSERT_EQ(n_5 + n20, (BigInteger) 15);
    ASSERT_EQ(n1 + n2, (BigInteger) 3);
    ASSERT_EQ(n_10 + n_5, (BigInteger) -15);
    
}

TEST(ArithmeticTest, SubTest){
    BigInteger n20 = 20;
    BigInteger n2 = 2;
    BigInteger n1 = 1;
    BigInteger n5 = 5;
    BigInteger n_5 = -5;
    BigInteger n_10 = -10;

    ASSERT_EQ(n20 - n2, (BigInteger) 18);
    ASSERT_EQ(n2 - n_10, (BigInteger) 12);
    ASSERT_EQ(n20 - n_5, (BigInteger) 25);
    ASSERT_EQ(n_10 - n2, (BigInteger) -12);
    ASSERT_EQ(n_5 - n20, (BigInteger) -25);
    ASSERT_EQ(n1 - n2, (BigInteger) -1);
    ASSERT_EQ(n_10 - n_5, (BigInteger) -5);
    
}

TEST(ArithmeticTest, MulTest){
    BigInteger n20 = 20;
    BigInteger n2 = 2;
    BigInteger n1 = 1;
    BigInteger n5 = 5;
    BigInteger n_5 = -5;
    BigInteger n_10 = -10;

    ASSERT_EQ(n20 * n2, (BigInteger) 40);
    ASSERT_EQ(n2 * n_10, (BigInteger) -20);
    ASSERT_EQ(n20 * n_5, (BigInteger) -100);
    ASSERT_EQ(n_10 * n2, (BigInteger) -20);
    ASSERT_EQ(n_5 * n20, (BigInteger) -100);
    ASSERT_EQ(n1 * n2, (BigInteger) 2);
    ASSERT_EQ(n_10 * n_5, (BigInteger) 50);
    
}

TEST(ArithmeticTest, DivTest){
    BigInteger n20 = 20;
    BigInteger n2 = 2;
    BigInteger n1 = 1;
    BigInteger n5 = 5;
    BigInteger n_5 = -5;
    BigInteger n_10 = -10;

    ASSERT_EQ(n20 / n2, (BigInteger) 10);
    ASSERT_EQ(n2 / n_10, (BigInteger) 0);
    ASSERT_EQ(n20 / n_5, (BigInteger) -4);
    ASSERT_EQ(n_10 / n2, (BigInteger) -5);
    ASSERT_EQ(n_5 / n20, (BigInteger) 0);
    ASSERT_EQ(n2 / n1, (BigInteger) 2);
    ASSERT_EQ(n_10 / n_5, (BigInteger) 2);
    
}

TEST(ArithmeticTest, ModTest){
    BigInteger n20 = 20;
    BigInteger n2 = 2;
    BigInteger n1 = 1;
    BigInteger n5 = 5;
    BigInteger n_5 = -5;
    BigInteger n_10 = -10;

    ASSERT_EQ(n20 % n2, (BigInteger) 0);
    ASSERT_EQ(n2 % n_10, (BigInteger) 2);
    ASSERT_EQ(n20 % n_5, (BigInteger) 0);
    ASSERT_EQ(n_10 % n2, (BigInteger) 0);
    ASSERT_EQ(n_5 % n20, (BigInteger) -5);
    ASSERT_EQ(n1 % n2, (BigInteger) 1);
    ASSERT_EQ(n_10 % n_5, (BigInteger) 0);
    
}

TEST(ArithmeticTest, InvTest){
    BigInteger n20 = 20;
    BigInteger n2 = 2;
    BigInteger n1 = 1;
    BigInteger n5 = 5;
    BigInteger n_5 = -5;
    BigInteger n_10 = -10;

    ASSERT_EQ(- n20, (BigInteger) -20);
    ASSERT_EQ(- n2, (BigInteger) -2);
    ASSERT_EQ(- n1, (BigInteger) -1);
    ASSERT_EQ(- n5, (BigInteger) -5);
    ASSERT_EQ(- n_5, (BigInteger) 5);
    ASSERT_EQ(- n_10, (BigInteger) 10);
    
}

