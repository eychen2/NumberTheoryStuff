#include <iostream>
#include <unordered_map>
#include<vector>
#include <math.h>
using namespace std;
void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
int gcd(int a, int b)
{
    if(a<b)
        swap(a,b);
    while(a%b!=0)
    {
        int temp =b;
        b=a%b;
        a=temp;

    }
    return b;
}
int gcd(int a, int b,unordered_map<int,vector<int>> &linear)
{
    if(a<b)
        swap(a,b);
    linear[a]={1,0};
    linear[b]={0,1};
    while(a%b!=0)
    {
        int prevA=a;
        int temp =b;
        b=a%b;
        a=temp;
        linear[b]={linear[prevA].front()-(prevA/temp)*linear[a].front(),linear[prevA].back()-(prevA/temp)*linear[a].back()};
    }
    return b;
}
int inverseMod(int numbers, int modulus)
{
    unordered_map<int,vector<int>> store;
    if(gcd(modulus,numbers,store)!=1)
        return -1;
    else
        return (store[1].back()+modulus)%modulus;
}
int powerModularArithmetic(int rem, int exponent, int mod)
{

}
/**
 * returns the least common multiple between a and b
 * @param a input number
 * @param b input number
 * @return least common multiple between a and b
 */
int lcm(int a, int b)
{
    return (a/gcd(a,b))*b;
}
string linearCombo(int a, int b, int lin)
{
    unordered_map<int,vector<int>> linear;
    int gcd_=gcd(a,b,linear);
    if(a<b)
    {
        swap(a,b);
    }
    string first = to_string(a);
    string second = to_string(b);
    string lin_ = to_string(lin);
    if(lin%gcd_!=0)
        return lin_ +" cannot be expressed as an integer linear combination between "
        +first +" and " +second;
    return "One linear combination of " +first +" and " +second +" that results in " +lin_ +" is "
    +to_string((lin/gcd_)*linear[gcd_].front()) +"*" +first +" + " +to_string((lin/gcd_)*linear[gcd_].back())
    +"*" +second +" = " +lin_;
}
vector<int> primes(int num)
{

}
unordered_map<int,int> primeFactor(int num)
{
    unordered_map<int,int> result;
    int count=0;
    while(num%2==0)
    {
        ++count;
        num=num/2;
    }
    if(count!=0)
        result[2]=count;
    count=0;
    for(unsigned int i=3; i*i<num;i+=2)
    {
        while(num%i==0)
        {
            ++count;
            num=num/i;
        }
        if(count!=0)
            result[i]=count;
        count=0;
    }
    return result;
}
bool millerRabin(int num)
{
    int a_1=2;
    int a_2=3;

}
int CRT()
{
    cout<<"Please enter remainders and modulus to use Chinese Remainder Theorem"<<endl;
    vector<int> remainders;
    vector<int> modulus;
    string cheese="yes";
    while(cheese=="yes")
    {
        int temp;
        cout<<"Remainder: "<<endl;
        cin>>temp;
        remainders.push_back(temp);
        cout<<"Modulus: "<<endl;
        cin>>temp;
        modulus.push_back(temp);
        remainders[0]=remainders[0]%temp;
        cout<<"Are there more congruencies? Type \"yes\" to continue and anything else to stop"<<endl;
        cin>>cheese;
    }

}
int legendre(int top, int bottom)
{
    if(top<-1)
        return legendre(-1,bottom)* legendre(-1*top,bottom);
    if(top==1)
        return 1;
    else if(top==-1)
    {
        if(bottom%4==1)
            return 1;
        else
            return -1;
    }
    else if(top==2)
    {
        if(bottom%8==1||bottom%8==7)
            return 1;
        else
            return -1;
    }
    else
    {
        if(bottom%4==1||top%4==1)
            return legendre(bottom%top,top);
        else
            return -1* legendre(bottom%top,top);
    }
}
int main() {
    cout<<legendre(-2,101)<<endl;
    return 0;
}
