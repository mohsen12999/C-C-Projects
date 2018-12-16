#include <iostream> 
using namespace std; 

int fact (int n)
{
	if(n<=1)
	{
		return 1;
	}
	return n*fact(n-1);
}

int pascal(int n,int k)
{
	return (float)fact(n)/(fact(k)*fact(n-k));
}

int main()
{
    int n,k;
    cout<<"n: ";
    cin>>n;
    cout<<"k: ";
    cin>>k;

    cout<<"tarkib ("<<n<<","<<k<<"): "<<pascal(n,k);

    return 0;
}
