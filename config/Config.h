#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <utility>

enum WriteMode {
	Naive,
	DCW,
	Flip_N_Write,
	Permutation_Write,
	M_Out_Of_N_Write,
	Combine_PW_FNW
};

class Config {
private:
	std::string fileName;
	std::string fileNameExtension;
	std::map<std::string, std::string> values;
	std::set<std::string> warned;
	//std::ofstream debugLogFile;
public:

	Config() {};
	~Config() {};
	void Read(std::string filename);
	std::string GetFileName();
	std::string GetFileNameExtension();
	bool KeyExists(std::string key);

	uint64_t GetValueUL(std::string key);
	void GetValueUL(std::string Key, uint64_t& value);

	int  GetValue(std::string key);
	void GetValue(std::string key, int& value);
	void SetValue(std::string key, std::string value);

	std::string GetString(std::string key);
	void  GetString(std::string key, std::string& value);
	void  SetString(std::string key, std::string);

	void GetBool(std::string key, bool& value);

	void GetMode(std::string key, WriteMode& value);

	void Print();

	void CalculateMOutOfN(int& m, int& n);
};

#endif // !PARAMETER_H

