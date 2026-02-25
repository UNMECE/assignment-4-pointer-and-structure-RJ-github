#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./item.h"

int main(int argc, char* argv[]) {
	if(argc != 2) {
		printf("please add an sku number to lookup\n");
		return 0;
	}

	Item *items = (Item *)malloc(sizeof(Item) * 5);

	add_item(items, 2.00, "001", "produce", "strawberries", 0);
	add_item(items, 4.00, "002", "produce", "lettuce", 1);
	add_item(items, 60.00, "003", "entertainment", "TV", 2);
	add_item(items, 10.00, "004", "cosmetics", "lipstick", 3);
	add_item(items, 8.00, "005", "produce", "eggplant", 4);

	print_items(items, 5);
	printf("\naverage price: %f\n\n", average_price(items, 5));

	printf("item lookup: %s\n\n", argv[argc - 1]);

	int i = 0;
	while (strcmp(argv[argc - 1], items[i].sku) != 0) {
		i++;

		if(i == 5) {
			printf("Item was not found\n");
			return 0;
		}
	}

	print_item(items, i);

	free_items(items, 5);

	return 0;
}
