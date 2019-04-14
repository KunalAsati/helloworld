#include<iostream>
#include<math.h>
 
using namespace std;
 
//to find gcd
int gcd(int a, int h)
{
    int temp;
    while(1)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
}
 
int main()
{
        int p,q,msg;
	int i,flag = 0;
    // Two random prime numbers
        cout<<"Enter msg:";
	cin>>msg;
	cout<<"Enter two prime numbers:";
	cin>>p;
	/////////////
    for(i = 2; i <= p/2; ++i)
    {
        // condition for nonprime number
        if(p%i == 0)
        {
            flag = 1;
          //  break;
        }
    }

    if (p == 1)
    {
      cout<<"1 is neither a prime nor a composite number.";
	return 0;
    }
    else
    {
        if (flag == 0)
          cout<<p<<"\tis a prime number."<<"\n";
        else
	   cout<<p<<"\tis not prime number."<<"\n";
    }

	cin>>q;
  for(i = 2; i <= q/2; ++i)
    {
        // condition for nonprime number
        if(q%i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (q == 1)
    {
     cout<<"1 is neither a prime nor a composite number.";
	return 0;
    }
    else
    {
        if (flag == 0)
          cout<<q<<"\tis a prime number."<<"\n";
        else
	   cout<<q<<"\tis not prime number."<<"\n";
    }
    
      
    double n=p*q;
    double count;
    double phi = (p-1)*(q-1);
 
    //public key
    //e stands for encrypt
    double e=2;
 
    //for checking co-prime which satisfies e>1
    while(e<phi){
    count = gcd(e,phi);
    if(count==1)
        break;
    else
        e++;
    }
 
    //private key
    //d stands for decrypt
    double d;
 
    //k can be any arbitrary value
    double k = 5;
  
    //choosing d such that it satisfies d*e = 1 + k * phi
    d = (1 + (k*phi))/e;
    
    double c = pow(msg,e);
    double m = pow(c,d);
    c=fmod(c,n);
    m=fmod(m,n);
 
    cout<<"Message data = "<<msg;
    cout<<"\n"<<"p = "<<p;
    cout<<"\n"<<"q = "<<q;
    cout<<"\n"<<"n = pq = "<<n;
    cout<<"\n"<<"phi = "<<phi;
    cout<<"\n"<<"e = "<<e;
    cout<<"\n"<<"k = "<<k;
    cout<<"\n"<<"Encrypted data = "<<c;
    cout<<"\n"<<"Original Message sent = "<<m;
 
    return 0;
}

