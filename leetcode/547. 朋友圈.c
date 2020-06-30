void helper(int i, int** M, int* exit, int MSize)
{
    for (int j = 0; j < MSize; j++) {
        if (M[i][j] == 1 && exit[j] == 0) {
            exit[j] = 1;
            helper(j, M, exit, MSize);
        }
    }
    return;
}

int findCircleNum(int** M, int MSize, int* MColSize){
    if (MSize <= 0 || *MColSize <= 0) {
        return 0;
    }
    int exit[*MColSize];
    memset(exit, 0, sizeof(exit));
    int res = 0;
    for (int i = 0; i < MSize; i++) {
        if (exit[i] == 0) {
            res++;
            helper(i, M, exit, *MColSize);
        }
    }
    return res;
}