int ori(pl a, pl b, pl c){// Returns orientation of points
    int eq = (b.s - a.s) * (c.f - b.f) - (c.s - b.s) * (b.f - a.f);
    if(eq < 0){
        return -1; // Left turn
    }
    else if(eq == 0){
        return 0; // Collinear
    }
    else{
        return 1; // Right turn
    }
}
// Creates convex hull from points
vector<pl> chull(pl list[MX], bool upper, int n){
    pl a, b, c;
    vector<pl> hull;
    if(upper){
        for(int i = 0; i < (n + 1) / 2; i++){
            pl toSwap = list[i];
            list[i] = list[n - 1 - i];
            list[n - 1 - i] = toSwap;
        }
    }
    int curSize = 0;
    for(int i = 0; i < n; i++){
        pl cur = list[i];
        if(curSize >= 2){// At least two points in hull
            // cout << "Current point: " << cur.f << ", " << cur.s << "\n";
            c = cur; b = hull[curSize - 1]; a = hull[curSize - 2];
            while(ori(a, b, c) == -1 && curSize >= 2){
                curSize --;
                hull.resize(hull.size() - 1);
                if(curSize < 2){
                    break;
                }
                b = hull[curSize - 1];
                a = hull[curSize - 2];
            }
        }
        hull.pb(cur);
        curSize ++;
    }
    return hull;
}

int main() {
    int n;
    cin >> n;
    pl A[n]; pl B[n];
    F0R(i, n){
        ll x, y;
        cin >> x >> y;
        A[i] = {x, y};
    }
    sort(A, A + n);
    vector<pl> newHull = chull(A, false, n);
    vector<pl> newHull2 = chull(A, true, n);
    
    newHull.resize(newHull.size() - 1);
    newHull2.resize(newHull2.size() - 1);
    vector<pl> combo;
    
    combo.insert(combo.end(), newHull.begin(), newHull.end());
    combo.insert(combo.end(), newHull.begin(), newHull.end());
}
