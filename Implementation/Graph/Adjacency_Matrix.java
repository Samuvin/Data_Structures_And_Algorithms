import java.util.Scanner;
public class Graph {
    private int V;
    private int E;
    private boolean[][] adj;
    public Graph(int V)
    {
        this.V=V;
        this.E=E;
        this.adj=new boolean[V+1][V+1];
    }
    public void addEdge(int u,int v) {
        adj[u][v] = true;
        adj[v][u] = true;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int V=sc.nextInt();
        int E=sc.nextInt();
        Graph g=new Graph(V);
        for(int i=0;i<E;i++){
            int u=sc.nextInt();
            int v=sc.nextInt();
            g.addEdge(u,v);
        }
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                System.out.print(g.adj[i][j]+" ");
            }
            System.out.println();
        }
    }
}
