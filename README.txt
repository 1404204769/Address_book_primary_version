2021-7-23
第一天的工作开始了
需求：
1.录入操作
2.查询操作
3.批量生成10万条数据，并计算耗时
4.本地从同一个新人svn同时checkout2个svn目录，一个目录用于提交，另外一个目录用于验证svm上的代码是否能正常编译过

其他要求：
1.控制台或者带界面都可以
2.用户名和地址支持中文，手机号要检测格式(11个数字)
3.注意编码规范
4.代码要提交到svn，不要提交无用的文件

问题：
vs2019没办法在控制台输入中文并显示,使用高级保存选项也没用，经测验发现在代码首部加上如下即可：
system("chcp 936 && cls");

设计：
struct m_user{
	char *pszName;//保存名字
	char *pszTel;//保存手机号
	char *pszAdress;//保存地址
}
Class CuserMgr{
	const char* const filename = "UserDatabase.txt";//用于保存数据的文件，不可以更改
	vector<m_Cuser>VecByTel;//使用手机号作为索引，因为名字可能一样但是手机号不可能一样
public://内部的逻辑函数
	checkTel;//用于检查手机号是否规范，并且判断是否存在重复手机号
	GetUser();//用于生成随机数据
	AddUser();//用于将数据添加到VecByTel数组内
	saveInfoToFile;//文件写操作
	readInfoFromFile;//文件读操作
	showName();//打印输出所有的现存的名字
	showDetailByName();//输入用户的名字查询对应的信息
}

2021-7-24
第二天的工作开始了
经过一天的工作，完成了剩余功能的开发，并对代码进行了命名规范化
