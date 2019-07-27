#include "conversions.h"
#include "mapping.h"
#include "split.h"

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>

using std::string;
using std::vector;

string toBase10Core(const string &str, const int fromBase);
string fromBase10Core(const string &str, const int toBase);
vector<string> split(const string &str);

string BaseConversions::toBase10(const string &str, const int fromBase) {
    if(fromBase < 2) {
        std::cerr << "Invalid base" << std::endl;
        std::exit(0);
    } else if(fromBase == 10) {
        return str;
    }

    int counter = 0;
    string result;
    vector<string> words = split(str);
    
    for(string word : words) {
        if(++counter != 1)
            result += " ";
        result += toBase10Core(word, fromBase);
    }

    return result;
}

string BaseConversions::fromBase10(const string &str, const int toBase) {
    if(toBase < 2) {
        std::cerr << "Invalid base" << std::endl;
        std::exit(0);
    } else if(toBase == 10) {
        return str;
    }

    int counter = 0;
    string result;
    vector<string> words = split(str);
    
    for(string word : words) {
        if(++counter != 1)
            result += " ";
        result += fromBase10Core(word, toBase);
    }

    return result;
}

inline string BaseConversions::changeBase(const string &str, const int fromBase, const int toBase) {
    return fromBase10(toBase10(str, fromBase), toBase);
}

//use dictionary instead?
inline string bin2hex(const string &bin) {
    return BaseConversions::changeBase(bin, 2, 16);
}

inline string bin2dec(const string &bin) {
    return BaseConversions::changeBase(bin, 2, 10);
}

inline string dec2bin(const string &dec) {
    return BaseConversions::changeBase(dec, 10, 2);
}

inline string dec2hex(const string &dec) {
    return BaseConversions::changeBase(dec, 10, 16);
}

//use dictionary instead?
inline string hex2bin(const string &hex) {
    return BaseConversions::changeBase(hex, 16, 2);
}

inline string hex2dec(const string &hex) {
    return BaseConversions::changeBase(hex, 16, 10);
}

