import java.io.*;
import java.util.*;

public class Main {

public static void main(String[] args) {
Scanner scn = new Scanner(System.in);
int n = scn.nextInt();
int m = scn.nextInt();
int[][] arr = new int[n][m];
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
arr[i][j] = scn.nextInt();
}
}
boolean[][] visited = new boolean [n][m];
floodfill(arr, 0, 0, "",visited);
}


public static void floodfill(int[][] maze, int sr, int sc, String asf,boolean[][] visited) {

if(maze.length-1==sr && maze[0].length-1==sc ){
System.out.println(asf);
return;
}
visited [sr][sc]=true;

if(sr>=1 && maze[sr-1][sc]==0 && visited[sr-1][sc]==false){

floodfill(maze,sr-1,sc, asf+'t',visited);
}

if(sc>=1 && maze[sr][sc-1]==0 && visited[sr][sc-1]==false){

floodfill(maze,sr,sc-1, asf+'l',visited);
}

if(sr
floodfill(maze,sr+1,sc, asf+'d',visited);
}


if(sc
floodfill(maze,sr,sc+1, asf+'r',visited);

visited[sr][sc]=true;

}
visited[sr][sc]=false;




}
}
