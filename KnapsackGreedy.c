#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;

    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;

    if (ratioA > ratioB) {
        return -1;
    } else if (ratioA < ratioB) {
        return 1;
    } else {
        return 0;
    }
}

int knapsack(struct Item items[], int n, int capacity) {
    int totalValue = 0;
    int currentWeight = 0;

    qsort(items, n, sizeof(struct Item), compare);

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            double fraction = (double)remainingWeight / items[i].weight;
            totalValue += fraction * items[i].value;
            break;
        }
    }
//Worst time complexity O(n^2) , Best O(n log n)
//The space complexity of the algorithm is O(n)
    return totalValue;
}

int main() {
    int n, capacity;
    struct Item items[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    int totalValue = knapsack(items, n, capacity);

    printf("The maximum value that can be obtained is %d\n", totalValue);

    return 0;
}

