#include<bits/stdc++.h>
using namespace std;
vector<double> mean(vector<vector<string>> v)
{
    vector<double> means;
    for(int j=0;j<v[0].size();j++)
    {
        double sum=0;
        for(int i=1;i<v.size();i++)
        {
            sum = sum + stoi(v[i][j]);
        }
        double meanVal = sum/(v.size()-1);
        means.push_back(meanVal);
    }
    return means;
}
 
vector<double> std_dev(vector<vector<string>> v,vector<double> means)
{
    vector<double> std_devi;
    for(int j=0;j<v[0].size();j++)
    {
        double sd = 0;
        for(int i=1;i<v.size();i++)
        {
            sd = sd + pow((stoi(v[i][j]) - means[j]), 2);
        }
       
        sd = (double)sd / (v.size()-2);
        sd = sqrt(sd);
       
        std_devi.push_back(sd);
    }
   
    return std_devi;
}
 
 
int main()
{
    ifstream readFile("DMLab75_8.csv");
   
    string a,b;
    vector<vector<string>> v;
    while(readFile.peek()!=EOF)
    {
        getline(readFile,a,',');
        getline(readFile,b,'\n');
       
        vector<string> row;
        row.push_back(a);
        row.push_back(b);
        v.push_back(row);
    }
   
    /*
    formula : Gamma_ab = Summation((A-MeanA)*(B-MeanB))/((n-1)*(SigmaA*SigmaB))
    */
   
    vector<double> means = mean(v);
    double meanA = means[0];
    double meanB = means[1];
   
    vector<double> sd = std_dev(v,means);
    double SigmaA = sd[0];
    double SigmaB = sd[1];
   
    double summation = 0;
    for(int i=1;i<v.size();i++)
    {
        summation = summation + ( (stoi(v[i][0]) - meanA) * (stoi(v[i][1]) - meanB));
    }
   
    int gamma_ab = summation/((v.size()-1)*(SigmaA*SigmaB));
   
   
    ofstream writeFile("DMLab75_8_output.csv");
   
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            writeFile<<v[i][j]<<',';
        }
        writeFile<<endl;
    }
   
    writeFile<<endl;
    writeFile<<"Coefficient of Co-Relation is "<<','<<gamma_ab<<endl;
   
    if(gamma_ab==1)
    writeFile<<"Type of Co-Relation is Possitive Co-Relation"<<endl;
    else if(gamma_ab==0)
    writeFile<<"There is No Co-Relation"<<endl;
    else if(gamma_ab==-1)
    writeFile<<"Type of Co-Relation is negative Co-Relation"<<endl;
}
 


