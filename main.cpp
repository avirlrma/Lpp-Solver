
//#include <graphics.h>
#include <iostream>

using namespace std ;

void intersectPlot(int i,int j,int X[],int Y[],int rhs[]){
	double x=(double)(rhs[i]*Y[j]-Y[i]*rhs[j])/(double)(Y[j]*X[i]-Y[i]*X[j]) ;
	double y=(double)(rhs[i]*X[j]-X[i]*rhs[j])/(double)(X[j]*Y[i]-X[i]*Y[j]) ;
	cout<<x<<","<<y<<endl ;
}


int main()
{
	int n ;
	cin>>n ;
	int X[n],Y[n],rhs[n] ;
	for(int i=0;i<n;i++){
		cin>>X[i]>>Y[i]>>rhs[i] ;
	}	
for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){
		intersectPlot(i,j,X,Y,rhs) ;
	}
}
return  0 ;

}
