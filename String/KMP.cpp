void KMP(string txt, string pat){
    int N = txt.size(); int M = pat.size();
    int lps[M];
    int i = 0; int j = 0;
    compute_lps(M, lps, pat);
    for(int i = 0; i < M; i++){
        cout << lps[i];
    }
    while(i < N){
        if(txt[i] == pat[j]){
            i++; 
            j++;
        }
        if(j == M){
            cout << "Found at index: " << i - j << "\n";
            j = lps[j - 1];
        }
        else if(i < N and pat[j] != txt[i]){
            if(j != 0){
                j = lps[j - 1];
            }
            else if(j == 0){
                i = i + 1;
            }
        }
    }
}
