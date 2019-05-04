#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

double Mean (vector<double> nums) {
  double n = nums.size();
  double sum = 0;
  for (int i=0; i<nums.size(); i++) {
    sum += nums.at(i);
  }

  sum = sum/n;
  return sum;
}

double Variance (vector<double> nums) {
  double n = nums.size();
  double mean = Mean(nums);
  double sum = 0;

  for (int i=0; i<nums.size(); i++) {
    double num = pow((nums.at(i) - mean), 2);
    sum += num;
  }

  sum = sum/(n-1);
  return sum;
}

double Deviation (vector<double> nums)  {
  double answer = Variance(nums);
  answer = sqrt(answer);
  return answer;
}

double factorial (double num) {
  if (num == 0) {
    return 1;
  }

  double sum = num;
  num--;
  for (num; num>0; num--) {
    sum *= num;
  }
  return sum;
}

double Binomial (double x, double n, double p)  {
  // Combination
  double top = factorial(n);
  double bottom = factorial(n-x) * factorial(x);
  double combination = top/bottom;

  // p and q
  double pExp = pow(p,x);
  double qExp = pow( (1-p), n-x);

  double answer = combination * pExp * qExp;
  return answer;
}

double BinomialExpected (double n, double p)  {
  return n*p;
}

double Geometric (double x, double p) {
  double fistPart = pow((1 - p), (x-1));
  double answer = fistPart * p;
  return answer;
}

template <class T>
string printVector(vector<T> nums)  {
  string response = "";
  response += "[ ";
  for (int i=0; i<nums.size(); i++) {
    ostringstream strs;
    strs << nums.at(i);
    string str = strs.str();
    response += str;
    response += " ";
  }
  response += "]";
  return response;
}

vector<double> determineVector(string response) {
  vector<double> nums;
  string delim = " ";
  auto start = 0U;
  auto end = response.find(delim);
  while (end != std::string::npos)
  {
      string token = response.substr(start, end - start);
      double num = stod(token);
      nums.push_back(num);
      start = end + delim.length();
      end = response.find(delim, start);
  }
  string token = response.substr(start, end);
  double num = stod(token);
  nums.push_back(num);
  return nums;
}

void findMean() {
  string response;
  vector<double> nums;
  cout << "\nFind Mean" << endl;
  cout << "Enter the numbers you want to calculate (seperate by whitespace)" << endl;
  getline(cin, response);
  nums = determineVector(response);

  cout << "\nThe mean of " << printVector(nums) << " is: " << Mean(nums) << "\n";
  cout << "With the size of n = " << nums.size() << "\n\n";
}

void findVariance() {
  string response;
  vector<double> nums;
  cout << "\nFind Variance" << endl;
  cout << "Enter the numbers you want to calculate (seperate by whitespace)" << endl;
  getline(cin, response);
  nums = determineVector(response);

  cout << "\nThe variance of " << printVector(nums) << " is: " << Variance(nums) << "\n";
  cout << "With the size of n = " << nums.size() << "\n\n";
}

void findDeviation() {
  string response;
  vector<double> nums;
  cout << "\nFind Deviation" << endl;
  cout << "Enter the numbers you want to calculate (seperate by whitespace)" << endl;
  getline(cin, response);
  nums = determineVector(response);

  cout << "\nThe deviation of " << printVector(nums) << " is: " << Deviation(nums) << "\n";
  cout << "With the size of n = " << nums.size() << "\n\n";
}

void findBinomial() {
  string response;
  double xVal;
  double nVal;
  double pVal;

  cout << "\nFind Binomial Distribution" << endl;
  cout << "Enter x value: " << endl;
  getline(cin, response);
  xVal = stod(response);

  cout << "\nEnter n value: " << endl;
  getline(cin, response);
  nVal = stod(response);

  cout << "\nEnter p value: " << endl;
  getline(cin, response);
  pVal = stod(response);
  cout << "\n";

  cout << "Value for binomial distribution is : " << Binomial(xVal, nVal, pVal) << "\n\n";
  cin.clear();
}

void findBinomialExpected()  {
  string response;
  double nVal;
  double pVal;

  cout << "\nFind Binomial Expected Value" << endl;
  cout << "\nEnter n value: " << endl;
  getline(cin, response);
  nVal = stod(response);
  
  cout << "\nEnter p value: " << endl;
  getline(cin, response);
  pVal = stod(response);
  cout << "\n";

  cout << "Value for expected value is: " << BinomialExpected(nVal, pVal) << "\n\n";
  cin.clear();
}

void findGeometric()  {
  string response;
  double xVal;
  double pVal;

  cout << "Enter x value: " << endl;
  getline(cin, response);
  xVal = stod(response);
  cout << "\nEnter p value: " << endl;
  getline(cin, response);
  pVal = stod(response);
  cout << "\n";

  cout << "Value for Geometric Distribution is: " << Geometric(xVal, pVal) << "\n\n";
  cin.clear();
}

void decideFunction() {
  string response;
  while(true)  {
    response = "";

    cout << "Welcome to Stats Saver" << endl;

    cout << "Select what you want to do" << endl;
    cout << "1 - Mean" << endl;
    cout << "2 - Variance" << endl;
    cout << "3 - Deviation" << endl;
    cout << "4 - Binomial Distribution" << endl;
    cout << "5 - Binomial Expected Value" << endl;
    cout << "6 - Geometric Distribution" << endl;
    cout << "0 - Quit" << endl;

    getline(cin, response);

    if (response.compare("0") == 0)  {
      break;
    }
    else if (response.compare("1") == 0)  {
      findMean();
    }
    else if (response.compare("2") == 0)  {
      findVariance();
    }
    else if (response.compare("3") == 0)  {
      findDeviation();
    }
    else if (response.compare("4") == 0)  {
      findBinomial();
    }
    else if (response.compare("5") == 0)  {
      findBinomialExpected();
    }
    else if (response.compare("6") == 0)  {
      findGeometric();
    }
    else  {
      cout << "Not an option, try again...\n" << endl;
    }

    cin.clear();
  }
}

int main () {
  decideFunction();

  return 0;
}
