int func (int mid , int n, int number){
  long long ans = 1;
  for(int i =0; i<n ;i++){
    ans = ans*mid;
    if(ans > number) return 0;
  }
  if(ans == number) return 1;
  return 2;
}

int NthRoot(int power, int number){
  int low = 1, high = number ;
  while(low<=high){
    int mid = (low+high)/2;
    int midN = func(mid , power ,number);
    if(midN == 1){
      return mid;
    }
    else if(midN == 0){
      high = mid-1;
    }
    else{
      low = mid+1;
    }
  }
  return -1;
}
