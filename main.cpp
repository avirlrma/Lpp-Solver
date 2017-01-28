#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <algorithm>

using namespace std ;

void intersectPlot(int i,int j,int X[],int Y[],int rhs[],double &a,double& b){
	double x=(double)(rhs[i]*Y[j]-Y[i]*rhs[j])/(double)(Y[j]*X[i]-Y[i]*X[j]) ;
	double y=(double)(rhs[i]*X[j]-X[i]*rhs[j])/(double)(X[j]*Y[i]-X[i]*Y[j]) ;
	circle(x*100,y*100,5) ;
   a=x ; b=y;
}

void linePlot(int i,int X[],int Y[],int rhs[],double a,double b){
	double x=(double)rhs[i]/(double)X[i] ;
	double y=(double)rhs[i]/(double)Y[i] ;
	line(x*100,0,0,y*100) ;
	a=x ;b=y;
   
}

void linePlot(int a,int b,int c){
	double x=(double)c/(double)a ;
	double y=(double)c/(double)b ;
	line(x*100,0,0,y*100) ;
}

int max(double arr[],int size){
	double max=0 ;
	int index=0;
	for(int i=0;i<size;i++){
		if(max<arr[i]){
			max=arr[i] ;
			index=i;
		}
	}
	cout<<"The maximum value of function is "<<max ;
	return index;
}

/*All constraints are assumed to be of less than equal to type!.*/

int main()
{ 	 cout<<"                        LPP Solver!"<<endl ;
   //graphics stuff declaration!
    int gd=DETECT,gm;
  	initgraph(&gd,&gm,NULL);
  	//for objective function! -- ax+by 
	int a,b ;
	cout<<"Enter the coefficents of objective function: "<<endl ;
	cin>>a>>b ;
	//n constraints!
	setcolor(BLUE) ;
	int n ;
	cin>>n ;
	//for storing boundary points! 
	int size=(n+2)*(n+1)/2 ;
	double bouX[size],bouY[size],val[size] ;
	//for storing equations! 
	int X[n],Y[n],rhs[n] ;
	for(int i=0;i<n;i++){
		cin>>X[i]>>Y[i]>>rhs[i] ;
	}	
  //marking intersections of contraints 
for(int i=0,k=0;i<n;i++){
	for(int j=i+1;j<n;j++,k++){
		intersectPlot(i,j,X,Y,rhs,bouX[k],bouY[k]) ;
	}
 }	

//plot each line -- take care of zero
	for(int i=0,k=(n*n-n)/2;i<n;i++,k++){
	linePlot(i,X,Y,rhs,bouX[k],bouY[k]) ;
	}

bouX[size-1]=0 ;bouY[size-1]=0 ; //origin!

for(int i=0;i<size;i++){
	val[i]=a*bouX[i]+b*bouY[i] ;
	}
int index=max(val,size) ;
setcolor(RED) ;
floodfill(bouX[index]*100,bouY[index]*100,BLUE) ;
cout<<" and it occurs at ("<<bouX[index]<<","<<bouY[index]<<")"<<endl;
setcolor(YELLOW) ;
floodfill(0,0,BLUE) ;

/*
//plots objective func!
 setcolor(RED) ;
 for(int i=5;i<10;i++){
 	linePlot(a,b,i) ; 
 }*/

//draw the axis !
setcolor(WHITE) ;
line(0,0,getmaxx(),0) ;
line(0,0,0,getmaxy()) ; 


delay(10000);
closegraph();
return  0 ;
}
