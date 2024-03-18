// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int result = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                result++;
            }
        }
    }
    return result;
}
int countPairs2(int *arr, int len, int value) {
    while (arr[len] > value) {
        len--;
    }
    int result = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                result++;
            } else if (arr[i] + arr[j] < value) break;
        }
    }
    return result;
}
int countPairs3(int *arr, int len, int value) {
    int result = 0;
    for (int i = 0; i < len - 1; i++) {
        int r_bound = i;
        int l_bound = len;
        while (r_bound < l_bound - 1) {
            int middle = (r_bound + l_bound) / 2;
            if (arr[i] + arr[middle] == value) {
                result++;
                int j = middle + 1;
                while ((arr[i] + arr[j] == value) && (j < r_bound)) {
                    result++;
                    j++;
                }
                j = middle - 1;
                while ((arr[i] + arr[j] == value) && (j > l_bound)) {
                    result++;
                    j--;
                }
                break;
            } else if (arr[i] + arr[middle] > value) l_bound = middle;
            else {
                r_bound = middle;
            }
        }
    }
    return result;
}
