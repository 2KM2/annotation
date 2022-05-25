// MESSAGE SAFETY_SET_NO_FLY_ZONE PACKING

#define MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE 56

typedef struct __mavlink_safety_set_no_fly_zone_t
{
 uint64_t begin_at; /*< effective UTC time*/
 uint64_t end_at; /*< expiration UTC time*/
 uint64_t updated_at; /*< update UTC time*/
 int32_t area_id; /*< the id of the no-fly zone*/
 int32_t lat; /*< the center latitude of the no-fly zone*/
 int32_t lon; /*< the center longtitude of the no-fly zone*/
 float randius; /*< the randius of the no-fly zone*/
 int32_t polygon_lat[16]; /*< the latitude array of the polygon no-fly zone*/
 int32_t polygon_lon[16]; /*< the longtitude array of the polygon no-fly zone*/
 uint8_t target_system; /*< system id*/
 uint8_t target_component; /*< component id*/
 uint8_t frame; /*< cordinate frame defined by MAV_FRAME enum*/
 char country[2]; /*< country code*/
 int8_t level; /*< the level of the no-fly zone(-1:unknown;0:warning;2:no fly;5:ok to fly)*/
 int8_t shape; /*< the shape of the no-fly zone.(-1:unknown;0:circle;1:rectangle;12:polygon)*/
 int8_t type; /*< type of this no-fly zone.(-1:unknown;0:airport;1:specific area;2:military zone;3.goverment;4:ok to fly zone;5:ferry terminals;6:train station;7.gymnasium;8.prison.)*/
} mavlink_safety_set_no_fly_zone_t;

#define MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN 176
#define MAVLINK_MSG_ID_56_LEN 176

#define MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_CRC 250
#define MAVLINK_MSG_ID_56_CRC 250

#define MAVLINK_MSG_SAFETY_SET_NO_FLY_ZONE_FIELD_POLYGON_LAT_LEN 16
#define MAVLINK_MSG_SAFETY_SET_NO_FLY_ZONE_FIELD_POLYGON_LON_LEN 16
#define MAVLINK_MSG_SAFETY_SET_NO_FLY_ZONE_FIELD_COUNTRY_LEN 2

#define MAVLINK_MESSAGE_INFO_SAFETY_SET_NO_FLY_ZONE { \
	"SAFETY_SET_NO_FLY_ZONE", \
	16, \
	{  { "begin_at", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_safety_set_no_fly_zone_t, begin_at) }, \
         { "end_at", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_safety_set_no_fly_zone_t, end_at) }, \
         { "updated_at", NULL, MAVLINK_TYPE_UINT64_T, 0, 16, offsetof(mavlink_safety_set_no_fly_zone_t, updated_at) }, \
         { "area_id", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_safety_set_no_fly_zone_t, area_id) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_safety_set_no_fly_zone_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 32, offsetof(mavlink_safety_set_no_fly_zone_t, lon) }, \
         { "randius", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_safety_set_no_fly_zone_t, randius) }, \
         { "polygon_lat", NULL, MAVLINK_TYPE_INT32_T, 16, 40, offsetof(mavlink_safety_set_no_fly_zone_t, polygon_lat) }, \
         { "polygon_lon", NULL, MAVLINK_TYPE_INT32_T, 16, 104, offsetof(mavlink_safety_set_no_fly_zone_t, polygon_lon) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 168, offsetof(mavlink_safety_set_no_fly_zone_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 169, offsetof(mavlink_safety_set_no_fly_zone_t, target_component) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 170, offsetof(mavlink_safety_set_no_fly_zone_t, frame) }, \
         { "country", NULL, MAVLINK_TYPE_CHAR, 2, 171, offsetof(mavlink_safety_set_no_fly_zone_t, country) }, \
         { "level", NULL, MAVLINK_TYPE_INT8_T, 0, 173, offsetof(mavlink_safety_set_no_fly_zone_t, level) }, \
         { "shape", NULL, MAVLINK_TYPE_INT8_T, 0, 174, offsetof(mavlink_safety_set_no_fly_zone_t, shape) }, \
         { "type", NULL, MAVLINK_TYPE_INT8_T, 0, 175, offsetof(mavlink_safety_set_no_fly_zone_t, type) }, \
         } \
}


/**
 * @brief Pack a safety_set_no_fly_zone message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system system id
 * @param target_component component id
 * @param frame cordinate frame defined by MAV_FRAME enum
 * @param area_id the id of the no-fly zone
 * @param country country code
 * @param begin_at effective UTC time
 * @param end_at expiration UTC time
 * @param updated_at update UTC time
 * @param level the level of the no-fly zone(-1:unknown;0:warning;2:no fly;5:ok to fly)
 * @param shape the shape of the no-fly zone.(-1:unknown;0:circle;1:rectangle;12:polygon)
 * @param type type of this no-fly zone.(-1:unknown;0:airport;1:specific area;2:military zone;3.goverment;4:ok to fly zone;5:ferry terminals;6:train station;7.gymnasium;8.prison.)
 * @param lat the center latitude of the no-fly zone
 * @param lon the center longtitude of the no-fly zone
 * @param randius the randius of the no-fly zone
 * @param polygon_lat the latitude array of the polygon no-fly zone
 * @param polygon_lon the longtitude array of the polygon no-fly zone
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_safety_set_no_fly_zone_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t target_component, uint8_t frame, int32_t area_id, const char *country, uint64_t begin_at, uint64_t end_at, uint64_t updated_at, int8_t level, int8_t shape, int8_t type, int32_t lat, int32_t lon, float randius, const int32_t *polygon_lat, const int32_t *polygon_lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN];
	_mav_put_uint64_t(buf, 0, begin_at);
	_mav_put_uint64_t(buf, 8, end_at);
	_mav_put_uint64_t(buf, 16, updated_at);
	_mav_put_int32_t(buf, 24, area_id);
	_mav_put_int32_t(buf, 28, lat);
	_mav_put_int32_t(buf, 32, lon);
	_mav_put_float(buf, 36, randius);
	_mav_put_uint8_t(buf, 168, target_system);
	_mav_put_uint8_t(buf, 169, target_component);
	_mav_put_uint8_t(buf, 170, frame);
	_mav_put_int8_t(buf, 173, level);
	_mav_put_int8_t(buf, 174, shape);
	_mav_put_int8_t(buf, 175, type);
	_mav_put_int32_t_array(buf, 40, polygon_lat, 16);
	_mav_put_int32_t_array(buf, 104, polygon_lon, 16);
	_mav_put_char_array(buf, 171, country, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN);
#else
	mavlink_safety_set_no_fly_zone_t packet;
	packet.begin_at = begin_at;
	packet.end_at = end_at;
	packet.updated_at = updated_at;
	packet.area_id = area_id;
	packet.lat = lat;
	packet.lon = lon;
	packet.randius = randius;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.frame = frame;
	packet.level = level;
	packet.shape = shape;
	packet.type = type;
	mav_array_memcpy(packet.polygon_lat, polygon_lat, sizeof(int32_t)*16);
	mav_array_memcpy(packet.polygon_lon, polygon_lon, sizeof(int32_t)*16);
	mav_array_memcpy(packet.country, country, sizeof(char)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN);
#endif
}

/**
 * @brief Pack a safety_set_no_fly_zone message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system system id
 * @param target_component component id
 * @param frame cordinate frame defined by MAV_FRAME enum
 * @param area_id the id of the no-fly zone
 * @param country country code
 * @param begin_at effective UTC time
 * @param end_at expiration UTC time
 * @param updated_at update UTC time
 * @param level the level of the no-fly zone(-1:unknown;0:warning;2:no fly;5:ok to fly)
 * @param shape the shape of the no-fly zone.(-1:unknown;0:circle;1:rectangle;12:polygon)
 * @param type type of this no-fly zone.(-1:unknown;0:airport;1:specific area;2:military zone;3.goverment;4:ok to fly zone;5:ferry terminals;6:train station;7.gymnasium;8.prison.)
 * @param lat the center latitude of the no-fly zone
 * @param lon the center longtitude of the no-fly zone
 * @param randius the randius of the no-fly zone
 * @param polygon_lat the latitude array of the polygon no-fly zone
 * @param polygon_lon the longtitude array of the polygon no-fly zone
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_safety_set_no_fly_zone_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t target_component,uint8_t frame,int32_t area_id,const char *country,uint64_t begin_at,uint64_t end_at,uint64_t updated_at,int8_t level,int8_t shape,int8_t type,int32_t lat,int32_t lon,float randius,const int32_t *polygon_lat,const int32_t *polygon_lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN];
	_mav_put_uint64_t(buf, 0, begin_at);
	_mav_put_uint64_t(buf, 8, end_at);
	_mav_put_uint64_t(buf, 16, updated_at);
	_mav_put_int32_t(buf, 24, area_id);
	_mav_put_int32_t(buf, 28, lat);
	_mav_put_int32_t(buf, 32, lon);
	_mav_put_float(buf, 36, randius);
	_mav_put_uint8_t(buf, 168, target_system);
	_mav_put_uint8_t(buf, 169, target_component);
	_mav_put_uint8_t(buf, 170, frame);
	_mav_put_int8_t(buf, 173, level);
	_mav_put_int8_t(buf, 174, shape);
	_mav_put_int8_t(buf, 175, type);
	_mav_put_int32_t_array(buf, 40, polygon_lat, 16);
	_mav_put_int32_t_array(buf, 104, polygon_lon, 16);
	_mav_put_char_array(buf, 171, country, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN);
#else
	mavlink_safety_set_no_fly_zone_t packet;
	packet.begin_at = begin_at;
	packet.end_at = end_at;
	packet.updated_at = updated_at;
	packet.area_id = area_id;
	packet.lat = lat;
	packet.lon = lon;
	packet.randius = randius;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.frame = frame;
	packet.level = level;
	packet.shape = shape;
	packet.type = type;
	mav_array_memcpy(packet.polygon_lat, polygon_lat, sizeof(int32_t)*16);
	mav_array_memcpy(packet.polygon_lon, polygon_lon, sizeof(int32_t)*16);
	mav_array_memcpy(packet.country, country, sizeof(char)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN);
#endif
}

/**
 * @brief Encode a safety_set_no_fly_zone struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param safety_set_no_fly_zone C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_safety_set_no_fly_zone_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_safety_set_no_fly_zone_t* safety_set_no_fly_zone)
{
	return mavlink_msg_safety_set_no_fly_zone_pack(system_id, component_id, msg, safety_set_no_fly_zone->target_system, safety_set_no_fly_zone->target_component, safety_set_no_fly_zone->frame, safety_set_no_fly_zone->area_id, safety_set_no_fly_zone->country, safety_set_no_fly_zone->begin_at, safety_set_no_fly_zone->end_at, safety_set_no_fly_zone->updated_at, safety_set_no_fly_zone->level, safety_set_no_fly_zone->shape, safety_set_no_fly_zone->type, safety_set_no_fly_zone->lat, safety_set_no_fly_zone->lon, safety_set_no_fly_zone->randius, safety_set_no_fly_zone->polygon_lat, safety_set_no_fly_zone->polygon_lon);
}

/**
 * @brief Encode a safety_set_no_fly_zone struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param safety_set_no_fly_zone C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_safety_set_no_fly_zone_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_safety_set_no_fly_zone_t* safety_set_no_fly_zone)
{
	return mavlink_msg_safety_set_no_fly_zone_pack_chan(system_id, component_id, chan, msg, safety_set_no_fly_zone->target_system, safety_set_no_fly_zone->target_component, safety_set_no_fly_zone->frame, safety_set_no_fly_zone->area_id, safety_set_no_fly_zone->country, safety_set_no_fly_zone->begin_at, safety_set_no_fly_zone->end_at, safety_set_no_fly_zone->updated_at, safety_set_no_fly_zone->level, safety_set_no_fly_zone->shape, safety_set_no_fly_zone->type, safety_set_no_fly_zone->lat, safety_set_no_fly_zone->lon, safety_set_no_fly_zone->randius, safety_set_no_fly_zone->polygon_lat, safety_set_no_fly_zone->polygon_lon);
}

/**
 * @brief Send a safety_set_no_fly_zone message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system system id
 * @param target_component component id
 * @param frame cordinate frame defined by MAV_FRAME enum
 * @param area_id the id of the no-fly zone
 * @param country country code
 * @param begin_at effective UTC time
 * @param end_at expiration UTC time
 * @param updated_at update UTC time
 * @param level the level of the no-fly zone(-1:unknown;0:warning;2:no fly;5:ok to fly)
 * @param shape the shape of the no-fly zone.(-1:unknown;0:circle;1:rectangle;12:polygon)
 * @param type type of this no-fly zone.(-1:unknown;0:airport;1:specific area;2:military zone;3.goverment;4:ok to fly zone;5:ferry terminals;6:train station;7.gymnasium;8.prison.)
 * @param lat the center latitude of the no-fly zone
 * @param lon the center longtitude of the no-fly zone
 * @param randius the randius of the no-fly zone
 * @param polygon_lat the latitude array of the polygon no-fly zone
 * @param polygon_lon the longtitude array of the polygon no-fly zone
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_safety_set_no_fly_zone_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t frame, int32_t area_id, const char *country, uint64_t begin_at, uint64_t end_at, uint64_t updated_at, int8_t level, int8_t shape, int8_t type, int32_t lat, int32_t lon, float randius, const int32_t *polygon_lat, const int32_t *polygon_lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN];
	_mav_put_uint64_t(buf, 0, begin_at);
	_mav_put_uint64_t(buf, 8, end_at);
	_mav_put_uint64_t(buf, 16, updated_at);
	_mav_put_int32_t(buf, 24, area_id);
	_mav_put_int32_t(buf, 28, lat);
	_mav_put_int32_t(buf, 32, lon);
	_mav_put_float(buf, 36, randius);
	_mav_put_uint8_t(buf, 168, target_system);
	_mav_put_uint8_t(buf, 169, target_component);
	_mav_put_uint8_t(buf, 170, frame);
	_mav_put_int8_t(buf, 173, level);
	_mav_put_int8_t(buf, 174, shape);
	_mav_put_int8_t(buf, 175, type);
	_mav_put_int32_t_array(buf, 40, polygon_lat, 16);
	_mav_put_int32_t_array(buf, 104, polygon_lon, 16);
	_mav_put_char_array(buf, 171, country, 2);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE, buf, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE, buf, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN);
#endif
#else
	mavlink_safety_set_no_fly_zone_t packet;
	packet.begin_at = begin_at;
	packet.end_at = end_at;
	packet.updated_at = updated_at;
	packet.area_id = area_id;
	packet.lat = lat;
	packet.lon = lon;
	packet.randius = randius;
	packet.target_system = target_system;
	packet.target_component = target_component;
	packet.frame = frame;
	packet.level = level;
	packet.shape = shape;
	packet.type = type;
	mav_array_memcpy(packet.polygon_lat, polygon_lat, sizeof(int32_t)*16);
	mav_array_memcpy(packet.polygon_lon, polygon_lon, sizeof(int32_t)*16);
	mav_array_memcpy(packet.country, country, sizeof(char)*2);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE, (const char *)&packet, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE, (const char *)&packet, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_safety_set_no_fly_zone_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t frame, int32_t area_id, const char *country, uint64_t begin_at, uint64_t end_at, uint64_t updated_at, int8_t level, int8_t shape, int8_t type, int32_t lat, int32_t lon, float randius, const int32_t *polygon_lat, const int32_t *polygon_lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint64_t(buf, 0, begin_at);
	_mav_put_uint64_t(buf, 8, end_at);
	_mav_put_uint64_t(buf, 16, updated_at);
	_mav_put_int32_t(buf, 24, area_id);
	_mav_put_int32_t(buf, 28, lat);
	_mav_put_int32_t(buf, 32, lon);
	_mav_put_float(buf, 36, randius);
	_mav_put_uint8_t(buf, 168, target_system);
	_mav_put_uint8_t(buf, 169, target_component);
	_mav_put_uint8_t(buf, 170, frame);
	_mav_put_int8_t(buf, 173, level);
	_mav_put_int8_t(buf, 174, shape);
	_mav_put_int8_t(buf, 175, type);
	_mav_put_int32_t_array(buf, 40, polygon_lat, 16);
	_mav_put_int32_t_array(buf, 104, polygon_lon, 16);
	_mav_put_char_array(buf, 171, country, 2);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE, buf, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE, buf, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN);
#endif
#else
	mavlink_safety_set_no_fly_zone_t *packet = (mavlink_safety_set_no_fly_zone_t *)msgbuf;
	packet->begin_at = begin_at;
	packet->end_at = end_at;
	packet->updated_at = updated_at;
	packet->area_id = area_id;
	packet->lat = lat;
	packet->lon = lon;
	packet->randius = randius;
	packet->target_system = target_system;
	packet->target_component = target_component;
	packet->frame = frame;
	packet->level = level;
	packet->shape = shape;
	packet->type = type;
	mav_array_memcpy(packet->polygon_lat, polygon_lat, sizeof(int32_t)*16);
	mav_array_memcpy(packet->polygon_lon, polygon_lon, sizeof(int32_t)*16);
	mav_array_memcpy(packet->country, country, sizeof(char)*2);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE, (const char *)packet, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE, (const char *)packet, MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE SAFETY_SET_NO_FLY_ZONE UNPACKING


/**
 * @brief Get field target_system from safety_set_no_fly_zone message
 *
 * @return system id
 */
static inline uint8_t mavlink_msg_safety_set_no_fly_zone_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  168);
}

/**
 * @brief Get field target_component from safety_set_no_fly_zone message
 *
 * @return component id
 */
static inline uint8_t mavlink_msg_safety_set_no_fly_zone_get_target_component(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  169);
}

/**
 * @brief Get field frame from safety_set_no_fly_zone message
 *
 * @return cordinate frame defined by MAV_FRAME enum
 */
static inline uint8_t mavlink_msg_safety_set_no_fly_zone_get_frame(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  170);
}

/**
 * @brief Get field area_id from safety_set_no_fly_zone message
 *
 * @return the id of the no-fly zone
 */
static inline int32_t mavlink_msg_safety_set_no_fly_zone_get_area_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field country from safety_set_no_fly_zone message
 *
 * @return country code
 */
static inline uint16_t mavlink_msg_safety_set_no_fly_zone_get_country(const mavlink_message_t* msg, char *country)
{
	return _MAV_RETURN_char_array(msg, country, 2,  171);
}

/**
 * @brief Get field begin_at from safety_set_no_fly_zone message
 *
 * @return effective UTC time
 */
static inline uint64_t mavlink_msg_safety_set_no_fly_zone_get_begin_at(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field end_at from safety_set_no_fly_zone message
 *
 * @return expiration UTC time
 */
static inline uint64_t mavlink_msg_safety_set_no_fly_zone_get_end_at(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field updated_at from safety_set_no_fly_zone message
 *
 * @return update UTC time
 */
static inline uint64_t mavlink_msg_safety_set_no_fly_zone_get_updated_at(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  16);
}

/**
 * @brief Get field level from safety_set_no_fly_zone message
 *
 * @return the level of the no-fly zone(-1:unknown;0:warning;2:no fly;5:ok to fly)
 */
static inline int8_t mavlink_msg_safety_set_no_fly_zone_get_level(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  173);
}

/**
 * @brief Get field shape from safety_set_no_fly_zone message
 *
 * @return the shape of the no-fly zone.(-1:unknown;0:circle;1:rectangle;12:polygon)
 */
static inline int8_t mavlink_msg_safety_set_no_fly_zone_get_shape(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  174);
}

/**
 * @brief Get field type from safety_set_no_fly_zone message
 *
 * @return type of this no-fly zone.(-1:unknown;0:airport;1:specific area;2:military zone;3.goverment;4:ok to fly zone;5:ferry terminals;6:train station;7.gymnasium;8.prison.)
 */
static inline int8_t mavlink_msg_safety_set_no_fly_zone_get_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  175);
}

/**
 * @brief Get field lat from safety_set_no_fly_zone message
 *
 * @return the center latitude of the no-fly zone
 */
static inline int32_t mavlink_msg_safety_set_no_fly_zone_get_lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field lon from safety_set_no_fly_zone message
 *
 * @return the center longtitude of the no-fly zone
 */
static inline int32_t mavlink_msg_safety_set_no_fly_zone_get_lon(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field randius from safety_set_no_fly_zone message
 *
 * @return the randius of the no-fly zone
 */
static inline float mavlink_msg_safety_set_no_fly_zone_get_randius(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field polygon_lat from safety_set_no_fly_zone message
 *
 * @return the latitude array of the polygon no-fly zone
 */
static inline uint16_t mavlink_msg_safety_set_no_fly_zone_get_polygon_lat(const mavlink_message_t* msg, int32_t *polygon_lat)
{
	return _MAV_RETURN_int32_t_array(msg, polygon_lat, 16,  40);
}

/**
 * @brief Get field polygon_lon from safety_set_no_fly_zone message
 *
 * @return the longtitude array of the polygon no-fly zone
 */
static inline uint16_t mavlink_msg_safety_set_no_fly_zone_get_polygon_lon(const mavlink_message_t* msg, int32_t *polygon_lon)
{
	return _MAV_RETURN_int32_t_array(msg, polygon_lon, 16,  104);
}

/**
 * @brief Decode a safety_set_no_fly_zone message into a struct
 *
 * @param msg The message to decode
 * @param safety_set_no_fly_zone C-struct to decode the message contents into
 */
static inline void mavlink_msg_safety_set_no_fly_zone_decode(const mavlink_message_t* msg, mavlink_safety_set_no_fly_zone_t* safety_set_no_fly_zone)
{
#if MAVLINK_NEED_BYTE_SWAP
	safety_set_no_fly_zone->begin_at = mavlink_msg_safety_set_no_fly_zone_get_begin_at(msg);
	safety_set_no_fly_zone->end_at = mavlink_msg_safety_set_no_fly_zone_get_end_at(msg);
	safety_set_no_fly_zone->updated_at = mavlink_msg_safety_set_no_fly_zone_get_updated_at(msg);
	safety_set_no_fly_zone->area_id = mavlink_msg_safety_set_no_fly_zone_get_area_id(msg);
	safety_set_no_fly_zone->lat = mavlink_msg_safety_set_no_fly_zone_get_lat(msg);
	safety_set_no_fly_zone->lon = mavlink_msg_safety_set_no_fly_zone_get_lon(msg);
	safety_set_no_fly_zone->randius = mavlink_msg_safety_set_no_fly_zone_get_randius(msg);
	mavlink_msg_safety_set_no_fly_zone_get_polygon_lat(msg, safety_set_no_fly_zone->polygon_lat);
	mavlink_msg_safety_set_no_fly_zone_get_polygon_lon(msg, safety_set_no_fly_zone->polygon_lon);
	safety_set_no_fly_zone->target_system = mavlink_msg_safety_set_no_fly_zone_get_target_system(msg);
	safety_set_no_fly_zone->target_component = mavlink_msg_safety_set_no_fly_zone_get_target_component(msg);
	safety_set_no_fly_zone->frame = mavlink_msg_safety_set_no_fly_zone_get_frame(msg);
	mavlink_msg_safety_set_no_fly_zone_get_country(msg, safety_set_no_fly_zone->country);
	safety_set_no_fly_zone->level = mavlink_msg_safety_set_no_fly_zone_get_level(msg);
	safety_set_no_fly_zone->shape = mavlink_msg_safety_set_no_fly_zone_get_shape(msg);
	safety_set_no_fly_zone->type = mavlink_msg_safety_set_no_fly_zone_get_type(msg);
#else
	memcpy(safety_set_no_fly_zone, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SAFETY_SET_NO_FLY_ZONE_LEN);
#endif
}
