#include<iostream>
#include<fstream>
#include <string.h>
using namespace std;

int main()
{
char x[100],var[1000000];
int gil=0,st_2pct=1,prim=1,i,dim,dimm=0,poz=0;

ifstream in("convertor.in");
ofstream out("convertor.out");

while(in>>x)
    {
    if(gil%2!=0 && st_2pct==0 &&prim==1)
        {
        var[poz]=' ';
        poz++;
        }
    if(gil%2!=0 && st_2pct==0 && prim==0) out.write(" ",1);
    if(gil%2!=0 && st_2pct==1 && prim==1) out.write(" ",1);

    dim=strlen(x);
    for(i=0;i<dim;i++ )
        {
        if(x[i]==':') st_2pct=0;
        if(x[i]==',') st_2pct=1;
        if(x[i]=='"') gil++;

    if(prim==0 && dimm==0)
        {
        out<<','<<"\n"<<var;
        dimm++;
        }

    if(st_2pct==0 && prim==1&&x[i]!='"' && x[i]!=':' && x[i]!='{' && x[i]!='}' && x[i]!=']' && x[i]!='[')
        {
        var[poz]=x[i];
        poz++;
        }
    if(st_2pct==1 && prim==1 && x[i]!='"' && x[i]!=':' && x[i]!='{' && x[i]!='}' && x[i]!=']' && x[i]!='[')
        out.write(x+i,1);
    if(st_2pct==0 && prim==0 && x[i]!='"' && x[i]!=':' && x[i]!='{' && x[i]!='}' && x[i]!=']' && x[i]!='[')
        out.write(x+i,1);

    if(x[i]==','&& prim==1)
        {
        var[poz]=x[i];
        poz++;
        }
    if(x[i]==','&& prim==0)
        out.write(x+i,1);

    if(x[i]=='{' && prim!=1)
        out.write("\n",1);
    else if(x[i]=='}')prim=0;
         else if(x[i]==']')out.write(",",1);
        }
    }
return 0;
}

