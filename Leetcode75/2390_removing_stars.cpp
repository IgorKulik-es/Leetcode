#include <stack>
#include <iostream>

class Solution {
public:
	std::string removeStars(std::string s)
	{
		char	result[s.size() + 1];
		int		lastLetter = 1;
		std::string::iterator	iter;
		std::string::iterator	end;

		iter = s.begin();
		end = s.end();
		result[0] = *iter;
		iter++;
		while (iter != end)
		{
			if (*iter == '*')
				lastLetter--;
			else
			{
				result[lastLetter] = *iter;
				lastLetter++;
			}
			iter++;
		}
		result[lastLetter] = '\0';
		return std::string(result);
	}
};

int	main(int argc, char** argv)
{
	Solution	solve;

	std::string	s = std::string("era*sez*z****sss");
	std::cout << solve.removeStars(s) << std::endl;
	return (0);
}