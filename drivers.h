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



#ifndef	__DRIVERS_H__
#define	__DRIVERS_H__


#include "system.h"




// 定义全局变量和宏 ---------------------------------------------

//时基2Hz中断统计次数统计，引用drivers.asm里的定义
extern volatile UINT16 guwTime2;

// 系统消息状态（按bit定义），引用drivers.asm里的定义（包括宏）
extern volatile UINT16 guwMsg_Route;
#define cM_ARP_TIME			0x0001			// ARP表老化事件
#define cM_TCP_PERIODIC		0x0002			// TCP轮询事件
#define cM_ADC_ENABLE		0x0004			// 允许ADC 转换开始
#define cM_DAC1_ENABLE		0x0008			// 允许DAC1转换开始
#define cM_DAC2_ENABLE		0x0010			// 允许DAC2转换开始

// 分配系统应用临时缓冲区（按 wrod 定义），guwAppBuf 引用main.c里的定义
#define cAppSizeMax		730    // 必须是偶数
extern UINT16 guwAppBuf[cAppSizeMax];

// 保存UART已接收到的Byte长度，引用drivers.asm里的定义
extern volatile UINT16 guwUartRxLen;
// UART接收缓冲区地址，按Word存放，guwAppBuf 引用main.c里的定义
#define guwUartRxBuf	((UINT16 *)&guwAppBuf[0])
// 定义UART允许使用的最大缓存，按Byte计算
#define cUART_RX_MAXLEN    1460    // 必须小于等于guwAppBuf的Byte容量

// 保存 MIC A/D 已接收到的Byte长度，引用drivers.asm里的定义
extern volatile UINT16 guwMicRxLen;
// MIC A/D 接收缓冲区地址，按Word存放，guwAppBuf 引用main.c里的定义
#define guwMicRxBuf  ((UINT16 *)&guwAppBuf[0])
// 定义 MIC A/D 允许使用的最大缓存，按Byte计算
#define cMIC_RX_MAXLEN   730    // 必须小于等于(guwAppBuf/2)的Byte容量

// 保存 DAC1 已转换完成的Byte长度，引用drivers.asm里的定义
extern volatile UINT16 guwDAC1TxLen;
// DAC1 使用的缓冲区地址，按Word存放，guwAppBuf 引用main.c里的定义
#define guwDAC1TxBuf  ((UINT16 *)&guwAppBuf[cMIC_RX_MAXLEN])
// 定义 DAC1 允许使用的最大缓存，按Byte计算
#define cDAC1_MAXLEN   cMIC_RX_MAXLEN    // 必须等于guwMicRxBuf的Byte容量
// 定义当前DAC1需要转换的总Byte长度(当存放值超过cDAC1_MAXLEN，会自动截为cDAC1_MAXLEN的长度)，引用drivers.asm里的定义
extern volatile UINT16 guwDAC1TotalLen;



//--------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
// 定义‘开中断’和‘关中断’
//////////////////////////////////////////////////////////////////
#define SP_OPEN_IRQ()   __asm("irq on")
#define SP_OPEN_FIQ()   __asm("fiq on")
#define SP_CLOSE_IRQ()  __asm("irq off")
#define SP_CLOSE_FIQ()  __asm("fiq off")


//////////////////////////////////////////////////////////////////
// Function: void SP_OpenTime2();
// 开启时基2Hz中断
// 内有清除看门狗功能
//////////////////////////////////////////////////////////////////
extern void SP_OpenTime2(void);

//////////////////////////////////////////////////////////////////
// Function: void ClearWatchDog();
// 清看门狗，必须在程序运行0.75秒内执行
//////////////////////////////////////////////////////////////////
extern void ClearWatchDog(void);

//////////////////////////////////////////////////////////////////
// Function: void SP_CloseTime2();
// 关闭时基2Hz中断
//////////////////////////////////////////////////////////////////
extern void SP_CloseTime2(void);

//////////////////////////////////////////////////////////////////
// Function: void SP_ADAC_INI(UINT16 Sample)
// A/D, D/A 初始化，TImeB 申请 FIQ 中断
// TImeB 计时采用32768频率
// Sample: 采样率的定义，只能采用下面定义的宏。否则，产生不可预测错误！
//////////////////////////////////////////////////////////////////
extern void SP_ADAC_INIT(UINT16 Sample);
//////////////////////////////////////////////////////////////////
// 定义TimeB使用的计数初值，这些定义用于：void SP_ADAC_INI(UINT16 Sample)
// 使用32768Hz做基准
//////////////////////////////////////////////////////////////////
#define cSample_32768	0xffff		// 32768Hz 采样：记 1 次
#define cSample_16384	0xfffe		// 16384Hz 采样：记 2 次
#define cSample_8192	0xfffc		// 8192Hz  采样：记 4 次
#define cSample_4096	0xfff8		// 4096Hz  采样：记 8 次

//////////////////////////////////////////////////////////////////
// 功能函数: void SP_IO_INIT()
// (1) 初始化I/O工作状态
// (2) IOA为输入、高阻、唤醒模式
// (3) IOB[15-11]输出'0'匹配8019as的SA[4-0]
// (4) IOB[6-4]输出'1'匹配8019as的Reset, IORD , IOWR
// (5) IOB[3]下拉输入模式，作为8019as的中断输入查询
// (6) IOB[7]高阻输入唤醒模式，作为Uart_RX
// (7) IOB[10]输出'0'，作为Uart_TX
// (8) IOB[9-8,2-0]未使用，暂定为下拉输入模式（抗干扰）。
// (9) 系统工作频率 CPUCLK = 49.152MHz
// (10) 开放2Hz中断，2Hz中断内置清除看门狗功能！
// (11) 警告：所有程序过程不允许关闭2Hz中断超过看门狗上限时间(0.75秒)
//////////////////////////////////////////////////////////////////
extern void SP_IO_INIT(void);

//////////////////////////////////////////////////////////////////
// Function: void SP_UART_INIT(UINT16 Baud)
// Rx/Tx interrupt mode, and setup Baud.
// DATA: 8bit
// STOP: 1bit
// PARITY Check: no
// IOB7/10  must be first set in SP_IO_INIT() as follows:
// (1) IOB[7]高阻输入唤醒模式，作为Uart_RX
// (2) IOB[10]输出'0'，作为Uart_TX
//////////////////////////////////////////////////////////////////
extern void SP_UART_INIT(UINT16 baud);
//////////////////////////////////////////////////////////////////
// Define for P_UART_BaudScalarLow and P_UART_BaudScalarHigh
// Fosc = 1500*32768 = 49.152MHz
//////////////////////////////////////////////////////////////////
#define C_UART_Baud_9600		0x0500	// ((1500*32768)/(4*9600))
#define C_UART_Baud_14400		0x0355 	// ((1500*32768)/(4*14400))
#define C_UART_Baud_19200		0x0280	// ((1500*32768)/(4*19200))
#define C_UART_Baud_38400		0x0140	// ((1500*32768)/(4*38400))
#define C_UART_Baud_57600		0x00d5	// ((1500*32768)/(4*57600))
#define C_UART_Baud_115200		0x006b	// ((1500*32768)/(4*115200))


//////////////////////////////////////////////////////////////////
// Function: void SP_UART_TX(UINT16 txlen, UINT16 *txbuf)
// txbuf: 指向发送首地址
// txlen: 待发送的Byte长度
// BIG_ENDIAN 模式对齐
//////////////////////////////////////////////////////////////////
extern void SP_UART_TX(UINT16 txlen, UINT16 *txbuf);



//--------------------------------------------------------------------

//////////////////////////////////////////////////////////////////
// Function: void MEMCPY(UINT16 ByteLen, UINT16 *in, UINT16 *out)
// Function: copy memory regions
// Description: This function copies <WordLen> Words from the memory
//              region pointed to by <in> to the memory region pointed
//              to by <out>
// Return: ignore
//////////////////////////////////////////////////////////////////
extern void MEMCPY(UINT16 ByteLen, UINT16 *in, UINT16 *out);

////////////////////////////////////////////////////////////////////////
// UINT16 checksum(UINT16 ByteLen, UINT16 *mbuf)
// TCP/IP 通用校验和过程。由于用汇编，所以只适宜BIG_ENDIAN模式。
// ByteLen: 长度bytes，必须满足条件：ByteLen >= 2 否则计算没有意义
// mbuf: 存放Word缓冲区首指针
////////////////////////////////////////////////////////////////////////
extern UINT16 checksum(UINT16 ByteLen, UINT16 *mbuf);


//--------------------------------------------------------------------



//////////////////////////////////////////////////////////////////
// Function: void RTL8019AS_RESET(void)
// RTL8019AS硬件复位
//////////////////////////////////////////////////////////////////
extern void RTL8019AS_RESET(void);


//////////////////////////////////////////////////////////////////
// RTL8019AS初始化，包含软复位。
// 返回0：表示MCU控制RTL8019AS通讯异常。
// 返回1：表示初始化成功。
//////////////////////////////////////////////////////////////////
extern UINT16 RTL8019AS_INIT(void);

//////////////////////////////////////////////////////////////////
// Function: void RTL8019AS_TX(UINT16 ByteLen, UINT16 *mbuf)
// ByteLen: 传送以太包的字节数
// mbuf: 以太包缓冲区的首指针
//////////////////////////////////////////////////////////////////
extern void RTL8019AS_TX(UINT16 ByteLen, UINT16 *mbuf);

//////////////////////////////////////////////////////////////////
// Function: UINT16 RTL8019AS_RX(UINT16 *mbuf)
// mbuf: 以太包缓冲区的首指针
// 返回接收以太包的字节数。如果是0，则没有包。
//////////////////////////////////////////////////////////////////
extern UINT16 RTL8019AS_RX(UINT16 *mbuf);
//--------------------------------------------------------------------

#endif
