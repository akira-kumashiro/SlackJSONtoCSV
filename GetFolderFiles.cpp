#include "GetFolderFiles.h"

//コンストラクタ　フォルダが空の時EXIT_FAILURE
GetFolderFiles::GetFolderFiles(std::string _folderPath)
{
	if (!getFileNames(_folderPath))
		exit(EXIT_FAILURE);
}

bool GetFolderFiles::getFileNames(std::string _folderPath)
{
	using namespace std::filesystem;
	std::error_code err;
	directory_iterator iter(_folderPath, err), end;

	for (const directory_entry& entry : recursive_directory_iterator(_folderPath, err))
	{
		std::filesystem::path filePath = entry.path().string();
		if (filePath.extension() == ".csv" || filePath.extension() == ".CSV")
			fileList.push_back(entry.path().string());
		std::cout << fileList.back() << std::endl;
	}

	/* エラー処理 */
	if (err) {
		std::cout << err.value() << std::endl;
		std::cout << err.message() << std::endl;
		return false;
	}
	return true;
}
