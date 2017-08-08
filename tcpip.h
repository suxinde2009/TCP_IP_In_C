///
// Copyright (c) 2003, Wolver Wang, MinShan Inc. R&D Center
// wolver@minshan-inc.com
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. All advertising materials mentioning features or use of this software
//    must display the following acknowledgement:
//      This product includes software developed by Wolver Wang.
// 4. The name of the author may not be used to endorse or promote
//    products derived from this software without specific prior
//    written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///


///
// Copyright (c) 2003, Wolver Wang, MinShan Inc. R&D Center
// wolver@minshan-inc.com
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. All advertising materials mentioning features or use of this software
//    must display the following acknowledgement:
//      This product includes software developed by Wolver Wang.
// 4. The name of the author may not be used to endorse or promote
//    products derived from this software without specific prior
//    written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///


///
// 版权 2003, 王卫无，四川绵阳岷山集团有限公司--研究开发中心
// wolver@minshan-inc.com
// 保留一切权利
//
// 如果符合以下条件，则无论是以原代码或非原代码代码形式，且不论是否修改，
// 再分发和使用本软件都是被允许的。
// 1. 原代码的再分发必须保留上述的版权声明、本条件说明和以下免责声明。
// 2. 非原代码形式的再分发，必须在证明文件和(或)其它一同提供的材料中重新
//    作上述的版权声明、本条件说明和以下免责声明。
// 3. 一切提及本软件和使用的广告材料必须显示以下致谢：
//    本产品包含王卫无（四川绵阳岷山集团有限公司--研究开发中心）开发的软件。
// 4. 如果没有预先得到特定的书面许可，不能用作者的名字来宣传推广基于本软件得到
//    的产品。
//
// 免责声明：
// 本软件是由某某作者提供，如果出现以下情况，作者都不承担任何责任。
// 1. 因作者的说明以及任何明确的或暗示的保证(包括但不限于表达某种商业性和适合某一
//    特定目的暗示性保证)而产生的损失。
// 2. 无论在何种情况下，对使用本软件造成的任何直接的、间接的、偶然的、特定的、可预
//    见性的和连带产生的损失(包括但不限于获取产品和服务、作用丧失、数据遗失、利益损
//    失或商业干预)，无论这些损失是怎样造成的，并且是以何种方式阐释责任。
// 3. 任何因使用本软件而相关的合同、严格赔偿责任和侵权行为(包含：疏忽或其它)的损失，
//    甚至即便是可能的此类已经明示或暗示的损失。
///

// 所有这些定义适用于vIP4版本的TCP/IP协议

#ifndef	__TCPIP_H__
#define	__TCPIP_H__

#include "system.h"
#include "drivers.h"


// 定义前缀 -----------------------------------------------------------------------------------
// c  <-> Constant
// g  <-> Global
// uw <-> Unsigned Word
// p  <-> Point
// st <-> Struct
// pt <-> Point of Struct


// 定义TCP/IP模式 ------------------------------------------------------------------------------
#define TCP_DHCP			0		// 没有DHCP协议

// 系统工作于服务模式。定义为：0
// 允许TCP/IP主动激活（客户模式）。定义为：1
// 服务模式和客户模式同时存在。定义为：1
#define TCP_ACTIVE_OPEN		1


// 预置本机IP地址。例如： IP = 192.168.0.30 ------------------------------------------------------
#if TCP_DHCP == 0
#define cIpAddr1	192	// Byte Length
#define cIpAddr2	168	// Byte Length
#define cIpAddr3	0	// Byte Length
#define cIpAddr4	60	// Byte Length
extern const UINT16 guwIpAddr[2];
#else
extern UINT16 guwIpAddr[2];
#endif

// 预置本机IP的掩码。例如： NETMASK = 255.255.255.0 -----------------------------------------------
#if TCP_DHCP == 0
#define cNetMask1	255	// Byte Length
#define cNetMask2	255	// Byte Length
#define cNetMask3	255	// Byte Length
#define cNetMask4	0	// Byte Length
extern const UINT16 guwNetMask[2];
#else
extern UINT16 guwNetMask[2];
#endif

// 预置本机的网关。例如： GateWay = 192.168.0.1 ---------------------------------------------------
#if TCP_DHCP == 0
#define cDR_IpAddr1	192	// Byte Length
#define cDR_IpAddr2	168	// Byte Length
#define cDR_IpAddr3	0	// Byte Length
#define cDR_IpAddr4	1	// Byte Length
extern const UINT16 guwDR_IpAddr[2];
#else
extern UINT16 guwDR_IpAddr[2];
#endif

// 预置本机的以太物理地址。例如： MAC = 52H-54H-ABH-1D-A4-F9H ------------------------------------
#define cEthAddr1	0x52	// Byte Length
#define cEthAddr2	0x54	// Byte Length
#define cEthAddr3	0xab	// Byte Length
#define cEthAddr4	0x1d	// Byte Length
#define cEthAddr5	0xa4	// Byte Length
#define cEthAddr6	0xfa	// Byte Length
extern const UINT16 guwEthAddr[3];


//---------------------------------------------------------------------------------

// 定义TCP应用数据长度最大缓冲区，单位：字(Word)
#define cTcpDataSize		(1460/2)

//---------------------------------------------------------------------------------

// 定义TCP/IP协议的相关结构长度，单位：字(Word)，参考结构定义
#define cEthHdrLen		7		// 以太头结构长度
#define cArpHdrLen		14		// ARP头结构长度
#define cIpHdrLen		10		// IP头结构长度（不含扩展选项）
#define cIcmpHdrLen		4		// ICMP中Ping协议头结构长度
#define cTcpHdrLen		10		// TCP头结构长度（不含扩展选项）

//---------------------------------------------------------------------------------

// 以太头结构
typedef struct{
    UINT16 DestEthAddr[3];
    UINT16 SrcEthAddr[3];
    UINT16 EthType;
    // 以太头的包类型。EthHdr_Stru.EthType
#define cEthType_Arp	0x0806	// ARP Packet
#define cEthType_Ip		0x0800	// IP Packet
}EthHdr_Stru;

// 最大允许的以太包长度，单位：字(Word)
#define cEthBufSize		(cEthHdrLen + cIpHdrLen + cTcpHdrLen + cTcpDataSize)

// 分配允许的以太包处理缓冲区，单位：字(Word)
extern UINT16 guwEthBuf[cEthBufSize];

// 以太头的常数指针。
#define cpEthHdrBuf		((UINT16 *)&guwEthBuf[0])		// 指向Word的buffer
#define cptEthHdrBuf	((EthHdr_Stru *)&guwEthBuf[0])	// 指向结构

//---------------------------------------------------------------------------------

// ARP头结构
typedef struct{
    UINT16 HwType;
    // ARP包硬件类型。 ArpHdr_Stru.HwType
#define cHwType_Eth		0x01		// 以太模式
    UINT16 ProtoType;
    // #define cEthType_Ip		0x0800	// IP Packet
    UINT16 Hw8Proto8;
    // ARP协议类型 ArpHdr_Stru.Hw8Proto8
#define c_vIP4			0x0604		// vIP4
    UINT16 OpCode;
    // ARP操作类型 ArpHdr_Stru.OpCode
#define cArpRequest		0x01		// ARP请求
#define cArpReply		0x02		// ARP回应
    UINT16 SndEthAddr[3];
    UINT16 SndIpAddr[2];
    UINT16 RcvEthAddr[3];
    UINT16 RcvIpAddr[2];
}ArpHdr_Stru;

// ARP头的常数指针。
#define cptArpHdrBuf	((ArpHdr_Stru *)&guwEthBuf[cEthHdrLen])				// 指向结构

//---------------------------------------------------------------------------------

// IP头结构，不含扩展选项
typedef struct{
    UINT16 Tos:8, Vhl:8;
    // IpHdr_Stru.Tos = 0x00	// 服务类型0x00允许：TCP和ICMP查询、ICMP差错、BOOTP
    // IP头格式 IpHdr_Stru.Vhl
#define cIP_VER_HLEN		0x45	// vIP4
    UINT16 Len;
    UINT16 IpId;
    UINT16 Offset:13, Flags:3;
    // IpHdr_Stru.offset = 0
    // IpHdr_Stru.Flags 分片帧
#define cIP_DF	0x2		// 不分片帧(Do not Fragment)
#define cIP_MF	0x1		// 非最后帧，分片帧(More Fragment)
    UINT16 Proto:8, Ttl:8;
    // IP头的存活时间与协议类型 IpHdr_Stru.Proto
#define cIP_PROTO_ICMP		0x01	// IP属于ICMP类
#define cIP_PROTO_TCP		0x06	// IP属于TCP类
    // IP头的存活时间与协议类型 IpHdr_Stru.Ttl
#define cIP_TTL				0xff	// 存活时间
    UINT16 IpChkSum;
    UINT16 SrcIpAddr[2];
    UINT16 DestIpAddr[2];
}IpHdr_Stru;

// IP头的常数指针。
#define cpIpHdrBuf		((UINT16 *)&guwEthBuf[cEthHdrLen])		// 指向Word的buffer
#define cptIpHdrBuf		((IpHdr_Stru *)&guwEthBuf[cEthHdrLen])	// 指向结构

// 记录本地IP序号
extern volatile UINT16 guwIpId;

//---------------------------------------------------------------------------------

// ICMP头结构，不含扩展选项
typedef struct{
    UINT16 Code:8, Type:8;
    // IcmpHdr_Stru.Code = 0x00 only for PING relpy!
    // ICMP操作类型 IcmpHdr_Stru.Type
#define cICMP_ECHO_REPLY	0x00	// ICMP回应
#define cICMP_ECHO			0x08	// ICMP呼叫
    UINT16 ChkSum;
    UINT16 Id;
    UINT16 SeqNum;
}IcmpHdr_Stru;

// ICMP头的常数指针。
#define cpIcmpHdrBuf	((UINT16 *)&guwEthBuf[cEthHdrLen + cIpHdrLen])			// 指向Word的buffer
#define cptIcmpHdrBuf	((IcmpHdr_Stru *)&guwEthBuf[cEthHdrLen + cIpHdrLen])	// 指向结构

//---------------------------------------------------------------------------------

// TCP头结构，不含扩展选项
typedef struct{
    UINT16 SrcPort;					// 本地端口
    UINT16 DestPort;				// 远端端口
    UINT16 SeqNum[2];				// 本地32位序号
    UINT16 AckNum[2];				// 远端期待的32位序号
    UINT16 Flags:6, Reserve:6, HdrLen:4;
    // TCP保留 TcpHdr_Stru.Reserve = 0
    // TCP标识 TcpHdr_Stru.HdrLen 代表TCP头长度，以32bit（4 byte）为单位
#define cTCP_HDR_NOOPT		0x05	// TCP头无操作选项
#define cTCP_HDR_OPT		0x07	// TCP头有操作选项，操作选项长度4 word 或8 byte
    // TCP标识 TcpHdr_Stru.Flags
#define cTCP_FIN			0x01
#define cTCP_SYN			0x02
#define cTCP_RST			0x04
#define cTCP_PSH			0x08
#define cTCP_ACK			0x10
#define cTCP_URG			0x20
    UINT16 WndSize;					// 窗口大小，表明接还能容纳的TCP数据（最大0xFFFF）
#define cTCP_WS				1460	// 定义本地窗口，必须满足条件：cTCP_MSS <= cTCP_MSS <= 0xFFFF
    UINT16 TcpChkSum;
    UINT16 UrgPoint;				// 紧急指针
    //	UINT16 OptData[2];
    // 最长TCP报文大小（头选项之一）：字节（最大1460）
#define cTCP_MSS     		1460	// 定义本地最大TCP报文长度
}TcpHdr_Stru;

// TCP 本地初始32位序号
extern volatile UINT16 guwISN[2];

// TCP头的常数指针。
#define cpTcpHdrBuf		((UINT16 *)&guwEthBuf[cEthHdrLen + cIpHdrLen])			// 指向Word的buffer
#define cptTcpHdrBuf	((TcpHdr_Stru *)&guwEthBuf[cEthHdrLen + cIpHdrLen])		// 指向结构

// TCP数据段指针
#define cpTcpData	((UINT16 *)&guwEthBuf[cEthHdrLen + cIpHdrLen + cTcpHdrLen])	// 指向Word的buffer

//---------------------------------------------------------------------------------

// ARP表结构
typedef struct{
    UINT16 IpAddr[2];
    UINT16 EthAddr[3];
    UINT16 Time2;		// 刷新时刻，2Hz的计数
    // ARP表记录的最大老化清除时间：20分钟（4.4BSD-Lite 默认）。
#define cArpMaxAge 20*60
}ArpEntries_Stru;

// 最大ARP表记录数
#define cArpTabSize 	16

// 分配ARP链表的内存
extern ArpEntries_Stru gstArpTab[cArpTabSize];

// ARP表记录的地址
#define cptArpTabStart		((ArpEntries_Stru *)&gstArpTab[0])				// 指向结构，开始地址指针
#define cptArpTabEnd		((ArpEntries_Stru *)&gstArpTab[cArpTabSize])	// 指向结构，结束地址指针

//---------------------------------------------------------------------------------

// TCP事务联接状态记录结构
typedef struct{
    UINT16 TcpStateFlags;		// TCP状态和标识
    // TCP 事务状态标识 Conn_Stru->TcpStateFlags
#define cTCP_CLOSED			0x00
#define cTCP_SYN_RCVD		0x01
#define cTCP_SYN_SENT		0x02
#define cTCP_ESTABLISHED	0x03
#define cTCP_FIN_WAIT_1		0x04
#define cTCP_FIN_WAIT_2		0x05
#define cTCP_CLOSING		0x06
#define cTCP_TIME_WAIT		0x07
#define cTCP_CLOSE_WAIT		0x08
#define cTCP_LAST_ACK		0x09
#define cTCP_TS_MASK		0x0f
#define cTCP_OUTSTANDING	0x10
#define cTCP_STOPPED		0x20
    UINT16 LocalPort;			// 本地端口
    UINT16 RemotePort;			// 远端端口
    UINT16 RemoteIpAddr[2];		// 远端IP
    UINT16 RcvNum[2];			// 下次接收包的远端32位Seq序号
    UINT16 AckNum[2];			// 下次接收包的远端32位Ack序号
    UINT16 SeqNum[2];		    // 本地当前包32位Seq序号
    UINT16 MaxSegSize;          // 本连接事务使用的最长TCP报文大小，详见TCP头结构说明
    UINT16 Timer;				// 状态需要等待的时间
    UINT16 NumRetran;			// 重传次数
    UINT16 PollTime;			// 空闲时间计数
    // 由于TCP事务轮询时间为1秒，所以300秒空闲就异常终止当前连接。（WIN2K用900秒）
#define cTCP_MAX_POLL	300
}Conn_Stru;

// TCP最大联接事务数。
#define cMaxConnetions		16

// 分配TCP最大联接事务链表内存
extern Conn_Stru gstConns[cMaxConnetions];

// TCP最大联接事务记录表首地址
#define cptConnsStart		((Conn_Stru *)&gstConns[0])				// 指向结构
// TCP最大联接事务记录表结束地址
#define cptConnsEnd		((Conn_Stru *)&gstConns[cMaxConnetions])	// 指向结构

// 用于RTT估计器的重传指数退避时间，公式： T = cTCP_RTO * 2^n （n表示第几次重传）
#define cTCP_RTO	3

// TCP超时关闭联接的时间，即在TIME_WAIT状态的联接保持时间
#define cTCP_TIME_WAIT_2MSL		120		// 120 秒（因为TCP事务1秒轮询1次）

// TCP最大重传次数
#define cTCP_MAXRTX		3

// 本地TCP端口范围
#define cLocalPortStart	4096	// 开始：0x1000
#define cLocalPortEnd	28672	// 结束：0x7000

// TCP最大侦听端口数。除非作为Web服务器，否则通常为1
#define cMaxListenPorts		8	// 本应用允许侦听端口

// 当前TCP事务联接指针
extern Conn_Stru *gptConn;

// 分配TCP侦听端口号链表内存
extern UINT16 guwListenPorts[cMaxListenPorts];

//---------------------------------------------------------------------------------

// 其它定义

// 正在处理包的字节长度（byte）。这个值随处理正在处理的协议层的不同而改变！
extern volatile UINT16 guwEthLen;

// TCP/IP协议栈和应用程序间通讯的变量
extern volatile UINT16 guwFlags;
// 协议层通过guwFlags与应用层的联系常数定义
#define cTCP_ACKDATA	0x01	// 上次发的数据已经被确认，通知应用程序可以发新的数据
#define cTCP_NEWDATA	0x02	// 远端发给本地数据包，协议层需要ACK回应
#define cTCP_REXMIT		0x04	// 通知应用程序重发上次的数据包
#define cTCP_POLL		0x08	// 如果应用程序等待发数据，就给它一个标识POLL
#define cTCP_CLOSE		0x10	// 远端已经关闭联接，或应用程序要关闭联接
#define cTCP_ABORT		0x20	// 远端要放弃联接，或应用程序要放弃联接
#define cTCP_CONNECTED	0x40	// 联接成功建立
#define cTCP_TIMEDOUT	0x80	// 超过重传次数，放弃联接

// cTCP_DATA：msip_Process()的入口参数，表示需要处理已经在guwEthBuf缓冲区的包。
// cTCP_TIMER：msip_Process()的入口参数，表示需要做周期性的TCP事务处理。
#define cTCP_DATA    1
#define cTCP_TIMER   2

//---------------------------------------------------------------------------------
// 以太收发功能

// ether_Send(): 发送以太包宏定义，兼容性定义
#define ether_Send()		RTL8019AS_TX(guwEthLen, cpEthHdrBuf)

// ether_Receive(): 接收以太包宏定义，兼容性定义
#define ether_Receive()		RTL8019AS_RX(cpEthHdrBuf)

//---------------------------------------------------------------------------------
// ARP 功能过程

// msip_Arp_Timer()：ARP表老化扫描，每8秒执行1次(BSD default 10 seconds)
// 超过20分钟(BSD default)未变化的，将被删除！
extern void msip_Arp_Time(void);

// msip_Arp_Update()：ARP表更新过程。
// uwIpAddr：IP地址
// uwEthAddr：物理地址
// 返回更新的ARP表的地址。如果地址在表外，说明更新失败。
extern ArpEntries_Stru *msip_Arp_Update(UINT16 *uwIpAddr, UINT16 *uwEthAddr);

// msip_Arp_In()：如果检测到ARP包输入就执行。
// 如果远端ARP请求，过程发送ARP回应。
// 如果远端ARP回应，过程更新ARP表。
extern void msip_Arp_In(void);

// msip_Arp_Out()：将待发送的IP包封装以太头，并发送封装好的以太包
// pARPTAB：指向ARP表中远端IP和物理地址的影射表记录地址
//       如果pARP是空指针，原IP包将被破坏，并且用ARP请求包替代发送。
extern void msip_Arp_Out(ArpEntries_Stru *pARPTAB);

//---------------------------------------------------------------------------------
// TCP/IP 功能：

// msip_TcpChkSum()：TCP/IP校验和过程。
extern UINT16 msip_TcpChkSum(void);

// msip_Process(): TCP/IP 全处理过程
// uwFlag：处理类型，见cTCP_DATA和cTCP_TIMER
// pConn：TCP事件指针
extern void msip_Process(UINT16 uwFlag);

// 系统接口类：

// msip_Init(): TCP/IP功能初始化，必须在其它TCP/IP处理前调用。包含ARP、被动侦听端口和TCP事务连接
extern void msip_Init(void);

// msip_Periodic(): TCP/IP事务周期轮询过程，1秒发生1次
extern void msip_Periodic(void);

// msip_Input(): 如果输入的是IP包，接执行改过程。
#define msip_Input()	msip_Process(cTCP_DATA)

// msip_APPCALL(): 供用户写TCP应用代码的函数名。
#define userapp		msip_APPCALL	// 指向RS232应用

// 应用程序接口类：（应用层控制协议层状态变迁）

// msip_Listen(): TCP/IP被动侦听本地端口是否被占用！用于服务端
// uwPort：本地TCP端口
// 返回0：表示端口被用
// 返回1：表示建立成功
extern UINT16 msip_Listen(UINT16 uwPort);

// msip_Connect(): TCP/IP建立主动联接远端，用于客户端
// uwLocalPort：本地TCP端口
// puwRemoteIpAddr：远端IP地址
// uwRemotePort：远端TCP端口
// 返回0：表示建立失败
// 返回1：表示建立成功
#if  TCP_ACTIVE_OPEN == 1
extern UINT16 msip_Connect(UINT16 uwLocalPort, UINT16 *puwRemoteIpAddr, UINT16 uwRemotePort);
#endif

// msip_Send()：发送数据到当前的连接，保留的uIP定义，我们不用
#define msip_Send()

// msip_DataLen()：当前TCP数据段的长度（Bytes），保留的uIP定义，我们不用
#define msip_DataLen()		guwEthLen

// msip_Close(): 主动关闭当前连接，应用层通知协议层正常关闭当前连接（FIN）
#define msip_Close()	(guwFlags = cTCP_CLOSE)

// msip_Abort()：异常关闭当前连接，应用层通知协议层复位当前连接（RST）
#define msip_Abort()	(guwFlags = cTCP_ABORT)

// msip_Stop(): 停止接收含TCP数据段的包，应用层通知协议层将窗口尺寸设置为0，期待远端暂停发送带数据的TCP包！
#define msip_Stop()		(gptConn->TcpStateFlags |= cTCP_STOPPED)

// msip_Restart(): 重新开始当前的连接，应用层通知协议层重新开放窗口尺寸，以便允许远端发送带数据的TCP包！
#define msip_Restart()	{guwFlags |= cTCP_NEWDATA; 	gptConn->TcpStateFlags &= ~cTCP_STOPPED;}

// 测试判断接口类：（应用层查询协议层状态）

// msip_connected():
// 服务或服务都有效，表明当前连接建立成功！状态只会出现一次！
// 在客户模式可以传TCP数据；服务模式最好不发送数据！
#define msip_Connected()	(guwFlags & cTCP_CONNECTED)

// msip_Poll():
// 不论是服务或客户，都表明协议层处于连接空闲状态！标识由TCP事件轮询传回，在这个状态下可设置
// 空闲计数器记录空闲次数，达到一定时间就异常终止连接！如果这样做，就不能在这个状态发送数据！
// 允许发送数据的条件是：((guwEthLen > 0) || (guwFlags & cTCP_NEWDATA))
#define msip_Poll()		(guwFlags & cTCP_POLL)

// msip_NewData()：处于ESTABLELISH状态
//（guwEthLen > 0）协议层收到远端发出TCP数据包，并期待应用层处理：在这个状态下，允许只
// 发送无TCP数据的ACK确认（设置：guwEthLen = 0），或者发送带TCP数据的ACK确认（把要发送的
// TCP数据长度设置给guwEthLen）。
#define msip_NewData()	(guwFlags & cTCP_NEWDATA)

// msip_Acked()：处于ESTABLELISH状态
//（guwEthLen = 0）协议层收到远端发出ACK确认包。在这个状态下，允许发送带TCP数据的ACK
// 确认（把要发送的TCP数据长度设置给guwEthLen），或者不响应。
#define msip_Acked()		(guwFlags & cTCP_ACKDATA)

// mip_Reset_Acked(): 清除确认后的标志，好象没有用？！（也许用于重传）
#define mip_Reset_Acked()	(guwFlags &= ~cTCP_ACKDATA)

// msip_Rexmit(): 应用层上次的以发数据需要重传，标识由TCP事件轮询传回！应用层不允许更改guwEthLen的值！！！
#define msip_Rexmit()	(guwFlags & cTCP_REXMIT)

// msip_Stopped(): 当前连接已经停止接收含TCP数据段的包，连接是正常的。
#define msip_Stopped()	(gptConn->TcpStateFlags & cTCP_STOPPED)

// msip_Aborted(): 当前连接已经异常关闭，协议层发送RST复位包。
#define msip_Aborted()	(guwFlags & cTCP_ABORT)

// msip_Closed(): 当前连接已经正常关闭，应用层发送FIN包
#define msip_Closed()	(guwFlags & cTCP_CLOSE)

// msip_TimedOut(): 当前连接时间溢出，并且连接因时间溢出异常关闭，协议层发送RST复位包。
#define msip_TimedOut()	(guwFlags & cTCP_TIMEDOUT)

// 附加接口类：-------------------------------------------------------------------

// msip_MSS(): 读 TCP/IP 的MSS，以决定将要发送的数据长度远端是否能接受。
#define msip_MSS()		(gptConn->MaxSegSize)

//--------------------------------------------------------------------------------------


#endif
