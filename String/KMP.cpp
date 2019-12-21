void compute_lps(int M, int *lps, string pat){
    int len = 0; int i = 1;
    lps[0] = 0;
    while(i < M){
        if(pat[i] == pat[len]){
            len ++;
            lps[i] = len;
            i ++;
        }
        else{
            if(len != 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i ++;
            }
        }
    }
}
/** BAAA
    AAA
    i = 0, j = 0: i = 1, j = 0
    i = 1, j = 0: i = 2, j = 1
    i = 2, j = 1: i = 3: j = 2
    i = 3, j = 2: i = 4:, j = 3:
**/

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
int main()
{
    string str = "AABAACAADAABAABA";
    string pat = "AABA";
    // string str = "ABABDABACDABABCABAB";
    // string pat = "ABABCABAB";
    KMP(str, pat);
}
