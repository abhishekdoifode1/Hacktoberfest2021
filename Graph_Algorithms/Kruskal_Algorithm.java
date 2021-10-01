import java.util.*;

public class Kruskal_Algorithm {

    static class Edge implements Comparable<Edge> {
        int src;
        int dest;
        int weight;

        Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }

        @Override
        public int compareTo(Kruskal_Algorithm.Edge o) {
            return this.weight - o.weight;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int E = sc.nextInt();
        Edge[] input = new Edge[E];

        // Input
        for (int i = 0; i < E; i++) {
            int src = sc.nextInt();
            int dest = sc.nextInt();
            int weight = sc.nextInt();
            input[i] = new Edge(src, dest, weight);
        }
        sc.close();

        int parent[] = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        Edge[] output = new Edge[n - 1];

        // Sort
        Arrays.sort(input);

        int count = 0;
        int i = 0;
        while (i < E && count != n - 1) {
            Edge front = input[i];
            int srcParent = findParent(front.src, parent);
            int destParent = findParent(front.dest, parent);
            if (srcParent != destParent) {
                output[count] = front;
                count++;
                parent[srcParent] = destParent;
            }
            i++;
        }

        // Print
        System.out.println("Required Tree is");
        for (Edge ans : output) {
            System.out.println(ans.src + " " + ans.dest + " " + ans.weight);
        }
    }

    static int findParent(int v, int[] parent) {
        if (parent[v] == v) {
            return v;
        }
        return findParent(parent[v], parent);
    }
}
