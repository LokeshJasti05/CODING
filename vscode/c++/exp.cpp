#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float num1,num2;
    double resnum1,resnum2;
    cin>>resnum1;   
    cin>>resnum2;
    resnum1= static_cast<double>(num1);
    resnum2= static_cast<double>(num2);
    cout<<std::fixed<<std::setprecision(6)<<resnum1<<endl;
    cout<<std::fixed<<std::setprecision(6)<<resnum2<<endl;
	return 0;
}