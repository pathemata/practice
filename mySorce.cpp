#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

const int MIN = numeric_limits<int>::min();

// N^3
int inefficientMaxSum(const vector<int>& A) {
    int N = A.size(), ret = MIN;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            //구간 [i, j]의 합을 구한다.
            int sum = 0;
            for (int k = i; k <= j; ++k) {
                sum += A[k];
            }
            ret = max(ret, sum);
        }
    }

    return ret;
}

//N^2
int betterMaxSum(const vector<int>& A) {
    int N = A.size(), ret = MIN;
    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += A[j];
            ret = max(ret, sum);
        }
    }

    return ret;
}

//N*lgN
int fastMaxSum(const vector<int>& A, int lo, int hi) {
    //기저 사례: 구간의 길이가 1인 경우
    if (lo == hi) return A[lo];
    //배열을 A[lo,mid], A[mid+1,hi]의 두조각으로 나눈다. 
    int mid = (lo + hi) / 2;
    //두 부분에 모두 걸쳐있는 최대 합 구간을 찾는다. 이 구간은
    //A[i,mid]와 A[mid+1, j]형태를 갖는 구간의 합으로 이루어진다. 
    //A[i,mid]형태를 갖는 최대 구간을 찾는다.
    int left = MIN, right = MIN, sum = 0;
    for (int i = mid; i >= lo; --i) {
        sum += A[i];
        left = max(left, sum);
    }

    //A[mid+1,j]형태를 갖는 최대구간을 찾는다. 
    sum = 0;
    for (int j = mid + 1; j <= hi; ++j) {
        sum += A[j];
        right = max(right, sum);
    }
    //최대 구간이 두 조각 중 하나에만 속해있는 경우의 답을 재귀호출로 찾는다.
    int single = max(fastMaxSum(A, lo, mid)
               , fastMaxSum(A, mid + 1, hi));

    return max(left + right, single);

}

int fastestMaxSum(const vector<int>& A) {
    int N = A.size(), ret = MIN, psum = 0;
    for (int i = 0; i < N; ++i) {
        psum = max(psum, 0) + A[i];
        ret = max(psum, ret);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << "Some changes";
 
    return 0;
}
