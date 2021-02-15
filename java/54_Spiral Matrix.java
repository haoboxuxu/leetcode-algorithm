class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        if(matrix.length == 0) {
        	return new ArrayList<Integer>();
        }
        int len = matrix.length * matrix[0].length;
        List<Integer> res = new ArrayList<Integer>();
        
        int x = 0, y = 0;
        int xLBound = 0, yLBound = 0;
        int xHBound = matrix.length, yHBound = matrix[0].length;
        
        int move = 1;
        while(res.size() < len - 1) {
        	for (; (move < 0 && y > yLBound) || (move > 0 && y < yHBound - 1); y += move) {
                res.add(matrix[x][y]);
            }
            
            for (; (move < 0 && x > xLBound) || (move > 0 && x < xHBound - 1); x += move) {
                res.add(matrix[x][y]);
            }

            if (move > 0) {
                yHBound--;
                xLBound++;
            } else {
                yLBound++;
                xHBound--;
            }
            move *= -1;
        }
        res.add(matrix[x][y]);
        return res;
    }
}
