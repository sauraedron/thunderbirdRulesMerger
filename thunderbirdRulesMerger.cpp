#include <iostream>
#include <fstream>
using namespace std;
int main(int argv, char **argc)
{
  if(argv==0 || argv==1)
    {
      cout<<"Usage: ./executable [msgFilter.dat location] [FilterOn] [Operator] [inputFile] [DestinationFolder])\n";
    }

  string dat_file,filter, op, input_file, destination;
  //dat_file = argc[1];
  //  filter = argc[2];
  //  op = argc[3];
  //  input_file = argc[4];
  //  destination = argc[5];
  dat_file = "/home/saurabh/.thunderbird/9jtgbmex.default/ImapMail/imap.mail.yahoo.com/msgFilterRules.dat";
  filter = "subject";
  op = "contains";
  input_file = "/home/saurabh/thunderbird.dat";
  destination = "imap://saw_wan20%40yahoo.com@imap.mail.yahoo.com/Bulk Mail";
  try
    {
      ifstream userRead;
      ofstream userWrite;
      userWrite.open("\home\saurabh\op.txt");
      userRead.open(input_file.c_str());
      string tmp;
      while(getline(userRead, tmp))
	{	  
	  cout<<tmp<<"\n";
	}
    }
  catch(const exception &e)
    {
      cout<<"Caught Exception";
    }
  
  
}
