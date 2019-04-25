#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double findMean (vector<double> nums) {
  double n = nums.size();
  double sum = 0;
  for (int i=0; i<nums.size(); i++) {
    sum += nums.at(i);
  }

  sum = sum/n;
  return sum;
}

double findVariance (vector<double> nums) {
  double n = nums.size();
  double mean = findMean(nums);
  double sum = 0;

  for (int i=0; i<nums.size(); i++) {
    double num = pow((nums.at(i) - mean), 2);
    sum += num;
  }

  sum = sum/(n-1);
  return sum;
}

int main () {

  cout << "Welcome to Stats Saver" << endl;

  cout << "Select what you want to do" << endl;

  vector<double> nums = {1,2,3,4,5,6};

  double sum = findVariance(nums);
  cout << "Sum: " << sum << endl;

  return 0;
}
