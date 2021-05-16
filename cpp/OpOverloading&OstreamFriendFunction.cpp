#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box{
    int l, b, h;
    public:
    Box(){ l = 0, b = 0, h = 0; }
    Box(int length, int breadth, int height){ l = length, b = breadth, h = height; }
    Box(Box &B){ l = B.l, b = B.b, h = B.h; }
    int getLength(){ return l; }
    int getBreadth(){ return b; }
    int getHeight(){ return h; }
    long long CalculateVolume(){ return ((long long)l*b*h);}
    bool operator <(Box& x){
        if(l < x.l || (b < x.b && l == x.l) || (h < x.h && l == x.l && b == x.b)) return true;
        else return false;
    }
    friend ostream& operator <<(ostream& out, const Box &x);
};
ostream& operator <<(ostream& out, const Box &x){ out<<x.l<<" "<<x.b<<" "<<x.h; return out; }

// link for above data: https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/

void check2(){
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}



// ********** SAMPLE OUTPUT **********
// Box b1; // Should set b1.l = b1.b = b1.h = 0;
// Box b2(2, 3, 4); // Should set b2.l = 2, b2.b = 3, b2.h = 4;
// b2.getLength();	// Should return 2
// b2.getBreadth(); // Should return 3
// b2.getheight();	// Should return 4
// b2.CalculateVolume(); // Should return 24
// bool x = (b1 < b2);	// Should return true based on the conditions given
// cout<<b2; // Should print 2 3 4 in order.