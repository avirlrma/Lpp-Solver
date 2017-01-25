
//#include <graphics.h>
#include <iostream>
#include <stdio.h>
#include <graphics.h>

using namespace std ;

void intersectPlot(int i,int j,int X[],int Y[],int rhs[]){
	double x=(double)(rhs[i]*Y[j]-Y[i]*rhs[j])/(double)(Y[j]*X[i]-Y[i]*X[j]) ;
	double y=(double)(rhs[i]*X[j]-X[i]*rhs[j])/(double)(X[j]*Y[i]-X[i]*Y[j]) ;
	circle(x*100,y*100,5) ;
	cout<<"intersect: "<<x<<" "<<y<<endl ;
}
void linePlot(int i,int X[],int Y[],int rhs[]){
	double x=(double)rhs[i]/(double)X[i] ;
	double y=(double)rhs[i]/(double)Y[i] ;
	line(x*100,0,0,y*100) ;
	circle(x*100,0,5) ;
		circle(0,y*100,5) ;
}
void linePlot(int a,int b,int c){
	double x=(double)c/(double)a ;
	double y=(double)c/(double)b ;
	line(x*100,0,0,y*100) ;
}

int main()
{   //for objective function! -- ax+by 
	int a,b ;
	cin>>a>>b ;
	//graphics stuff declaration!
	int gd=DETECT,gm;
  	initgraph(&gd,&gm,NULL);
  	//draw the axis bitches!
  	line(0,0,getmaxx(),0) ;
  	line(0,0,0,getmaxy()) ;
	//n constraints!
	int n=2 ;
//	cin>>n ;
	int X[n],Y[n],rhs[n] ;
	for(int i=0;i<n;i++){
		cin>>X[i]>>Y[i]>>rhs[i] ;
	}	
	//plot each line -- take care of zero
	for(int i=0;i<n;i++){
		linePlot(i,X,Y,rhs) ;
	}	

for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){
		intersectPlot(i,j,X,Y,rhs) ;
	}
 }	
 setcolor(RED) ;
 for(int i=5;i<10;i++){
 	linePlot(a,b,i) ;
 }
delay(10000);
  closegraph();
return  0 ;

}
