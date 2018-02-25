/*
    Data Compression Course - 3rd Computer Engineering, Shoubra Faculty of Engineering
    Assignment 1!
    Group Names : Mai Mahmoud Hegazy
                  Huda Atta
                  Nehal Taha

    Front Compression for Names List -- Compression File --
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
string  RemoveSpace(string str);
int CountNumOfNames(ifstream &file);
vector<string> GetNamesFromFile(ifstream &file,int size);
int CountSimilarCharcters(string str1,string str2);
string IntToString (int num);
string NameCompressed (int cnt, string str);
void CompressedToFile(ofstream &file, string Arr[],int size);
//string RemoveIfZero (string str);
int main()
{
    ifstream NameList ("NameList.txt");
    ofstream Out ("output.txt");
    int filesize= CountNumOfNames(NameList);
    vector <string> NamesWithSpace ;
    NamesWithSpace = GetNamesFromFile(NameList,filesize);
    string Compressed[filesize+2];
    for(int i=0;i<NamesWithSpace.size();i++)
    {
        string str1 = RemoveSpace(NamesWithSpace[i]);
        Compressed[i]=str1;
    }

    for(int j=1;j<filesize+1;j++)
      {
        string sr ;
        int CSC = CountSimilarCharcters(Compressed[j],Compressed[j+1]);
        Compressed[j]= NameCompressed(CSC,Compressed[j+1]);

      }
      for (int k=0; k<filesize-1;k++)
      {
       // Compressed[k]= RemoveIfZero (Compressed[k]);
        cout << Compressed[k] << endl;
      }

     CompressedToFile(Out,Compressed,filesize);

    return 0;
}
string RemoveSpace(string str)
{
 int size = str.length();
    for(int j = 0; j<=size; j++)
    {
        for(int i = 0; i <=j; i++)
        {
            if(str[i] == ' ' )
            {
                str.erase(str.begin() + i);
            }
        }
    }
    return str;
}
int CountNumOfNames(ifstream &file)
{
    string Name;
    int i=0;
    if (file.is_open())
    {
        while (!file.eof())
    {
      getline(file,Name);
      i++;
    }
  }
  else cout << "Unable to open file";
  file.seekg(0); // seek to the first character in the file
  return i;
}
vector<string> GetNamesFromFile(ifstream &file, int size)
{
  int j=0;
  vector <string> Names;
  string Name;
  if (file.is_open()){
  while (getline(file, Name))
  {
      Names.push_back(Name);
      j++;
  }
  }
  else cout << "ERROR";
  return Names;
}
int CountSimilarCharcters(string str1,string str2)
{
     int count =0;

    while (str1[count] == str2[count])
        {
            count++;
        }
    return count;
}
void CompressedToFile(ofstream &file ,string Arr[],int size)
{
    for (int i=0;i<size-1;i++)
  {
      file << Arr[i] << endl;
  }
  file.close();
}

string IntToString (int num)
 {
    string str;
    stringstream ss;
    ss << num;
    ss >> str;
    return str;
}

string NameCompressed (int cnt, string str)
{
    str.replace(0,cnt,IntToString (cnt));
    return str;
}

/*string RemoveIfZero (string str)
{
 int size = str.length();
    for(int j = 0; j<=size; j++)
    {
        for(int i = 0; i <=j; i++)
        {
            if(str[i] == '0' )
            {
                str.erase(str.begin() + i);
            }
        }
    }
    return str;
}*/
