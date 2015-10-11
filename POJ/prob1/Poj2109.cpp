#include"string"
//#include"cmath"
#include"cstdio"
#include"iostream"
#include"cstring"
#include"vector"
#include"cstring"

using namespace std;

int cmp(const string&s1,const string&s2);
string reverseStr(const string &n1);
string sub1(const string &num);
string strip_zeros(const string&s1);
string add(const string&s1,const string &s2);
string div2(const string&num);
string multiply(const string&a,const string&b);
/*int stoi(const string&s){
   int ret(0);
   int ten(1);
   if(s.empty())return ret;
   for(int i=0;i<s.size();ten*=10,i++){
      ret+=ten*(s[i]-'0');  
   }
   return ret;
}*/
int compare_Nth(const string&mid,const string&n,const string&P);

string multiply(const string&a,const string&b){
    string ret("");
    if(a.empty()||b.empty())return ret;
    int n1=a.size();
    int n2=b.size();
    for(int i=0;i<n1;i++){
        string tsum("");
        for(int j=0;j<i;j++){
            tsum.push_back('0');
        }
        int rr(0);
        for(int j=0;j<n2;j++){
            int p1=a[i]-'0';
            int p2=b[j]-'0';
            int cur=p1*p2+rr;
            rr=cur/10;
            cur=cur%10;
            tsum.push_back(cur+'0');
        }
        if(rr>0){tsum.push_back('0'+rr);}
        ret=add(ret,tsum);
    }
    return ret;
}
string strip_zeros(const string&s1){
    if(s1.empty())return s1;
    int N=s1.size();
    int cnt(N);
    for(int i=N-1;i>=0;i--){
        if(s1[i]=='0'){
            cnt=i;
        } else break; 
    }
    string ret=s1.substr(0,cnt);
    return ret;
}
string div2(const string&num){
    if(num.empty())return "";
    int N=num.size();
    string ret;
    int rr(0);
    for(int i=N-1;i>=0;i--){
        int p1=num[i]-'0';
        p1+=rr*10;
        rr=p1&1;
        p1/=2;
        ret.push_back(p1+'0');
    }
    return reverseStr(ret); 
}
string sub1(const string &num){
    string cnum=strip_zeros(num);
    if(cmp(cnum,"0")<=0){return "";}//NULL for neg numbers
    string ret;
    int N=cnum.size();
    int rr(1);
    for(int i=0;i<N;i++){
       int p=cnum[i]-'0';
       if(p<rr){
           p+=10; 
           p-=rr;
           rr=1;
           
       }else{
          p-=rr;
          rr=0;  
       }
       //printf("i=%d,p=%d\n",i,p);
       ret.push_back(p+'0');
    }
    return ret; 
}
string add(const string&s1,const string &s2){
    if(s1.empty())return s2;
    if(s2.empty())return s1;
    int n1=s1.size();
    int n2=s2.size();
    int rr(0);
    string ret;
    for(int i=0;i<max(n1,n2);i++){
       int p1(0);
       if(i<n1)p1=s1[i]-'0';
       int p2(0);
       if(i<n2)p2=s2[i]-'0';
       int cur=p1+p2+rr;
       rr=cur/10;
       cur=cur%10;
       ret.push_back(cur+'0');
    }
    if(rr>0){
       ret.push_back(rr+'0');  
    }
    ret=strip_zeros(ret);
    return ret;
}
int cmp(const string&s1,const string&s2){
    if(s1.empty()&&s2.empty())return 0;
    if(s1.empty())return -1;
    if(s2.empty())return 1;
    int n1=s1.size();
    int n2=s2.size();
    if(n1!=n2)return (n1-n2)/abs(n1-n2);
    for(int i=n1-1;i>=0;i--){
        if(s1[i]!=s2[i]){
            char c1=s1[i];
            char c2=s2[i];
            return (c1-c2)/abs(c1-c2);
        }  
    }
    return 0;
}
string reverseStr(const string &n1){
    if(n1.empty())return "";
    int N=n1.size();
    string ret;
    for(int i=N-1;i>=0;i--){
        ret.push_back(n1[i]);
    }
    return ret;
}
int compare_Nth(const string&mid,const string&n,const string&P){
    string cur("1");
    int N=stoi(reverseStr(n));
    for(int i=0;i<N;i++){
       cur=multiply(cur,mid); 
       //cout<<i<<"and "<<cur<<endl;

    }     
    cur=strip_zeros(cur);
    return cmp(cur,P);
}
int main(){


    string a,b;
    while(cin>>a>>b){
        a=reverseStr(a);
        b=reverseStr(b);
        string L("1");
        string R(b);
        string ans("");
        int debug=10;
        while(cmp(L,R)!=1){
           string mid=div2(add(L,R));
           mid=strip_zeros(mid);
           //cout<<L<<" mid "<<mid<<" "<<R<<endl;
           int val=compare_Nth(mid,a,b);
           //printf("val=%d\n",val);
           if(val==0){
               ans=mid;
               break;
           }else if(val>0){
              R=sub1(mid);  
           }else{
               L=add(mid,"1");
           }
           R=strip_zeros(R);
           L=strip_zeros(L);
        }
        ans=reverseStr(ans);
        cout<<ans<<endl;
    }

    return 0;
}

