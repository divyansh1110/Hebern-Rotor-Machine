/* Author:- Divyansh Chawda
 Decryption algorithm of hebern machine 
 All the I/O are using text file
*/
#include<bits/stdc++.h>
using namespace std ;

int decry();                   //Decryption function
int check(string);             // Function for checking errors 
int find(char,string);                


int main()
{
    ios_base::sync_with_stdio(0);

       
      decry();        //calling decryption function
                
                
    return 0;
}


int decry()   // decryption function
{
    fstream k;
    k.open("Key\\key.txt");
    string key;
          getline(k,key);
         transform(key.begin(), key.end(), key.begin(), ::tolower);
    int ans=check(key);
         if(ans==0){
          cout<<"Invalid Key !!! \n";
             return 0;
         }
       
       k.close();
      
fstream c;
c.open("CypherText\\cipher.txt");
    string ciphertext;
        getline(c,ciphertext);
        c.close();
        transform(ciphertext.begin(), ciphertext.end(), ciphertext.begin(), ::tolower);

 fstream p;
 p.open("Plaintext\\plaintext.txt");       
    string plaintext;  
    int len=ciphertext.length(),j;  
    for(int i=0;i<len;i++)
    { 
        if(ciphertext[i]>96 && ciphertext[i]<123)
            { 
               j=find(ciphertext[i],key);
                 plaintext+=j;
            }
            else
            {
              plaintext+=ciphertext[i];
            }


            char temp=key[0];
       for (int i = 0; i < 25; i++)
       {
             key[i]=key[i+1];
       }
         key[25]=temp;

    }
     p<<plaintext;

    cout<<"Plaintext is:- "<<plaintext<<'\n';
    cout<<"Plaintext is also saved to the text file";

p.close();
       
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



int find(char a,string key)
{
   for (int i = 0; i < 26; i++)
   {
     if(key[i]==a)
     {
       return i+97;
     }
   }
   return 0;
}