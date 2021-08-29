#include<bits/stdc++.h>
#include<fstream>
using namespace std;

string get_random_line(fstream &file)
{
	int line_count = 0;
	string line;
	while(getline(file,line)) line_count++;
	srand(time(0));
	int rand_line = rand()%line_count;
	file.clear();
	file.seekg(0,ios::beg);
	while(rand_line>=0 && getline(file,line))
	{
		rand_line--;
	}
	line = "//" + line + "\n\n";
	return line;
}

string get_file_in_string (fstream &f)
{
	string buffer;
	string line;
	while(getline(f,line))
	{
		buffer += line;
		buffer+='\n';
	}
	return buffer;
}

int main(int argc, char** args)
{
	if(argc<3) return 0;
	fstream f;
	string fetch_from = args[1];
	string target_file = args[2];

	f.open(target_file,ios::in);
	if(!f) 
	{
		return 0;
	}
	string file_buffer = get_file_in_string(f);
	f.close();
	if(file_buffer[0]=='/')
	{
		return 0;
	}
	f.open(fetch_from,ios::in);
	string put_text = get_random_line(f);
	file_buffer = put_text + file_buffer;
	f.close();
	f.open(target_file,ios::out);
	f<<file_buffer;
	f.close();
	//cout<<file_buffer<<endl;
	return 0;
}
