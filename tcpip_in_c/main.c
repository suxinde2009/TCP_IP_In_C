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


#include "system.h"
#include "tcpip.h"
#include "drivers.h"

// 定义应用：1 表示开启功能，0 表示关闭功能
#define cTCP_RS232   1    // TCP <-> RS232 的应用，只用于服务模式
#define cTCP_ADAC    1    // TCP <-> Audio, 主要用于服务，也可以用于客户。要求高带宽： > 912Kbit



// 分配本地用户自定义服务模式应用TCP端口号，不能与知名端口相同！如：23, 80
// 注意：对不同的TCP事件使用不同的本地端口号，有助于快速查找TCP事件而不需要判断IP是否相同！
//       这样做能使本地快速响应。
#define cTCP_ListenPort_TEST   0x1000   // 4096

#if cTCP_RS232 == 1
#define cTCP_ListenPort_RS232  0x2000   // 8192
#endif

#if cTCP_ADAC == 0
#define cTCP_ListenPort_ADAC   0x3000   // 12288
#endif

// 客户应用模式的本地TCP端口号。不能与知名端口相同！如：23, 80
// 注意：对不同的TCP事件使用不同的本地端口号（包括：本地侦听端口），有助于快速查找TCP事件而
//       不需要判断IP是否相同！这样做能使本地快速响应。
#if (cTCP_ADAC == 1) && (TCP_ACTIVE_OPEN == 1)
#define cTCP_ActivePort_ADAC  0x3001   // 12289
#endif




// 分配系统应用临时缓冲区（按 wrod 存储）
UINT16 guwAppBuf[cAppSizeMax];

//--------------------------------------------------------------------------------------

main(){
#if  TCP_ACTIVE_OPEN == 1
    UINT16 temp[2];
#endif
    
    
    // 1. Hardware initialize: SPCE061A
    SP_IO_INIT();
    
    // 2. Open and Enable Hardware interrupt 2Hz and Clear WatchDog!
    SP_OpenTime2();
    
    // 3. Hardware initialize: RTL8019AS
    RTL8019AS_RESET();
    RTL8019AS_INIT();
    
    // 4. vIP4 TCP/IP initialize
    msip_Init();
    
    // 5. We listen test port
    msip_Listen(cTCP_ListenPort_TEST);		// 用于侦听来自链路测试的TCP包
    
    
#if cTCP_RS232 == 1
    SP_UART_INIT(C_UART_Baud_115200);		// Hardware initialize: UART of SPCE061A
    
    msip_Listen(cTCP_ListenPort_RS232);		// 用于侦听来自RS232的TCP包
#endif
    
    
#if cTCP_ADAC == 1
    //	SP_ADAC_INIT(cSample_4096);				// Open ADAC
    //	SP_ADAC_INIT(cSample_8192);				// Open ADAC
    //	SP_ADAC_INIT(cSample_16384);			// Open ADAC
    //	SP_ADAC_INIT(cSample_32768);			// Open ADAC
    //	SP_CLOSE_FIQ();		// 关闭FIQ中断，同时也禁止了ADAC
    
    msip_Listen(cTCP_ListenPort_ADAC);		// 用于侦听来自远端的Audio的TCP包
#endif
    
    
#if (cTCP_ADAC == 1) && (TCP_ACTIVE_OPEN == 1)
    // for test audio, wo active link remote: 192.168.0.60
    temp[0] = ((192<<8)|168);
    temp[1] = ((0<<8)|30);
    msip_Connect(cTCP_ActivePort_ADAC, temp, cTCP_ListenPort_ADAC);
#endif
    
    
    
    // 6. We do TCP/IP Check Loop
loop:
    // 接收新的以太包，并处理
    if ((guwEthLen = ether_Receive()) != 0){
        switch (cptEthHdrBuf->EthType){
            case cEthType_Arp:
                msip_Arp_In();
                break;
            case cEthType_Ip:
                msip_Input();
        }
    }
    
    // ARP表老化处理
    if (guwMsg_Route & cM_ARP_TIME){
        msip_Arp_Time();
    }
    
    // TCP事件轮询
    if (guwMsg_Route & cM_TCP_PERIODIC){
        msip_Periodic();
    }
    
    goto loop;
    
}



// SUB-SUB-SUB-SUB-SUB-SUB-SUB-SUB-SUB-SUB-SUB-SUB-SUB-SUB-SUB-SUB-SUB-SUB-SUB-SUB-SUB


//--------------------------------------------------------------------------------------
//
//      |--------------|       |-----|----------|------|       |------|--------|
//      |工业设备|RS232| <---> |RS232|核心嵌入板|TCP/IP| <---> |TCP/IP|普通PC机|
//      |--------------|       |-----|----------|------|       |------|--------|
//
//-------------------------------------------------------------------------------------
void userapp(){
    
    switch (gptConn->LocalPort){
#if cTCP_RS232 == 1
        case cTCP_ListenPort_RS232:
            goto link_rs232;
#endif
            
#if cTCP_ADAC == 1	// ADAC 工作时：由于双向通讯，所以Listen和Active处理是一样的！
        case cTCP_ListenPort_ADAC:
            goto link_adac_listen;
#endif
            
#if (cTCP_ADAC == 1) && (TCP_ACTIVE_OPEN == 1)	// ADAC 工作时：由于双向通讯，所以Listen和Active处理是一样的！
        case cTCP_ActivePort_ADAC:
            goto link_adac_active;
#endif
            
        case cTCP_ListenPort_TEST:
            goto test_net;
            
        default:
            return;
    }
    
    
#if cTCP_RS232 == 1
link_rs232:	 // 与RS232透明传输通讯：本系统的一个应用。
    
    
    // 以下事件的过虑判断并不按照事件发生的顺序，是因为有些事件通常只会发生一次，
    // 从而在大多数其它经常发生的事件状态下，减少对那些事件的过滤判断，以提高速度!!!
    
    if (msip_Poll() || msip_Acked()){	// 如果RS232有数据要发送，就转发TCP数据段！
        if (guwUartRxLen > 0) {	// 根据guwUartRxLen判断是否转发RS232数据
            MEMCPY(guwUartRxLen, guwUartRxBuf, cpTcpData);
            guwEthLen = guwUartRxLen;
            guwUartRxLen = 0;
            gptConn->PollTime = 0;	// 清除空闲时间记数
        } else	if (gptConn->PollTime++ > 3*cTCP_MAX_POLL){	// 太长时间空闲(900秒)，终止连接！
            msip_Close();
        }
        
        return;
    }
    
    if (msip_NewData()){	// 收到TCP数据包，转发给RS232
        if (guwEthLen > 0){
            SP_UART_TX(guwEthLen, cpTcpData);
            guwEthLen = 0;
        }
        if (guwUartRxLen > 0) {	// 根据guwUartRxLen判断是否转发RS232数据
            MEMCPY(guwUartRxLen, guwUartRxBuf, cpTcpData);
            guwEthLen = guwUartRxLen;
            guwUartRxLen = 0;
            gptConn->PollTime = 0;	// 清除空闲时间记数
        }
        
        gptConn->PollTime = 0;	// 清除空闲时间记数
        return;
    }
    
    if (msip_Connected()){
        gptConn->PollTime = 0;	// 清除空闲时间记数
        guwEthLen = 0;			// 释放TCP数据区
        
        return;
    }
    
    
    //	if (msip_Aborted() || msip_Closed()){	// 如果异常关闭，那就关闭当前连接
    // Nothing to do!
    //		return;
    //	}
    
    return;
#endif
    
    
    
#if cTCP_ADAC == 1	// ADAC 工作时：由于双向通讯，所以Listen和Active处理是一样的！
link_adac_listen:
    if (msip_Acked()){   // 如果有A/D数据要发送，就转发TCP数据包
        /*
         if (guwMicRxLen > 0) {	// 根据guwMicRxLen判断是否转发Audio数据
         SP_CLOSE_FIQ();		// 关闭FIQ中断，同时也禁止了ADAC
         MEMCPY(guwMicRxLen, guwMicRxBuf, cpTcpData);
         guwEthLen = guwMicRxLen;
         guwMicRxLen = 0;		// A/D 转换计数复位
         SP_OPEN_FIQ();			// 开启FIQ中断，同时也开启了ADAC
         gptConn->PollTime = 0;	// 清除空闲时间记数
         } */
        guwEthLen = 0;
        return;
    }
    
    
    if (msip_NewData()){
        /*
         if (guwEthLen > 0){	// 收到Audio数据包
         // 如果上次没有转换完，就等....
         while(guwDAC1TxLen < guwDAC1TotalLen);
         // 如果转换完，就复制buffer
         SP_CLOSE_FIQ();		// 关闭FIQ中断，同时也禁止了ADAC
         if (guwEthLen > cDAC1_MAXLEN){  // 拦截超长bytes部分
         guwEthLen = cDAC1_MAXLEN;
         }
         MEMCPY(guwEthLen, cpTcpData, guwDAC1TxBuf); // 将TCP数据Audio复制给DAC1的buffer
         guwDAC1TxLen = 0;   			// DAC1 转换计数复位
         guwDAC1TotalLen = guwEthLen;	// DAC1 转换buffer总长
         SP_OPEN_FIQ();					// 开启FIQ中断，同时也开启了ADAC
         
         guwEthLen = 0;
         }
         if (guwMicRxLen > 0) {	// 根据guwMicRxLen判断是否转发Audio数据
         SP_CLOSE_FIQ();		// 关闭FIQ中断，同时也禁止了ADAC
         MEMCPY(guwMicRxLen, guwMicRxBuf, cpTcpData);
         guwEthLen = guwMicRxLen;
         guwMicRxLen = 0;		// A/D 转换计数复位
         SP_OPEN_FIQ();			// 开启FIQ中断，同时也开启了ADAC
         } */
        
        guwEthLen = 0;
        gptConn->PollTime = 0;	// 清除空闲时间记数
        return;
        
    }
    
    
    if (msip_Connected()){
        gptConn->PollTime = 0;	// 清除空闲时间记数
        guwEthLen = 0;			// 释放TCP数据区
        /*
         guwMicRxLen = 0;		// A/D 转换计数复位
         guwDAC1TotalLen = 0;	// DAC1 转换计数复位
         SP_OPEN_FIQ();			// 开启FIQ中断，同时也开启了ADAC
         */
        
        return;
    }
    
    if (msip_Poll()){
        if (gptConn->PollTime++ > 3*cTCP_MAX_POLL){	// 太长时间空闲(900秒)，终止连接！
            msip_Close();
            //SP_CLOSE_FIQ();		// 关闭FIQ中断，同时也禁止了ADAC
        }
        guwEthLen = 0;
        return;
    }
    
    if (msip_Aborted() || msip_Closed()){	// 如果异常关闭，那就关闭当前连接
        //SP_CLOSE_FIQ();		// 关闭FIQ中断，同时也禁止了ADAC
        return;
    }
    
link_adac_active:
    if (msip_Acked()){   // 如果有A/D数据要发送，就转发TCP数据包
        /*
         if (guwMicRxLen > 0) {	// 根据guwMicRxLen判断是否转发Audio数据
         SP_CLOSE_FIQ();		// 关闭FIQ中断，同时也禁止了ADAC
         MEMCPY(guwMicRxLen, guwMicRxBuf, cpTcpData);
         guwEthLen = guwMicRxLen;
         guwMicRxLen = 0;		// A/D 转换计数复位
         SP_OPEN_FIQ();			// 开启FIQ中断，同时也开启了ADAC
         gptConn->PollTime = 0;	// 清除空闲时间记数
         } */
        guwEthLen = 0;
        return;
    }
    
    
    if (msip_NewData()){
        /*
         if (guwEthLen > 0){	// 收到Audio数据包
         // 如果上次没有转换完，就等....
         while(guwDAC1TxLen < guwDAC1TotalLen);
         // 如果转换完，就复制buffer
         SP_CLOSE_FIQ();		// 关闭FIQ中断，同时也禁止了ADAC
         if (guwEthLen > cDAC1_MAXLEN){  // 拦截超长bytes部分
         guwEthLen = cDAC1_MAXLEN;
         }
         MEMCPY(guwEthLen, cpTcpData, guwDAC1TxBuf); // 将TCP数据Audio复制给DAC1的buffer
         guwDAC1TxLen = 0;   			// DAC1 转换计数复位
         guwDAC1TotalLen = guwEthLen;	// DAC1 转换buffer总长
         SP_OPEN_FIQ();					// 开启FIQ中断，同时也开启了ADAC
         
         guwEthLen = 0;
         }
         if (guwMicRxLen > 0) {	// 根据guwMicRxLen判断是否转发Audio数据
         SP_CLOSE_FIQ();		// 关闭FIQ中断，同时也禁止了ADAC
         MEMCPY(guwMicRxLen, guwMicRxBuf, cpTcpData);
         guwEthLen = guwMicRxLen;
         guwMicRxLen = 0;		// A/D 转换计数复位
         SP_OPEN_FIQ();			// 开启FIQ中断，同时也开启了ADAC
         } */
        
        guwEthLen = 0;
        gptConn->PollTime = 0;	// 清除空闲时间记数
        return;
        
    }
    
    
    if (msip_Connected()){
        gptConn->PollTime = 0;	// 清除空闲时间记数
        guwEthLen = 0;			// 释放TCP数据区
        /*
         guwMicRxLen = 0;		// A/D 转换计数复位
         guwDAC1TotalLen = 0;	// DAC1 转换计数复位
         SP_OPEN_FIQ();			// 开启FIQ中断，同时也开启了ADAC
         */
        
        return;
    }
    
    if (msip_Poll()){
        if (gptConn->PollTime++ > 3*cTCP_MAX_POLL){	// 太长时间空闲(900秒)，终止连接！
            msip_Close();
            //SP_CLOSE_FIQ();		// 关闭FIQ中断，同时也禁止了ADAC
        }
        guwEthLen = 1460;
        return;
    }
    
    if (msip_Aborted() || msip_Closed()){	// 如果异常关闭，那就关闭当前连接
        //SP_CLOSE_FIQ();		// 关闭FIQ中断，同时也禁止了ADAC
        return;
    }
    
    
    return;
#endif
    
    
    
    
    
    // 以下部分用于Ping功能失效时的网络测试！TMD现在网络病毒太多，许多ISP运营商都禁Ping了！
    // 不管是否传数据，都将在300秒后断开.....
test_net:
    
    if (msip_NewData()){
        // Message: 收到！别惹我，烦着呢......
        cpTcpData[0] = 0xcad5;
        cpTcpData[1] = 0xb5bd;
        cpTcpData[2] = 0xa3a1;
        cpTcpData[3] = 0xb1f0;
        cpTcpData[4] = 0xc8c7;
        cpTcpData[5] = 0xced2;
        cpTcpData[6] = 0xb7b3;
        cpTcpData[7] = 0xb7b1;
        cpTcpData[8] = 0xd7c5;
        cpTcpData[9] = 0xc4d8;
        cpTcpData[10] = 0x2e2e;
        cpTcpData[11] = 0x2e2e;
        cpTcpData[12] = 0x2e2e;
        guwEthLen = 26;
        return;
    }
    
    if (msip_Poll()){
        if (gptConn->PollTime == 0){
            // Message: Welcome to you!
            cpTcpData[0] = 0x5765;	// "We"+
            cpTcpData[1] = 0x6c63;	// "lc"+
            cpTcpData[2] = 0x6f6d;	// "om"+
            cpTcpData[3] = 0x6520;	// "e "+
            cpTcpData[4] = 0x746f;	// "to"+
            cpTcpData[5] = 0x2079;	// "yo"+
            cpTcpData[6] = 0x6f75;	// " u"+
            cpTcpData[7] = 0x2120;	// "! "
            guwEthLen = 16;
        }
        
        if (gptConn->PollTime++ > cTCP_MAX_POLL){	// 太长时间空闲，终止连接！
            msip_Close();
        }
        
        return;
    }
    
    
    if (msip_Connected()){
        gptConn->PollTime = 0;	// 清除空闲时间记数
        return;
    }
    
    //	if (msip_Aborted() || msip_Closed()){	// 如果异常关闭，那就关闭当前连接
    // Nothing to do!
    //		return;
    //	}
    
    return;
}
