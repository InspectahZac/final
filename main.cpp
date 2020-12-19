#include <iostream>
#include <vector>
#include <queue>
#include <stack> 
#include <string> 
#include <bits/stdc++.h> //for min and max element
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
	//print_vector(temps);
	
	//Copy temps into a queue
	std::queue<int, std::deque<int>> q(std::deque<int>(temps.begin(), temps.end()));

	//print_queue(q);

	//create stacks for groups a and b
	std::stack<int> group_a;
	std::stack<int> group_b;

	//sort the queue into the two stacks
	//above 99 goes into a and below or equals goes into b
while (!q.empty()) 	{
	if (q.front() > 99) 	{
	group_a.push(q.front());
	q.pop();
				}
	else			{
	group_b.push(q.front());
        q.pop();
				}
			}
	//print the sizes of groups a and b using the size command
	std::cout << "The size of group A is " << group_a.size() << std::endl;
	std::cout << "The size of group B is " << group_b.size() << std::endl;
	
	//print the min and max values using the min and max element commands
	std::cout << "The lowest temperature is " << *min_element(temps.begin(), temps.end()) << std::endl;
	std::cout << "The highest temperature is " << *max_element(temps.begin(), temps.end()) << std::endl;

	//print the average of all values using the original vector
        float average_all = accumulate(temps.begin(), temps.end(), 0.0)/temps.size();
        std::cout << "The average of all temperatures is " << average_all << std::endl;

	//copy group a and add all values together in float total_a
        std::stack<int> average_a(group_a);
        float total_a = 0;
	while(!average_a.empty())
        {
        total_a = total_a + average_a.top();
        average_a.pop();
        }       
	//print by dividing the total_a by the size command
        std::cout << "The average temperature of group A is " << total_a/group_a.size() << std::endl;
		
	//copy group b and add all values together in float total_b
	std::stack<int> average_b(group_b);
        float total_b = 0;
        while(!average_b.empty())
        {
        total_b = total_b + average_b.top();
        average_b.pop();
        }
	//print by dividing the total_b by the size command
        std::cout << "The average temperature of group B is " << total_b/group_b.size() << std::endl;

	return 0;
}
