#ifndef SELECTION__TRIE_H_
#define SELECTION__TRIE_H_

#include <string>
#include <map>

class Trie {
 public:
  Trie();
  ~Trie();
  void addWord(const std::string &string);
  class State;
  std::string complete(const State &state) const;
  std::string getWord(const State &state) const;
  State createNewState();
 private:
  struct TrieNode;

  std::string getWord(TrieNode *node) const;
  static void deleteSubtree(TrieNode *node);
  friend class Trie::State;
  TrieNode *root_;
};

class Trie::State {
 public:
  void addLetters(const std::string &string);
 private:
  Trie::TrieNode *node_;
  explicit State(TrieNode *node) : node_(node) {}
  friend class Trie;
};

struct Trie::TrieNode {
  std::map<char, TrieNode *> transition;
  uint32_t frequency = 0;
  TrieNode *parent = nullptr;
  TrieNode *completion_node = this;
  char parent_char = '\0';
  TrieNode(TrieNode *parent,
           char parent_char,
           uint32_t frequency = 0) : parent(parent),
                                     parent_char(parent_char),
                                     frequency(frequency) {}
};

#endif //SELECTION__TRIE_H_
