#include<stdio.h>
#include <stdlib.h>

/*
 *   -M  --mgroup	指定多播组
 *   -P  --port		指定接收端口
 *   -p  --player	指定播放器
 *   -H  --help		显示帮助
 */


struct client_conf_st client_conf={
	rcvport=DEFAULT_REVPORT,
	mgroup=DEFAULT_MGROUP,
	player_cmd=DEFAULT_PLAYERCMD
};


static void printhelp(void)
{
	printf("-P --port 指定接收端口\n
			-M --mgroup 指定多播组 \n
			-p --player_cmd  执定播放器\n
			-H --help 显示帮助\n "
			)
}
int main(int argc,char ** argv)
{

	int index=0;
	struct option argarr[]={
		{
			"port",1,NULL,'P'
		},
		{
			"mgroup",1,NULL,'M'
		},
		{
			"player",1,NULL,'p'
		},
		{
			"help",1,NULL,'H'
		},
		{
			NULL,0,NULL,0
		}
		};
	/* 
	 *初始化 
	 *级别： 默认值 ，配置文件，环境变量，命令行参数
	 *
	 */
	int c;
	while(1)
	{
		c=	getopt_long(argc,argv,"P:M:p:H",argarr,&index)
			if(c<0)
				switch(c)
				{
					case 'p':
						client_conf.revport=optarg;
						break;
					case 'M'
						client_conf.mgroup=optarg;
						break;
					case 'p'
						client_conf.player_cmd=optarg;
						break;
					case 'H'
						printhelp();
						exit(0);
						break;
					default:
						abort();
						break;
				}
	}

	pip();

	fork();
	// 子继承调用解码器
	// 父进程  从网络上收包 发送给子进程
	
	exit(0);
}
