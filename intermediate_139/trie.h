#ifndef TRIE_H
#define TRIE_H

typedef struct trie_root_node trie_root_node;

trie_root_node * create_trie();
int add_word(trie_root_node *root_node, char word[]);
int contains_word(trie_root_node *root, char word[]);

#endif
