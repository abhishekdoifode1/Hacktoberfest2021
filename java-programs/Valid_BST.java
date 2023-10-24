public class Solution {
    List<Integer> list=new ArrayList<Integer>();
    
    public boolean isValidBST(TreeNode A) {
        List<Integer> list1=new ArrayList<Integer>();
        list1=inorder(A);
        boolean ans=true;
        System.out.println(list1);
        for(int i=0;i<list1.size();i++){
            if(i==list1.size()-1){
                break;
            }
            if(list1.get(i+1)<=list1.get(i)){
                ans=false;
                break;
            }
        }
        return ans;
     
    }
    
    public List<Integer> inorder(TreeNode root){
        if(root!=null){
            inorder(root.left);
            list.add(root.val);
            inorder(root.right);
        }
        return list;
    }
}
