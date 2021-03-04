//
//  Get_primes.cpp
//  Rolling Hash
//

#include "Get_primes.h"
std::vector<int> get_primes(int n) {
    //Решето Эратосфена
    std::vector<bool> nums(n + 1, 1);
    std::vector<int> primes;
    for (int i = 2; i < n; ++i) {
        if (nums[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= n; j += i) {
                nums[j] = 0;
            }
        }
    }
    return primes;
}
