#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <cstdio>
#include <chrono>
int main(){
	auto start = std::chrono::high_resolution_clock::now();
	std::ios_base::sync_with_stdio(false);
	
	for(int i = 0; i < 50; i++)
	{
		int id = getpid();
	}

	auto end = std::chrono::high_resolution_clock::now();
	double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	std::cout<<"Time taken by program is : " << std::fixed << time_taken
		<< std::setprecision(9) << " sec\n";
	return 0;
}
