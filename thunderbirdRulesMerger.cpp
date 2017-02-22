#include <iostream>
#include <vector>
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
  dat_file = "/home/saurabh/.thunderbird/9jtgbmex.default/ImapMail/imap.mail.yahoo.com/messageFilterRules.dat";
  filter = "subject";
  op = "contains";
  input_file = "/home/saurabh/thunderbird.dat";
  destination = "imap://saw_wan20%40yahoo.com@imap.mail.yahoo.com/Bulk Mail";
  try
    {
      ifstream userRead;
      ofstream userWrite;
      userWrite.open(dat_file, ios::app);
      userRead.open(input_file.c_str());
      string tmp;
      vector<string> input_values;
      while(getline(userRead, tmp))
	{	  
	  input_values.push_back(tmp);
	}
      userRead.close();
      //      userWrite.seekg(ios::en);
      userWrite<<"name=\"Auto gen\"\n";
      userWrite<<"enabled=\"yes\"\n";
      userWrite<<"type=\"17\"\n";
      userWrite<<"action = \"Move to folder\"\n";
      userWrite<<"actionValue=\""<<destination<<"\"\n";
      userWrite<<"condition=\"";
      for(int i=0; i<input_values.size(); ++i)
	{
	  userWrite<<"OR (from,"<<op<<","<<input_values.at(i)<<") ";
	}
      userWrite<<"\""<<endl;
      
      userWrite.close();
      
    }
  catch(const exception &e)
    {
      cout<<"Caught Exception";
    }
  
  
}
