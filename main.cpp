#include <bits/stdc++.h>

using namespace std;
class BigDecimalInt{
private:
    string number;
    int size;
    int sign;
public:
    BigDecimalInt();
    BigDecimalInt(string decStr, int decSz, int decSign);
    //BigDecimalInt operator+ (BigDecimalInt anotherDec);
    //BigDecimalInt operator- (BigDecimalInt anotherDec);
    //bool operator< (BigDecimalInt anotherDec);
    bool operator> (BigDecimalInt anotherDec);
    bool operator== (BigDecimalInt anotherDec);
    BigDecimalInt operator= (BigDecimalInt anotherDec);
    int Size();
    int Sign();
    //friend ostream& operator << (ostream& out, BigDecimalInt b);
};
BigDecimalInt::BigDecimalInt(){
    number = "0";
    size = 1;
    sign = 1;
}
BigDecimalInt::BigDecimalInt(string decStr, int decSz, int decSign){
    number = decStr;
    size = decSz;
    sign = decSign;
}
bool BigDecimalInt:: operator> (BigDecimalInt anotherDec){
    if(size > anotherDec.size){
        return true;
    }
    else if(size < anotherDec.size){
        return false;
    }
    else{
        for (int i = 0; i < size; ++i) {
            if(number[i] > anotherDec.number[i]){
                return true;
            }
        }
    }
    return false;
}
bool BigDecimalInt::operator== (BigDecimalInt anotherDec){
    int check = 0;
    if(size != anotherDec.size){
        return false;
    }
    else{
        for (int i = 0; i < size && check == 0; ++i) {
            if(number[i] != anotherDec.number[i]){
                check = 1;
                return false;
            }
        }
    }
    return true;
}
int BigDecimalInt::Size(){
    if(number[0] == '-'){
        return number.length()-1;
    }
    else{
        return number.length();
    }
}
int BigDecimalInt::Sign(){
    if(number[0] == '-'){
        return 0;
    }
    else{
        return 1;
    }
}

int main() {
    string str1, str2;
    int s1, s2, sign1, sign2;
    cin >> str1 >> s1 >> str2 >> s2;
    if(str1[0] == '-'){
        sign1 = 0;
    }
    else{
        sign1 = 1;
    }
    if(str2[0] == '-'){
        sign2 = 0;
    }
    else{
        sign2 = 1;
    }
    BigDecimalInt n1 = BigDecimalInt(str1, s1, sign1);
    BigDecimalInt n2 = BigDecimalInt(str2, s2, sign2);
}
