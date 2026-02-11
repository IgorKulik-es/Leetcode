#include <iostream>
#include <stack>

class StockSpanner
{
	private:
		std::stack<std::pair<int, int>>	peaks;
	public:
		StockSpanner();
		int next(int price);
};

StockSpanner::StockSpanner(): peaks(){};

int	StockSpanner::next(int price)
{
	int	span = 1;

	while (!peaks.empty() && peaks.top().first <= price)
	{
		span +=peaks.top().second;
		peaks.pop();
	}
	peaks.push(std::pair<int, int>(price, span));
	return span;
}

int main()
{
	{
		StockSpanner	spanner;
		std::cout << spanner.next(100) << spanner.next(80) << spanner.next(60)
			<< spanner.next(70) << spanner.next(60) << spanner.next(75) << spanner.next(85) << std::endl;
	}
	{
		StockSpanner	spanner;
		std::cout << spanner.next(7) << spanner.next(34) << spanner.next(1) << spanner.next(2) << spanner.next(8) << std::endl;
	}
	return 0;
}