#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

class MyModule
{
public:
	static int abs(int n)
	{
		if (n < 0)
			return -n;
		else
			return n;
	}

	// factorial 계산
	static int factorial(int x)
	{
		std::function<int(int, int)> Go = [&Go](int n, int acc) -> int
		{
			if (n <= 0) return acc;
			else return Go(n - 1, n*acc);
		};

		return Go(x, 1);
	}

	// 피보나치
	// 0 1 1 2 3 5 ...
	static int Fibonacci(int n)
	{
		if (n < 0)
			return -1;
		class c
		{
		public:
			int operator() (int n1, int n2, int cnt, int end)
			{
				if (cnt == end)
					return n1;

				c a2;
				return a2(n2, n1 + n2, cnt + 1, end);
			}
		};
		std::function<int(int, int, int, int)> Go = [&Go](int n1, int n2, int cnt, int end) -> int
		{
			if (cnt == end)
				return n1;

			return Go(n2, n1 + n2, cnt + 1, end);
		};

		//return Go(0, 1, 1, n);
		c a2;
		return a2(0, 1, 1, n);
	}

private:
	static std::string format(std::string name, const int n, int(*func)(int n))
	{
		const char* msg = "The %s of %dth is %d.\n";
		char buf[100];
		sprintf_s(buf, msg, name.c_str(), n, func(n));
		return std::string(buf);
	}

public:
	static void Main()
	{
		printf(format("abs", -42, abs).c_str());
		printf(format("factorial", 7, factorial).c_str());
		printf(format("Fibonacci", 7, Fibonacci).c_str());
	}
};


void main()
{
	MyModule::Main();
}