#include<stdio.h>

struct Activity {
    int id;
    float start;
    float end;
};

void display(struct Activity a[], int n) {
    printf("\nActivity\tStart\tFinish\n");
    for(int i=0; i<n; i++)
        printf("%d\t\t%.2f\t%.2f\n", a[i].id, a[i].start, a[i].end);
}

void insertionSort(struct Activity a[], int n) {
	for(int i=1; i<n; i++) {
		struct Activity currentElement = a[i];
		int index=i-1;
		while(index>=0 && currentElement.end<a[index].end) {
			a[index+1]=a[index];
			index--;
		}
		a[index+1]=currentElement;
	}
}

void activitySelection(struct Activity a[], int n) {
    if(n<=0) {
        printf("No activities available\n");
        return;
    }
    insertionSort(a, n);
    printf("\nSorted in ascending order of Finish Time\n");
    display(a, n);

    printf("\nSelected Activities\n");
    printf("Activity\tStart\tFinish\n");
    printf("%d\t\t%.2f\t%.2f\n", a[0].id, a[0].start, a[0].end);
    float e = a[0].end;
    for(int i=1; i<n; i++) {
        if(a[i].start >= e) {
            printf("%d\t\t%.2f\t%.2f\n", a[i].id, a[i].start, a[i].end);
            e = a[i].end;
        }
    }
}

int main() {
    int n;
    printf("Number of activities: ");
    scanf("%d", &n);

    struct Activity a[n];
    for(int i=0; i<n; i++) {
        printf("Activity %d\n", i+1);
        a[i].id = i+1;
        printf("Start time: ");
        scanf("%f", &a[i].start);
        printf("End time: ");
        scanf("%f", &a[i].end);
    }

    activitySelection(a, n);

    return 0;
}