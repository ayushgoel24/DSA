#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
#define modulo 1000000007

long long findFactorial(long long n) {
	if (n == 1 || n == 0) return 1;
	return ( findFactorial(n - 1) * n ) % modulo;
}

int getInfectionSequence(vector<int>& infectedHouses, int n) {
	queue< pair<long long, long long> > houseQueue; 
	long long maximum = 1;
	vector<int> infectedVector(n + 1);
	map<long long, long long> mapping;

	for(auto house : infectedHouses){
		houseQueue.push( {house, 0} );
		infectedVector[house] = 2;
	}

	while(!houseQueue.empty()) {
		pair<long long, long long> p = houseQueue.front();
		houseQueue.pop();

		long long houseLeftIndex = p.first - 1;
		long long houseRightIndex = p.first + 1;

		if(infectedVector[houseLeftIndex] != 2 && houseLeftIndex > 0)
		{
			infectedVector[houseLeftIndex] = 2;
			if (mapping.find(p.second + 1) == mapping.end() ) {
			    mapping[p.second + 1] = 1;
			} else {
			    mapping[p.second + 1] += 1;
			}
			houseQueue.push({houseLeftIndex, p.second + 1});
		}
		if(infectedVector[houseRightIndex] != 2 && houseRightIndex <= n)
		{
			infectedVector[houseRightIndex] = 2;
			if (mapping.find(p.second + 1) == mapping.end() ) {
			    mapping[p.second + 1] = 1;
			} else {
			    mapping[p.second + 1] += 1;
			}
			houseQueue.push({houseRightIndex, p.second + 1});
		}
	}

	for(auto p : mapping)
	{
		long long res = findFactorial(p.second);
		maximum *= res;
	}
	return maximum;
}


int main() {
    std::cout << "Hello World!\n";
    int n = 6;
    vector<int> infectedHouses = {3, 5};
    int res = getInfectionSequence(infectedHouses, n);
    std::cout << res << std::endl;
    
    n = 5; 
    infectedHouses = {1, 5};
    res = getInfectionSequence(infectedHouses, n);
    std::cout << res << std::endl;
    
    n = 7;
    infectedHouses = {4};
    res = getInfectionSequence(infectedHouses, n);
    std::cout << res << std::endl;
    
}