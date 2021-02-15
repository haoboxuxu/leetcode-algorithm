class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) {
            dfs(image, sr, sc, newColor, color);
        }
        return image;
    }

    private void dfs(int[][] image, int r, int c, int newColor, int color) {
        if (image[r][c] == color) {
            image[r][c] = newColor;
            if (r >= 1) dfs(image, r-1, c, newColor, color);
            if (c >= 1) dfs(image, r, c-1, newColor, color);
            if (r+1 < image.length) dfs(image, r+1, c, newColor, color);
            if (c+1 < image[0].length) dfs(image, r, c+1, newColor, color);
        }
    }
}
