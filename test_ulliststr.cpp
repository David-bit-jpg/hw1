#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "ulliststr.h"
using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main()
{
  ULListStr dat;
  dat.push_back("7");
  dat.push_front("8");
  dat.push_back("9");
  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
  // prints: 8 7 9
  // dat.pop_front();
  // cout << dat.get(0) << " " << dat.get(1) << endl;
  // //7 9
  // // cout<<dat.front()<<"front "<<endl;
  // // cout<<dat.back()<<"back "<<endl;
  // dat.pop_front();
  // cout << dat.get(0) << endl;
  // //9
  dat.pop_back();
  cout<<"困了"<<endl;
  cout << dat.get(0) << " " << dat.get(1) << endl;
  //8 7
  // cout<<dat.front()<<"front "<<endl;
  // cout<<dat.back()<<"back "<<endl;
  dat.pop_back();
  cout << dat.get(0) << endl;
  //8
  cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
}
