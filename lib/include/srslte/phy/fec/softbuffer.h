/*
 * Copyright 2013-2020 Software Radio Systems Limited
 *
 * This file is part of srsLTE.
 *
 * srsLTE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsLTE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

/******************************************************************************
 *  File:         softbuffer.h
 *
 *  Description:  Buffer for RX and TX soft bits. This should be provided by MAC.
 *                Provided here basically for the examples.
 *
 *  Reference:
 *****************************************************************************/

#ifndef SRSLTE_SOFTBUFFER_H
#define SRSLTE_SOFTBUFFER_H

#include "srslte/config.h"

typedef struct SRSLTE_API {
  uint32_t  max_cb;
  uint32_t  max_cb_size;
  int16_t** buffer_f;
  uint8_t** data;
  bool*     cb_crc;
  bool      tb_crc;
} srslte_softbuffer_rx_t;

typedef struct SRSLTE_API {
  uint32_t  max_cb;
  uint32_t  max_cb_size;
  uint8_t** buffer_b;
} srslte_softbuffer_tx_t;

#define SOFTBUFFER_SIZE 18600

SRSLTE_API int srslte_softbuffer_rx_init(srslte_softbuffer_rx_t* q, uint32_t nof_prb);

/**
 * @brief Initialises Rx soft-buffer for a number of code blocks and their size
 * @param q The Rx soft-buffer pointer
 * @param max_cb The maximum number of code blocks to allocate
 * @param max_cb_size The code block size to allocate
 * @return It returns SRSLTE_SUCCESS if it allocates the soft-buffer succesfully, otherwise it returns SRSLTE_ERROR code
 */
SRSLTE_API int srslte_softbuffer_rx_init_guru(srslte_softbuffer_rx_t* q, uint32_t max_cb, uint32_t max_cb_size);

SRSLTE_API void srslte_softbuffer_rx_reset(srslte_softbuffer_rx_t* p);

SRSLTE_API void srslte_softbuffer_rx_reset_tbs(srslte_softbuffer_rx_t* q, uint32_t tbs);

SRSLTE_API void srslte_softbuffer_rx_reset_cb(srslte_softbuffer_rx_t* q, uint32_t nof_cb);

SRSLTE_API void srslte_softbuffer_rx_free(srslte_softbuffer_rx_t* p);

SRSLTE_API int srslte_softbuffer_tx_init(srslte_softbuffer_tx_t* q, uint32_t nof_prb);

/**
 * @brief Initialises Tx soft-buffer for a number of code blocks and their size
 * @param q The Tx soft-buffer pointer
 * @param max_cb The maximum number of code blocks to allocate
 * @param max_cb_size The code block size to allocate
 * @return It returns SRSLTE_SUCCESS if it allocates the soft-buffer succesfully, otherwise it returns SRSLTE_ERROR code
 */
SRSLTE_API int srslte_softbuffer_tx_init_guru(srslte_softbuffer_tx_t* q, uint32_t max_cb, uint32_t max_cb_size);

SRSLTE_API void srslte_softbuffer_tx_reset(srslte_softbuffer_tx_t* p);

SRSLTE_API void srslte_softbuffer_tx_reset_tbs(srslte_softbuffer_tx_t* q, uint32_t tbs);

SRSLTE_API void srslte_softbuffer_tx_reset_cb(srslte_softbuffer_tx_t* q, uint32_t nof_cb);

SRSLTE_API void srslte_softbuffer_tx_free(srslte_softbuffer_tx_t* p);

#endif // SRSLTE_SOFTBUFFER_H
