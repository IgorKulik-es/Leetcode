#include <string>
#include <deque>
#include <iostream>

class Solution
{
	private:
		void	multiplyString(std::pair<std::string, int>& stringItem);
	public:
		std::string	decodeString(std::string s);
};

std::string	Solution::decodeString(std::string s)
{
	std::deque<std::pair<std::string, int>>				dequeDecode;
	std::deque<std::pair<std::string, int>>::iterator	iterDeque;
	std::string::iterator								iterString = s.begin();
	int													substringLength;

	dequeDecode.push_back(std::pair<std::string, int>("", 1));
	for (;iterString != s.end();iterString++)
	{
		if (isalpha(*iterString))
			dequeDecode.back().first += *iterString;
		else if (isdigit(*iterString))
		{
			substringLength = 0;
			for (;isdigit(*iterString);iterString++)
				substringLength = substringLength * 10 + (*iterString - '0');
			dequeDecode.push_back(std::pair<std::string, int>("", substringLength));
		}
		else
		{
			multiplyString(dequeDecode.back());
			iterDeque = dequeDecode.end();
			std::advance(iterDeque, -2);
			(*iterDeque).first += dequeDecode.back().first;
			dequeDecode.pop_back();
		}
	}
	return	std::string(dequeDecode.back().first);
}

void	Solution::multiplyString(std::pair<std::string, int>& stringItem)
{
	stringItem.first.reserve(stringItem.second * stringItem.first.size());
	std::string::iterator	start = stringItem.first.begin();
	std::string::iterator	end = stringItem.first.end();

	for (int i = 1; i < stringItem.second; i++)
		stringItem.first.append(start, end);
}

int	main()
{
	Solution	solve;

	{
		std::string	s("3[a]2[bc]");
		std::cout << solve.decodeString(s) << std::endl;
	}
	{
		std::string	s("3[a2[c]]");
		std::cout << solve.decodeString(s) << std::endl;
	}
	{
		std::string	s("2[abc]3[cd]ef");
		std::cout << solve.decodeString(s) << std::endl;
	}
	{
		std::string	s("10[a]");
		std::cout << solve.decodeString(s) << std::endl;
	}
	{
		std::string	s("a");
		std::cout << solve.decodeString(s) << std::endl;
	}
	return (0);
}