#include "include/mavlink.h"
#include  "include/mavlink_msg_file_heads.h"
#include  "include/mavlink_msg_file_data.h"
#include "upload_file.h"

#define PORT 8888
#define IP "192.168.1.72"
int total_send=0;
int file_transfer(int file_server_fd,char* path,unsigned long int file_size);
int file_imformation_transfer(int server_fd);
int get_file_md5(char *file_url,unsigned char md5 []);
int compare_str(char arr1[],char arr2[],int len);
int main()
{
    printf("test upload file\n");

    int fd;

	struct sockaddr_in daddr;
	int err;

    //建立套接字
	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd < 0){
		printf("socket create fail!\n");
	}
    //初始化服务器地址
	memset(&daddr,0,sizeof(struct sockaddr));
	daddr.sin_family = AF_INET;
	daddr.sin_port = htons(PORT);
	daddr.sin_addr.s_addr = inet_addr(IP);
	//建立连接
	err = connect(fd,(struct sockaddr*)&daddr,sizeof(struct sockaddr));
	if(err < 0){
		printf("connect fail!\n");
        return 0;
	}
	file_imformation_transfer(fd);
	close(fd);
    return 0;
}

//在传输文件内容之前，先传送文件信息，比如文件名、文件大小、文件MD5值
int file_imformation_transfer(int server_fd){
     struct stat sta;
     mavlink_file_heads_t file_heads;
	char path[200];
	memset(path,0,sizeof(path));
	memset(&file_heads,0,sizeof(mavlink_file_heads_t));
	memset(&sta,0,sizeof(struct stat));
	printf("请输入文件路径和文件名：\n");
	scanf("%s",path);
	if(stat(path,&sta) == -1){
		perror("获取文件信息错误");
		return -1;
	}
    file_heads.file_size=sta.st_size;
    strcpy(file_heads.file_name,path);
    //获取文件MD5值
	get_file_md5(path,file_heads.md5);
    printf("md5值为");
	for(int i = 0; i < 16;i++){
		printf("%02X",file_heads.md5[i]);
	}
	printf("\n");
    file_heads.file_type=0;
    mavlink_message_t  mavlink_message;
    mavlink_msg_file_heads_encode(1,2,&mavlink_message,&file_heads);
    uint8_t msgbuffer[MAVLINK_MAX_PACKET_LEN];
    unsigned buf_len;
    buf_len=mavlink_msg_to_send_buffer(msgbuffer,&mavlink_message);
    for(int i=0;i<buf_len;i++)
    {
        printf("%02X",msgbuffer[i]);
    }
    printf("\n");
     int ret=-1;
    if(buf_len)
    {
       ret=write(server_fd,msgbuffer,buf_len);
        printf("send head size:%d\n",ret);
		total_send=1;
    }
	sleep(10);
    file_transfer(server_fd,path,sta.st_size);


    printf("read status\n");
    return 0;
}
//获取文件MD5值函数，file_url代表文件路径加文件名，根据其读取文件。char md5[]用于存放md5值
int get_file_md5(char *file_url,unsigned char md5 [])
{
	MD5_CTX ctx;
	char buffer[1024];
	int len=0;
	FILE * fp=NULL;
	memset(buffer,0,sizeof(buffer));
	//打开文件
	fp=fopen(file_url,"rb");
	if(fp==NULL)
	{
		printf("Can't open file\n");
		return 0;
	}
	//初始化
	MD5_Init(&ctx);
	//读取文件计算MD5值
	while((len=fread(buffer,1,1024,fp))>0)
	{
	MD5_Update(&ctx,buffer,len);
	memset(buffer,0,sizeof(buffer));
	}
	//获取MD5值
	MD5_Final(md5,&ctx);
	return 0;
}

//比较md5,两个字符数组中字符是否相等
int compare_str(char arr1[],char arr2[],int len){
	int i = len;
	for(;i < len;i++){
		if(arr1[i] == arr2[i]){
			continue;
		}else{
			return 0;
		}
		return 1;
	}
}
//传输文件内容
int file_transfer(int file_server_fd,char* path,unsigned long int file_size)
{
    int size = 0;
	unsigned long sum = 0;
	int n = 0;
	char buffer[250];

	mavlink_file_data_t content;
	mavlink_message_t  mavlink_message;
	uint8_t msgbuffer[MAVLINK_MAX_PACKET_LEN];
	unsigned buf_len;
	memset(msgbuffer,0,sizeof(msgbuffer));
	memset(buffer,0,sizeof(250));
	int filefd = open(path,O_RDWR);
	if(filefd == -1){
		perror("file open fail");
	}
	while(1){
		size = read(filefd,buffer,sizeof(buffer));
		if(size == -1){
			printf("文件传输错误\n");
			close(filefd);
			return -1;
		}else if(size > 0){
			content.package_id=0;
			memcpy(content.file_data,buffer,sizeof(buffer));
			mavlink_msg_file_data_encode(1,2,&mavlink_message,&content);
			buf_len=mavlink_msg_to_send_buffer(msgbuffer,&mavlink_message);
			write(file_server_fd,msgbuffer,buf_len);
			sum += size;
			unsigned long int p = (sum * 100)/file_size;
			printf("\r文件已传输%ld%%",p);
			total_send=total_send+1;
			memset(content.file_data,0xFF,250);
			memset(msgbuffer,0xFF,sizeof(msgbuffer));
		}else{
			//当读取为0时，表示文件读取完毕
			printf("传输成功 %ld   total_send:%d  byte  \n",sum,total_send);
            close(file_server_fd);
			close(filefd);
            return 0;
		}
	}
}

















