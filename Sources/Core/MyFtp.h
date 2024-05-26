//
// Created by 10484 on 24-5-8.
//

#ifndef MYFTP_H
#define MYFTP_H

#include <ftplib.h>
#include <memory>
#include <string>
#include <vector>

namespace Core
{
	// IP 端口 用户名 密码
	struct FtpUserData
	{
		std::string host;
		std::string port;
		std::string user;
		std::string password;
	};

	// 文件信息
	struct FtpFileInfo
	{
		// 权限
		std::string access;
		// 链接数
		std::string linkNB;
		// // 属主
		std::string ower;
		// 属组
		std::string group;
		// 大小
		std::string size;
		// 日期
		std::string date;
		// 文件名|文件夹名
		std::string fileName;
	};

	/**
	 * Ftp包装类
	 */
	class MyFtp
	{
	public:
		MyFtp();

		~MyFtp();

		/**
		 * 连接 登录
		 * @param data 用户信息
		 * @return
		 */
		[[nodiscard]] bool Login(const FtpUserData &data) const;

		/**
		 * 获取远程工作目录
		 * @return 
		 */
		[[nodiscard]] std::string Pwd() const;

		/**
		 * 获取当前目录下的文件列表
		 * @return
		 */
		[[nodiscard]] std::vector<FtpFileInfo> Dir() const;

		/**
		 * 跳转目录
		 * @param path
		 * @return 
		 */
		[[nodiscard]] bool Cd(const std::string &path) const;

		/**
		 * 回退上级目录
		 * @return 
		 */
		[[nodiscard]] bool CdUp() const;

		/**
		 * 上传
		 * @param filePath 要被上传的完整文件路径
		 * @return 
		 */
		[[nodiscard]] bool Put(const std::string& filePath) const;

		/**
		 * 下载
		 * @param getFile  要下载到的完整文件路径
		 * @param remoteFile 要被下载的完整文件路径
		 * @return
		 */
		[[nodiscard]] bool Get(const std::string &getFile, const std::string &remoteFile) const;

		/**
		 * 删除文件或目录
		 * @param file 文件或目录
		 * @return
		 */
		[[nodiscard]] bool Delete(const std::string &file) const;

		/**
		 * 获取错误信息
		 * @return
		 */
		[[nodiscard]] std::string GetError() const;

	private:
		std::unique_ptr<ftplib> ftpCtx;
	};
} // Core

#endif //MYFTP_H
