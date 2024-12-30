#include<iostream>
using namespace std;

int* calculatNumofTimeSlices(int bt[],int timeslice,int length){
	
	int* NTS=new int [length];
	for(int i=0;i<length;i++){
		
		if(bt[i]< timeslice){
			NTS[i]=1;
		}else{
			NTS[i]=(bt[i]+timeslice-1)/timeslice;
		}
	}
	
	return NTS;
}
int* calculatWaitingTime(int bt[],int cst,int length){
	int* WT=new int[length];
	for(int i=0;i<length;i++){
		if(i==0){
			WT[i]=0;
		}else{
			WT[i]=WT[i-1]+bt[i-1]+cst;
		}
	}
	
	return WT;
}
int* calculatTurnaroundTime(int wt[],int bt[],int length){
	int*TAT=new int[length];
	for(int i=0;i<length;i++){
		TAT[i]=wt[i]+bt[i];
	}
	
	return TAT;
	
}
int calculatAverageWaitingTime(int wt[],int length){
	int totalWT=0;
	for(int i=0;i<length;i++){
	totalWT+=wt[i];
	}
	int averageWT=totalWT/length;
	
	return averageWT; 
}

int calculatAverageTurnaroundTime(int tat[],int length){
	int totalTAT=0;
	for(int i=0;i<length;i++){
	totalTAT+=tat[i];
	}
	int averageTAT=totalTAT/length;
	
	return averageTAT; 
}

int main(){
	int pronum;
	int timeQuantum;
	//array that holdes the burst time
	int*BT=new int[pronum];
	//geting the number of process
	cout<<"Enter the number of the processes : ";
	cin>>pronum;
	//getting the time quantum
	cout<<endl<<"Enter the Time Quantum : ";
	cin>>timeQuantum;
	//context switch time
	int CST;
	cout<<endl<<"Enter the context switching time : ";
	cin>>CST;
	
	//loop that used for to get the burst time
	for(int i=0;i<pronum;i++){
		cout<<"Enter the burst time of the process "<<i+1<<" : ";
		cin>>BT[i];
	}
	
	//Number of time slices
	int*NTS= calculatNumofTimeSlices(BT,timeQuantum,pronum);
	//wating time
	int*WT=calculatWaitingTime(BT,CST,pronum);
	//turnaround time
	int* TAT=calculatTurnaroundTime(WT,BT,pronum);
	
	int averageWT=calculatAverageWaitingTime(WT,pronum);
	int averageTAT=calculatAverageTurnaroundTime(TAT,pronum);
	
	

	
	delete[] BT;
    delete[] NTS;
    delete[] WT;
    delete[] TAT;
	return 0;
}