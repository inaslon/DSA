bool makesquare(int* matchsticks, int matchsticksSize) {
    int sum = 0;
    for (int i = 0; i < matchsticksSize; i++) {
        sum += matchsticks[i];
    }

    if (sum % 4 != 0)
        return false;

    int target = sum / 4;
    int dp[(1 << matchsticksSize)];
    for (int i = 0; i < (1 << matchsticksSize); i++) {
        dp[i] = -1;
    }
    dp[0] = 0;

    for (int mask = 0; mask < (1 << matchsticksSize); mask++) {
        if (dp[mask] == -1) {
            continue;
        }

        for (int i = 0; i < matchsticksSize; i++) {
            if (mask & (1 << i))
                continue;

            int newsum = matchsticks[i] + dp[mask];
            if (newsum > target)
                continue;

            int newmask = mask | (1 << i);

            dp[newmask] = newsum % target;
        }
    }

    int fullmask = (1 << matchsticksSize) - 1;
    return dp[fullmask] == 0;
}