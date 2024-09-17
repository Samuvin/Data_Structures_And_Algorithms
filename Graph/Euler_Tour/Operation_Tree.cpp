class LockingTree {
public:
    vector<vector<int>>adj;
    vector<int>locks;
    vector<int>in;
    vector<int>out;
    int timer;
    int V;
    void Euler_Tour(int src){
        in[src]=timer++;
        for(int i:adj[src])
            Euler_Tour(i);
        out[src]=timer++;
    }
    LockingTree(vector<int>& parent) {
        timer=0;
        V=parent.size();
        locks.assign(V,-1);
        adj.assign(V,vector<int>());
        for(int i=1;i<V;i++){
            adj[parent[i]].push_back(i);
        }
        in.assign(V,-1);
        out.assign(V,-1);
        Euler_Tour(0);
    }
    
    bool lock(int num, int user) {
        if(locks[num]==-1)
        {
            locks[num]=user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(locks[num]==user)
        {
            locks[num]=-1;
            return true;
        }  
        return false;
    }
    bool isAncestor(int u,int v)
    {
        if(in[u]<in[v] && out[u]>out[v])
            return true;
        return false;
    }
    bool isDecendant(int u,int v)
    {
        if(in[v]<in[u] && out[v]>out[u])
            return true;
        return false;
    }
    bool upgrade(int num, int user) {
        if(locks[num]!=-1)
            return false;
        bool flag1=false;
        bool flag2=false;
        for(int i=0;i<V;i++)
        {
            if(isAncestor(i,num))
            {
                if(locks[i]!=-1)
                    flag1=true;
            }
        }
        if(flag1)
            return false;
        for(int i=0;i<V;i++)
        {
            if(isDecendant(i,num))
            {
                if(locks[i]!=-1)
                {
                    locks[i]=-1;
                    flag2=true;
                }
            }
        }
        if(!flag2)
            return false;
        locks[num]=user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
