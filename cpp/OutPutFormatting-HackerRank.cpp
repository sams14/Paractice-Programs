#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        //A : Strip its decimal (i.e., truncate it) and print its hexadecimal representation (including the Ox prefix) in lower case letters.
        printf("%#lx\n",(long long)A);
        //cout<<hex<<left<<showbase<<nouppercase<<(long long)A<<endl; //another way

        //B : Print it to a scale of 2 decimal places, preceded by a + or - sign (indicating if it's positive or negative), right justified, and left-padded with underscores so that the printed result is exactly  characters wide.
        printf("%.*s%+.2f\n",15 - to_string((int)B).length() - 4,"_______________",B);
        //cout<<dec<<right<<setw(15)<<setfill('_')<<showpos<<fixed<<setprecision(2)<<B<<endl;  //another way

        //C : Print it to a scale of exactly nine decimal places, expressed in scientific notation using upper case.
        printf("%.9E\n",C);
        //cout<<scientific<<uppercase<<noshowpos<<setprecision(9)<<C<<endl;   //another way


        // however printf() methods are faster than usage of cout<<
	}
	return 0;

}