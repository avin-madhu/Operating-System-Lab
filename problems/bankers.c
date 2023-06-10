#include <stdio.h>

// Program to perform Bankers Algorithm in C


int main () {
	int n;  // no. of processes
	int r;  // no. of resources
	
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	printf("Enter the number of resources: ");
	scanf("%d", &r);
	
	int ans[n], finished[n];
	int avail[r];
	int alloc[n][r], max[n][r], need[n][r];
	
	for (int i = 0; i < n; i++) {
		finished[i] = 0;  // initialising finished
	}
	
	printf("\n");
	printf("Enter total resources\n");
	for (int i = 0; i < r; i++)
		scanf("%d", &avail[i]);
		
	printf("\n");
	printf("Enter allocation matrix\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < r; j++)
			scanf("%d", &alloc[i][j]);
	
	printf("\n");
	printf("Enter max matrix\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < r; j++)
			scanf("%d", &max[i][j]);
			
	// Calcluate Available
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < r; j++) {
			avail[j] -= alloc[i][j];
		}
	}
			
	// Need matrix
	for (int i = 0; i < n; i++)
		for (int j = 0; j < r; j++)
			need[i][j] = max[i][j] - alloc[i][j];
			
	int i = 0, count = 0;
	int can_run = 0;  // flag for checking if need <= avail
	int safe = 1;  // flag for checking safety
	while (safe && count < n) {
		safe = 0;
		for (i = 0; i < n; i++) {
			if (!finished[i]) {
				can_run = 1;
				for (int j = 0; j < r; j++) {
					if (need[i][j] > avail[j]) {
						can_run = 0;
						break;
					}
				}
				
				if (can_run) {
					for (int j = 0; j < r; j++) {
						avail[j] += alloc[i][j];
					}
					finished[i] = 1;
					safe = 1;
					ans[count++] = i;
				}
			}
		}
	}
	printf("\n");
	if (safe) {
		printf("Need Matrix\n");
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < r; j++)
				printf("%d ", need[i][j]);
			printf("\n");
		}
		printf("\n A possible safe sequence for allocation is: ");
		for (int i = 0; i < n-1; i++)
			printf("p%d -> ", ans[i]);
		printf("p%d\n", ans[n-1]);
	}	
	else {
		printf("System is in an unsafe state!!\n");
	}
}
