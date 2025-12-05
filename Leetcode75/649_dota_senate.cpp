#include <iostream>
#include <queue>

class Solution {
public:
	std::string predictPartyVictory(std::string senate)
	{
		std::queue<char>		speakingQueue;
		std::string::iterator	iter;
		int						voter;
		int						numSenators[2] = {0, 0};
		int						votesCount[2] = {0, 0};

		for (iter = senate.begin(); iter != senate.end(); iter++)
		{
			speakingQueue.push(*iter == 'D');
			if (*iter == 'R')
				numSenators[0]++;
			else
				numSenators[1]++;
		}
		while (numSenators[0] && numSenators[1])
		{
			voter = speakingQueue.front();
			if (votesCount[voter] == 0)
			{
				speakingQueue.push(voter);
				votesCount[(voter ^ 1)]++;
			}
			else
			{
				votesCount[voter]--;
				numSenators[voter]--;
			}
			speakingQueue.pop();
		}
		if (numSenators[0])
			return "Radiant";
		else
			return "Dire";
	}
};

int	main(int argc, char** argv)
{
	Solution	solve;

	std::string	s = std::string("RDDR");
	std::cout << solve.predictPartyVictory(s) << std::endl;
	return (0);
}