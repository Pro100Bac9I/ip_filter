#define BOOST_TEST_MODULE ip_filter_test

#include <iostream>
#include <string>
#include <sstream>

#include <boost/test/unit_test.hpp>

#include "../lib/IPPool.h"
#include "../lib/Tools.h"

BOOST_AUTO_TEST_CASE(filter)
{
    std::string ipsStr = "244.12.181.18\n" 
                         "123.112.143.10\n"
                         "244.123.1.2\n" 
                         "211.11.231.11\n"
                         "12.11.42.111";

    IPFilter_NS::IPv4Pool ipPool;
    for (const auto &ip: Tools_NS::split(ipsStr))
    {
        IPFilter_NS::IPv4 ipv4(ip);
        ipPool.append(ipv4);
    }
    ipPool.sort();

    std::ostringstream oss;

    oss << ipPool.filter(244, 12);

    std::string expectedResult = "244.12.181.18\n";

    BOOST_CHECK_EQUAL(oss.str(), expectedResult);
}

BOOST_AUTO_TEST_CASE(filter_any)
{
    std::string ipsStr = "244.12.181.18\n" 
                         "123.112.143.10\n"
                         "244.123.1.2\n" 
                         "211.11.231.11\n"
                         "12.11.42.111";

    IPFilter_NS::IPv4Pool ipPool;
    for (const auto &ip: Tools_NS::split(ipsStr))
    {
        IPFilter_NS::IPv4 ipv4(ip);
        ipPool.append(ipv4);
    }
    ipPool.sort();

    std::ostringstream oss;

    oss << ipPool.filter_any(231);

    std::string expectedResult = "211.11.231.11\n";

    BOOST_CHECK_EQUAL(oss.str(), expectedResult);
}
