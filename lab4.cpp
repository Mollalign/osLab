# include<iostream>
using namespace std;


//calculateTurnaroundTime
int* calculateTurnaroundTime(int bt[],int wt[],int length){
	int* TAT = new int[length];
	for(int i=0;i<length;i++){
		TAT[i]=bt[i]+wt[i];
	}
	return TAT;
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
//calculat average TAT
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
	int pronum;
	cout<<"Enter the number of the processes : ";
	cin>>pronum;
	//array that holdes the burst time
	int*BT=new int[pronum];
		//loop that used for to get the burst time
	for(int i=0;i<pronum;i++){
		cout<<"Enter the burst time of the process "<<i+1<<" : ";
		cin>>BT[i];
	}
}