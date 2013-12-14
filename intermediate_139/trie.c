#include <stdlib.h>
#include <stdio.h>

#include "trie.h"

typedef struct trie_node {
	int is_word;
	char key;
	struct trie_node *next, *children;
} trie_node;

struct trie_root_node {
	trie_node *root;
};

trie_node * create_node(char c);
trie_node * get_child(trie_node *node, char c);
trie_node * add_child( trie_node *node, char c);

/*int main(int argc, char *argv[])
{
	trie_root_node *root = create_trie();
	add_word(root, "hey");
	add_word(root, "heyt");

	printf("Contains hey? %d\n", contains_word(root, "hey"));
	printf("Contains heyt? %d\n", contains_word(root, "heyt"));
	printf("Contains great? %d\n", contains_word(root, "great"));

	add_word(root, "great");

	printf("Contains great? %d\n", contains_word(root, "great"));

	add_word(root, "help");

	printf("Contains hey? %d\n", contains_word(root, "hey"));
	printf("Contains heyt? %d\n", contains_word(root, "heyt"));
	printf("Contains great? %d\n", contains_word(root, "great"));
	printf("Contains help? %d\n", contains_word(root, "help"));
}*/

trie_node * create_node(char c)
{
	trie_node *new_node = (trie_node *)malloc(sizeof(trie_node));
	new_node->is_word = 0;
	new_node->key = c;
	new_node->next = NULL;
	new_node->children = NULL;

	return new_node;
}

trie_root_node * create_trie()
{
	trie_node *node = create_node('\0');
	trie_root_node *root_node = (trie_root_node *)malloc(sizeof(trie_root_node));
	root_node->root = node;

	return root_node;
}

int add_word(trie_root_node *root_node, char word[])
{
	if(word == NULL)
	{
		return 0;
	}

	if(root_node == NULL)
	{
		return 0;
	}

	trie_node *current_node = root_node->root;
	trie_node *temp;
	int i;
	char *c = word;

	while(*c != '\0' && (temp = get_child(current_node, *c)) != NULL)
	{
		//printf("Found node:   %c\n", *c);
		current_node = temp;
		c++;
	}

	while(1)
	{
		//printf("Adding child: %c under %c\n", *c, current_node->key);
		current_node = add_child(current_node, *c);
		c++;

		if(*c == '\0')
		{
			current_node->is_word = 1;
			break;
		}
	}

	return 1;
}

trie_node * add_child(trie_node *node, char c)
{
	trie_node *new_node = create_node(c);

	if(node->children == NULL)
	{
		node->children = new_node;
	}
	else
	{
		trie_node *current_node = node->children;
		trie_node *temp = current_node;
		while((temp = temp->next) != NULL)
		{
			current_node = temp;
		}

		current_node->next = new_node;
	}

	return new_node;
}

trie_node * get_child(trie_node *node, char c)
{	
	trie_node *current_node = node->children;

	if(node == NULL)
	{
		return NULL;
	}

	if(current_node == NULL)
	{
		return NULL;
	}

	if(current_node->key == c)
	{
		return current_node;
	}

	while(current_node != NULL)
	{
		//printf("Comparing %c\n", c);
		if(current_node->key == c)
		{
			return current_node;
		}

		current_node = current_node->next;
	}

	return NULL;
}

int contains_word(trie_root_node *root, char word[])
{
	if(word == NULL)
	{
		return 0;
	}

	if(root == NULL)
	{
		return 0;
	}

	char c = word[0];
	int i = 0;
	trie_node *current_node = root->root;

	while(c != '\0')
	{
		//printf("Looking for %c under %c\n", c, current_node->key);
		if((current_node = get_child(current_node, c)) == NULL)
		{
			return 0;
		}

		//printf("Found %c\n", c);

		c = word[++i];
	}

	return 1;
}
