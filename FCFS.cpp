#include<iostream>

using namespace std;

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
int main(){
	int numpro;
	cout<<"Enter the number of process :"<<endl;
	cin>>numpro;
	
	//Burst time
	int*BT=new int[numpro];
	
	

	//turnaround time

	for(int i=0;i<numpro;i++){
		cout<<"Enter the Burst time(BT) fot the processes :"<<" "<<i+1<<endl;
		cin>>BT[i];
	}
	//wating time
	int* wt = calculateWaitingTime(BT,numpro);
	
	//turnaround time
	int* TAT= calculateTurnaroundTime(BT,wt,numpro);
	//averageWT
	double averageWt=avergWaitTime(wt,numpro);
	double averageTAT=avergTurnariundTime(TAT,numpro);
for(int i=0; i<numpro;i++){
	cout<<"wating time of the process "<<i+1<<" is"<<wt[i]<<endl;
}
for(int i=0; i<numpro;i++){
	cout<<" turnaround time of the process "<<i+1<<" is"<<TAT[i]<<endl;
}	
cout<<"the averge WT is"<<averageWt<<endl;
cout<<"the averg TAT is"<<averageTAT;


//delete[] BT;
//delete[] wt;
return 0;
}