
Problems Titles :
1.Turbo Sort
2.Maximum Length even Subarray
3.Racing Horses
4.Puppy and Sum 
5.Farmer And His Plot
6.Balls and Boxes
7.Fill The Grid
8.The Begining Era Of Cyberverse
9.Alternate Additions
10.Tom And Jerry 
11.Distinct Pair sum
12.Turn It
13.Andrew and the Meatballs
14.Chef and easy problem
15.Facebook
16.Passing Marks
17.400M Race
18.ChefWatson uses Social Network
19.WA Test Cases
20.Simple Statistics
21.Existence
22.Cutting Recipes
23.Chef and Interview
24.Little elephant and divisors
25.Number of Factors
26.Little Elephant and Divisors
27.Chef and String
28.Evacuate to Moon
29.Maximize Disjoint Pair sum
30.Maximum Weight difference
31.Watson asks Does permutation Exist
32.Snakes, Mongooses and the Ultimate Election
33.K-flip
34.Coins and Triangle
35. The Wave
36.Shoekand and Number
37.Minion Chef and Banana
38.Snake Eating
39.
Snake Eating
------------------

#include<bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define mod 1000000007
#define MAXN 1000010
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MP make_pair
#define INF mod

typedef vector<int> VI;
typedef long long LL;
typedef list<int> LI;
LL N, Q;
LL BS( LL arr[] , LL X )
{
	LL lo = 0, hi = N-1, mid;
	while( lo < hi ){
 
		mid = lo + (hi-lo+1)/2;
 
		if( arr[mid] < X )
			lo = mid+1;
 
		else
			hi = mid;
	}
	return lo ;
} 
LL BS_extra( LL arr[], LL X , LL idx ) 
{
	LL lo = 0, hi = idx, mid;
	LL found = 0;
	while( lo <= hi ){ 
		mid =( lo + hi)/2;
		if( X*(idx-mid+1) - (arr[mid] - arr[idx+1]) > mid )
			lo = mid+1;
		else{
			if( found == 1 && hi==lo)break;
			hi = mid;
			found = 1;
		}
	}
	if( found == 1 )return idx-lo+1;
	else return 0;
}
int main()
{
	LL TC;
	scanf("%lld",&TC);
	while( TC-- ){ 
		scanf("%lld %lld",&N,&Q);
		LL arr[N];
		REP(i,N)
		scanf("%lld",&arr[i]); 
		sort(arr, arr+N);
		LL sum[N+1];
		sum[N] = 0;
		sum[N-1] = arr[N-1];
		for( int i=N-2; i>=0; i-- )
			sum[i] = sum[i+1] + arr[i];
		while( Q-- ){
			LL K; LL ans = 0;
			scanf("%lld",&K);
 
			if( K <= arr[0] )
				ans = N;
			else{
				 int index= lower_bound(arr,arr+N,K)-arr;
				ans += N-index;
				ans += BS_extra(sum,K,index-1);
			}
			printf("%lld\n",ans);
	}
}
 

Minion Chef and Banana
-----------------------
#include <stdio.h>

int can_finish_all_bananas(int N, int H, int piles[]) {
    int max_bananas = 0;
    for (int i = 0; i < N; i++) {
        if (piles[i] > max_bananas) {
            max_bananas = piles[i];
        }
    }
    
    int left = 1, right = max_bananas;
    while (left < right) {
        int mid = (left + right) / 2;
        int hours = 0;
        for (int i = 0; i < N; i++) {
            hours += (piles[i] + mid - 1) / mid;
        }
        if (hours <= H) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int N, H;
        scanf("%d %d", &N, &H);
        int piles[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &piles[i]);
        }
        int result = can_finish_all_bananas(N, H, piles);
        printf("%d\n", result);
    }
    return 0;
}


Shoekand and number
--------------------
#include <stdio.h>
#include <math.h>
int main(void) {
	int t;
	scanf("%d",&t);
	while(t--){
	    int n;
	    scanf("%d",&n);
	    int n1=n;
	    int ct=0;
	    while(n!=0){
	        n=n/2;
	        ct++;
	    }
	    int a= pow(2,0) + pow(2,ct-1);
	    int min = abs(a-n1);
	    for(int i=1;i<ct-1;i++){
	        
	        int x = pow(2,i) + pow(2,ct-1);
	        int y = abs(n1-x);
	        if(min>y){
	            min=y;
	        }
	    }
	    int a1 = pow(2,0) + pow(2,ct);
	    int min1 = abs(a1-n1);
	    if(n1==1){
	        printf("2\n");
	    }
	    else if(min1>min){
	        printf("%d\n",min);
	    }
	    else if(n1==1){
	        printf("2\n");
	    }
	    else {
	        printf("%d\n",min1);
	    }
	}

}

The Wave
-------------------
#include <iostream>
#include <algorithm>

using namespace std;

int binary_search(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid; 
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int pos = binary_search(arr, n, x);
        if (pos != -1) {
            cout << "0" << endl;
        } else {
            int greater_count = upper_bound(arr, arr + n, x) - arr;
            if (greater_count % 2 == 0) {
                cout << "POSITIVE" << endl;
            } else {
                cout << "NEGATIVE" << endl;
            }
        }
    }
    return 0;
}

Coins and Triangle
--------------------
#include <stdio.h>

int main() {
    int t, c;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &c);
        int count = 0;
        int j = 1;
        while (c > 0) {
            c -= j;
            if(c<0)
            break;
            else
            {
            count++;
            j++;
            }
        }
        printf("%d\n", count);
    }
    return 0;}

Zonal Computing Olympiad 2015, 29 Nov 2014
---------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start, end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

int smallestSetSize(std::vector<Interval>& intervals) {
    std::sort(intervals.begin(), intervals.end(), compareIntervals);

    int setSize = 0;
    int currentEnd = -1;

    for (const auto& interval : intervals) {
        if (interval.start > currentEnd) {
            setSize++;
            currentEnd = interval.end;
        }
    }

    return setSize;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Interval> intervals(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> intervals[i].start >> intervals[i].end;
    }

    int result = smallestSetSize(intervals);

    std::cout << result << std::endl;

    return 0;
}



K-flip
----------------
#include <stdio.h>
#include <string.h>
char setd[100001];
long long int arr[200001], N, K, don;
void dip_1() {
    scanf("%lld %lld", &N, &K);
    don = 0;
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &setd[i]); 
    memset(arr, 0, sizeof(arr));

    for (int i = 1; i <= N - K + 1; i++) {
        if ((setd[i] + don) % 2 == 1) {
            don++;
            arr[i + K - 1] = 1;
        }
        don -= arr[i];
        setd[i] = '0'; 
    }

    for (int i = N - K + 2; i <= N; i++) {
        setd[i] = '0' + (setd[i] + don) % 2;
        don -= arr[i];
    }
    for (int i = 1; i <= N; i++) {
        printf("%c", setd[i]);
    }

    printf("\n");
}

int main() {
    int za;
    scanf("%d", &za);

    while (za--) {
        dip_1();
    }

    return 0;
}



Snakes, Mongooses and the Ultimate Election
-----------------------------------------------
#include<bits/stdc++.h>
#define pi                  acos(-1)
#define READ                freopen("in.txt", "r", stdin)
#define WRITE               freopen("out.txt", "w", stdout)
#define INF                 1000000000000000000
#define dist(ax,ay,bx,by)   sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))
#define M                   1000000
#define gcd(a,b)            __gcd(a,b)
#define lcm(a,b)            (a*b)/__gcd(a,b)
#define m_p(a,b)            make_pair(a,b)
#define pb                  push_back
#define pf                  printf
#define sf                  scanf

using namespace std;
typedef unsigned long long llu;
typedef long long lli;
typedef long double ld;

using namespace std;
int main()
{
    string a;
    stack<char>s;
    stack<char>s1;
    lli p,i;
    cin>>p;
    bool mark=true;
    while(p--)
    {
cin>>a;
        mark=true;
        for(i=0; i<a.size(); i++)
        {
            if(a[i]=='m'&&a[i+1]=='s'&&mark)
            {
                mark=false;
                swap(a[i],a[i+1]);
            }
            if(a[i]=='s')
            {
           s.push('s');
            }
            else
            {
                mark=true;

                if(!s.empty()&&a[i-1]=='s') s.pop();
                s1.push('m');
            }
        }
        if(s.size()>s1.size()) cout<<"snakes";
        else  if(s.size()<s1.size()) cout<<"mongooses";
        else cout<<"tie";
        cout<<endl;
        while(!s.empty())
            s.pop();
        while(!s1.empty())
            s1.pop();
}

}

watson asks Does permutation Exist
-------------------------------------
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef long long int ll;
int main()
{
 int t,flag;
 ll n,*arr,i;
 cin>>t;
 while(t--) }
}
 {
 cin>>n;
 arr=(ll *)malloc(sizeof(ll)*n);
 for(i=0;i<n;i++)
 {
 cin>>arr[i];
 }
 sort(arr,arr+n);
 flag=0;
 for(i=1;i<n;i++)
 {
 if(arr[i]-arr[i-1]>1)
 {
 flag=1;
 break;
 }
 }
 if(flag==0)
 {
 cout<<"YES\n";
 }
 else
 {
 cout<<"NO\n";
 }
 }
}


Maximum Weight difference
-----------------------------
for _ in range(int(input())):
    N,K=map(int,input().split())
    w=list(map(int,input().split()))
    w.sort()
    son=sum(w[:K])
    dad=sum(w[K:])
    first=dad-son
    w.reverse()
    min=sum(w[:K])
    max=sum(w[K:])
    sec=min-max
    if first<sec:
        print(sec)
    else:
        print(first)


Maximize Disjoint pair sum
-----------------------------
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, d;
		cin >> n >> d;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long ans = 0;
		for (int i = n - 1; i - 1 >= 0; ) {
			if (a[i] - a[i - 1] < d) {
				ans += (a[i] + a[i - 1]);
				i -= 2;
			} else {
				i--;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

Evacuate to Moon
---------------------
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
   long long n,m,h;
   cin>>n>>m>>h;
   long long int A[n],B[m];
   int c1=0,c2=0,co=0,c3=0;
   for(int i=0;i<n;i++)
   cin>>A[i];
   for(int i=0;i<m;i++)
   cin>>B[i];
   sort(A,A+n,greater<long long>());
   sort(B,B+m,greater<long long>());
   long long ans=0;
   for(int i=0;i<min(m,n);i++)
   {
      ans+=min(A[i],B[i]*h);
   }
   cout<<ans<<endl;
    }}
chef and String
------------------
#include <stdio.h>
#include <string.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int ans1 = 0;
        char s[100000];
        scanf("%s", s);
        int n = strlen(s);
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                ans1++;
                i++;
            }
        }
        printf("%d\n", ans1);
    }
    return 0;
}

Little Elephant and Divisors
---------------------------------
#include <stdio.h>
#include <math.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int getFactor(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return i;
        }
    }
    return x;
}
int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int g = a[0];
        for (int i = 1; i < n; i++) {
            g = gcd(a[i], g);
        }
        int factor = getFactor(g);
        printf("%d\n", factor > 1 ? factor : -1);
    }
    return 0;
}


Number of factors
---------------------------
const MAX = 1000001;
function countFactors(n) {
    let factors = new Array(MAX).fill(0);
    
    for (let i = 2; i * i <= n; ++i) {
        while (n % i === 0) {
            factors[i]++;
            n /= i;
        }
    }
    
    if (n > 1) {
        factors[n]++;
    }
    
    let count = 1;
    for (let i = 2; i < MAX; ++i) {
        if (factors[i] > 0) {
            count *= (factors[i] + 1);
        }
    }
    
    return count;
}
function main() {
    const readline = require('readline');
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.question("Enter the number of test cases: ", function(t) {
        t = parseInt(t);
        let testCase = 0;
        rl.question("Enter the values for each test case separated by space: ", function(input) {
            let values = input.split(' ').map(Number);
            for (let i = 0; i < t; ++i) {
                let n = values[testCase++];
                let product = 1;
                for (let j = 0; j < n; ++j) {
                    let a = values[testCase++];
                    product *= a;
                }
                console.log(countFactors(product));
            }
            rl.close();
        });
    });
}
main();


Little Elephant and Divisors 
------------------------------
#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int getFactor(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return i;
        }
    }
    return x;
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
      
        int g = a[0];
        for (int i = 1; i < n; i++) {
            g = gcd(a[i], g);
        }
        int factor = getFactor(g);
        printf("%d\n", factor > 1 ? factor : -1);
    }
    return 0;
}



Chef and Interview(java)
-------------------
import java.io.*;
import java.util.*;

public class Main {
	
	private static FastReader in;
	
	public static void main(String[] args) {
		in = new FastReader();
		int tc = 1;
		tc = in.nextInt();
		for(int t = 0; t < tc; t++) {
			new Solver();
		}
	}
	static class Solver { 
		Solver() {
			int n = in.nextInt();
			ArrayList<Integer> divisors = new ArrayList<Integer>();
			for(int i = 1; i <= (int) Math.sqrt(n); i++) {
				if(n % i == 0) {
					divisors.add(i);
					int otherDivisor = n / i;
					if(otherDivisor != i) {
						divisors.add(otherDivisor);
					}
				}
			}
			
	
			long sum = 0;
			for(Integer x : divisors) {
				sum += x;
			}
			

			System.out.println(sum);
		}
	}
	static class FastReader {
		BufferedReader br;
		StringTokenizer st;
		
		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		String next() {
			while(st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch(IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		
		long nextLong() {
			return Long.parseLong(next());
		}
		
		double nextDouble() {
			return Double.parseDouble(next());
		}
		
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch(IOException e) {
				e.printStackTrace();
			}
			return str;
}
}
}
Cutting Recipes
----------------
#include <stdio.h>
int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int T, N, i, gcd_all, min_factor;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int A[N];
        for (i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        gcd_all = A[0];
        for (i = 1; i < N; i++) {
            gcd_all = gcd(gcd_all, A[i]);
        }
        min_factor = gcd_all;
        for (i = 0; i < N; i++) {
            A[i] /= min_factor;
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    return 0;
}

Existence
------------
#include <stdio.h>
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long X, Y;
        scanf("%lld %lld", &X, &Y);

        if (X * X == 2 * Y) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

Simple Statistics
-----------------------
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int measurements[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &measurements[i]);
        }
        qsort(measurements, n, sizeof(int), compare);
        double sum = 0;
        for (int i = k; i < n - k; i++) {
            sum += measurements[i];
        }
        double average = sum / (n - 2 * k);
        printf("%.6lf\n", average);
    }
    return 0;
}

WA Test Cases
---------------------
#include <stdio.h>
#include <limits.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int sizes[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &sizes[i]);
        }
        char verdict[n + 1];
        scanf("%s", verdict);
        int minSize = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (verdict[i] == '0') {
                if (sizes[i] < minSize) {
                    minSize = sizes[i];
                }
            }
        }
        printf("%d\n", minSize);
    }
    return 0;
}

ChefWatson uses Social Network
----------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct post {
    int id;
    int popularity;
    char content[101];
    int is_special;
} Post;
int compare_posts(const void* a, const void* b) {
    const Post* post_a = (const Post*)a;
    const Post* post_b = (const Post*)b;
    if (post_a->is_special != post_b->is_special) {
        return post_a->is_special > post_b->is_special ? -1 : 1;
    } else if (post_a->popularity != post_b->popularity) {
        return post_a->popularity > post_b->popularity ? -1 : 1;
    } else {
        return strcmp(post_a->content, post_b->content);
    }
}
int main() {
    int n, m; 
    scanf("%d %d", &n, &m);
    int special_friends[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &special_friends[i]);
    }
    Post posts[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %s", &posts[i].id, &posts[i].popularity, posts[i].content);
        posts[i].is_special = 0;
        for (int j = 0; j < n; j++) {
            if (posts[i].id == special_friends[j]) {
                posts[i].is_special = 1;
                break;
            }
        }
    }
    qsort(posts, m, sizeof(Post), compare_posts);
    for (int i = 0; i < m; i++) {
        printf("%s\n", posts[i].content);
    }
    return 0;
}

400M Race
--------------
#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        double speedAlice = 400.0 / a;
        double speedBob = 400.0 / b;
        double speedCharlie = 400.0 / c;
        if (speedAlice > speedBob && speedAlice > speedCharlie) {
            printf("ALICE\n");
        } else if (speedBob > speedAlice && speedBob > speedCharlie) {
            printf("BOB\n");
        } else {
            printf("CHARLIE\n");
        }
    }
    return 0;
}

Passing Marks
------------------
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, X;
        scanf("%d %d", &N, &X);

        int A[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        qsort(A, N, sizeof(int), cmp);
        int passingMark = A[N - X];
        printf("%d\n", passingMark-1);
    }
    return 0;
}

Facebook
-----------------
#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        int mostPopularIndex = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[mostPopularIndex] || (a[i] == a[mostPopularIndex] && b[i] > b[mostPopularIndex])) {
                mostPopularIndex = i;
            }
        }
        printf("%d\n", mostPopularIndex + 1);
    }
    return 0;
}


Chef and easy problem
-----------------------------
#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
    return (*(int*)b) - (*(int*)a);
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n];

    
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), compare);
        long long maxStones = 0;
        for (int i = 0; i < n; i += 2) {
            maxStones += a[i];
        }
        printf("%lld\n", maxStones);
    }

    return 0;
}


Andrew and the Meatballs
---------------------------------
#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n, m;
        scanf("%lld %lld", &n, &m);
        long long p[n];
        for (int i = 0; i < n; i++) {
            scanf("%lld", &p[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (p[j] < p[j + 1]) {
       
                    long long temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
                }
            }
        }
        long long totalMeatballs = 0;
        int plates = 0;
        for (int i = 0; i < n; i++) {
            totalMeatballs += p[i];
            plates++;
            if (totalMeatballs >= m) {
                break;
            }
        }
        if (totalMeatballs >= m) {
            printf("%d\n", plates);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}

Turbo Sort
-------------------
Given a list of numbers, you have to sort them in non decreasing order.

#include <stdio.h>
#include <limits.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int sizes[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &sizes[i]);
        }

        char verdict[n + 1];
        scanf("%s", verdict);


        int minSize = INT_MAX;


        for (int i = 0; i < n; i++) {

            if (verdict[i] == '0') {
                if (sizes[i] < minSize) {
                    minSize = sizes[i];
                }
            }
        }
        printf("%d\n", minSize);
    }
    return 0;
}

Maximum Length Even Subarray 
----------------------------
#include <stdio.h>
int max_even_subsequence_length(int N) {
    int sequence_sum = N * (N + 1) / 2;
    if (sequence_sum % 2 == 0) {
        return N;
    }
        return N - 1;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);
        int result = max_even_subsequence_length(N);
        printf("%d\n", result);
    }
    return 0;
}

Racing Horses
---------------------
#include <stdio.h>
#include <stdlib.h> 
int compare(const void *a, const void *b) {
    return *(long *)a - *(long *)b;
}
int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        long s[n];
        for (int i = 0; i < n; i++) {
            scanf("%ld", &s[i]);
        }

        qsort(s, n, sizeof(long), (int (*)(const void *, const void *))compare);

        long min_diff = s[n - 1];  
        for (int i = 1; i < n; i++) {
            long diff = s[i] - s[i - 1];
            if (diff < min_diff) {
                min_diff = diff;
            }
        }

        printf("%ld\n", min_diff);
    }

    return 0;
}

Turn It
---------
#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while (T--) {
        long long U, V, A, S;
        scanf("%lld %lld %lld %lld", &U, &V, &A, &S);
        long long min_distance = (U * U) - (V * V);
               if (min_distance <= 2 * A * S) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}

Distinct Pair Sums
------------------
#include <stdio.h>
int count_reachable(int L, int R) {
    return (2 * R - 2 * L) + 1;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int L, R;
        scanf("%d %d", &L, &R);
        int result = count_reachable(L, R);
        printf("%d\n", result);
    }

    return 0;
}

Tom And Jerry 
----------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* can_reach_in_k_moves(int a, int b, int c, int d, int k) {
    int distance = abs(a - c) + abs(b - d);
    if (distance > k || (k - distance) % 2 != 0) {
        return "NO";
    } else {
        return "YES";
    }
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        int a, b, c, d, k;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        char* result = can_reach_in_k_moves(a, b, c, d, k);
        printf("%s\n", result);
    }

    return 0;
}

Alternate Additions
-------------------
#include <stdio.h>

int main() 
{
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        int A,B;
        scanf("%d %d", &A, &B);
        int diff = B - A;
        if ((B - A) % 3 == 0)
        {
            printf("Yes\n");
        }
        else if ((B - A)%3 == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

The Begining Era Of Cyberverse
-------------------------------

#include <stdio.h>

int solve(int N, int K) {
    return K / N;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 0; tc < T; ++tc) {
        int N, K;
        scanf("%d %d", &N, &K);

        printf("%d\n", solve(N, K));
    }

    return 0;
}

Fill The Grid
-------------
#include <stdio.h>

int main() 
{
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        int n,m;
        scanf("%d %d", &n, &m);
        if(n % 2 != 0 && m % 2 != 0)
        {
            printf("%d\n", n+m-1);
        }
        else if(n % 2 != 0 && m % 2 == 0)
        {
            printf("%d\n", m);
        }
        else if(n % 2 == 0 && m % 2 != 0)
        {
            printf("%d\n", n);
        }
        else
        {
            printf("%d\n", 0);
        }
    }
    
    return 0;
}

Balls and Boxes
---------------

#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--){
	    int n,k,s;
	    scanf(" %d %d",&n,&k);
	    s=(k*(k+1)/2);
	    if(s<=n){
	        printf("Yes \n");
	    }
	    else{
	        printf("No \n");
	    }
	}
	return 0;
}

Farmer And His Plot
--------------------

#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int find_min_square_plots(int length, int breadth) {
    int common_divisor = gcd(length, breadth);
    int min_plots = (length / common_divisor) * (breadth / common_divisor);
    return min_plots;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
         int N, M;
        scanf("%d %d", &N, &M);
        int result = find_min_square_plots(N, M);
        printf("%d\n", result);
    }

    return 0;
}

Puppy and Sum (python)
--------------
def sum_function(D, N):
    if D == 1:
        return sum(range(1, N+1))
    else:
        return sum_function(D-1, sum(range(1, N+1)))

# Input reading
T = int(input())
for _ in range(T):{
    D, N = map(int, input().split())
    result = sum_function(D, N)
    print(result)
}

Turbo Sort
-----------------
Given a list of numbers, you have to sort them in non decreasing order.
#include <stdio.h>
#include <limits.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        int sizes[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &sizes[i]);
        }

        char verdict[n + 1];
        scanf("%s", verdict);
        int minSize = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (verdict[i] == '0') {
                if (sizes[i] < minSize) {
                    minSize = sizes[i];
                }
            }
        }
        printf("%d\n", minSize);
    }

    return 0;
}
