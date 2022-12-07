#include<bits/stdc++.h>
using namespace std;

void calculateProbability(vector<vector<string>> matrix,vector<double> & probabilities)
{
	int m = matrix.size();
	int n = matrix[0].size();
	probabilities.push_back(-1);

	for(int i=1;i<n;i++)
	{
		int one=0;
		for(int j=1;j<m;j++)
		{
			if(matrix[j][i]=="1") one++;
		}
		
		double probability = (double)one/(m-1);
		
		probabilities.push_back(probability);
	}
}
double entropy(double probability)
{
	if(probability==0) return 0;
	return -1*( probability*log2(probability));
}
pair<double,double> splitProbability(vector<vector<string>> matrix,int parentNo,vector<pair<double,double>> & splitProbabilities)
{
	int m = matrix.size();
	int n = matrix[0].size();
	splitProbabilities.push_back({-1,-1});
	
	for(int i=1;i<n;i++)
	{
		int one=0;
		int onematched = 0;
		int zero=0;
		int zeromatched=0;
		for(int j=1;j<m;j++)
		{
			if(matrix[j][i]=="1")
			{
				 if(matrix[parentNo][i]=="1")
				 onematched++;
				 
				 one++;
			}
			if(matrix[j][i]=="0")
			{
				 if(matrix[parentNo][i]=="0")
				 zeromatched++;
				 
				 zero++;
			} 
		}
		double oneProbability = (double)onematched/one;
		double zeroProbability = (double)zeromatched/zero;
		splitProbabilities.push_back({oneProbability,zeroProbability}); 
	}
}
int main()
{
	ifstream readFile("DMLab75_3.csv");
	vector<vector<string>> v;
	string name;
	string coep;
	string wce;
	string vjti;
	while(readFile.peek()!=EOF)
	{
		getline(readFile,name,',');
		getline(readFile,coep,',');
		getline(readFile,wce,',');
		getline(readFile,vjti,',');
		
		vector<string> row;
		row.push_back(name);
		row.push_back(coep);
		row.push_back(wce);
		row.push_back(vjti);
		
		v.push_back(row);
	}
	
	int parentNo;
	cout<<"Enter column no to choose attribute as parent :";
	cin>>parentNo;
	
	double entropyParent = 1;
	
	vector<double> probabilities;
	calculateProbability(v,probabilities);
	
	vector<pair<double,double>> splitProbabilities;
	splitProbability(v,parentNo,splitProbabilities);
	
	vector<pair<double,double>> entropies;
	entropies.push_back({-1,-1});
	for(int i=1;i<splitProbabilities.size();i++)
	{
		double e1 = (double)entropy(splitProbabilities[i].first);
		double e2 = (double)entropy(splitProbabilities[i].second);
		entropies.push_back({e1,e2});
	}
	
	vector<pair<double,double>> result;
	for(int i=1;i<entropies.size();i++)
	{
		result.push_back({probabilities[i]*entropies[i].first,(i-probabilities[i])*entropies[i].second});
	}
	
	vector<double> infogain;
	infogain.push_back(-1);
	for(int i=1;i<result.size();i++)
	{
		infogain.push_back(entropyParent - result[i].first - result[i].second);
	}
	
	ofstream writeFile("DMLab75_3_output.csv");
	
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[0].size();j++)
		{
			writeFile << v[i][j] << ",";
		}
	}
	
	writeFile<< "\n"<<"Info Gain" << ","; 
	
	for(int i=1;i<infogain.size();i++)
	{
		writeFile << infogain[i] << ",";
	}
	
}
