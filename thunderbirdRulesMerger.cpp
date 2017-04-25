#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main(int argv, char **argc)
{
  if(argv==0 || argv==1)
    {
      cout<<"usage [filtername]"
    }
  string trm_filter_name, trm_location_for_update, trm_filter_on, trm_opeartor, trm_input_file, trm_message_destination;
  trm_fiter_name = argv[1];
  trm_location_for_update = argv[2];
  trm_filter_on = argv[3];
  trm_operator = argv[4];
  trm_input_file = argv[5];
  
  //dat_file = argc[1];
  //  filter = argc[2];
  //  op = argc[3];
  //  input_file = argc[4];
  //  destination = argc[5];
  trm_location_for_update = "/home/saurabh/.thunderbird/9jtgbmex.default/ImapMail/imap.mail.yahoo.com/messageFilterRules.dat";
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
      userWrite<<"name=\"Auto gen_"<<rand()<<"\"\n";
      userWrite<<"enabled=\"yes\"\n";
      userWrite<<"type=\"17\"\n";
      userWrite<<"action=\"Move to folder\"\n";
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
