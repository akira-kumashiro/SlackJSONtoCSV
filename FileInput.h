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

	std::vector<std::vector<double>> fileData;//CSV�s��(CSV��)
	std::vector<std::string> date;//�f�[�^���t
	std::vector<std::string> time;//����
	std::vector<std::string> triggerWord;//�g���K����
	std::vector<std::string> message;//Slack���̃��b�Z�[�W

	std::vector<std::vector<double>> dataInput(std::string filename);
	std::vector<std::string> split(std::string& input, char delimiter);
	std::string getDate(time_t _time);
	std::string getTime(time_t _time);
	
	~FileInput();
};

