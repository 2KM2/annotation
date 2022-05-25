#pragma once
// MESSAGE WIFI_SETS PACKING

#define MAVLINK_MSG_ID_WIFI_SETS 214


typedef struct __mavlink_wifi_sets_t {
 uint8_t type; /*<  type*/
 uint8_t ack; /*<  ack*/
 uint8_t ssid[20]; /*<  ssid*/
 uint8_t psk[20]; /*<  psk*/
} mavlink_wifi_sets_t;

#define MAVLINK_MSG_ID_WIFI_SETS_LEN 42
#define MAVLINK_MSG_ID_WIFI_SETS_MIN_LEN 42
#define MAVLINK_MSG_ID_214_LEN 42
#define MAVLINK_MSG_ID_214_MIN_LEN 42

#define MAVLINK_MSG_ID_WIFI_SETS_CRC 173
#define MAVLINK_MSG_ID_214_CRC 173

#define MAVLINK_MSG_WIFI_SETS_FIELD_SSID_LEN 20
#define MAVLINK_MSG_WIFI_SETS_FIELD_PSK_LEN 20

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WIFI_SETS { \
    214, \
    "WIFI_SETS", \
    4, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wifi_sets_t, type) }, \
         { "ack", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wifi_sets_t, ack) }, \
         { "ssid", NULL, MAVLINK_TYPE_UINT8_T, 20, 2, offsetof(mavlink_wifi_sets_t, ssid) }, \
         { "psk", NULL, MAVLINK_TYPE_UINT8_T, 20, 22, offsetof(mavlink_wifi_sets_t, psk) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WIFI_SETS { \
    "WIFI_SETS", \
    4, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wifi_sets_t, type) }, \
         { "ack", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wifi_sets_t, ack) }, \
         { "ssid", NULL, MAVLINK_TYPE_UINT8_T, 20, 2, offsetof(mavlink_wifi_sets_t, ssid) }, \
         { "psk", NULL, MAVLINK_TYPE_UINT8_T, 20, 22, offsetof(mavlink_wifi_sets_t, psk) }, \
         } \
}
#endif

/**
 * @brief Pack a wifi_sets message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type  type
 * @param ack  ack
 * @param ssid  ssid
 * @param psk  psk
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_sets_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t type, uint8_t ack, const uint8_t *ssid, const uint8_t *psk)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_SETS_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, ack);
    _mav_put_uint8_t_array(buf, 2, ssid, 20);
    _mav_put_uint8_t_array(buf, 22, psk, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_SETS_LEN);
#else
    mavlink_wifi_sets_t packet;
    packet.type = type;
    packet.ack = ack;
    mav_array_memcpy(packet.ssid, ssid, sizeof(uint8_t)*20);
    mav_array_memcpy(packet.psk, psk, sizeof(uint8_t)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_SETS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_SETS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WIFI_SETS_MIN_LEN, MAVLINK_MSG_ID_WIFI_SETS_LEN, MAVLINK_MSG_ID_WIFI_SETS_CRC);
}

/**
 * @brief Pack a wifi_sets message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type  type
 * @param ack  ack
 * @param ssid  ssid
 * @param psk  psk
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_sets_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t type,uint8_t ack,const uint8_t *ssid,const uint8_t *psk)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_SETS_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, ack);
    _mav_put_uint8_t_array(buf, 2, ssid, 20);
    _mav_put_uint8_t_array(buf, 22, psk, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_SETS_LEN);
#else
    mavlink_wifi_sets_t packet;
    packet.type = type;
    packet.ack = ack;
    mav_array_memcpy(packet.ssid, ssid, sizeof(uint8_t)*20);
    mav_array_memcpy(packet.psk, psk, sizeof(uint8_t)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_SETS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_SETS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WIFI_SETS_MIN_LEN, MAVLINK_MSG_ID_WIFI_SETS_LEN, MAVLINK_MSG_ID_WIFI_SETS_CRC);
}

/**
 * @brief Encode a wifi_sets struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wifi_sets C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_sets_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wifi_sets_t* wifi_sets)
{
    return mavlink_msg_wifi_sets_pack(system_id, component_id, msg, wifi_sets->type, wifi_sets->ack, wifi_sets->ssid, wifi_sets->psk);
}

/**
 * @brief Encode a wifi_sets struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wifi_sets C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_sets_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wifi_sets_t* wifi_sets)
{
    return mavlink_msg_wifi_sets_pack_chan(system_id, component_id, chan, msg, wifi_sets->type, wifi_sets->ack, wifi_sets->ssid, wifi_sets->psk);
}

/**
 * @brief Send a wifi_sets message
 * @param chan MAVLink channel to send the message
 *
 * @param type  type
 * @param ack  ack
 * @param ssid  ssid
 * @param psk  psk
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wifi_sets_send(mavlink_channel_t chan, uint8_t type, uint8_t ack, const uint8_t *ssid, const uint8_t *psk)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_SETS_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, ack);
    _mav_put_uint8_t_array(buf, 2, ssid, 20);
    _mav_put_uint8_t_array(buf, 22, psk, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_SETS, buf, MAVLINK_MSG_ID_WIFI_SETS_MIN_LEN, MAVLINK_MSG_ID_WIFI_SETS_LEN, MAVLINK_MSG_ID_WIFI_SETS_CRC);
#else
    mavlink_wifi_sets_t packet;
    packet.type = type;
    packet.ack = ack;
    mav_array_memcpy(packet.ssid, ssid, sizeof(uint8_t)*20);
    mav_array_memcpy(packet.psk, psk, sizeof(uint8_t)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_SETS, (const char *)&packet, MAVLINK_MSG_ID_WIFI_SETS_MIN_LEN, MAVLINK_MSG_ID_WIFI_SETS_LEN, MAVLINK_MSG_ID_WIFI_SETS_CRC);
#endif
}

/**
 * @brief Send a wifi_sets message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wifi_sets_send_struct(mavlink_channel_t chan, const mavlink_wifi_sets_t* wifi_sets)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wifi_sets_send(chan, wifi_sets->type, wifi_sets->ack, wifi_sets->ssid, wifi_sets->psk);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_SETS, (const char *)wifi_sets, MAVLINK_MSG_ID_WIFI_SETS_MIN_LEN, MAVLINK_MSG_ID_WIFI_SETS_LEN, MAVLINK_MSG_ID_WIFI_SETS_CRC);
#endif
}

#if MAVLINK_MSG_ID_WIFI_SETS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wifi_sets_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t type, uint8_t ack, const uint8_t *ssid, const uint8_t *psk)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, ack);
    _mav_put_uint8_t_array(buf, 2, ssid, 20);
    _mav_put_uint8_t_array(buf, 22, psk, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_SETS, buf, MAVLINK_MSG_ID_WIFI_SETS_MIN_LEN, MAVLINK_MSG_ID_WIFI_SETS_LEN, MAVLINK_MSG_ID_WIFI_SETS_CRC);
#else
    mavlink_wifi_sets_t *packet = (mavlink_wifi_sets_t *)msgbuf;
    packet->type = type;
    packet->ack = ack;
    mav_array_memcpy(packet->ssid, ssid, sizeof(uint8_t)*20);
    mav_array_memcpy(packet->psk, psk, sizeof(uint8_t)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_SETS, (const char *)packet, MAVLINK_MSG_ID_WIFI_SETS_MIN_LEN, MAVLINK_MSG_ID_WIFI_SETS_LEN, MAVLINK_MSG_ID_WIFI_SETS_CRC);
#endif
}
#endif

#endif

// MESSAGE WIFI_SETS UNPACKING


/**
 * @brief Get field type from wifi_sets message
 *
 * @return  type
 */
static inline uint8_t mavlink_msg_wifi_sets_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field ack from wifi_sets message
 *
 * @return  ack
 */
static inline uint8_t mavlink_msg_wifi_sets_get_ack(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field ssid from wifi_sets message
 *
 * @return  ssid
 */
static inline uint16_t mavlink_msg_wifi_sets_get_ssid(const mavlink_message_t* msg, uint8_t *ssid)
{
    return _MAV_RETURN_uint8_t_array(msg, ssid, 20,  2);
}

/**
 * @brief Get field psk from wifi_sets message
 *
 * @return  psk
 */
static inline uint16_t mavlink_msg_wifi_sets_get_psk(const mavlink_message_t* msg, uint8_t *psk)
{
    return _MAV_RETURN_uint8_t_array(msg, psk, 20,  22);
}

/**
 * @brief Decode a wifi_sets message into a struct
 *
 * @param msg The message to decode
 * @param wifi_sets C-struct to decode the message contents into
 */
static inline void mavlink_msg_wifi_sets_decode(const mavlink_message_t* msg, mavlink_wifi_sets_t* wifi_sets)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wifi_sets->type = mavlink_msg_wifi_sets_get_type(msg);
    wifi_sets->ack = mavlink_msg_wifi_sets_get_ack(msg);
    mavlink_msg_wifi_sets_get_ssid(msg, wifi_sets->ssid);
    mavlink_msg_wifi_sets_get_psk(msg, wifi_sets->psk);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WIFI_SETS_LEN? msg->len : MAVLINK_MSG_ID_WIFI_SETS_LEN;
        memset(wifi_sets, 0, MAVLINK_MSG_ID_WIFI_SETS_LEN);
    memcpy(wifi_sets, _MAV_PAYLOAD(msg), len);
#endif
}
