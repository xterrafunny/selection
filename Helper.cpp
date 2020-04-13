#include "Helper.h"
#include <iostream>

void Helper::processQueries(std::istream &in, std::ostream &out) {
  Trie trie;
  Trie::State state = trie.createNewState();
  while (true) {
    std::string command;
    std::cin >> command;
    if (command == "exit") {
      break;
    } else if (command == "add_word") {
      std::string word;
      std::cin >> word;
      trie.addWord(word);
    } else if (command == "add_words") {
      uint32_t words_cnt;
      std::cin >> words_cnt;
      for (uint32_t i = 0; i < words_cnt; ++i) {
        std::string word;
        std::cin >> word;
        trie.addWord(word);
      }
    } else if (command == "query") {
      std::string word;
      std::cin >> word;
      state = trie.createNewState();
      state.addLetters(word);
      std::cout << trie.complete(state) << '\n';
    } else if (command == "add_letters") {
      std::string word;
      std::cin >> word;
      state.addLetters(word);
    } else if (command == "complete") {
      std::cout << trie.complete(state) << '\n';
    }
  }
}
