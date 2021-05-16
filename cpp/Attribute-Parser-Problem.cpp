#include <bits/stdc++.h>
using namespace std;

function getMap(vector<string> hrml, int n){
    map<string, string> m;
    string temp;
    vector<string> t;
    for(int i=0;i<n;i++)
    {
        temp=hrml[i];
        temp.erase(remove(temp.begin(), temp.end(), '\"' ),temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '>' ),temp.end());
        if(temp.substr(0,2)=="</")
        {
            t.pop_back();
        }
        else
        {
            stringstream ss;
            ss.str("");
            ss<<temp;
            string t1,a,val;
            char ch;
            ss>>ch>>t1>>a>>ch>>val;
            string T1="";
            if(t.size()>0)  T1=*t.rbegin()+"."+t1;
            else
                T1=t1;
            t.push_back(T1);
            m[*t.rbegin()+"~"+p1]=val;
            while(ss)
            {
                ss>>a>>ch>>val;
                m[*t.rbegin()+"~"+p1]=v1;
            }
        }
    }
    return m;
}

int main() {
    int n, q;
    string temp;
    cin>>n>>q;
    cin.ignore();
    vector<string> hrml;
    vector<string> qry;
    for(int i=0; i<n; i++){
        getline(cin, temp);
        hrml.push_back(temp);
    }
    for(int i=0; i<q; i++){
        getline(cin, temp);
        qry.push_back(temp);
    }
    map<string, string> m = getMap(hrml, n);
    for(int i=0;i<q;i++){
        if (m.find(qry[i]) == m.end())
            cout << "Not Found!"<<endl;
        else
            cout<<m[qry[i]]<<endl;
    }
    return 0;
}
