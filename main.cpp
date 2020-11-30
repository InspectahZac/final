#include <iostream>

#include <vector>
#include <queue>
#include <stack> 
#include <string> 

#include <fstream> 

// This function opens a file and copies its contents to a vector
void init_temps(std::vector<int> &v, std::string filename) {
	std::ifstream infile(filename);
	if (infile.is_open()) {
		int temp;
		while (infile >> temp) {
			v.push_back(temp);
		}
		infile.close();
	}
}

// Print functions
template <typename T>
void print_vector(const std::vector<T> &v) {
	for (const auto &i : v) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

template <typename Q>
void print_queue(std::queue<Q> q) {
	while(!q.empty()) {
		std::cout << q.front() << ' ';
		q.pop();
	}
	std::cout << '\n';
}

template <typename S>
void print_stack(std::stack<S> s) {
	while(!s.empty()) {
		std::cout << s.top() << ' ';
		s.pop();
	}
	std::cout << '\n';
}

int main() {
	std::string filename("temperature_data.txt");

	// A vector containing temperatures
	std::vector<int> temps;
	init_temps(temps, filename);

	// Start here

	return 0;
}
