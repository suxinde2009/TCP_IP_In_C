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


#include "tcpip.h"

#if TCP_DHCP == 0
const UINT16 guwIpAddr[2] = {((cIpAddr1<<8)|cIpAddr2), ((cIpAddr3<<8)|cIpAddr4)};
#else
UINT16 guwIpAddr[2];
#endif

#if TCP_DHCP == 0
const UINT16 guwNetMask[2] = {((cNetMask1<<8)|cNetMask2), ((cNetMask3<<8)|cNetMask4)};
#else
UINT16 guwNetMask[2];
#endif

#if TCP_DHCP == 0
const UINT16 guwDR_IpAddr[2] = {((cDR_IpAddr1<<8)|cDR_IpAddr2), ((cDR_IpAddr3<<8)|cDR_IpAddr4)};
#else
UINT16 guwDR_IpAddr[2];
#endif

const UINT16 guwEthAddr[3] = {((cEthAddr1<<8)|cEthAddr2), ((cEthAddr3<<8)|cEthAddr4), ((cEthAddr5<<8)|cEthAddr6)};



// 最大允许的以太包缓冲区
UINT16 guwEthBuf[cEthBufSize];

// 正在处理包的字节长度。这个值随处理层的不同而改变！
volatile UINT16 guwEthLen = 0;

// 分配ARP表的内寸
ArpEntries_Stru		gstArpTab[cArpTabSize];

// 记录本地IP序号
volatile UINT16 guwIpId;

// TCP 本地初始32位序号
volatile UINT16 guwISN[2];

// 记录TCP本地端口号
UINT16 guwListenPorts[cMaxListenPorts];

// TCP最大联接事务记录表
Conn_Stru			gstConns[cMaxConnetions];

// 当前TCP事务联接指针
Conn_Stru *gptConn;

// TCP/IP协议栈和应用程序间通讯的变量
volatile UINT16 guwFlags;

//--------------------------------------------------------------------------------------
void msip_Init(void){
    UINT16 index;
    
    // Initialize ArpEntries
    for (index = 0; index < cArpTabSize; index++){
        gstArpTab[index].IpAddr[0] = 0;
        gstArpTab[index].IpAddr[1] = 0;
    }
    
    // Initialize Listen Ports
    for (index = 0; index < cMaxListenPorts; index++)
        guwListenPorts[index] = 0;
    
    // Initialize Listen Ports
    for (index = 0; index < cMaxConnetions; index++){
        gstConns[index].TcpStateFlags = cTCP_CLOSED;
        gstConns[index].PollTime = 0;
    }
    
}

//--------------------------------------------------------------------------------------
void msip_Arp_Time(){
    ArpEntries_Stru *pARP;
    
    for (pARP = cptArpTabStart; pARP < cptArpTabEnd; pARP++){
        if (((pARP->IpAddr[0] | pARP->IpAddr[1]) != 0) && ((guwTime2 - pARP->Time2) > 2*cArpMaxAge)){
            pARP->IpAddr[0] = 0;
            pARP->IpAddr[1] = 0;
        }
    }
    
    guwMsg_Route &= ~cM_ARP_TIME;	// 清除ARP表老化处理事件
}

//--------------------------------------------------------------------------------------
ArpEntries_Stru *msip_Arp_Update(UINT16 *uwIpAddr, UINT16 *uwEthAddr){
    ArpEntries_Stru *pARPTAB, *pARPTAB1;
    UINT16 maxtime,cmptime;
    
    // 如果接收包的源地址与本地相同，说明是DDoS攻击！！！
    if ((uwIpAddr[0] == guwIpAddr[0]) && (uwIpAddr[1] == guwIpAddr[1])){
        return cptArpTabEnd;
    }
    
    // 如果找到匹配的IP，就更新MAC
    for (pARPTAB = cptArpTabStart; pARPTAB < cptArpTabEnd; pARPTAB++){
        if((pARPTAB->IpAddr[0] == uwIpAddr[0]) && (pARPTAB->IpAddr[1] == uwIpAddr[1])){
            goto Arp_Update_Exit2;	// 更新 MAC/Time
        }
    }
    
    // 没有找到匹配IP，找个空记录来更新
    for (pARPTAB = cptArpTabStart; pARPTAB < cptArpTabEnd; pARPTAB++){
        if((pARPTAB->IpAddr[0] | pARPTAB->IpAddr[1]) == 0){
            goto Arp_Update_Exit1;	// 更新 IP/MAC/Time
        }
    }
    
    // 既没有匹配IP，又没有空记录！把时间最长的记录更新
    maxtime = 0;
    for (pARPTAB1 = cptArpTabStart; pARPTAB1 < cptArpTabEnd; pARPTAB1++){
        cmptime = guwTime2 - pARPTAB1->Time2;	// 计算记录存放时间
        if(cmptime > maxtime){
            maxtime = cmptime;			// 记录最大时间
            pARPTAB = pARPTAB1;				// 记录ARP表指针
        }
    }
    
Arp_Update_Exit1:
    pARPTAB->IpAddr[0] = uwIpAddr[0];
    pARPTAB->IpAddr[1] = uwIpAddr[1];
    
Arp_Update_Exit2:
    pARPTAB->EthAddr[0] = uwEthAddr[0];
    pARPTAB->EthAddr[1] = uwEthAddr[1];
    pARPTAB->EthAddr[2] = uwEthAddr[2];
    pARPTAB->Time2 = guwTime2;
    
    return pARPTAB;
}

//--------------------------------------------------------------------------------------
void msip_Arp_In(void){
    
    // 如果接收包的源地址与本地相同，说明是DDoS攻击！！！
    if ((cptArpHdrBuf->SndIpAddr[0] == guwIpAddr[0]) &&
        (cptArpHdrBuf->SndIpAddr[1] == guwIpAddr[1])){
        goto arp_in_exit;
    }
    
    // 如果不是请求本地，就退出！
    if ((cptArpHdrBuf->RcvIpAddr[0] != guwIpAddr[0]) ||
        (cptArpHdrBuf->RcvIpAddr[1] != guwIpAddr[1])){
        goto arp_in_exit;
    }
    
    switch (cptArpHdrBuf->OpCode){
        case cArpRequest:
            // 如果是ARP请求，就构造ARP回应
            cptEthHdrBuf->DestEthAddr[0] = cptArpHdrBuf->SndEthAddr[0];
            cptArpHdrBuf->RcvEthAddr[0] = cptArpHdrBuf->SndEthAddr[0];
            
            cptEthHdrBuf->DestEthAddr[1] = cptArpHdrBuf->SndEthAddr[1];
            cptArpHdrBuf->RcvEthAddr[1] = cptArpHdrBuf->SndEthAddr[1];
            
            cptEthHdrBuf->DestEthAddr[2] = cptArpHdrBuf->SndEthAddr[2];
            cptArpHdrBuf->RcvEthAddr[2] = cptArpHdrBuf->SndEthAddr[2];
            
            cptEthHdrBuf->SrcEthAddr[0] = guwEthAddr[0];
            cptArpHdrBuf->SndEthAddr[0] = guwEthAddr[0];
            
            cptEthHdrBuf->SrcEthAddr[1] = guwEthAddr[1];
            cptArpHdrBuf->SndEthAddr[1] = guwEthAddr[1];
            
            cptEthHdrBuf->SrcEthAddr[2] = guwEthAddr[2];
            cptArpHdrBuf->SndEthAddr[2] = guwEthAddr[2];
            
            cptArpHdrBuf->RcvIpAddr[0] = cptArpHdrBuf->SndIpAddr[0];
            cptArpHdrBuf->RcvIpAddr[1] = cptArpHdrBuf->SndIpAddr[1];
            cptArpHdrBuf->SndIpAddr[0] = guwIpAddr[0];
            cptArpHdrBuf->SndIpAddr[1] = guwIpAddr[1];
            
            cptArpHdrBuf->OpCode = cArpReply;
            // cptEthHdrBuf->EthType: is unchanged
            // cptArpHdrBuf->HwType: is unchanged
            // cptArpHdrBuf->ProtoType: is unchanged
            // cptArpHdrBuf->HwLen8Proto8:  is unchanged
            
            // 发送以太包
            guwEthLen = 60;
            ether_Send();
            break;
        case cArpReply:
            // 如果是ARP回应，就更新ARP表
            msip_Arp_Update(cptArpHdrBuf->SndIpAddr, cptArpHdrBuf->SndEthAddr);
    }
    
arp_in_exit:
    
    // 释放缓冲区
    guwEthLen = 0;
}


//--------------------------------------------------------------------------------------
void msip_Arp_Out(ArpEntries_Stru *pARPTAB){
    
    // 如果指针是否在ARP表范围内，就构造以太头
    if ((pARPTAB >= cptArpTabStart) && (pARPTAB < cptArpTabEnd)){
        goto build_eth;
    }
    
    // 指针不在ARP范围，检查远端IP是否在本地网内，以决定ARP请求的远端IP地址
    if (((cptIpHdrBuf->DestIpAddr[0] & guwNetMask[0]) == (guwIpAddr[0] & guwNetMask[0])) &&
        ((cptIpHdrBuf->DestIpAddr[1] & guwNetMask[1]) == (guwIpAddr[1] & guwNetMask[1]))){
        // IP在本地网内，在ARP表里查找对应远端IP地址的表指针
        for (pARPTAB = cptArpTabStart; pARPTAB < cptArpTabEnd; pARPTAB++){
            
            if((pARPTAB->IpAddr[0] == cptIpHdrBuf->DestIpAddr[0]) &&
               (pARPTAB->IpAddr[1] == cptIpHdrBuf->DestIpAddr[1])){
                
                goto build_eth;
            }
        }
        
        goto request_local;
        
    } else {
        // 远端IP不在本地网内，在ARP表里查找网关IP地址的表指针
        for (pARPTAB = cptArpTabStart; pARPTAB < cptArpTabEnd; pARPTAB++){
            
            if((pARPTAB->IpAddr[0] == guwDR_IpAddr[0]) && (pARPTAB->IpAddr[1] == guwDR_IpAddr[1])){
                
                goto build_eth;
            }
        }
        
        //goto request_gateway;
    }
    
    
    // 如果到这里，表明在ARP表里找不到相应的IP记录！所以构造需要的ARP请求包
request_gateway:
    cptArpHdrBuf->RcvIpAddr[0] = guwDR_IpAddr[0];
    cptArpHdrBuf->RcvIpAddr[1] = guwDR_IpAddr[1];
    goto build_arp;
    
request_local:
    cptArpHdrBuf->RcvIpAddr[0] = cptIpHdrBuf->DestIpAddr[0];
    cptArpHdrBuf->RcvIpAddr[1] = cptIpHdrBuf->DestIpAddr[1];
    
build_arp:
    cptArpHdrBuf->SndIpAddr[0] = guwIpAddr[0];
    cptArpHdrBuf->SndIpAddr[1] = guwIpAddr[1];
    
    cptEthHdrBuf->DestEthAddr[0] = 0xffff;
    cptEthHdrBuf->DestEthAddr[1] = 0xffff;
    cptEthHdrBuf->DestEthAddr[2] = 0xffff;
    
    cptArpHdrBuf->RcvEthAddr[0] = 0x0000;
    cptArpHdrBuf->RcvEthAddr[1] = 0x0000;
    cptArpHdrBuf->RcvEthAddr[2]	= 0x0000;
    
    cptEthHdrBuf->SrcEthAddr[0] = guwEthAddr[0];
    cptArpHdrBuf->SndEthAddr[0] = guwEthAddr[0];
    
    cptEthHdrBuf->SrcEthAddr[1] = guwEthAddr[1];
    cptArpHdrBuf->SndEthAddr[1] = guwEthAddr[1];
    
    cptEthHdrBuf->SrcEthAddr[2] = guwEthAddr[2];
    cptArpHdrBuf->SndEthAddr[2] = guwEthAddr[2];
    
    cptEthHdrBuf->EthType = cEthType_Arp;
    cptArpHdrBuf->HwType = cHwType_Eth;
    cptArpHdrBuf->ProtoType = cEthType_Ip;
    cptArpHdrBuf->Hw8Proto8 = c_vIP4;
    cptArpHdrBuf->OpCode = cArpRequest;
    
    guwEthLen = 60;
    goto send_eth;	// 跳到发送以太包处理
    
build_eth:
    // 构造需要的以太头
    cptEthHdrBuf->DestEthAddr[0] = pARPTAB->EthAddr[0];
    cptEthHdrBuf->DestEthAddr[1] = pARPTAB->EthAddr[1];
    cptEthHdrBuf->DestEthAddr[2] = pARPTAB->EthAddr[2];
    cptEthHdrBuf->SrcEthAddr[0] = guwEthAddr[0];
    cptEthHdrBuf->SrcEthAddr[1] = guwEthAddr[1];
    cptEthHdrBuf->SrcEthAddr[2] = guwEthAddr[2];
    cptEthHdrBuf->EthType = cEthType_Ip;
    
    if ((guwEthLen += 2*cEthHdrLen) < 60){
        guwEthLen = 60;
    }
    
send_eth:
    ether_Send();		// 发送以太包
    guwEthLen = 0;		// 释放缓冲区
}

//--------------------------------------------------------------------------------------
#if  TCP_ACTIVE_OPEN == 1
UINT16 msip_Connect(UINT16 uwLocalPort, UINT16 *puwRemoteIpAddr, UINT16 uwRemotePort){
    Conn_Stru *pConn;
    
    // 检查本地端口是否在本机指定的范围内
    if ((uwLocalPort < cLocalPortStart) && (uwLocalPort > cLocalPortEnd)){
        return 0;
    }
    
    // 检查本地端口是否已经分配或占用
    for (pConn = cptConnsStart; pConn < cptConnsEnd; pConn++){
        if ((pConn->TcpStateFlags != cTCP_CLOSED) && (pConn->LocalPort == uwLocalPort)){
            return 0;
        }
    }
    
    // 查找TCP事务中的未使用联接（或已经关闭的联接）
    for (pConn = cptConnsStart; pConn < cptConnsEnd; pConn++){
        if (pConn->TcpStateFlags == cTCP_CLOSED){
            // 构造一个主动联接事务
            pConn->TcpStateFlags = cTCP_SYN_SENT|cTCP_OUTSTANDING;
            
            pConn->SeqNum[0] = guwISN[0];
            pConn->SeqNum[1] = guwISN[1];
            
            pConn->AckNum[0] = guwISN[0];
            pConn->AckNum[1] = guwISN[1];
            if (++pConn->AckNum[1] == 0){
                ++pConn->AckNum[0];
            }
            
            pConn->NumRetran = 0;
            pConn->Timer = 1;
            pConn->LocalPort = uwLocalPort;
            pConn->RemotePort = uwRemotePort;
            pConn->RemoteIpAddr[0] = puwRemoteIpAddr[0];
            pConn->RemoteIpAddr[1] = puwRemoteIpAddr[1];
            pConn->MaxSegSize = 0;	// 远端未知，初始化为：0
            
            return 1;
        }
    }
    // 找不到空闲的TCP联接！
    return 0;
}
#endif

//--------------------------------------------------------------------------------------
UINT16 msip_Listen(UINT16 uwPort){
    UINT16 index;
    for (index = 0; index < cMaxListenPorts; index++){
        if (guwListenPorts[index] == 0){
            guwListenPorts[index] = uwPort;
            return 1;
        }
    }
    return 0;
}

//--------------------------------------------------------------------------------------
UINT16 msip_TcpChkSum(void){
    UINT16 SUM , temp;
    
    // 获取TCP段字节长度
    temp = cptIpHdrBuf->Len - ((cptIpHdrBuf->Vhl & 0x0f) << 2);
    
    // 计算TCP头和数据段的校验和
    SUM = checksum(temp, cpTcpHdrBuf);
    
    // 累加计算伪TCP头的校验和
    
    // 16bit TCP length
    if ((SUM += temp) < temp)
        ++SUM;
    
    // 8bit Protocol
    if ((SUM += cptIpHdrBuf->Proto) < cptIpHdrBuf->Proto)
        ++SUM;
    
    // Source IP Address
    if ((SUM += cptIpHdrBuf->SrcIpAddr[0]) < cptIpHdrBuf->SrcIpAddr[0])
        ++SUM;
    
    if ((SUM += cptIpHdrBuf->SrcIpAddr[1]) < cptIpHdrBuf->SrcIpAddr[1])
        ++SUM;
    
    // Destination IP Address
    if ((SUM += cptIpHdrBuf->DestIpAddr[0]) < cptIpHdrBuf->DestIpAddr[0])
        ++SUM;
    
    if ((SUM += cptIpHdrBuf->DestIpAddr[1]) < cptIpHdrBuf->DestIpAddr[1])
        ++SUM;
    
    return SUM;
}

//--------------------------------------------------------------------------------------
void msip_Periodic(){
    // 增加初始序号
    if (++guwISN[1] == 0){
        ++guwISN[0];
    }
    
    for (gptConn = cptConnsStart; gptConn < cptConnsEnd; gptConn++){
        msip_Process(cTCP_TIMER);
    }
    
    guwMsg_Route &= ~cM_TCP_PERIODIC;	// 清除TCP轮询事件
    
}

//--------------------------------------------------------------------------------------
void msip_Process(UINT16 uwFlag){
    ArpEntries_Stru *pARP = cptArpTabEnd;	// 给他一个等价的空指针
    UINT16 i,j;
    
    switch (uwFlag){
        case cTCP_DATA:			// IP输入处理
            goto ip_input;
        case cTCP_TIMER:		// 检验是否TCP事务论询
            // goto tcp_Periodic;
    }
    
tcp_Periodic:
    
    guwEthLen = 0;
    
    if ((gptConn->TcpStateFlags == cTCP_TIME_WAIT) ||
        (gptConn->TcpStateFlags == cTCP_FIN_WAIT_2)){	// TIMER_WAIT状态：2MSL等待！
        
        if (++gptConn->Timer == cTCP_TIME_WAIT_2MSL){	// 记录等待超时时间，并判断超时
            gptConn->TcpStateFlags = cTCP_CLOSED;		// 超时关闭联接
        }
        
    } else if (gptConn->TcpStateFlags != cTCP_CLOSED){	// 如果是已经关闭的事务，就跳过！
        
        // 如果在OUTSTANDING状态（本地已经发出包，但没有收到回应），需要特殊的重传处理！
        if (gptConn->TcpStateFlags & cTCP_OUTSTANDING){
            
            if (--gptConn->Timer == 0){		// 记录等待时间，并校验是否等待时间已过
                
                if (gptConn->NumRetran == cTCP_MAXRTX){		// 记录重传次数，并校验是否到达最大重传次数
                    
                    // 超过重传次数......
                    gptConn->TcpStateFlags = cTCP_CLOSED;	// 关闭联接
                    
                    // 通知应用程序时间益出
                    guwFlags = cTCP_TIMEDOUT;
                    msip_APPCALL();
                    
                    // 发RSTACK包通知确认给远端：本地已经异常停止连接！
                    cptTcpHdrBuf->Flags = cTCP_RST | cTCP_ACK;
                    
                    goto tcp_send_nodata;
                }
                
                // 等待时间的指数退避
                gptConn->Timer = cTCP_RTO << (gptConn->NumRetran > 4 ? 4 : gptConn->NumRetran);
                
                ++gptConn->NumRetran;	// 记录重传次数
                
                // 重传处理变迁
                switch (gptConn->TcpStateFlags & cTCP_TS_MASK){
                    case cTCP_SYN_RCVD:		// SYN_RCVD状态：发送SYNACK包
                        goto tcp_send_synack;
                        
#if TCP_ACTIVE_OPEN == 1
                    case cTCP_SYN_SENT:		// SYN_SENT状态：重发SYN包。
                        cptTcpHdrBuf->Flags = 0;
                        goto tcp_send_syn;
#endif
                        
                    case cTCP_ESTABLISHED:	// ESTABLISHED状态：通知应用程序，需要重传上次发出的数据包！！！
                        guwEthLen = 0;
                        guwFlags = cTCP_REXMIT;
                        msip_APPCALL();
                        goto apprexmit;
                        
                    case cTCP_CLOSE_WAIT:
                    case cTCP_LAST_ACK:			// LAST_ACK状态，结束当前连接！
                        goto tcp_send_finack;	// 重发FINACK包
                    case cTCP_FIN_WAIT_1:
                        goto tcp_send_finack;	// 重发FINACK包
                    case cTCP_FIN_WAIT_2:
                    case cTCP_CLOSING:
                    case cTCP_TIME_WAIT:
                }
            }
        } else if ((gptConn->TcpStateFlags & cTCP_TS_MASK) == cTCP_ESTABLISHED){
            // ESTABLISHED状态，通知应用程序允许发送数据。
            guwEthLen = 0;
            guwFlags = cTCP_POLL;
            msip_APPCALL();
            goto appsend;
        }
    }
    
    goto drop;
    
    // IP输入处理线程
ip_input:
    
    // IP头校验：IP version and header length. vIP4
    if(cptIpHdrBuf->Vhl != cIP_VER_HLEN){
        goto drop;
    }
    
    // IP分片校验：必须是最后帧才响应（隐含默认：不分片帧）。
    if (cptIpHdrBuf->Flags & cIP_MF){
        goto drop;
    }
    
    // 接收IP包的目标IP地址与本地不相同，丢弃！
    if((cptIpHdrBuf->DestIpAddr[0] != guwIpAddr[0]) ||
       (cptIpHdrBuf->DestIpAddr[1] != guwIpAddr[1])){
        goto drop;
    }
    
    // 接收IP包的源地址是与本地相同，丢弃！说明远端在做 DDos 攻击！！！！
    if((cptIpHdrBuf->SrcIpAddr[0] == guwIpAddr[0]) &&
       (cptIpHdrBuf->SrcIpAddr[1] == guwIpAddr[1])){
        goto drop;
    }
    
    // IP校验和：错误丢弃！
    i = ((cptIpHdrBuf->Vhl & 0x0f) << 2);
    if (checksum(i, cpIpHdrBuf) != 0xffff){
        goto drop;
    }
    
    // 合法IP包：获取IP包缓冲区长度
    guwEthLen = cptIpHdrBuf->Len;
    
    // 合法IP包：更新ARP表，并记录更新后的映射表指针位置。
    pARP = msip_Arp_Update(cptIpHdrBuf->SrcIpAddr,cptEthHdrBuf->SrcEthAddr);
    
    
    // IP协议分组
    switch(cptIpHdrBuf->Proto){
        case cIP_PROTO_ICMP:				// 是否是ICMP包？
            goto icmp_input;
        case cIP_PROTO_TCP:					// 是否TCP包？
            goto tcp_input;
        default:							// 不是我们能处理的包，丢弃！
            goto drop;
    }
    
    
    // ICMP处理线程
icmp_input:
    
    // ICMP处理：只接受 ping 呼叫，否则丢弃！
    if (cptIcmpHdrBuf->Type != cICMP_ECHO){
        goto drop;
    }
    
    // 校验 ICMP CheckSum
    i = cptIpHdrBuf->Len - ((cptIpHdrBuf->Vhl & 0x0f) << 2);
    if (checksum(i, cpIcmpHdrBuf) != 0xffff){
        goto drop;
    }
    
    // 处理ICMP的 ping 回应
    cptIcmpHdrBuf->Type = cICMP_ECHO_REPLY;
    
    // 计算 ICMP PING REPLY ChkSum
    if((cptIcmpHdrBuf->ChkSum += (cICMP_ECHO << 8)) < (cICMP_ECHO << 8)){
        cptIcmpHdrBuf->ChkSum += 1;
    }
    
    // Swap IP addresses.
    cptIpHdrBuf->SrcIpAddr[0]  ^= cptIpHdrBuf->DestIpAddr[0];
    cptIpHdrBuf->DestIpAddr[0] ^= cptIpHdrBuf->SrcIpAddr[0];
    cptIpHdrBuf->SrcIpAddr[0]  ^= cptIpHdrBuf->DestIpAddr[0];
    
    cptIpHdrBuf->SrcIpAddr[1]  ^= cptIpHdrBuf->DestIpAddr[1];
    cptIpHdrBuf->DestIpAddr[1] ^= cptIpHdrBuf->SrcIpAddr[1];
    cptIpHdrBuf->SrcIpAddr[1]  ^= cptIpHdrBuf->DestIpAddr[1];
    
    goto send;	// 发送IP包
    
    // TCP线程处理
tcp_input:
    
    // 校验 TCP checksum.
    if (msip_TcpChkSum() != 0xffff){
        goto drop;
    }
    
    // 是否是已经存在的TCP事务联接
    for (gptConn = cptConnsStart; gptConn < cptConnsEnd; gptConn++){
        
        if  ((gptConn->TcpStateFlags != cTCP_CLOSED) &&
             (cptIpHdrBuf->SrcIpAddr[0] == gptConn->RemoteIpAddr[0]) &&
             (cptIpHdrBuf->SrcIpAddr[1] == gptConn->RemoteIpAddr[1]) &&
             (cptTcpHdrBuf->DestPort == gptConn->LocalPort) &&
             (cptTcpHdrBuf->SrcPort == gptConn->RemotePort)){
            
            goto found;
        }
    }
    
    // 如果是不存在的TCP事务：（远端发同步连接请求）
    if (cptTcpHdrBuf->Flags & cTCP_SYN){
        // 1）如果是SYN请求联接包，就侦听本地联接
        for (i = 0; (i < cMaxListenPorts) && (guwListenPorts[i] != 0); i++){
            if (cptTcpHdrBuf->DestPort == guwListenPorts[i]){
                goto found_listen;
            }
        }
    }
    
    // 2）如果也不是SYN请求联接包，就发送RSTACK，通知远端本地异常终止该连接！！！（半打开状态）
    // goto reset;	// UIP模式
    goto drop;		// 采用丢弃，防止不相关DDoS攻击！！！
    
    
reset:	// 本地异常终止连接处理：发送 RSTACK 包
    
    // 如果接到的是RSTACK包，不响应！
    if (cptTcpHdrBuf->Flags & cTCP_RST){
        goto drop;
    }
    
    // 准备发送RSTACK包
    guwEthLen = 2*(cIpHdrLen + cTcpHdrLen);
    cptTcpHdrBuf->HdrLen = cTCP_HDR_NOOPT;
    cptTcpHdrBuf->Flags = cTCP_RST|cTCP_ACK;
    
    // 直接使用远端的SeqNum和AckNum变换为本地的......
    cptTcpHdrBuf->SeqNum[0] ^= cptTcpHdrBuf->AckNum[0];
    cptTcpHdrBuf->AckNum[0] ^= cptTcpHdrBuf->SeqNum[0];
    cptTcpHdrBuf->SeqNum[0] ^= cptTcpHdrBuf->AckNum[0];
    cptTcpHdrBuf->SeqNum[1] ^= cptTcpHdrBuf->AckNum[1];
    cptTcpHdrBuf->AckNum[1] ^= cptTcpHdrBuf->SeqNum[1];
    cptTcpHdrBuf->SeqNum[1] ^= cptTcpHdrBuf->AckNum[1];
    
    // AckNum加1(SYN逻辑的需要)
    if (++cptTcpHdrBuf->AckNum[1] == 0){
        ++cptTcpHdrBuf->AckNum[0];
    }
    
    // 交换端口
    cptTcpHdrBuf->SrcPort ^= cptTcpHdrBuf->DestPort;
    cptTcpHdrBuf->DestPort ^= cptTcpHdrBuf->SrcPort;
    cptTcpHdrBuf->SrcPort ^= cptTcpHdrBuf->DestPort;
    
    // 交换IP
    cptIpHdrBuf->SrcIpAddr[0]  ^= cptIpHdrBuf->DestIpAddr[0];
    cptIpHdrBuf->DestIpAddr[0] ^= cptIpHdrBuf->SrcIpAddr[0];
    cptIpHdrBuf->SrcIpAddr[0]  ^= cptIpHdrBuf->DestIpAddr[0];
    cptIpHdrBuf->SrcIpAddr[1]  ^= cptIpHdrBuf->DestIpAddr[1];
    cptIpHdrBuf->DestIpAddr[1] ^= cptIpHdrBuf->SrcIpAddr[1];
    cptIpHdrBuf->SrcIpAddr[1]  ^= cptIpHdrBuf->DestIpAddr[1];
    
    // 发送RSTACK包
    goto tcp_send_noconn;
    
    // 如果接收的是SYN请求包，本地又有空闲的TCP事务连接
    // 1）创建TCP事务连接
    // 2）发送SYNACK，进入cTCP_SYN_RCVD|cTCP_OUTSTANDING状态
found_listen:
    // 查找空闲的TCP联接
    for (gptConn = cptConnsStart; gptConn < cptConnsEnd; gptConn++){
        if ((gptConn->TcpStateFlags == cTCP_CLOSED) ||
            (gptConn->TcpStateFlags == cTCP_TIME_WAIT)){
            goto found_unused_connection;
        }
    }
    
    goto drop;	// 没有空闲的TCP联接，进入异常终止远端处理！
    
    // 有空闲的TCP联接，回应远端的SYN请求
found_unused_connection:
    // 设置初始TCP联接事务状态
    gptConn->Timer = cTCP_RTO;
    gptConn->NumRetran = 0;
    gptConn->LocalPort = cptTcpHdrBuf->DestPort;
    gptConn->RemotePort = cptTcpHdrBuf->SrcPort;
    gptConn->RemoteIpAddr[0] = cptIpHdrBuf->SrcIpAddr[0];
    gptConn->RemoteIpAddr[1] = cptIpHdrBuf->SrcIpAddr[1];
    gptConn->TcpStateFlags = cTCP_SYN_RCVD|cTCP_OUTSTANDING;
    //-------------------------
    gptConn->SeqNum[0] = guwISN[0];
    gptConn->SeqNum[1] = guwISN[1];
    //-------------------------
    gptConn->AckNum[0] = guwISN[0];
    gptConn->AckNum[1] = guwISN[1];
    if (++gptConn->AckNum[1] == 0){
        ++gptConn->AckNum[0];
    }
    //-------------------------
    gptConn->RcvNum[0] = cptTcpHdrBuf->SeqNum[0];
    gptConn->RcvNum[1] = cptTcpHdrBuf->SeqNum[1];
    if (++gptConn->RcvNum[1] == 0){
        ++gptConn->RcvNum[0];
    }
    
    // 获取远端TCP报文长度。如果远端比本地小，就以远端为准。
    i = cptTcpHdrBuf->HdrLen;
    if (i > cTCP_HDR_NOOPT){
        i = (i - cTCP_HDR_NOOPT) << 1;	// Convert 32bit number to 16bit number.
        for (j = 0; j < i; j++){
            if (cpTcpData[j] == 0x0204){
                gptConn->MaxSegSize = cpTcpData[j + 1] > cTCP_MSS ? cTCP_MSS : cpTcpData[j + 1];
                break;
            }
        }
    }
    
    // 发送 SYNACK 包
#if TCP_ACTIVE_OPEN == 1
tcp_send_synack:
    cptTcpHdrBuf->Flags = cTCP_ACK;
tcp_send_syn:
    cptTcpHdrBuf->Flags |= cTCP_SYN;
#else
tcp_send_synack:
    cptTcpHdrBuf->Flags = cTCP_SYN|cTCP_ACK;
#endif
    
    // 给 SYNACK 包配置TCP头选项表
    cpTcpData[0] = 0x0204;		// 0x0204 表示最大报文段长度前缀
    cpTcpData[1] = cTCP_MSS;	// 最大报文段长度前缀
    cpTcpData[2] = 0x0101;		// 0x01表示无操作，0x00表示选项表结束
    cpTcpData[3] = 0x0402;		// 0x0402 表示 SACK 被允许
    guwEthLen = 2*cIpHdrLen + (cTCP_HDR_OPT << 2);
    cptTcpHdrBuf->HdrLen = cTCP_HDR_OPT;
    goto tcp_send;
    
    // 找到已经存在的TCP联接事物
found:
    guwFlags = 0;
    
    // 如果远端是RST包，就通知本地应用层：当前连接被远端异常终止！
    if (cptTcpHdrBuf->Flags & cTCP_RST){
        gptConn->TcpStateFlags = cTCP_CLOSED;
        guwFlags = cTCP_ABORT;
        msip_APPCALL();
        goto drop;
    }
    
    // 如果没有ACK标识，不响应！
    if (!(cptTcpHdrBuf->Flags & cTCP_ACK)){
        goto drop;
    }
    
    // 计算TCP数据段字节长度
    guwEthLen -= ((cptIpHdrBuf->Vhl & 0x0f) << 2) + (cptTcpHdrBuf->HdrLen << 2);
    
    
    // 检验远端的ACK序号是否我们期待的.....
    if ((cptTcpHdrBuf->AckNum[0] == gptConn->AckNum[0]) && (cptTcpHdrBuf->AckNum[1] == gptConn->AckNum[1])){
        
        gptConn->SeqNum[0] = gptConn->AckNum[0];
        gptConn->SeqNum[1] = gptConn->AckNum[1];
        
        gptConn->TcpStateFlags &= ~cTCP_OUTSTANDING;
        gptConn->Timer = cTCP_RTO;
        gptConn->NumRetran = 0;
        
        guwFlags = cTCP_ACKDATA;
    } else {
        goto drop;
    }
    
    // 根据不同的联接状态决定TCP状态变迁，并通知应用程序
    switch (gptConn->TcpStateFlags & cTCP_TS_MASK){
            // CLOSED和LISTEN状态不在这里处理
            // CLOSE_WAIT状态同样被忽略：因为一旦本地收到FIN，我们就强制应用层关闭，即从ESTABLISH到LAST_ACK
            
        case cTCP_SYN_RCVD:
            // 在SYN_RCVD状态下，我们收到远端ACK回应
            // 另一方面，如果已经存在cTCP_ACKDATA标识，就进入ESTABLISHED状态
            gptConn->TcpStateFlags = cTCP_ESTABLISHED;
            guwFlags = cTCP_CONNECTED;
            msip_APPCALL();
            goto appsend;
            
#if TCP_ACTIVE_OPEN == 1
        case cTCP_SYN_SENT:
            // 在SYN_SENT状态，我们收到远端SYNACK响应，本地发送ACK后就进入ESTABLISHED状态
            
            // 获取远端TCP报文长度。如果远端比本地小，就以远端为准。
            i = cptTcpHdrBuf->HdrLen;
            if (i > cTCP_HDR_NOOPT){
                i = (i - cTCP_HDR_NOOPT) << 1;
                for (j = 0; j < i; j++){
                    if (cpTcpData[j] == 0x0204){
                        gptConn->MaxSegSize = cpTcpData[j + 1] > cTCP_MSS ? cTCP_MSS : cpTcpData[j + 1];
                        break;
                    }
                }
            }
            
            gptConn->RcvNum[0] = cptTcpHdrBuf->SeqNum[0];
            gptConn->RcvNum[1] = cptTcpHdrBuf->SeqNum[1];
            if (++gptConn->RcvNum[1] == 0){
                ++gptConn->RcvNum[0];
            }
            
            gptConn->TcpStateFlags = cTCP_ESTABLISHED;
            guwFlags = cTCP_CONNECTED;
            msip_APPCALL();
            goto appsend;
            
#endif
            
        case cTCP_ESTABLISHED: // 应用状态标识cTCP_ACKDATA被设置，允许应用层发送TCP数据包
            
            // 如果收到包含FIN标识的包，协议层发送FIN并进入LAST_ACK状态，并向应用层发cTCP_CLOSE标识
            if  (cptTcpHdrBuf->Flags & cTCP_FIN) {
                
                i = 1 + guwEthLen;
                if ((gptConn->RcvNum[1] += i) < i){
                    ++gptConn->RcvNum[0];
                }
                
                guwFlags = cTCP_CLOSE;
                msip_APPCALL();
                
                if (++gptConn->AckNum[1] == 0){
                    ++gptConn->AckNum[0];
                }
                
                gptConn->TcpStateFlags = cTCP_LAST_ACK|cTCP_OUTSTANDING;
                
            tcp_send_finack:	// 发送FINACK包：由TCP事务查询重传跳过来的.....
                cptTcpHdrBuf->Flags = cTCP_FIN|cTCP_ACK;
                goto tcp_send_nodata;
            }
            
            
            if (guwEthLen > 0){	// 收到的TCP包有数据段
                
                if (gptConn->TcpStateFlags & cTCP_STOPPED){
                    // 1）如果有cTCP_STOPPED标识，表明应用层没有buffer处理，我们只能ACK回应。
                    // guwFlags = cTCP_ACKDATA; // 已经存在的，这里不需要重设
                    goto tcp_send_ack;
                } else {
                    // 2）应用层可以处理这个含数据段的TCP包，给应用层发cTCP_NEWDATA标识以替换cTCP_ACKDATA标识
                    guwFlags = cTCP_NEWDATA;
                    if ((gptConn->RcvNum[1] += guwEthLen) < guwEthLen){
                        ++gptConn->RcvNum[0];
                    }
                }
            }
            
            // 协议层通知应用层目前的状态：
            msip_APPCALL();
            
            
        appsend:	// 根据应用层的反馈标识处理回应远端
            
            // 如果应用层需要异常终止当前连接，协议层就RSTACK远端，并清除这个TCP事务！
            if (guwFlags & cTCP_ABORT){
                gptConn->TcpStateFlags = cTCP_CLOSED;
                cptTcpHdrBuf->Flags = cTCP_RST|cTCP_ACK;
                guwEthLen = 0;
                goto tcp_send_nodata;
            }
            
            // 如果应用层需要正常关闭当前连接，协议层就进入等待FIN_WAIT_1状态，并向远端发送FINACK
            if (guwFlags & cTCP_CLOSE){
                
                if (++gptConn->AckNum[1] == 0){
                    ++gptConn->AckNum[0];
                }
                
                gptConn->TcpStateFlags = cTCP_FIN_WAIT_1|cTCP_OUTSTANDING;
                gptConn->NumRetran = 0;
                cptTcpHdrBuf->Flags = cTCP_FIN|cTCP_ACK;
                guwEthLen = 0;
                goto tcp_send_nodata;
            }
            
            // 检查应用层是否有TCP数据包
            if (guwEthLen > 0){ // 应用层有TCP数据包
                
                gptConn->TcpStateFlags |= cTCP_OUTSTANDING;
                gptConn->NumRetran = 0;
                
                if ((gptConn->AckNum[1] += guwEthLen) < guwEthLen){
                    ++gptConn->AckNum[0];
                }
                
                // 重传处理，当然也要处理正常的ACK回应。
            apprexmit:
                // 发送ACK确认，可能包含TCP数据
                guwEthLen += 2*(cIpHdrLen + cTcpHdrLen);
                // 设置PSHACK标识
                cptTcpHdrBuf->Flags = cTCP_ACK | cTCP_PSH;
                // 进入TCP封装
                goto tcp_send_noopts;
            } else if (guwFlags & cTCP_NEWDATA){ // 应用层没有有TCP数据包。检查远端是否等待本地的ACK回应
                goto tcp_send_ack;
            }
            
            goto drop;  // 远端是没有数据的ACK回应，并且应用层也没有数据要传。
            
        case cTCP_LAST_ACK:
            // 如果收到远端ACK确认本地FIN，协议层关闭连接。
            if (guwFlags & cTCP_ACKDATA){
                gptConn->TcpStateFlags = cTCP_CLOSED;
            }
            goto drop;
            
        case cTCP_FIN_WAIT_1:
            // 应用层已经关闭，但远端还没有。本地协议层等待FIN
            if (guwEthLen > 0){
                if ((gptConn->RcvNum[1] += guwEthLen) < guwEthLen){
                    ++gptConn->RcvNum[0];
                }
            }
            
            if (cptTcpHdrBuf->Flags & cTCP_FIN){
                if (guwFlags & cTCP_ACKDATA){
                    gptConn->TcpStateFlags = cTCP_TIME_WAIT;
                    gptConn->Timer = 0;
                }
                else{
                    gptConn->TcpStateFlags = cTCP_CLOSING|cTCP_OUTSTANDING;
                }
                
                if (++gptConn->RcvNum[1] == 0){
                    ++gptConn->RcvNum[0];
                }
                
                goto tcp_send_ack;
            }
            else if (guwFlags & cTCP_ACKDATA){
                gptConn->TcpStateFlags = cTCP_FIN_WAIT_2;
                goto drop;
            }
            
            if (guwEthLen > 0){
                goto tcp_send_ack;
            }
            
            goto drop;
            
        case cTCP_FIN_WAIT_2:
            if (guwEthLen > 0){
                if ((gptConn->RcvNum[1] += guwEthLen) < guwEthLen){
                    ++gptConn->RcvNum[0];
                }
            }
            
            if (cptTcpHdrBuf->Flags & cTCP_FIN){
                gptConn->TcpStateFlags = cTCP_TIME_WAIT;
                gptConn->Timer = 0;
                
                if (+gptConn->RcvNum[1] == 0){
                    ++gptConn->RcvNum[0];
                }
                
                goto tcp_send_ack;
            }
            
            if(guwEthLen > 0){
                goto tcp_send_ack;
            }
            
            goto drop;
            
        case cTCP_TIME_WAIT:
            goto tcp_send_ack;
            
        case cTCP_CLOSING:
            if (guwFlags & cTCP_ACKDATA){
                gptConn->TcpStateFlags = cTCP_TIME_WAIT;
                gptConn->Timer = 0;
            }
    }
    
    goto drop;
    
    // 封装 TCP
tcp_send_ack:
    cptTcpHdrBuf->Flags = cTCP_ACK;
    
tcp_send_nodata:
    guwEthLen = 2*(cIpHdrLen + cTcpHdrLen);
    
tcp_send_noopts:
    cptTcpHdrBuf->HdrLen = cTCP_HDR_NOOPT;
    
tcp_send:	// 构造TCP头
    cptTcpHdrBuf->AckNum[0] = gptConn->RcvNum[0];
    cptTcpHdrBuf->AckNum[1] = gptConn->RcvNum[1];
    
    cptTcpHdrBuf->SeqNum[0] = gptConn->SeqNum[0];
    cptTcpHdrBuf->SeqNum[1] = gptConn->SeqNum[1];
    
    cptTcpHdrBuf->SrcPort = gptConn->LocalPort;
    cptTcpHdrBuf->DestPort = gptConn->RemotePort;
    
    cptIpHdrBuf->SrcIpAddr[0] = guwIpAddr[0];
    cptIpHdrBuf->SrcIpAddr[1] = guwIpAddr[1];
    
    cptIpHdrBuf->DestIpAddr[0] = gptConn->RemoteIpAddr[0];
    cptIpHdrBuf->DestIpAddr[1] = gptConn->RemoteIpAddr[1];
    
    // 如果应用层要求停止数据，协议层冻结窗口
    if (gptConn->TcpStateFlags & cTCP_STOPPED){
        cptTcpHdrBuf->WndSize = 0;
    }
    else{
        // 通知远端本地重新开放窗口。由于本地RAM小，所以是静态窗口
        cptTcpHdrBuf->WndSize = cTCP_WS;
    }
    
tcp_send_noconn:	// 构造IP头
    
    cptIpHdrBuf->Vhl = cIP_VER_HLEN;
    cptIpHdrBuf->Tos = 0;
    cptIpHdrBuf->Len = guwEthLen;
    cptIpHdrBuf->IpId = ++guwIpId;
    cptIpHdrBuf->Flags = cIP_DF;				// Do not Fragment!
    cptIpHdrBuf->Offset = 0;
    cptIpHdrBuf->Ttl = cIP_TTL;
    cptIpHdrBuf->Proto = cIP_PROTO_TCP;
    
    // Calculate IP checksums.
    cptIpHdrBuf->IpChkSum = 0;
    cptIpHdrBuf->IpChkSum = ~checksum(2*cIpHdrLen, cpIpHdrBuf);
    
    // Calculate TCP checksums.
    cptTcpHdrBuf->Reserve = 0;
    cptTcpHdrBuf->TcpChkSum = 0;
    cptTcpHdrBuf->TcpChkSum = ~msip_TcpChkSum();
    
send:		// 发生送IP包
    msip_Arp_Out(pARP);
    
drop:	// 释放缓冲区
    guwEthLen = 0;
    return;
    
}

