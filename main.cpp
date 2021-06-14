#include <iostream>
#include "MyString.h"
int main() {
    MyString str = "Test";
    MyString str1 = " String";
    MyString sumstr;
    sumstr = str + str1;
    sumstr.Print();
    std::cout << sumstr[0];

}
