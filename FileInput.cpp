#include "FileInput.h"

FileInput::FileInput(std::string _filename)
{
	fileData = dataInput(_filename);
}

std::vector<std::vector<double>> FileInput::dataInput(std::string filename)
{
	std::ifstream ifs(filename);

	if (!ifs.is_open())
	{
		std::cerr << "Could not open the file - '"
			<< filename << "'" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string line;
	std::vector<double> result;
	std::vector<std::vector<double>> fileData;

	std::getline(ifs, line);//1行分進める
	while (std::getline(ifs, line))
	{
		std::vector < std::string> strvec = split(line, ',');//1行のデータ

		date.push_back(getDate(stoll(strvec.at(3))));
		time.push_back(getTime(stoll(strvec.at(3))));
		triggerWord.push_back(strvec.at(11));
		message.push_back(strvec.at(2));
	}

	return fileData;
}

std::vector<std::string> FileInput::split(std::string& input, char delimiter)
{
	std::istringstream stream(input);
	std::string field;
	std::vector<std::string> result;
	while (std::getline(stream, field, delimiter))
		result.push_back(field);

	return result;
}

std::string FileInput::getDate(time_t _time)
{
	std::ostringstream converted_date;

	tm conv_time;
	errno_t error = localtime_s(&conv_time, &_time);

	// print by accessing contents of the structure
	converted_date << conv_time.tm_year + 1900 // year 0 corresponds to 1900
		<< "/" << conv_time.tm_mon + 1 // month starts from 0
		<< "/" << conv_time.tm_mday;  // mday means day in a month
	return converted_date.str();
}

std::string FileInput::getTime(time_t _time)
{
	std::ostringstream converted_time;
	tm conv_time;
	errno_t error = localtime_s(&conv_time, &_time);


	converted_time << std::setw(2) << std::setfill('0') << conv_time.tm_hour
		<< ":" << std::setw(2) << std::setfill('0') << conv_time.tm_min << ":00";
	return converted_time.str();
}

FileInput::~FileInput()
{
}
