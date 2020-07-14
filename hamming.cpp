int hammingDist(char* str1, char* str2) {
    int i = 0, count = 0;
    while (str1[i] != 0) {
        if (str1[i] != str2[i]) {
            count++;
        }
        i++;
    }
    return count;
}


int hammingDistance(int n1, int n2) {
    int x = n1 ^ n2;
    int setBits = 0;

    while (x > 0) {
        setBits += x & 1;
        x >>= 1;
    }
}
