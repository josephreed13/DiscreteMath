#include<iostream>
using namespace std;
long fnpr(int, int);
long fncr(int, int);
long factorial(int);
void RoyalFlush(long);
void StraightFlush(long,long);
void FourOfAKind(long,long,long);
void FullHouse(long,long,long,long);
void Flush(long,long,long);
void Straight(long,long);
void Three(long,long,long,long);
void Two(long,long,long,long);
void One(long,long,long,long);
void High(long,long);


int main()
{
 int n, r;
 long ncr, npr;
// cout<<"\nEnter the value of n : ";
//cin>>n;
// cout<<"Enter the value of r : ";
//cin>>r;
// ncr=fncr(n,r);
 long fourone = fncr(4,1);
 long tenone = fncr(10,1);
 long lone = fncr(11,1);
 long thrteen = fncr(13,1);
 long tweleveone = fncr(12,1);
 long twelevetwo = fncr(12,2);
 long twelevethree = fncr(12,3);
 long fourthree = fncr(4,3);
 long fourtwo = fncr(4,2);
 long thrfive = fncr(13,5);
 long thrtwo = fncr(13,2);
 RoyalFlush(fourone);
 StraightFlush(tenone,fourone);
 FourOfAKind(thrteen,tweleveone,fourone);
 FullHouse(thrteen,fourthree,tweleveone,fourtwo);
 Flush(thrfive,fourone,tenone);
 Straight(tenone,fourone);
 Three(thrteen,fourthree,twelevetwo,fourone); 
 Two(thrtwo,fourtwo,lone,fourone);
 One(thrteen,fourtwo,twelevethree,fourone);
 High(thrfive,fourone);
 
 //npr=fnpr(n,r);

 //cout<<"\nValue of "<<n<<"C"<<r<<" = "<<ncr;
 //cout<<"\nValue of "<<n<<"P"<<r<<" = "<<npr;
}
long fnpr(int n,int r)
{
 long value;
 value=factorial(n)/factorial(n-r);
 return value;
}
long fncr(int n,int r)
{
 long value;
 value=factorial(n)/(factorial(r)*factorial(n-r));
 return value;
}
long factorial(int n)
{
 if(n==0)
   return 1;
 else
 {
 return(n*factorial(n-1));
 }
}
void RoyalFlush(long value){
	cout << "Royal Flush No. of Ways " << value << endl;
	cout << "Probability is .000002 " << endl;
}
void StraightFlush(long value1,long value2){
	long value = ((value1*value2)-value2);
	cout << "StraightFlush Flush No. of Ways " << value << endl;
	cout << "Probability is 0.000015" << endl;
}
void FourOfAKind(long value1, long value2, long value3){
	long value = value1 * value2 * value3;
	cout << "Four of a kind No. of Ways " << value << endl;
	cout << "Probability is 0.000240" << endl;
}
void FullHouse(long value1, long value2, long value3,long value4){
	long value = value1 * value2 * value3 * value4;
	cout << "Full House No. of Ways " << value << endl;
	cout << "Probability is 0.001441" << endl;
}
void Flush(long value1,long value2, long value3){
	long value = ((value1*value2)-(value3*value2));
	cout << "Flush No. of Ways " << value << endl;
	cout << "Probability is 0.001965" << endl;
}
void Straight(long value1,long value2){
	long value = ((value1*(value2*value2*value2*value2*value2)) - (value1*value2));
	cout << "Straight No. of Ways " << value << endl;
	cout << "Probability is 0.003925" << endl;
}
void Three(long value1,long value2,long value3,long value4){
	long value = (value1 * value2 * value3 * (value4*value4));
	cout << "Three of a Kind No. of Ways " << value << endl;
	cout << "Probability is 0.021129" << endl;
}
void Two(long value1,long value2, long value3, long value4){
	long value = (value1*(value2*value2)*value3*value4);
	cout << "Two of a Kind " << value << endl;
	cout << "Probability is 0.021129" << endl;
}
void One(long value1,long value2, long value3, long value4){
	long value = (value1*value2*value3*(value4*value4*value4));
	cout << "One of a kind No. of Ways " << value << endl;
	cout << "Probability is 0.422569" << endl;
}
void High(long value1, long value2){
	long value = ((value1 - 10)*((value2*value2*value2*value2*value2)-4));
	cout << "No pair/ High Card No. of Ways " << value << endl;
	cout << "Probability is 0.501177" << endl;
}
