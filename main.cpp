#include "stdafx.h"
#include"GetFolderFiles.h"
#include "FileInput.h"

int main(void)
{
	std::string folderTarget;
	std::cout << "ファイルのフルパスは？" << std::endl;
	std::cin >> folderTarget;
	std::cout << folderTarget << std::endl;
	GetFolderFiles folderFilesList(folderTarget);
	std::ostringstream result;

	for (int fileNumber = 0; fileNumber < folderFilesList.fileList.size(); fileNumber++)
	{
		FileInput fileio(folderFilesList.fileList[fileNumber].string());
		std::cout << folderFilesList.fileList[fileNumber] << std::endl;

		for (int i = 0; i < fileio.date.size(); i++)
		{
			std::cout << fileio.date.at(i) << "," << fileio.time.at(i) << ", ," << fileio.triggerWord.at(i) << "," << fileio.message.at(i) << std::endl;
			result << fileio.date.at(i) << "," << fileio.time.at(i) << ", ," << fileio.triggerWord.at(i) << "," << fileio.message.at(i) << std::endl;
		}
	}
	std::ofstream writing_file;
	std::string filename = "result.csv";
	std::ostringstream filePath;
	filePath<<folderTarget<<"\\"<<filename;
	writing_file.open(filePath.str(), std::ios::out);
	std::string writing_text = result.str();
	writing_file << writing_text << std::endl;
	writing_file.close();
}