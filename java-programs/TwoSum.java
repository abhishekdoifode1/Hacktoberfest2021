import java.util.Scanner;

class TwoSum {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String[] entry = sc.nextLine().split(" ");
        int[] sequence = strToint(entry);
        int total = sc.nextInt();

        System.out.println(twosum(sequence, total).trim());
    }

    public static String twosum(int[] sequence, int total) {
        String res = "";
        int sum;
        for (int i = 0; i < sequence.length; i++) {
            for (int j = i + 1; j < sequence.length; j++) {
                sum = sequence[i] + sequence[j];
                if (sum == total) {
                    res += sequence[i] + " " + sequence[j] + " ";
                }
                sum = 0;
            }
        }

        if (res.equals("")) return "-1";
        return res;
    }

    public static int[] strToint(String[] array) {
        int[] numbers = new int[array.length];
        for (int i = 0; i < array.length; i++) {
            numbers[i] = Integer.parseInt(array[i]);
        }
        return numbers;
    }
}