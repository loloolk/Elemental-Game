#include <string>

#ifndef factorial_
#define factorial_

int factorial(int number) {
    int iteration, factorial = 1;
    for(iteration = 1; iteration <= number; iteration++) {
        factorial=factorial*iteration;
    }
    return factorial;
}

int powerOf(int num1, int num2) {
    int b = num1;
    for (int i = 1; i <= num2; i++) {
        num1 *= b;
    }
    return num1;
}

bool noSpace(std::string a) {
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == ' ') {
            return true;
        }
    }
    return false;
}

std::string tidyText(std::string a) {
    a[0] = toupper(a[0]);    
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == ' ') {
            a[i + 1] = toupper(a[i + 1]);
        }
        if (i != 0 && a[i - 1] != ' ') {
            a[i] = tolower(a[i]);
        }
    }
    int fred = a.length();
    for (int i = fred + fred; i > 0; i--) {
        if (a[i] == ' ' && a[i + 1] == ' ') {
            a.erase(i, 1);
        }
        if (a[0] == ' ') {
            a.erase(0, 1);
        }
        if (a[a.length() - 1] == ' ') {
            a.erase(a.length() - 1, 1);
        }
    }
    return a;
}

/*int randNum(int i) {
    srand((unsigned) time(0));
    return (rand() % i) + 1;
}*/

#endif