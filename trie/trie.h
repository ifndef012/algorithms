#ifndef __TRIE_H__
#define __TRIE_H__

#include <string>
#include <unordered_map>
#include <memory>

class Trie {
public:
    Trie(): root_{std::make_unique<Node>()} {

    }

    void insert(const std::string& word) {
        Node* node{root_.get()};
        for (const auto& c: word) {
            auto& child{node->children[c]};
            if (!child) child = std::make_unique<Node>();
            node = child.get();
        }
        node->is_word = true;
    }

    bool search(const std::string& word) const {
        const Node* node{root_.get()};
        for (const auto& c: word) {
            if (node->children.count(c) == 0) return false;
            node = node->children.at(c).get();
        }
        return node->is_word;
    }

    bool startsWith(const std::string& prefix) const {
        const Node* node{root_.get()};
        for (const auto& c: prefix) {
            if (node->children.count(c) == 0) return false;
            node = node->children.at(c).get();
        }
        return true;
    }
private:
    struct Node {
        Node(bool is_word): is_word{is_word}, children{} {}
        Node(): Node{false} {}
        bool is_word;
        std::unordered_map<char, std::unique_ptr<Node>> children;
    };
    std::unique_ptr<Node> root_;
};


#endif // __TRIE_H__
