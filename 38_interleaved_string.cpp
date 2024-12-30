bool isInterleave(string A, string B, string C)
{
    int M = A.size(), N = B.size();
    if ((M + N) != C.size())
        return false;

    bool IL[M + 1][N + 1];
    memset(IL, 0, sizeof(IL));

    for (int i = 0; i <= M; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            if (i == 0 && j == 0)
                IL[i][j] = true;
            else if (i == 0 && B[j - 1] == C[j - 1])
                IL[i][j] = IL[i][j - 1];
            else if (j == 0 && A[i - 1] == C[i - 1])
                IL[i][j] = IL[i - 1][j];
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1])
                IL[i][j] = IL[i - 1][j];
            else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1])
                IL[i][j] = IL[i][j - 1];
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1])
                IL[i][j] = IL[i - 1][j] || IL[i][j - 1];
        }
    }

    return IL[M][N];
}
