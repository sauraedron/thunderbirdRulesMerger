#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main(int argv, char **argc)
{
  if(argv==0 || argv==1)
    {
      cout<<"usage [filtername] [location for update] [filter on] [operator] [input_file]\n";
      return -1;
    }
  string trm_filter_name, trm_location_for_update, trm_filter_on, trm_operator, trm_input_file, trm_message_destination;
  trm_filter_name = argc[1];
  // trm_location_for_update = argc[2];
  // trm_filter_on = argc[3];
  // trm_operator = argc[4];
  // trm_input_file = argc[5];

  string dat_file = argc[1];

  trm_location_for_update = "/home/saurabh/.thunderbird/9jtgbmex.default/ImapMail/imap.mail.yahoo.com/msgFilterRules.dat";
  dat_file = trm_location_for_update;
  string filter = "subject";
  string op = "contains";
  string input_file = "/home/saurabh/thunderbird.dat";
  string destination = "imap://saw_wan20%40yahoo.com@imap.mail.yahoo.com/Bulk Mail";
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
      userWrite<<"name=\""<<trm_filter_name<<"\"\n";
      userWrite<<"enabled=\"yes\"\n";
      userWrite<<"type=\"17\"\n";
      userWrite<<"action=\"Move to folder\"\n";
      userWrite<<"actionValue=\""<<destination<<"\"\n";
      userWrite<<"condition=\"";
      for(int i=0; i<input_values.size(); ++i)
	{
    size_t xx = input_values.at(i).find('@');

	  userWrite<<"OR (from,"<<op<<","<<input_values.at(i).substr(xx+1, input_values.at(i).size()-xx)<<") ";
	}
      userWrite<<"\""<<endl;

      userWrite.close();

    }
  catch(const exception &e)
    {
      cout<<"Caught Exception";
    }

}
