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

double getMedian(std::vector<double> vec){
	if(vec.empty()){
		return 0;
	}

	size_t size = vec.size();
	std::sort(vec.begin(), vec.end());
	if(size % 2 == 0){
		return (vec[size / 2 - 1] + vec[size / 2]) / 2;
	}
	else{
		return vec[size / 2];
	}
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
	std::cout << "mean: " << mean << std::endl;
	max = getMax(vec);
	std::cout << "max: " << max << std::endl;
	min = getMin(vec);
	std::cout << "min: " << min << std::endl;
	median = getMedian(vec);
	std::cout << "median: " << median << std::endl;
	return 0;
}
	

