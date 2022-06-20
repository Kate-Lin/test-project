#ifndef TTAI_SOCKET_CLIENT_H_
#define TTAI_SOCKET_CLIENT_H_
#include <vector>
#include <sys/time.h>
#include <string>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <cmath>
/**
 * @brief 打开与服务器的TCP链接
 *
 * @param ip[in] 服务器的ip地址
 * @param port[in] 服务器端口
 * @param soc[out] socket文件描述符
 * @return int 0-成功，-1-失败
 */
int OpenSession(std::string ip, int port, int &soc);

/**
 * @brief 关闭socket链接，采用全关闭的方式
 *
 * @param soc[in] 被关闭文件的描述符
 * @return int 0-成功，-1-失败
 */
int CloseSession(int soc);

/**
 * @brief 将数据分组,每组格式   组号-数据|       组号从0开始，末尾|为结束符号
 *
 * @param mess[in] 待分组的消息
 * @param vec[out] 分组的结果
 * @param length[in] 每一组的长度
 * @return int
 */
int split_mess(std::string mess, std::vector<std::string> &vec, int length);

/**
 * @brief 使用socke发送数据
 *
 * @param input 待发送的明文数据
 * @param sock 用于通信的socket
 */
int SocketWrite(std::string input, int sock);

/**
 * @brief 从socket中接收数据
 *
 * @param buff
 * @param sock
 */
int SocketRead(std::string &buff, int sock);

/**
 * @brief 发送消息的初始信息
 *
 * @param group_num 消息一共有多少组
 * @param total_length 一共有多长
 * @param sock 使用的文件描述符
 * @return int 0-初始化成功，1-初始化发送失败，2-初始化接收失败
 */
int TransSendInit(int group_num, int total_length, int sock);

/**
 * @brief 接收传输初始化信息
 *
 * @param group_num 组数
 * @param total_length 总长度
 * @param sock 所用socket
 * @return int 0-成功，1-发送初始化信息失败。2-接收初始化信息失败
 */
int TransReadInit(int &group_num, int &total_length, int sock);
#endif