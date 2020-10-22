class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> a=new ArrayList<Integer>();
        Arrays.sort(nums);
        if(nums.length==0 || nums.length==1){
            return a;
        }else{
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]==nums[i+1]){
                a.add(nums[i]);
            }
        }
        return a;}
    }
}