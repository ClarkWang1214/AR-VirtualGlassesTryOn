#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdexcept>


namespace tezcat
{
	namespace io
	{

		//************************************
		// Method:    loadBinary
		// FullName:  tezcat::IO::loadBinary
		// Access:    public static
		// Returns:   char *
		// Qualifier:
		// Parameter: const std::string & file
		// Note:      别忘记释放内存
		//************************************
		static inline char *loadBinary(const std::string &file)
		{
			std::ifstream in(file, std::ifstream::in);
			if (in.fail())
			{
				throw std::logic_error("open file error");
				in.close();
				return nullptr;
			}
			else
			{
				in.seekg(0, std::ios_base::end);
				size_t m_Length = (size_t)in.tellg();
				in.seekg(0, std::ios_base::beg);

				char *dataBuffer = new char[m_Length + 1];
				memset(dataBuffer, 0x00, m_Length);
				dataBuffer[m_Length] = '\0';

				in.read(dataBuffer, m_Length);
				in.close();
				return dataBuffer;
			}
		}

		//***************************************
		// Method:    loadBinary2String
		// FullName:  tezcat::io::loadBinary
		// Access:    public static
		// Returns:   std::string
		// Qualifier:
		// Parameter: const std::string & file
		// Note:
		//***************************************
		static inline std::string loadBinary2String(const std::string &file)
		{
// 			std::ifstream in(file, std::ios::binary);
//
// 			if (in.fail())
// 			{
// 				std::logic_error("open file error");
// 				in.close();
// 				return nullptr;
// 			}
// 			else
// 			{
// 				in.seekg(0, std::ios_base::end);
// 				size_t m_Length = (size_t)in.tellg();
// 				in.seekg(0, std::ios_base::beg);
//
// 				char *dataBuffer = new char[(int)m_Length + 1];
// 				memset(dataBuffer, 0x00, m_Length);
// 				dataBuffer[m_Length] = '\0';
//
// 				in.read(dataBuffer, m_Length);
// 				in.close();
// 				std::string temp = dataBuffer;
// 				delete[] dataBuffer;
//
// 				return temp;
// 			}
			auto data = loadBinary(file);
			if (data != nullptr)
			{
				std::string temp = data;
				delete[] data;
				return temp;
			}
			else
			{
				return std::string("error");
			}
		}

		static inline bool createFile(const std::string &file_name, const std::string &content)
		{
			std::ofstream out(file_name, std::ios::binary);

			if (out.fail())
			{
				throw std::logic_error("open file error");
				out.close();
				return false;
			}
			else
			{
				out << content;
				out.flush();
				out.close();
				return true;
			}
		}

		static inline std::string getPathByIndexAndFlag(std::string path, const size_t &index, const std::string &flag)
		{
			std::string result;
			for (size_t i = 0; i < index; i++)
			{
				auto pos = path.find_first_of(flag);
				auto temp = path.substr(0, pos + 1);
				path = path.substr(pos, path.size() - 1);
				result += temp;
			}

			return result;
		}

		static inline std::string getPathByLastFlag(std::string path, const std::string &flag)
		{
			return path.substr(0, path.find_last_of(flag) + 1);
		}
	}
}
