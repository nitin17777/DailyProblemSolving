#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    vector<int> freq(26, 0);

    // Count letters in magazine
    for (char ch : magazine) {
        freq[ch - 'a']++;
    }

    // Check ransomNote letters
    for (char ch : ransomNote) {
        if (freq[ch - 'a'] == 0)
            return false;

        freq[ch - 'a']--;
    }

    return true;
}

int main() {
    string ransomNote = "aa";
    string magazine = "aab";

    if (canConstruct(ransomNote, magazine))
        cout << "true";
    else
        cout << "false";

    return 0;
}