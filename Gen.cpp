//
//  Gen.cpp
//  Rolling Hash
//
#pragma once
#include "Gen.hpp"
#include <random>
#include <chrono>

//Собственная функция рандома
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
long long myRand(long long B) {
    return (unsigned long long)rng() % B;
}

std::string generate_string(int length, unsigned long long seed){
    std::string cur_string = "";
    for(int i = 0; i < length; ++i){
        cur_string += char(97 + (myRand(seed) % 26)); //Добавление к строке рандомного символа
    }
    return cur_string;
}
