//
//  Test_for_collisions.cpp
//  Rolling Hash
//
#pragma once
#include <unordered_set>
#include "Test_for_collisions.h"
#include "Gen.h"
#include "HashFunction.h"

void count_collisions(std::map<char, int> values, int MOD, int prime_number, int& result) {
    int cnt = 0;
    std::unordered_multiset<int> hashes;
    for (int i = 0; i < 1e6; ++i) {
        //сгенерировать строку
        std::string cur_s = generate_string(10, 1e9 + 7); //1e9 + 7 рандомный seed
        //посчитать хэш-функцию
        int cur_hash = get_hash(cur_s, values, MOD, prime_number);
        //проверить на коллизию
        if (hashes.find(cur_hash) == hashes.end()) {
            hashes.insert(cur_hash);
        }
        else {
            cnt += hashes.count(cur_hash);
            hashes.insert(cur_hash);
        }
    }
    result = cnt;
    return;
}
