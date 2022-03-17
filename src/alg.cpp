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

int cbinsearch(int *arr, int size, int crit, int value) {
  int count = 0;
  int l = crit;
  int r = size - 1;
  int mid = 0;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (arr[mid] == value && mid != crit) {
      count++;
      int m1 = mid, m2 = mid;
      while (arr[--m1] == value && m1>crit) {
        count++;
      }
      while (arr[++m2] == value) {
        count++;
      }
      return count;
    } else if (arr[mid] > value) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return 0;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] <= value - arr[i]) {
      count += cbinsearch(arr, len, i, value - arr[i]);
    }
  }
  return count;
}
