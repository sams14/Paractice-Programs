#include <bits/stdc++.h>
#define num 1000000007
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'superFunctionalStrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
set<string> distinctSubstring(string str)
{
    set<string> result ;
    for (int i = 0; i <= str.length(); i++)
    {
        for (int j = 1; j <= str.length()-i; j++)
        {
            result.insert(str.substr(i, j));
        }
    }
    return result;
}
int couDist(string str){
    int count = 0;
    for (int i = 0; i < str.length(); i++){
        bool appears = false;
        for (int j = 0; j < i; j++){
            if (str[j] == str[i]){
                appears = true;
                break;
            }
        }
        if (!appears){
            count++;
        }
    }
    return count;
}
long long superFunctionalStrings(string s) {
    long long ans = 0;
    set<string> res = distinctSubstring(s);
    for(auto x:res){
        long long y = pow(double(x.length()), double(couDist(x)));
        ans += (y % num);
    }
    return (ans%num);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        long long result = superFunctionalStrings(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
