/*
 * Copyright (c) 2007-2008 Atheros Communications, Inc.
 * All rights reserved.
 *
 */
/**
 * @defgroup fal_acl FAL_ACL
 * @{
 */
#include "sw.h"
#include "fal_acl.h"
#include "hsl_api.h"

static sw_error_t
_fal_acl_list_creat(a_uint32_t dev_id, a_uint32_t list_id, a_uint32_t prio)
{
    sw_error_t rv;
    hsl_api_t *p_api;

    SW_RTN_ON_NULL(p_api = hsl_api_ptr_get(dev_id));

    if (NULL == p_api->acl_list_creat)
        return SW_NOT_SUPPORTED;

    rv = p_api->acl_list_creat(dev_id, list_id, prio);
    return rv;
}

static sw_error_t
_fal_acl_list_destroy(a_uint32_t dev_id, a_uint32_t list_id)
{
    sw_error_t rv;
    hsl_api_t *p_api;

    SW_RTN_ON_NULL(p_api = hsl_api_ptr_get(dev_id));

    if (NULL == p_api->acl_list_destroy)
        return SW_NOT_SUPPORTED;

    rv = p_api->acl_list_destroy(dev_id, list_id);
    return rv;
}

static sw_error_t
_fal_acl_rule_add(a_uint32_t dev_id, a_uint32_t list_id, a_uint32_t rule_id,
                    a_uint32_t rule_nr, fal_acl_rule_t * rule)
{
    sw_error_t rv;
    hsl_api_t *p_api;

    SW_RTN_ON_NULL(p_api = hsl_api_ptr_get(dev_id));

    if (NULL == p_api->acl_rule_add)
        return SW_NOT_SUPPORTED;

    rv = p_api->acl_rule_add(dev_id, list_id, rule_id, rule_nr, rule);
    return rv;
}

static sw_error_t
_fal_acl_rule_delete(a_uint32_t dev_id, a_uint32_t list_id, a_uint32_t rule_id,
                    a_uint32_t rule_nr)
{
    sw_error_t rv;
    hsl_api_t *p_api;

    SW_RTN_ON_NULL(p_api = hsl_api_ptr_get(dev_id));

    if (NULL == p_api->acl_rule_delete)
        return SW_NOT_SUPPORTED;

    rv = p_api->acl_rule_delete(dev_id, list_id, rule_id, rule_nr);
    return rv;
}

static sw_error_t
_fal_acl_rule_query(a_uint32_t dev_id, a_uint32_t list_id, a_uint32_t rule_id,
                    fal_acl_rule_t * rule)
{
    sw_error_t rv;
    hsl_api_t *p_api;

    SW_RTN_ON_NULL(p_api = hsl_api_ptr_get(dev_id));

    if (NULL == p_api->acl_rule_query)
        return SW_NOT_SUPPORTED;

    rv = p_api->acl_rule_query(dev_id, list_id, rule_id, rule);
    return rv;
}

static sw_error_t
_fal_acl_list_bind(a_uint32_t dev_id, a_uint32_t list_id,
                     fal_acl_direc_t direc, fal_acl_bind_obj_t obj_t,
                     a_uint32_t obj_idx)
{
    sw_error_t rv;
    hsl_api_t *p_api;

    SW_RTN_ON_NULL(p_api = hsl_api_ptr_get(dev_id));

    if (NULL == p_api->acl_list_bind)
        return SW_NOT_SUPPORTED;

    rv = p_api->acl_list_bind(dev_id, list_id, direc, obj_t, obj_idx);
    return rv;
}

static sw_error_t
_fal_acl_list_unbind(a_uint32_t dev_id, a_uint32_t list_id,
                       fal_acl_direc_t direc, fal_acl_bind_obj_t obj_t,
                       a_uint32_t obj_idx)
{
    sw_error_t rv;
    hsl_api_t *p_api;

    SW_RTN_ON_NULL(p_api = hsl_api_ptr_get(dev_id));

    if (NULL == p_api->acl_list_unbind)
        return SW_NOT_SUPPORTED;

    rv = p_api->acl_list_unbind(dev_id, list_id, direc, obj_t, obj_idx);
    return rv;
}

static sw_error_t
_fal_acl_status_set(a_uint32_t dev_id, a_bool_t enable)
{
    sw_error_t rv;
    hsl_api_t *p_api;

    SW_RTN_ON_NULL(p_api = hsl_api_ptr_get(dev_id));

    if (NULL == p_api->acl_status_set)
        return SW_NOT_SUPPORTED;

    rv = p_api->acl_status_set(dev_id, enable);
    return rv;
}

static sw_error_t
_fal_acl_status_get(a_uint32_t dev_id, a_bool_t * enable)
{
    sw_error_t rv;
    hsl_api_t *p_api;

    SW_RTN_ON_NULL(p_api = hsl_api_ptr_get(dev_id));

    if (NULL == p_api->acl_status_get)
        return SW_NOT_SUPPORTED;

    rv = p_api->acl_status_get(dev_id, enable);
    return rv;
}

static sw_error_t
_fal_acl_port_udf_profile_set(a_uint32_t dev_id, fal_port_t port_id,
                               fal_acl_udf_type_t udf_type, a_uint32_t offset,
                               a_uint32_t length)
{
    sw_error_t rv;
    hsl_api_t *p_api;

    SW_RTN_ON_NULL(p_api = hsl_api_ptr_get(dev_id));

    if (NULL == p_api->acl_port_udf_profile_set)
        return SW_NOT_SUPPORTED;

    rv = p_api->acl_port_udf_profile_set(dev_id, port_id, udf_type, offset, length);
    return rv;
}

static sw_error_t
_fal_acl_port_udf_profile_get(a_uint32_t dev_id, fal_port_t port_id,
                               fal_acl_udf_type_t udf_type, a_uint32_t * offset,
                               a_uint32_t * length)
{
    sw_error_t rv;
    hsl_api_t *p_api;

    SW_RTN_ON_NULL(p_api = hsl_api_ptr_get(dev_id));

    if (NULL == p_api->acl_port_udf_profile_get)
        return SW_NOT_SUPPORTED;

    rv = p_api->acl_port_udf_profile_get(dev_id, port_id, udf_type, offset, length);
    return rv;
}

sw_error_t
fal_acl_list_dump(a_uint32_t dev_id)
{
    sw_error_t rv;
    hsl_api_t *p_api;

    SW_RTN_ON_NULL(p_api = hsl_api_ptr_get(dev_id));

    if (NULL == p_api->acl_list_dump)
        return SW_NOT_SUPPORTED;

    rv = p_api->acl_list_dump(dev_id);
    return rv;
}

sw_error_t
fal_acl_rule_dump(a_uint32_t dev_id)
{
    sw_error_t rv;
    hsl_api_t *p_api;

    SW_RTN_ON_NULL(p_api = hsl_api_ptr_get(dev_id));

    if (NULL == p_api->acl_rule_dump)
        return SW_NOT_SUPPORTED;

    rv = p_api->acl_rule_dump(dev_id);
    return rv;
}
/**
 * @brief Creat an acl list
 * @details  Comments:
  *     If the priority of a list is more small then the priority is more high,
 *     that means the list could be first matched.
 * @param[in] dev_id device id
 * @param[in] list_id acl list id
 * @param[in] list_pri acl list priority
 * @return SW_OK or error code
 */
sw_error_t
fal_acl_list_creat(a_uint32_t dev_id, a_uint32_t list_id, a_uint32_t prio)
{
    sw_error_t rv;

    FAL_API_LOCK;
    rv = _fal_acl_list_creat(dev_id, list_id, prio);
    FAL_API_UNLOCK;
    return rv;
}

/**
 * @brief Destroy an acl list
 * @param[in] dev_id device id
 * @param[in] list_id acl list id
 * @return SW_OK or error code
 */
sw_error_t
fal_acl_list_destroy(a_uint32_t dev_id, a_uint32_t list_id)
{
    sw_error_t rv;

    FAL_API_LOCK;
    rv = _fal_acl_list_destroy(dev_id, list_id);
    FAL_API_UNLOCK;
    return rv;
}

/**
 * @brief Add one rule or more rules to an existing acl list
 * @param[in] dev_id device id
 * @param[in] list_id acl list id
 * @param[in] rule_id first rule id of this adding operation in list
 * @param[in] rule_nr rule number of this adding operation
 * @param[in] rule rules content of this adding operation
 * @return SW_OK or error code
 */
sw_error_t
fal_acl_rule_add(a_uint32_t dev_id, a_uint32_t list_id, a_uint32_t rule_id,
                    a_uint32_t rule_nr, fal_acl_rule_t * rule)
{
    sw_error_t rv;

    FAL_API_LOCK;
    rv = _fal_acl_rule_add(dev_id, list_id, rule_id, rule_nr, rule);
    FAL_API_UNLOCK;
    return rv;
}

/**
 * @brief Delete one rule or more rules from an existing acl list
 * @param[in] dev_id device id
 * @param[in] list_id acl list id
 * @param[in] rule_id first rule id of this deleteing operation in list
 * @param[in] rule_nr rule number of this deleteing operation
 * @return SW_OK or error code
 */
sw_error_t
fal_acl_rule_delete(a_uint32_t dev_id, a_uint32_t list_id, a_uint32_t rule_id,
                    a_uint32_t rule_nr)
{
    sw_error_t rv;

    FAL_API_LOCK;
    rv = _fal_acl_rule_delete(dev_id, list_id, rule_id, rule_nr);
    FAL_API_UNLOCK;
    return rv;
}

/**
 * @brief Query one particular rule in a particular acl list
 * @param[in] dev_id device id
 * @param[in] list_id acl list id
 * @param[in] rule_id first rule id of this deleteing operation in list
 * @param[out] rule rule content of this operation
 * @return SW_OK or error code
 */
sw_error_t
fal_acl_rule_query(a_uint32_t dev_id, a_uint32_t list_id, a_uint32_t rule_id,
                    fal_acl_rule_t * rule)
{
    sw_error_t rv;

    FAL_API_LOCK;
    rv = _fal_acl_rule_query(dev_id, list_id, rule_id, rule);
    FAL_API_UNLOCK;
    return rv;
}

/**
 * @brief Bind an acl list to a particular object
 * @details  Comments:
 *    If obj_t equals FAL_ACL_BIND_PORT then obj_idx means port id
 * @param[in] dev_id device id
 * @param[in] list_id acl list id
 * @param[in] direc direction of this binding operation
 * @param[in] obj_t object type of this binding operation
 * @param[in] obj_idx object index of this binding operation
 * @return SW_OK or error code
 */
sw_error_t
fal_acl_list_bind(a_uint32_t dev_id, a_uint32_t list_id,
                     fal_acl_direc_t direc, fal_acl_bind_obj_t obj_t,
                     a_uint32_t obj_idx)
{
    sw_error_t rv;

    FAL_API_LOCK;
    rv = _fal_acl_list_bind(dev_id, list_id, direc, obj_t, obj_idx);
    FAL_API_UNLOCK;
    return rv;
}

/**
 * @brief Unbind an acl list from a particular object
 * @details  Comments:
  *    If obj_t equals FAL_ACL_BIND_PORT then obj_idx means port id 
 * @param[in] dev_id device id
 * @param[in] list_id acl list id
 * @param[in] direc direction of this unbinding operation
 * @param[in] obj_t object type of this unbinding operation
 * @param[in] obj_idx object index of this unbinding operation
 * @return SW_OK or error code
 */
sw_error_t
fal_acl_list_unbind(a_uint32_t dev_id, a_uint32_t list_id,
                       fal_acl_direc_t direc, fal_acl_bind_obj_t obj_t,
                       a_uint32_t obj_idx)
{
    sw_error_t rv;

    FAL_API_LOCK;
    rv = _fal_acl_list_unbind(dev_id, list_id, direc, obj_t, obj_idx);
    FAL_API_UNLOCK;
    return rv;
}

/**
 * @brief Set working status of ACL engine on a particular device
 * @param[in] dev_id device id
 * @param[in] enable A_TRUE or A_FALSE
 * @return SW_OK or error code
 */
sw_error_t
fal_acl_status_set(a_uint32_t dev_id, a_bool_t enable)
{
    sw_error_t rv;

    FAL_API_LOCK;
    rv = _fal_acl_status_set(dev_id, enable);
    FAL_API_UNLOCK;
    return rv;
}

/**
 * @brief Get working status of ACL engine on a particular device
 * @param[in] dev_id device id
 * @param[out] enable A_TRUE or A_FALSE
 * @return SW_OK or error code
 */
sw_error_t
fal_acl_status_get(a_uint32_t dev_id, a_bool_t * enable)
{
    sw_error_t rv;

    FAL_API_LOCK;
    rv = _fal_acl_status_get(dev_id, enable);
    FAL_API_UNLOCK;
    return rv;
}

/**
 * @brief Set user define fields profile on a particular port
 * @param[in] dev_id device id
 * @param[in] port_id port id
 * @param[in] udf_type udf type
 * @param[in] offset udf offset
 * @param[in] length udf length
 * @return SW_OK or error code
 */
sw_error_t
fal_acl_port_udf_profile_set(a_uint32_t dev_id, fal_port_t port_id,
                              fal_acl_udf_type_t udf_type, a_uint32_t offset,
                              a_uint32_t length)
{
    sw_error_t rv;

    FAL_API_LOCK;
    rv = _fal_acl_port_udf_profile_set(dev_id, port_id, udf_type, offset,
                                        length);
    FAL_API_UNLOCK;
    return rv;
}

/**
 * @brief Get user define fields profile on a particular port
 * @param[in] dev_id device id
 * @param[in] port_id port id
 * @param[in] udf_type udf type
 * @param[out] offset udf offset
 * @param[out] length udf length
 * @return SW_OK or error code
 */
sw_error_t
fal_acl_port_udf_profile_get(a_uint32_t dev_id, fal_port_t port_id,
                              fal_acl_udf_type_t udf_type, a_uint32_t * offset,
                              a_uint32_t * length)
{
    sw_error_t rv;

    FAL_API_LOCK;
    rv = _fal_acl_port_udf_profile_get(dev_id, port_id, udf_type, offset,
                                        length);
    FAL_API_UNLOCK;
    return rv;
}


/**
 * @}
 */
