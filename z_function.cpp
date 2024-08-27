vector<int> z_function(string s){
    int n=s.length();
    vector<int> z(n);
    z[0]=n;
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(r>=i){
            z[i]=min(z[i-l],r-i+1);
        }
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
        if(r<i+z[i]-1){
            l=i;
            r=z[i]+i-1;
        }
    }
    return z;
}
