#include<bits/stdc++.h>
using namespace std;

int minA()
{
	ifstream readFile("DMlab75_2.csv");
	
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
int maxA()
{
	ifstream readFile("DMlab75_2.csv");
	
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
double minmaxnormalization(string marks,int minA,int maxA,int newMinA,int newMaxA)
{
	stringstream obj;
	int value;
	obj<<marks;
	obj>>value;
	
	double ans = ( ((double)( value - minA)/(maxA - minA) ) * (newMaxA - newMinA) ) + newMinA;
	return ans;
}

double mean()
{
	ifstream readFile("DMlab75_2.csv");
	double ans;
	string marks;
	int sum = 0;
	int count = 0;
	int value;
	while(readFile.good())
	{
		getline(readFile,marks,'\n');
		
		stringstream obj;
	
		obj<<marks;
		obj>>value;
		
		sum = sum + value;
		count++;
	}
	ans  = (double)(sum-value)/(count-1);
	return ans;	
}

double standardDeviation()
{
	ifstream readFile("DMlab75_2.csv");
	int ans = 0;
	string marks;
	int value;
	int count=0;
	double meanValue = mean();
	while(readFile.good())
	{
		getline(readFile,marks,'\n');
		
		stringstream obj;
		obj<<marks;
		obj>>value;
		
		ans = ans + pow(value - meanValue,2);
		count++;
	}
	return sqrt((double)ans/ (count - 1));
}


double zScoreNormalization(string marks)
{
	int meanValue = mean();
	int sd = standardDeviation();
	int value;
	
	stringstream obj;
	obj<<marks;
	obj>>value;
	
	double ans = (double)(value - meanValue)/sd;
	return ans;
}
int main()
{
	ifstream readFile("DMlab75_2.csv");
	ofstream writeFile("DMlab75_2_output.csv");
	
	if(!readFile.is_open()) cout<<"ERROR : File Open"<<endl;
	
	
	string marks;
	
	int newMin;
	int newMax;
	
	int min = minA();
	int max = maxA();

	cout<<"Enter newMin : ";
	cin>>newMin;
	cout<<endl;
	
	cout<<"Enter newMax : ";
	cin>>newMax;
	cout<<endl;
	
	writeFile<<"Marks"<<","<<"Normalized Marks(Min-Max )"<<","<<"Normalized Marks (Z Score)"<<endl;
	while(readFile.peek()!=EOF)
	{
		getline(readFile,marks,'\n');
		writeFile << marks << "," << minmaxnormalization(marks,min,max,newMin,newMax)<<","<<zScoreNormalization(marks)<<endl;
	}
}
