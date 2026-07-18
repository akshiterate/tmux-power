#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <unordered_map>
int main(){
	std::string folderpath = "/sys/class/power_supply/";
	std::string batterypath;
	for(const auto &entry : std::filesystem::directory_iterator(folderpath)){
		std::string path= entry.path().string();
		std::ifstream file(path+"/type");
		if(!file.is_open()){
			std::cerr<<"Error: could not open type file\n";
			return 1;
		}
		std::string line;
		std::getline(file,line);
		if(line == "Battery") batterypath = path;
		
	}
	std::ifstream battery_cap(batterypath+"/capacity");
	if(!battery_cap.is_open()){
		std::cerr<<"Error: could not open battery cap\n";
		return 1;
	}
	std::ifstream battery_status(batterypath+"/status");
	if(!battery_status.is_open()){
		std::cerr<<"Error: could nt open battery status\n";
		return 1;
	}
	std::string capacity,status;
	std::getline(battery_cap,capacity);
	std::getline(battery_status,status);
	std::unordered_map<std::string,std::string> stat = {
		{"Not charging","[NCHG]"},
		{"Full","[FULL]"},
		{"Discharging","[DCHG]"},
		{"Charging","[CHG]"}
	};
	std::cout<<"BAT:"<<capacity<<"%"<<stat[status]<<std::endl;
	return 0;
}
