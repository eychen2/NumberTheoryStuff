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
/**
 * Performs the Euclidean algorithm on a and b to determine the gcd
 * @param a input
 * @param b input
 * @return gcd of a and b
 */
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
/**
 * Performs the Euclidean Algorithm and stores the coefficient of a and b at each step as (coeff(a),coeff(b))
 * respectively in linear
 * @param a input number
 * @param b input number
 * @param linear a vector to store data of steps of Euclidean Algorithm for different algorithms like
 * finding linear combinations
 * @return the gcd of the two numbers
 */
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
/**
 * returns the inverse of the input number given a certain modulus
 * @param numbers the number you want to find the inverse of
 * @param modulus the modulus you are working with
 * @return the inverse of numbers in the modulus you are in
 */
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
/**
 *
 * @param a input number
 * @param b input number
 * @param lin the number you want to see if there is a linear combination of a and b that makes lin
 * @return the linear combination of the two numbers as a string or that it can't be
 * expressed as a linear combination of the two
 */
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
/**
 * Uses a very rudimentary algorithm to prime factorize num.
 * @param num the number you want to find the prime factor of
 * @return the prime factorization of the number as a map with map[a]=b meaning a^b
 * is a part of the prime factorization. If a does not exist, it is not a prime factor of num
 */
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
/**
 * Performs the Chinese Remainder Theorem to solve a typical Chinese Remainder Theorem problem.
 * A typical problem generally is "Find the smallest number that is 5mod7, 3mod4, and 4mod 9.
 * Generally it is worded differently, but it boils down to that form. For the Chinese Remainder Theorem
 * to work, the modulus must be pairwise coprime and we will assume the user knows that
 * @return the smallest positive value that satisfies a typical Chinese Remainder Theorem problem.
 * Returns -1 if it is not possible
 */
int CRT()
{
    cout<<"Please enter remainders and modulus to use Chinese Remainder Theorem"<<endl;
    vector<int> remainders;
    vector<int> modulus;
    string cheese="yes";
    string cheese2;
    int a =0;
    while(cheese=="yes")
    {
        int temp;
        cout<<"Remainder: "<<endl;
        cin>>temp;
        remainders.push_back(temp);
        cout<<"Modulus: "<<endl;
        cin>>temp;
        modulus.push_back(temp);
        remainders[a]=remainders[a]%temp;
        cout<<"You typed in "<<remainders[a]<<"mod"<<modulus[a]<<" is this correct? Type \"yes\" if it is"<<endl;
        cin>>cheese2;
        if(cheese2!="yes")
        {
            remainders.pop_back();
            modulus.pop_back();
            cout<<"Retype"<<endl;
        }
        else
        {
            ++a;
            cout<<"Are there more congruencies? Type \"yes\" to continue and anything else to stop"<<endl;
            cin>>cheese;
        }

    }
    //Perform CRT algorithm
    int modulo=1;
    for(unsigned int i=0; i<modulus.size();++i)
        modulo*=modulus[i];
    vector<int> forAlgorithm;
    for(unsigned int i=0; i<modulus.size();++i)
    {
        forAlgorithm.emplace_back(inverseMod(modulo/modulus[i]%modulus[i],modulus[i]));
    }
    int ans=0;
    for(unsigned int i=0; i<forAlgorithm.size();++i)
    {
        ans=(ans+forAlgorithm[i]*remainders[i]*modulo/modulus[i])%modulo;
    }
    return ans;
}
/**
 * a legendre symbol is defined as (a/p) and is equal to 1 if a is a quadratic residue modulo p,
 * -1 if a is a non-residue modulo p, and 0 if a%p=0. This returns the legendre symbol of
 * (a/p) where a is top and p is bottom. The algorithm used is recursive based on facts
 * I had to prove with legendre symbols.
 * @param top the top
 * @param bottom the bottom
 * @return the legendre symbol of top/bottom
 */
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
    cout<<CRT()<<endl;
    return 0;
}
