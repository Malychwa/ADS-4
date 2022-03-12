// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = len-1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}



int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    int left = i;
    int right = len - 1;
    while (left < right) {
      int mind = (left + right) / 2;
      if (arr[i] + arr[mind] == value) {
        count++;
        int m = mind - 1;
        while ((arr[i] + arr[m] == value) && (m > left)) {
          count++;
          m--;
        }
        m = mind + 1;
        while ((arr[i] + arr[m] == value) && (m <= right)) {
          count++;
          m++;
        }
        break;
      }
      if (arr[i] + arr[mind] > value) {
        right = mind;
      } else {
        left = mind;
      }
    }
  }
  return count;
}
