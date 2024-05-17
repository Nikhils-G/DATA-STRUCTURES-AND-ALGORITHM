#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if two strings are anagrams
bool isAnagram(char* s, char* t) {
    // Check if the lengths are different
    if (strlen(s) != strlen(t)) {
        return false;
    }

    // Create an array to count character frequencies
    int count[26] = {0}; // Assuming the strings only contain lowercase English letters

    // Count characters in the first string
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
    }

    // Decrease count for characters in the second string
    for (int i = 0; t[i] != '\0'; i++) {
        count[t[i] - 'a']--;
    }

    // Check if all counts are zero
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    char s[] = "abc";
    char t[] = "cba";

    if (isAnagram(s, t)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
