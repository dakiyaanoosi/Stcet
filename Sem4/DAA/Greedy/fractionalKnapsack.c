#include<stdio.h>

struct Items {
    int weight;
    int profit;
    float pwr;
};

void display(struct Items i[], int n) {
    printf("\nItem\tWeight\tProfit\tP/W\n");
    for(int j=0; j<n; j++)
        printf("%d\t%d\t%d\t%.3f\n", j+1, i[j].weight, i[j].profit, i[j].pwr);
}

void insertionSort(struct Items i[], int n) {
    for(int j=1; j<n; j++) {
        struct Items currentItem = i[j];
        int index = j-1;
        while(index>=0 && i[index].pwr < currentItem.pwr) {
            i[index+1] = i[index];
            index--;
        }
        i[index+1] = currentItem;
    }
}

float fractionalKnapsack(struct Items i[], int n, int cap) {
    insertionSort(i, n);
    printf("\nSorted in descending order of P/W ratio");
    display(i, n);

    float profit = 0.0;

    for(int j=0; j<n; j++) {
        if(i[j].weight <= cap) {
            cap -= i[j].weight;
            profit += i[j].profit;
        }
        else if(i[j].weight > cap && cap!=0) {
            profit += (float)cap * i[j].pwr;
            break;
        }
    }
    return profit;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Items i[n];
    for(int j=0; j<n; j++) {
        printf("Item %d\n", j+1);
        printf("Weight: ");
        scanf("%d", &i[j].weight);
        printf("Profit: ");
        scanf("%d", &i[j].profit);
        i[j].pwr = (float)i[j].profit/i[j].weight;
    }

    display(i, n);

    int cap;
    printf("Enter Knapsack Capacity: ");
    scanf("%d", &cap);

    float result = fractionalKnapsack(i, n, cap);
    printf("Maximum Profit: %.2f\n", result);

    return 0;
}