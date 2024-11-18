#pragma once
#include <string>

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
