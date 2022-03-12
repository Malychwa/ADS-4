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


int search(int* arr, int left, int right, int value) {
  if (left <= right) {
    int mind = left + (right - left) / 2;
    if (arr[mind] == value) {
      int l = search(arr, left, mind - 1, value);
      int r = search(arr, mind + 1, right, value);
      return l + r + 1;
    }
    if (arr[mind] > value) {
      return search(arr, left, mind - 1, value);
    }
    return search(arr, mind + 1, right, value);
  }
  return 0;
}


int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    count += search(&arr[i + 1], 0, len - i, value - arr[i]);
  }
  return count;
}
