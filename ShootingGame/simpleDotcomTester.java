class simpleDotcomTester {
    
    public String checking(String s, int arr[], int p) {
        int x = Integer.parseInt(s);
        for (int i=0; i<p; i++){
            if (x == arr[i] || x == arr[i] + 1) {
                System.out.println("Kill!");
                return ("Kill!");
            }
        }
        System.out.println("Miss!");
        return ("Miss!");
    }
    

}