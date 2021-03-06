/*
 * Copyright (c) 2016-2018 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _TX_MSDU_EXTENSION_H_
#define _TX_MSDU_EXTENSION_H_
#if !defined(__ASSEMBLER__)
#endif


// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	tso_enable[0], reserved_0a[6:1], tcp_flag[15:7], tcp_flag_mask[24:16], reserved_0b[31:25]
//	1	l2_length[15:0], ip_length[31:16]
//	2	tcp_seq_number[31:0]
//	3	ip_identification[15:0], udp_length[31:16]
//	4	checksum_offset[13:0], partial_checksum_en[14], reserved_4a[15], payload_start_offset[29:16], reserved_4b[31:30]
//	5	payload_end_offset[13:0], reserved_5a[15:14], wds[16], reserved_5b[31:17]
//	6	buf0_ptr_31_0[31:0]
//	7	buf0_ptr_39_32[7:0], reserved_7a[15:8], buf0_len[31:16]
//	8	buf1_ptr_31_0[31:0]
//	9	buf1_ptr_39_32[7:0], reserved_9a[15:8], buf1_len[31:16]
//	10	buf2_ptr_31_0[31:0]
//	11	buf2_ptr_39_32[7:0], reserved_11a[15:8], buf2_len[31:16]
//	12	buf3_ptr_31_0[31:0]
//	13	buf3_ptr_39_32[7:0], reserved_13a[15:8], buf3_len[31:16]
//	14	buf4_ptr_31_0[31:0]
//	15	buf4_ptr_39_32[7:0], reserved_15a[15:8], buf4_len[31:16]
//	16	buf5_ptr_31_0[31:0]
//	17	buf5_ptr_39_32[7:0], reserved_17a[15:8], buf5_len[31:16]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_TX_MSDU_EXTENSION 18

struct tx_msdu_extension {
             uint32_t tso_enable                      :  1, //[0]
                      reserved_0a                     :  6, //[6:1]
                      tcp_flag                        :  9, //[15:7]
                      tcp_flag_mask                   :  9, //[24:16]
                      reserved_0b                     :  7; //[31:25]
             uint32_t l2_length                       : 16, //[15:0]
                      ip_length                       : 16; //[31:16]
             uint32_t tcp_seq_number                  : 32; //[31:0]
             uint32_t ip_identification               : 16, //[15:0]
                      udp_length                      : 16; //[31:16]
             uint32_t checksum_offset                 : 14, //[13:0]
                      partial_checksum_en             :  1, //[14]
                      reserved_4a                     :  1, //[15]
                      payload_start_offset            : 14, //[29:16]
                      reserved_4b                     :  2; //[31:30]
             uint32_t payload_end_offset              : 14, //[13:0]
                      reserved_5a                     :  2, //[15:14]
                      wds                             :  1, //[16]
                      reserved_5b                     : 15; //[31:17]
             uint32_t buf0_ptr_31_0                   : 32; //[31:0]
             uint32_t buf0_ptr_39_32                  :  8, //[7:0]
                      reserved_7a                     :  8, //[15:8]
                      buf0_len                        : 16; //[31:16]
             uint32_t buf1_ptr_31_0                   : 32; //[31:0]
             uint32_t buf1_ptr_39_32                  :  8, //[7:0]
                      reserved_9a                     :  8, //[15:8]
                      buf1_len                        : 16; //[31:16]
             uint32_t buf2_ptr_31_0                   : 32; //[31:0]
             uint32_t buf2_ptr_39_32                  :  8, //[7:0]
                      reserved_11a                    :  8, //[15:8]
                      buf2_len                        : 16; //[31:16]
             uint32_t buf3_ptr_31_0                   : 32; //[31:0]
             uint32_t buf3_ptr_39_32                  :  8, //[7:0]
                      reserved_13a                    :  8, //[15:8]
                      buf3_len                        : 16; //[31:16]
             uint32_t buf4_ptr_31_0                   : 32; //[31:0]
             uint32_t buf4_ptr_39_32                  :  8, //[7:0]
                      reserved_15a                    :  8, //[15:8]
                      buf4_len                        : 16; //[31:16]
             uint32_t buf5_ptr_31_0                   : 32; //[31:0]
             uint32_t buf5_ptr_39_32                  :  8, //[7:0]
                      reserved_17a                    :  8, //[15:8]
                      buf5_len                        : 16; //[31:16]
};

/*

tso_enable
			
			Enable transmit segmentation offload <legal all>

reserved_0a
			
			FW will set to 0, MAC will ignore.?? <legal 0>

tcp_flag
			
			TCP flags
			
			{NS,CWR,ECE,URG,ACK,PSH, RST ,SYN,FIN}<legal all>

tcp_flag_mask
			
			TCP flag mask. Tcp_flag is inserted into the header
			based on the mask, if tso is enabled

reserved_0b
			
			FW will set to 0, MAC will ignore.?? <legal 0>

l2_length
			
			L2 length for the msdu, if tso is enabled <legal all>

ip_length
			
			Ip length for the msdu, if tso is enabled <legal all>

tcp_seq_number
			
			Tcp_seq_number for the msdu, if tso is enabled <legal
			all>

ip_identification
			
			Ip_identification for the msdu, if tso is enabled <legal
			all>

udp_length
			
			TXDMA is copies this field into MSDU START TLV

checksum_offset
			
			The calculated checksum from start offset to end offset
			will be added to the checksum at the offset given by this
			field<legal all>

partial_checksum_en
			
			Partial Checksum Enable Bit.
			
			<legal 0-1>

reserved_4a
			
			<Legal 0>

payload_start_offset
			
			L4 checksum calculations will start fromt this offset
			
			<Legal all>

reserved_4b
			
			<Legal 0>

payload_end_offset
			
			L4 checksum calculations will end at this offset. 
			
			<Legal all>

reserved_5a
			
			<Legal 0>

wds
			
			If set the current packet is 4-address frame.  Required
			because an aggregate can include some frames with 3 address
			format and other frames with 4 address format.  Used by the
			OLE during encapsulation.  
			
			Note: there is also global wds tx control in the
			TX_PEER_ENTRY
			
			<legal all>

reserved_5b
			
			<Legal 0>

buf0_ptr_31_0
			
			Lower 32 bits of the first buffer pointer 
			
			
			
			NOTE: SW/FW manages the 'cookie' info related to this
			buffer together with the 'cookie' info for this
			MSDU_EXTENSION descriptor
			
			<legal all>

buf0_ptr_39_32
			
			Upper 8 bits of the first buffer pointer <legal all>

reserved_7a
			
			<Legal 0>

buf0_len
			
			Length of the first buffer <legal all>

buf1_ptr_31_0
			
			Lower 32 bits of the second buffer pointer 
			
			
			
			NOTE: SW/FW manages the 'cookie' info related to this
			buffer together with the 'cookie' info for this
			MSDU_EXTENSION descriptor
			
			<legal all>

buf1_ptr_39_32
			
			Upper 8 bits of the second buffer pointer <legal all>

reserved_9a
			
			<Legal 0>

buf1_len
			
			Length of the second buffer <legal all>

buf2_ptr_31_0
			
			Lower 32 bits of the third buffer pointer 
			
			NOTE: SW/FW manages the 'cookie' info related to this
			buffer together with the 'cookie' info for this
			MSDU_EXTENSION descriptor
			
			<legal all>

buf2_ptr_39_32
			
			Upper 8 bits of the third buffer pointer <legal all>

reserved_11a
			
			<Legal 0>

buf2_len
			
			Length of the third buffer <legal all>

buf3_ptr_31_0
			
			Lower 32 bits of the fourth buffer pointer
			
			
			
			NOTE: SW/FW manages the 'cookie' info related to this
			buffer together with the 'cookie' info for this
			MSDU_EXTENSION descriptor
			
			 <legal all>

buf3_ptr_39_32
			
			Upper 8 bits of the fourth buffer pointer <legal all>

reserved_13a
			
			<Legal 0>

buf3_len
			
			Length of the fourth buffer <legal all>

buf4_ptr_31_0
			
			Lower 32 bits of the fifth buffer pointer 
			
			
			
			NOTE: SW/FW manages the 'cookie' info related to this
			buffer together with the 'cookie' info for this
			MSDU_EXTENSION descriptor
			
			<legal all>

buf4_ptr_39_32
			
			Upper 8 bits of the fifth buffer pointer <legal all>

reserved_15a
			
			<Legal 0>

buf4_len
			
			Length of the fifth buffer <legal all>

buf5_ptr_31_0
			
			Lower 32 bits of the sixth buffer pointer
			
			
			
			NOTE: SW/FW manages the 'cookie' info related to this
			buffer together with the 'cookie' info for this
			MSDU_EXTENSION descriptor
			
			 <legal all>

buf5_ptr_39_32
			
			Upper 8 bits of the sixth buffer pointer <legal all>

reserved_17a
			
			<Legal 0>

buf5_len
			
			Length of the sixth buffer <legal all>
*/


/* Description		TX_MSDU_EXTENSION_0_TSO_ENABLE
			
			Enable transmit segmentation offload <legal all>
*/
#define TX_MSDU_EXTENSION_0_TSO_ENABLE_OFFSET                        0x00000000
#define TX_MSDU_EXTENSION_0_TSO_ENABLE_LSB                           0
#define TX_MSDU_EXTENSION_0_TSO_ENABLE_MASK                          0x00000001

/* Description		TX_MSDU_EXTENSION_0_RESERVED_0A
			
			FW will set to 0, MAC will ignore.?? <legal 0>
*/
#define TX_MSDU_EXTENSION_0_RESERVED_0A_OFFSET                       0x00000000
#define TX_MSDU_EXTENSION_0_RESERVED_0A_LSB                          1
#define TX_MSDU_EXTENSION_0_RESERVED_0A_MASK                         0x0000007e

/* Description		TX_MSDU_EXTENSION_0_TCP_FLAG
			
			TCP flags
			
			{NS,CWR,ECE,URG,ACK,PSH, RST ,SYN,FIN}<legal all>
*/
#define TX_MSDU_EXTENSION_0_TCP_FLAG_OFFSET                          0x00000000
#define TX_MSDU_EXTENSION_0_TCP_FLAG_LSB                             7
#define TX_MSDU_EXTENSION_0_TCP_FLAG_MASK                            0x0000ff80

/* Description		TX_MSDU_EXTENSION_0_TCP_FLAG_MASK
			
			TCP flag mask. Tcp_flag is inserted into the header
			based on the mask, if tso is enabled
*/
#define TX_MSDU_EXTENSION_0_TCP_FLAG_MASK_OFFSET                     0x00000000
#define TX_MSDU_EXTENSION_0_TCP_FLAG_MASK_LSB                        16
#define TX_MSDU_EXTENSION_0_TCP_FLAG_MASK_MASK                       0x01ff0000

/* Description		TX_MSDU_EXTENSION_0_RESERVED_0B
			
			FW will set to 0, MAC will ignore.?? <legal 0>
*/
#define TX_MSDU_EXTENSION_0_RESERVED_0B_OFFSET                       0x00000000
#define TX_MSDU_EXTENSION_0_RESERVED_0B_LSB                          25
#define TX_MSDU_EXTENSION_0_RESERVED_0B_MASK                         0xfe000000

/* Description		TX_MSDU_EXTENSION_1_L2_LENGTH
			
			L2 length for the msdu, if tso is enabled <legal all>
*/
#define TX_MSDU_EXTENSION_1_L2_LENGTH_OFFSET                         0x00000004
#define TX_MSDU_EXTENSION_1_L2_LENGTH_LSB                            0
#define TX_MSDU_EXTENSION_1_L2_LENGTH_MASK                           0x0000ffff

/* Description		TX_MSDU_EXTENSION_1_IP_LENGTH
			
			Ip length for the msdu, if tso is enabled <legal all>
*/
#define TX_MSDU_EXTENSION_1_IP_LENGTH_OFFSET                         0x00000004
#define TX_MSDU_EXTENSION_1_IP_LENGTH_LSB                            16
#define TX_MSDU_EXTENSION_1_IP_LENGTH_MASK                           0xffff0000

/* Description		TX_MSDU_EXTENSION_2_TCP_SEQ_NUMBER
			
			Tcp_seq_number for the msdu, if tso is enabled <legal
			all>
*/
#define TX_MSDU_EXTENSION_2_TCP_SEQ_NUMBER_OFFSET                    0x00000008
#define TX_MSDU_EXTENSION_2_TCP_SEQ_NUMBER_LSB                       0
#define TX_MSDU_EXTENSION_2_TCP_SEQ_NUMBER_MASK                      0xffffffff

/* Description		TX_MSDU_EXTENSION_3_IP_IDENTIFICATION
			
			Ip_identification for the msdu, if tso is enabled <legal
			all>
*/
#define TX_MSDU_EXTENSION_3_IP_IDENTIFICATION_OFFSET                 0x0000000c
#define TX_MSDU_EXTENSION_3_IP_IDENTIFICATION_LSB                    0
#define TX_MSDU_EXTENSION_3_IP_IDENTIFICATION_MASK                   0x0000ffff

/* Description		TX_MSDU_EXTENSION_3_UDP_LENGTH
			
			TXDMA is copies this field into MSDU START TLV
*/
#define TX_MSDU_EXTENSION_3_UDP_LENGTH_OFFSET                        0x0000000c
#define TX_MSDU_EXTENSION_3_UDP_LENGTH_LSB                           16
#define TX_MSDU_EXTENSION_3_UDP_LENGTH_MASK                          0xffff0000

/* Description		TX_MSDU_EXTENSION_4_CHECKSUM_OFFSET
			
			The calculated checksum from start offset to end offset
			will be added to the checksum at the offset given by this
			field<legal all>
*/
#define TX_MSDU_EXTENSION_4_CHECKSUM_OFFSET_OFFSET                   0x00000010
#define TX_MSDU_EXTENSION_4_CHECKSUM_OFFSET_LSB                      0
#define TX_MSDU_EXTENSION_4_CHECKSUM_OFFSET_MASK                     0x00003fff

/* Description		TX_MSDU_EXTENSION_4_PARTIAL_CHECKSUM_EN
			
			Partial Checksum Enable Bit.
			
			<legal 0-1>
*/
#define TX_MSDU_EXTENSION_4_PARTIAL_CHECKSUM_EN_OFFSET               0x00000010
#define TX_MSDU_EXTENSION_4_PARTIAL_CHECKSUM_EN_LSB                  14
#define TX_MSDU_EXTENSION_4_PARTIAL_CHECKSUM_EN_MASK                 0x00004000

/* Description		TX_MSDU_EXTENSION_4_RESERVED_4A
			
			<Legal 0>
*/
#define TX_MSDU_EXTENSION_4_RESERVED_4A_OFFSET                       0x00000010
#define TX_MSDU_EXTENSION_4_RESERVED_4A_LSB                          15
#define TX_MSDU_EXTENSION_4_RESERVED_4A_MASK                         0x00008000

/* Description		TX_MSDU_EXTENSION_4_PAYLOAD_START_OFFSET
			
			L4 checksum calculations will start fromt this offset
			
			<Legal all>
*/
#define TX_MSDU_EXTENSION_4_PAYLOAD_START_OFFSET_OFFSET              0x00000010
#define TX_MSDU_EXTENSION_4_PAYLOAD_START_OFFSET_LSB                 16
#define TX_MSDU_EXTENSION_4_PAYLOAD_START_OFFSET_MASK                0x3fff0000

/* Description		TX_MSDU_EXTENSION_4_RESERVED_4B
			
			<Legal 0>
*/
#define TX_MSDU_EXTENSION_4_RESERVED_4B_OFFSET                       0x00000010
#define TX_MSDU_EXTENSION_4_RESERVED_4B_LSB                          30
#define TX_MSDU_EXTENSION_4_RESERVED_4B_MASK                         0xc0000000

/* Description		TX_MSDU_EXTENSION_5_PAYLOAD_END_OFFSET
			
			L4 checksum calculations will end at this offset. 
			
			<Legal all>
*/
#define TX_MSDU_EXTENSION_5_PAYLOAD_END_OFFSET_OFFSET                0x00000014
#define TX_MSDU_EXTENSION_5_PAYLOAD_END_OFFSET_LSB                   0
#define TX_MSDU_EXTENSION_5_PAYLOAD_END_OFFSET_MASK                  0x00003fff

/* Description		TX_MSDU_EXTENSION_5_RESERVED_5A
			
			<Legal 0>
*/
#define TX_MSDU_EXTENSION_5_RESERVED_5A_OFFSET                       0x00000014
#define TX_MSDU_EXTENSION_5_RESERVED_5A_LSB                          14
#define TX_MSDU_EXTENSION_5_RESERVED_5A_MASK                         0x0000c000

/* Description		TX_MSDU_EXTENSION_5_WDS
			
			If set the current packet is 4-address frame.  Required
			because an aggregate can include some frames with 3 address
			format and other frames with 4 address format.  Used by the
			OLE during encapsulation.  
			
			Note: there is also global wds tx control in the
			TX_PEER_ENTRY
			
			<legal all>
*/
#define TX_MSDU_EXTENSION_5_WDS_OFFSET                               0x00000014
#define TX_MSDU_EXTENSION_5_WDS_LSB                                  16
#define TX_MSDU_EXTENSION_5_WDS_MASK                                 0x00010000

/* Description		TX_MSDU_EXTENSION_5_RESERVED_5B
			
			<Legal 0>
*/
#define TX_MSDU_EXTENSION_5_RESERVED_5B_OFFSET                       0x00000014
#define TX_MSDU_EXTENSION_5_RESERVED_5B_LSB                          17
#define TX_MSDU_EXTENSION_5_RESERVED_5B_MASK                         0xfffe0000

/* Description		TX_MSDU_EXTENSION_6_BUF0_PTR_31_0
			
			Lower 32 bits of the first buffer pointer 
			
			
			
			NOTE: SW/FW manages the 'cookie' info related to this
			buffer together with the 'cookie' info for this
			MSDU_EXTENSION descriptor
			
			<legal all>
*/
#define TX_MSDU_EXTENSION_6_BUF0_PTR_31_0_OFFSET                     0x00000018
#define TX_MSDU_EXTENSION_6_BUF0_PTR_31_0_LSB                        0
#define TX_MSDU_EXTENSION_6_BUF0_PTR_31_0_MASK                       0xffffffff

/* Description		TX_MSDU_EXTENSION_7_BUF0_PTR_39_32
			
			Upper 8 bits of the first buffer pointer <legal all>
*/
#define TX_MSDU_EXTENSION_7_BUF0_PTR_39_32_OFFSET                    0x0000001c
#define TX_MSDU_EXTENSION_7_BUF0_PTR_39_32_LSB                       0
#define TX_MSDU_EXTENSION_7_BUF0_PTR_39_32_MASK                      0x000000ff

/* Description		TX_MSDU_EXTENSION_7_RESERVED_7A
			
			<Legal 0>
*/
#define TX_MSDU_EXTENSION_7_RESERVED_7A_OFFSET                       0x0000001c
#define TX_MSDU_EXTENSION_7_RESERVED_7A_LSB                          8
#define TX_MSDU_EXTENSION_7_RESERVED_7A_MASK                         0x0000ff00

/* Description		TX_MSDU_EXTENSION_7_BUF0_LEN
			
			Length of the first buffer <legal all>
*/
#define TX_MSDU_EXTENSION_7_BUF0_LEN_OFFSET                          0x0000001c
#define TX_MSDU_EXTENSION_7_BUF0_LEN_LSB                             16
#define TX_MSDU_EXTENSION_7_BUF0_LEN_MASK                            0xffff0000

/* Description		TX_MSDU_EXTENSION_8_BUF1_PTR_31_0
			
			Lower 32 bits of the second buffer pointer 
			
			
			
			NOTE: SW/FW manages the 'cookie' info related to this
			buffer together with the 'cookie' info for this
			MSDU_EXTENSION descriptor
			
			<legal all>
*/
#define TX_MSDU_EXTENSION_8_BUF1_PTR_31_0_OFFSET                     0x00000020
#define TX_MSDU_EXTENSION_8_BUF1_PTR_31_0_LSB                        0
#define TX_MSDU_EXTENSION_8_BUF1_PTR_31_0_MASK                       0xffffffff

/* Description		TX_MSDU_EXTENSION_9_BUF1_PTR_39_32
			
			Upper 8 bits of the second buffer pointer <legal all>
*/
#define TX_MSDU_EXTENSION_9_BUF1_PTR_39_32_OFFSET                    0x00000024
#define TX_MSDU_EXTENSION_9_BUF1_PTR_39_32_LSB                       0
#define TX_MSDU_EXTENSION_9_BUF1_PTR_39_32_MASK                      0x000000ff

/* Description		TX_MSDU_EXTENSION_9_RESERVED_9A
			
			<Legal 0>
*/
#define TX_MSDU_EXTENSION_9_RESERVED_9A_OFFSET                       0x00000024
#define TX_MSDU_EXTENSION_9_RESERVED_9A_LSB                          8
#define TX_MSDU_EXTENSION_9_RESERVED_9A_MASK                         0x0000ff00

/* Description		TX_MSDU_EXTENSION_9_BUF1_LEN
			
			Length of the second buffer <legal all>
*/
#define TX_MSDU_EXTENSION_9_BUF1_LEN_OFFSET                          0x00000024
#define TX_MSDU_EXTENSION_9_BUF1_LEN_LSB                             16
#define TX_MSDU_EXTENSION_9_BUF1_LEN_MASK                            0xffff0000

/* Description		TX_MSDU_EXTENSION_10_BUF2_PTR_31_0
			
			Lower 32 bits of the third buffer pointer 
			
			NOTE: SW/FW manages the 'cookie' info related to this
			buffer together with the 'cookie' info for this
			MSDU_EXTENSION descriptor
			
			<legal all>
*/
#define TX_MSDU_EXTENSION_10_BUF2_PTR_31_0_OFFSET                    0x00000028
#define TX_MSDU_EXTENSION_10_BUF2_PTR_31_0_LSB                       0
#define TX_MSDU_EXTENSION_10_BUF2_PTR_31_0_MASK                      0xffffffff

/* Description		TX_MSDU_EXTENSION_11_BUF2_PTR_39_32
			
			Upper 8 bits of the third buffer pointer <legal all>
*/
#define TX_MSDU_EXTENSION_11_BUF2_PTR_39_32_OFFSET                   0x0000002c
#define TX_MSDU_EXTENSION_11_BUF2_PTR_39_32_LSB                      0
#define TX_MSDU_EXTENSION_11_BUF2_PTR_39_32_MASK                     0x000000ff

/* Description		TX_MSDU_EXTENSION_11_RESERVED_11A
			
			<Legal 0>
*/
#define TX_MSDU_EXTENSION_11_RESERVED_11A_OFFSET                     0x0000002c
#define TX_MSDU_EXTENSION_11_RESERVED_11A_LSB                        8
#define TX_MSDU_EXTENSION_11_RESERVED_11A_MASK                       0x0000ff00

/* Description		TX_MSDU_EXTENSION_11_BUF2_LEN
			
			Length of the third buffer <legal all>
*/
#define TX_MSDU_EXTENSION_11_BUF2_LEN_OFFSET                         0x0000002c
#define TX_MSDU_EXTENSION_11_BUF2_LEN_LSB                            16
#define TX_MSDU_EXTENSION_11_BUF2_LEN_MASK                           0xffff0000

/* Description		TX_MSDU_EXTENSION_12_BUF3_PTR_31_0
			
			Lower 32 bits of the fourth buffer pointer
			
			
			
			NOTE: SW/FW manages the 'cookie' info related to this
			buffer together with the 'cookie' info for this
			MSDU_EXTENSION descriptor
			
			 <legal all>
*/
#define TX_MSDU_EXTENSION_12_BUF3_PTR_31_0_OFFSET                    0x00000030
#define TX_MSDU_EXTENSION_12_BUF3_PTR_31_0_LSB                       0
#define TX_MSDU_EXTENSION_12_BUF3_PTR_31_0_MASK                      0xffffffff

/* Description		TX_MSDU_EXTENSION_13_BUF3_PTR_39_32
			
			Upper 8 bits of the fourth buffer pointer <legal all>
*/
#define TX_MSDU_EXTENSION_13_BUF3_PTR_39_32_OFFSET                   0x00000034
#define TX_MSDU_EXTENSION_13_BUF3_PTR_39_32_LSB                      0
#define TX_MSDU_EXTENSION_13_BUF3_PTR_39_32_MASK                     0x000000ff

/* Description		TX_MSDU_EXTENSION_13_RESERVED_13A
			
			<Legal 0>
*/
#define TX_MSDU_EXTENSION_13_RESERVED_13A_OFFSET                     0x00000034
#define TX_MSDU_EXTENSION_13_RESERVED_13A_LSB                        8
#define TX_MSDU_EXTENSION_13_RESERVED_13A_MASK                       0x0000ff00

/* Description		TX_MSDU_EXTENSION_13_BUF3_LEN
			
			Length of the fourth buffer <legal all>
*/
#define TX_MSDU_EXTENSION_13_BUF3_LEN_OFFSET                         0x00000034
#define TX_MSDU_EXTENSION_13_BUF3_LEN_LSB                            16
#define TX_MSDU_EXTENSION_13_BUF3_LEN_MASK                           0xffff0000

/* Description		TX_MSDU_EXTENSION_14_BUF4_PTR_31_0
			
			Lower 32 bits of the fifth buffer pointer 
			
			
			
			NOTE: SW/FW manages the 'cookie' info related to this
			buffer together with the 'cookie' info for this
			MSDU_EXTENSION descriptor
			
			<legal all>
*/
#define TX_MSDU_EXTENSION_14_BUF4_PTR_31_0_OFFSET                    0x00000038
#define TX_MSDU_EXTENSION_14_BUF4_PTR_31_0_LSB                       0
#define TX_MSDU_EXTENSION_14_BUF4_PTR_31_0_MASK                      0xffffffff

/* Description		TX_MSDU_EXTENSION_15_BUF4_PTR_39_32
			
			Upper 8 bits of the fifth buffer pointer <legal all>
*/
#define TX_MSDU_EXTENSION_15_BUF4_PTR_39_32_OFFSET                   0x0000003c
#define TX_MSDU_EXTENSION_15_BUF4_PTR_39_32_LSB                      0
#define TX_MSDU_EXTENSION_15_BUF4_PTR_39_32_MASK                     0x000000ff

/* Description		TX_MSDU_EXTENSION_15_RESERVED_15A
			
			<Legal 0>
*/
#define TX_MSDU_EXTENSION_15_RESERVED_15A_OFFSET                     0x0000003c
#define TX_MSDU_EXTENSION_15_RESERVED_15A_LSB                        8
#define TX_MSDU_EXTENSION_15_RESERVED_15A_MASK                       0x0000ff00

/* Description		TX_MSDU_EXTENSION_15_BUF4_LEN
			
			Length of the fifth buffer <legal all>
*/
#define TX_MSDU_EXTENSION_15_BUF4_LEN_OFFSET                         0x0000003c
#define TX_MSDU_EXTENSION_15_BUF4_LEN_LSB                            16
#define TX_MSDU_EXTENSION_15_BUF4_LEN_MASK                           0xffff0000

/* Description		TX_MSDU_EXTENSION_16_BUF5_PTR_31_0
			
			Lower 32 bits of the sixth buffer pointer
			
			
			
			NOTE: SW/FW manages the 'cookie' info related to this
			buffer together with the 'cookie' info for this
			MSDU_EXTENSION descriptor
			
			 <legal all>
*/
#define TX_MSDU_EXTENSION_16_BUF5_PTR_31_0_OFFSET                    0x00000040
#define TX_MSDU_EXTENSION_16_BUF5_PTR_31_0_LSB                       0
#define TX_MSDU_EXTENSION_16_BUF5_PTR_31_0_MASK                      0xffffffff

/* Description		TX_MSDU_EXTENSION_17_BUF5_PTR_39_32
			
			Upper 8 bits of the sixth buffer pointer <legal all>
*/
#define TX_MSDU_EXTENSION_17_BUF5_PTR_39_32_OFFSET                   0x00000044
#define TX_MSDU_EXTENSION_17_BUF5_PTR_39_32_LSB                      0
#define TX_MSDU_EXTENSION_17_BUF5_PTR_39_32_MASK                     0x000000ff

/* Description		TX_MSDU_EXTENSION_17_RESERVED_17A
			
			<Legal 0>
*/
#define TX_MSDU_EXTENSION_17_RESERVED_17A_OFFSET                     0x00000044
#define TX_MSDU_EXTENSION_17_RESERVED_17A_LSB                        8
#define TX_MSDU_EXTENSION_17_RESERVED_17A_MASK                       0x0000ff00

/* Description		TX_MSDU_EXTENSION_17_BUF5_LEN
			
			Length of the sixth buffer <legal all>
*/
#define TX_MSDU_EXTENSION_17_BUF5_LEN_OFFSET                         0x00000044
#define TX_MSDU_EXTENSION_17_BUF5_LEN_LSB                            16
#define TX_MSDU_EXTENSION_17_BUF5_LEN_MASK                           0xffff0000


#endif // _TX_MSDU_EXTENSION_H_
