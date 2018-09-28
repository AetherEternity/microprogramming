#include<thread>
#include<iostream>
#include<unistd.h>

using namespace std;

void Process(int time,int number){
for(int i=0;i<10;i++){
cout<<"Process"<<number<<endl;
usleep(time);
}
}

int main(){
thread T(Process,30,1);
thread T2(Process,100,2);
thread T3(Process,30000,3);

Process(10000,343422);
T.join();
T2.join();
T3.join();

return 0;
}
// g++ ./main.cpp -pthread -std=c++11