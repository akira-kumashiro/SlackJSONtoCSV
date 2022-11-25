#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <numeric>
#include <filesystem>
#include <ctime>
#include <codecvt>
#include <string>

class FileInput
{
private:

public:
	FileInput(std::string _filename);

	std::vector<std::vector<double>> fileData;//CSV行数(CSV列数)
	std::vector<std::string> date;//データ日付
	std::vector<std::string> time;//時間
	std::vector<std::string> triggerWord;//トリガ文字
	std::vector<std::string> message;//Slack内のメッセージ

	std::vector<std::vector<double>> dataInput(std::string filename);
	std::vector<std::string> split(std::string& input, char delimiter);
	std::string getDate(time_t _time);
	std::string getTime(time_t _time);
	
	~FileInput();
};

