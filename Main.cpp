#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class CaesarCipher {
public:
    string Caesar(string s, int k) {
        string s2;

        for (char c : s) {
            if ('a' <= c && c <= 'z') {
                int val = c - 'a';
                val = (val + k) % 26;
                val = 'a' + val;
                s2 += val;
            } else if ('A' <= c && c <= 'Z') {
                int val = c - 'A';
                val = (val + k) % 26;
                val = 'A' + val;
                s2 += val;
            } else {
                s2 += c;
            }
        }
        return s2;
    }
};
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)

// Input: vatsal key: 3 Output: ydwvdo



class AtbashCipher {
public:
    void encryptDecrypt(string& text) {
        for (char& c : text) {
            if (c >= 'A' && c <= 'Z') {
                c = 'Z' - (c - 'A');
            } else if (c >= 'a' && c <= 'z') {
                c = 'z' - (c - 'a');
            }
        }
    }
};
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(1) 
// Input: vatsal Output: ezghzo




class KeywordCipher {
public:
    string KcEncrypt(string key, string s1) {
        char S[26];
        int k = 0;
        for (char i = 'A'; i <= 'Z'; i++) {
            S[k] = i;
            // cout << S[k];
            k++;
        }
        cout << "\n";

        
           

            // Convert keyword to uppercase
            transform(key.begin(), key.end(), key.begin(), ::toupper);

            char E[26];
            char in[26];
            int x = key.length();
            for (int i = 0; i < x; i++) {
                E[i] = in[i] = key[i];
            }

            int v = x;
            for (char i = 'A'; i <= 'Z'; i++) {
                int c = 0;
                for (int j = 0; j < x; j++) {
                    if (i == in[j]) {
                        c++;
                    }
                }

                if (c == 0) {
                    E[v] = i;
                    v++;
                }
            }

            cout << "\n";
            // for (int i = 0; i < 26; i++) {
            //     cout << E[i];
            // }
            cout << "\n\n";


            // Convert input to uppercase
            transform(s1.begin(), s1.end(), s1.begin(), ::toupper);

            char s2[100];
            int vk = s1.length();

            for (int i = 0; i < vk; i++) {
                if (isalpha(s1[i])) {
                    for (int j = 0; j < 26; j++) {
                        if (s1[i] == S[j]) {
                            s2[i] = E[j];
                            break;
                        }
                    }
                } else {
                    s2[i] = s1[i]; // Copy non-alphabetic characters as is
                }
            }

          
         return s2;
    }
};


// TIME COMPLEXITY: O(n^2)
// SPACE COMPLEXITY: O(n)

// Input: Vatsal Output: VCTSCJ


int main() {
    int choice;
    string text;
    string k;

    cout << "Choose a cipher:" << endl;
    cout << "1. Caesar Cipher" << endl;
    cout << "2. Atbash Cipher" << endl;
    cout << "3. Keyword Cipher" << endl;
    cout << "4. Exit" << endl;

    
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter text for Caesar Cipher: ";
                cin.ignore();
                getline(cin, text);
                cout << "Enter the Key: ";
                cin >> k;
                text = CaesarCipher().Caesar(text, stoi(k));
                cout << "Answer: "<< text << endl;
                break;
            case 2:
                cout << "Enter text for Atbash Cipher: ";
                cin.ignore();
                getline(cin, text);
                AtbashCipher().encryptDecrypt(text);
                cout << "Encrypted/Decrypted text: " << text << endl;
                break;
            case 3:
                cout << "Enter the keyword: ";
                cin.ignore();
                getline(cin, k);
                cout << "Enter data: ";
                cin >> text;
                text = KeywordCipher().KcEncrypt(k, text);
                cout << "Answer: "<< text << endl;
                
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

   

    return 0;
}
