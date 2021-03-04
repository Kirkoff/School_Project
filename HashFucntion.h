//
//  HashFunction.h
//  Rolling Hash
//
#pragma once
#ifndef HashFunction_h
#define HashFunction_h
#include <stdio.h>
#endif /* HashFunction_h */
#include <string>
#include <map>
int get_hash(std::string s, std::map<char, int>, int MOD, int prime_number);
