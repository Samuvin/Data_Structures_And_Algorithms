import java.sql.Array;
import java.util.ArrayList;
import java.util.Scanner;
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
}

public class Adjacency_List {

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
        for (int i = 1; i <= V; i++) {
            System.out.print("Vertex " + i + ": ");
            for (int nbr : g.adj.get(i)) {
                System.out.print(nbr + " ");
            }
            System.out.println();
        }
    }
}
