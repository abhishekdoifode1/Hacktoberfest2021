class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> a  = new HashSet<>();
        Arrays.sort(nums);
        if(nums.length==0) return new ArrayList<>(a);
        for(int i=0;i<nums.length-2;i++){
            if( i==0 || (nums[i-1]!=nums[i] && i>0)){
            int x=nums[i];
            Map<Integer,Integer> maps=new HashMap<Integer,Integer>();
            int target=0-x;
            for(int j=i+1;j<nums.length;j++){
                if(maps.containsKey(target-nums[j])){
                    a.add(Arrays.asList(x,target-nums[j],nums[j]));
                }else{
                    maps.put(nums[j],j);
                }
            }
            
        }
        }   
        return new ArrayList<>(a);
    }
}