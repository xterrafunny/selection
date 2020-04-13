#ifndef SELECTION__HELPER_H_
#define SELECTION__HELPER_H_

#include "Trie.h"

#include <vector>
#include <iostream>

class Helper {
 public:
  Helper() = default;
  void processQueries(std::istream &in, std::ostream &out);
};

#endif //SELECTION__HELPER_H_
