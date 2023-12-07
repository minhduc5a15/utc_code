#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char eq[50], left[25], right[25], d = 0;
	char *p1, *p2;
	fgets(eq, 50, stdin);
	sscanf(eq, "%[^=]=%s", left, right);
	int len = strlen(left);
	for (int i = 0; i < len; i++) {
		if (left[i] != 'x' && (left[i] < '0' || left[i] > '9')) {
			d = left[i];
			break;
		}
	}
	p1 = strtok(left, &d);
	p2 = strtok(NULL, &d);
	int right_val = atoi(right);
	int p1_val = atoi(p1);
	int p2_val = atoi(p2);
	if (d == '+') {
		if (strcmp(p1, "x") == 0) {
			if (right_val - p2_val < 0) printf("Khong tim duoc x");
			else printf("x=%d", right_val - p2_val);
		}
		else {
			if (right_val - p1_val < 0) printf("Khong tim duoc x");
			else printf("x=%d", right_val - p1_val);
		}
	}
	else if (d == '-') {
		if (strcmp(p1, "x") == 0) printf("x=%d", right_val + p2_val);
		else {
			if (p1_val - right_val < 0) printf("Khong tim duoc x");
			else printf("x=%d", p1_val - right_val);
		}
	}
	else if (d == '.') {
		int i = (strcmp(p1, "x") == 0 ? p2_val : p1_val);
		if (right_val % i != 0) printf("Khong tim duoc x");
		else printf("x=%d", right_val / i);
	}
	return 0;
}
