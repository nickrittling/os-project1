#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <cstdio>
#include <chrono>
#include <fstream>
int main(){
	std::ofstream myfile("pidresult.txt");
	if(myfile.is_open()){
		for(int j = 0; j < 1000; j++){

			auto start = std::chrono::high_resolution_clock::now();
			std::ios_base::sync_with_stdio(false);
	
			for(int i = 0; i < 100000; i++)
			{
				int id = getpid();
			}

			auto end = std::chrono::high_resolution_clock::now();
			double time_taken = std::chrono::duration_cast<std::
				chrono::nanoseconds>(end - start).count();

			time_taken *= 1e-9;
			myfile << std::setprecision(9) << time_taken << std::endl;
	}

		myfile.close();

	}
	return 0;
}
