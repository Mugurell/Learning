#include <iostream>
#include <vector>
#include <string>

using std::vector;	//push_back is a vector member


int main()
{
	vector<int> vi;		// empty vector which can hold int objects

	for(int x = 0; x < 10; ++x) 
		vi.push_back(x);
	for(auto i : vi)
		std::cout << '\t' << i << std::endl;



	std::cout << "\nNow say a few words if you may.." << std::endl;

	vector<std::string>st;	//st is an empty container for strings
	std::string word;

	while (std::cin >> word) {
		if (word == "stop")
			break;
		else
			st.push_back(word);
	}

	std::cout << "So you've said.." << std::endl;
	for(auto each_word : st)
		std::cout << each_word << ' ';
	std::cout << std::endl;
	
	std::cout << "\nSecond word is " << st[1] << std::endl;



	return 0;
}