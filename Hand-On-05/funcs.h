#ifndef FUNCS_H
#define FUNCS_H

#include <string>
#include <vector>

using namespace std;

// Count distinct characters in a string
int countDistinct(string str);

// Function to find the index of the first occurrence of p in t
int indexOf(char p[], char t[]);

// Boyer-Moore-Horspool algorithm
bool Boyer_Moore_Horspool(char P[], char T[]);

// Z algorithm
void z_algo(const char *s, int *z);

// Longest common subsequence (LCS) function
int lcs_func(vector<vector<int>>& L, const char* A, const char* B);

#endif // FUNCS_H
