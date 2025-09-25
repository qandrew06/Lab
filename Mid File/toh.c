#include <stdio.h>
void towerOfHanoi(int n, char src, char helper, char des) {

    if (n == 1) {
        printf("Move disk 1 src %c des %c\n", src, des);
        return;
    }

    towerOfHanoi(n - 1, src, des, helper);
    printf("Move disk %d src %c des %c\n", n, src, des);
    towerOfHanoi(n - 1, helper, src, des);
}

int main() {

    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'S', 'H', 'D');
    return 0;
}