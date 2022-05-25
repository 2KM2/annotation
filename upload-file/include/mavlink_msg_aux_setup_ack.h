#pragma once
// MESSAGE AUX_SETUP_ACK PACKING

#define MAVLINK_MSG_ID_AUX_SETUP_ACK 211


typedef struct __mavlink_aux_setup_ack_t {
 uint32_t token; /*< Aux dance step token*/
 uint16_t id; /*< Drone ID*/
 uint8_t result; /*< Result: 1, */
}mavlink_aux_setup_ack_t;

#define MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN 7
#define MAVLINK_MSG_ID_AUX_SETUP_ACK_MIN_LEN 7
#define MAVLINK_MSG_ID_211_LEN 7
#define MAVLINK_MSG_ID_211_MIN_LEN 7

//#define MAVLINK_MSG_ID_AUX_SETUP_ACK_CRC 117
//#define MAVLINK_MSG_ID_211_CRC 117
#define MAVLINK_MSG_ID_AUX_SETUP_ACK_CRC 0
#define MAVLINK_MSG_ID_211_CRC 0



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUX_SETUP_ACK { \
    211, \
    "AUX_SETUP_ACK", \
    3, \
    {  { "token", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_aux_setup_ack_t, token) }, \
         { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_aux_setup_ack_t, id) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_aux_setup_ack_t, result) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUX_SETUP_ACK { \
    "AUX_SETUP_ACK", \
    3, \
    {  { "token", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_aux_setup_ack_t, token) }, \
         { "id", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_aux_setup_ack_t, id) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_aux_setup_ack_t, result) }, \
         } \
}
#endif

/**
 * @brief Pack a aux_setup_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param token Aux dance step token
 * @param id Drone ID
 * @param result Result: 1, 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_aux_setup_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t token, uint16_t id, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN];
    _mav_put_uint32_t(buf, 0, token);
    _mav_put_uint16_t(buf, 4, id);
    _mav_put_uint8_t(buf, 6, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN);
#else
    mavlink_aux_setup_ack_t packet;
    packet.token = token;
    packet.id = id;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUX_SETUP_ACK;
    return mavlink_finalize_message(msg, system_id, component_id,  MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN, MAVLINK_MSG_ID_AUX_SETUP_ACK_CRC);
}

/**
 * @brief Pack a aux_setup_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param token Aux dance step token
 * @param id Drone ID
 * @param result Result: 1, 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_aux_setup_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t token,uint16_t id,uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN];
    _mav_put_uint32_t(buf, 0, token);
    _mav_put_uint16_t(buf, 4, id);
    _mav_put_uint8_t(buf, 6, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN);
#else
    mavlink_aux_setup_ack_t packet;
    packet.token = token;
    packet.id = id;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_AUX_SETUP_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan,  MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN, MAVLINK_MSG_ID_AUX_SETUP_ACK_CRC);
}

/**
 * @brief Encode a aux_setup_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param aux_setup_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_aux_setup_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_aux_setup_ack_t* aux_setup_ack)
{
    return mavlink_msg_aux_setup_ack_pack(system_id, component_id, msg, aux_setup_ack->token, aux_setup_ack->id, aux_setup_ack->result);
}

/**
 * @brief Encode a aux_setup_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param aux_setup_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_aux_setup_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_aux_setup_ack_t* aux_setup_ack)
{
    return mavlink_msg_aux_setup_ack_pack_chan(system_id, component_id, chan, msg, aux_setup_ack->token, aux_setup_ack->id, aux_setup_ack->result);
}

/**
 * @brief Send a aux_setup_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param token Aux dance step token
 * @param id Drone ID
 * @param result Result: 1, 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_aux_setup_ack_send(mavlink_channel_t chan, uint32_t token, uint16_t id, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN];
    _mav_put_uint32_t(buf, 0, token);
    _mav_put_uint16_t(buf, 4, id);
    _mav_put_uint8_t(buf, 6, result);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUX_SETUP_ACK, buf,  MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN, MAVLINK_MSG_ID_AUX_SETUP_ACK_CRC);
#else
    mavlink_aux_setup_ack_t packet;
    packet.token = token;
    packet.id = id;
    packet.result = result;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUX_SETUP_ACK, (const char *)&packet,  MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN, MAVLINK_MSG_ID_AUX_SETUP_ACK_CRC);
#endif
}

/**
 * @brief Send a aux_setup_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_aux_setup_ack_send_struct(mavlink_channel_t chan, const mavlink_aux_setup_ack_t* aux_setup_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_aux_setup_ack_send_allid(chan, aux_setup_ack->token, aux_setup_ack->id, aux_setup_ack->result);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUX_SETUP_ACK, (const char *)aux_setup_ack,  MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN, MAVLINK_MSG_ID_AUX_SETUP_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_aux_setup_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t token, uint16_t id, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, token);
    _mav_put_uint16_t(buf, 4, id);
    _mav_put_uint8_t(buf, 6, result);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUX_SETUP_ACK, buf,  MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN, MAVLINK_MSG_ID_AUX_SETUP_ACK_CRC);
#else
    mavlink_aux_setup_ack_t *packet = (mavlink_aux_setup_ack_t *)msgbuf;
    packet->token = token;
    packet->id = id;
    packet->result = result;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUX_SETUP_ACK, (const char *)packet,  MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN, MAVLINK_MSG_ID_AUX_SETUP_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE AUX_SETUP_ACK UNPACKING


/**
 * @brief Get field token from aux_setup_ack message
 *
 * @return Aux dance step token
 */
static inline uint32_t mavlink_msg_aux_setup_ack_get_token(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field id from aux_setup_ack message
 *
 * @return Drone ID
 */
static inline uint16_t mavlink_msg_aux_setup_ack_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field result from aux_setup_ack message
 *
 * @return Result: 1, 
 */
static inline uint8_t mavlink_msg_aux_setup_ack_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Decode a aux_setup_ack message into a struct
 *
 * @param msg The message to decode
 * @param aux_setup_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_aux_setup_ack_decode(const mavlink_message_t* msg, mavlink_aux_setup_ack_t* aux_setup_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    aux_setup_ack->token = mavlink_msg_aux_setup_ack_get_token(msg);
    aux_setup_ack->id = mavlink_msg_aux_setup_ack_get_id(msg);
    aux_setup_ack->result = mavlink_msg_aux_setup_ack_get_result(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN? msg->len : MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN;
        memset(aux_setup_ack, 0, MAVLINK_MSG_ID_AUX_SETUP_ACK_LEN);
    memcpy(aux_setup_ack, _MAV_PAYLOAD(msg), len);
#endif
}
