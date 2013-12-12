/*
You have just been hired at a local home improvement store to help compute the proper costs of inventory. The current prices are out of date and wrong; you have to figure out which items need to be re-labeled with the correct price.
You will be first given a list of item-names and their current price. You will then be given another list of the same item-names but with the correct price. You must then print a list of items that have changed, and by how much.
Formal Inputs & Outputs
Input Description
The first line of input will be an integer N, which is for the number of rows in each list. Each list has N-lines of two space-delimited strings: the first string will be the unique item name (without spaces), the second string will be the price (in whole-integer cents). The second list, following the same format, will have the same unique item-names, but with the correct price. Note that the lists may not be in the same order!
Output Description
For each item that has had its price changed, print a row with the item name and the price difference (in cents). Print the sign of the change (e.g. '+' for a growth in price, or '-' for a loss in price). Order does not matter for output.
*/

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

struct Item {
	char name[20];
	int price;
};

void print_items(struct Item items[], int size);
int get_num_items(FILE *file);
void read_items(FILE *file, struct Item *items, int num_items);
void print_differences(struct Item *old_items, struct Item *new_items, int num_items);

int main(int argc, char **argv)
{
	char *filename;
	char line[MAX_LINE_LENGTH];
	FILE *file;

	if(argc <= 1)
	{
		puts("This application requires an argument. The argument should be a file.");
		return 0;
	}
	else
	{
		filename = argv[1];
		file = fopen(filename, "r");

		if(file != NULL)
		{
			int num_items = get_num_items(file);

			struct Item old_items[num_items];
			struct Item new_items[num_items];

			read_items(file, old_items, num_items);
			read_items(file, new_items, num_items);
			print_differences(old_items, new_items, num_items);
		}
		else
		{
			puts("Couldn't open the file");
		}
	}

	return 0;
}

void read_items(FILE *file, struct Item *items, int num_items)
{
	char line[MAX_LINE_LENGTH];
	int i;
	for(i = 0; i < num_items; i++)
	{
		if(fgets(line, MAX_LINE_LENGTH, file) != NULL)
		{
			sscanf(line, "%s %d", items[i].name, &items[i].price);
		}
	}
}

int get_num_items(FILE *file)
{
	char line[MAX_LINE_LENGTH];
	fgets(line, MAX_LINE_LENGTH, file);
	int num_items;
	sscanf(line, "%d", &num_items);

	return num_items;
}

void print_items(struct Item items[], int size)
{
	int i;
	for(int i = 0; i < size; i++)
	{
		printf("%s %d\n", items[i].name, items[i].price);
	}
}

void print_differences(struct  Item *old_items, struct Item *new_items, int num_items)
{
	struct Item old_item;
	struct Item new_item;

	int i, j;
	for(int i = 0; i < num_items; i++)
	{
		old_item = old_items[i];
		for(int j = 0; j < num_items; j++)
		{
			new_item = new_items[j];

			if(strcmp(old_item.name, new_item.name) == 0)
			{
				if(new_item.price == old_item.price)
				{
					break;
				}

				printf("%s ", old_item.name);

				if(new_item.price < old_item.price)
				{
					printf("%c%d\n", '-', old_item.price-new_item.price);
				}
				else
				{
					printf("%c%d\n", '+', new_item.price-old_item.price);
				}

				break;
			}
		}
	}
}
