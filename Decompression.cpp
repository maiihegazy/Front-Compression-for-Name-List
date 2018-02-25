/*
    Data Compression Course - 3rd Computer Engineering, Shoubra Faculty of Engineering
    Assignment 1!
    Group Names : Mai Mahmoud Hegazy
                  Huda Atta
                  Nehal Taha

    Front Compression for Names List -- Decompression File --
*/
#include <iostream>
#include <ctype.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
string  AddSpace(string str);
int CountNumOfNames(ifstream &file);
vector<string> GetNamesFromFile(ifstream &file, int size);
string NameDecompressed (int cnt, string str, string str1);
int GetFristCharOfString (string str);
void CompressedToFile(ofstream &file ,string Arr[],int size);
int main()
{
    ifstream Compressed ("Compressed.txt");
    ofstream Decompressed ("Decompressed.txt");
    int fileSize = CountNumOfNames(Compressed);
    vector <string> CompressedNames;
    string DecompressedNames [fileSize];
    CompressedNames = GetNamesFromFile(Compressed,fileSize);
   for (int i=0 ; i < CompressedNames.size()-1;i++)
    {
        int count = GetFristCharOfString(CompressedNames[i+1]);
        if (count < 10 )
        {
            CompressedNames[i+1].erase(0,1);

        }
        else
        {
            CompressedNames[i+1].erase(0,2);
        }
        string Str1 = CompressedNames[i];
        string Rep = Str1.erase(count);
        CompressedNames[i+1].insert(0,Rep);
        DecompressedNames [i] = AddSpace(CompressedNames[i+1]);
        cout << DecompressedNames[i] << endl;
        CompressedToFile(Decompressed ,DecompressedNames,fileSize);
    }
    return 0;
}
string AddSpace(string str)
{
 int size = str.length();

        for(int i = 1; i <=size; i++)
        {
            if(isupper(str[i]) )
            {
                str.insert(i," ");
                i++;
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
  vector <string> Names;
  string Name;
  if (file.is_open()){
  while (!file.eof())
  {
      getline(file, Name);
      Names.push_back(Name);

  }
  }
  else cout << "ERROR";
  return Names;
}
string NameDecompressed (int cnt, string str, string str1)
{
    str.replace(0,cnt,str1);
    return str;
}
void CompressedToFile(ofstream &file ,string Arr[],int size)
{
    for (int i=0;i<size;i++)
  {
      file << Arr[i] << endl;
  }
  file.close();
}

int GetFristCharOfString (string str)
{
    int num;
    string a;
    a =str.substr(0,2);
    stringstream ss;
    ss <<a;
    ss >> num;
    return num;
}
