#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
	int N;
	std::cin >> N;
	std::vector<int> v(N);
	std::vector<int> dist(N - 1);

	for (int i = 0; i < N; i++)
		std::cin >> v[i];

	for (int i = 1; i < v.size(); i++)
		dist[i - 1] = v[i] - v[i - 1];

	int gcd = accumulate(dist.begin(), dist.end(), dist[0], std::gcd<int, int>);

	std::cout << (v.back() - v.front()) / gcd - (N - 1);
}