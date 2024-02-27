#include <iostream>
#include <string>
using namespace std;

// Функция, которая разворачивает слово
void reverse_word(string& word) 
{
    int left = 0; 
    int right = word.size() - 1; 
    while (left < right) 
    { 
        swap(word[left], word[right]); 
        left++; 
        right--; 
    }
}

// Функция, которая преобразует строку
string trans_string(const string& s) 
{
    string result;
    string word; 
    for (char c : s) 
    { 
        if (c == ' ') 
        { 
            reverse_word(word); 
            result += word + " "; 
            word = ""; 
        }
        else 
        { 
            word += c; 
        }
    }
    reverse_word(word); 
    result += word; 
    return result; 
}

int main() 
{
    
    string s = "Mom and dad are parents";
    
    string t = trans_string(s);
    
    cout << t << endl;

    return 0;
}
