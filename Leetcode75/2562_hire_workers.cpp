#include <iostream>
#include <vector>
#include <queue>

typedef std::priority_queue<int, std::vector<int>, std::greater<int>>	WorkerQueue;

class Solution
{
	private:
		WorkerQueue	queueLower;
		WorkerQueue	queueUpper;
		int			boundLower;
		int			boundUpper;
		bool		isCandidateAvailable = true;

		int	takeFromQueue(std::vector<int>& costs, WorkerQueue& queue, int& bound, int increment);
		bool	isLowerQueueBetter();
	public:
		long long	totalCost(std::vector<int>& costs, int k, int candidates);
};

long long	Solution::totalCost(std::vector<int>& costs, int k, int candidates)
{
	long long	result = 0;

	boundLower = candidates;
	boundUpper = costs.size() - candidates - 1;
	isCandidateAvailable = (boundLower <= boundUpper);
	if (!isCandidateAvailable)
		boundUpper = boundLower - 1;
	queueLower = WorkerQueue(costs.begin(), costs.begin() + boundLower);
	if (costs.size() > (size_t)candidates)
		queueUpper = WorkerQueue(costs.begin() + boundUpper + 1, costs.end());
	for (int i = 0; i < k; i++)
	{
		if (isLowerQueueBetter())
			result += takeFromQueue(costs, queueLower, boundLower, 1);
		else
			result += takeFromQueue(costs, queueUpper, boundUpper, -1);
	}
	return result;
}

int	Solution::takeFromQueue(std::vector<int>& costs, WorkerQueue& queue, int& bound, int increment)
{
	int	result = queue.top();
	queue.pop();
	if (isCandidateAvailable)
	{
		queue.emplace(costs[bound]);
		bound += increment;
	}
	if (boundLower > boundUpper)
		isCandidateAvailable = false;
	return result;
}

bool	Solution::isLowerQueueBetter()
{
	if (queueLower.empty())
		return false;
	if (queueUpper.empty())
		return true;
	return (queueLower.top() <= queueUpper.top());
}

int	main()
{
	{
		Solution	solve;
		std::vector<int>	vec({17,12,10,2,7,2,11,20,8});
		std::cout << solve.totalCost(vec, 3, 4) << std::endl;
	}
	{
		Solution	solve;
		std::vector<int>	vec({1,2,4,1});
		std::cout << solve.totalCost(vec, 3, 3) << std::endl;
	}
	{
		Solution	solve;

		std::vector<int>	vec({1,2,4,5});

		std::cout << solve.totalCost(vec, 4, 2) << std::endl;
	}
	{
		Solution	solve;
		std::vector<int>	vec({1});
		std::cout << solve.totalCost(vec, 1, 1) << std::endl;
	}
	{
		Solution	solve;
		std::vector<int>	vec({1,5,5,1,3,3});
		std::cout << solve.totalCost(vec, 3, 2) << std::endl;
	}

	return (0);
}