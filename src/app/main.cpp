#include <iostream>
#include <string>

#include "../lib/IPPool.h"

int main()
{
  std::string line;
  IPFilter_NS::IPv4Pool ipPool;

  while (std::getline(std::cin, line))
  {
  	IPFilter_NS::IPv4 ip(line);
  	ipPool.append(ip);
  }

  ipPool.sort();

  std::cout << ipPool << std::endl;

  std::cout << ipPool.filter(1) << std::endl;

  std::cout << ipPool.filter(46, 70) << std::endl;

  std::cout << ipPool.filter_any(46) << std::endl;

  return 0;
}
