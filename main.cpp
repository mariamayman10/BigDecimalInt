#include <bits/stdc++.h>
using namespace std;
#define ll long long
string str1, str2;
int s1, s2, sign1, sign2;
class BigDecimalInt{
private:
    string number;
    unsigned ll size;
    int sign;
public:
    BigDecimalInt();
    BigDecimalInt(int decInt);
    BigDecimalInt(string decStr, unsigned ll decSz, int decSign);
    //BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
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
BigDecimalInt::BigDecimalInt(int decInt ){
    number = to_string(decInt);
    size = number.size();
    if(number[0] == '-'){
        sign = 0;
    }
    else{
        sign = 1;
    }
}
BigDecimalInt::BigDecimalInt(string decStr, unsigned ll decSz,int decSign ){
    number = decStr;
    size = decSz;
    sign = decSign;
}
BigDecimalInt BigDecimalInt:: operator- (BigDecimalInt anotherDec) {
    BigDecimalInt result;
    sign1 = this->Sign();
    sign2 = anotherDec.Sign();
    int reminder = 0;
    int num1, num2, intresult;
    string result1, str_result, ch_to_str, StrNum1 = this->number, StrNum2 = anotherDec.number;
    unsigned ll add_zeroes;
    if (sign1 == 0) {
        StrNum1[0] = '0';
    }
    if (sign2 == 0) {
        StrNum2[0] = '0';
    }
    cout <<  sign1 << ' ' << sign2 << '\n';
    if (StrNum1.size() != StrNum2.size()) {
        if (StrNum1.size() > StrNum2.size()) {
            add_zeroes = StrNum1.size() - StrNum2.size();
            for (int i = 0; i < add_zeroes; i++) {
                StrNum2 = "0" + StrNum2;
            }
        } else {
            add_zeroes = StrNum2.size() - StrNum1.size();
            for (int i = 0; i < add_zeroes; i++) {
                StrNum1 = "0" + StrNum1;
            }
        }
    }
    if (sign1 == 1 && sign2 == 1) {//2 +ve nums
        if (StrNum2 > StrNum1) {
            swap(StrNum1, StrNum2);
            for (int i = StrNum1.size() - 1; i > -1; i--) {
                ch_to_str = StrNum1[i];
                num1 = stoi(ch_to_str);
                ch_to_str = StrNum2[i];
                num2 = stoi(ch_to_str);
                if (reminder > 0) {
                    num1 -= reminder;
                    reminder--;
                }
                if (num1 < num2) {
                    intresult = (num1 + 10) - num2;
                    reminder++;
                } else {
                    intresult = num1 - num2;
                }
                str_result = to_string(intresult);
                result1 = str_result + result1;
            }
            for (int i = 0; i < result1.size(); ++i) {
                if(result1[i] == '0'){
                    result1.erase(i, 1);
                    i--;
                }
                else{
                    break;
                }
            }
            result.number = result1;
            result.sign = 0;
            return result;
        }
        else{
            for (int i = StrNum1.size() - 1; i > -1; i--) {
                ch_to_str = StrNum1[i];
                num1 = stoi(ch_to_str);
                ch_to_str = StrNum2[i];
                num2 = stoi(ch_to_str);
                if (reminder > 0) {
                    num1 -= reminder;
                    reminder--;
                }
                if (num1 < num2) {
                    intresult = (num1 + 10) - num2;
                    reminder++;
                } else {
                    intresult = num1 - num2;
                }
                str_result = to_string(intresult);
                result1 = str_result + result1;
            }
            for (int i = 0; i < result1.size(); ++i) {
                if(result1[i] == '0'){
                    result1.erase(i, 1);
                    i--;
                }
                else{
                    break;
                }
            }
            result.number = result1;
            result.sign = 1;
            return result;
        }
    }
    else if (sign1 == 0 && sign2 == 0) {//two -ve nums
        if (StrNum2 > StrNum1) {
            swap(StrNum1, StrNum2);
            for (int i = StrNum1.size() - 1; i > -1; i--) {
                ch_to_str = StrNum1[i];
                num1 = stoi(ch_to_str);
                ch_to_str = StrNum2[i];
                num2 = stoi(ch_to_str);
                if (reminder > 0) {
                    num1 -= reminder;
                    reminder--;
                }
                if (num1 < num2) {
                    intresult = (num1 + 10) - num2;
                    reminder++;
                } else {
                    intresult = num1 - num2;
                }
                str_result = to_string(intresult);
                result1 = str_result + result1;
            }
            for (int i = 0; i < result1.size(); ++i) {
                if(result1[i] == '0'){
                    result1.erase(i, 1);
                    i--;
                }
                else{
                    break;
                }
            }
            result.number = result1;
            result.sign = 1;
            return result;
        }
        else {
            for (int i = StrNum1.size() - 1; i > -1; i--) {
                ch_to_str = StrNum1[i];
                num1 = stoi(ch_to_str);
                ch_to_str = StrNum2[i];
                num2 = stoi(ch_to_str);
                if (reminder > 0) {
                    num1 -= reminder;
                    reminder--;
                }
                if (num1 < num2) {
                    intresult = (num1 + 10) - num2;
                    reminder++;
                } else {
                    intresult = num1 - num2;
                }
                str_result = to_string(intresult);
                result1 = str_result + result1;

            }
            for (int i = 0; i < result1.size(); ++i) {
                if(result1[i] == '0'){
                    result1.erase(i, 1);
                    i--;
                }
                else{
                    break;
                }
            }
            result.number = result1;
            result.sign = 0;
            return result;
        }
    }
    else if (sign2 == 0 || sign1 == 0) {//
        for (int i = StrNum1.size() - 1; i > -1; i--) {
            ch_to_str = StrNum1[i];
            num1 = stoi(ch_to_str);
            num1 += reminder;
            if (reminder > 0) {
                reminder--;
            }
            ch_to_str = StrNum2[i];
            num2 = stoi(ch_to_str);
            intresult = num1 + num2;
            if (intresult >= 10 && i != 0) {
                intresult -= 10;
                reminder++;
            }
            str_result = to_string(intresult);
            result1 = str_result + result1;
            result.number = result1;
        }
        if (sign1 == 0) {
            result.sign = 0;
        }
        return result;
    }
    return anotherDec;
}
bool BigDecimalInt::operator<(BigDecimalInt anotherDec) {
    if (number[0] == '-' || anotherDec.number[0] == '-') {
        if (number[0] == '-' && anotherDec.number[0] != '-') {
            return true;
        } else if (number[0] != '-' && anotherDec.number[0] == '-') {
            return false;
        } else {
            if (number.length() - 1 > anotherDec.number.length() - 1) {
                return true;
            } else if (number.length() - 1 < anotherDec.number.length() - 1) {
                return false;
            } else {
                for (int i = 0; i < size; ++i) {
                    if (number[i] > anotherDec.number[i]) {
                        return true;
                    }
                }
            }
            return true;
        }
    } else {
        if (size > anotherDec.size) {
            return false;
        } else if (size < anotherDec.size) {
            return true;
        } else {
            for (int i = 0; i < size; ++i) {
                if (number[i] > anotherDec.number[i]) {
                    return false;
                }
            }
        }
        return true;
    }

}
bool BigDecimalInt::operator>(BigDecimalInt anotherDec) {
    if (number[0] == '-' || anotherDec.number[0] == '-') {
        if (number[0] == '-' && anotherDec.number[0] != '-') {
            return false;
        } else if (number[0] != '-' && anotherDec.number[0] == '-') {
            return true;
        } else {
            if (number.length() - 1 > anotherDec.number.length() - 1) {
                return false;
            } else if (number.length() - 1 < anotherDec.number.length() - 1) {
                return true;
            } else {
                for (int i = 0; i < size; ++i) {
                    if (number[i] > anotherDec.number[i]) {
                        return false;
                    }
                }
            }
            return false;
        }
    } else {
        if (size > anotherDec.size) {
            return true;
        } else if (size < anotherDec.size) {
            return false;
        } else {
            for (int i = 0; i < size; ++i) {
                if (number[i] > anotherDec.number[i]) {
                    return true;
                }
            }
        }
        return false;
    }
}
bool BigDecimalInt::operator==(BigDecimalInt anotherDec) {
    if (number == anotherDec.number) {
        return true;
    }
    return false;
}
BigDecimalInt &BigDecimalInt::operator=(BigDecimalInt anotherDec) {
    number = anotherDec.number;
    size = anotherDec.size;
    sign = anotherDec.sign;
    return *this;
}
unsigned ll BigDecimalInt::Size() {
    if (number[0] == '-') {
        return number.length() - 1;
    } else {
        return number.length();
    }
}
int BigDecimalInt::Sign() {
    if (number[0] == '-') {
        return 0;
    } else {
        return 1;
    }
}
ostream &operator<<(ostream &out, const BigDecimalInt &b) {
    if(b.sign == 0){
        cout << "Number = ";
        out << "-" << b.number << '\n';
        return out;
    }
    else{
        cout << "Number = ";
        out << b.number << '\n';
        return out;
    }
}
int main() {
    cin >> str1 >> str2;
    s1 = str1.length();
    s2 = str2.length();
    if (str1[0] == '-') {
        sign1= 0;
    } else {
        sign1= 1;
    }
    if (str2[0] == '-') {
        sign2= 0;
    } else {
        sign2= 1;
    }

    BigDecimalInt n1 = BigDecimalInt(str1, s1, sign1);
    BigDecimalInt n2 = BigDecimalInt(str2, s2, sign2);
    cout << n1-n2;

}

