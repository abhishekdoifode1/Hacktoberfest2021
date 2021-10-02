class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int m = dungeon.length;
        int n = dungeon[0].length;
        int[][] f = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            Arrays.fill(f[i], Integer.MAX_VALUE);
        }
        f[m][n - 1] = 1;
        f[m - 1][n] = 1;
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int health = Math.min(f[i + 1][j], f[i][j + 1]) - dungeon[i][j];
                f[i][j] = health > 0 ? health : 1;
            }
        }
        return f[0][0];
    }
}
