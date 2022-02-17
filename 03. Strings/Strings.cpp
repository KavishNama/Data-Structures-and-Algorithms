#include <iostream>
using namespace std;

// Helper function to swap two characters
void swap(char* a, char* b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Printing all permutations of a string - Method 1: Using Auxiliary array
void perm1(char s[], int k) {
    static int counter[10] = { 0 };
    static char Res[10];
    int i;
    if (s[k] == '\0') {
        Res[k] = '\0';
        cout << Res << endl;
    }
    else {
        for (i = 0; s[i] != '\0'; i++) {
            if (counter[i] == 0) {
                Res[k] = s[i];
                counter[i] = 1;
                perm1(s, k + 1);
                counter[i] = 0;
            }
        }
    }
}

// Printing all permutations of a string - Method 2: Using Swapping
void perm2(char s[], int l, int h) {
    int i;
    if (l == h) {
        cout << s << endl;
    }
    else {
        for (i = l; i <=h ; i++) {
            swap(&s[l], &s[i]);
            perm2(s, l + 1, h);
            swap(&s[l], &s[i]);
        }
    }
}

int main()
{
    // Declaring and Initialising a character variable
    char temp = 'a';

    // Declaring and Initialising an array of characters
    char arr1[5] = { 'A','B','C','D','E' };
    char arr2[] = { 'A','B','C' };
    char arr3[5] = { 65,66,67,68,69 };
    char arr4[5] = { 'a','b' };

    // Declaring and Initialising a string
    char string1[10] = { 'J','o','h','n','\0' };
    char string2[] = { 'J','o','h','n','\0' };
    char string3[] = "John";
    const char *string4 = "John";

    // Printing a string
    cout << string1 << endl;

    // Finding the length of a string
    int i;
    for (i = 0; string1[i] != '\0'; i++){}
    cout << "Length of string1 is: " << i << endl;


    // Toggling the case of a string
    char string5[] = "WElcOmE";
    for (i = 0; string5[i] != '\0'; i++) {
        if (string5[i] >= 65 && string5[i] <= 90) {
            string5[i] += 32;
        }
        else if (string5[i] >= 'a' && string5[i] <= 'z') {
            string5[i] -= 32;
        }
    }
    cout << "Toggled string: " << string5 << endl;

    // Counting vowels and consonants in a string
    char string6[] = "How are you";
    int vcount = 0, ccount = 0;
    for (i = 0; string6[i] != '\0'; i++) {
        if (string6[i] == 'a' || string6[i] == 'e' || string6[i] == 'i' || string6[i] == 'o' || string6[i] == 'u' || string6[i] == 'A' || string6[i] == 'E' || string6[i] == 'I' || string6[i] == 'O' || string6[i] == 'U') {
            vcount++;
        }
        else if ((string6[i] >= 65 && string6[i] <= 90) || (string6[i] >= 97 && string6[i] <= 122)) {
            ccount++;
        }
    }
    cout << "Vowels: " << vcount << ", Consonants: " << ccount << endl;

    // Counting number of words
    char string7[] = "How are you";
    int space = 0;
    for (i = 0; string7[i] != '\0'; i++) {
        if (string7[i] == ' ' && string7[i - 1] != ' ') {
            space++;
        }
    }
    cout << "Number of words are: " << space + 1 << endl;

    // Checking validity of a string
    char string8[] = "Kavish@123";
    bool flag = true;
    for (i = 0; string8[i] != '\0'; i++) {
        if (!(string8[i] >= 65 && string8[i] <= 90) && !(string8[i] >= 97 && string8[i] <= 122) && !(string8[i] >= 48 && string8[i] <= 57)) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "String is valid" << endl;
    }
    else {
        cout << "String is invalid" << endl;
    }

    // Reversing a string - Method 1: Using auxiliary string
    char A[] = "python";
    char B[7];
    for (i = 0; A[i] != '\0'; i++) {}
    i--;
    int j;
    for (j = 0; i >= 0; i--, j++) {
        B[j] = A[i];
    }
    B[j] = '\0';
    cout << "Reversed string: " << B << endl;

    // Reversing a string - Method 2: Changing same string
    char C[] = "kavish";
    char t;
    for (j = 0; A[j] != '\0'; j++) {}
    j--;
    for (i = 0; i < j; i++, j--) {
        t = C[i];
        C[i] = C[j];
        C[j] = t;
    }
    cout << "Reversed string: " << C << endl;

    // Comparing two strings
    char D[] = "painter";
    char E[] = "painting";
    for (i = 0, j = 0; D[i] != '\0' && E[j] != '\0'; i++, j++) {
        if (D[i] != E[j]) {
            break;
        }
    }
    if (D[i] == E[j])
        cout << "Strings are equal" << endl;
    else if (D[i] < E[j])
        cout << "First string is smaller" << endl;
    else
        cout << "Second string is smaller" << endl;

    // Checking Palindrome - Method 1: Using auxiliary string
    char F[] = "madam";
    char G[10];
    for (i = 0; F[i] != '\0'; i++) {}
    i--;
    for (j = 0; i >= 0; i--, j++) {
        G[j] = F[i];
    }
    G[j] = '\0';
    for (i = 0, j = 0; F[i] != '\0' && G[j] != '\0'; i++, j++) {
        if (F[i] != G[j]) {
            break;
        }
    }
    if (F[i] == G[j])
        cout << "Palindrome" << endl;
    else 
        cout << "Not Palindrome" << endl;

    // Checking Palindrome - Method 2: Using same string
    char H[] = "racecar";
    flag = true;
    for (j = 0; H[j] != '\0'; j++) {}
    j--;
    for (i = 0; i < j; i++, j--) {
        if (H[i] != H[j]) {
            flag = false;
            break;
        }  
    }
    if (flag) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not Palindrome" << endl;
    }

    // Finding duplicates in a string - Method 1: Search each character in the string
    char myString[] = "mississippi";
    int count, strlength;
    for (strlength = 0; myString[strlength] != '\0'; strlength++) {}
    for (i = 0; i < strlength - 1; i++) {
        count = 1;
        if (myString[i] != ' ') {
            for (j = i + 1; j < strlength; j++) {
                if (myString[i] == myString[j]) {
                    count++;
                    myString[j] = ' ';
                }
            }
        }
        if (count > 1) {
            cout << myString[i] << " appeared for " << count << " times" << endl;
        }
    }

    // Finding duplicates in a string - Method 2: Using hashtable
    char mystring2[] = "finding";
    int Hash[26]={0};
    for (i = 0; mystring2[i] != '\0'; i++) {
        Hash[mystring2[i] - 97] += 1;
    }
    for (i = 0; i < 26; i++) {
        if (Hash[i] > 1) {
            cout << char(i + 97) << " appeared for " << Hash[i] << " times" << endl;
        }
    }

    // Finding duplicates in a string - Method 3: Using bitwise operations
    char mystring3[] = "finding";
    int H1 = 0, x1 = 0;
    for (i = 0; mystring3[i] != '\0'; i++) {
        x1 = 1;
        x1 = x1 << (mystring3[i] - 97);
        if ((x1 & H1) > 0) {
            cout << mystring3[i] << " is duplicate" << endl;
        }
        else {
            H1 = x1 | H1;
        }
    }

    // Checking if two strings are anagrams
    char mystring4[] = "decimal";
    char mystring5[] = "medical";
    int H2[26] = { 0 };
    for (i = 0; mystring4[i] != '\0'; i++) {
        H2[mystring4[i] - 97] += 1;
    }
    for (i = 0; mystring5[i] != '\0'; i++) {
        H2[mystring5[i] - 97] -= 1;
        if (H2[mystring5[i] - 97] < 0) {
            cout << "Not Anagrams" << endl;
            break;
        }
    }
    if (mystring5[i] == '\0') {
        cout << "Anagrams" << endl;
    }

    // Printing all permutations of a string - Method 1: Using Auxiliary array
    char s[] = "ABC";
    cout << "Permutations of ABC are: " << endl;
    perm1(s, 0);

    // Printing all permutations of a string - Method 2: Using Swapping
    char s2[] = "XYZ";
    cout << "Permutations of XYZ are: " << endl;
    perm2(s2, 0, 2);


    return 0;
}