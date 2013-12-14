#include <stdio.h>

#include "trie.h"

#define MAX_LINE 80

int main(int argc, char *argv[])
{
	FILE *file;
	char line[MAX_LINE];

	if((file = fopen(argv[1], "r")) == NULL)
	{
		puts("Couldn't open file. Exiting.");
		return 1;
	}

	trie_root_node *trie = create_trie();

	while(fgets(line, MAX_LINE, file) != NULL)
	{
		add_word(trie, line);
	}

	printf("Contains word dfsdfg? %d\n", contains_word(trie, "dfsdfg"));
	printf("Contains word yolky? %d\n", contains_word(trie, "yolky"));

	return 0;
}