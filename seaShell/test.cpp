#include<iostream>
#include<fstream>
#include<dirent.h>
#include<vector>
#include<errno.h>
#include<cstdlib>
#include<unistd.h>


void init(std::string& username, std::string& pwd){
	username = std::getenv("USERNAME");
	pwd = std::getenv("PWD");	
}

int changeDir(std::string dirName){
		return 0;
}

std::vector<char*> listDir(std::string dirName){
	DIR *dir;
	dirent *temp;
	const char* dirNameStr = dirName.c_str();
	dir = opendir(dirNameStr);
	std::vector<char*> dirList;
	temp = readdir(dir);
	while(temp!=NULL){
		dirList.push_back(temp->d_name);
		temp=readdir(dir);
	}
	closedir(dir);
	
	return dirList;
	
}

std::string cdCommandHandler(std::string &pwd, std::string folder){
	if(folder[0]!='/'){
		pwd = pwd + '/' + folder;
	}else{
		pwd = folder;
	}
	
	DIR* dir = opendir(folder.c_str());
	if(dir){
		closedir(dir);
		setenv("PWD", pwd.c_str(), 1) ;
		chdir(pwd.c_str());
		return "Success: working directory changed to "+pwd;
	}else if(ENOENT == errno){
		return "Error: given address is not an existing directory";
	}else{
		return "Error: failed to open directory";
	}
		
}

int executeCommand(std::string command){
	std::vector<std::string> tokens;
	size_t curPos = 0;
	//std::cout<<command<<std::endl;
	while(true){
		curPos = command.find(" ");
		std::string test = command.substr(0, curPos);
		tokens.push_back(test);
		if(curPos == std::string::npos){
			break;
		}
		curPos++;
		//std::cout<<curPos;
		command = command.substr(curPos);
		std::cout<<"substr: "<<command<<std::endl;
	}
	std::cout<<"function"<<std::endl;
	for (std::string s : tokens) {
		std::cout<<s<<std::endl;
	}
	
	return 0;
}

int main(){
	std::string username;
	std::string pwd;
	
	init(username, pwd);
	std::cout<<"username: "<<username<<std::endl;
	std::cout<<"pwd: "<<pwd<<std::endl;
	std::vector<char*> dirList = listDir(pwd);
	std::cout<<"dirlist:-"<<std::endl;
	for(char* filename: dirList){
		std::cout<<filename<<std::endl;
	}
	/*
	std::cout<<"enter dir name: ";
	std::string newDir;
	std::cin>>newDir;
	
	std::cout<<std::endl<<cdCommandHandler(pwd, newDir)<<std::endl;
	init(username, pwd);
	std::cout<<pwd<<std::endl;
	
	dirList = listDir(pwd);
	std::cout<<"dirlist:-"<<std::endl;
	for(char* filename: dirList){
		std::cout<<filename<<std::endl;
	}
	*/
	std::string commandString;
	std::cout<<"enter command"<<std::endl;
	getline(std::cin, commandString);
	executeCommand(commandString);
	
	
	return 0;
}

