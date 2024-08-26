import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Queue;
class Graph {
    private int V;
    private int E;
    public ArrayList<ArrayList<Integer>>adj;

    public Graph(int V)
    {
        this.V=V;
        this.E=E;
        this.adj=new ArrayList<ArrayList<Integer>>(V+1);
        for(int i=0;i<=V;i++){
            adj.add(new ArrayList<Integer>());
        }

    }
    public void addEdge(int u,int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }
    public ArrayList<Integer> bfs(int src){
        ArrayList<Integer> elements=new ArrayList<Integer>();
        int visited[]=new int[V+1];
        Queue<Integer> level=new LinkedList<>();
        level.add(src);
        visited[src]=1;
        while(!level.isEmpty())
        {
            int node=level.remove();
            elements.add(node);
            visited[node]=1;
            for(int nbr:adj.get(node)){
                if(visited[nbr]==0){
                    level.add(nbr);
                    visited[nbr]=1;
                }
            }
        }
        return elements;
    }
}

public class Breadth_First_Search {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int V = sc.nextInt();
        int E = sc.nextInt();
        Graph g = new Graph(V);
        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            g.addEdge(u, v);
        }
        ArrayList<Integer> ans=g.bfs(1);
        for(int i:ans){
            System.out.print(i+" ");
        }
    }
}
