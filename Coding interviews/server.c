#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#define portnumber 8888

int main(int argc,char** argv)
{
	int sockfd,new_fd;
	struct sockaddr_in server_addr;
	struct sockaddr_in client-addr;
	int sin_size;
	char rbuffer[1024];
	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
	{
		fprintf(stderr,"Socket error:%s\n\a",strerror(errno));
		return;
	}
	bzero(&server_addr,sizeof(struct sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(portnumber);
	if(bind(sockfd,(const struct sockaddr*)(&server_addr),sizeof(const struct sockaddr)) == -1)
	{
		fprintf(stderr,"Bind error:%s\n\a",strerror(errno));
		return;
	}
	if(listen(sockfd,5) == -1)
	{
		fprintf(stderr,"Listen error:%s\n\a",strerror(errno));
		return;
	}
	while(1)
	{
		sin_size = sizeof(struct sockaddr_in);
		if((new_fd = accept(sockfd,(struct sockaddr*)(&client_addr),&sin_size)) == -1 )
		{
			fprintf(stderr,"Accept error:%s\n\a",strerror(errno));
			return;
		}
		printf("Server get connection from %s:%d\n",inet_ntoa(client_addr.sin_addr),portnumber);
		while(1)
		{
			int nrecv,i;
			if((nrecv = recv(new_fd,rbuffer,sizeof(rbuffer))) > 0)
			{
				printf("Recveived message:%s\n",rbuffer);
			}
			else
			{
				printf("Recveived message error!\n");
				close(new_fd);
				break;
			}
		}
		close(new_fd);
	}
	close(sockfd);
	return 0;
}
