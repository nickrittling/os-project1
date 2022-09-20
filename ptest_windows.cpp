#include <iostream>
#include <Windows.h>
#include <chrono>
#include <iomanip>



int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);

    int id = GetCurrentProcessId();

    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    std::cout << "Time taken by program is : " << std::fixed << time_taken
        << std::setprecision(9) << " sec\n";

	
	//std::cout << id << std::endl;
	return 0;
}
