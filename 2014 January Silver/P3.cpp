#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
  freopen("superbull.in", "r", stdin);
  freopen("superbull.out", "w", stdout);

  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  long long result = 0;
  vector<bool> used(N, false);
  vector<int> D(N, 0);
  for (int i = 0; i < N; i++) {
    /* Find the index, j, of the 'furthest' node from the current spanning tree. */
    int j = -1;
    for (int k = 0; k < N; k++) {
      if (used[k]) continue;
      if (j == -1 || D[k] > D[j]) {
        j = k;
      }
    }

    /* Update the result and 'relax' the edges out of vertex j. */
    result += D[j];
    used[j] = true;
    for (int k = 0; k < N; k++) {
      D[k] = max(D[k], A[j] ^ A[k]);
    }
  }

  cout << result << endl;
  return 0;
}
