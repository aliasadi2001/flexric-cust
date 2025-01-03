
/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *    
 *      http://www.openairinterface.org/?page_id=698
 *    
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */   
      
#ifndef E42_IAPP_API_H
#define E42_IAPP_API_H 

#include "../../lib/e2ap/e2ap_global_node_id_wrapper.h"
#include "../../lib/e2ap/e2ap_ran_function_wrapper.h"
#include "../../lib/e2ap/type_defs_wrapper.h"    
#include "near_ric_if.h"

#include <stdint.h>
#include <stddef.h>

typedef struct near_ric_s near_ric_t;

void init_iapp_api(const char* addr, int port, near_ric_if_t ric);
  
void stop_iapp_api(void);     

#ifdef E2AP_V1 
void add_e2_node_iapp_api_v1(global_e2_node_id_t* id, size_t len, ran_function_t const ran_func[len]);
#elif defined(E2AP_V2) || defined(E2AP_V3)
void add_e2_node_iapp_api(global_e2_node_id_t* id, size_t len, ran_function_t const ran_func[len],  size_t len_cca, e2ap_node_component_config_add_t const* cca);
#else
  static_assert(0!=0, "Unknown E2Ap version");
#endif

void rm_e2_node_iapp_api(global_e2_node_id_t* id);

void notify_msg_iapp_api(e2ap_msg_t const* msg);

#endif

