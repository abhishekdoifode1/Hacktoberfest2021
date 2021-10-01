
public class Overloading {
    public static void main(String[] args) {

        // overloaded methods = methods that share the same name but have different parameter
        //						method name + parameters = method signature

//        make("You never know what happen next");
//        make(2334,45);
       int ans = make(34,53,4);
        System.out.println(ans);


    }
    static int make(int a, int b){
        return a+b;

    }
     static int make(int a, int b, int c){
        return a+b+c;


    }
}
