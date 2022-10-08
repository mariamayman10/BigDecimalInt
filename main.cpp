#include <bits/stdc++.h>
using namespace std;
class BigDecimalInt{
private:
    string number;
    int size;
public:
    BigDecimalInt(string decStr);
    BigDecimalInt(int decInt);
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    bool operator< (BigDecimalInt anotherDec);
    bool operator> (BigDecimalInt anotherDec);
    bool operator==(BigDecimalInt anotherDec);
    BigDecimalInt operator= (BigDecimalInt anotherDec);
};
int main() {

}
