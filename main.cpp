#include "BigDecimalInt.h"

int main() {
    int option = menu_system();
    while(true) {
        options(option);
        option = menu_system();
        if(option == 10){
            cout << "Thanks for using our program\n\n";
            break;
        }
    }
}
