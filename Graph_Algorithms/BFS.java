import java.util.*;

public class BFS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int vertex = sc.nextInt();
        int edge = sc.nextInt();
        ArrayList<Integer> mat[] = new ArrayList[vertex];
        for (int i = 0; i < vertex; i++) {
            mat[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < edge; i++) {
            int src = sc.nextInt();
            int dest = sc.nextInt();
            mat[src].add(dest);
            mat[dest].add(src);
        }
        sc.close();
        System.out.println(bfs_algorithm(mat));
        System.out.println(dfs_algorithm(mat));
    }

    static ArrayList<Integer> bfs_algorithm(ArrayList<Integer> mat[]) {
        // Ans list
        ArrayList<Integer> bfs = new ArrayList<>();

        // visited array for tracking of visited nodes ;
        boolean visited[] = new boolean[mat.length];

        // Lopping becoz to check connected components
        for (int i = 0; i < mat.length; i++) {
            if (visited[i])
                continue;

            // Adding src node to queue
            Queue<Integer> q = new LinkedList<>();
            q.add(i);
            visited[i] = true;

            // Traversing
            while (!q.isEmpty()) {
                int curr = q.poll();
                bfs.add(curr);
                for (int it : mat[curr]) {
                    if (visited[it])
                        continue;
                    q.add(it);
                    visited[it] = true;
                }
            }
        }
        return bfs;
    }

    static ArrayList<Integer> dfs_algorithm(ArrayList<Integer> mat[]) {
        boolean visited[] = new boolean[mat.length];
        ArrayList<Integer> store_dfs = new ArrayList<>();
        for (int i = 0; i < mat.length; i++) {
            if (!visited[i]) {
                dfs_helper(mat, visited, i, store_dfs);
            }
        }
        return store_dfs;
    }

    static void dfs_helper(ArrayList<Integer> mat[], boolean visited[], int src, ArrayList<Integer> store_dfs) {
        if (visited[src])
            return;

        visited[src] = true;
        store_dfs.add(src);
        for (int temp : mat[src]) {
            if (visited[temp])
                continue;
            dfs_helper(mat, visited, temp, store_dfs);
        }
    }

}
