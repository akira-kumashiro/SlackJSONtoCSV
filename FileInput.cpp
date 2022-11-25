#include "FileInput.h"

FileInput::FileInput(std::string _filename)
{
	fileData = dataInput(_filename);
}

std::vector<std::vector<double>> FileInput::dataInput(std::string filename)
{
	setlocale(LC_ALL, "");

	std::ifstream ifs(filename);

	//static_assert(sizeof(wchar_t) == 2, "error.");//Linuxではつかうcvt違うから直してくれ
	//ifs.imbue(std::locale(std::locale(""), new std::codecvt_utf8_utf16<wchar_t, 0x10ffff, std::consume_header>()));

	if (!ifs.is_open())
	{
		std::cerr << "Could not open the file - '"
			<< filename << "'" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string line;
	std::vector<double> result;
	std::vector<std::vector<double>> fileData;

	std::getline(ifs, line);
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
	{
		result.push_back(field);
	}

	return result;
}

std::string FileInput::getDate(time_t _time)
{
	std::ostringstream converted_date;
	/*
	Tue Aug 2 02:13:24 2016
	Tue Aug 2 03:55:19 2016
	2016/8/2 3:55:19
	*/

	// convert time_t to structure tm. You can use instead gmtime() for UTC
	//tm* tm_previous = localtime(&_time);

	// print time using asctime() function.
	//std::cout << asctime(tm_previous);

	// for current time
	//time_t current_time = std::time(0); // get current time
	tm conv_time;
	errno_t error = localtime_s(&conv_time, &_time);
	//std::cout << asctime(tm_current);

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
