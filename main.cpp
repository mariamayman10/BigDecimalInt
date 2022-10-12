#include <bits/stdc++.h>
using namespace std;
#define ll long long
string str1, str2;
int s1, s2, sign1, sign2;
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
    bool operator< (BigDecimalInt anotherDec);
    bool operator> (BigDecimalInt anotherDec);
    bool operator== (BigDecimalInt anotherDec);
    BigDecimalInt& operator= (BigDecimalInt anotherDec);
    unsigned ll Size();
    int Sign();
    friend ostream& operator << (ostream& out, const BigDecimalInt& b);
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
bool BigDecimalInt:: operator< (BigDecimalInt anotherDec){
    if(number[0] == '-' || anotherDec.number[0] == '-'){
        if(number[0] == '-' && anotherDec.number[0] != '-'){
            return true;
        }
        else if(number[0] != '-' && anotherDec.number[0] == '-'){
            return false;
        }
        else{
            if(number.length() - 1 > anotherDec.number.length() - 1){
                return true;
            }
            else if(number.length() - 1 < anotherDec.number.length() - 1){
                return false;
            }
            else{
                for (int i = 0; i < size; ++i) {
                    if(number[i] > anotherDec.number[i]){
                        return true;
                    }
                }
            }
            return true;
        }
    }
    else{
        if(size > anotherDec.size){
            return false;
        }
        else if(size < anotherDec.size){
            return true;
        }
        else{
            for (int i = 0; i < size; ++i) {
                if(number[i] > anotherDec.number[i]){
                    return false;
                }
            }
        }
        return true;
    }

}
bool BigDecimalInt:: operator> (BigDecimalInt anotherDec){
    if(number[0] == '-' || anotherDec.number[0] == '-'){
        if(number[0] == '-' && anotherDec.number[0] != '-'){
            return false;
        }
        else if(number[0] != '-' && anotherDec.number[0] == '-'){
            return true;
        }
        else{
            if(number.length() - 1 > anotherDec.number.length() - 1){
                return false;
            }
            else if(number.length() - 1 < anotherDec.number.length() - 1){
                return true;
            }
            else{
                for (int i = 0; i < size; ++i) {
                    if(number[i] > anotherDec.number[i]){
                        return false;
                    }
                }
            }
            return false;
        }
    }
    else{
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
}
bool BigDecimalInt::operator== (BigDecimalInt anotherDec){
    if(number == anotherDec.number){
        return true;
    }
    return false;
}
BigDecimalInt& BigDecimalInt:: operator= (BigDecimalInt anotherDec){
    number = anotherDec.number;
    size = anotherDec.size;
    sign = anotherDec.sign;
    return *this;
}
unsigned ll BigDecimalInt::Size(){
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
ostream& operator << (ostream& out, const BigDecimalInt& b){
    cout << "Number = ";
    out << b.number << '\n';
    return out;
}
int main() {
    cin >> str1 >> str2;
    s1 = str1.length();
    s2 = str2.length();
    if (str1[0] == '-') {
        sign1 = 0;
    } else {
        sign1 = 1;
    }
    if (str2[0] == '-') {
        sign2 = 0;
    } else {
        sign2 = 1;
    }
    BigDecimalInt n1 = BigDecimalInt(str1, s1, sign1);
    BigDecimalInt n2 = BigDecimalInt(str2, s2, sign2);
}

