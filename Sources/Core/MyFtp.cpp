//
// Created by 10484 on 24-5-8.
//
#pragma execution_character_set("utf-8")
#include "MyFtp.h"

#include <filesystem>

#include "MyString.h"
#include <fstream>
#include <string>

namespace Core
{
	MyFtp::MyFtp()
	{
		this->ftpCtx = std::make_unique<ftplib>();
		this->ftpCtx->SetConnmode(ftplib::port);
	}

	MyFtp::~MyFtp()
	{
		this->ftpCtx.reset();
	}

	bool MyFtp::Login(const FtpUserData &data) const
	{
		const std::string host = data.host + ":" + (data.port.empty() ? data.port : "21");
		if (!ftpCtx->Connect(host.c_str()))
			return false;
		return ftpCtx->Login(data.user.c_str(), data.password.c_str());
	}

	std::string MyFtp::Pwd() const
	{
		// 包含 256个空字符（'\0'）
		std::string path(256, '\0');
		ftpCtx->Pwd(path.data(), static_cast<int>(path.size()));
		return std::move(path);
	}

	std::vector<FtpFileInfo> MyFtp::Dir() const
	{
		std::string file = "Dir.txt";
		// 获取当前目录下的文件列表，并将其保存到名为 "Dir.txt" 的文件中
		if (int ret = ftpCtx->Dir(file.c_str(), Pwd().c_str()); !ret)
			return {};
		// 打开文件 "Dir.txt"
		std::ifstream in(file);
		// 文件的每一行
		std::vector<std::string> lines;
		// 读取
		if (in)
		{
			std::string line;
			while (getline(in, line))
				lines.push_back(line);
		}
		// 关闭 "Dir.txt"
		in.close();
		// 当前目录的全部文件的信息
		std::vector<FtpFileInfo> list;
		for (const auto &line: lines)
		{
			// lines 大概长这样
			//?类型权限    链接数 用户 属组     大小   日期         文件名|文件夹名
			// -r--r--r-- 1 ftp ftp         99982 Jul 27  2023 LitleCat.jpg
			// dr--r--r-- 1 ftp ftp             0 Feb 13  2024 ffmpeg_learn
			// ...
			// 用空格将每一行分割成多个参数
			std::vector<std::string> args = Utils::StringSplit(line, ' ');
			// 这行没东西
			if (args.size() < 9)
				continue;
			// 拼接日期
			std::string date = args.at(5) + " " + args.at(6) + " " + args.at(7);
			// 文件名
			std::string fileName = args.at(8);
			// 将文件名后面的参数（如果有的话）拼接到文件名字符串中
			for (int i = 9; i < args.size(); ++i)
				fileName += " " + args.at(i);
			list.push_back({
				args.at(0), // 权限
				args.at(1), // 链接数
				args.at(2), // 属主
				args.at(3), // 属组
				args.at(4), // 大小
				date,       // 日期
				fileName    // 文件名
			});
		}
		return std::move(list);
	}

	bool MyFtp::Cd(const std::string &path) const
	{
		return ftpCtx->Chdir(path.c_str());
	}

	bool MyFtp::CdUp() const
	{
		return ftpCtx->Cdup();
	}

	bool MyFtp::Put(const std::string &filePath) const
	{
		const filesystem::path p(filePath);
		// 提取文件名
		const std::string fileName = p.filename().string();
		// 上传
		return ftpCtx->Put(filePath.c_str(), fileName.c_str(), ftplib::image);
	}

	bool MyFtp::Get(const std::string &getFile, const std::string &remoteFile) const
	{
		return ftpCtx->Get(getFile.c_str(), remoteFile.c_str(), ftplib::image);
	}

	bool MyFtp::Delete(const std::string &file) const
	{
		// 删除文件
		if (ftpCtx->Delete(file.c_str())) return true;
		// 删除目录
		return ftpCtx->Rmdir(file.c_str());
	}

	std::string MyFtp::GetError() const
	{
		return ftpCtx->LastResponse();
	}
} // Core
