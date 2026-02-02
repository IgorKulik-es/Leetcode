#include <iostream>
#include <deque>
#include <algorithm>

class RecentCounter
{
	private:
		std::deque<int>	calls;
		int				oldestCall;
	public:
		RecentCounter();
		int	ping(int t);
};

RecentCounter::RecentCounter(): calls(0), oldestCall(0){};

int	RecentCounter::ping(int t)
{
	std::deque<int>::iterator	find;
	calls.push_back(t);
	find = std::lower_bound(calls.begin() + oldestCall, calls.end(), t - 3000);
	oldestCall = std::distance(find, calls.begin());
	return std::distance(find, calls.end());
}

int	main()
{
	{
		RecentCounter	callCenter;

		std::cout << callCenter.ping(1) << " " << callCenter.ping(100) << " "
			<< callCenter.ping(3001) << " " << callCenter.ping(3002) << std::endl;
	}
	{
		RecentCounter	callCenter;

		std::cout << callCenter.ping(1) << " " << callCenter.ping(3002) << " "
			<< callCenter.ping(6003) << std::endl;
	}
	{
		RecentCounter	callCenter;

		for (int i = 0; i < 1000; i++)
			std::cout << callCenter.ping(i * 30) << " i: " << i << " ";
		std::cout << std::endl;
	}
}
