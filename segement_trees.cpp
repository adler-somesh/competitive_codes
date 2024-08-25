class SGTree{
    /*
        queries based on 0 indexing 
        
    */
private:
    int n;
    vector<int> seg;

    //operation based
    int queryhelp(int ind, int low, int high, int i, int j){
        if(high<i||low>j){
            return INT_MIN;
        }

        if(i<=low&&j>=high){
            return seg[ind];
        }
        int mid=(low+high) >> 1;
        int lval=queryhelp(2*ind+1, low, mid, i , j);
        int rval=queryhelp(2*ind+2, mid+1, high, i, j);
        return max(lval,rval);
    }

    void buildhelp(int ind, int low , int high , const vector<int> & input){
        if(low==high){
            seg[ind]=input[low];
            return;
        }
        int mid=(low+high) >> 1;
        buildhelp(2*ind+1, low, mid, input);
        buildhelp(2*ind+2, mid+1, high, input);

        //operation
        seg[ind]=max(seg[2*ind+1], seg[2*ind+2]);
    }

    void updatehelp(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;
        if (i<=mid) updatehelp(2*ind+1, low, mid, i, val);
        else updatehelp(2*ind+2, mid+1, high, i, val);
        seg[ind] = max(seg[2*ind + 1], seg[2*ind + 2]);
    }
public:
    SGTree(int m){
        n=m;
        seg.resize(4*m+1, -1);
    }
    SGTree(const vector<int> &input){
        int m=input.size();
        n=m;
        seg.resize(4*m+1, -1);
        build(input);
    }

    void build(const vector<int> &input){
        if(input.size()!=n)return ;
        buildhelp(0, 0, n-1, input);
    }

    int query(int a, int b){
        return queryhelp(0, 0, n-1 , a, b);
    }

    void update(int i, int val){
        updatehelp(0, 0, n-1, i, val);
    }
};
