//O(n+m)
/*
class Solution {
    public void setZeroes(int[][] matrix) {
        int row = matrix.length;
        int col = matrix[0].length;
        
        boolean[] rowFlags = new boolean[row];
        boolean[] colFlags = new boolean[col];
        
        for(int i = 0 ; i < row; i++) {
        	for(int j = 0; j < col; j++) {
        		if(matrix[i][j] == 0) {
        			rowFlags[i] = true;
                    colFlags[j] = true;
        		}
        	}
        }
        
        for (int i = 0; i < row; i++) {
            if (rowFlags[i]) {
                for (int j = 0; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < col; i++) {
            if (colFlags[i]) {
                for (int j = 0; j < row; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
}
*/
public void setZeroes(int[][] matrix) {
        int noZeroRawIndex = -1;
        int rawLength = matrix.length;
        int colLength = matrix[0].length;
        for (int i = 0; i < rawLength; i++) {
            int index = 0;
            for (index = 0; index < colLength; index++) {
                if (matrix[i][index] == 0) {
                    break;
                }
            }
            if (index == colLength) {
                noZeroRawIndex = i;
                break;
            }
        }

        if (noZeroRawIndex == -1) {
            for (int i = 0; i < rawLength; i++) {
                for (int j = 0; j < colLength; j++) {
                    matrix[i][j] = 0;
                }
            }
        } else {
            for (int i = 0; i < rawLength; i++) {
                for (int j = 0; j < colLength; j++) {
                    if (matrix[i][j] == 0) {
                        matrix[noZeroRawIndex][j] = 0;
                    }
                }
            }

            for (int i = 0; i < rawLength; i++) {
                for (int j = 0; j < colLength; j++) {
                    if (i == noZeroRawIndex) {
                        continue;
                    }
                    if (matrix[i][j] == 0) {
                        for (int j2 = 0; j2 < colLength; j2++) {
                            matrix[i][j2] = 0;
                        }
                    }
                }
            }

            for (int i = 0; i < colLength; i++) {
                if (matrix[noZeroRawIndex][i] == 0) {
                    for (int j = 0; j < rawLength; j++) {
                        matrix[j][i] = 0;
                    }
                }
            }
        }
    }
}
