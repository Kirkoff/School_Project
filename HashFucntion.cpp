//
//  HashFucntion.cpp
//  Rolling Hash
//
#pragma once
#include "HashFucntion.hpp"

int get_hash(std::string s, std::map<char, int> values, int MOD, int prime_number){
    long long hash = 0;
    for(auto symbol : s){
        hash *= prime_number;
        hash += values[symbol];
        hash %= MOD;
    }
    return int(hash);
}
