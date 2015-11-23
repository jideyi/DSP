/*
 * upp.h
 * uppӲ�������
 *  Created on: 2015-11-12
 *      Author: Administrator
 */
#ifndef __UPP_H__
#define __UPP_H__

#include "utils.h"

//����ͨ����������
#define upp_receive_byte_count              2
#define upp_receive_line_count               1
#define upp_receive_line_offset               upp_receive_byte_count
#define upp_receive_buffer_size              upp_receive_byte_count * upp_receive_line_count

//���ݴ���״̬
#define UPP_TRAN_FINISHED       1
#define UPP_TRAN_UNFINISHED  0

// uPP ͨ��
#define uPP_CHA                    (0x00000000u)
#define uPP_CHB                    (0x00000001u)

#define uPP_DMA_CHI                (0x00000002u)
#define uPP_DMA_CHQ                (0x00000003u)

// uPP �ܽŸ���
// ����μ� TMS320C6748 DSP Technical Reference Manual 1471ҳ �� 31-3
#define uPP_CHA_8BIT               (0x00000000u)
#define uPP_CHA_16BIT              (0x00000001u)
#define uPP_CHA_8BIT_CHB_8BIT      (0x00000002u)
#define uPP_CHA_8BIT_CHB_16BIT     (0x00000003u)
#define uPP_CHA_16BIT_CHB_8BIT     (0x00000004u)
#define uPP_CHA_16BIT_CHB_16BIT    (0x00000005u)

// uPP ���ݸ�ʽ����
// ���ݶ��뷽ʽ
#define uPP_DataPackingFmt_RJZE    (0x00000000u << 5)    // �Ҷ��� ����չ
#define uPP_DataPackingFmt_RJSE    (0x00000001u << 5)    // �Ҷ��� ������չ
#define uPP_DataPackingFmt_LJZE    (0x00000002u << 5)    // ����� ����չ

// ͨ������
#define uPP_DataPacking_FULL       (0x00000000u << 2)    // 8 λ���� 16 λ
#define uPP_DataPacking_9BIT       (0x00000001u << 2)
#define uPP_DataPacking_10BIT      (0x00000002u << 2)
#define uPP_DataPacking_11BIT      (0x00000003u << 2)
#define uPP_DataPacking_12BIT      (0x00000004u << 2)
#define uPP_DataPacking_13BIT      (0x00000005u << 2)
#define uPP_DataPacking_14BIT      (0x00000006u << 2)
#define uPP_DataPacking_15BIT      (0x00000007u << 2)

// �ӿڿ���
#define uPP_InterfaceWidth_8BIT    (0x00000000u << 1)    // 8 λ
#define uPP_InterfaceWidth_16BIT   (0x00000001u << 1)    // 16 λ

// ������
#define uPP_DataRate_SINGLE        (0x00000000u << 0)    // ������
#define uPP_DataRate_DOUBLE        (0x00000001u << 0)    // ˫����

// uPP ͨ������
// ˫�������ʸ���ģʽ
#define uPP_DDRDEMUX_DISABLE       (0x00000000u << 4)
#define uPP_DDRDEMUX_ENABLE        (0x00000001u << 4)

// ���������ʽ���ģʽ
#define uPP_SDRTXIL_DISABLE        (0x00000000u << 3)
#define uPP_SDRTXIL_ENABLE         (0x00000001u << 3)

// ͨ��ʹ������
#define uPP_CHN_ONE                (0x00000000u << 2)
#define uPP_CHN_TWO                (0x00000001u << 2)

// ����ģʽ
#define uPP_ALL_RECEIVE            (0x00000000u << 0)
#define uPP_ALL_TRANSMIT           (0x00000001u << 0)
#define uPP_DUPLEX0                (0x00000002u << 0)         // �ػ� B > A
#define uPP_DUPLEX1                (0x00000003u << 0)         // �ػ� A > B

// uPP �ӿڡ��ܽš���λ����
#define uPP_PIN_PHASE_NORMAL       (0x00000000u)
#define uPP_PIN_PHASE_INVERT       (0x00000001u)
#define uPP_PIN_TRIS               (0x00002000u)
#define uPP_PIN_TRISB             (0x20000000u)    //ͨ��B�Ƿ��ͷ�������ʱ��Ϊ����

#define uPP_PIN_WAIT_DISABLED  (0x00000000u)   //by Administrator
#define uPP_PIN_WAIT               (0x00000020u)
#define uPP_PIN_ENABLE             (0x00000010u)
#define uPP_PIN_START              (0x00000008u)

#define uPP_PIN_POLARITY_WAIT      (0x00000004u)
#define uPP_PIN_POLARITY_ENABLE    (0x00000002u)
#define uPP_PIN_POLARITY_START     (0x00000001u)

#define UPP_PIN_POLARITY_DEFAULT (0x00000000u)

// uPP ��������
#define uPP_Threshold_64Bytes      (0x00000000u)
#define uPP_Threshold_128Bytes     (0x00000001u)
#define uPP_Threshold_256Bytes     (0x00000003u)

// uPP DMA �ж�
#define uPP_INT_EOL                (0x00000010u)         // �д�������ж�
#define uPP_INT_EOW                (0x00000008u)         // ���ڴ�������ж�
#define uPP_INT_ERR                (0x00000004u)         // �ڲ����ߴ����ж�
#define uPP_INT_UOR                (0x00000002u)         // ������Ƿ�� / ��������ж�
#define uPP_INT_DPE                (0x00000001u)         // ��� / ���ô����ж�

// uPP DMA ����
typedef struct
{
	// DMA ���ڵ�ַ���� 3 λ����Ϊ 0 ��ǿ�� 64 λ���룩
	unsigned int *WindowAddress;
	// ȡֵ��Χ 0x001-0xFFFF
	unsigned short LineCount;
    // DMA ���ֽ���Ŀ 16 λ���� 0 λ����Ϊ 0 ��ǿ��Ϊż����ȡֵ��Χ 0x000-0xFFFE
	unsigned short ByteCount;
	// DMA ������ƫ�Ƶ�ַ 16 λ���� 3 λ����Ϊ 0 ��ǿ�� 64 λ���룩 ȡֵ��Χ 0x000-0xFFF8
	unsigned short LineOffsetAddress;
} uPPDMAConfig;

// uPP DMA ״̬
typedef struct
{
	// DMA ��ǰ���ڵ�ַ
	unsigned int WindowAddress;
	// ��ǰ����
	unsigned short LineCount;
	// ��ǰ�ֽ���
	unsigned short ByteCount;
	// FIFO ʹ��״��
	unsigned char FIFO;
	// DMA �ȴ��д��䣨�� DMA ͨ������ʱ���ܹ������µ� DMA ���䣩
	unsigned char PEND;
	// DMA ״̬
	unsigned char DMA;
} uPPDMAStatus;

//uPPͨ��buffer��������
typedef    unsigned short  UPP_DATA_TYPE;

/****************************************************************************/
/*                                                                          */
/*              ��������                                                    */
/*                                                                          */
/****************************************************************************/
void uPPGetVersion(void);

void uPPPinMuxSetup(unsigned char OperatingMode);
void uPPClkConfig(unsigned int baseAddr, unsigned char channel, unsigned int Clk,
		            unsigned int moduleClk, unsigned char polarity);
void uPPEnable(unsigned int baseAdd);
void uPPDisable(unsigned int baseAdd);
void uPPPeripheralConfig(unsigned int baseAddr, unsigned int config);
void uPPDataFmtConfig(unsigned int baseAddr, unsigned char channel, unsigned int config);
void uPPChannelConfig(unsigned int baseAddr, unsigned int config);
void uPPPinConfig(unsigned int baseAddr, unsigned char channel, unsigned int config);
void uPPPinPolarityConfig(unsigned int baseAddr, unsigned char channel, unsigned int config);
void uPPIdleValueConfig(unsigned int baseAddr, unsigned char channel, unsigned int config);
void uPPThresholdConfig(unsigned int baseAddr, unsigned char channel, unsigned int config);
void uPPDLBConfig(unsigned int baseAddr, unsigned int config);

void uPPIntEnable(unsigned int baseAdd, unsigned char DMAchannel, unsigned int intFlags);
void uPPIntDisable(unsigned int baseAdd, unsigned char DMAchannel, unsigned int intFlags);
void uPPIntClear(unsigned int baseAdd, unsigned char DMAchannel, unsigned int intFlags);
unsigned int uPPIntStatus(unsigned int baseAdd, unsigned char DMAchannel);
void uPPEndOfInt(unsigned int baseAddr);

void uPPDMATransfer(unsigned int baseAdd, unsigned char DMAChannel, uPPDMAConfig *config);
uPPDMAStatus *uPPGetDMAStatus(unsigned int baseAdd, unsigned char channel);
void uPPReset(unsigned int baseAddr);

void UPPTranClearStatus();
unsigned int UPPTranGetStatus();
void UPPIsr(UArg arg);
void UPPReceive(uPPDMAConfig *p_upp_tran_channel);
void UPPBufferConfig(uPPDMAConfig *p_upp_tran_channel, UPP_DATA_TYPE *p_upp_buffer);
void UPPInit();

#endif/* UPP_H_ */