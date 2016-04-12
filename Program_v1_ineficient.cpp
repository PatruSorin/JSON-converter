#include<iostream>
#include<stdio.h>
#include<fstream>
#include <string.h>
using namespace std;

int main()
{char x[20];
ifstream in("convertor.in");
ofstream out("convertor.out");
int gil=0,st_2pct=1,prim=1,i,dim;

while(in>>x)
    {
        if(gil%2!=0 && st_2pct==1)  //pune spatii intre cuvinele din gilimele "pt hipsteri si chestii"
        out<<" ";
        dim=strlen(x);
     for(i=0;i<dim;i++ )
        {
        if(x[i]==':')
            st_2pct=0;
        if(x[i]==',')
            {
            st_2pct=1;
            }
        if(x[i]=='"')
            gil++;
                    if(st_2pct==1)
                        if(x[i]!='"' && x[i]!=':' && st_2pct==1 &&x[i]!='{'&&x[i]!='}'&&x[i]!=']'&&x[i]!='[')
                            out<<x[i];
                  // else
                   // {in>>x;}

        if(x[i]=='{' && prim!=1) //trece pe randul urmator cand intalneste }
            {
            in.clear();
            in.seekg(0, ios::end);
            i=dim;

            } else if(x[i]=='{')prim=0;
                else if(x[i]==']')out<<",";
        }
    }out<<"\n";
in.clear();
in.seekg(0, ios::beg);
prim=1;
st_2pct=1;
while(in>>x)
    {
        if(gil%2!=0 && st_2pct==0)  //pune spatii intre cuvinele din gilimele "pt hipsteri si chestii"
        out<<" ";
        dim=strlen(x);
     for(i=0;i<dim;i++ )
        {
        if(x[i]==':')
            st_2pct=0;
        if(x[i]==',')
            {
            st_2pct=1;
            }
                    if(x[i]=='"')
                        gil++;
                    if(x[i]!='"' && x[i]!=':' && st_2pct==0 &&x[i]!='{'&&x[i]!='}'&&x[i]!=']'&&x[i]!='[')
                        out<<x[i];

                    if(x[i]==',')
                        out<<x[i];
         if(x[i]=='{' && prim!=1) //trece pe randul urmator cand intalneste }
            {
            out<<"\n";
            } else if(x[i]=='{')prim=0;
        }
    }
out<<",";
return 0;
}
