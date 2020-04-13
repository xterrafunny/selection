#include "Trie.h"
#include <algorithm>

Trie::Trie() {
  root_ = new TrieNode(nullptr, '\0');
}

Trie::~Trie() {
  deleteSubtree(root_);
}

void Trie::addWord(const std::string &string) {
  TrieNode *current_node = root_;
  for (char c: string) {
    if (current_node->transition.find(c) == current_node->transition.end()) {
      current_node->transition[c] = new TrieNode(current_node, c);
    }
    current_node = current_node->transition[c];
  }
  ++current_node->frequency;
  uint32_t new_frequency = current_node->frequency;

  while (current_node != root_) {
    TrieNode *prev_node = current_node->parent;
    if (prev_node->completion_node->frequency < new_frequency) {
      prev_node->completion_node = current_node->completion_node;
    }
    current_node = prev_node;
  }
}

std::string Trie::complete(const Trie::State &state) const {
  return getWord(state.node_->completion_node);
}

std::string Trie::getWord(const Trie::State &state) const {
  return getWord(state.node_);
}

Trie::State Trie::createNewState() {
  return State(root_);
}

void Trie::deleteSubtree(Trie::TrieNode *node) {
  for (std::pair<char, TrieNode *> item: node->transition) {
    deleteSubtree(item.second);
  }
  delete node;
}

std::string Trie::getWord(Trie::TrieNode *node) const {
  std::string string;
  while (node != root_) {
    string.push_back(node->parent_char);
    node = node->parent;
  }
  std::reverse(string.begin(), string.end());
  return string;
}

void Trie::State::addLetters(const std::string &string) {
  for (char c: string) {
    if (node_->transition.find(c) == node_->transition.end()) {
      node_->transition[c] = new TrieNode(node_, c);
    }
    node_ = node_->transition[c];
  }
}
