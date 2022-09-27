#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include <string>
#include <algorithm>

double getMean (std::vector<double> const& vec){
	if(vec.empty()){
		return 0;
	}

	auto const count = static_cast<double>(vec.size());
	return std::reduce(vec.begin(), vec.end()) / count;
}


double getMax (std::vector<double> const& vec){
	if(vec.empty()){
		return 0;
	}

	return *std::max_element(vec.begin(), vec.end());
}

double getMin(std::vector<double> const& vec){
	if(vec.empty()){
		return 0;
	}

	return *std::min_element(vec.begin(), vec.end());
}







int main(){
	std::vector<double> vec;
	std::string fname;
	std::string line;
	double mean = 0, median = 0, max = 0, min = 0;
	std::cout << "Enter output file name\n";
	std::cin >> fname;
	std::ifstream infile(fname);
	if(infile.is_open()){
		while(getline(infile, line)){
			vec.push_back(std::stod(line));
		}//end while
		infile.close();		
	}//end if 
	
	mean = getMean(vec);
	std::cout << mean << std::endl;
	max = getMax(vec);
	std::cout << "max: " << max << std::endl;
	min = getMin(vec);
	std::cout << "min: " << min << std::endl;
	return 0;
}
	

