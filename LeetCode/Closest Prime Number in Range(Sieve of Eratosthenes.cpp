

class Solution {
public:
    //We are getting list of primes numbers using 
    // Sieve of Erotosthenes in O(NloglongN) TC.
    vector<int> primeNumbers(int n,int left,int right){
        vector<int> primes(n+1,1);
        for(int i=2;i*i<=n;i++){
            for(int j=i*i;j<=n;j+=i)
                primes[j] =0;
        }
        vector<int> res;
        for(int i=max(left,2);i<=right;i++) if(primes[i]==1) res.push_back(i);
        return res;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = primeNumbers(right,left,right);
        int num1=-1,num2=-1,diff = INT_MAX;
        for(int i=1;i<primes.size();i++){
            if(primes[i]-primes[i-1]<diff){
                diff = primes[i]- primes[i-1];
                num1 = primes[i-1];
                num2 = primes[i];
            }
        }
        return {num1,num2};
    } 
};
