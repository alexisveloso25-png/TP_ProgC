#include <stdio.h>

int factorielle(int num) {
    if (num <= 0) return 1;
    int val = num * factorielle(num - 1);
    return val;
}
