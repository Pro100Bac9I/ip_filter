#pragma once

#include <vector>
#include <string>
#include <cassert>
#include <utility>
#include <tuple>

namespace Tools_NS 
{
  using StrVector = std::vector<std::string>;

  StrVector split(const std::string &str, char d);
  
  template <typename T, std::size_t... Indices>
  auto vectorToTupleHelper(const std::vector<T>& v, std::index_sequence<Indices...>)
  {
    return std::make_tuple(std::stoi(v[Indices])...);
  }

  template <std::size_t N, typename T>
  auto vectorToTuple(const std::vector<T>& v)
  {
    assert(v.size() >= N);
    return vectorToTupleHelper(v, std::make_index_sequence<N>());
  }
}