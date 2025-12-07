#include <iostream>
#include <queue>

class SmallestInfiniteSet {
	private:
		int	smallestAvailable;
		void	CleanUpDetached(int top);
		std::priority_queue<int, std::vector<int>, std::greater<int>>	detachedNumbers;
	public:
		SmallestInfiniteSet()
		{
			smallestAvailable = 1;
		}
		
		int popSmallest()
		{
			int temp;

			CleanUpDetached(smallestAvailable);
			if (detachedNumbers.empty() || detachedNumbers.top() > smallestAvailable)
			{
				smallestAvailable++;
				return smallestAvailable - 1;
			}
			temp = detachedNumbers.top();
			CleanUpDetached(temp);
			return temp;
		}
		
		void addBack(int num)
		{
			if (num >= smallestAvailable)
				return ;
			if (num == (smallestAvailable - 1))
				smallestAvailable--;
			else
				detachedNumbers.push(num);
		}
};

void	SmallestInfiniteSet::CleanUpDetached(int top)
{
	while (!detachedNumbers.empty() && (detachedNumbers.top() == top))
		detachedNumbers.pop();
}


int	main()
{
	SmallestInfiniteSet	smallSet;

	std::cout << smallSet.popSmallest() << std::endl;
	std::cout << smallSet.popSmallest() << std::endl;
	smallSet.addBack(1);
	smallSet.addBack(2);
	smallSet.addBack(1);
	std::cout << smallSet.popSmallest() << std::endl;
	std::cout << smallSet.popSmallest() << std::endl;
	std::cout << smallSet.popSmallest() << std::endl;
	return (0);
}

// ["SmallestInfiniteSet","popSmallest","popSmallest","addBack","addBack","addBack","popSmallest","popSmallest","popSmallest"]