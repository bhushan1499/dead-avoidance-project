#include<iostream>
#include<conio.h>
using namespace std;
int main()

{

 int instance[5],count,sequence[10],safe,s=0,j,completed,i;

 int available[5],allocation[10][5],max[10][5];

 int need[10][5],process,p[10],countofr,countofp,running[10];

 cout<<"\n enter the number of resources (<=5):";

 cin>>countofr;

 for(int i=0;i<countofr;i++)

 {

  cout<<"\n enter the max instance of resource R["<<i<<"]:";

  cin>>instance[i];

  available[i]=instance[i];

  

 }

 cout<<"\n enter the number of process (<=10)";

 cin>>countofp;

 cout<<"\n enter the allocation matrix \n";

 

 for(i=0;i<countofp;i++)

 {

  cout<<" FOR THE PROCESS P["<<i<<"]"<<endl;

  for(int j=0;j<countofr;j++)

  {

   cout<<"allocation of resource R["<<j<<"]is:";

   cin>>allocation[i][j];

   available[j]=allocation[i][j];

  }

 }

 cout<<"\n enter the max matrix \n\n";

 for(i=0;i<countofp;i++)

 {

  cout<<"for the process P["<<i<<"]"<<endl;

  for(int j=0;j<countofr;j++)

  {

   cout<<"max demand of resource R["<<j<<"] is:";

   cin>>max[i][j];

  }

 }

 

 

 cout<<"\n the given data are:\n";

 cout<<endl<<"\n total resource in the system\n\n";

 for(i=0;i<countofr;i++)

 {

  cout<<"R["<<i<<"]";

 }

 cout<<endl;

 for(i=0;i<countofr;i++)

 cout<<" "<<instance[i];

 

 cout<<"\n\n allocation matrix \n\n\t";

 for(j=0;j<countofr;j++)

 cout<<"R["<<j<<"]";

 cout<<endl;

 for(i=0;i<countofp;i++)

 {

  cout<<"P["<<i<<"]";

  for(j=0;j<countofr;j++)

  cout<<" "<<allocation[i][j];

  cout<<endl;

 }

 cout<<"\n\n max matrix \n\n\t";

 for(j=0;j<countofr;j++)

 cout<<"R["<<j<<"] ";

 cout<<endl;

 for(i=0;i<countofp;i++)



{

 cout<<"P["<<i<<"] ";

 for(j=0;j<countofr;j++)

 cout<<" "<<max[i][j];

 cout<<endl;

}

for(i=0;i<countofp;i++)

{

 for(j=0;j<countofr;j++)

 {

  need[i][j] = max[i][j]-allocation[i][j];

 }

}



cout<<"\n\n need matrix \n\n\t";

for(j=0;j<countofr;j++)

cout<<"R["<<j<<"] ";

cout<<endl;



for(i=0;i<countofp;i++)

{

 cout<<"P["<<i<<"]";

 for(j=0;j<countofr;j++)

 cout<<" "<<need[i][j];

 cout<<endl;

}

cout<<"\n now to check wheather above state is safe ";

cout<<"\n sequence in which above requests can be fullfilled";

cout<<"\n press any key to continue";

getch();

count = countofp;

for(i=0;i<countofp;i++)

{

 running[i]=1;

}

while(count)

{

 safe =0;

 for(i=0;i<countofp;i++)

 {

  if(running[i])

  {

   completed = 1;

   for(j=0;j<countofr;j++)

   {

    if(need[i][j]>available[j])

    {

     completed =0;

     break;

    }

   }

   if(completed)

   {

    running[i]=0;

    count--;

    safe = 1;

    for(j=0;j<countofr;j++)

    {

     available[j]+=allocation[i][j];

    }

    sequence[s++]=i;

    cout<<"\n\n running process P["<<i<<"]";

   cout<<endl<<"\n\n total resources now available \n\n";

   for(i=0;i<countofr;i++)

   cout<<"R["<<i<<"] ";

   cout<<endl;

   for(i=0;i<countofr;i++)

   cout<<" "<<available[i];

   break;

  

  

   }

  }

 }

 if(!safe)

break;



}

if(safe)

{

 cout<<"\n the system is in the safe state";

 cout<<"\n safe sequence is :";

 for(i=0;i<countofp;i++)

 {

  cout<<"\t"<<"P["<<sequence[i]<<"]";

  

 }

}

 else

 {

  cout<<"\n the system is in unsafe state";

 }

 

getch();



}
