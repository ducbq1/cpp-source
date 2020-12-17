
// C++ code for calculating number of ways 
// to distribute m mangoes amongst n people 
// where all mangoes and people are identical 
#include <bits/stdc++.h> 
using namespace std; 

// function used to generate binomial coefficient 
// time complexity O(m) 
int binomial_coefficient(long long n, long long m) 
{ 
	long long res = 1; 

	if (m > n - m) 
		m = n - m; 

	for (int i = 0; i < m; ++i) { 
		res *= (n - i); 
		res /= (i + 1); 
	} 

	return res; 
} 

// helper function for generating no of ways 
// to distribute m mangoes amongst n people 
long long calculate_ways(long long m, long long n) 
{ 
	// not enough mangoes to be distributed 
	if (m < n) 
		return 0; 
	
	// ways -> (n+m-1)C(n-1)
  long long ways = binomial_coefficient(m - 1, n - 1);
	// long long ways = binomial_coefficient(n + m - 1, n - 1); 
	return ways; 
} 

// Driver function 
int main() 
{ 
	// m represents number of mangoes 
	// n represents number of people 
	long long m, n;
  cin >> m >> n;

	long long result = calculate_ways(m, n); 
	printf("%lld\n", result % 1000000007); 

	return 0; 
} 
