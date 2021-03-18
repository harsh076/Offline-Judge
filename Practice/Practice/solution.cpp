#include "solution.h"
#include <bits/stdc++.h>

//correct solution source code goes here
void Solution::Solve()
{
	freopen("solution_output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);

	int i;
	std::cin >> i;
	while (i != 42)
	{
		std::cout << i << "\n";
		std::cin >> i;
	}
}
