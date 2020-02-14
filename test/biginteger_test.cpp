#include "../include/biginteger.h"
#include "test.h"

using namespace std;

int test_geometry(){
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