while (numGroup > 1) {
  if (numGroup % 2 == 0) {
    for (int i = 0; i < numGroup; i = i + 2) {
      temp.push_back(arr[i] + arr[i + 1]);
      maxTime = max(maxTime, arr[i] + arr[i + 1]);
    }
    numGroup = numGroup / 2;
  } else {
    for (int i = 0; i < numGroup - 1; i = i + 2) {
      temp.push_back(arr[i] + arr[i + 1]);
      maxTime = max(maxTime, arr[i] + arr[i + 1]);
    }
    maxTime = max(maxTime, arr[numGroup - 1]);
    temp.push_back(arr[numGroup - 1]);
    numGroup = numGroup / 2 + 1;
  }
  for (int i = 0; i < numGroup; i++) {
    arr[numGroup - 1 - i] = temp.back();
    temp.pop_back();
  }
  sumTime += maxTime;
}
