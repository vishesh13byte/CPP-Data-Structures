struct DSU
{
    vector<int> parent, size;
    int comp;
    DSU(int n)
    {
        parent.resize(n); size.resize(n);
        for(int i = 0; i < n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
        comp = n;
    }

    int get(int x)
    {
        return (parent[x] == x) ? x : parent[x] = get(parent[x]);
    }

    bool join(int a, int b)
    {
        a = get(a);
        b = get(b);

        if(a == b) return false;

        if(size[a] < size[b]) swap(a, b);

        size[a] += size[b];
        parent[b] = a;
        comp--;
        return true;
    }
};
