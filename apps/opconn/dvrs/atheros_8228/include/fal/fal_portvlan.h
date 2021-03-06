/*
 * Copyright (c) 2007-2008 Atheros Communications, Inc.
 * All rights reserved.
 *
 */

/**
 * @defgroup fal_port_vlan FAL_PORT_VLAN
 * @{
 */
#ifndef _FAL_PORT_VLAN_H_
#define _FAL_PORT_VLAN_H_

#ifdef __cplusplus
extern "C" {
#endif                          /* __cplusplus */

#include "common/sw.h"
#include "fal/fal_type.h"

/**
@brief This enum defines 802.1q mode type.
*/
typedef enum {
    FAL_1Q_DISABLE = 0, /**<  802.1q mode disbale, port based vlan */
    FAL_1Q_SECURE,      /**<   secure mode, packets which vid isn't in vlan table or source port isn't in vlan port member will be discarded.*/
    FAL_1Q_CHECK,       /**<   check mode, packets which vid isn't in vlan table will be discarded, packets which source port isn't in vlan port member will forward base on vlan port member*/
    FAL_1Q_FALLBACK,    /**<   fallback mode, packets which vid isn't in vlan table will forwarded base on port vlan, packet's which source port isn't in vlan port member will forward base on vlan port member.*/
    FAL_1Q_MODE_BUTT
} fal_pt_1qmode_t;

/**
@brief This enum defines packets transmitted out vlan tagged mode.
*/
typedef enum {
    FAL_EG_UNMODIFIED = 0,  /**<  egress transmit packets unmodified */
    FAL_EG_UNTAGGED,        /**<   egress transmit packets without vlan tag*/
    FAL_EG_TAGGED,          /**<  egress transmit packets with vlan tag     */
    FAL_EG_HYBRID,          /**<  egress transmit packets in hybrid tag mode     */
    FAL_EG_MODE_BUTT
} fal_pt_1q_egmode_t;

/**
@brief This enum defines receive packets tagged mode.
*/
typedef enum {
    FAL_INVLAN_ADMIT_ALL = 0,  /**<  receive all packets include tagged and untagged */
    FAL_INVLAN_ADMIT_TAGGED,   /**<  only receive tagged packets*/
    FAL_INVLAN_ADMIT_UNTAGGED, /**<  only receive untagged packets include priority tagged */
    FAL_INVLAN_MODE_BUTT
} fal_pt_invlan_mode_t;

/**
@brief This enum defines vlan propagation mode.
*/
typedef enum {
    FAL_VLAN_PROPAGATION_DISABLE = 0, /**<  vlan propagation disable */
    FAL_VLAN_PROPAGATION_CLONE,       /**<  vlan paopagation mode is clone */
    FAL_VLAN_PROPAGATION_REPLACE,     /**<  vlan paopagation mode is repalce */
    FAL_VLAN_PROPAGATION_MODE_BUTT
}fal_vlan_propagation_mode_t;

/**
  @details  Fields description:
 
 o_vid - original vlan id
 s_vid - service vid id
 c_vid - custom vid id
 bi_dir - entry search direction
 
@brief This structure defines the vlan translation entry.

*/
typedef struct {
    a_uint32_t o_vid;
    a_uint32_t s_vid;
    a_uint32_t c_vid;
    a_bool_t   bi_dir;
}fal_vlan_trans_entry_t;

/**
@brief This enum defines qinq working mode.
*/
typedef enum {
    FAL_QINQ_CTAG_MODE = 0,
    FAL_QINQ_STAG_MODE,
    FAL_QINQ_MODE_BUTT
}fal_qinq_mode_t;

/**
@brief This enum defines port role in qinq mode.
*/
typedef enum {
    FAL_QINQ_EDGE_PORT = 0,
    FAL_QINQ_CORE_PORT,
    FAL_QINQ_PORT_ROLE_BUTT
}fal_qinq_port_role_t;


sw_error_t
fal_port_1qmode_set(a_uint32_t dev_id, fal_port_t port_id,
                    fal_pt_1qmode_t port_1qmode);



sw_error_t
fal_port_1qmode_get(a_uint32_t dev_id, fal_port_t port_id,
                    fal_pt_1qmode_t * pport_1qmode);



sw_error_t
fal_port_egvlanmode_set(a_uint32_t dev_id, fal_port_t port_id,
                        fal_pt_1q_egmode_t port_egvlanmode);



sw_error_t
fal_port_egvlanmode_get(a_uint32_t dev_id, fal_port_t port_id,
                        fal_pt_1q_egmode_t * pport_egvlanmode);



sw_error_t
fal_portvlan_member_add(a_uint32_t dev_id, fal_port_t port_id,
                        fal_port_t mem_port_id);



sw_error_t
fal_portvlan_member_del(a_uint32_t dev_id, fal_port_t port_id,
                        fal_port_t mem_port_id);



sw_error_t
fal_portvlan_member_update(a_uint32_t dev_id, fal_port_t port_id,
                           fal_pbmp_t mem_port_map);



sw_error_t
fal_portvlan_member_get(a_uint32_t dev_id, fal_port_t port_id,
                        fal_pbmp_t * mem_port_map);



sw_error_t
fal_port_default_vid_set(a_uint32_t dev_id, fal_port_t port_id,
                         a_uint32_t vid);



sw_error_t
fal_port_default_vid_get(a_uint32_t dev_id, fal_port_t port_id,
                         a_uint32_t * vid);



sw_error_t
fal_port_force_default_vid_set(a_uint32_t dev_id, fal_port_t port_id,
                               a_bool_t enable);



sw_error_t
fal_port_force_default_vid_get(a_uint32_t dev_id, fal_port_t port_id,
                               a_bool_t * enable);



sw_error_t
fal_port_force_portvlan_set(a_uint32_t dev_id, fal_port_t port_id,
                            a_bool_t enable);



sw_error_t
fal_port_force_portvlan_get(a_uint32_t dev_id, fal_port_t port_id,
                            a_bool_t * enable);



sw_error_t
fal_port_nestvlan_set(a_uint32_t dev_id, fal_port_t port_id,
                      a_bool_t enable);



sw_error_t
fal_port_nestvlan_get(a_uint32_t dev_id, fal_port_t port_id,
                      a_bool_t * enable);



sw_error_t
fal_nestvlan_tpid_set(a_uint32_t dev_id, a_uint32_t tpid);



sw_error_t
fal_nestvlan_tpid_get(a_uint32_t dev_id, a_uint32_t * tpid);


sw_error_t
fal_port_invlan_mode_set(a_uint32_t dev_id, fal_port_t port_id,
                           fal_pt_invlan_mode_t mode);


sw_error_t
fal_port_invlan_mode_get(a_uint32_t dev_id, fal_port_t port_id,
                           fal_pt_invlan_mode_t * mode);


sw_error_t
fal_port_tls_set(a_uint32_t dev_id, fal_port_t port_id,
                           a_bool_t enable);


sw_error_t
fal_port_tls_get(a_uint32_t dev_id, fal_port_t port_id,
                           a_bool_t * enable);


sw_error_t
fal_port_pri_propagation_set(a_uint32_t dev_id, fal_port_t port_id,
                           a_bool_t enable);


sw_error_t
fal_port_pri_propagation_get(a_uint32_t dev_id, fal_port_t port_id,
                           a_bool_t * enable);


sw_error_t
fal_port_default_svid_set(a_uint32_t dev_id, fal_port_t port_id,
                           a_uint32_t vid);


sw_error_t
fal_port_default_svid_get(a_uint32_t dev_id, fal_port_t port_id,
                           a_uint32_t * vid);


sw_error_t
fal_port_default_cvid_set(a_uint32_t dev_id, fal_port_t port_id,
                           a_uint32_t vid);


sw_error_t
fal_port_default_cvid_get(a_uint32_t dev_id, fal_port_t port_id,
                           a_uint32_t * vid);


sw_error_t
fal_port_vlan_propagation_set(a_uint32_t dev_id, fal_port_t port_id,
                           fal_vlan_propagation_mode_t mode);


sw_error_t
fal_port_vlan_propagation_get(a_uint32_t dev_id, fal_port_t port_id,
                           fal_vlan_propagation_mode_t * mode);


sw_error_t
fal_port_vlan_trans_add(a_uint32_t dev_id, fal_port_t port_id, fal_vlan_trans_entry_t *entry);


sw_error_t
fal_port_vlan_trans_del(a_uint32_t dev_id, fal_port_t port_id, fal_vlan_trans_entry_t *entry);


sw_error_t
fal_port_vlan_trans_get(a_uint32_t dev_id, fal_port_t port_id, fal_vlan_trans_entry_t *entry);


sw_error_t
fal_qinq_mode_set(a_uint32_t dev_id, fal_qinq_mode_t mode);


sw_error_t
fal_qinq_mode_get(a_uint32_t dev_id, fal_qinq_mode_t * mode);


sw_error_t
fal_port_qinq_role_set(a_uint32_t dev_id, fal_port_t port_id, fal_qinq_port_role_t role);


sw_error_t
fal_port_qinq_role_get(a_uint32_t dev_id, fal_port_t port_id, fal_qinq_port_role_t * role);


sw_error_t
fal_port_vlan_trans_iterate(a_uint32_t dev_id, fal_port_t port_id,
                        a_uint32_t * iterator, fal_vlan_trans_entry_t * entry);


#ifdef __cplusplus
}
#endif                          /* __cplusplus */
#endif                          /* _PORT_VLAN_H_ */
/**
 * @}
 */
