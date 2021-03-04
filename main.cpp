//@author: Kirkon

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include "HashFunction.h"
#include "Gen.h"
#include "Get_primes.h"
#include "Test_for_collisions.h"
#include <thread>
//using namespace std;

#pragma GCC target("sse, sse2, sse3, ssse3, sse4, popcnt, abm, mmx, avx, avx2, tune=native")
#pragma GCC optimize("O3")

const int num_of_threads = 6;


template<class T>
std::ostream& operator << (std::ostream& out, std::vector<T>& a) {
    for (auto i : a) {
        out << i << " ";
    }
    return out;
}

std::ifstream big_in("all_primes_big.txt");
std::ifstream small_in("all_primes_small.txt");
std::ofstream answers_big("Big_Answers.txt");
std::ofstream answers_small("Small_Answers.txt");
int main(int argc, const char* argv[]) {
    //freopen("output.txt", "w", stdout);
    std::map<char, int> values;
    for (char i = 'a'; i <= 'z'; ++i) {
        values[i] = int(i) - 97;
    }
    std::vector<int> small_primes;
    std::vector<int> big_primes;
    for (int i = 0; i < 1000000; ++i) {
        int x;
        small_in >> x;
        small_primes.push_back(x);
    }
    for (int i = 0; i < 1000000; ++i) {
        int x;
        big_in >> x;
        big_primes.push_back(x);
    }
    
    //answers << "MOD = ... Prime = ... Collisions = ..."

    //big test
    for (int _ = 0; _ < 500; ++_) {
        clock_t start = clock();
        std::vector<std::vector<int>> ans(num_of_threads, std::vector<int>(3));
        std::vector<std::thread> threads;
        for (int __ = 0; __ < num_of_threads; ++__) {
            int rand1 = myRand(999999);
            int rand2 = myRand(999999);
            ans[__][0] = big_primes[rand1];
            ans[__][1] = small_primes[rand2];
            threads.push_back(std::thread(count_collisions, values, big_primes[rand1], small_primes[rand2], std::ref(ans[__][2])));
        }
        for (auto& cur_thread : threads) {
            cur_thread.join();
        }
        for (std::vector<int> result : ans) {
            answers_big << result << std::endl;
        }
        
        clock_t end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        printf("The time: %f seconds\n", seconds);
    }

    //check for small
    for (int _ = 0; _ < 500; ++_) {
        clock_t start = clock();
        std::vector<std::vector<int>> ans(num_of_threads, std::vector<int>(3));
        std::vector<std::thread> threads;
        for (int __ = 0; __ < num_of_threads; ++__) {
            int rand1 = myRand(1000);
            int rand2 = myRand(1000);
            ans[__][0] = big_primes[rand1];
            ans[__][1] = small_primes[rand2];
            threads.push_back(std::thread(count_collisions, values, big_primes[rand1], small_primes[rand2], std::ref(ans[__][2])));
        }
        for (auto& cur_thread : threads) {
            cur_thread.join();
        }
        for (std::vector<int> result : ans) {
            answers_small << result << std::endl;
        }
        
        clock_t end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        printf("The time: %f seconds\n", seconds);
    }
    return 0;
}
