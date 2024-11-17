#include<iostream>
#include<cmath>
using namespace std;
class Vector {
private:
	float x;
	float y;
public:
	Vector() {
		x = y = 0;
	}
	void setVector(float a, float b) {
		x = a;
		y = b;
	}
	Vector add(Vector a, Vector b) {
		Vector sum_result;
		sum_result.x = a.x + b.x;
		sum_result.y = a.y + b.y;
		return sum_result;
	}
	void print() {
		cout << "(" << x << "," << y << ")" << endl;
	}
	void print_x() {
		cout <<"x="<< x << endl;
	}
	void print_y() {
		cout <<"y="<< y << endl;
	}
	void dir() {
		float abs_x, abs_y,length;
		abs_x = abs(x);
		abs_y = abs(y);
		length = sqrt(abs_x * abs_x + abs_y * abs_y);
		cout << length << endl;
	}
};
int main() {
	Vector a, b, c;
    float x1,y1,x2,y2;
    string inputdata;
    cin>>inputdata;
    int elenum=1;
    int k=0;
    if (inputdata[k]<=9 && inputdata[k]>=0 && k<=inputdata.size())
        {
            switch (elenum)
            {
            case 1:{
                x1=x1*10+inputdata[k];
                break;}
            case 2:{
                y1=y1*10+inputdata[k];
            }
            case 3:{
                x2=x2*10+inputdata[k];
                break;}
            case 4:{
                y2=y2*10+inputdata[k];
            }
            default:
                break;
            }
            k++;
        
            
        }
        else{
            k++;
        }
    a.setVector(x1, y1);
	b.setVector(x2, y2);
    c.setVector(0,0);
    c.add(a,b);
    cout<<"向量之和: "<<endl;
    c.print_x();
    cout<<","<<endl;
    c.print_y();
    cout<<"\n模长"<<endl;
    c.dir();
    a.print_x();
}

    
