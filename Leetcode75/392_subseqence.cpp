#include <iostream>
#include <string>
#include <cstring>
#include <string.h>

class Solution {
public:
	bool isSubsequence(std::string t, std::string s)
	{
		char*	iter1 = s.begin().base();
		char*	iter2 = t.begin().base();

		for (; *iter2; iter2++)
		{
			iter1 = strchr(iter1, *iter2);
			if (iter1 == NULL)
				return false;
			iter1++;
		}
		return true;
	}
};

int	main(int argc, char** argv)
{
	Solution	solve;

	std::string	str1 = std::string("AZ");
	std::string	str2 = std::string("ABCZ");
	std::cout << solve.isSubsequence(str1, str2) << std::endl;
	return (0);
}