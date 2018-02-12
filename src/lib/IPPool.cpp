#pragma once

#include <algorithm>
#include <iostream>

#include "IPPool.h"
#include "Tools.h"

namespace IPFilter_NS
{

  IPv4::IPv4(const std::string &str)
  {
    ip_ = Tools_NS::vectorToTuple<4>(Tools_NS::split(str, '.'));
  }

  void IPv4Pool::append(const IPv4 &ip)
  {
    pool_.push_back(ip);
  }

  void IPv4Pool::sort()
  {
	std::sort(pool_.begin(), pool_.end(), [](const IPv4 &left, const IPv4 &right)
	{
	  return left > right;
	});
  }

  IPv4Pool IPv4Pool::filter_any(uint num) const
  {
    IPv4Pool tempPool;
    ivec vals(4);

    for(const auto &ip: pool_)
    {
      std::tie(vals[0], vals[1], vals[2], vals[3]) = ip.ip_;
      if (std::any_of(vals.cbegin(), vals.cend(), [&num](auto val)
        {
          return val == num;
        }))
        tempPool.append(ip);
    }

    return tempPool;
  }
  
  std::ostream &operator<<(std::ostream &os, const IPv4 &ip)
  {
	os << std::get<0>(ip.ip_) << '.' << std::get<1>(ip.ip_) << '.'
	  << std::get<2>(ip.ip_) << '.' << std::get<3>(ip.ip_) << std::endl;
	return os;
  }

  std::ostream &operator<<(std::ostream &os, const IPv4Pool &ipPool)
  {
	for (const auto &ip : ipPool.pool_)
	  os << ip;
	return os;
  }
}