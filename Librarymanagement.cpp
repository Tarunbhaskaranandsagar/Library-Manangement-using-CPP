#include<bits/stdc++.h>
#include<string.h>
using namespace std;

map<string,int> books;
int totalbooks=0;
bool isprime=false;

void trim(string &s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            s.erase(i,1);
        }
        else
        {
            break;
        }
    }
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]==' ')
        {
            s.erase(i,1);
        }
        else
        {
            break;
        }
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            if(s[i+1]==' ')
            {
                s.erase(i,1);
            }
        }
    }
}

void mainmenu()
{
    cout<<"Choose From The Give Option"<<endl;
    cout<<"1 : Add A Book"<<endl;
    cout<<"2 : Checkout A Boook"<<endl;
    cout<<"3 : Total Book Available"<<endl;
    cout<<"4 : Search For A Book"<<endl;
    cout<<"5 : Total Stock Available"<<endl;
    cout<<"6 : Take Prime Membership"<<endl;
    cout<<"7 : Exit"<<endl;
}
void case1()
{
    string s;
    int a;
    cout<<"Enter The Exact Name Of the book To add"<<endl;
    cin.ignore();
    getline(cin, s);
    for(auto &x : s)
    {
        x=tolower(x);
    }
    trim(s);
    cout<<"Quantity Of Book"<<endl;
    cin>>a;
    if(books.find(s)!=books.end())
    {
        books[s]+=a;
    }
    else
    books.insert({s,a});
    if(a>0 and s.size()!=0)
    {
        cout<<"Book successfully added"<<endl;
        totalbooks+=a;
    }
    else
    {
        cout<<"Some error Happened"<<endl;
    }
}
void case2()
{
    string s;
    int a;
    cout<<"Check A Book To Chekout"<<endl;
    cin.ignore();
    getline(cin, s);
    trim(s);
    for(auto &x : s)
        x=tolower(x);
    cout<<"Quantity Of Book To Checkout"<<endl;
    cin>>a;
    if(books.find(s)!=books.end())
    {
        if(a<=books[s])
        {
            cout<<"Books successfully Withdraw"<<endl;
            books[s]-=a;
            totalbooks-=a;
            if(books[s]==0)
            {
                books.erase(s);
            }
        }
        else
        {
            cout<<"Books Sortage"<<" "<<books[s]<<" "<<"Books available only"<<endl;
        }
    }
    else
    {
        cout<<"Book Unavailable"<<endl;
        cout<<"Here What we find closest"<<endl;
        int i=1;
        for (auto it = books.begin();it != books.end(); ++it)
        {
            if(it->first.find(s) != string::npos)
            {
                cout<<i<<": Book : "<<it->first<<endl;
                cout<<"Quantity : "<<it->second<<endl;
                cout<<endl;
                i++;
            }
            else
            {
                continue;
            }
        }
        if(i==1) cout<<"Nothing Mathes"<<endl;
        else
        {
            case2();
        }

    }
}
void case3()
{
    cout<<"Total Number Of Books Availabele : "<<totalbooks<<endl;
}
void case4()
{
    string s;
    cin.ignore();
    getline(cin,s);
    trim(s);
    for(auto &x : s)
        x=tolower(x);
    int i=1;
    for (auto it = books.begin();it != books.end(); ++it)
    {
        if(it->first.find(s) != string::npos)
        {
            if(it->second!=0)
            {
                cout<<i<<": Book : "<<it->first<<endl;
                cout<<"Quantity : "<<it->second<<endl;
                cout<<endl;
                i++;
            }
        }
        else
        {
            continue;
        }
    }
    if(i==1)
    {
        cout<<"No Result Found"<<endl;
    }
}
void case5()
{
    //Total Stock Available
    int i=1;
    for (auto it = books.begin();it != books.end(); ++it)
    {
        cout<<i<<": Book : "<<it->first<<endl;
        cout<<"Quantity : "<<it->second<<endl;
        cout<<endl;
        i++;
    }
    if(i==1)
    {
        cout<<"Stock Empty"<<endl;
    }
}
void case6()
{
    if(isprime)
    {
        cout<<"You are a Prime Member Already"<<endl;
    }
    else
    {
        string s;
        cout<<"Get Prime : Write \"BUY\" to Buy prime"<<endl;
        cin>>s;
        for(auto &x : s)
            x=tolower(x);
        if(s=="buy")
        {
            cout<<"Now You are a Prime Member"<<endl;
            isprime=true;
        }
    }
}
int main()
{
    cout<<"Welcome To TSK Library"<<endl;
    bool running = true;
    while(running)
    {
        mainmenu();
        int a;
        cin>>a;
        if(a==1)
        {
            case1();
        }
        else if(a==2)
        {
            if(isprime)
            case2();
            else
            {
                cout<<"Take Prime Memebership To Withdraw"<<endl;
                cout<<"Press \'6\' to take prime or any other key to cancel"<<endl;
                int b;
                cin>>b;
                if(b==6)
                {
                    case6();
                }
                else
                {
                    continue;
                }
            }
        }
        else if(a==3)
        {
            case3();
        }
        else if(a==4)
        {
            case4();
        }
        else if(a==5)
        {
            case5();
        }
        else if(a==6)
        {
            case6();
        }
        else
        {
            running = false;
        }
    }
}
