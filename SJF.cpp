#include<iostream>
using namespace std;

int* sortBT(int bt[],int length){
	int y;

	for(int i=0;i<length;i++){
	//	int x=bt[i];
		for(int j=i;j<length;j++){
			if(bt[i]>bt[j]){
				y=bt[i];
				bt[i]=bt[j];
				bt[j]=y;
			}
		}
	}
	return bt;
}
int* calculateWaitingTime(int bt[],int lenght){
	
	int* WT = new int[lenght];
	
	   for(int i=0;i<lenght;i++){
		   if(i==0){
			 WT[i]=0;  
		   }else{
			   WT[i]=WT[i-1]+bt[i-1];
		   }
	   }	
	return WT;
}
//calculateTurnaroundTime
int* calculateTurnaroundTime(int bt[],int wt[],int length){
	int* TAT = new int[length];
	for(int i=0;i<length;i++){
		TAT[i]=bt[i]+wt[i];
	}
	return TAT;
}

//calclate avarge wait time
float avergWaitTime(int wt[],int numpro){
	int totalWaitingTime=0;
	 float averageWT=0;	
	 for(int i =0;i<numpro;i++){
		 totalWaitingTime+=wt[i];
	 }
	 averageWT=totalWaitingTime/numpro;
	 
	 return averageWT;
}
float avergTurnariundTime(int TAT[],int numpro){
	int totalTurnaroundTime=0;
	 float averageTAT=0;	
	 for(int i =0;i<numpro;i++){
		 totalTurnaroundTime+=TAT[i];
	 }
	 averageTAT=totalTurnaroundTime/numpro;
	 
	 return averageTAT;
}
int main()
{
	int pronum;
	cout<<"Enter the number of process"<<endl;
	cin>>pronum;
	int*BT= new int[pronum];
	
	
	for(int i=0;i<pronum;i++){
		cout<<"Enter the the BT fot the process "<<i+1<<" :"<<endl;
		cin>>BT[i];
	}
	int* orderdBT=sortBT(BT,pronum);
	for(int i=0;i<pronum;i++){
		cout<<orderdBT[i];
	}
	int*WT=calculateWaitingTime(orderdBT,pronum);
	int*TAT=calculateTurnaroundTime(orderdBT,WT,pronum);
	float averagwaiting=avergWaitTime(WT,pronum);
	float avergturnaroundTime=avergTurnariundTime(TAT,pronum);
	
	

	 delete[] BT;
    delete[] WT;
    delete[] TAT;
	return 0;
}