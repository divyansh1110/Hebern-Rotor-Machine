// author Divyansh Chawda
// Encryption algorithm 

#include<bits/stdc++.h>
using namespace std ;

int ency();                   //encryption function
int check(string);            // function for checking errors 
int find(char);
int decy();


int main()
{
    ios_base::sync_with_stdio(0);

       
      ency();          //calling encryption function
                
                
    return 0;
}


int ency()   // encryption function
{
    string key="abcdefghijlkmnopqrstuvwxyz";
        // cout<<"enter the key :- ";
         // cin>>key;
         transform(key.begin(), key.end(), key.begin(), ::tolower);
    // cout<<"check 1 "<<key<<'\n';
    // cout<<key.length()<<'\n';
    int ans=check(key);
   // cout<<ans<<"\n";
         if(ans==0){
          cout<<"Invalid Key!!! \n";
             return 0;
         }
       
       
      

    string plaintext="abcdefghijklmnopqrstvuwxyz";
       // cout<<"Enter plain text:-";
       // cin>>plaintext;
        transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::tolower);
    string ciphertext;    
        int len=plaintext.length();
        int j;
       for (int i = 0; i < len; i++)
       {  
           if(plaintext[i]>=97 && plaintext[i] <123) {
                j=find(plaintext[i]);
                ciphertext+=key[j];
       }else
       {
           ciphertext+=plaintext[i];
       }
        
        char temp=key[0];
       for (int i = 0; i < 25; i++)
       {
             key[i]=key[i+1];             
       }
         key[25]=temp;

       }
           
    cout<<ciphertext;
                      
return 0;
}



int check(string key)
{

  int len=key.length();

    if(len!=26)
        return 0;

  int a[26];
  for(int i=0;i<26;i++)
    a[i]=0;   

int re;
  for(int i=0;i<26;i++)
   {
     re=key[i];
     re-=97;
     if(a[re]==0)
     {
       a[re]=1;
     }else if(a[re]==1)
     {
       return 0;
     }
     
   }        
   for(int i=0;i<26;i++){
   if(a[i]!=1)
   {
     return 0;
   }
   }
   return 1;
}



int find(char a)
{
  int z=a, i=97;
   while(i<123)
   {
      if(i==z)
         {
           i-=97;
           return i;
         }
      i++;
   }
   return 0;
}
