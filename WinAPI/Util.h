#pragma once

#include <string>

class Util
{
public:
	static std::wstring WStringFormat(const std::wstring fmt, va_list args)
	{
		int size = ((int)fmt.size()) * 2;
		wchar_t* buffer = nullptr;

		while (true)
		{
			if (buffer != nullptr)
			{
				delete[] buffer;
			}
			buffer = new wchar_t[size + 1];
			int n = _vsnwprintf_s(buffer, size + 1, size, (wchar_t*)fmt.c_str(), args);

			if (-1 < n && n < size)
			{
				break;
			}
			else
			{
				size *= 2;
			}
		}

		std::wstring result = buffer;
		delete[] buffer;

		return result;
	}

	static std::wstring WStringFormat(const std::wstring fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		std::wstring result = WStringFormat(fmt, args);
		va_end(args);

		return result;
	}

	static vector<int> NonDuplicatedRandom(int min, int max, int count)
	{
		vector<int> result;
		vector<int> randoms;

		for (int i = min; i <= max; i++)
		{
			randoms.push_back(i);
		}

		for (int i = 0; i < count; i++)
		{
			int randomIndex = (rand() + i) % randoms.size();
			int temp = randoms[i];
			randoms[i] = randoms[randomIndex];
			randoms[randomIndex] = temp;
			result.push_back(randoms[i]);
		}

		return result;
	}
};