#include<bits/stdc++.h>
using namespace std;


int min()
{
	ifstream readFile("DMLab75_5.csv");
	
	int min=INT_MAX;
	string marks;
	while(readFile.good())
	{
		getline(readFile,marks,'\n');
		
		stringstream obj;
		int value;
		obj<<marks;
		obj>>value;
		if(min>value) min = value;
	}
	return min;
}
int max()
{
	ifstream readFile("DMLab75_5.csv");
	
	int max=INT_MIN;
	string marks;
	while(readFile.good())
	{
		getline(readFile,marks,'\n');
		stringstream obj;
		int value;
		obj<<marks;
		obj>>value;
		if(max<value) max = value;
	}
	return max;
}

double median()
{
	ifstream readFile("DMLab75_5.csv");
	vector<double> v;
	
	string str;
	while(readFile.good())
	{
		getline(readFile,str,'\n');
		stringstream obj;
		double value;
		obj<<str;
		obj>>value;
		v.push_back(value);
	}
	sort(v.begin(),v.end());
	int n = v.size();
	double ans;
	if(n%2==1)
	{
		ans = v[(double)(n+1)/2];
	}
	else
	{
		ans = (double)(v[n/2] + v[(n/2) + 1])/2;
	}
	return ans;
}

double quartile1()
{
	ifstream readFile("DMLab75_5.csv");
	vector<double> v;
	
	string str;
	while(readFile.good())
	{
		getline(readFile,str,'\n');
		stringstream obj;
		double value;
		obj<<str;
		obj>>value;
		v.push_back(value);
	}
	sort(v.begin(),v.end());
	int n = v.size();
	double ans = v[(double)(n+1)/4];
	
	return ans;
}

double quartile3()
{
	ifstream readFile("DMLab75_5.csv");
	vector<double> v;
	
	string str;
	while(readFile.good())
	{
		getline(readFile,str,'\n');
		stringstream obj;
		double value;
		obj<<str;
		obj>>value;
		v.push_back(value);
	}
	sort(v.begin(),v.end());
	int n = v.size();
	double ans = v[(double)(3*(n+1))/4];
	
	return ans;
}

int main()
{
	int maxVal = max();
	int minVal = min();
	double medianVal = median();
	double quartile1Val = quartile1();
	double quartile3Val = quartile3();
	
	ofstream writeFile("DMLab75_5_output.csv");

	writeFile << "," << "Max Value : " <<","<< maxVal<<endl;
	writeFile << "," << "Min Value : " <<","<< minVal<<endl;
	writeFile << "," << "Median : " << ","<<medianVal<<endl;
	writeFile << "," << "Quartile 1: " << ","<<quartile1Val<<endl;
	writeFile << "," << "Quartile 3: " << ","<<quartile3Val<<endl;
}
