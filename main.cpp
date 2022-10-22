#include <bits/stdc++.h>
using namespace std;
#define ll long long
string str1, str2;
int sign1, sign2;
static int AddSub;
bool check_if_all_zeroes(const string& string1){
    int counter = 0;
    for (char i : string1) {
        if(i == '0'){
            counter++;
        }
    }
    if(counter == string1.length()){
        return true;
    }
    else{
        return false;
    }
}
int menu_system(){
    cout << "________Welcome to BigDecimalInt Program________\n";
    cout << "The program provide the following processes:\n1-Subtract two numbers\n2-Add two numbers\n"
            "3-Check if the first number is greater than the second number\n4-Check if the second number is greater then the first number\n"
            "5-Check if the two numbers are equal\n6-Assign empty number with another number\n7-Get the size of a number\n"
            "8-Get the sign of a number\n9-Get the number\n10-EXIT\n\n";
    string choice;
    int choice_int;
    cout << "Your choice is: ";
    cin >> choice;
    while(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6"
            && choice != "7" && choice != "8" && choice != "9" && choice != "10"){
        cout << "Invalid Input, Try again\nYour choice is: ";
        cin >> choice;
    }
    cout << '\n';
    choice_int = stoi(choice);
    return choice_int;
}
class BigDecimalInt{
private:
    string number;
    unsigned ll size;
    int sign;
public:
    BigDecimalInt();
    BigDecimalInt(int decInt);
    BigDecimalInt(string decStr);
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    bool operator< (BigDecimalInt anotherDec);
    bool operator> (BigDecimalInt anotherDec);
    bool operator== (BigDecimalInt anotherDec);
    BigDecimalInt& operator= (BigDecimalInt anotherDec);
    unsigned ll Size();
    int Sign();
    string Number();
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
    else
    {
        sign = 1;
    }
}
BigDecimalInt:: BigDecimalInt(string decStr){
    int sum = 0;
    for (int i = 0; i < decStr.size(); i++) {
        if ((decStr[i] >= 48 && decStr[i] <= 57) || (decStr[i] == '+' && i == 0) || (decStr[i] == '-' && i == 0)) {
            sum += 1;
        }
    }
    if(sum == decStr.size()){
        if(decStr[0] == '-'){
            sign = 0;
            size = decStr.size() - 1;
            decStr.erase(decStr.begin());
            number = decStr;
        }
        else if(decStr[0] == '+'){
            sign = 1;
            size = decStr.size() - 1;
            decStr.erase(decStr.begin());
            number = decStr;
        }
        else{
            sign = 1;
            size = decStr.size();
            number = decStr;
        }
    }
    else {
        cout << "Invalid number, it will be used to be equal to 0\n";
        number = "0";
        sign = 1;
        size = 1;
    }
}
BigDecimalInt BigDecimalInt:: operator- (BigDecimalInt anotherDec) {
    BigDecimalInt result;
    sign1 = sign;
    sign2 = anotherDec.sign;
    int reminder = 0;
    int num1, num2, intresult;
    string result1, str_result, ch_to_str, StrNum1 = number, StrNum2 = anotherDec.number;
    unsigned ll add_zeroes;
    if(StrNum1.size() == StrNum2.size()){
        if(sign1 == sign2){
            if(sign1 == 1) {// 2 +ve
                if (StrNum1 >= StrNum2) {
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
                    if (!check_if_all_zeroes(result1)) {
                        for (int i = 0; i < result1.size(); ++i) {
                            if (result1[i] == '0') {
                                result1.erase(i, 1);
                                i--;
                            } else {
                                break;
                            }
                        }
                    } else {
                        result1 = "0";
                    }
                    result.number = result1;
                    result.sign = 1;
                    return result;
                }
                else{
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
                    if (!check_if_all_zeroes(result1)) {
                        for (int i = 0; i < result1.size(); ++i) {
                            if (result1[i] == '0') {
                                result1.erase(i, 1);
                                i--;
                            } else {
                                break;
                            }
                        }
                    } else {
                        result1 = "0";
                    }
                    result.number = result1;
                    result.sign = 0;
                    return result;
                }
            }
            else if(sign1 == 0){// 2 -ve
                if(StrNum1 > StrNum2){
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
                    if (!check_if_all_zeroes(result1)) {
                        for (int i = 0; i < result1.size(); ++i) {
                            if (result1[i] == '0') {
                                result1.erase(i, 1);
                                i--;
                            } else {
                                break;
                            }
                        }
                    } else {
                        result1 = "0";
                    }
                    result.number = result1;
                    result.sign = 0;
                    return result;
                }
                else{
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
                    if (!check_if_all_zeroes(result1)) {
                        for (int i = 0; i < result1.size(); ++i) {
                            if (result1[i] == '0') {
                                result1.erase(i, 1);
                                i--;
                            } else {
                                break;
                            }
                        }
                    } else {
                        result1 = "0";
                    }
                    result.number = result1;
                    result.sign = 1;
                    return result;
                }
            }
        }
        else if(sign1 != sign2){
            if(sign1 == 0){//-ve +ve
                BigDecimalInt first_number(number);
                BigDecimalInt second_number(anotherDec.number);
                result = first_number + second_number;
                result.sign = 0;
                return result;
            }
            else if(sign2 == 0){//+ve -ve
                BigDecimalInt first_number(number);
                BigDecimalInt second_number(anotherDec.number);
                result = first_number + second_number;
                return result;
            }
        }
    }
    else if(StrNum1.size() != StrNum2.size()){
        if(sign1 == sign2) {
            if (sign1 == 1) {// 2 +ve
                if (StrNum1.size() > StrNum2.size()) {
                    add_zeroes = StrNum1.size() - StrNum2.size();
                    for (int i = 0; i < add_zeroes; i++) {
                        StrNum2 = "0" + StrNum2;
                    }
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
                    if (!check_if_all_zeroes(result1)) {
                        for (int i = 0; i < result1.size(); ++i) {
                            if (result1[i] == '0') {
                                result1.erase(i, 1);
                                i--;
                            } else {
                                break;
                            }
                        }
                    } else {
                        result1 = "0";
                    }
                    result.number = result1;
                    result.sign = 1;
                    return result;
                }
                else {
                    add_zeroes = StrNum2.size() - StrNum1.size();
                    for (int i = 0; i < add_zeroes; i++) {
                        StrNum1 = "0" + StrNum1;
                    }
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
                    if (!check_if_all_zeroes(result1)) {
                        for (int i = 0; i < result1.size(); ++i) {
                            if (result1[i] == '0') {
                                result1.erase(i, 1);
                                i--;
                            } else {
                                break;
                            }
                        }
                    } else {
                        result1 = "0";
                    }
                    result.number = result1;
                    result.sign = 0;
                    return result;
                }
            }
            else if (sign1 == 0) {// 2 -ve
                if(StrNum1.size() > StrNum2.size()){
                    add_zeroes = StrNum1.size() - StrNum2.size();
                    for (int i = 0; i < add_zeroes; i++) {
                        StrNum2 = "0" + StrNum2;
                    }
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
                    if (!check_if_all_zeroes(result1)) {
                        for (int i = 0; i < result1.size(); ++i) {
                            if (result1[i] == '0') {
                                result1.erase(i, 1);
                                i--;
                            } else {
                                break;
                            }
                        }
                    } else {
                        result1 = "0";
                    }
                    result.number = result1;
                    result.sign = 0;
                    return result;
                }
                else{
                    add_zeroes = StrNum2.size() - StrNum1.size();
                    for (int i = 0; i < add_zeroes; i++) {
                        StrNum1 = "0" + StrNum1;
                    }
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
                    if (!check_if_all_zeroes(result1)) {
                        for (int i = 0; i < result1.size(); ++i) {
                            if (result1[i] == '0') {
                                result1.erase(i, 1);
                                i--;
                            } else {
                                break;
                            }
                        }
                    } else {
                        result1 = "0";
                    }
                    result.number = result1;
                    result.sign = 1;
                    return result;
                }
            }
        }
        else if(sign1 != sign2){
            if(sign1 == 0){// -ve +ve
                BigDecimalInt first_number(number);
                BigDecimalInt second_number(anotherDec.number);
                result = first_number + second_number;
                result.sign = 0;
                return result;
            }
            else if(sign2 == 0){// +ve -ve
                BigDecimalInt first_number(number);
                BigDecimalInt second_number(anotherDec.number);
                result = first_number + second_number;
                return result;
            }
        }
    }
    return anotherDec;
}
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec) {
    BigDecimalInt finalResultOfAdd;
    int carry = 0, test = 0;
    vector<int>vec;
    if((sign == 0 && anotherDec.sign == 0) || (sign == 1 && anotherDec.sign == 1)) {
        if(sign == 0 && anotherDec.sign == 0){
            AddSub = 2;
        }
        reverse(number.begin(), number.end());
        reverse(anotherDec.number.begin(), anotherDec.number.end());
        int ma, mi;
        ma = number.size();
        mi = anotherDec.number.size();
        if(ma >= mi) {
            for (int i = 0; i < mi; i++) {
                int n1, n2;
                string st1, st2;
                st1 = number[i];
                st2 = anotherDec.number[i];
                n1 = stoi(st1);
                n2 = stoi(st2);
                if (((n1 + n2 + carry)) >= 10) {
                    int I1, I2;
                    I1 = (n1 + n2 + carry) % 10;
                    I2 = (n1 + n2 + carry) / 10;
                    vec.push_back(I1);
                    carry = I2;
                } else {
                    vec.push_back(n1 + n2 + carry);
                    carry = 0;
                }
            }
            for(int j = mi ; j < ma ; j++){
                int n1;
                string st1;
                st1 = number[j];
                n1 = stoi(st1);
                if(n1 + carry >= 10){
                    int I1 = (n1 + carry) % 10;
                    vec.push_back(I1);
                    carry = (n1 + carry) / 10;
                }
                else{
                    vec.push_back(n1 + carry);
                    carry = 0;
                }
            }
            if (test == 0 && carry != 0) {
                vec.push_back(carry);
            }
            reverse(vec.begin(), vec.end());
            string resultOfAddition;
            reverse(vec.begin(), vec.end());
            for (int j: vec) {
                resultOfAddition += to_string(j);
            }

            reverse(resultOfAddition.begin(), resultOfAddition.end());
            if (AddSub == 2) {
                finalResultOfAdd.sign = 0;
                AddSub = 0;
            }
            finalResultOfAdd.number = resultOfAddition;
            return finalResultOfAdd;
        }
        else if(ma < mi) {//-35 -9999 -40 -50
            for (int i = 0; i < ma; i++) {
                int n1, n2;
                string st1, st2;
                st1 = number[i];
                st2 = anotherDec.number[i];
                n1 = stoi(st1);
                n2 = stoi(st2);
                if (((n1 + n2 + carry)) >= 10) {
                    int I1, I2;
                    I1 = (n1 + n2 + carry) % 10;
                    I2 = (n1 + n2 + carry) / 10;
                    vec.push_back(I1);
                    carry = I2;
                } else {
                    vec.push_back(n1 + n2 + carry);
                    carry = 0;
                }
            }
            for(int j = ma ; j < mi ; j++){
                int n1;
                string st1;
                st1 = anotherDec.number[j];
                n1 = stoi(st1);
                if(n1 + carry >= 10){
                    int I1 = (n1 + carry) % 10;
                    vec.push_back(I1);
                    carry = (n1 + carry) / 10;
                }
                else{
                    vec.push_back(n1 + carry);
                    carry = 0;
                }
            }
            if (test == 0 && carry != 0) {
                vec.push_back(carry);
            }
            reverse(vec.begin(), vec.end());
            string resultOfAddition;
            reverse(vec.begin(), vec.end());
            for (int j: vec) {
                resultOfAddition += to_string(j);
            }

            reverse(resultOfAddition.begin(), resultOfAddition.end());
            if (AddSub == 2) {
               finalResultOfAdd.sign = 0;
               AddSub = 0;
            }
            finalResultOfAdd.number = resultOfAddition;
            return finalResultOfAdd;
        }
    }
    else{
        if(sign == 0){
            BigDecimalInt num1(number);
            BigDecimalInt num2(anotherDec.number);
            finalResultOfAdd = num2 - num1 ;
        }
        else{
            BigDecimalInt num1(number);
            BigDecimalInt num2(anotherDec.number);
            finalResultOfAdd = num1 - num2;
        }
        return finalResultOfAdd;
    }
}
bool BigDecimalInt::operator<(BigDecimalInt anotherDec) {
    if (sign == 0 || anotherDec.sign == 0) {
        if (sign == 0 && anotherDec.sign != 0) {
            return true;
        } else if (sign != 0 && anotherDec.sign == 0) {
            return false;
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
    else {
        if (size > anotherDec.size) {
            return false;
        }
        else if (size < anotherDec.size) {
            return true;
        }
        else {
            for (int i = 0; i < size; ++i) {
                if (number[i] > anotherDec.number[i]) {
                    return false;
                }
            }
        }
        return false;
    }
}
bool BigDecimalInt::operator>(BigDecimalInt anotherDec) {
    if (sign == 0 || anotherDec.sign == 0) {
        if (sign == 0 && anotherDec.sign != 0) {
            return false;
        } else if (sign != 0 && anotherDec.sign == 0) {
            return true;
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
    if (number == anotherDec.number && sign == anotherDec.sign) {
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
    return size;
}
int BigDecimalInt::Sign() {
    return sign;
}
string BigDecimalInt::Number() {
    return number;
}
ostream &operator<<(ostream &out, const BigDecimalInt &b) {
    if(b.sign == 0){
        out << "-" << b.number << '\n';
        return out;
    }
    else{
        out << b.number << '\n';
        return out;
    }
}

int main() {
    int option;
    option = menu_system();
    while(option != 10){
        if(option == 1){
            cout << "Enter the first number: ";
            cin >> str1;
            cout << "\nEnter the second number: ";
            cin >> str2;
            BigDecimalInt n1 = BigDecimalInt(str1);
            BigDecimalInt n2 = BigDecimalInt(str2);
            cout << "\nThe result of subtraction is " << n1 - n2 << "\n\n";
        }
        else if(option == 2){
            cout << "Enter the first number: ";
            cin >> str1;
            cout << "\nEnter the second number: ";
            cin >> str2;
            BigDecimalInt n1 = BigDecimalInt(str1);
            BigDecimalInt n2 = BigDecimalInt(str2);
            cout << "\nThe result of addition is " << n1 + n2 << "\n";
        }
        else if(option == 3){
            bool ans;
            cout << "Enter the first number: ";
            cin >> str1;
            cout << "\nEnter the second number: ";
            cin >> str2;
            BigDecimalInt n1 = BigDecimalInt(str1);
            BigDecimalInt n2 = BigDecimalInt(str2);
            ans = n1 > n2;
            if(ans)cout << "\nThe first number is greater than the second number\n\n";
            else cout << "\nThe first number isn't greater than the second number\n\n";
        }
        else if(option == 4){
            bool ans;
            cout << "Enter the first number: ";
            cin >> str1;
            cout << "\nEnter the second number: ";
            cin >> str2;
            BigDecimalInt n1 = BigDecimalInt(str1);
            BigDecimalInt n2 = BigDecimalInt(str2);
            ans = n1 < n2;
            if(ans)cout << "\nThe second number is greater than the first number\n\n";
            else cout << "\nThe second number isn't greater than the first number\n\n";
        }
        else if(option == 5){
            bool ans;
            cout << "Enter the first number: ";
            cin >> str1;
            cout << "\nEnter the second number: ";
            cin >> str2;
            BigDecimalInt n1 = BigDecimalInt(str1);
            BigDecimalInt n2 = BigDecimalInt(str2);
            ans = n1 == n2;
            if(ans)cout << "\nThe numbers are equal\n\n";
            else cout << "\nThe numbers aren't equal\n\n";
        }
        else if(option == 6){
            cout << "Enter a number: ";
            cin >> str1;
            BigDecimalInt n1 = BigDecimalInt(str1), n2;
            cout << "\nBefore assigning value in the variable n2 it equals to " << n2 << '\n';
            n2 = n1;
            cout << "After assigning value in the variable n2 it equals to " << n2 << '\n';
        }
        else if(option == 7){
            cout << "Enter a number: ";
            cin >> str1;
            BigDecimalInt n1 = BigDecimalInt(str1);
            cout << "\nThe size of the number equals to = " << n1.Size() << "\n\n";
        }
        else if(option == 8){
            cout << "Enter a number: ";
            cin >> str1;
            BigDecimalInt n1 = BigDecimalInt(str1);
            cout << "\nThe size of the number equals to = " << n1.Sign() << "\n\n";
        }
        else if(option == 9){
            cout << "Enter a number: ";
            cin >> str1;
            BigDecimalInt n1 = BigDecimalInt(str1);
            cout << "\nThe size of the number equals to = " << n1.Number() << "\n\n";
        }
        option = menu_system();
    }
    cout << "Thanks for using our program\n\n";
}

