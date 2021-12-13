#include<iostream>
using namespace std;

const int N = 1e5;
struct Bignum{
   int v[N], n=0;
   Bignum(int num){
      while(num >0 ){
         v[n++] = num%10;
         num /= 10; 
      }
   }
   int getInteger(){
      int res = 0;
      for(int i=n-1; i>=0; --i)
         res = 10*res + v[i];
      return res;
   }
};

void print(Bignum num){
   for(int i=num.n-1; i>=0; --i)
      cout<<num.v[i];
}

Bignum add(const Bignum & a, const Bignum & b){
   if(a.n < b.n)
      return add(b, a);
   Bignum res(0);
   int flag = 0, i = 0;
   for(; i<a.n; ++i){
      flag = a.v[i] + flag;
      if(i<b.n)
         flag += b.v[i];
      res.v[i] = flag % 10;
      flag /= 10;
   }
   if(flag)
      res.v[i++] = 1;
   res.n = i;
   return res;
}


Bignum mulSingle(const Bignum & a, const int num){
   Bignum res(0);
   int flag = 0;
   for(int j=0; j<a.n; ++j){
      flag = num * a.v[j] + flag;
      res.v[j] = flag % 10;
      flag /= 10;
   }
   if(flag){
      res.v[a.n] = flag;
      res.n = a.n+1;
   }
   return res;
}

Bignum mul(const Bignum & a, const Bignum & b){
   if(a.n < b.n)
      return mul(b, a);
   Bignum res(0);
   int flag = 1;
   for(int i=0; i<b.n; ++i, flag*=10){
      int curr = b.v[i];
      Bignum temp = mulSingle(a, curr*flag);
      res = add(res, temp);
   }
   return res;
}

int main(){
   Bignum num = mul(Bignum(199), Bignum(199));
   print(num);
   return 0;
}