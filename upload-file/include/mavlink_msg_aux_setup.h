// MESSAGE AUX_SETUP PACKING

#define MAVLINK_MSG_ID_AUX_SETUP 210

typedef struct __mavlink_aux_setup_t {
 int32_t lat; /*< Latitude * 1E7*/
 int32_t lon; /*< Longitude * 1E7*/
 int32_t alt; /*< Altitude * 1E3*/
 float yaw; /*< Yaw*/
 uint32_t token; /*< Aux dance step token*/
} mavlink_aux_setup_t;

#define MAVLINK_MSG_ID_AUX_SETUP_LEN 20
#define MAVLINK_MSG_ID_210_LEN 20

#define MAVLINK_MSG_ID_AUX_SETUP_CRC 138
#define MAVLINK_MSG_ID_210_CRC 138



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_AUX_SETUP { \
	210, \
	"AUX_SETUP", \
	5, \
	{  { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_aux_setup_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_aux_setup_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_aux_setup_t, alt) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_aux_setup_t, yaw) }, \
         { "token", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_aux_setup_t, token) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_AUX_SETUP { \
	"AUX_SETUP", \
	5, \
	{  { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_aux_setup_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_aux_setup_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_aux_setup_t, alt) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_aux_setup_t, yaw) }, \
         { "token", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_aux_setup_t, token) }, \
         } \
}
#endif

/**
 * @brief Pack a aux_setup message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lat Latitude * 1E7
 * @param lon Longitude * 1E7
 * @param alt Altitude * 1E3
 * @param yaw Yaw
 * @param token Aux dance step token
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_aux_setup_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int32_t lat, int32_t lon, int32_t alt, float yaw, uint32_t token)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AUX_SETUP_LEN];
	_mav_put_int32_t(buf, 0, lat);
	_mav_put_int32_t(buf, 4, lon);
	_mav_put_int32_t(buf, 8, alt);
	_mav_put_float(buf, 12, yaw);
	_mav_put_uint32_t(buf, 16, token);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUX_SETUP_LEN);
#else
	mavlink_aux_setup_t packet;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.yaw = yaw;
	packet.token = token;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUX_SETUP_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AUX_SETUP;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_AUX_SETUP_LEN, MAVLINK_MSG_ID_AUX_SETUP_CRC);
}

/**
 * @brief Pack a aux_setup message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lat Latitude * 1E7
 * @param lon Longitude * 1E7
 * @param alt Altitude * 1E3
 * @param yaw Yaw
 * @param token Aux dance step token
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_aux_setup_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int32_t lat,int32_t lon,int32_t alt,float yaw,uint32_t token)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AUX_SETUP_LEN];
	_mav_put_int32_t(buf, 0, lat);
	_mav_put_int32_t(buf, 4, lon);
	_mav_put_int32_t(buf, 8, alt);
	_mav_put_float(buf, 12, yaw);
	_mav_put_uint32_t(buf, 16, token);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_AUX_SETUP_LEN);
#else
	mavlink_aux_setup_t packet;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.yaw = yaw;
	packet.token = token;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_AUX_SETUP_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_AUX_SETUP;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_AUX_SETUP_LEN, MAVLINK_MSG_ID_AUX_SETUP_CRC);
}

/**
 * @brief Encode a aux_setup struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param aux_setup C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_aux_setup_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_aux_setup_t* aux_setup)
{
	return mavlink_msg_aux_setup_pack(system_id, component_id, msg, aux_setup->lat, aux_setup->lon, aux_setup->alt, aux_setup->yaw, aux_setup->token);
}

/**
 * @brief Encode a aux_setup struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param aux_setup C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_aux_setup_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_aux_setup_t* aux_setup)
{
	return mavlink_msg_aux_setup_pack_chan(system_id, component_id, chan, msg, aux_setup->lat, aux_setup->lon, aux_setup->alt, aux_setup->yaw, aux_setup->token);
}

/**
 * @brief Send a aux_setup message
 * @param chan MAVLink channel to send the message
 *
 * @param lat Latitude * 1E7
 * @param lon Longitude * 1E7
 * @param alt Altitude * 1E3
 * @param yaw Yaw
 * @param token Aux dance step token
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_aux_setup_send(mavlink_channel_t chan, int32_t lat, int32_t lon, int32_t alt, float yaw, uint32_t token)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_AUX_SETUP_LEN];
	_mav_put_int32_t(buf, 0, lat);
	_mav_put_int32_t(buf, 4, lon);
	_mav_put_int32_t(buf, 8, alt);
	_mav_put_float(buf, 12, yaw);
	_mav_put_uint32_t(buf, 16, token);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUX_SETUP, buf, MAVLINK_MSG_ID_AUX_SETUP_LEN, MAVLINK_MSG_ID_AUX_SETUP_CRC);
#else
	mavlink_aux_setup_t packet;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.yaw = yaw;
	packet.token = token;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUX_SETUP, (const char *)&packet, MAVLINK_MSG_ID_AUX_SETUP_LEN, MAVLINK_MSG_ID_AUX_SETUP_CRC);
#endif
}

/**
 * @brief Send a aux_setup message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_aux_setup_send_struct(mavlink_channel_t chan, const mavlink_aux_setup_t* aux_setup)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_aux_setup_send(chan, aux_setup->lat, aux_setup->lon, aux_setup->alt, aux_setup->yaw, aux_setup->token);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUX_SETUP, (const char *)aux_setup, MAVLINK_MSG_ID_AUX_SETUP_LEN, MAVLINK_MSG_ID_AUX_SETUP_CRC);
#endif
}

#if MAVLINK_MSG_ID_AUX_SETUP_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_aux_setup_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t lat, int32_t lon, int32_t alt, float yaw, uint32_t token)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int32_t(buf, 0, lat);
	_mav_put_int32_t(buf, 4, lon);
	_mav_put_int32_t(buf, 8, alt);
	_mav_put_float(buf, 12, yaw);
	_mav_put_uint32_t(buf, 16, token);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUX_SETUP, buf, MAVLINK_MSG_ID_AUX_SETUP_LEN, MAVLINK_MSG_ID_AUX_SETUP_CRC);
#else
	mavlink_aux_setup_t *packet = (mavlink_aux_setup_t *)msgbuf;
	packet->lat = lat;
	packet->lon = lon;
	packet->alt = alt;
	packet->yaw = yaw;
	packet->token = token;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AUX_SETUP, (const char *)packet, MAVLINK_MSG_ID_AUX_SETUP_LEN, MAVLINK_MSG_ID_AUX_SETUP_CRC);
#endif
}
#endif

#endif

// MESSAGE AUX_SETUP UNPACKING


/**
 * @brief Get field lat from aux_setup message
 *
 * @return Latitude * 1E7
 */
static inline int32_t mavlink_msg_aux_setup_get_lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field lon from aux_setup message
 *
 * @return Longitude * 1E7
 */
static inline int32_t mavlink_msg_aux_setup_get_lon(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field alt from aux_setup message
 *
 * @return Altitude * 1E3
 */
static inline int32_t mavlink_msg_aux_setup_get_alt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field yaw from aux_setup message
 *
 * @return Yaw
 */
static inline float mavlink_msg_aux_setup_get_yaw(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field token from aux_setup message
 *
 * @return Aux dance step token
 */
static inline uint32_t mavlink_msg_aux_setup_get_token(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Decode a aux_setup message into a struct
 *
 * @param msg The message to decode
 * @param aux_setup C-struct to decode the message contents into
 */
static inline void mavlink_msg_aux_setup_decode(const mavlink_message_t* msg, mavlink_aux_setup_t* aux_setup)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	aux_setup->lat = mavlink_msg_aux_setup_get_lat(msg);
	aux_setup->lon = mavlink_msg_aux_setup_get_lon(msg);
	aux_setup->alt = mavlink_msg_aux_setup_get_alt(msg);
	aux_setup->yaw = mavlink_msg_aux_setup_get_yaw(msg);
	aux_setup->token = mavlink_msg_aux_setup_get_token(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_AUX_SETUP_LEN? msg->len : MAVLINK_MSG_ID_AUX_SETUP_LEN;
        memset(aux_setup, 0, MAVLINK_MSG_ID_AUX_SETUP_LEN);
	memcpy(aux_setup, _MAV_PAYLOAD(msg), len);
#endif
}
