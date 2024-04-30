#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int prime = 13; 
const int base = 10; 

int rolling_hash(const string& str, int len) {
    int hash_val = 0;
    for (int i = 0; i < len; ++i) {
        hash_val += (int)str[i] * pow(base, len - i - 1);
    }
    return hash_val;
}

void rabin_karp(const string& text, const string& pattern) {
    int text_len = text.length();
    int pattern_len = pattern.length();
    int text_hash = rolling_hash(text, pattern_len);
    int pattern_hash = rolling_hash(pattern, pattern_len);

    for (int i = 0; i <= text_len - pattern_len; ++i) {
        if (text_hash == pattern_hash) {
            bool match = true;
            for (int j = 0; j < pattern_len; ++j) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }
        if (i < text_len - pattern_len) {
            text_hash = (base * (text_hash - (int)text[i] * pow(base, pattern_len - 1))) + (int)text[i + pattern_len];
        }
    }
}

int main() {
    string text = "3141592653589793";
    string pattern = "26";
    rabin_karp(text, pattern);
    return 0;
}
