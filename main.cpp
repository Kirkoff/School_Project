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
#include "HashFucntion.hpp"
#include "Gen.hpp"
#include "Get_primes.hpp"
#include "Test_for_collisions.hpp"
#include <thread>
//using namespace std;

#pragma GCC target("sse, sse2, sse3, ssse3, sse4, popcnt, abm, mmx, avx, avx2, tune=native")
//#pragma GCC optimize("O3")


template<class T>
std::ostream& operator << (std::ostream& out, std::vector<T>& a) {
    for (auto i : a) {
        out << i << " ";
    }
    return out;
}

/*std::mt19937_64 rnG(std::chrono::steady_clock::now().time_since_epoch().count());
long long myRand(long long B) {
    return (unsigned long long)rnG() % B;
}*/

//std::ofstream big_out("all_primes_big.txt");
//std::ofstream small_out("all_primes_small.txt");
std::ifstream big_in("all_primes_big.txt");
std::ifstream small_in("all_primes_small.txt");
std::ofstream answers_big("Big_Answers.txt");
std::ofstream answers_small("Small_Answers.txt");
int main(int argc, const char * argv[]) {
    //freopen("output.txt", "w", stdout);
    std::map<char, int> values;
    for(char i = 'a'; i <= 'z'; ++i){
        values[i] = int(i) - 97;
    }
    /*std::vector<int> all_primes;
    all_primes = get_primes(1 << 30);
    std::cout << "Get finished" << std::endl;
    for(auto i : all_primes){
        small_out << i << " ";
    }
    std::reverse(all_primes.begin(), all_primes.end());
    for(auto i : all_primes){
        big_out << i << " ";
    }*/
    std::vector<int> small_primes;
    std::vector<int> big_primes;
    for(int i = 0; i < 1000000; ++i){
        int x;
        small_in >> x;
        small_primes.push_back(x);
    }
    for(int i = 0; i < 1000000; ++i){
        int x;
        big_in >> x;
        big_primes.push_back(x);
    }
    //std::cout << small_primes[0];
    /*
    for(auto i : small_primes){
        std::cout << i << " ";
    }
    std::cout << "\nABAB\n";
    for(auto i : big_primes){
        std::cout << i << " ";
    }*/
    //answers << "MOD = ... Prime = ... Collisions = ..."
    
    
    
    //random big test
    for(int _ = 0; _ < 1000; ++_){
        int i = (abs((rand() << 15) + rand())) % (999999);
        int j = (abs((rand() << 15) + rand())) % (999999);
        answers_big << big_primes[i] << " ";
        answers_big << small_primes[j] << " ";
        answers_big << count_collisions(values, big_primes[i], small_primes[j]) << std::endl;
    }
    
    //check for small
    for(int _ = 0; _ < 1000; ++_){
        int i = (abs((rand() << 15) + rand())) % (100);
        int j = (abs((rand() << 15) + rand())) % (100);
        answers_small << big_primes[i] << " ";
        answers_small << small_primes[j] << " ";
        answers_small << count_collisions(values, big_primes[i], small_primes[j]) << std::endl;
    }
    return 0;
}
