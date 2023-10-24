class ReshapeMatrix {
  
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        
        int [][] ans = new int[r][c];
        
        int m = mat.length;
        int n = mat[0].length;
        
        if(m * n != r * c){ 
            return mat;
        }
        
        int a = 0; //row of ans 
        int b = 0; //col of ans
        
        for(int row = 0; row < mat.length; row++){
            
            for(int col = 0; col < mat[row].length ; col++){
                
                ans[a][b] = mat[row][col];
                b++;
                if(b == c){
                    a++;
                    b = 0;
                }
            }

        }
        return ans;
    }
}
