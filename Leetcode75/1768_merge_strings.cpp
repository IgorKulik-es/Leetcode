#include <iostream>
#include <string>

class Solution {
public:
	std::string mergeAlternately(std::string word1, std::string word2)
	{
		std::string				result;
		std::string::iterator	iter1 = word1.begin();
		std::string::iterator	iter2 = word2.begin();
		std::string::iterator	end1 = word1.end();
		std::string::iterator	end2 = word2.end();


		while (iter1 != end1)
		{
			result.push_back(*iter1);
			iter1++;
			if (iter2 != end2)
				result.push_back(*iter2);
			else
				return (result.append(iter1.base()));
			iter2++;
		}
		return (result.append(iter2.base()));
	}
};

int	main(int argc, char** argv)
{
	Solution	solve;

	if (argc >= 3)
		std::cout << solve.mergeAlternately(argv[1], argv[2]) << std::endl;
	return (0);
}