#pragma once

#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>

namespace IPFilter_NS
{
 	using uint = unsigned int;
 	using ivec = std::vector<int>;

	struct IPv4
	{
		IPv4(const std::string &str);
		std::tuple<int, int, int, int> ip_;
		
		friend bool operator>(const IPv4 &left, const IPv4 &right)
		{
			return left.ip_ > right.ip_;
		}
	};

	class IPv4Pool
	{
	public:
		IPv4Pool() = default;
		void append(const IPv4 &ip);
		void sort();
		
		IPv4Pool filter_any(uint num) const;

		template<typename... Args>
		IPv4Pool filter(Args... args) const
		{
			IPv4Pool tempPool;
			ivec vals(4);
			ivec unpackedArgs = {args...};

			for (const auto &ip: pool_)
			{
				std::tie(vals[0], vals[1], vals[2], vals[3]) = ip.ip_;
				if (std::equal(unpackedArgs.begin(), unpackedArgs.end(), vals.begin()))
					tempPool.append(ip);
			}

			return tempPool;
		}
	
	private:
		std::vector<IPv4> pool_;
		friend std::ostream &operator<<(std::ostream &os, const IPv4Pool &ipPool);
	};
} //IPFilter_NS