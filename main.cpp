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

  cout << "\nThe mean of " << printVector(nums) << " is: " << Mean(nums) << "\n\n";
}

void findVariance() {
  string response;
  vector<double> nums;
  cout << "\nFind Variance" << endl;
  cout << "Enter the numbers you want to calculate (seperate by whitespace)" << endl;
  getline(cin, response);
  nums = determineVector(response);

  cout << "\nThe variance of " << printVector(nums) << " is: " << Variance(nums) << "\n\n";
}

void findDeviation() {
  string response;
  vector<double> nums;
  cout << "\nFind Deviation" << endl;
  cout << "Enter the numbers you want to calculate (seperate by whitespace)" << endl;
  getline(cin, response);
  nums = determineVector(response);

  cout << "\nThe deviation of " << printVector(nums) << " is: " << Deviation(nums) << "\n\n";
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
    else  {
      cout << "Not an option, try again...\n" << endl;
    }
  }
}

int main () {
  decideFunction();

  return 0;
}
