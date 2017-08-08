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

#ifndef	__SYSTEM_H__
#define	__SYSTEM_H__


// 声明本系统使用的MCU型号，程序中其他任何地方都没有用到这个定义
//#define MCU		SPCE061A

// 定义 MCU 16bit的字节序模式
#define BIG_ENDIAN	1	// for SPCE061A

// 定义16bit的无符号整数声明
#ifndef __UINT16__
#define __UINT16__
typedef unsigned int UINT16;
#endif

// 定义16bit的符号整数声明
#ifndef __SINT16__
#define __SINT16__
typedef int SINT16;
#endif


#endif
