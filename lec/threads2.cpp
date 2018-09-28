#include<thread>
#include<iostream>
#include<unistd.h>

using namespace std;

int arr[4]={0,0,0,0};

void Process(int time,int number){
usleep(time);
arr[number]=1;
cout<<"[T"<<number<<"] Exiting..."<<endl;
}

void Processwatcher(int number){
	int ff=0;
	int sf=0;
	if(number==0){
		sf=1;
	}
	while(!ff||!sf){
		usleep(10000);
		if(!ff&&arr[number+1]==1){
			cout<<"[T"<<number<<"] Process "<<(number+1)<<" exited"<<endl;
			ff=1;
		}
		if(!sf&&arr[number-1]==1){
			cout<<"[T"<<number<<"] Process "<<(number-1)<<" exited"<<endl;
			sf=1;
		}
	}
	usleep(1000000);
	arr[number]=1;
	cout<<"[T"<<number<<"] Exiting..."<<endl;
}



int main(){
	thread T0(Process,1000000,0);
	thread T1(Processwatcher,1);
	thread T2(Process,3000000,2);
	
	while(!(arr[0]&&arr[1]&&arr[2])){
		cout<<"[MAIN] "<<"T0: "<<arr[0]<<"  T1: "<<arr[1]<<"  T2: "<<arr[2]<<endl;
		usleep(100000);
	}
	
	cout<<"[MAIN] Exiting..."<<endl;

	T0.join();
	T1.join();
	T2.join();
	
	return 0;
}
// g++ ./threads2.cpp -pthread -std=c++11 -o threads2