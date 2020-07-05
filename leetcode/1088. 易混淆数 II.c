int shiftNum[10] = {
    0, 1, -1, -1, -1, -1, 9, -1, 8, 6
};
int SymmetricalNum[5] = {
    0, 1, 6, 8, 9
};

bool CheckNumIsValid(long long n)
{
    if (n == 0) {
        return false;
    }
    long long tmp = 0;
    long long num = n;
    while (n > 0) {
        tmp = tmp * 10 + (shiftNum[n % 10]);
        n /= 10;
    }
    return tmp != num;
}

int confusingNumberII(int N){
    long long res = 0;
    if (N < 6) {
        return 0;
    }
    if (N < 9) {
        return 1;
    }
    if (N < 10) {
        return 2;
    }
    res = 2;
    int q[10000000] = {0};
    int front = 0;
    int end = 0;
    q[end++] = 1;
    q[end++] = 6;
    q[end++] = 8;
    q[end++] = 9;
    while (front < end) {
        int top = q[front++];
        for (int i = 0; i < 5; i++) {
            int tmp = top * 10 + SymmetricalNum[i];
            if (tmp > N) {
                return res;
            }
            if (CheckNumIsValid(tmp)) {
                res++;
            }
            q[end++] = tmp;
        }

    }
    return res;
}