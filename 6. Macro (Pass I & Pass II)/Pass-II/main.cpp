#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class pass_II
{
    struct MNT
    {
        int MNTC;
        string macroName;
        int MDTC;
    };
    
    struct MDT
    {
        int MDTC;
        string statement;
    };
    
    int mnt_c = 2;
    int mdt_c = 4;
    MNT mnt[2]= {{ 0 , "ABC" , 0} , { 1 ,  "mno" , 2}};
    MDT mdt[4]= {{ 0 , "movem areg, a"} , { 1 , "mend"} , { 2 , "add areg, a"} , { 3 , "mend"}};
    
    
    
  public:
    void generatePassIIOutput();
    void printMNT();
    void printMDT();
};

void pass_II::generatePassIIOutput()
{
    fstream fr , fw;
    string buffer;
    
    fr.open("input.dat" , fstream::in);
    fw.open("output.dat", fstream::out);

    while(!fr.eof())
    {
        bool isMacro = false;
        // Check for macro , start , end , imperative statement
        fr>>buffer;
        for(int i=0;i<mnt_c;i++)
        {
            if(buffer == mnt[i].macroName)
            {
                int j = mnt[i].MDTC ;
                isMacro = true;
                do
                {
                    fw<<mdt[j].statement<<endl;
                    j++;
                }while(mdt[j].statement!= "mend");
                break;
            }
        }
        
        if(!isMacro)
        {
            if(buffer == "start")
            {
                fw<<buffer<<" ";
                fr>>buffer;
                fw<<buffer<<"\n";
            }
            else if(buffer == "end")
            {
                fw<<buffer<<endl;
                break;
            }
            else
            {
                fw<<buffer<<" ";
                fr>>buffer;
                fw<<buffer<<" ";
                fr>>buffer;
                fw<<buffer<<endl;
            }
        }
        
    }
    
    
    
    
    fr.close();
    fw.close();
    
}

void pass_II::printMNT()
{
    cout<<endl;
    cout<<"Macro Name Table:- \n";
    cout<<"-------------------------------------------"<<endl;
    cout<<"MNTC \tMacro Name \tMDTC \n";
    for(int i=0;i<mnt_c;i++)
    {
        cout<<mnt[i].MNTC<<"\t"<<mnt[i].macroName<<"\t"<<mnt[i].MDTC<<endl;
    }
}

void pass_II::printMDT()
{
    cout<<endl;
    cout<<"Macro Definition Table:- \n";
    cout<<"-------------------------------------------"<<endl;
    cout<<"MDTC \tMacro Definition  \n";
    for(int i=0;i<mdt_c;i++)
    {
        cout<<mdt[i].MDTC<<"\t"<<mdt[i].statement<<endl;
    }
}


int main()
{
    pass_II obj;
    obj.printMNT();
    obj.printMDT();
    obj.generatePassIIOutput();
    
}
