#include <iostream>
#include "Helper.h"

int main() {
  Helper helper;
  helper.processQueries(std::cin, std::cout);
}

/*
add_words 3
yabloko yabloko yabloneviy
query yablo
add_letters n
complete
add_word yablonya
add_word yablonya
add_word yablonya
query yabl
*/
