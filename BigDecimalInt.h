#ifndef BIGDECIMALINT_BIGDECIMALINT_H
#define BIGDECIMALINT_BIGDECIMALINT_H
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

static int AddSub;
bool check_if_all_zeroes(const string& string1);
int menu_system();
int options(int choice);
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
ostream &operator<<(ostream &out, const BigDecimalInt &b);

#endif //BIGDECIMALINT_BIGDECIMALINT_H
