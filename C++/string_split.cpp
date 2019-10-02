// A useful function that returns a vector of strings by tokenizing input string by some delimiter (default is space)
#include <bits/stdc++.h>

std::vector<std::string> string_split(const std::string &s, const string &delimiter=" "){
    std::vector<std::string> tokens;
    std::string token;
    size_t pos = 0, prev = 0, delim_length = delimiter.length();
    while ((pos = s.find(delimiter, pos)) != std::string::npos){
        token = s.substr(prev, pos - prev);
        if(!token.empty()){
            tokens.push_back(token);
        }
        prev = pos += delim_length;
    }
    tokens.push_back(s.substr(prev, pos));
    return tokens;
}


