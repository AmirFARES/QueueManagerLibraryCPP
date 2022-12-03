#include <iostream>

using namespace std;

//structures _____________________________
typedef struct Liste
{
    int val;
    Liste *suiv;
}Liste;

typedef struct File
{
    Liste *l;
    Liste *quee;
}File;

//Prototype ______________________________
File Enfiler (File fa,int v);
File Defiler(File fa,int *v);
bool FileVide(File fa);

int main()
{
    File file;
    file.l=NULL;
    int v;
    for(int i=0;i<5;i++)
    {
        cin >> v;
        file=Enfiler(file,v);
    }
    cout << "Defiler :" << endl;
    for(int i=0;i<5;i++)
    {
        file=Defiler(file,&v);
        cout << v <<endl;
    }
    return 0;
}

//functions ______________________________
File Enfiler (File fa,int v)
{
    Liste *ptr=new Liste;
    ptr->val=v;
    ptr->suiv=NULL;
    if(FileVide(fa))
    {
        fa.l=ptr;
    }
    else
    {
        fa.quee->suiv=ptr;
    }
    fa.quee=ptr;
    return(fa);
}

File Defiler(File fa,int *v)
{
    Liste *ptr = fa.l;
    fa.l = fa.l->suiv;
    *v = ptr->val;
    delete ptr;
    return(fa);
}

bool FileVide(File fa)
{
    return(fa.l==NULL);
}
