/* Author:- Divyansh Chawda
 Encryption algorithm of hebern machine 
 All the I/O are using text file
*/
#include<bits/stdc++.h>
using namespace std ;

int ency();                   //encryption function
int check(string);            // function for checking errors 
int find(char);                


int main()
{
    ios_base::sync_with_stdio(0);

       
      ency();          //calling encryption function
                
                
    return 0;
}


int ency()   // encryption function
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
      
fstream p;
p.open("Plaintext\\plaintext.txt");
    string plaintext;
        getline(p,plaintext);
        p.close();
        transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::tolower);

 fstream c;
 c.open("CypherText\\cipher.txt");       
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
           
    c<<ciphertext;

    cout<<"Encrypted ciphertext is:- "<<ciphertext<<'\n';
    cout<<"Ciphertext is also saved to the text file";
    c.close();
                      
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