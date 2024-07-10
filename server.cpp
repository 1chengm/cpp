#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(){
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if( sockfd ==-1){
		exit(1);
	}
	struct sockaddr_in saddr,caddr;//fuwuqidizhi
	memset(&saddr,0,sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(6000);//zhuan wangluo zijie xulie
	saddr.sin_addr.s_addr = inet_addr("192.168.159.130");
	int res = bind(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));
	if(res==-1){
		printf("bind error\n");
		exit(1);
	}
	listen(sockfd,5);
	while(1){
		int len = sizeof(caddr);
		int c = accept(sockfd,(struct sockaddr*)&caddr,&len);//zuse
		if ( c<0){
			continue;
		}
		printf("accept c=%d",c);
		char buff[128] = {0};
		recv(c,buff,127,0);
		printf("buff=%s\n",buff);
		send(c,"ok",2,0);
		close(c);
	}
}
