#include "mavlink_helpers.h"

#define MAVLINK_MSG_ID_QR 100 //the same as optical_flow
#define MAVLINK_MSG_ID_QR_MAX_NUM 1

#define MAVLINK_MSG_ID_QR_QRINFO_SIZE 10

MAVPACKED(
typedef struct __qr_info_t
{
	uint16_t data;    /*数据*/
	float dtx;     /*中心点x反切 弧度*/ 
	float dty;     /*中心点y反切 弧度*/  
}) qr_info_t;

MAVPACKED(
typedef struct __mavlink_qr_t {
	uint64_t time_usec;
	float roll;               /*翻滚角*/       
	float pitch;              /*俯仰角*/
	float yaw;                /*偏航角*/
	float ground_distance;    /*超声波*/
	float azimuth;            /*二维码方向*/
	float height;		  /*二维码高度*/
	uint8_t qr_num;           /*二维码数量*/
	qr_info_t qr_info[MAVLINK_MSG_ID_QR_MAX_NUM];
}) mavlink_qr_t;

#define MAVLINK_MSG_ID_QR_LEN  (33+MAVLINK_MSG_ID_QR_MAX_NUM*MAVLINK_MSG_ID_QR_QRINFO_SIZE)
#define MAVLINK_MSG_ID_QR_MIN_LEN (33+MAVLINK_MSG_ID_QR_MAX_NUM*MAVLINK_MSG_ID_QR_QRINFO_SIZE)
#define MAVLINK_MSG_ID_100_LEN (33+MAVLINK_MSG_ID_QR_MAX_NUM*MAVLINK_MSG_ID_QR_QRINFO_SIZE)
#define MAVLINK_MSG_ID_100_MIN_LEN (33+MAVLINK_MSG_ID_QR_MAX_NUM*MAVLINK_MSG_ID_QR_QRINFO_SIZE)

#define MAVLINK_MSG_ID_QR_CRC 175
#define MAVLINK_MSG_ID_100_CRC 175

/**
 * @brief Send a qr message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (UNIX)
 * @param sensor_id Sensor ID
 * @param flow_x Flow in pixels * 10 in x-sensor direction (dezi-pixels)
 * @param flow_y Flow in pixels * 10 in y-sensor direction (dezi-pixels)
 * @param flow_comp_m_x Flow in meters in x-sensor direction, angular-speed compensated
 * @param flow_comp_m_y Flow in meters in y-sensor direction, angular-speed compensated
 * @param quality Optical flow quality / confidence. 0: bad, 255: maximum quality
 * @param ground_distance Ground distance in meters. Positive value: distance known. Negative value: Unknown distance
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_qr_send(mavlink_channel_t chan, uint64_t time_usec, float roll, float pitch, float yaw, float ground_distance, float azimuth, float height,float qr_num, qr_info_t *qr_info)
{
	int i = 0;
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_QR_LEN];
	_mav_put_uint64_t(buf, 0, time_usec);
	_mav_put_float(buf, 8, roll);
	_mav_put_float(buf, 12, pitch);
	_mav_put_float(buf, 16, yaw);
	_mav_put_float(buf, 20, ground_distance);
	_mav_put_float(buf, 24, azimuth);
	_mav_put_float(buf, 28, height);
	_mav_put_uint8_t(buf, 32, qr_num);

	_mav_put_uint16_t(buf, 33, qr_info[i].data);
	_mav_put_float(buf, 35, qr_info[i].dtx);
	_mav_put_float(buf, 39, qr_info[i].dty);

	offset = 39;
	for(i = 1; i < MAVLINK_MSG_ID_QR_MAX_NUM; i++)
	{
		_mav_put_uint16_t(buf, offset+=4, qr_info[i].data);
		_mav_put_float(buf, offset+=2, qr_info[i].dtx);
		_mav_put_float(buf, offset+=4, qr_info[i].dty);
	}

 	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QR, buf, MAVLINK_MSG_ID_QR_MIN_LEN, MAVLINK_MSG_ID_QR_LEN, MAVLINK_MSG_ID_QR_CRC);
#else
	mavlink_qr_t packet;
	packet.time_usec = time_usec;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.ground_distance = ground_distance;
	packet.azimuth = azimuth;
	packet.height = height;
	packet.qr_num = qr_num;

	for(i = 0; i < MAVLINK_MSG_ID_QR_MAX_NUM; i++)
	{
		packet.qr_info[i].data = qr_info[i].data;
		packet.qr_info[i].dtx = qr_info[i].dtx;
		packet.qr_info[i].dty = qr_info[i].dty;
	}

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QR, (const char *)&packet, MAVLINK_MSG_ID_QR_MIN_LEN, MAVLINK_MSG_ID_QR_LEN, MAVLINK_MSG_ID_QR_CRC);
#endif
}

/**
 * @brief Send a qr message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_qr_send_struct(mavlink_channel_t chan, const mavlink_qr_t* qr)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	mavlink_msg_qr_send(chan, qr->time_usec, qr->pitch, qr->yaw, qr->azimuth ,qr->height, qr->qr_num, qr->qr_info);
#else
	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QR, (const char *)qr, MAVLINK_MSG_ID_QR_MIN_LEN, MAVLINK_MSG_ID_QR_LEN, MAVLINK_MSG_ID_QR_CRC);
#endif
}

#endif
