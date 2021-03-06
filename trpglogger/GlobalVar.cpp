#include "GlobalVar.h"
#include <string>
#include <map>
#include <vector>
#include <aws/core/Aws.h>
#include <aws/core/auth/AWSCredentialsProvider.h>


// 全局应用目录
std::string fileLoc;
// 全局数据库路径
std::string dbLoc_UTF8;
// Aws SDK设置
Aws::SDKOptions options;
// Aws Credentials, 显式指定使用空字符串匿名Credentials
Aws::Auth::AWSCredentials awsCredentials("", "");
// 应用是否启用
bool Enabled = false;
// Log信息存储
std::map<long long, time_t> LogInfo;		// 群
std::map<long long, time_t> LogInfoDiscuss;	// 讨论组
// 版本信息
const std::string TrpgLoggerVer = "TrpgLogger by w4123溯洄 Version 1.0.4(18)";
//自定义回执
std::string CustomReplyLoc_UTF8;
std::map<std::string, std::string> CustomReply
{
	{"self", "我"},
	{"strAlreadyLogging", "正在进行日志记录, 无法再次开始!"},
	{"strStartLogging", "开始日志记录"},
	{"strStartSaveLog", "正在保存日志"},
	{"strSuccessSaveLog", "日志记录已结束，文件已保存，正在上传至服务器"},
	{"strFailSaveLog", "保存失败，您可以尝试稍后重试此命令再次保存\n错误信息:"},
	{"strSuccessUploadLogBefore", "上传已完成，请访问"},
	{"strSuccessUploadLogAfter", "以查看记录"},
	{"strFailUploadLog", "上传过程中发生错误，请联系管理员或稍后再次使用此命令重试上传\n错误信息:"},
	{"strNeverLog", "没有已开始的日志记录!"},
	{"strLogHlp", "\n.log     \t 启动日志记录\n.log stop\t 停止日志记录\n.log help\t 日志记录帮助"}
};
const std::vector<std::string> CustomReplyFilter
{
	"self"
};
//静态替换
std::string& replace_all(std::string& str, const std::string& old_value, const std::string& new_value)
{
	while (true)
	{
		std::string::size_type pos(0);
		if ((pos = str.find(old_value)) != std::string::npos)
		{
			str.replace(pos, old_value.length(), new_value);
		}
		else
		{
			break;
		}
	}
	return str;
}