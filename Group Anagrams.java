class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> op=new ArrayList<List<String>>();
        Map<String, LinkedList<String>> hm=new HashMap<String, LinkedList<String>>();
        for(String str:strs){
            char[] temp=str.toCharArray();
            Arrays.sort(temp);
            String key=new String(temp);
            if(!hm.containsKey(key)){
                LinkedList<String> l=new LinkedList<String>();
                l.add(str);
                hm.put(key,l);
            }
            else{
                hm.get(key).add(str);
            }
        }
        for(String str:hm.keySet()){
            op.add(new ArrayList<String>(hm.get(str)));
        }
        return op;
    }
}
        
