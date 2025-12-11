#include <bits/stdc++.h>
using namespace std;

// Function to compute LPS (Longest Prefix Suffix) array
void computeLPS(string pattern, vector<int> &lps) {
    int n = pattern.size();
    lps[0] = 0;  // first character has LPS = 0
    int len = 0; // length of previous longest prefix suffix
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // fall back
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search function
void KMP(string text, string pattern) {
    int m = pattern.size();
    int n = text.size();

    vector<int> lps(m);
    computeLPS(pattern, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    cout << "Pattern found at indices: ";

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << (i - j) << " "; // pattern found at i-j
            j = lps[j - 1]; // look for next possible match
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    cout << endl;
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    KMP(text, pattern);

    return 0;
}
