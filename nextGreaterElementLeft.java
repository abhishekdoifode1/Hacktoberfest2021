package Stack;
/*Next greater element in Left*/

import java.util.ArrayList;
import java.util.Stack;

public class NextGreateLeft {
    public static void main(String[] args) {
        int arr[] = {7, 8, 1, 4};
        ArrayList<Integer> ans = NgeL(arr, arr.length);
        System.out.println(ans.toString());

    }
    public static ArrayList<Integer> NgeL(int arr[],int n){
        ArrayList<Integer> v = new ArrayList<>();
        Stack<Integer> s = new Stack<>();


        for (int i=0;i<n;i++){
            while (!s.empty() && s.peek()<arr[i]){
                s.pop();
            }
            if (s.empty()){
                v.add(-1);
            }
            else{
                v.add(s.peek());
            }
            s.push(arr[i]);

        }

        return  v;
    }
}
