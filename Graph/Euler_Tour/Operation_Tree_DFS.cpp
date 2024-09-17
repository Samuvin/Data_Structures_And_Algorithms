class LockingTree {
public:
    vector<vector<int>>adj;
    vector<int>locks;
    int V;
    LockingTree(vector<int>& parent) {
        V=parent.size();
        locks.assign(V,-1);
        adj.assign(V,vector<int>());
        for(int i=1;i<V;i++){
            adj[parent[i]].push_back(i);
        }
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
    vector<int>path;
    bool dfs(int src,int tar)
    {
        path.push_back(src);
        if(src==tar)
            return true;
        for(int i:adj[src]){
            if(dfs(i,tar))
                return true;
        }
        path.pop_back();
        return false;
    }
    void dfs2(int src)
    {
        path.push_back(src);
        for(int i:adj[src])
        {
            dfs2(i);
        }
    }
    bool upgrade(int num, int user) {
        if(locks[num]!=-1)
            return false;
        path.clear();
        dfs(0,num);
        for(int i:path)
        {
            if(locks[i]!=-1)
                return false;
        }
        path.clear();
        dfs2(num);
        bool flag=false;
        for(int i:path)
        {
            if(locks[i]!=-1)
            {
                locks[i]=-1;
                flag=true;
            }
        }
        if(!flag)
            return false;
        locks[num]=user;
        return flag;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
