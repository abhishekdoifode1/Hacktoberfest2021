public class MinDepthTree {
    //      Definition for a binary tree node.
     public class TreeNode {
          int val;
          TreeNode left;
          TreeNode right;
          TreeNode() {}
          TreeNode(int val) { this.val = val; }
          TreeNode(int val, TreeNode left, TreeNode right) {
              this.val = val;
              this.left = left;
              this.right = right;
          }
      }

    public int minDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        int leftHeight = minDepth(root.left);
        int rightHeight = minDepth(root.right);
        // to prevent skewed and make our answer just return a 1
        if(leftHeight == 0 || rightHeight == 0) {
            return Math.max(leftHeight, rightHeight) + 1;

        }

        return Math.min(leftHeight, rightHeight) +1;

    }



}