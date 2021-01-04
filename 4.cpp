#include <iostream>
#include <cmath>
using namespace std;


float mean(int *pointer1);
float median(int *pointer2);
int mode(int *pointer3);
float varianceAndStandardDeviation(int *pointer4);



int main(){
	
char turn='y';

while(turn!='n'){

int noOfStudents;
cout<<"Enter number of students : ";
cin>>noOfStudents;

const int size=noOfStudents+1; // additional one for limit checking

int *pntValues= NULL;
	
int *array =new int[noOfStudents];	

	cout<<"Enter data for 10 students :";
for(int i=0;i<noOfStudents;++i){
	cin>>array[i];
}
array[noOfStudents]=-1;

cout<<"---------------------------------------------"<<endl;
cout<<"Mean :"<<mean(array)<<endl;
cout<<"Median :"<<median(array)<<endl;
cout<<"Mode :";
if(mode(array)==-1){
	cout<<"No mode"<<endl;
}

if(mode(array)>-1){
	cout<<mode(array)<<endl;
}

cout<<"Variance :"<<varianceAndStandardDeviation(array)<<endl;
cout<<"Std. Deviation :"<<pow(varianceAndStandardDeviation(array),0.5)<<endl;
cout<<"----------------------------------------------"<<endl;


cout<<"Do you want to continue (y/n): ";
cin>>turn;
cout<<endl;
delete[]array;	
}
	

	
  return 0;
}



float mean(int *pointer1){
	
	int i,tot=0;
	for(i=0; ; i++){
		if(*(pointer1+i)==-1){
			break;
		}
	
		tot=tot+*(pointer1+i);
	}

	float meanVal=tot/float(i);
	
	return meanVal;

}


float median(int *pointer2){
	int i,c;
	for(i=0; ; i++){
		if(*(pointer2+i)==-1){
			break;
		}
	
		if(*(pointer2+i)>*(pointer2+i+1) && *(pointer2+i+1)!=-1){
			c=*(pointer2+i);
			*(pointer2+i)=*(pointer2+i+1);
			*(pointer2+i+1)=c;
		}	
	
	
	}
	
	if(i%2==1){
		return *(pointer2+(i/2)); 
	}
	
	if(i%2==0){
		return (*(pointer2+(i/2))+*((pointer2+(i/2)-1)))/float(2); 
	}

}

int mode(int *pointer3){
	
	int i,n=1,max=1,val=-1;
	for(i=0; ; i++){
		if(*(pointer3+i)==-1){
			break;
		}
		
		if(*(pointer3+i)==*(pointer3+i+1) && *(pointer3+i+1)!=-1){
			n++;
			if(n>max){
				max=n;
				val=*(pointer3+i);
		}
		}
		
		if(*(pointer3+i)!=*(pointer3+i+1) && *(pointer3+i+1)!=-1){
			n=1;
		}
		
		
		
	}
	
	return val;	
}

float varianceAndStandardDeviation(int *pointer4){
	
 float miu=mean(pointer4);
 
 	int i;
 	float tot;
	for(i=0; ; i++){
		if(*(pointer4+i)==-1){
			break;
		}
		
		tot=tot+pow((*(pointer4+i)-miu),2);
	}
	
	float vari=tot/float(i);
	
	return vari;
	
}


